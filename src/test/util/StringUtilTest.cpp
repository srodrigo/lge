/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include "lge/util/StringUtil.h"

TEST(TestStringUtil_Hash_Empty)
{
	CHECK(lge::util::hash("") == 0);
}

TEST(TestStringUtil_Hash_NonEmpty)
{
	CHECK(lge::util::hash(TEST_IMAGE_1) != 0);
}
