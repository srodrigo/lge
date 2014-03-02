/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_SPRITE_NODE_H_
#define _LGE_SPRITE_NODE_H_

#include "lge/core/scene/SceneNode.h"
#include "lge/core/resource/SpriteResource.h"

#include <SFML/Graphics.hpp>

#include <vector>

namespace lge
{

/**
 * @brief Represents a Sprite node
 * 
 * Represents a sprite node and provides operations to load, update and draw it.
 * 
 * Contains a SpriteResource instance.
 * 
 * @author Sergio Rodrigo
 */
class SpriteNode : public SceneNode
{
public:
	explicit SpriteNode(const std::string& filename)
			: sprite(filename) {}
	
	virtual ~SpriteNode() {}
	
	virtual void update(sf::Int32 delta);

	virtual void draw(sf::RenderWindow* window) const;
	
	virtual bool load();
	
	SpriteResource* getResource() { return &sprite; }
	
private:
	SpriteResource sprite;
	
};

} // namespace

#endif
