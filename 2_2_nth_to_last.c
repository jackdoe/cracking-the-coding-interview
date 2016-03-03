#include <stdio.h>
struct node {
    struct node *next;
    int value;
} head;

void insert(struct node *e) {
    e->next = head.next;
    head.next = e;
}

struct node *nth_to_last(int nth) {
    struct node *behind = head.next;
    int i = 0;
    for(struct node *e = head.next; e; e = e->next, i++) {
        if (i > nth)
            behind = behind->next;
    }
    return behind;
}

int main(void) {
    struct node items[] = {
        {.value = 5},
        {.value = 4},
        {.value = 3},
        {.value = 2},
        {.value = 1},
    };

    for (int i = 0; i < sizeof(items)/sizeof(items[0]);i++)
        insert(&items[i]);

    for(struct node *e = head.next; e; e = e->next)
        printf("%d\n",e->value);

    for (int i = 0; i < sizeof(items)/sizeof(items[0]);i++)
        printf("last %dth: %d\n",i,nth_to_last(i)->value);
}
