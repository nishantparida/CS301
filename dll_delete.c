#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int number; 
	struct node *next;
    struct node *prev;
}node;

void delete(struct node *ref, int key)
{
    struct node *temp = ref, *prevnode;

    if (temp != NULL && temp->number == key) 
    {
        ref = temp->next; 
        free(temp); 
        return;
    }
 
    while (temp != NULL && temp->number != key) 
    {
        prevnode = temp;
        temp = temp->next;
    }
 
    if (temp == NULL)
        return;
 
    prevnode->next = temp->next;
    prevnode->prev=temp->prev;
 
    free(temp);
}
 
void print(node *ref)
{
    while(ref!=NULL)
{
    printf("%d\n", ref->number);
    ref=ref->next;
}
}
int main(void)
{

    struct node *head = NULL;
    struct node *last = NULL;
    struct node *numbers = NULL;

	while(1)
	{
		int num;
		printf("\nenter you number: ");
		scanf("%d", &num);
	
		if (num != 0)
		{
		node *n = malloc(sizeof(node));

		if(!n)
		{
			return 1;		
		}

		n-> number =num;
		n-> next = NULL;
        n-> prev = NULL;

        if(head==NULL) 
         head = n;

		if(numbers)
        	{
			for (node *ptr =numbers; ptr!=NULL; ptr=ptr->next)
            {
			if(ptr->next == NULL)
			{
				n->prev= head;
                last=n;
                ptr->next=last;
				break;
			}
		}
            }
		else
		{
			numbers=n;		
		}

	}	
         else if (num==0)
           break;
    }
printf("Enter the position of the node");
int p;
scanf("%d", &p);
delete(numbers, p);
print(numbers);
}
