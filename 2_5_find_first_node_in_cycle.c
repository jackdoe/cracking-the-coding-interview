#include <stdio.h>
struct node {
    struct node *next;
    int value;
    int marked;
};

void insert(struct node *head, struct node *e) {
    e->next = head->next;
    head->next = e;
}

struct node *find_first_loop(struct node *head) {
    if (head == NULL || head->marked) return head;

    // simply cleanup our marks after recursing
    head->marked = 1;
    struct node *found = find_first_loop(head->next);
    head->marked = 0;

    return found;
}

int main(void) {
    struct node list[] = {
        {.value = 0},
        {.value = 5},
        {.value = 1},
        {.value = 3},
    };
    // 3 -> 1 -> 5 -> 3
    insert(&list[0],&list[1]);
    insert(&list[0],&list[2]);
    insert(&list[0],&list[3]);

    list[1].next = &list[3]; // loop 5 to 3
    printf("%d\n",find_first_loop(&list[0])->value);
}
