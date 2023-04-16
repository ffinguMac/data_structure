#include <stdio.h>
#include <stdlib.h>

struct _Node
{
  int data;
  struct _Node* ptr;
};
typedef struct _Node Node;

Node* head = NULL;

Node* createNode(int data)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->ptr = NULL;

  return newNode;
}

void insert(int data)
{
  Node* newNode = createNode(data);
  if (head == NULL)
  {
    head = newNode;
    return 0;
  }
  Node* nowNode = head;
  while (nowNode->ptr != NULL)
    nowNode = nowNode->ptr;
  nowNode->ptr = newNode;
  return 0;
}

void print()
{
  Node* nowNode = head;
  while (nowNode != NULL)
  {
    printf("%d ", nowNode->data);
    nowNode = nowNode->ptr;
  }

  return 0;
}

void reverse()
{
  Node* prevNode = NULL;
  Node* nowNode = head;
  Node* nextNode = NULL;
  while (nowNode != NULL)
  {
    nextNode = nowNode->ptr;
    nowNode->ptr = prevNode;
    prevNode = nowNode;
    nowNode = nextNode;
  }
  head = prevNode;

}

void delete(int value)
{
  if (value == 0)
  {
    Node* nowNode = head;
    head = head->ptr;
    free(nowNode);
    return 0;
  }
  Node* prevNode = NULL;
  Node* nowNode = head;
  for (int i = 0; i <= value - 2; i++)
  {
    prevNode = nowNode;
    nowNode = nowNode->ptr;
  }
  prevNode->ptr = nowNode->ptr;
  free(nowNode);
}

int main(void)
{
  insert(1);
  insert(5);
  insert(11);
  insert(4);
  delete(0);
  print();
  printf("\n");
  reverse();
  print();
}
