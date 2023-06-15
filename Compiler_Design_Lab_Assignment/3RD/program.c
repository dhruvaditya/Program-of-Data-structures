%{
#include <stdio.h>
int vowel_count = 0;
%}

%%
[aeiouAEIOU]   { vowel_count++; }
.|\n    ;
%%

int main() {
    yylex();
    
    printf("Vowel count: %d\n", vowel_count);
    
    return 0;
}
