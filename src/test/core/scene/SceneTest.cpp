/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include <SFML/Graphics.hpp>

#include "lge/core/scene/Scene.h"
#include "lge/log/logger.h"

TEST(TestScene_Update_noRootNode)
{
	lge::log::debug("SceneTest", "*** TestScene_Update_noRootNode ***");
	
	sf::RenderWindow win;
	lge::Scene scene(&win);
	scene.update();
}

TEST(TestScene_Update)
{
	lge::log::debug("SceneTest", "*** TestScene_Update ***");
	
	sf::RenderWindow win;
	lge::Scene scene(&win);
	
	lge::SceneNode* root = new lge::SceneNode();
	lge::SceneNode* child1 = new lge::SceneNode();
	root->addChild(child1);
	lge::SceneNode* child2 = new lge::SceneNode();
	root->addChild(child2);
	
	scene.setRootNode(root);
	scene.update();
	
	delete child1;
	delete child2;
	delete root;
}

TEST(TestScene_Draw_noRootNode)
{
	lge::log::debug("SceneTest", "*** TestScene_Draw_noRootNode ***");
	
	sf::RenderWindow win;
	lge::Scene scene(&win);
	scene.draw();
}

TEST(TestScene_Draw)
{
	lge::log::debug("SceneTest", "*** TestScene_Draw ***");
	
	sf::RenderWindow win;
	lge::Scene scene(&win);
	
	lge::SceneNode* root = new lge::SceneNode();
	lge::SceneNode* child1 = new lge::SceneNode();
	root->addChild(child1);
	lge::SceneNode* child2 = new lge::SceneNode();
	root->addChild(child2);
	
	scene.setRootNode(root);
	scene.draw();
	
	delete child1;
	delete child2;
	delete root;
}
