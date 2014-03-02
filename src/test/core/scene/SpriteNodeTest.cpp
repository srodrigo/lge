/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include <SFML/System/Vector2.hpp>
#include "lge/core/scene/SpriteNode.h"
#include "lge/log/logger.h"

TEST(TestSpriteNode_Update_noChildren)
{
	lge::log::debug("SpriteNodeTest", "*** TestSpriteNode_Update_noChildren ***");
	
	lge::SpriteNode node(TEST_IMAGE_1);
	node.load();
	node.update(MILIS_IN_FRAME_30FPS);
}

TEST(TestSpriteNode_Update_twoChildren)
{
	lge::log::debug("SpriteNodeTest", "*** TestSpriteNode_Update_twoChildren ***");
	
	lge::SpriteNode node(TEST_IMAGE_1);
	node.load();
	lge::SpriteNode* child1 = new lge::SpriteNode(TEST_IMAGE_1);
	child1->load();
	node.addChild(child1);
	lge::SpriteNode* child2 = new lge::SpriteNode(TEST_IMAGE_1);
	child2->load();
	node.addChild(child2);
	
	node.update(MILIS_IN_FRAME_30FPS);
	
	delete child1;
	delete child2;
}

TEST(TestSpriteNode_Draw_noChildren)
{
	lge::log::debug("SpriteNodeTest", "*** TestSpriteNode_Draw_noChildren ***");
	
	lge::SpriteNode node(TEST_IMAGE_1);
	node.load();
	sf::RenderWindow window;
	node.draw(&window);
}

TEST(TestSpriteNode_Draw_twoChildren)
{
	lge::log::debug("SpriteNodeTest", "*** TestSpriteNode_Draw_twoChildren ***");
	
	lge::SpriteNode node(TEST_IMAGE_1);
	node.load();
	lge::SpriteNode* child1 = new lge::SpriteNode(TEST_IMAGE_1);
	child1->load();
	node.addChild(child1);
	lge::SpriteNode* child2 = new lge::SpriteNode(TEST_IMAGE_2);
	child2->load();
	node.addChild(child2);
	
	sf::RenderWindow window;
	node.draw(&window);
	
	delete child1;
	delete child2;
}

TEST(TestSpriteNode_Position_Update_twoChildren)
{
	lge::log::debug("SpriteNodeTest", "*** TestSpriteNode_Position_Update_twoChildren ***");
	
	lge::SpriteNode node(TEST_IMAGE_1);
	node.load();
	lge::SpriteNode* child1 = new lge::SpriteNode(TEST_IMAGE_1);
	child1->load();
	node.addChild(child1);
	lge::SpriteNode* child2 = new lge::SpriteNode(TEST_IMAGE_1);
	child2->load();
	node.addChild(child2);
	
	node.setPosition(342, 64);
	node.update(MILIS_IN_FRAME_30FPS);
	sf::Sprite* sprite = node.getResource()->getResource();
	sf::Vector2f spritePos = sprite->getPosition();
	CHECK(node.getPosX() == spritePos.x);
	CHECK(node.getPosY() == spritePos.y);
	CHECK(node.getPosition() == spritePos);
	
	sf::Sprite* spriteChild1 = child1->getResource()->getResource();
	sf::Vector2f spriteChild1Pos = spriteChild1->getPosition();
	CHECK(child1->getPosX() == spriteChild1Pos.x);
	CHECK(child1->getPosY() == spriteChild1Pos.y);
	CHECK(child1->getPosition() == spriteChild1Pos);
	
	sf::Sprite* spriteChild2 = child2->getResource()->getResource();
	sf::Vector2f spriteChild2Pos = spriteChild2->getPosition();
	CHECK(child2->getPosX() == spriteChild2Pos.x);
	CHECK(child2->getPosY() == spriteChild2Pos.y);
	CHECK(child2->getPosition() == spriteChild2Pos);
	
	delete child1;
	delete child2;
}

TEST(TestSpriteNode_Position_No_Update_twoChildren)
{
	lge::log::debug("SpriteNodeTest", "*** TestSpriteNode_Position_No_Update_twoChildren ***");
	
	lge::SpriteNode node(TEST_IMAGE_1);
	node.load();
	lge::SpriteNode* child1 = new lge::SpriteNode(TEST_IMAGE_1);
	child1->load();
	node.addChild(child1);
	lge::SpriteNode* child2 = new lge::SpriteNode(TEST_IMAGE_1);
	child2->load();
	node.addChild(child2);
	
	node.setPosition(342, 64);
	// No update
	sf::Sprite* sprite = node.getResource()->getResource();
	sf::Vector2f spritePos = sprite->getPosition();
	CHECK(spritePos.x == 0.0f);
	CHECK(spritePos.y == 0.0f);
	
	sf::Sprite* spriteChild1 = child1->getResource()->getResource();
	sf::Vector2f spriteChild1Pos = spriteChild1->getPosition();
	CHECK(spriteChild1Pos.x == 0.0f);
	CHECK(spriteChild1Pos.y == 0.0f);
	
	sf::Sprite* spriteChild2 = child2->getResource()->getResource();
	sf::Vector2f spriteChild2Pos = spriteChild2->getPosition();
	CHECK(spriteChild2Pos.x == 0.0f);
	CHECK(spriteChild2Pos.y == 0.0f);
	
	delete child1;
	delete child2;
}
