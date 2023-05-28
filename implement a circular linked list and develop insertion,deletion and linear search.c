#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

// function prototyping
struct node *create(int);
void insert_at_begin(int);

void delete_at_begin();

void update(int, int);
void print_list();

int size_of_list();
int getData();
int getPosition();

int main()
{
    char user_active = 'Y';
    int user_choice;
    int data, position;

    while(user_active == 'Y' || user_active == 'y')
    {

        printf("\n\n------ Circular Singly Linked List -------\n");
        printf("\n1. Insert a node at beginning");

        printf("\n\n2. Delete a node from beginning");

        printf("\n\n3. Print list from beginning");

        printf("\n4. Update a node data");
        printf("\n5. Exit");
        printf("\n\n------------------------------\n");

        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);

        printf("\n------------------------------\n");
        switch(user_choice)
        {
            case 1:
                printf("\nInserting a node at beginning");
                data = getData();
                insert_at_begin(data);
                break;


            case 2:
                printf("\nDeleting a node from beginning\n");
                delete_at_begin();
                break;


            case 3:
                printf("\nPrinting the list from beginning\n\n");
                print_list();
                break;





            case 4:
                printf("\nUpdating the node data");
                data = getData();
                position = getPosition();
                update(position, data);
                break;

            case 5:
                printf("\nProgram was terminated\n\n");
                return 0;

            default:
                printf("\n\t Invalid Choice\n");
        }

        printf("\n...............................\n");
        printf("\nDo you want to continue? (Y/N) : ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }

    return 0;
}

struct node *create(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory can't be allocated.\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// function to insert a new node at the beginning of the list
void insert_at_begin(int data)
{
    struct node *new_node = create(data);

    if (new_node != NULL)
    {
        struct node *last = head;

        // if the list is empty
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }

        // traverse to the end node
        while (last->next != head)
        {
            last = last->next;
        }

        // update  the last node to the new node
        last->next = new_node;

        // update the next pointer of the new node to the head node
        new_node->next = head;

        // update the head of the list to new node
        head = new_node;
    }
}


void delete_at_begin()
{
    // check where the list is empty or not
    if (head == NULL)
    {
        printf("\n List is Empty! \n");
        return;
    }

    // traverse to the end of the list
    struct node *last = head;
    struct node *temp = head;

    // if only one node in the list
    if (last->next == head)
    {
        free(last);
        head = NULL;
        return;
    }

    // traverse to the last node
    while (last->next != head)
    {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
    temp = NULL;
}



void update(int position, int new_data)
{
    if (position <= 0 || position > size_of_list())
    {
        printf("\n Invalid position\n");
        return;
    }

    struct node* temp = head;
    int i = 0;

    while (i <= position)
    {
        temp = temp->next;
        i += 1;
    }

    temp->data = new_data;
}
void print_list()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("\n List is Empty! \n");
        return;
    }

    printf("\n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}




// function to calculate the size of the list
int size_of_list()
{
    if (head == NULL)
    {
        return 0;
    }

    struct node *temp = head;
    int count = 1;

    while (temp->next != head)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

int getData()
{
    int data;
    printf("\n\nEnter Data: ");
    scanf("%d", &data);

    return data;
}

int getPosition()
{
    int pos;
    printf("\n\nEnter Position: ");
    scanf("%d", &pos);

    return pos;
}
