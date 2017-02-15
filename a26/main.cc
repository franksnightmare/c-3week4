#include "Scanner.h"

using namespace std;

string dequote(string const &str)
{
	size_t start = str.find('\"') + 1;
	return str.substr(start, str.length() - (start + 1));
}

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

void makeRaw(string &str)
{	
	for (auto idx = str.begin(); idx != str.end(); ++idx)
	{
		if (*idx == '\\')
			idx = str.insert(idx, '\\') + 1;
	}
}

int main(int argc, char **argv)
{
	Scanner scanner;
	
	string str;
	while (int token = scanner.lex())
	{
		switch (token)
		{
			// Case for normal string
			case (STRING):
				str += scanner.matched();
				str = dequote(str);
				cout << str;
				str = string{};
				// cout << "grabbed(1, asfsdf.sdf)";
				// do magick and write to file(s)
				break;
			
			// Case for raw string
			case (RSTRING):
				str += scanner.matched();
				str = dequote(str);
				makeRaw(str);
				cout << str;
				str = string{};
				// cout << "grabbed(1, asfsdf.sdf)";
				// do magick and write to file(s)
				break;
			
			case (STRING_SEG):
				{
					string temp(scanner.matched());
					temp = temp.substr(0, temp.length() - 1);
					str += temp.substr(0, temp.find_last_of('\"'));
				}
				break;
			
			// Anything else
			default:
				cout << scanner.matched();
				// write to file
				break;
		}
	}
}
