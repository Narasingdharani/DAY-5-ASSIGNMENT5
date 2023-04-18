#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Failed to open input file\n");
        exit(EXIT_FAILURE);
    }

    output_file = fopen("error_log.txt", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Failed to open output file\n");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {

        if (strstr(line, "error") != NULL) {

            fputs(line, output_file);
        }
    }

    
    fclose(input_file);
    fclose(output_file);

    output_file = fopen("error_log.txt", "r");
    if (output_file == NULL) {
        fprintf(stderr, "Failed to open output file for reading\n");
        exit(EXIT_FAILURE);
    }

    printf("Contents of error_log.txt:\n");
    while (fgets(line, MAX_LINE_LENGTH, output_file) != NULL) {
        printf("%s", line);
    }

    fclose(output_file);

    return 0;
}
