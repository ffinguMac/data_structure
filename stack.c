#include <stdio.h> //리스트로 구현한 스택
#include <stdlib.h>

// 스택의 노드 구조체
typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* top = NULL;  // 스택의 top 노드를 나타내는 포인터

// 스택에 원소를 삽입하는 함수 (push)
void push(int x) {
  Node* newNode = (Node*)malloc(sizeof(Node));  // 새로운 노드 동적 할당
  newNode->data = x;                           // 새로운 노드의 데이터 설정
  newNode->next = top;                         // 새로운 노드의 next를 현재 top으로 설정
  top = newNode;                               // top을 새로운 노드로 업데이트
}

// 스택에서 원소를 삭제하고 반환하는 함수 (pop)
int pop() {
  if (top == NULL) {
    printf("Error: Stack is empty.\n");
    return -1;
  }
  int popped = top->data;  // 현재 top의 데이터 저장
  Node* temp = top;       // 현재 top 노드를 임시 변수에 저장
  top = top->next;        // top을 다음 노드로 업데이트
  free(temp);             // 삭제한 노드 메모리 해제
  return popped;          // 삭제한 노드의 데이터 반환
}

// 스택의 top에 위치한 원소를 반환하는 함수 (top)
int top() {
  if (top == NULL) {
    printf("Error: Stack is empty.\n");
    return -1;
  }
  return top->data;  // 현재 top의 데이터 반환
}

// 스택이 비어있는지 여부를 반환하는 함수 (IsEmpty)
int IsEmpty() {
  return (top == NULL) ? 1 : 0;
}
