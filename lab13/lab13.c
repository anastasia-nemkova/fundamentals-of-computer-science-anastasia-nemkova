#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long long set;

bool is_separator(int sym) {
    return (sym == ' ' || sym == '\t' || sym == '\n');
}

int letter_to_int(int sym) {
    if (sym >= 'a' && sym <= 'z')
        return sym - 'a';
    if (sym >= 'A' && sym <= 'Z')
        return sym - 'A';
    else
      return -1;
}

set letter_to_set(int sym) {
    int ind = letter_to_int(sym);
    return (1U) << ind;
}

void check_letters() {
    int c;
    set all_letters = 0;
    set consonant_letters = letter_to_set('B') | letter_to_set('C') | letter_to_set('D') | letter_to_set('F') | letter_to_set('G') | letter_to_set('H') | letter_to_set('J') | letter_to_set('K') | letter_to_set('L') | letter_to_set('M') | letter_to_set('N') | letter_to_set('P') | letter_to_set('Q') | letter_to_set('R') | letter_to_set('S') | letter_to_set('T') | letter_to_set('V') | letter_to_set('W') | letter_to_set('X');
    while (true) {
        c = getchar();
        if (is_separator(c)) {
            continue;
        } else if (c == EOF) {
            if (((all_letters & consonant_letters) == consonant_letters)) { 
                printf("NO \n");
            } else { 
                printf("YES\n");
            }
            break;
        } else {
            all_letters = all_letters | letter_to_set(c);
        }
    }
}

int main() {
    check_letters();
    return 0;
}

