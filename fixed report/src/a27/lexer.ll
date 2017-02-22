%x cComment
%x EOLcomment
%x string
%x header

SPACE		[ \t\n]
ALPHA		[a-zA-Z]
NUM			[0-9]
ALPHANUM	{ALPHA}|{NUM}
ANY			[^ \t\n]

%%

({ALPHA}|[_\-])({ALPHANUM}|[_\-])*					return IDENT;
{NUM}+												return INT;
({NUM}+.{NUM}+)(E{NUM})?							return DOUBLE;

"+"|"-"|"*"|"/"|"."|"~"|"="|"<"|">"|"&"|"!"|"|"		return matched()[0];
"<<"												return SHL_OP;
">>"												return SHR_OP;
"&&"												return AND;
"||"												return OR;
"<="												return LESS_EQUALS;
">="												return GREATER_EQUALS;
"=="												return EQUALS;
"!="												return NOT_EUQALS;
"+="|"-="|"<<="|">>="|"*="|"/="						return ASSIGNMENT_OP;
"->"												return POINTER;

\'\\?{ANY}+\'										return CONSTANT;

"/*"						{
								begin(StartCondition__::cComment);
								more();
							}
<cComment>"*/"				{
								begin(StartCondition__::INITIAL);
								// ignore
							}
<cComment>{SPACE}|.			more();

"//"						{
								begin(StartCondition__::EOLcomment);
								more();
							}
<EOLcomment>\n				{
								begin(StartCondition__::INITIAL);
								redo(1);
								// ignore
							}
<EOLcomment>.				more();

R?\"						{
								begin(StartCondition__::string);
								more();
							}
<string>\"					{
								begin(StartCondition__::INITIAL);
								return STRING;
							}
// Needs stitching as seen in exercise 26/28
<string>\"{SPACE}*\"		return STRING_SEG;
<string>\n					more();
<string>.					more();

"#include <"|"#include \""	{
								begin(StartCondition__::header);
								more();
							}
<header>\"|\>				{
								begin(StartCondition__::INITIAL);
								return HEADER;
							}
<header>.					more();

\n							return ENDLINE;
[ \t]						// ignore
.							return matched()[0];
