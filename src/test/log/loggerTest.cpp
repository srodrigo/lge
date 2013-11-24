/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "test/test.h"

#include <stdio.h>

#include "lge/log/logger.h"

TEST(TestLogger_debug)
{
	printf("\n*** TestLogger_debug ***\n");
	
	lge::log::debug("debug test module", "debug test message");
	lge::log::info("info test module", "info test message");
	lge::log::warn("warn test module", "warn test message");
	lge::log::error("error test module", "error test message");
}
