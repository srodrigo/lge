/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include "lge/core/resource/ImageResource.h"

TEST(TestImageResource_load)
{
	printf("\n*** TestImageResource_load ***\n");
	
	lge::ImageResource image(TEST_IMAGE_1);
	CHECK(image.load());
}

TEST(TestImageResource_loadFail)
{
	printf("\n*** TestImageResource_loadFail ***\n");
	
	lge::ImageResource image("");
	CHECK(!image.load());
}

TEST(TestImageResource_clone)
{
	printf("\n*** TestImageResource_clone ***\n");
	
	lge::ImageResource image(TEST_IMAGE_1);
	
	lge::ImageResource* newInstance = image.clone();
	CHECK(newInstance->getFilename().compare(image.getFilename()) == 0);
	CHECK(image.getResource() == NULL);
	CHECK(newInstance->getResource() == NULL);
}

TEST(TestImageResource_cloneAfterLoad)
{
	printf("\n*** TestImageResource_cloneAfterLoad ***\n");
	
	lge::ImageResource image(TEST_IMAGE_1);
	image.load();
	
	lge::ImageResource* newInstance = image.clone();
	CHECK(newInstance->getFilename().compare(image.getFilename()) == 0);
	CHECK(newInstance->getResource() != image.getResource());
	
	// Quick (but not very accurate) check to compare the resources
	sf::Image* res = image.getResource();
	sf::Image* newRes = image.getResource();
	CHECK(res->getSize().x == newRes->getSize().x);
	CHECK(res->getSize().y == newRes->getSize().y);
}

TEST(TestImageResource_cloneBeforeLoad)
{
	printf("\n*** TestImageResource_clone ***\n");
	
	lge::ImageResource image(TEST_IMAGE_1);
	
	lge::ImageResource* newInstance = image.clone();
	CHECK(newInstance->getFilename().compare(image.getFilename()) == 0);
	
	image.load();
	// Still different pointer addresses
	CHECK(newInstance->getResource() != image.getResource());
	
	// Quick (but not very accurate) check to compare the resources
	sf::Image* res = image.getResource();
	sf::Image* newRes = image.getResource();
	CHECK(res->getSize().x == newRes->getSize().x);
	CHECK(res->getSize().y == newRes->getSize().y);
}

TEST(TestImageResource_release)
{
	printf("\n*** TestImageResource_release ***\n");
	
	lge::ImageResource image(TEST_IMAGE_1, false);
	image.load();
	CHECK(image.getResource() != NULL);
	image.release();
	CHECK(image.getResource() == NULL);
}
