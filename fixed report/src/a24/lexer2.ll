NONBLANK									[a-zA-Z\-]	
NOHOLDBOAT									[^hold|boat]
HOLDBOAT									[hold|boat]

%%
	
											
house/(hold|boat)							{
												std::cout << matched() << '\n';
												return WORD;
											}
											
{NONBLANK}*house{NONBLANK}*					{
												std::cout << matched() << '\n';
												return WORD;
											}
											
\n					// ignore
