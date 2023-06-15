%{
#include "y.tab.h"
%}

%%
[Aa]    { yylval = yytext[0]; return A; }
[Bb]    { yylval = yytext[0]; return B; }
.       { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
