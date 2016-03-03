#include <stdlib.h>
#include <stdio.h>
int size_after_spacification(char *s) {
    int n = 0;
    for (; *s; s++) {
        if (*s == ' ')
            n += 3;
        else
            n++;
    }
    return n;
}

char *spacify(char *s) {
    int modified_len = size_after_spacification(s) + 1;
    char *copy = malloc(modified_len);
    if (!copy) {
        fprintf(stderr,"enomem");
        exit(1);
    }

    copy[modified_len] = '\0';
    for (int j = 0; *s; s++, j++) {
        if (*s == ' ') {
            copy[j] = '%';
            copy[++j] = '2';
            copy[++j] = '0';
        } else {
            copy[j] = *s;
        }
    }
    return copy;
}

int main(void) {
    printf("%s\n",spacify("hello world"));
    printf("%s\n",spacify("hello world bzbz bazinga   hello"));
}
