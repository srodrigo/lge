/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "Time.h"

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace lge
{

namespace time
{

sf::Clock clock;

sf::Uint32 getCurrentTimeInMilis()
{
	sf::Time now;
	return now.asMilliseconds();
}

sf::Uint32 getElapsedTimeInMilis()
{
	// What about the first call?
	return clock.restart().asMilliseconds();
}

} // namespace

} // namespace
