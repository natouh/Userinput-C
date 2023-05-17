//this program prints out numbers 0 - 9 on a new line
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//simple for loop that prints numbers 0 - 9
int main() {
    int j;
    for (j = 0; j < 10; ++j) {
        printf("%d\n", j);
    }
    return 0;
}

