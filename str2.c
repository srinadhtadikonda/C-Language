#include <stdio.h>

int main() {
    char s1[25] = "state bank of india";
    int i;
    int count = 0;  // Variable to count the number of characters

    // Loop through the string and print each character, while also counting them
    for (i = 0; s1[i] != '\0'; i++) {
        printf("%c", s1[i]);  // Print each character
        count++;  // Increment the counter for each character
    }

    // After the loop, print the number of characters
    printf("\nNumber of characters (including spaces): %d\n", count);

    return 0;
}
