#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/* NODE: structure for a node in a doubly-linked-list. the properties:
 * x, y: the cell index in the game board
 * prevZ: the previous value of the cell
 * currZ: the current value of the cell
 * next: pointer to the next node in the list
 * prev: pointer to the previous node in the list */
typedef struct node_t {
    int x;
    int y;
    int prevZ;
    int currZ;
    struct node_t *next;
    struct node_t *prev;
}Node;

/* LINK: a structure for a doubly-linked-list. the properties:
 * head: pointer to a list of nodes
 * next: pointer for the next list, because the undo-redo list is implemented as a list of lists
 * prev: pointer for the previous list, because the undo-redo list is implemented as a list of lists  */
typedef struct list_t{
	Node *head;
	struct list_t * next;
	struct list_t * prev;
}Link;

/* the function gets a head node and frees its list */
void freeListNode(Node *head);

/* the functions gets a head link and deap frees its list - frees the inner lists as well  */
void freeList(Link *head);

/* the function gets the node properties, created a node and adds it to a link (a list).
 * the function returns 1 if the adding was successful and handles memory allocation errors if needed. (returns -1) */
int addNode(Node **lst, int x, int y, int currZ, int prevZ);

/* the function gets the link properties, created a link (a list) and adds it to a list of lists.
 * the function returns 1 if the adding was successful and handles memory allocation errors if needed (returns -1) */
int addLink(Link **lst, int x, int y, int currZ, int prevZ);
#endif /* LINKEDLIST_H_ */
