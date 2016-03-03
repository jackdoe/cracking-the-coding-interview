#include <stdio.h>
#include <string.h>

void dedup(char *input) {
    int end = strlen(input);
    char prev = '\0';
    for (int i = 0; i < end; i++) {
        int shift_left = 0;
        int j = i;
        while (input[j] == prev) {
            shift_left++;
            j++;
        }
        if (shift_left > 0) {
            memmove(input + i, input + i + shift_left, shift_left);
            end -= shift_left;
            i -= shift_left;
            input[end] = '\0';
        }
        prev = input[i];
    }
}

int main(void) {
    char example[] = "aabcddde";
    printf("%s -> ",example);
    dedup(example);
    printf("%s\n",example);
}
