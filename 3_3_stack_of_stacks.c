#include <stdio.h>
#include <stdlib.h>
struct stack {
    struct node *top;
    int n_items;
};

struct node {
    void *value;
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
    s->n_items = 0;
    return s;
}

struct node *node_new(void *value) {
    struct node *n = malloc(sizeof(*n));
    if (n == NULL)
        panic("enomem");
    n->value = value;
    n->next = NULL;
    return n;
}

struct node *s_peek(struct stack *s) {
    return s->top;
}

void s_push(struct stack *s, struct node *n) {
    n->next = s->top;
    s->top = n;
    s->n_items++;
}

struct node *s_pop(struct stack *s) {
    struct node *popped = s->top;
    if (popped == NULL)
        return NULL;
    s->top = popped->next;
    s->n_items--;
    return popped;
}

struct stack *b_current_stack(struct stack *balancer) {
    struct node *n = s_peek(balancer);
    return (struct stack *) (n ? n->value : NULL);
}

void b_push(struct stack *balancer, struct node *n, int thresh) {
    struct stack *s = b_current_stack(balancer);
    if (s == NULL || s->n_items >= thresh) {
        s = stack_new();
        s_push(balancer,node_new(s));
    }

    s_push(s,n);
}

struct node* b_pop(struct stack *balancer) {
    struct stack *s = b_current_stack(balancer);
    if (s == NULL)
        return NULL;

    struct node *n = s_pop(s);
    if (s->n_items == 0) {
        free(s_pop(balancer));
    }
    return n;
}

int main(void) {
    struct stack *balancer = stack_new();
    for (int i = 0; i < 10; i++) {
        b_push(balancer, node_new((void *)0xbeef), 2);
        printf("after push, n stacks in the balancer: %d\n",balancer->n_items);
    }

    for (int i = 0; i < 10; i++) {
        struct node *n = b_pop(balancer);
        printf("after pop, n stacks in the balancer: %d, val: %p\n",balancer->n_items, n->value);
    }

}
