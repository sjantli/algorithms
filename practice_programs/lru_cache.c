#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
        int pgnum;
        struct Node* prev;
        struct Node* next;
}Node;

typedef struct Queue
{
    int totalFrames;
    int count;
    Node* front;
    Node* rear;
}Queue;

typedef struct Hash
{
    int capacity;
    Node **array;
}Hash;

Node* getNode(int pgnum);
Queue* createQueue(int totalFrames);
Hash* createHash(int capacity);
int isQueueFull(Queue* q);
int isQueueEmpty(Queue* q);
void dequeue(Queue* q);
void enqueue(Queue* q, Hash* hash, int pgnum);
void referencePage(Queue* q, Hash* hash, int pgnum);

int main()
{
    // Let cache can hold 4 pages
    Queue* q = createQueue( 4 );

    // Let 10 different pages can be requested (pages to be
    // referenced are numbered from 0 to 9
    Hash* hash = createHash( 10 );

    // Let us refer pages 1, 2, 3, 1, 4, 5
    referencePage( q, hash, 1);
    referencePage( q, hash, 2);
    referencePage( q, hash, 3);
    referencePage( q, hash, 1);
    referencePage( q, hash, 4);
    referencePage( q, hash, 5);

    //Let us print cache frames after the above referenced pages
    printf ("%d ", q->front->pgnum);
    printf ("%d ", q->front->next->pgnum);
    printf ("%d ", q->front->next->next->pgnum);
    printf ("%d ", q->front->next->next->next->pgnum);
}

Node* getNode(int pgnum)
{
	Node* newnode = (Node *)malloc(sizeof(Node));
	if (newnode != NULL) {
		newnode->prev = NULL;
		newnode->next = NULL;
        newnode->pgnum = pgnum;
	}
	return newnode;
}

Queue* createQueue(int totalFrames) {
    Queue* q = (Queue *)malloc(sizeof(Queue));
    if (q != NULL) {
        q->count = 0;
        q->totalFrames = totalFrames;
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}

Hash* createHash(int capacity) {
    Hash* hash = (Hash *) malloc(sizeof(Hash));
    if (hash != NULL) {
        hash->capacity = capacity;
        hash->array = (Node **) malloc(capacity * sizeof(Node*));
        if (hash->array != NULL) {
            for(int i = 0; i < capacity; i++) {
                hash->array[i] = NULL;
            }
        }
    }
    return hash;
}

int isQueueFull(Queue* q) {
    return (q->count == q->totalFrames);
}

int isQueueEmpty(Queue* q) {
    return (q->rear == NULL);
}

void dequeue(Queue* q) {
    if (isQueueEmpty(q))
        return;
    // if this is the only node, update front
    if (q->front == q->rear)
        q->front = NULL;

    Node* temp = q->rear;
    q->rear = q->rear->prev;

    if (q->rear) {
        q->rear->next = NULL;
    }
    free(temp);
    q->count--;
}

void enqueue(Queue* q, Hash* hash, int pgnum) {
    if (isQueueFull(q)) {
        hash->array[q->rear->pgnum] = NULL;
        dequeue(q);
    }

    Node* temp = getNode(pgnum);
    temp->next = q->front;

    if (isQueueEmpty(q)) {
        //update both front and rear
        q->front = q->rear = temp;
    } else {
        q->front->prev = temp;
        q->front = temp;
    }

    hash->array[pgnum] = temp;
    q->count++;
}

void referencePage(Queue* q, Hash* hash, int pgnum) {
    Node *temp = hash->array[pgnum];
    if (temp == NULL) {
        enqueue(q, hash, pgnum);
    } else if (temp != q->front) {
        // requested page is not at front, rearrange the nodes of queue
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        // if the requested node is rear, update rear
        if (q->rear == temp) {
            q->rear = temp->prev;
            q->rear->next = NULL;
        }

        // Put the temp in the front
        temp->next = q->front;
        temp->prev = NULL;
        temp->next->prev = temp;
        q->front = temp;
    }
}
