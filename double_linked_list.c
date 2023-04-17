#include <stdio.h>
#include <stdlib.h>

struct _Node
{
  int data;
  struct _Node *next;
  struct _Node *prev;
};

typedef struct _Node Node;
Node *head = NULL;

Node* createNode(int data)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void insert_at_tail(int x)
{
  Node *newNode = createNode(x);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node* nowNode = head;
  while (nowNode->next != NULL)
    nowNode = nowNode->next;
  nowNode->next = newNode;
  newNode->prev = nowNode;
}

void print()
{
  Node* nowNode = head;
  while (nowNode != NULL)
  {
    printf("%d ", nowNode->data);
    nowNode = nowNode->next;
  }
}

void reverse_print()
{
  Node* nowNode = head;
  if (nowNode == NULL)
    return;
  while (nowNode->next != NULL)
    nowNode = nowNode->next;
  while (nowNode != NULL)
  {
    printf("%d ", nowNode->data);
    nowNode = nowNode->prev;
  }
}

void reverse()
{
  if (head == NULL)
    return;
  Node* nowNode = head;
  Node* prev = NULL;
  Node* next = NULL;
  while (nowNode != NULL)
  {
    next = nowNode->next;
    nowNode->next = prev;
    nowNode->prev = next;
    prev = nowNode;
    nowNode = next;
  }
  head = prev;
}

void delete(int idx)
{
  if (idx == 0)
  {
    Node* nowNode = head;
    head = head->next;
    if (head != NULL)
      head->prev = NULL;
    free(nowNode);
    return;
  }
  Node* nowNode = head;
  for (int i = 0; i <= idx - 1; i++)
    nowNode = nowNode->next;
  nowNode->prev->next = nowNode->next;
  if (nowNode->next != NULL)
    nowNode->next->prev = nowNode->prev;
  free(nowNode);
}
