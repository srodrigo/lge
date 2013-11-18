/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_RESOURCE_LOADER_H_
#define _LGE_RESOURCE_LOADER_H_

#include "lge/core/resource/Resource.h"

#include <stdio.h>
#include <string>
#include <map>

namespace lge
{

/**
 * @brief Resource Loader for custom resources
 * 
 * Provides mechanisms to load and release custom resources that extend {@link IResource}
 * interface.
 * 
 * Implements a cache to store one copy per resource. If the same resource is
 * requested more than once, the count is incremented for that resource.
 * 
 * When a resource is no longer used, it is automatically released.
 * 
 * @see IResource
 * @see Resource
 * 
 * @author Sergio Rodrigo
 */
class ResourceLoader
{
public:
	ResourceLoader();
	
	/**
	 * @brief Destructor
	 * 
	 * Releases all the resources that wasn't manually released.
	 */
	~ResourceLoader();
	
	/**
	 * @brief Load a physical resource in disk
	 * 
	 * Loads a resource in disk, allocating space, if the resource which filename
	 * is specified does not exist in the cache.
	 * 
	 * If the resource is currently in the cache, this method simply returns a
	 * pointer to it.
	 * 
	 * A NULL pointer is returned if the resource couldn't be loaded from disk.
	 * 
	 * @param filename Complete resource location
	 * @return Resource allocated; NULL if the load failed
	 */
	template<typename T>
	const T* load(const std::string& filename)
	{
		// Try to get the resource from the cache
		printf("Loading resource \"%s\"\n", filename.c_str());
		int hash = Resource<T>::hash(filename);
		ResourceContainer::iterator iter = resources.find(hash);
		if (iter != resources.end()) {
			iter->second.usages++;
			printf("%p, %d\n", iter->second.ptr, iter->second.usages);
			return dynamic_cast<T*>(iter->second.ptr);
		}
		
		// Resource not found, create a new one
		T* resource = new T(filename);
		if (resource->load()) {
			printf("Inserting resource into memory\n");
			resources.insert(std::make_pair(hash, ResourceEntry(resource, 1)));
			return resource;
		}
		printf("Load failed. Removing resource\n");
		delete resource;
		return NULL;
	}
	
	/**
	 * @brief Release a resource
	 * 
	 * Releases a resource from the cache.
	 * 
	 * If the physical resource is being used elsewhere (its count is > 1), the
	 * count is decremented and the actual resource is not deleted.
	 * 
	 * If the physical resource is only being used by the parameter, it's removed
	 * from the cache and it's destructor is invoked.
	 * 
	 * @param resource Resource to be freed
	 * @return true if the resource count is in memory (so it's either removed or
	 * its count is decremented); false otherwise
	 */
	template<typename T>
	bool release(const T& resource)
	{
		int hash = Resource<T>::hash(resource->getFilename());
		ResourceContainer::iterator iter = resources.find(hash);
		if (iter != resources.end()) {
			printf("Decrementing count for resource \"%s\"\n",
					resource->getFilename().c_str());
			iter->second.usages--;
			// Only deallocate resources not used anywhere else
			if (iter->second.usages == 0) {
				printf("Removing resource \"%s\", resource from memory\n",
						resource->getFilename().c_str());
				delete iter->second.ptr;
				resources.erase(iter);
			}
			return true;
		}
		printf("Could not remove resource \"%s\", resource not in memory\n",
				resource->getFilename().c_str());
		return false;
	}
	
	/**
	 * @brief Count pointers using the resource
	 * 
	 * Counts the number of pointers using the resource provided.
	 * 
	 * @param resource Resource reference
	 * @return Number of pointers using the resource
	 */
	template<typename T>
	int currentUsages(const T& resource) const
	{
		int hash = Resource<T>::hash(resource->getFilename());
		ResourceContainer::const_iterator iter = resources.find(hash);
		if (iter == resources.end()) {
			return 0;
		}
		return iter->second.usages;
	}
	
private:
	struct ResourceEntry
	{
		IResource* ptr;
		int usages;
		
		ResourceEntry(IResource* const ptr, int usages)
				: ptr(ptr), usages(usages)
		{
		}
	};

	typedef std::map<int, ResourceEntry> ResourceContainer;
	
	ResourceContainer resources;
	
};

} // namespace

#endif
