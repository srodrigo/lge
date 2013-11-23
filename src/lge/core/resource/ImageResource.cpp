/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/core/resource/ImageResource.h"

#include <stdio.h>

namespace lge
{

ImageResource::ImageResource(const std::string& filename)
			: Resource(filename)
{
}

ImageResource::ImageResource(const std::string& filename, sf::Image* const resource)
		: Resource(filename, resource)
{
}

ImageResource::ImageResource(const std::string& filename, bool releaseResource)
		: Resource(filename, releaseResource)
{
}

ImageResource::~ImageResource()
{
	printf("~ImageResource()\n");
}

ImageResource* ImageResource::clone() const
{
	printf("Cloning ImageResource\n");
	ImageResource* newInstance = new ImageResource(getFilename());
	if (getResource() != NULL) {
		// Force to create and load a new resource
		newInstance->load();
	}
	return newInstance;
}

bool ImageResource::load()
{
	if (getResource() == NULL) {
		printf("Creating ImageResource\n");
		setResource(new sf::Image());
	}
	
	printf("Loading ImageResource \"%s\"\n", getFilename().c_str());
	return getResource()->loadFromFile(getFilename());
}

} // namespace
