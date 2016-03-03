#include <stdio.h>
struct node {
    struct node *next;
    int value;
};

void insert(struct node *head, struct node *e) {
    e->next = head->next;
    head->next = e;
}

int to_num(struct node *head) {
    int n = 0;
    int i = 0;
    for (struct node *e = head->next; e; e = e->next, i++)
        n = (n * 10) + e->value;
    return n;
}

int sum(struct node *h1, struct node *h2) {
    return to_num(h1) + to_num(h2);
}

int sum2(struct node *h1, struct node *h2) {
    int n = 0;
    int carry = 0;
    int i = 0;
    for (struct node *e1 = h1->next, *e2 = h2->next; e1 && e2; e1 = e1->next, e2 = e2->next, i++) {
        int value = (e1->value + e2->value);
        if (carry > 0) {
            value++;
            carry = 0;
        }
        if (value >= 10) {
            carry = 1;
            value %= 10;
        }
        n = (n * 10) + value;
    }
    return n;
}


int main(void) {
    struct node n1[] = {
        {.value = 0},
        {.value = 5},
        {.value = 1},
        {.value = 3},
    };

    struct node n2[] = {
        {.value = 0},
        {.value = 2},
        {.value = 9},
        {.value = 5},
    };

    #define setup(x) do {                               \
    for (int i = 1; i < sizeof((x))/sizeof((x)[0]);i++) \
        insert(&(x)[0],&(x)[i]);                        \
    } while(0)

    setup(n1);
    setup(n2);

    #undef setup
    printf("%d\n",sum(&n1[0],&n2[0]));
    printf("%d\n",sum2(&n1[0],&n2[0]));
}
