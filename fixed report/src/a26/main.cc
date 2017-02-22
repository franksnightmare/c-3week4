#include "main.ih"

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cerr << "Please give your c/c++ file path.\n";
		return 1;
	}
	
	ifstream input;
	input.open(argv[1]);
	Scanner scanner(input, cout);
	Writer writer(argv[1]);
	
	string str;
	string delimeter;
	while (int token = scanner.lex())
	{
		switch (token)
		{
			// Case for normal string
			case (STRING):
				str += scanner.matched();
				processString(str, writer);
				break;
			
			// Case for raw string
			case (RSTRING):
				str += scanner.matched();
				if (!checkDelimeter(delimeter, str))
					break;
				str = str.substr(0,
					str.find_last_of(')')) + '\"';
				processString(str, writer, makeRaw);
				delimeter = string{};
				break;
			
			case (RSTRING_START):
				str += scanner.matched();
				delimeter = str.substr(2,str.length() - 1);
				str = "\"";
				break;
			
			case (STRING_SEG):
				{
					string temp(scanner.matched());
					// remove second starting quote
					temp = temp.substr(0, temp.length() - 1);
					// add until first closing quote
					str += temp.substr(0,
						temp.find_last_of('\"'));
				}
				break;
			
			// Anything else
			default:
				writer.writeCode(scanner.matched());
				break;
		}
	}
}
