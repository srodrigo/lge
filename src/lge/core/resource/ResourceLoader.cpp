/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/core/resource/ResourceLoader.h"

namespace lge
{

ResourceLoader::ResourceLoader()
{
}

ResourceLoader::~ResourceLoader()
{
	int released = 0;
	for (ResourceContainer::iterator iter = resources.begin(); iter != resources.end(); iter++) {
		delete iter->second.ptr;
		resources.erase(iter);
		released++;
	}
	
	if (released > 0) {
		printf("Released %d resources not released manually\n", released);
	}
}

} // namespace
