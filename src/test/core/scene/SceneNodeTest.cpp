/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include "lge/core/scene/SceneNode.h"
#include "lge/log/logger.h"

TEST(TestSceneNode_noChildren)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_noChildren ***");
	
	lge::SceneNode node;
	CHECK(node.countChildren() == 0);
}

TEST(TestSceneNode_AddChild_one)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_AddChild_one ***");
	
	lge::SceneNode node;
	lge::SceneNode* child = new lge::SceneNode();
	node.addChild(child);
	CHECK(node.countChildren() == 1);
	
	delete child;
}

TEST(TestSceneNode_AddChild_two)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_AddChild_two ***");
	
	lge::SceneNode node;
	lge::SceneNode* child1 = new lge::SceneNode();
	node.addChild(child1);
	lge::SceneNode* child2 = new lge::SceneNode();
	node.addChild(child2);
	CHECK(node.countChildren() == 2);
	
	delete child1;
	delete child2;
}

TEST(TestSceneNode_RemoveChild_empty)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_RemoveChild_empty ***");
	
	lge::SceneNode node;
	lge::SceneNode* child = new lge::SceneNode();
	CHECK(!node.removeChild(child));
	CHECK(node.countChildren() == 0);
	
	delete child;
}

TEST(TestSceneNode_RemoveChild_one)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_RemoveChild_one ***");
	
	lge::SceneNode node;
	lge::SceneNode* child = new lge::SceneNode();
	node.addChild(child);
	CHECK(node.removeChild(child));
	CHECK(node.countChildren() == 0);
	
	delete child;
}

TEST(TestSceneNode_RemoveChild_oneOutOfTwo)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_RemoveChild_oneOutOfTwo ***");
	
	lge::SceneNode node;
	lge::SceneNode* child1 = new lge::SceneNode();
	node.addChild(child1);
	lge::SceneNode* child2 = new lge::SceneNode();
	node.addChild(child2);
	CHECK(node.removeChild(child1));
	CHECK(node.countChildren() == 1);
	
	delete child1;
	delete child2;
}

TEST(TestSceneNode_RemoveChild_oneOutOfTwoTwice)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_RemoveChild_oneOutOfTwoTwice ***");
	
	lge::SceneNode node;
	lge::SceneNode* child1 = new lge::SceneNode();
	node.addChild(child1);
	lge::SceneNode* child2 = new lge::SceneNode();
	node.addChild(child2);
	CHECK(node.removeChild(child1));
	CHECK(!node.removeChild(child1));
	CHECK(node.countChildren() == 1);
	
	delete child1;
	delete child2;
}

TEST(TestSceneNode_Update_noChildren)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_Update_noChildren ***");
	
	lge::SceneNode node;
	node.update(MILIS_IN_FRAME_30FPS);
}

TEST(TestSceneNode_Update_twoChildren)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_Update_twoChildren ***");
	
	lge::SceneNode node;
	lge::SceneNode* child1 = new lge::SceneNode();
	node.addChild(child1);
	lge::SceneNode* child2 = new lge::SceneNode();
	node.addChild(child2);
	
	node.update(MILIS_IN_FRAME_30FPS);
	
	delete child1;
	delete child2;
}

TEST(TestSceneNode_Draw_noChildren)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_Draw_noChildren ***");
	
	lge::SceneNode node;
	sf::RenderWindow window;
	node.draw(&window);
}

TEST(TestSceneNode_Draw_twoChildren)
{
	lge::log::debug("SceneNodeTest", "*** TestSceneNode_Draw_twoChildren ***");
	
	lge::SceneNode node;
	lge::SceneNode* child1 = new lge::SceneNode();
	node.addChild(child1);
	lge::SceneNode* child2 = new lge::SceneNode();
	node.addChild(child2);
	
	sf::RenderWindow window;
	node.draw(&window);
	
	delete child1;
	delete child2;
}

TEST(TestSceneNode_SetPosition_Two_Variables)
{
	lge::log::debug("TestSceneNode", "*** TestSceneNode_SetPosition_Two_Variables ***");
	
	lge::SceneNode node;
	float posX = 342.5f;
	float posY = 64.3f;
	node.setPosition(posX, posY);
	CHECK(node.getPosX() == posX);
	CHECK(node.getPosY() == posY);
	CHECK(node.getPosition() == sf::Vector2f(posX, posY));
}

TEST(TestSceneNode_SetPosition_Vector)
{
	lge::log::debug("TestSceneNode", "*** TestSceneNode_SetPosition_Vector ***");
	
	lge::SceneNode node;
	float posX = 342.5f;
	float posY = 64.3f;
	sf::Vector2f vectorPos(posX, posY);
	node.setPosition(vectorPos);
	CHECK(node.getPosX() == posX);
	CHECK(node.getPosY() == posY);
	CHECK(node.getPosition() == vectorPos);
}
