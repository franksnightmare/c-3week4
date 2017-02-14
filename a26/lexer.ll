%x cComment
%x EOLcomment
%x string
%x rawString

SPACE						[ \t\n]

%%

"\*"						begin(StartCondition__::cComment);
<cComment>"*/"				begin(StartCondition__::INITIAL); return COMMENT;
<cComment>.					// ignored

"\\"						begin(StartCondition__::EOLcomment);
<EOLcomment>\n				begin(StartCondition__::INITIAL); return COMMENT;
<EOLcomment>.				// ignored

"\""						begin(StartCondition__::string);
<string>"\""				begin(StartCondition__::INITIAL); return STRING;
<string>\"{SPACE}*\"		return STRING_SEG;
<string>.					// ignored

"R\""						begin(StartCondition__::rawString);
<rawString>"\""				begin(StartCondition__::INITIAL); return RSTRING;
<rawString>\"{SPACE}*\"		return STRING_SEG;
<rawString>.				// ignored
