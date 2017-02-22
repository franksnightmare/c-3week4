%x cComment
%x string
%x header

SPACE       [ \t\n]
ALPHA       [a-zA-Z]
NUM         [0-9]
ALPHANUM    {ALPHA}|{NUM}

// Anything but ALPHANUM tab and newline
SYMBOL      [^{ALPHANUM}\t\n]

%%

({ALPHA}|"_")({ALPHANUM}|"_")*  return IDENT;
{NUM}+                          return INT;
({NUM}+"."{NUM}+)(E-?{NUM})?    return DOUBLE;

// Singular operators taken care off at the end
"<<"                            return SHL_OP;
">>"                            return SHR_OP;
"&&"                            return AND;
"||"                            return OR;
"<="                            return LESS_EQUALS;
">="                            return GREATER_EQUALS;
"=="                            return EQUALS;
"!="                            return NOT_EUQALS;
"+="|"-="|"<<="                 return ASSIGNMENT_OP;
">>="|"*="|"/="                 return ASSIGNMENT_OP;
"->"                            return POINTER;

"'"("\")?({ALPHANUM}|{SYMBOL}|"\")+"'"
{
    return CONSTANT;
}

\\ EOL comment is ignored (but not the newline)
"//".*\n                    redo(1);

"/*"            {
                    begin(StartCondition__::cComment);
                    more();
                }
<cComment>"*/"  {
                    begin(StartCondition__::INITIAL);
                    // ignore
                }
<cComment>{SPACE}|.     more();

R?\"            {
                    begin(StartCondition__::string);
                    more();
                }
<string>\"      {
                    begin(StartCondition__::INITIAL);
                    return STRING;
                }

// Needs stitching as seen in exercise 26/28
<string>\"{SPACE}*\"        return STRING_SEG;
<string>\n                  more();
<string>.                   more();

"#include <"|"#include \""
{
    begin(StartCondition__::header);
    more();
}

<header>\"|\>   {
                    begin(StartCondition__::INITIAL);
                    return HEADER;
                }
<header>.       more();

\n              return ENDLINE;
[ \t]           // ignore
.               return matched()[0];
