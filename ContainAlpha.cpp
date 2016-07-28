#include "containAlph.h"

bool ContainAlpha(const std::string& str)
{
	size_t i = 0;
	bool result = false;
	
	for(; i < str.size(); ++i)
	{
		if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') )	
			result = true;
	}	
	
	return result;
}
