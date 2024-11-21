#include <stdio.h>
#include <ctype.h>  // For isalpha and isdigit functions

int main() {
    char s1[25] = "state bank of india 123";
    int i;
    int vowelCount = 0, consonantCount = 0, digitCount = 0;

    // Loop through the string and count vowels, consonants, and digits
    for (i = 0; s1[i] != '\0'; i++) {
        char ch = s1[i];

        // Skip spaces
        if (ch == ' ') {
            continue;
        }

        // Check if the character is a vowel (both lowercase and uppercase)
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowelCount++;
        }
        // Check if the character is a consonant (alphabetic character but not a vowel)
        else if (isalpha(ch)) {
            consonantCount++;
        }
        // Check if the character is a digit
        else if (isdigit(ch)) {
            digitCount++;
        }
    }

    // Print the results
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);
    printf("Number of digits: %d\n", digitCount);

    return 0;
}
