#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Event {
    char name[50];
} Event;

//queue structure
typedef struct QueueNode {
    Event event;
    struct QueueNode *next;
} QueueNode;

//pointers to the queue
typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

//to create queue
Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

//too add element
void enqueue(Queue *queue, Event event) {
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->event = event;
    temp->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }

    queue->rear->next = temp; //incrementing rear
    queue->rear = temp;
}

//to remove element
Event dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        Event emptyEvent = {"No Event"};
        return emptyEvent;
    }

    QueueNode *temp = queue->front;
    Event event = temp->event;
    queue->front = queue->front->next; //incrementing front to remove element

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return event;
}

//to print the queue
void printQueue(Queue *queue) {
    QueueNode *temp = queue->front;
    printf("Event Queue:\n");
    while (temp != NULL) {
        printf("Event: %s\n", temp->event.name);
        temp = temp->next;
    }
}

int main() {
    Queue *queue = createQueue();

    Event event1 = {"Conference"};
    Event event2 = {"Meetup"};
    Event event3 = {"Workshop"};

  
    enqueue(queue, event1);
    enqueue(queue, event2);
    enqueue(queue, event3);

 
    printQueue(queue);

    
    printf("\nDequeued event: %s\n", dequeue(queue).name);
    
    
    printQueue(queue);

    
    free(queue);

    return 0;
}