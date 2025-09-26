// ******************** Singly LinkedList Operations ********************************


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

void delete_end()
{
    ptr = head;
    if (head != NULL)
    {
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
    }
    else
    {
        printf("List empty");
    }
}

void delete_sp(int pos)
{
    if (pos >= 1 && pos <= count)
    {

        ptr = head;
        if (pos == 1)
        {
            head = head->next;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                ptr1 = ptr;
                ptr = ptr->next;
            }
            ptr1->next = ptr->next;
        }
        free(ptr);
        count--;
    }
    else
    {
        printf("Invalid Position");
    }
}

void update_by_val(int x, int y)
{
    ptr = head;
    if (head != NULL)
    {
        if (count == 1 && ptr->data == x)
        {
            ptr->data = y;
        }
        else
        {
            for (int i = 2; i <= count; i++)
            {
                ptr = ptr->next;
                if (x == ptr->data)
                {
                    ptr->data = y;
                    break;
                }
            }
            printf("Invalid value");
        }
    }
    else
    {
        printf("Empty");
    }
}

void update_by_pos(int pos, int val)
{
    int flag = 0;
    if (pos >= 1 && pos <= count)
    {
        ptr = head;
        if (pos == 1)
        {
            ptr->data = val;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                ptr = ptr->next;
            }
            ptr->data = val;
            flag = 1;
        }
        if (flag == 1)
        {
            printf("Value Updated");
        }
        else
        {
            printf("Value not found");
        }
    }
    else
    {
        printf("Invalid Pos");
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

