#include "ImageResource.h"

#include <stdio.h>

namespace lge
{

namespace core
{

ImageResource::ImageResource(const std::string& filename)
			: Resource(filename)
{
}

ImageResource::ImageResource(const std::string& filename, sf::Image* const resource)
		: Resource(filename, resource)
{
}

ImageResource::~ImageResource()
{
	printf("~ImageResource()\n");
}

ImageResource* ImageResource::clone() const
{
	return new ImageResource(getFilename(), getResource());
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

} // namespace
