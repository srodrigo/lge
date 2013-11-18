#ifndef _LGE_RESOURCE_H_
#define _LGE_RESOURCE_H_

#include "lge/core/resource/IResource.h"

#include <string>
#include <stdio.h>

#include "lge/util/StringUtil.h"

namespace lge
{

/**
 * @brief Generic resource wrapper
 * 
 * Wraps any kind of resource, identified by its complete filename (path + file name).
 * 
 * Stores a pointer to the resource, which should only be adquired on the {@link #load}
 * method. The virtual destructor frees the resource memory.
 * 
 * Provides a {@link #hash} method to convert the filename into a hash code for
 * eficiency purposes like identifying the resource without string comparisons.
 * 
 * Copy and assignment constructos are private to avoid the following (accidental)
 * situations:
 * 1) Creating new instances of the same internal resource.
 * 2) Having two instances pointing to the same internal resource, so when
 * one is deleted, the other one misses the resource.
 * 
 * A {@link clone} method is provided to allow explicit copies.
 * 
 * @see IResource
 * 
 * @author Sergio Rodrigo
 */
template<class T>
class Resource : public IResource
{
public:
	/**
	 * @brief Explicit constructor
	 * 
	 * Sets the filename to the parameter and the resource pointer to NULL.
	 * 
	 * Does not adquire the resource, as this is {@link #load} method responsibility
	 * and allows a resource manager/loader make an efficient use of physical resources,
	 * such as storing just one copy in memory.
	 * 
	 * @param filename Complete resource location
	 */
	explicit Resource(const std::string& filename)
			: filename(filename), resource(NULL)
	{
	}
	
	/**
	 * @brief Virtual destructor
	 * 
	 * Frees the resource memory if allocated and sets the pointer to NULL.
	 */
	virtual ~Resource()
	{
		if (resource) {
			printf("Removing resource pointer %p\n", resource);
			delete resource;
			resource = NULL;
		}
	}
	
	/**
	 * @brief Clone the object
	 * 
	 * Clones the current instance. This should include creating and allocating
	 * a new physical resource.
	 * 
	 * The purpose of this method is to provide a safe way of copying objects, as
	 * both copy and assignment constructors are private to avoid problems.
	 * 
	 * @return New instance with exactly the same information as the current one
	 */
	 virtual Resource* clone() const = 0;

	/**
	 * @brief Hashcode of a filename
	 * 
	 * Calculates the hashcode of the filename string provided.
	 * 
	 * @param filename String which hashcode is to be calculated
	 * @return Hashcode
	 */
	static int hash(const std::string& filename)
	{
		return lge::util::hash(filename);
	}
	
	/**
	 * @brief Load the resource
	 * 
	 * Loads the resource which filename was set on the constructor. Should use
	 * the {@link #setResource(T*)} method.
	 * 
	 * @return true if the resource was loaded successfully; false otherwise
	 */
	virtual bool load() = 0;
	
	/**
	 * @brief Get the filename
	 * 
	 * Returns a const reference to the filename string of the resource.
	 * 
	 * The string returned *MUST NOT* be modified.
	 * 
	 * @return Filename
	 */
	const std::string& getFilename() const
	{
		return filename;
	}
	
	T* getResource() const
	{
		return resource;
	}
	
protected:
	/**
	 * @brief Constructor
	 * 
	 * Sets the filename and the resource pointer to the parameters.
	 * 
	 * This constructor is intended to be used by subclasses when implementing
	 * the {@link clone} method. In most cases, the used won't need to copy the
	 * pointer address, as they would prefer allocating memory for a new resource,
	 * but this way makes it more flexible and gives another choice.
	 * 
	 * @param filename Complete resource location
	 * @param resource Resource pointer
	 * 
	 * @see {@link #Resource(const std::string&)}
	 */
	Resource(const std::string& filename, T* const resource)
			: filename(filename), resource(resource)
	{
	}
	
	/**
	 * @brief Set the resource pointer
	 * 
	 * This method should be called from {@link #load} when loading the physical
	 * resource.
	 * 
	 * @param resource Internal pointer to the resource
	 */
	void setResource(T* const resource)
	{
		this->resource = resource;
	}
	
private:
	Resource(const Resource& resource);
	Resource& operator=(const Resource&); 

	std::string filename;
	T* resource;
	
};

} // namespace

#endif
