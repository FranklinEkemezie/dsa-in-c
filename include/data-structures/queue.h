#ifndef QUEUE_H
#define QUEUE_H

/**
 * --------------------------------------
 * QUEUE Data Structure
 * 
 * Queue is a linear data structure that stores elements sequentially.
 * It uses the the FIFO (First In First Out) approach for accessing 
 * elements. Therefore, queues are typically used to manage threads in
 * multithreading and implementing prority queuing systems.
 * Insertion and deletion operations are done sequentially, thus,
 * items/elements added first must be removed first. Similar to a
 * real-world queue, insertion is performed at one end and deletion at
 * the other end.
 * 
 * The size of a queue data structure can be:
 * - Static    - using the usual array data type with fixed length
 * - Dynamic   - implemented using either a dynamic array (which we've
 * implemented before) or even a linked list
 * 
 * The structure of the memory allocation of a queue can be:
 * - Contiguous     - implemented using a (fixed) array data type.
 * - Non-contguous  - implemented using a (singly/doubly) linked list.
 * 
 * In this example, we are implementing:
 * - Static and contiguous queue        - using a fixed size contiguous 
 *                                        (array-like) memory structure.
 * - Dynamic and non-contiguous queue   - using a (doubly) linked list.
 */


/**
 * Static and Contiguous stack
 */
typedef struct Queue
{
    // Pointer to the array holding the
    // data
    int *data;

    // Size of the queue
    int size;

    // Length of the queue
    int length;

    // Index of the first element in the queue:
    // Serves as a pointer to the first element
    int first;
}
Queue;


/**
 * Initialise a Queue data structure
 * Similar to calling the constructor of a class in OOP
 */
Queue createQueue(int size);


/**
 * Free a Queue memory after use
 */
void freeQueue(Queue *q);


/**
 * Remove the last element in the queue and returns it.
 * @return Returns the last element in the queue
 */
int queue_dequeue(Queue *q);


/**
 * Insert an element to the queue
 */
void queue_enqueue(Queue *q, int value);


/**
 * Get the length of the queue
 */
int queue_get_length(Queue q);


/**
 * Get the size of the queue
 */
int queue_get_size(Queue q);


/**
 * Check whether or not a stack is empty
 */
int queue_is_empty(Queue q);


/**
 * Check whether queue is full
 */
int queue_is_full(Queue q);


/**
 * List the elements of a queue
 */
void queue_list(Queue q);


#endif