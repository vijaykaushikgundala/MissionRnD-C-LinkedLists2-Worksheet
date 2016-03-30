/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	if (head1 == NULL && head2 == NULL)
	{
		return NULL;
	}
	int x;
	struct node *temp1, *temp2, *temp;
	temp1 = head1;
	temp2 = head2;
	if (temp1 == NULL)
	{
		return head2;
	}
	if (temp2 == NULL)
	{
		return head1;
	}
	struct node *head = (struct node *)malloc(sizeof(struct node ));
	if (temp1->num > temp2->num)
	{
		x = head2->num;
		head->num = x;
		head->next = NULL;
		temp2 = temp2->next;
	}
	else
	{
	    x= head1->num;
		head->num = x;
		head->next = NULL;
		temp1 = temp1->next;
	}
	head->next = NULL;
	temp = head;
	while (temp1 != NULL||temp2 != NULL)
	{
		if (temp1 == NULL&&temp2 != NULL)
		{
			temp->next = temp2;
			temp = temp2;
			break;
		}
		if (temp2 == NULL&&temp1 != NULL)
		{
			temp->next = temp1;
			temp = temp1;
			break;
		}
		if (temp1->num > temp2->num)
		{
			struct node *newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = temp2->num;
			temp->next = newnode;
			temp = temp->next;
			temp->next = NULL;
			temp2 = temp2->next;
		}
		else
		{
			struct node *newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = temp1->num;
			temp->next = newnode;
			temp = temp->next;
			temp->next = NULL;
			temp1 = temp1->next;
		}
		
	}
	return head;
}
