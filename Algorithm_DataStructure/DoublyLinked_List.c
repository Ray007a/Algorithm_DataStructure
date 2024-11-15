#include <stdio.h>
#include <stdlib.h>

typedef struct _Node //ノードを表す構造体
{
    int data;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct //リストを表す構造体
{
    Node *head;
    Node *tail;
} list;

Node *gen_node(void); //ノードを作成
list *gen_list(void); //リストを作成
int front(list *l); //先頭要素
int back(list *l); //末尾要素
list *insert(list *l, int data); //末尾に要素を追加
list *erase(list *l); //末尾の要素を削除

int main(void) {
}

Node *gen_node(void) { return (Node *)malloc(sizeof(Node)); }

list *gen_list(void) 
{
    list *l = (list *)malloc(sizeof(list));
    l->head = l->tail = NULL;
    return l;
}

int front(list *l) { return l->head->data; }

int back(list *l) { return l->tail->data; }

list *insert(list *l, int data) {
    Node *new = gen_node();
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (l->head == NULL) l->head = l->tail = new; //リストが空のとき
    else 
    {
        new->prev = l->tail;
        l->tail->next = new;
        l->tail = new;
    }

    return l;
}

list *erase(list *l)
{
    if(l->tail == NULL) return l;
    Node *delete = l->tail;

    if(l->head == l->tail) l->head = l->tail = NULL;
    else
    {
        l->tail = l->tail->prev;
        l->tail->next = NULL;
    }
    
    free(delete);
    return l;
}