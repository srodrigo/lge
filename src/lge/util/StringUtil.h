/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_STRING_UTIL_H_
#define _LGE_STRING_UTIL_H_

#include <string>
#include <vector>

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

/**
 * @brief Split a string into tokens
 * 
 * Splits a string into tokens separated by a delimiter. The results is stored
 * into the vector parameter, so an empty vector is expected.
 * 
 * @param str String to split
 * @param delim Delimiter character
 * @param tokens Vector the results will be appended to
 * @return Reference to tokens param
 */
std::vector<std::string>& split(const std::string &str, char delim,
		std::vector<std::string>& tokens);

/**
 * @brief Convert the string to lower case
 * 
 * Converts the source string to lower case using the outout string.
 * 
 * @param str Source
 * @param out Output
 * @return Lower case string (reference to out param)
 */
std::string& toLowerCase(const std::string& str, std::string& out);

/**
 * @brief Convert the string to upper case
 * 
 * Converts the source string to upper case using the outout string.
 * 
 * @param str Source
 * @param out Output
 * @return Upper case string (reference to out param)
 */
std::string& toUpperCase(const std::string& str, std::string& out);

} // namespace

} // namespace

#endif
