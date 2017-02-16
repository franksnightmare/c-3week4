%x house
%x post

NONBLANK			[a-zA-Z\-]	

%%
house/(hold|boat)   {
						begin(StartCondition__::house);
						std::cout << matched() << '\n';
						return WORD;
					}

house			    {
						begin(StartCondition__::house);
						more();
					}
	
<house>
{
	hold|boat		{
						begin(StartCondition__::INITIAL);
						std::cout << matched() << '\n';	
						return WORD;
					}
					
	{NONBLANK}*		{
						begin(StartCondition__::INITIAL);
						std::cout << matched() << '\n';
						return WORD;
					}
}

{NONBLANK}*house    {
						begin(StartCondition__::post);
						more();
					}

<post>
{
	{NONBLANK}*		{
						begin(StartCondition__::INITIAL);
						std::cout << matched() << '\n';
						return WORD;
					}
}

\n					// ignore
