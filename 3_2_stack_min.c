#include <limits.h>
#include <stdio.h>

struct stack {
    struct node *top;
};

struct node {
    int value;
    int min;
    struct node *next;
};

struct node *s_peek(struct stack *s) {
    return s->top;
}

struct node *s_pop(struct stack *s) {
    struct node *popped = s->top;

    if (popped == NULL)
        return NULL;

    s->top = popped->next;
    return popped;
}

int s_min(struct stack *s) {
    return s->top ? s->top->min : INT_MAX;
}

void s_push(struct stack *s, struct node *n) {
    int current_min = s_min(s);
    n->min = n->value > current_min ? current_min : n->value;
    n->next = s->top;
    s->top = n;
}

int main(void) {
    struct stack s = {0};

    struct node n[5] = {{0}};

    n[0].value = 4;
    n[1].value = 3;
    n[2].value = 5;
    n[3].value = 1;
    n[4].value = 2;

    for (int i = 0; i < sizeof(n)/sizeof(n[0]); i++)
        s_push(&s,&n[i]);

    for (int i = 0; i < sizeof(n)/sizeof(n[0]); i++) {
        printf("min before pop: %d, ",s_min(&s));
        printf("popped: %d\n",s_pop(&s)->value);
    }
}
