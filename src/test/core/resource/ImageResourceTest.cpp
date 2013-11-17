#include "../../test.h"

TEST(TestImageResource_load)
{
	lge::core::ImageResource image(TEST_IMAGE_1);
	CHECK(image.load());
	CHECK(image.getResource() != NULL);
}

TEST(TestImageResource_clone)
{
	lge::core::ImageResource image(TEST_IMAGE_1);
	
	lge::core::ImageResource* newInstance = image.clone();
	CHECK(newInstance->getFilename().compare(image.getFilename()) == 0);
	CHECK(newInstance->getResource() == image.getResource());
}
