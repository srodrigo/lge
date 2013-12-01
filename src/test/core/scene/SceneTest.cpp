/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include "lge/core/scene/Scene.h"
#include "lge/log/logger.h"

TEST(TestScene_update_noRootNode)
{
	lge::log::debug("SceneTest", "*** TestScene_update_noRootNode ***");
	
	lge::Scene scene;
	scene.update();
}

TEST(TestScene_update)
{
	lge::log::debug("SceneTest", "*** TestScene_update ***");
	
	lge::Scene scene;
	
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

TEST(TestScene_draw_noRootNode)
{
	lge::log::debug("SceneTest", "*** TestScene_draw_noRootNode ***");
	
	lge::Scene scene;
	scene.draw();
}

TEST(TestScene_draw)
{
	lge::log::debug("SceneTest", "*** TestScene_draw ***");
	
	lge::Scene scene;
	
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
