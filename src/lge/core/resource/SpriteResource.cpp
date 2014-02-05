/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/core/resource/SpriteResource.h"

#include <stdio.h>

#include "lge/log/logger.h"

namespace lge
{

SpriteResource::SpriteResource(const std::string& filename)
			: Resource(filename)
{
}

SpriteResource::SpriteResource(const std::string& filename, sf::Sprite* const resource)
		: Resource(filename, resource)
{
}

SpriteResource::SpriteResource(const std::string& filename, bool releaseResource)
		: Resource(filename, releaseResource)
{
}

SpriteResource::~SpriteResource()
{
	lge::log::debug("SpriteResource::~SpriteResource", "Destroying SpriteResource");
}

SpriteResource* SpriteResource::clone() const
{
	lge::log::debug("SpriteResource::clone", "Cloning SpriteResource");
	SpriteResource* newInstance = new SpriteResource(getFilename());
	if (getResource() != NULL) {
		// Force to create and load a new resource
		newInstance->load();
	}
	return newInstance;
}

bool SpriteResource::load()
{
	bool success = false;
	if (getResource() == NULL) {
		lge::log::debug("SpriteResource::load", "Creating SpriteResource");
		texture = sf::Texture();
		lge::log::debug("SpriteResource::load", "Loading SpriteResource \"%s\"\n", getFilename().c_str());
		success = texture.loadFromFile(getFilename());
		setResource(new sf::Sprite(texture));
	}
	
	return success;
}

} // namespace
