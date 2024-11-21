#include <stdio.h>

int main() {
    char s1[25] = "state bank of india";
    int i;
    int count = 0;  // Variable to count the number of characters, excluding spaces

    // Loop through the string and print each character, while also counting them
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == ' ') {
            continue;  // Skip the space characters
        }
        count++;  // Increment the counter for each non-space character
        printf("%c", s1[i]);  // Print each non-space character
    }

    // After the loop, print the number of characters excluding spaces
    printf("\nNumber of characters (excluding spaces): %d\n", count);

    return 0;
}
