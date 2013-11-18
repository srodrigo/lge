/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/util/StringUtil.h"

namespace lge
{

namespace util
{
	int hash(const std::string& str)
	{
		int hash = 0;
		
		for (int i = 0; i < str.length(); i++) {
			hash = 37 * hash + str[i];
		}
		
		return hash;
	}

} // namespace

} // namespace

