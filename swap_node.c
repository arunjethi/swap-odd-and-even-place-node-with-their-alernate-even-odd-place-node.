// Swaping the node: even position with even position node && odd position with odd position node.
// input: 1 12 1 11 1 10 1 9 1 8 1 7 1 6 1 5 1 4 1 3 1 2 1 1 0
// output: 3 4 1 2 7 8 5 6 11 12 9 10 

#include <stdio.h>
#include <stdlib.h>

// creating a structure for linked list
typedef struct node
{
    int data;
    struct node *next;
} Node;    // using typedef we can gave any name to our structure here " Node " is provided.


// function where actual node will be swapped
void swap(Node *first, Node *second)
{
    Node *temp = first->next;
    temp->next = first;
    first->next = second->next;
    second->next = temp;
}

// swap node function called
Node *Swap_node(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *itr = head;
    if (itr->next != NULL && itr->next->next != NULL)
    {
        head = itr->next->next;
    }
    else
        return head;

    while (itr)
    {
        Node *slow = itr, *fast = itr->next;

        if (slow != NULL)
        {
            if (fast != NULL)
            {
                Node *ptr_s = NULL, *ptr_f = NULL;
                if (slow->next->next != NULL)
                {
                    ptr_s = slow->next->next;
                    swap(slow, slow->next->next);
                }
                else
                    break;

                if (fast->next->next != NULL)
                {
                    ptr_f = fast->next->next;
                    swap(fast, fast->next->next);
                    ptr_s->next = ptr_f;
                }
                else
                    break;
            }
        }
        itr = itr->next->next;
        if (fast->next)
        {
            if (fast->next->next)
            {
                if (fast->next->next->next)
                {
                    fast->next = itr->next->next;
                }
            }
        }
    }
    return head;
}

// function to add the node at the beginning of the linked list
Node *insertion_at_begin(Node *head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (!temp)
    {
        printf("Memory not allocated!\n");
        return NULL;
    }

    int val;
    printf("Enter data: ");
    scanf("%d", &val);
    temp->data = val;
    temp->next = head;

    head = temp;

    return head;
}

// function which will display the data of linked list 
void display(Node *head)
{
    if (head == NULL)
        return;
    printf("\nNode data:      ");
    Node *itr = head;
    while (itr)
    {
        printf("%d \t", itr->data);
        itr = itr->next;
    }
}
int main()
{
    Node *head = NULL;
    int choice;
    
    while (1)
    {
        printf("Enter 1 to continue: ");
        scanf("%d", &choice);
        if (choice == 1)
            head = insertion_at_begin(head);
        else
            break;
    }
    head = Swap_node(head);        // swap node function called
    display(head);                 // display function called
    return 0;
}
