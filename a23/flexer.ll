NONBLANK	[a-zA-Z]

%%

{NONBLANK}+	return WORD;

.|\n		// ignore
