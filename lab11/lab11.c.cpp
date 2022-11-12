#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

unsigned int max_size = 50;


unsigned long control_sum(const unsigned char word[], unsigned int length) {
    unsigned long res = 0;
    const long big_num = 1103515245;
    for (int i = 0; i < length; i++) {
        res += word[i] * big_num % 15250;
    }
    return res;
}

void print(const unsigned char word[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        printf("%c", word[i]);
    }
    printf(": %lu\n", control_sum(word, length));
}

void processing_string() {
    unsigned char* curr_word = malloc(sizeof(char) * max_size); // текущее слово
    unsigned int len = 0; // длина слова (от 0)
    int sym;
    sym = getchar();
    while (sym != EOF) {
        if (sym == '\n' || sym == '\r' || sym == ' ' || sym == '.' || sym == ',') {
            if (len) {
                print(curr_word, len);
                len = 0;
            }
        }
        else {
            if (len == max_size) {
                curr_word = realloc(curr_word, max_size * 2);
                max_size *= 2;
            }
            curr_word[len] = sym;
            ++len;
        }
        if ((sym = getchar()) == EOF) {
            if (len) {
                printf("%s:%lu", curr_word, control_sum(curr_word, len));
                break;
            }
        }
        else {
            continue;
        }
    }
}

int main() {
    processing_string();
    return 0;
}