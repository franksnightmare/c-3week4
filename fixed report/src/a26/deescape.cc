#include "main.ih"

void deEscape(string &str)
{	
	for (auto idx = str.begin();
		idx != str.end(); ++idx)
	{
		if (isEscape(*idx))
		{
			*idx = escapeChar(*idx);
			idx = str.insert(idx, '\\') + 1;
		}
	}
}
