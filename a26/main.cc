#include "main.ih"

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cerr << "Please give your c/c++ file path.\n";
		return 1;
	}
	
	Scanner scanner;
	Writer writer;
	
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
