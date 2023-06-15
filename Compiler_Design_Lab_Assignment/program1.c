#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void remove_comments(const char* input_file, const char* output_file) {
    FILE* in = fopen(input_file, "r");
    FILE* out = fopen(output_file, "w");
    
    if (in == NULL || out == NULL) {
        printf("Failed to open files.\n");
        exit(EXIT_FAILURE);
    }
    
    char ch;
    bool inside_comment = false;
    char prev = '\0';
    
    while ((ch = fgetc(in)) != EOF) {
        if (!inside_comment && ch == '/' && prev == '/') {
            // Start of a line comment
            inside_comment = true;
        } else if (inside_comment && ch == '\n') {
            // End of a line comment
            inside_comment = false;
        } else if (!inside_comment) {
            // Write non-comment characters to the output file
            fputc(ch, out);
        }
        
        prev = ch;
    }
    
    fclose(in);
    fclose(out);
}

int main() {
    const char* input_file = "input.c";
    const char* output_file = "output.c";
    
    remove_comments(input_file, output_file);
    
    printf("Comments removed successfully.\n");
    
    return 0;
}
