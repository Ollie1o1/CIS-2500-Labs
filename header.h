#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 100

int count_words(const char *line) {
    int count = 0;
    int in_word = 0;
    
    while (*line) {
        if (*line == ' ' || *line == '\n') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        line++;
    }
    return count;
}

void process_poem(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int *words_per_line = NULL;
    int total_words = 0, line_count = 0;
    
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\'' && line[1] == '0')
            break;
        line[strcspn(line, "\n")] = 0; // Remove newline
        
        int word_count = count_words(line);
        total_words += word_count;
        
        int *temp = (int *)realloc(words_per_line, (line_count + 1) * sizeof(int));
        if (!temp) {
            perror("Memory allocation failed");
            fclose(file);
            return;
        }
        words_per_line = temp;
        words_per_line[line_count++] = word_count;
    }
    fclose(file);
    
    printf("%d word%s on %d line%s\n", total_words, total_words == 1 ? "" : "s", line_count, line_count == 1 ? "" : "s");
    
    for (int i = 0; i < line_count; i++) {
        printf("%d%s", words_per_line[i], (i == line_count - 1) ? "\n" : " ");
    }
    
    free(words_per_line);
}
