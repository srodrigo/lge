#include "../../test.h"

TEST(TestResourceLoader_Load)
{
	printf("\n*** TestResourceLoader_Load ***\n");
	
	lge::core::ResourceLoader resLoader;
	const lge::core::ImageResource* image1 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.countResources(image1) == 1);
	
	const lge::core::ImageResource* image2 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_2);
	CHECK(resLoader.countResources(image2) == 1);

	const lge::core::ImageResource* image3 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.countResources(image1) == 2);
	CHECK(resLoader.countResources(image3) == 2);
	
	const lge::core::ImageResource* image4 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);
	CHECK(resLoader.countResources(image1) == 3);
	CHECK(resLoader.countResources(image4) == 3);
	
	const lge::core::ImageResource* image5 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_2);
	CHECK(resLoader.countResources(image2) == 2);
	CHECK(resLoader.countResources(image5) == 2);
}

TEST(TestResourceLoader_Release)
{
	printf("\n*** TestResourceLoader_Release ***\n");
	
	lge::core::ResourceLoader resLoader;
	const lge::core::ImageResource* image1 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);	
	const lge::core::ImageResource* image2 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_2);
	const lge::core::ImageResource* image3 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);	
	const lge::core::ImageResource* image4 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);
	const lge::core::ImageResource* image5 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_2);
	
	resLoader.release(image1);
	CHECK(resLoader.countResources(image1) == 2);
	resLoader.release(image2);
	CHECK(resLoader.countResources(image2) == 1);
	resLoader.release(image3);
	CHECK(resLoader.countResources(image3) == 1);
	resLoader.release(image4);
	CHECK(resLoader.countResources(image4) == 0);
	resLoader.release(image5);
	CHECK(resLoader.countResources(image5) == 0);
}

TEST(TestResourceLoader_Release_SeveralTimes)
{
	printf("\n*** TestResourceLoader_Release_SeveralTimes ***\n");
	
	lge::core::ResourceLoader resLoader;
	const lge::core::ImageResource* image1 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);
	
	bool image1Released = resLoader.release(image1);
	CHECK(image1Released);
	CHECK(resLoader.countResources(image1) == 0);
	
	// Release having being already released
	bool image1ReleasedAgain = resLoader.release(image1);
	CHECK(!image1ReleasedAgain);
	CHECK(resLoader.countResources(image1) == 0);
}

TEST(TestResourceLoader_Destructor)
{
	printf("\n*** TestResourceLoader_Destructor ***\n");
	
	lge::core::ResourceLoader resLoader;
	const lge::core::ImageResource* image1 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);	
	const lge::core::ImageResource* image2 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_2);
	const lge::core::ImageResource* image3 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);	
	const lge::core::ImageResource* image4 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_1);
	const lge::core::ImageResource* image5 = resLoader.load<lge::core::ImageResource>(TEST_IMAGE_2);
	
	resLoader.release(image1);
	CHECK(resLoader.countResources(image1) == 2);
	resLoader.release(image2);
	CHECK(resLoader.countResources(image2) == 1);
	resLoader.release(image3);
	CHECK(resLoader.countResources(image3) == 1);
}
