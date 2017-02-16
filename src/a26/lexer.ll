%x cComment
%x EOLcomment
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

"//"						{
								begin(StartCondition__::EOLcomment);
								more();
							}
<EOLcomment>\n				{
								begin(StartCondition__::INITIAL);
								redo(1);
								return COMMENT;
							}
<EOLcomment>.				more();

\"							{
								begin(StartCondition__::string);
								more();
							}
<string>\"					{
								begin(StartCondition__::INITIAL);
								return STRING;
							}
<string>\"{SPACE}*\"		return STRING_SEG;
<string>\n					more();
<string>.					more();

"R\""						{
								begin(StartCondition__::rawString);
								more();
							}
<rawString>\"				{
								begin(StartCondition__::INITIAL);
								return RSTRING;
							}
<rawString>\"{SPACE}*\"		return STRING_SEG;
<rawString>\n				more();
<rawString>.				more();

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
