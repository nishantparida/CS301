#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
}node;
node *head = NULL;  
node *tail = NULL;  
   
void add(int data)
{  
    node *newNode = malloc(sizeof(struct node));  
    newNode->data = data;   
    if(head == NULL)
    {  
        head = newNode;  
        tail = newNode;  
        newNode->next = head;  
    }
    else 
    {    
        tail->next = newNode;  
        tail = newNode;  
        tail->next = head;  
    }  
}  
void display()
{  
    node *current = head;  
    if(head == NULL){  
        printf("List is empty");  
    }  
    else
    {  
         do {    
            printf("%d\n", current->data);  
            current = current->next;  
        }while(current != head);  
        printf("\n");  
    }  
}  
      
int main()  
{  
    int i, num;
    while(1)
    {
    printf("Enter your data value except 0\n");
    scanf("%d",&num);
    if (num==0)
    break;
    else if(num!=0)
    add(num);
    }

    node *current=head;
    printf("\nEnter the number you want to replace");
    int old, recent;
    scanf("%d", &old);
    printf("\nEnter the new number");
    scanf("%d", &recent);
    while(current!=NULL)
    {
        if(current->data==old)
        {
        current->data=recent;
        break;
        }

        current=current->next;
    }

   display();  
     
   return 0;  
}  
