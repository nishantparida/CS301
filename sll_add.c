#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
}node;

void insert(struct node *prev, int new_data)
{
    if (prev == NULL)
    {
    printf("the given previous node cannot be NULL");    
    return;
    }   
    struct node *new =malloc(sizeof(struct node));
    new->number = new_data;
    new->next = prev->next;
    prev->next = new;
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

	node *numbers = NULL;
	while(1)
	{
		int num;
		printf("\nenter your number except 0: ");
		scanf("%d", &num);
	
		if (num!= 0)
		{
		
		node *n = malloc(sizeof(node));

		if(!n)
		{
			return 1;		
		}

		n-> number =num;
		n-> next = NULL;

		if(numbers)
		{
			for (node *ptr =numbers; ptr!=NULL; ptr=ptr->next)
            {
			if(ptr->next == NULL)
			{
				ptr->next=n;
				break;
			}
		}
        }
		else
		{
			numbers=n;		
		}


	}	
    else if(num==0)
    break;
   }
print(numbers);  
   printf("\nEnter the data you want to add");
    int a;
    scanf ("%d",&a);
    insert(numbers, a);
  print(numbers);
}
