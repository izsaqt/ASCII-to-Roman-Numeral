#include <stdio.h>
#include <string.h>

typedef struct {
    char ascii;
    int value;
    char roman[10];
} Roman;

void toRoman(int num, char *roman) {
    int numMap[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *romanMap[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;

    roman[0] = '\0';

    while (num > 0) {
        while (num >= numMap[i]) {
            strcat(roman, romanMap[i]);
            num -= numMap[i];
        }
        i++;
    }
}

int main() {
    Roman romans[52]; 
    for (int i = 0; i < 26; i++) {
        char roman[10] = "";
        int value = 'A' + i; 
        toRoman(value, roman);
        romans[i].ascii = 'A' + i;
        romans[i].value = value;
        strcpy(romans[i].roman, roman);
    }

    for (int i = 0; i < 26; i++) {
        char roman[10] = "";
        int value = 'a' + i; 
        toRoman(value, roman);
        romans[26 + i].ascii = 'a' + i;
        romans[26 + i].value = value;
        strcpy(romans[26 + i].roman, roman);
    }

    for (int i = 0; i < 52; i++) {
        printf("{'%c', %d, \"%s\"}, ", romans[i].ascii, romans[i].value, romans[i].roman);
    }
    printf("\n"); 

        char input[26];
        printf("Enter | ");
        fgets(input, sizeof(input), stdin);
    
        char finalValue[26] = ""; 

        for (int i = 0; i < strlen(input); i++) {
            char currentChar = input[i];
            if ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z')) {
                for (int j = 0; j < 52; j++) {
                    if (romans[j].ascii == currentChar) {
                        printf("Character: '%c', ASCII Value: %d, Roman Numeral: %s\n", 
                            romans[j].ascii, romans[j].value, romans[j].roman);

                            strcat(finalValue, romans[j].roman);
                        break;
                    }
                }
            }
        }
        printf("%s", finalValue);

    return 0;
}
