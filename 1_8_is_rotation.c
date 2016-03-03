#include <string.h>
#include <stdio.h>

int rotation(char *s1, char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);

    if (len_s1 != len_s2)
        return 0;

    int rot = 0;

again:
    ;
    int matching = 0;
    for (int j = rot, i = 0; j < len_s1 + rot && rot < len_s1 && i < len_s1; j++, i++) {
        if (s1[i] != s2[j % len_s1]) {
            rot++;
            goto again;
        } else {
            matching++;
        }
    }
    return (matching == len_s1);
}

int main(void) {
    #define is_rotation(a,b) printf(a " %s of " b "\n", rotation((a),(b)) ? "is rotation" : "is not rotation");
    is_rotation("water","aterw");
    is_rotation("water","aterww");
    is_rotation("waterbottle","erbottlewat");
    is_rotation("erbottlewat","waterbottle");
    is_rotation("hello","hheelloo");
    #undef is_rotation
}
