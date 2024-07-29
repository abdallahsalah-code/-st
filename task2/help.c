#include <stdio.h>
#include <stdlib.h>

// Function to display usage information
void help() {
    printf("Usage: ./my_program {echo|pwd|copy|move|help|exit}\n");
    printf("  echo <message>      - Print <message> to the terminal\n");
    printf("  pwd                - Display the current directory\n");
    printf("  copy <source> <dest> - Copy file from <source> to <dest>\n");
    printf("  move <source> <dest> - Move file from <source> to <dest>\n");
    printf("  help               - Show this help message\n");
    printf("  exit               - Exit the program with a message\n");
}


