#include "main.ih"

char escapeChar(char rawChar)
{
	switch(rawChar)
	{
		case('\?'):
			return '?';
		case('\a'):
			return 'a';
		case('\b'):
			return 'b';
		case('\f'):
			return 'f';
		case('\n'):
			return 'n';
		case('\r'):
			return 'r';
		case('\t'):
			return 't';
		case('\v'):
			return 'v';
	}
	return rawChar;
}
