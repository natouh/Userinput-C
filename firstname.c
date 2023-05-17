/* This program takes a command line argument, which is expected to be the user's first name. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// Check if there is exactly one command line argument (in addition to the program name itself). 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: firstname <yourfirstname>\n");
        return 1;
    }
    printf("%s\n", argv[1]);
    return 0;
}

