#include "main.ih"

bool isEscape(char rawChar)
{
	switch(rawChar)
	{
		case('\''):
			return true;
		case('\"'):
			return true;
		case('\?'):
			return true;
		case('\\'):
			return true;
		case('\a'):
			return true;
		case('\b'):
			return true;
		case('\f'):
			return true;
		case('\n'):
			return true;
		case('\r'):
			return true;
		case('\t'):
			return true;
		case('\v'):
			return true;
	}
	return false;
}
