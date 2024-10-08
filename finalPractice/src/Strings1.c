/**
 * Search singly linked list by the key name.
 *
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - key to search
 * @return Pointer to found node if found; otherwise NULL
 */

// iterative through the list
// compare value of each node with key
// if key matches return the corned else
// continue to iterate through list until end is reached.
NODE* sll_search(SLL *sllp, char *name) {
	NODE *foundNode = NULL;

	NODE *currNode = sllp->start;

	while (currNode != NULL) {
		if (strcmp(currNode->data, name) == 0) {
			return currNode;
		}
		currNode = currNode->next;
	}
	return foundNode;
}
