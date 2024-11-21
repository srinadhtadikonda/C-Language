#include <stdio.h>

int main() {
    char s1[25] = "state bank of india";
    int i, j;
    int count = 0;  // Variable to count the number of characters

    // Find the length of the string (count the characters including spaces)
    while (s1[count] != '\0') {
        count++;
    }

    // Reverse the string
    for (i = 0, j = count - 1; i < j; i++, j--) {
        // Swap characters
        char temp = s1[i];
        s1[i] = s1[j];
        s1[j] = temp;
    }

    // Print the reversed string
    printf("Reversed string: %s\n", s1);

    // Print the number of characters (including spaces)
    printf("Number of characters (including spaces): %d\n", count);

    return 0;
}
