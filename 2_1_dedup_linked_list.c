#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node *next;
    int value;
};

struct node *node_new(int v) {
    struct node *e = (struct node *)malloc(sizeof(*e));
    if (!e) {
        fprintf(stderr, "nomem");
        exit(1);
    }
    e->next = NULL;
    e->value = v;
    return e;
}

void insert(struct node *head, struct node *e) {
    e->next = head->next;
    head->next = e;
}

void dedup(struct node *head) {
    struct node *e = head->next;
    for (; e; e = e->next) {
        struct node *prev = e;
        for (struct node *again = e->next; again; ) {
            if (again->value == e->value) {
                prev->next = again->next;
                struct node *tmp = again->next;
                free(again);
                again = tmp;
            } else {
                prev = again;
                again = again->next;
            }
        }
    }
}
void pprint(struct node *head) {
    for (struct node *e = head->next; e; e = e->next)
        printf("%d\n",e->value);
    printf("--------\n");
}
int main(void) {
    struct node head = {0};
    insert(&head, node_new(4));
    insert(&head, node_new(3));
    insert(&head, node_new(4));
    insert(&head, node_new(5));
    insert(&head, node_new(5));
    insert(&head, node_new(5));
    insert(&head, node_new(6));
    insert(&head, node_new(5));
    insert(&head, node_new(4));

    pprint(&head);
    dedup(&head);
    pprint(&head);
}
