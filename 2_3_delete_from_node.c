#include <stdio.h>
struct node {
    struct node *next;
    int value;
} head;

void insert(struct node *e) {
    e->next = head.next;
    head.next = e;
}
typedef void (*t_cb_destructor)(struct node *);
int delete(struct node *e, t_cb_destructor cb_destructor) {
    struct node *tmp = e->next;
    e->next = tmp->next;
    e->value = tmp->value;

    if (cb_destructor != NULL)
        cb_destructor(tmp);
    return 1;
}

void destructor(struct node *e) {
    printf("have to delete %d, %p\n",e->value,e);
}

void pprint(void) {
    for(struct node *e = head.next; e; e = e->next)
        printf("%d\n",e->value);
    printf("-------\n");
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

    pprint();
    delete(&items[2], &destructor);
    pprint();
}
