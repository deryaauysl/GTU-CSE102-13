#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Define the Node structure*/
struct Node
{
    char class[30];
    char order[30];
    char family[30];
    char genus[30];
    char species[30];
    struct Node *next;
};

/*Function to create a new node*/
struct Node *createNode(char *class, char *order, char *family, char *genus, char *species)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->class, class);
    strcpy(newNode->order, order);
    strcpy(newNode->family, family);
    strcpy(newNode->genus, genus);
    strcpy(newNode->species, species);
    newNode->next = NULL;
    return newNode;
}

/*Function to add a node to the list*/
void addNode(struct Node **head)
{
    char class[30], order[30], family[30], genus[30], species[30];
    printf("Enter class: ");
    scanf("%s", class);
    printf("Enter order: ");
    scanf("%s", order);
    printf("Enter family: ");
    scanf("%s", family);
    printf("Enter genus: ");
    scanf("%s", genus);
    printf("Enter species: ");
    scanf("%s", species);

    struct Node *newNode = createNode(class, order, family, genus, species);
    newNode->next = *head;
    *head = newNode;
}

/*Function to modify an existing node*/
void modifyNode(struct Node *head, char *species)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->species, species) == 0)
        {
            printf("Enter new class: ");
            scanf("%s", temp->class);
            printf("Enter new order: ");
            scanf("%s", temp->order);
            printf("Enter new family: ");
            scanf("%s", temp->family);
            printf("Enter new genus: ");
            scanf("%s", temp->genus);
            printf("Enter new species: ");
            scanf("%s", temp->species);
            return;
        }
        temp = temp->next;
    }
    printf("Species not found.\n");
}

/*Function to delete a node from the list*/
void deleteNode(struct Node **head, char *species)
{
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && strcmp(temp->species, species) == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->species, species) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Species not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/*Function to display the list*/
void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("Class: %s, Order: %s, Family: %s, Genus: %s, Species: %s\n", temp->class, temp->order, temp->family, temp->genus, temp->species);
        temp = temp->next;
    }
}

/*Function to sort the list*/
void sortList(struct Node **head, int sortBy)
{
    struct Node *i, *j;
    char temp[30];

    for (i = *head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if ((sortBy == 1 && strcmp(i->species, j->species) > 0) || (sortBy == 2 && strcmp(i->family, j->family) > 0))
            {
                /*Swap class*/
                strcpy(temp, i->class);
                strcpy(i->class, j->class);
                strcpy(j->class, temp);

                /*Swap order*/
                strcpy(temp, i->order);
                strcpy(i->order, j->order);
                strcpy(j->order, temp);

                /*Swap family*/
                strcpy(temp, i->family);
                strcpy(i->family, j->family);
                strcpy(j->family, temp);

                /*Swap genus*/
                strcpy(temp, i->genus);
                strcpy(i->genus, j->genus);
                strcpy(j->genus, temp);

                /*Swap species*/
                strcpy(temp, i->species);
                strcpy(i->species, j->species);
                strcpy(j->species, temp);
            }
        }
    }
}

int main()
{
    struct Node *head = NULL;
    int choice;
    char species[30];

    do
    {
        printf("Menu:\n");
        printf("1. Add Species\n");
        printf("2. Modify Species\n");
        printf("3. Delete Species\n");
        printf("4. Display Species\n");
        printf("5. Sort Species\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addNode(&head);
            break;
        case 2:
            printf("Enter species to modify: ");
            scanf("%s", species);
            modifyNode(head, species);
            break;
        case 3:
            printf("Enter species to delete: ");
            scanf("%s", species);
            deleteNode(&head, species);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            printf("Sort by:\n1. Species\n2. Family\n");
            int sortBy;
            scanf("%d", &sortBy);
            sortList(&head, sortBy);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
