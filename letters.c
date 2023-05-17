// loop through characters 'a' to 'z'
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char ch;
    for (ch = 'a'; ch <= 'z'; ch++) {
        // printing each character
        putchar(ch);
    }
    // indicating successful completion of program
    putchar('\n');
    return 0;
}

