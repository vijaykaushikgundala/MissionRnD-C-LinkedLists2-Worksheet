/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
	{
		return -1;
	}
	struct node *temp;
	int count = 0, r, x, y;
	temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	temp = head;
	if (count % 2 != 0)
	{
		count = count / 2;
		while (count > 0)
		{
			temp = temp->next;
			count--;
		}
		r = temp->num;
		return r;
	}
	else
	{
		temp = head;
		x = (count / 2) - 1;
		y = (count / 2);
		while (x > 0)
		{
			temp = temp->next;
			x--;
		}
		x = temp->num;
		temp = head;
		while (y > 0)
		{
			temp = temp->next;
			y--;
		}
		y = temp->num;
		r = (x + y) / 2;
		return r;
	}
}
