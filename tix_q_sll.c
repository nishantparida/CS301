/*C Program to Implement Ticket & Queue using Singly Linked List */

#include <stdio.h>
#include <malloc.h>
#include<string.h>

/* * Node Declaration */
struct person
{
    char name[50];
    struct person *next;
};

struct ticket
{
char number[50];
struct ticket *next;
};

struct person* create_person(char *);
struct ticket* create_ticket(char *);

void insert_person();
void insert_ticket();
void display_persons();
void display_tickets();
void delete_person();
void delete_ticket();

struct person *newperson;
struct person *ptrPerson;
struct person *prev;
struct ticket *prevt;
struct ticket *newticket;
struct ticket *ptrTicket;

struct person * firstPerson = NULL;
struct person * lastPerson = NULL;
struct ticket * firstTicket = NULL;
struct ticket * lastTicket = NULL; 

/* * Main function: It contains menu. This menu displays the operations the customer can do like adding person in the Queue, adding ticket of a person, display people in line and display tickets.  */

int main()
{
int ch;
char ans = 'Y';

while (ans == 'Y'||ans == 'y') //For displaying options
{
printf("\n---------------------------------\n");
printf("\nOperations on Ticket & Queue\n");
printf("\n---------------------------------\n");
printf("\n1. Add Person in Q");
        printf("\n2. Add ticket");
printf("\n3.Display All Persons in Q:");
printf("\n4.Display All Tickets");
printf("\n5. Delete any Person in Q:");
printf("\n6.Delete any ticket:");
printf("\n10.Exit\n");
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("\nEnter your choice : ");
scanf("%d", &ch);

switch (ch) //For performing the desired operations
{
case 1: 
    printf("\n...Adding Person in Q...\n");
    insert_person();
    break;

  case 2: 
    printf("\n...Adding Ticket...\n");
    insert_ticket();
    break;      
case 3: 
    printf("\n...Displaying Persons in Q From Beginning to End : \n");
    display_persons();
    break;
case 4: 
    printf("\n...Displaying Tickets From Beginning to End :\n");
    display_tickets();
    break;
case 5:
        printf("\n...Enter the person name to be deleted:\n");  
        char val[50];
        scanf("%s",&val);
        delete_person(val);
        printf("\n...Displaying the queue after deleting %s from the queue",val) ;
        display_persons();
        break;
case 6:
        printf("\n...Enter the ticket to be deleted:\n"); 
        char value[50];
        scanf("%s",&value);
        delete_ticket(value);
        printf("\n...Displaying the tickets after deleting %s from the queue",value) ;
        display_tickets();
        break;           
case 10: 
    printf("\n...Exiting...\n");
    return 0;
    break;
default: 
    printf("\n...Invalid Choice...\n");
    break;
}
printf("\n\n You want to continue (Y/N)");
scanf(" %c", &ans);
}
return 0;
 }
 
/* Creating Node for person */
struct person* create_person(char *ptrName)
{
newperson = (struct person *)malloc(sizeof(struct person));
if (newperson == NULL)
{
printf("\nMemory was not allocated");
return 0;
}
else
{
strcpy(newperson->name, ptrName);
newperson->next = NULL;
return newperson;
}
}
 
/* Creating Node for ticket */
struct ticket* create_ticket(char *tktNumber)
{
newticket = (struct ticket *)malloc(sizeof(struct ticket));
if (newticket == NULL)
{
printf("\nMemory was not allocated");
return 0;
}
else
{
strcpy(newticket->number, tktNumber);
newticket->next = NULL;
return newticket;
}
}

/* Inserting Node for person */
void insert_person()
{
char val[50];

printf("\nEnter the name of person : ");    
scanf("%s", val);
newperson = create_person(val);
if (firstPerson == lastPerson && lastPerson == NULL)
{
firstPerson = lastPerson = newperson;
firstPerson->next = NULL;
lastPerson->next = NULL;
}
else
{
lastPerson->next = newperson;
lastPerson = newperson;
lastPerson->next = NULL;
}
printf("\n----INSERTED----");
}    

/* Inserting Node for ticket */
void insert_ticket()
{
char val[50];

printf("\nEnter the number of ticket : ");    
scanf("%s", val);
newticket = create_ticket(val);
if (firstTicket == lastTicket && lastTicket == NULL)
{
firstTicket = lastTicket = newticket;
firstTicket->next = NULL;
lastTicket->next = NULL;
}
else
{
lastTicket->next = newticket;
lastTicket = newticket;
lastTicket->next = NULL;
}
 printf("\n----INSERTED----");
} 
/* Displays non-empty List of people from Beginning to End */
void display_persons()
{
if (firstPerson == NULL)
{

printf(":No Person in the list to display\n");
}
else
{
for (ptrPerson = firstPerson; ptrPerson != NULL;ptrPerson = ptrPerson->next)
{    
  printf("%s\t", ptrPerson->name);
}
}
}
void delete_person(char *per_name)
{
        printf("In delete function of queue\n");
        ptrPerson = firstPerson;
        // If head node itself holds the key to be deleted
    if (ptrPerson != NULL && strcmp(ptrPerson->name,per_name)==0)
        {
        firstPerson = ptrPerson->next; // Changed head
        free(ptrPerson); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (ptrPerson != NULL && strcmp(ptrPerson->name,per_name)!=0) 
        {
        prev = ptrPerson;
        ptrPerson = ptrPerson->next;
    }
    // If key was not present in linked list
    if (ptrPerson == NULL)
    {
        return;
        }   
 
    // Unlink the node from linked list
    prev->next = ptrPerson->next;
    free(ptrPerson); // Free memory     
    
}

//delete ticket function
void delete_ticket(char *tic_num)
{
        printf("In delete function of ticket\n");
        ptrTicket = firstTicket;
        // If head node itself holds the key to be deleted
    if (ptrTicket != NULL && strcmp(ptrTicket->number,tic_num)==0)
        {
        firstTicket = ptrTicket->next; // Changed head
        free(ptrTicket); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (ptrTicket != NULL && strcmp(ptrTicket->number,tic_num)!=0) 
    {
        prevt = ptrTicket;
        ptrTicket = ptrTicket->next;
    }
    // If key was not present in linked list
    if (ptrTicket == NULL)
    {
        return;
    }   
 
    // Unlink the node from linked list
    prevt->next = ptrTicket->next;
    free(ptrTicket); // Free memory     
    
}
/* Displays non-empty List of tickets from Beginning to End */
void display_tickets()
{
if (firstTicket == NULL)
{
printf(":No Ticket in the list to display\n");
}
else
{
for (ptrTicket = firstTicket; ptrTicket != NULL;ptrTicket = ptrTicket->next)
{    
    printf("%s\t", ptrTicket->number);
}
}
} 
