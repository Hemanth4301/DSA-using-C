#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre, *next;
} * head, *temp, *newnode, *x;

int main(int argc, char *argv[])
{
    int op, del;
    head = 0;
    do
    {
        printf("\n***Enter your option***\n1.insert a node at beginning.\n2.display all the nodes.\n3.Delete a node.\n4.quit.\n");
        scanf("%d", &op);

        if (op == 1)
        {
            if (head == 0)
            {
                newnode = (struct node *)malloc(sizeof(node));
                printf("Enter data:");
                scanf("%d", &newnode->data);
                head = newnode;
                newnode->pre = 0;
                newnode->next = 0;
            }
            else
            {
                newnode = (struct node *)malloc(sizeof(node));
                printf("Enter data:");
                scanf("%d", &newnode->data);
                newnode->pre = 0;
                newnode->next = head;
                head = newnode;
            }
        }
        else if (op == 2)
        {
            temp = head;
            while (temp != 0)
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }
        }
        else if (op == 3)
        {
            x = head;
            temp = head;
            printf("Enter element to be deleted:");
            scanf("%d", &del);
            while (temp != 0)
            {
                if (temp->data == del)
                {
                    if (head == temp)
                    {
                        head = temp->next;
                    }
                    else
                    {
                        x->next = temp->next;
                        if(temp->next!=0)
                        temp->next->pre = x;
                    }
                    free(temp);
                    printf("Element deleted successfully\n");
                    break;
                }
                x = temp;
                temp = temp->next;
            }
            if (temp == 0)
                printf("Element not found");
        }

    } while (op != 4);
}