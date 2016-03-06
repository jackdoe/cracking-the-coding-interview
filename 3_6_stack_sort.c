#include <stdio.h>
#include <stdlib.h>
struct stack {
    struct node *top;
};

struct node {
    int value;
    struct node *next;
};

void panic(char *s) {
    fprintf(stderr,s);
    exit(1);
}

struct stack *stack_new() {
    struct stack *s = malloc(sizeof(*s));
    if (s == NULL)
        panic("enomem");
    s->top = NULL;
    return s;
}

struct node *node_new(int value) {
    struct node *n = malloc(sizeof(*n));
    if (n == NULL)
        panic("enomem");
    n->value = value;
    n->next = NULL;
    return n;
}

void s_push(struct stack *s, struct node *n) {
    n->next = s->top;
    s->top = n;
}

struct node *s_pop(struct stack *s) {
    struct node *popped = s->top;
    if (popped == NULL)
        return NULL;
    s->top = popped->next;
    return popped;
}

void s_insert_sorted(struct stack *s, struct node *n) {
    struct node *tmp = s_pop(s);
    if (tmp == NULL || tmp->value > n->value) {
        if (tmp != NULL)
            s_push(s,tmp);
        s_push(s,n);
    } else {
        s_insert_sorted(s,n);
        s_push(s,tmp);
    }
}

int main(void) {
    struct stack *s = stack_new();
    s_insert_sorted(s,node_new(2));
    s_insert_sorted(s,node_new(1));
    s_insert_sorted(s,node_new(3));
    s_insert_sorted(s,node_new(5));
    s_insert_sorted(s,node_new(2));

    struct node *n;
    while ((n = s_pop(s)) != NULL) {
        printf("val: %d\n",n->value);
    }
}
