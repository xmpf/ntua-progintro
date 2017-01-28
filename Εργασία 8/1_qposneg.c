#include <stdio.h>
#include <stdlib.h>

typedef enum bool_t {false, true} bool_t;

typedef struct node_t {
	int data;
	struct node_t *next;
} node_t;

typedef struct queue_t {
	node_t *head;
	node_t *tail;
	int		size;
} queue_t;

// Function prototypes
queue_t empty (void); 			// Return empty Queue.
int isEmpty (queue_t *);		// Check if Queue is empty.
void enqueue (queue_t *, int); 	// Insert element.
int dequeue (queue_t *); 		// Discard element.
int peek (queue_t *); 			// Return first element.
void cleanGarbage (queue_t *);  // Clean garbage if left


int main (void)
{
	bool_t exact = false;
	int value;
	int amount = 0; // amount > 0 => more positive values;
					// amount < 0 => more negative values;
					// amount = 0 => exact amount of positive and negative values
	queue_t pos_queue;
	queue_t neg_queue;

	pos_queue = neg_queue = empty ();

	while ((scanf ("%d", &value)) == 1) { // While successfully reading input:

		if (value > 0) {
			amount += 1;
			enqueue (&pos_queue, value);
		} else {
			amount -= 1;
			enqueue (&neg_queue, value);
		}

	}

	if (amount == 0) {
		while (pos_queue.size > 0) {
			if (dequeue (&pos_queue) == abs (dequeue (&neg_queue)))
				exact = true;
			else {
				exact = false;
				printf ("no\n");
				break;
			}
		}
	} else {
		printf ("no\n");
	}
	if (exact) {
		printf ("yes\n");
	} else {
		cleanGarbage (&pos_queue);
		cleanGarbage (&neg_queue);
	}
	return (0);
}

queue_t empty (void)
{
	queue_t temp;
	temp.head = NULL;
	temp.tail = NULL;
	temp.size = 0;

	return (temp);
}

int isEmpty (queue_t *queue)
{
	/* 0: indicates falsehood | 1: indicates truth */
	if (queue->head == NULL) {
		return (1);
	}
	return (0);
}

void enqueue (queue_t *queue, int data)
{
	node_t *node = (node_t *)malloc (sizeof (node_t));
	if (node == NULL) {
		fprintf (stderr, "[E] Insufficient memory.\n");
		exit (EXIT_FAILURE);
	}

	node->data = data;
	node->next = NULL;

	if (queue->head == NULL) {
		queue->head = node;
	} else {
		queue->tail->next = node;
	}

	queue->tail = node;
	queue->size += 1;
}

int dequeue (queue_t *queue)
{
	if (queue->head == NULL) {
		fprintf (stderr, "[E] Queue is empty.\n");
		exit (EXIT_FAILURE);
	}
	node_t *node;
	int value;

	node = queue->head;
	value = node->data;
	queue->head = node->next;

	if (queue->head == NULL)
		queue->tail = NULL;

	queue->size -= 1;
	free (node);
	return (value);
}

int peek (queue_t *queue)
{
	if (queue->head == NULL) { exit (EXIT_FAILURE); }

	return (queue->head->data);
}

void cleanGarbage (queue_t *queue)
{
	if (queue->head == NULL) { exit (EXIT_FAILURE); }
	node_t *node;
	node = queue->head;
	while (node != NULL) {
		queue->head = node->next;
		free (node);
		node = queue->head;
	}
}
