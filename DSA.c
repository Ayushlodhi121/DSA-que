#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL, *ptr, *ptr1;
int count = 0;

void insert_beg(int x)
{
    ptr = (node *)malloc(sizeof(node));

    ptr->data = x;
    if (head == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        ptr->next = head;
    }
    head = ptr;
    count++;
}

void insert_end(int x)
{
    ptr = (node *)malloc(sizeof(node));
    ptr->data = x;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr1 = head;
        while (ptr1->next != NULL)
        {
            ptr1 = ptr1->next;
        }
        ptr1->next = ptr;
    }
    count++;
}

void insert_sp(int pos, int x)
{
    if (pos >= 1 && pos <= count+1)
    {
        if (pos == 1)
        {
            insert_beg(x);
        }
        else if (pos == count + 1)
        {
            insert_end(x);
        }
        else
        {
            ptr = (node *)malloc(sizeof(node));
            ptr->data = x;
            ptr1 = head;
            for(int i = 1; i < pos-1; i++){
                ptr1 = ptr1->next;
            }
            ptr->next = ptr1->next;
            ptr1->next = ptr;
            count++;
        }
    }
    else
    {
        printf("Invalid Position");
    }
}

void delete_beg()
{
    if (head != NULL)
    {
        ptr = head;
        head = head->next;
        free(ptr);
        count--;
    }
    else
    {
        printf("List is Empty");
    }
}

void traverse()
{
    if (head != NULL)
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    insert_end(11);
    insert_end(12);
    insert_end(13);
    insert_end(14);
    insert_end(15);
    traverse();
}