/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_RESOURCE_H_
#define _LGE_RESOURCE_H_

namespace lge
{

/**
 * @brief Resources Interface
 * 
 * Provides an empty interface for Resource classes, as they must be specialized
 * and it is useful to have a common non-templatizated interface to be able to
 * use polimorfism.
 * 
 * @author Sergio Rodrigo
 */
class Resource
{
public:
	virtual ~Resource() {}
	
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
	 * @brief Release resource
	 * 
	 * Should release the resource memory and leave it in a consistent state.
	 */
	virtual void release() = 0;
	
	/**
	 * @brief Load the resource
	 * 
	 * Loads the resource which filename was set on the constructor. Should
	 * allocate memory for the resource if it's not already allocated.
	 * 
	 * @return true if the resource was loaded successfully; false otherwise
	 */
	virtual bool load() = 0;

protected:
	Resource() {}
	
};

} // namespace

#endif
