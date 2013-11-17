#include "../../test.h"

TEST(TestImageResource_load)
{
	lge::ImageResource image(TEST_IMAGE_1);
	CHECK(image.load());
	CHECK(image.getResource() != NULL);
}

TEST(TestImageResource_clone)
{
	lge::ImageResource image(TEST_IMAGE_1);
	
	lge::ImageResource* newInstance = image.clone();
	CHECK(newInstance->getFilename().compare(image.getFilename()) == 0);
	// As clone creates and loads from disc a new resource, its pointer must point
	// to a different address.
	CHECK(newInstance->getResource() != image.getResource());
}
