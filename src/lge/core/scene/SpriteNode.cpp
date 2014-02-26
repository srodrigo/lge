/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/core/scene/SpriteNode.h"

#include "lge/log/logger.h"

namespace lge
{

void SpriteNode::update()
{
	lge::SceneNode::update();
	
	sprite.setPosition(getPosX(), getPosY());
}

void SpriteNode::draw(sf::RenderWindow* window) const
{
	lge::log::debug("SpriteNode::draw", "Drawing using parent");
	
	lge::SceneNode::draw(window);
	
	sf::Sprite* resource = sprite.getResource();
	if (resource == NULL) {
		lge::log::warn("SpriteNode::draw", "Attempting to draw a null sprite");
		return;
	}
	lge::log::debug("SpriteNode::draw", "Drawing Sprite node");
	window->draw(*resource);
}

bool SpriteNode::load()
{
	return sprite.load();
}

} // namespace
