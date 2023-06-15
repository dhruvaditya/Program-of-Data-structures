%{
#include <stdio.h>
int line_count = 1;
int space_count = 0;
int symbol_count = 0;
int character_count = 0;
%}

%%
\n   { line_count++; }
[ ]  { space_count++; }
[^ \n]  { character_count++; }
[^\nA-Za-z0-9 ] { symbol_count++; }
%%

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    yylex(file);
    
    fclose(file);
    
    printf("Line count: %d\n", line_count);
    printf("Space count: %d\n", space_count);
    printf("Symbol count: %d\n", symbol_count);
    printf("Character count: %d\n", character_count);
    
    return 0;
}
