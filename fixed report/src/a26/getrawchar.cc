#include "main.ih"

char getRawChar(char rawChar)
{
	switch(rawChar)
	{
		case('n'):
			return '\n';
		case('t'):
			return '\t';
		case('\\'):
			return '\\';
		case('\"'):
			return '\"';
		case('\''):
			return '\'';
	}
	return ' ';
}
