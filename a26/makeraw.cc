#include "main.ih"

void makeRaw(string &str)
{	
	for (auto idx = str.begin(); idx != str.end(); ++idx)
	{
		if (*idx == '\\')
			idx = str.insert(idx, '\\') + 1;
	}
}
