#include <stdio.h>

int uniq(char *s) {
    unsigned int seen = 0;
    for (; *s; s++) {
        int bit = 1 << (*s - 'a');

        if (seen & bit)
            return 1;

        seen |= bit;
    }

    return 0;
}

int main(void) {
    char *example[] = {"abcdef","abcdc","hello","world","heeelllooo"};

    for (int i = 0; i < sizeof(example)/sizeof(example[0]); i++)
        printf("%s: %d\n",example[i],uniq(example[i]));
}
