/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include "lge/core/resource/ResourceLoader.h"
#include "lge/core/resource/ImageResource.h"

TEST(TestResourceLoader_Load)
{
	lge::log::debug("ResourceLoaderTest", "*** TestResourceLoader_Load ***");
	
	lge::ResourceLoader resLoader;
	const lge::ImageResource image = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.currentUsages(image) == 1);
}

TEST(TestResourceLoader_Load_fail)
{
	lge::log::debug("ResourceLoaderTest", "*** TestResourceLoader_Load_fail ***");
	
	lge::ResourceLoader resLoader;
	const lge::ImageResource image = resLoader.load<lge::ImageResource>("");
	// Stores empty resources
	CHECK(resLoader.currentUsages(image) == 1);
}

TEST(TestResourceLoader_Load_severalFiles)
{
	lge::log::debug("ResourceLoaderTest", "*** TestResourceLoader_Load_severalFiles ***");
	
	lge::ResourceLoader resLoader;
	const lge::ImageResource image1 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.currentUsages(image1) == 1);
	
	const lge::ImageResource image2 = resLoader.load<lge::ImageResource>(TEST_IMAGE_2);
	CHECK(resLoader.currentUsages(image2) == 1);

	const lge::ImageResource image3 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.currentUsages(image1) == 2);
	CHECK(resLoader.currentUsages(image3) == 2);
	
	const lge::ImageResource image4 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.currentUsages(image1) == 3);
	CHECK(resLoader.currentUsages(image4) == 3);
	
	const lge::ImageResource image5 = resLoader.load<lge::ImageResource>(TEST_IMAGE_2);
	CHECK(resLoader.currentUsages(image2) == 2);
	CHECK(resLoader.currentUsages(image5) == 2);
}

TEST(TestResourceLoader_Load_severalFiles_fail)
{
	lge::log::debug("ResourceLoaderTest", "*** TestResourceLoader_Load_severalFiles_fail ***");
	
	lge::ResourceLoader resLoader;
	const lge::ImageResource image1 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.currentUsages(image1) == 1);
	
	const lge::ImageResource image2 = resLoader.load<lge::ImageResource>(TEST_IMAGE_2);
	CHECK(resLoader.currentUsages(image2) == 1);

	// Fail
	const lge::ImageResource image3 = resLoader.load<lge::ImageResource>("");
	CHECK(resLoader.currentUsages(image3) == 1);
	
	const lge::ImageResource image4 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.currentUsages(image1) == 2);
	CHECK(resLoader.currentUsages(image4) == 2);
	
	// Fail
	const lge::ImageResource image5 = resLoader.load<lge::ImageResource>(TEST_IMAGE_2);
	CHECK(resLoader.currentUsages(image2) == 2);
	CHECK(resLoader.currentUsages(image5) == 2);
}

TEST(TestResourceLoader_Release)
{
	lge::log::debug("ResourceLoaderTest", "*** TestResourceLoader_Release ***");
	
	lge::ResourceLoader resLoader;
	const lge::ImageResource image1 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);	
	const lge::ImageResource image2 = resLoader.load<lge::ImageResource>(TEST_IMAGE_2);
	const lge::ImageResource image3 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);	
	const lge::ImageResource image4 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	const lge::ImageResource image5 = resLoader.load<lge::ImageResource>(TEST_IMAGE_2);
	
	resLoader.release(image1);
	CHECK(resLoader.currentUsages(image1) == 2);
	resLoader.release(image2);
	CHECK(resLoader.currentUsages(image2) == 1);
	resLoader.release(image3);
	CHECK(resLoader.currentUsages(image3) == 1);
	resLoader.release(image4);
	CHECK(resLoader.currentUsages(image4) == 0);
	resLoader.release(image5);
	CHECK(resLoader.currentUsages(image5) == 0);
}

TEST(TestResourceLoader_Release_fail)
{
	lge::log::debug("ResourceLoaderTest", "*** TestResourceLoader_Release_fail ***");
	
	lge::ResourceLoader resLoader;
	const lge::ImageResource image1 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	
	CHECK(resLoader.release(image1));
	CHECK(resLoader.currentUsages(image1) == 0);
	
	// Release having being already released
	bool image1ReleasedAgain = resLoader.release(image1);
	CHECK(!image1ReleasedAgain);
	CHECK(resLoader.currentUsages(image1) == 0);
}

TEST(TestResourceLoader_Count_zero)
{
	lge::log::debug("ResourceLoaderTest", "*** TestResourceLoader_Count_zero ***");
	
	lge::ResourceLoader resLoader;
	
	const lge::ImageResource image1 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	lge::ImageResource image2(TEST_IMAGE_2);
	CHECK(resLoader.currentUsages(image2) == 0);
}

TEST(TestResourceLoader_Count_one)
{
	lge::log::debug("ResourceLoaderTest", "*** TestResourceLoader_Count_one ***");
	
	lge::ResourceLoader resLoader;
	
	const lge::ImageResource image1 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.currentUsages(image1) == 1);
	CHECK(image1.getResource() != NULL);
}

TEST(TestResourceLoader_Destructor)
{
	lge::log::debug("ResourceLoaderTest", "*** TestResourceLoader_Destructor ***");
	
	lge::ResourceLoader resLoader;
	const lge::ImageResource image1 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);	
	const lge::ImageResource image2 = resLoader.load<lge::ImageResource>(TEST_IMAGE_2);
	const lge::ImageResource image3 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);	
	const lge::ImageResource image4 = resLoader.load<lge::ImageResource>(TEST_IMAGE_1);
	const lge::ImageResource image5 = resLoader.load<lge::ImageResource>(TEST_IMAGE_2);
	
	resLoader.release(image1);
	CHECK(resLoader.currentUsages(image1) == 2);
	CHECK(image1.getResource() != NULL);
	resLoader.release(image2);
	CHECK(resLoader.currentUsages(image2) == 1);
	CHECK(image2.getResource() != NULL);
	resLoader.release(image3);
	CHECK(resLoader.currentUsages(image3) == 1);
	CHECK(image3.getResource() != NULL);
}
