#include "Scanner.h"

using namespace std;

int main(int argc, char **argv)
{
	Scanner scanner;
	
	size_t counter = 0;
	int token;
	while ((token = scanner.lex()) != EOF)
	{
		++counter;
		switch (token)
		{
			case(STRING):
				cout << "STRING";
				cout << scanner.matched() << endl;
				break;
			case(RSTRING):
				cout << "RSTRING\n";
				break;
			case(STRING_SEG):
				cout << "RSTRING\n";
				break;
			case(COMMENT):
				cout << "COMMENT\n";
				break;
		}
		if (counter == 100)
			break;
	}
}
