/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_IMAGE_RESOURCE_H_
#define _LGE_IMAGE_RESOURCE_H_

#include "lge/core/resource/Resource.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace lge
{

/**
 * @brief SFML Sprite resource wrapper
 * 
 * Wraps a SFML Sprite.
 * 
 * @see Resource
 * 
 * @author Sergio Rodrigo
 */
class SpriteResource : public Resource<sf::Sprite>
{
public:
	explicit SpriteResource(const std::string& filename);
	
	explicit SpriteResource(const std::string& filename, bool releaseResource);
	
	virtual ~SpriteResource();
	
	virtual SpriteResource* clone() const;
	
	/**
	 * @brief Loads a SFML Sprite
	 * 
	 * Allocates memory for a new SFML Sprite and loads the image from disk.
	 * 
	 * @return true if the resource was loaded successfully; false otherwise
	 */
	virtual bool load();
	
	/**
	 * @brief Set Resource position
	 * 
	 * Sets the position of the resource.
	 *
	 * @param x Pos x
	 * @param y Pos y
	 */
	virtual void setPosition(int x, int y);
		
protected:
	SpriteResource(const std::string& filename, sf::Sprite* const resource);
	
	SpriteResource& operator=(const SpriteResource& res);
	
private:
	sf::Texture texture;

};

} // namespace

#endif
