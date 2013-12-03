/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include "lge/core/resource/SpriteResource.h"

TEST(TestSpriteResource_Load)
{
	lge::log::debug("SpriteResourceTest", "*** TestSpriteResource_Load ***");
	
	lge::SpriteResource sprite(TEST_IMAGE_1);
	CHECK(sprite.load());
}

TEST(TestSpriteResource_Load_fail)
{
	lge::log::debug("SpriteResourceTest", "*** TestSpriteResource_Load_fail ***");
	
	lge::SpriteResource sprite("");
	CHECK(!sprite.load());
}

TEST(TestSpriteResource_Clone)
{
	lge::log::debug("SpriteResourceTest", "*** TestSpriteResource_Clone ***");
	
	lge::SpriteResource sprite(TEST_IMAGE_1);
	
	lge::SpriteResource* newInstance = sprite.clone();
	CHECK(newInstance->getFilename().compare(sprite.getFilename()) == 0);
	CHECK(sprite.getResource() == NULL);
	CHECK(newInstance->getResource() == NULL);
}

TEST(TestSpriteResource_Clone_afterLoad)
{
	lge::log::debug("SpriteResourceTest", "*** TestSpriteResource_Clone_afterLoad ***");
	
	lge::SpriteResource sprite(TEST_IMAGE_1);
	sprite.load();
	
	lge::SpriteResource* newInstance = sprite.clone();
	CHECK(newInstance->getFilename().compare(sprite.getFilename()) == 0);
	CHECK(newInstance->getResource() != sprite.getResource());
	
	// Quick (but not very accurate) check to compare the resources
	sf::Sprite* res = sprite.getResource();
	sf::Sprite* newRes = sprite.getResource();
	CHECK(res->getTexture()->getSize().x == newRes->getTexture()->getSize().x);
	CHECK(res->getTexture()->getSize().y == newRes->getTexture()->getSize().y);
}

TEST(TestSpriteResource_Clone_beforeLoad)
{
	lge::log::debug("SpriteResourceTest", "*** TestSpriteResource_Clone_beforeLoad ***");
	
	lge::SpriteResource sprite(TEST_IMAGE_1);
	
	lge::SpriteResource* newInstance = sprite.clone();
	CHECK(newInstance->getFilename().compare(sprite.getFilename()) == 0);
	
	sprite.load();
	// Still different pointer addresses
	CHECK(newInstance->getResource() != sprite.getResource());
	
	// Quick (but not very accurate) check to compare the resources
	sf::Sprite* res = sprite.getResource();
	sf::Sprite* newRes = sprite.getResource();
	CHECK(res->getTexture()->getSize().x == newRes->getTexture()->getSize().x);
	CHECK(res->getTexture()->getSize().y == newRes->getTexture()->getSize().y);
}

TEST(TestSpriteResource_Release)
{
	lge::log::debug("SpriteResourceTest", "*** TestSpriteResource_Release ***");
	
	lge::SpriteResource sprite(TEST_IMAGE_1, false);
	sprite.load();
	CHECK(sprite.getResource() != NULL);
	sprite.release();
	CHECK(sprite.getResource() == NULL);
}
