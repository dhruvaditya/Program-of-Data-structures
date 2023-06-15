#include <stdio.h>
#include <ctype.h>

int main() {
    const char* filename = "input.c";
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    int line_count = 0;
    int punctuation_count = 0;
    int space_count = 0;
    char ch;
    
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_count++;
        } else if (ispunct(ch)) {
            punctuation_count++;
        } else if (isspace(ch)) {
            space_count++;
        }
    }-
    
    fclose(file);
    
    printf("Line count: %d\n", line_count);
    printf("Punctuation count: %d\n", punctuation_count);
    printf("Space count: %d\n", space_count);
    
    return 0;
}
