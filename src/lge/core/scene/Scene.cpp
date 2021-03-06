/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/core/scene/Scene.h"

#include <stdlib.h>
#include "lge/core/Time.h"
#include "lge/log/logger.h"

namespace lge
{

void Scene::update()
{
	lge::log::debug("Scene::update", "Updating scene");
	
	if (rootNode) {
		rootNode->update(lge::time::getElapsedTimeInMilis());
	}
}

void Scene::draw() const
{
	lge::log::debug("Scene::draw", "Drawing scene");
	
	window->clear();
	
	if (rootNode) {
		rootNode->draw(window);
	}
	
	window->display();
}

} // namespace
