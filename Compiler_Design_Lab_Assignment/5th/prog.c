%{
#include <stdio.h>
int a_count = 0;
int b_count = 0;
int yyerror(const char* msg);
%}

%token A B

%%

input: A { a_count++; }
     | B { b_count++; }
     | input A { a_count++; }
     | input B { b_count++; }
     ;

%%

int yyerror(const char* msg) {
    printf("%s\n", msg);
    return 0;
}

int main() {
    yyparse();
    
    if (a_count == b_count) {
        printf("String is valid.\n");
    } else {
        printf("String is invalid.\n");
    }
    
    return 0;
}
