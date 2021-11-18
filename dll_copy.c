#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int number; 
	struct node *next;
    struct node *prev;
}node;

void print(node *ref)
{
    while(ref!=NULL)
{
    printf("%d\n", ref->number);
    ref=ref->next;
}
}
struct node *dup(node *copy)
{
    if (copy==NULL)
    return NULL;

    else
    {
        node *start=NULL;
        node *new=malloc(sizeof(node));
        if(start==NULL)
        start=new;
      
      new->number=copy->number;
      new->next=dup(copy->next);
      new->prev=copy->prev;

    return new;
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
    node *newnode=dup(numbers);
   print(newnode);
}
