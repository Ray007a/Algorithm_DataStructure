#include <stdio.h>
#include <stdlib.h>
// ノードを表す構造体
typedef struct _Node
{
  int data;
  struct _Node *next;
} Node;
// キューを表す構造体
typedef struct
{
  Node *head;
  Node *tail;
} Queue;

Node *gen_node(void);
Queue *gen_queue(void);
int is_empty(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);

int main()
{
}

Queue *gen_queue(void)
{
  Queue *q;
  q = (Queue *)malloc(sizeof(Queue));

  q->head = q->tail = NULL;
  return q;
}

int is_empty(Queue *q){ return (q->tail == NULL);}

void enqueue(Queue *q, int data)
{
  Node *new;
  new = gen_node();
  new->data = data;
  new->next = NULL;
  if (is_empty(q))
  {
    q->head = q->tail = new;
  }
  else
  {
    q->tail->next = new;
    q->tail = new;
  }
}

int dequeue(Queue *q)
{
  int data;
  Node *old;
  if (is_empty(q))
  {
    return -1;
  }
  old = q->head;
  data = old->data;
  q->head = old->next;
  free(old);
  return data;
}

Node *gen_node(void)
{
  return (Node *)malloc(sizeof(Node));
}
