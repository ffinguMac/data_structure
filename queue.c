#include <stdio.h> //리스트로 구현한 큐
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL; // 큐의 앞(front) 포인터
Node* rear = NULL; // 큐의 뒤(rear) 포인터

// 큐에 원소를 삽입하는 함수 (enqueue)
void enqueue(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL) { // 큐가 비어있는 경우 front와 rear가 같은 노드를 가리키도록 초기화
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
// 큐에서 원소를 삭제하고 반환하는 함수 (dequeue)
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = front->data;
    Node* tmp = front;
    front = front->next;
    if (front == NULL) { // 큐가 비어있는 경우 rear도 NULL로 초기화
        rear = NULL;
    }
    free(tmp);
    return data;
}
// 큐의 front 원소를 반환하는 함수 (front)
int frontElement() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return front->data;
}
// 큐가 비어있는지 여부를 반환하는 함수 (IsEmpty)
int isEmpty() {
    return (front == NULL) ? 1 : 0;
}
