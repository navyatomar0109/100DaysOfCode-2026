//Bugs Identified

//While reviewing the program, I found multiple logical and pointer-related errors that 
//prevented the linked list from functioning correctly. The code compiled, but several
// operations either produced incorrect results or could cause runtime issues.




 //Issues Found
-In insert(), when the list was empty, the new node was never assigned to head, so the first node was lost.
-The next pointer of the newly created node was not initialized to NULL.
-In display(), the loop condition temp != head prevented traversal because temp started at head.
-In deleteHero(), the program incorrectly freed prev instead of the node being deleted.
//-In findMiddle(), the fast pointer advanced by only one node instead of two, so the middle element was calculated incorrectly.

void insert(int id)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->heroID = id;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}



void display()
{
    struct Node* temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->heroID);
        temp = temp->next;
    }

    printf("NULL\n");
}




void deleteHero(int id)
{
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->heroID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
}



struct Node* findMiddle()
{
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


Explanation

The errors were mainly caused by incorrect pointer handling and improper traversal logic.
 Initializing the head node correctly ensures the first insertion succeeds, while setting the
  new node's next pointer to NULL properly terminates the list. 
 The display function now traverses until the end of the list instead of stopping 
 immediately. In the deletion routine, freeing the removed node instead of its
  predecessor avoids memory management issues. Finally, updating the fast pointer by two
   nodes at a time allows the slow pointer to correctly identify the middle node in a 
   single traversal. These changes preserve the linked list structure and satisfy 
   all the required operations mentioned in the assignment.





