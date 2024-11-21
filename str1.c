#include <stdio.h>

int main() {
    char s1[25] = "state bank of india";
    int i;
    for (i = 0; s1[i] != '\0'; i++) {
        printf("%c", s1[i]);  // Print each character in the string
    }
    return 0;
}