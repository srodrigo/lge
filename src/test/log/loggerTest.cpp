/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include "lge/log/logger.h"

TEST(TestLogger_Debug)
{
	lge::log::debug("loggerTest", "*** TestLogger_debug ***");
	
	lge::log::debug("loggerTest", "debug test message");
	lge::log::info("loggerTest", "info test message");
	lge::log::warn("loggerTest", "warn test message");
	lge::log::error("loggerTest", "error test message");
}
