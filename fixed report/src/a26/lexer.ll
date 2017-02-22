%x cComment
%x string
%x rawString
%x header

SPACE						[ \t\n]

%%

"/*"						{
								begin(StartCondition__::cComment);
								more();
							}
<cComment>"*/"				{
								begin(StartCondition__::INITIAL);
								return COMMENT;
							}
<cComment>{SPACE}|.			more();

"//".*\n					{
								redo(1);
								return COMMENT;
							}

\"							{
								begin(StartCondition__::string);
								more();
							}
<string>\"					{
								begin(StartCondition__::INITIAL);
								return STRING;
							}
<string>\"{SPACE}*\"		return STRING_SEG;
<string>\n					// ignore
<string>.					more();

"R\""([^()\"]{1,16})?"("			{
									begin(StartCondition__::rawString);
									return RSTRING_START;
								}
<rawString>")"([^()\"]{1,16})?"\""	{
									begin(StartCondition__::INITIAL);
									return RSTRING;
								}
<rawString>.|\n					more();

"#include <"|"#include \""	{
								begin(StartCondition__::header);
								more();
							}
<header>\"|\>				{
								begin(StartCondition__::INITIAL);
								return HEADER;
							}
<header>.					more();

{SPACE}						return OTHER;
.							return OTHER;
