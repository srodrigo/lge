/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_LOGGER_H_
#define _LGE_LOGGER_H_

namespace lge
{

namespace log
{

void debug(const char* module, const char* message, ...);

void info(const char* module, const char* message, ...);

void warn(const char* module, const char* message, ...);

void error(const char* module, const char* message, ...);

} // namespace

} // namespace

#endif
