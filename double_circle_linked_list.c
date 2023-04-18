#include <stdio.h>
#include <stdlib.h>

struct _Node
{
  int data;
  struct _Node *next;
  struct _Node *prev;
};

typedef struct _Node Node;
Node *chead = NULL;

Node* createNode(int data)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void insert_circle(int x)
{
  Node* newNode = createNode(x);
  if (chead == NULL)
  {
    chead = newNode;
    newNode->prev = chead;
    newNode->next = chead;
  }
  chead->prev->next = newNode;
  newNode->prev = chead->prev;
  chead->prev = newNode;
  newNode->next = chead;
}

void print_circle()
{
  if (chead == NULL)
    return;
  Node* nowNode = chead;
  do {
    printf("%d ", nowNode->data);
    nowNode = nowNode->next;
  } while (nowNode != chead);
  printf("\n");
}

void reverse_circle()
{
  if (chead == NULL)
    return;
  Node* nowNode = chead;
  Node* prev = NULL;
  Node* next = NULL;
  do {
    next = nowNode->next;
    nowNode->next = prev;
    nowNode->prev = next;
    prev = nowNode;
    nowNode = next;
  } while (nowNode != chead);
  chead = prev;
}

void delete_circle(int idx)
{
  if (idx == 0)
  {
    if (chead->next == chead) 
    {
      free(chead);
      chead = NULL;
    }
    else
    {
      Node* tail = chead->prev;
      Node* temp = chead;
      chead = chead->next;
      tail->next = chead;
      chead->prev = tail;
      free(temp);
    }
    return;
  }
  Node* nowNode = chead;
  for (int i = 0; i <= idx - 1; i++)
    nowNode = nowNode->next;

  Node* prevNode = nowNode->prev;
  Node* nextNode = nowNode->next;
  prevNode->next = nextNode;
  nextNode->prev = prevNode;
  free(nowNode);
}
