#include "main.ih"

int main(int argc, char **argv)
{
    set<string> myset;
    if (argc == 1)
    {
        Scanner scanner(cin, cout);

        while (scanner.lex())
        {
            myset.insert(scanner.matched());
        }
	}
    else
    {
        for (int idx = 1; idx != argc; ++idx)
        {
            ifstream input;
            input.open(argv[idx]);
            Scanner scanner(input, std::cout);

            //read
            while (scanner.lex())
            {
                myset.insert(scanner.matched());
            }
        }
    }
    //print
    for(string const &idx : myset)
    {
        cout << idx << '\n';
    }
}
