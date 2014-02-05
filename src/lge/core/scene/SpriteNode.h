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
	explicit SpriteNode(const std::string& filename);
	virtual ~SpriteNode();
	
	/**
	 * @brief Update the node
	 * 
	 * Updates the current node.
	 */
	virtual void update();
	/**
	 * @brief Draw the node
	 * 
	 * Draws the current node.
	 */
	virtual void draw(sf::RenderWindow* window) const;
	
	/**
	 * @brief Load the node
	 * 
	 * Loads the current node.
	 * 
	 * @return Whether the node was successfully loaded
	 */
	virtual bool load();
	
private:
	SpriteResource sprite;
	
};

} // namespace

#endif
