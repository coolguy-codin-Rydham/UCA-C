#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "queue.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int queueSize;
} Queue;

Node *front = NULL;
Node *rear = NULL;
int queueSize = 0;

Node *newNode(int item)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;
    return temp;
};

void enqueue(int item)
{
    Node *temp = newNode(item);
    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    queueSize++;
}

int dequeue()
{
    if (front == NULL)
    {
        return INT_MIN;
    }
    Node *temp = front;
    int item = temp->data;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
    queueSize--;
    return item;
}

bool isEmpty()
{
    return (front == NULL);
}

int size()
{
    return queueSize;
}

void test()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    assert(dequeue() == 1);
    assert(size()==2);
    assert(isEmpty() == false);

    assert(dequeue() == 2);
    assert(size()==1);
    assert(isEmpty() == false);

    assert(dequeue()==3);
    assert(size()==0);
    assert(isEmpty() == true);
}

int main()
{
    test();
    printf("Passed All Test Cases");

    return 0;
}