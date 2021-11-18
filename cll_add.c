#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
}node;

node *head = NULL;  
node *tail = NULL;  

struct node *addAfter(struct node *last, int data, int item)
{
    if (last == NULL)
       return NULL;
 
    struct node *temp, *p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            temp = malloc(sizeof(struct node));
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;
            
            if (p == last)
                last = temp;
 
            return last;
        }
        p = p -> next;
    } while (p != last -> next);
    return last;
}
   
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

   display();  
   printf("\nEnter the data you want to add");
    int a;
    scanf ("%d",&a);
    printf("\nEnter the node index where you want to add");
    int c;
    scanf("%d", &c);
    addAfter(head, a,c);
  display();
     
   return 0;  
}  
