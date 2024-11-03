#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if (q->size >= MAX_QUEUE_SIZE)
        {
                printf("Queue is full\n");
                return;
        }
        q->proc[q->size] = proc;
        q->size++;
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if (empty(q))
        {
                printf("Queue is empty\n");
                return NULL;
        }

        struct pcb_t * head = q->proc[0];
        
        // Shift all processes to the left
        for (int i = 0; i < q->size - 1; i++)
        {
                q->proc[i] = q->proc[i+1];
        }
        // Assign NULL to the tail of the queue
        q->proc[q->size - 1] = NULL;
        q->size--;

	return head;
}
