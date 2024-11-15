#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

typedef struct 
{
    Node *top;
    int size;
} Stack;

Node *gen_node(void);
Stack *gen_stack(void);
int is_empty(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);

int main(void)
{

}

Stack *gen_stack(void)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

int is_empty(Stack *s){return (s->top == NULL?1:0);}

void push(Stack *s,int data)
{
    Node *new = gen_node();
    new->data = data;
    new->next = s->top;

    s->top = new;
    s->size++;
}

int pop(Stack *s)
{
    int data;
    Node *old = s->top;
    data = old->data;
    s->top = old->next;
    free(old);

    return data;
}

Node *gen_node(void){return (Node *)malloc(sizeof(Node));}


