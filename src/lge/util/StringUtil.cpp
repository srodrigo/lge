/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/util/StringUtil.h"

#include <stdio.h>
#include <sstream>
#include <algorithm>

namespace lge
{

namespace util
{

int hash(const std::string& str)
{
	int hash = 0;
	
	for (unsigned int i = 0; i < str.length(); i++) {
		hash = 37 * hash + str[i];
	}
	
	return hash;
}

std::vector<std::string>& split(const std::string &str, char delim,
		std::vector<std::string>& tokens)
{
    std::stringstream stream(str);
    std::string item;
    while (std::getline(stream, item, delim)) {
        tokens.push_back(item);
    }
	
    return tokens;
}

std::string& toLowerCase(const std::string& str, std::string& out)
{
	std::transform(str.begin(), str.end(), out.begin(), ::tolower);
	return out;
}

std::string& toUpperCase(const std::string& str, std::string& out)
{
	std::transform(str.begin(), str.end(), out.begin(), ::toupper);
	return out;
}

} // namespace

} // namespace
