#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <poem file>\n", argv[0]);
        return 1;
    }
    
    process_poem(argv[1]);
    
    return 0;
}
