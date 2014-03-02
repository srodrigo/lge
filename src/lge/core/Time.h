/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_TIME_H_
#define _LGE_TIME_H_

#include <SFML/Config.hpp>

namespace lge
{

namespace time
{

/**
 * @brief Return current miliseconds
 * 
 * Returns the current time in miliseconds.
 * 
 * @return Current time in miliseconds
 */
sf::Uint32 getCurrentTimeInMilis();

/**
 * @brief Return elapsed miliseconds
 * 
 * Returns the elapsed time in miliseconds since last time the function was called.
 * 
 * @return Elapsed time in miliseconds
 */
sf::Uint32 getElapsedTimeInMilis();

} // namespace
	
} // namespace

#endif
