/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_STRING_UTIL_H_
#define _LGE_STRING_UTIL_H_

#include <string>

namespace lge
{

namespace util
{
	
/**
 * @brief Hashcode for a string
 * 
 * Returns a hashcode for the string.
 * 
 * Returns 0 if the string is empty.
 * 
 * @param str String which hashcode is calculated
 * @return Hashcode
 */
int hash(const std::string& str);

} // namespace

} // namespace

#endif
