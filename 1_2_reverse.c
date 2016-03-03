#include <stdio.h>
int len(char *s) {
    int n = 0;
    while(*s++)
        n++;
    return n;
}

void reverse(char *s) {
    int end = len(s) - 1;
    char tmp;
    for (int i = 0; i < end/2; i++) {
        tmp = s[i];
        s[i] = s[end - i];
        s[end-i] = tmp;
    }
}

int main(void) {
    char example[] = "hello";
    printf("%s -> ",example);
    reverse(example);
    printf("%s\n",example);
}
