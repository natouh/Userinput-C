#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main() {
    char ch;
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            putchar(toupper(ch));
        }
    }
    return 0;
}

