#include <stdio.h>

unsigned int masked(char *s) {
    unsigned int seen = 0;
    for (; *s; s++)
        seen |= 1 << (*s - 'a');
    return seen;
}

int is_anagram(char *s1, char *s2) {
    return masked(s1) == masked(s2);
}

int main(void) {
    #define anagram(a,b) do {                                                  \
        printf(a " %s anagram of " b "\n", is_anagram((a),(b)) ? "is" : "is not"); \
    } while(0)

    anagram("mary","army");
    anagram("mary","ary");
    anagram("hello","world");
    anagram("anagram","anagram");

    #undef anagram
}
