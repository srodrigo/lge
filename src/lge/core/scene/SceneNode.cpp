/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/core/scene/SceneNode.h"

#include "lge/log/logger.h"

namespace lge
{
	
void SceneNode::addChild(SceneNode* child)
{
	lge::log::debug("SceneNode::addChild", "Adding child");
	
	children.push_back(child);
}

bool SceneNode::removeChild(SceneNode* child)
{
	lge::log::debug("SceneNode::removeChild", "Removing child");
	
	for (std::vector<SceneNode*>::iterator iter = children.begin();
			iter != children.end();
			++iter) {
		if (*iter == child) {
			children.erase(iter);
			lge::log::debug("SceneNode::removeChild", "Child removed");
			return true;
		}
	}
	lge::log::warn("SceneNode::removeChild", "Child not found");
	return false;
}

int SceneNode::countChildren() const
{
	return children.size();
}

void SceneNode::update()
{
	lge::log::debug("SceneNode::update", "Updating children");
	
	for (std::vector<SceneNode*>::iterator iter = children.begin();
			iter != children.end();
			++iter) {
		(*iter)->update();
	}
	
	lge::log::debug("SceneNode::update", "Updating node");
}

void SceneNode::draw(sf::RenderWindow* window) const
{
	lge::log::debug("SceneNode::draw", "Drawing children");
	
	for (std::vector<SceneNode*>::const_iterator iter = children.begin();
			iter != children.end();
			++iter) {
		(*iter)->draw(window);
	}
	
	lge::log::debug("SceneNode::draw", "Drawing node");
}

void SceneNode::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

} // namespace
