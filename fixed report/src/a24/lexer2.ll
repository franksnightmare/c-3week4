NONBLANK									[a-zA-Z\-]

%%
	
											
house/(hold|boat)							{
												std::cout << matched() << '\n';
												return WORD;
											}
											
{NONBLANK}*house{NONBLANK}*					{
												std::cout << matched();
												return WORD;
											}
											
\n											std::cout << matched()[0];
