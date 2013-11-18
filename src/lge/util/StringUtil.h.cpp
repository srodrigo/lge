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

