#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head, *temp, *newnode, *tail, *pre;
int main(int argc, char *argv[])
{
    int op, pos, i = 1, ele, del;
    head = 0;
    do
    {
        printf("(Enter your option)\n1.insert at beginning.\n2.insert at specified position.\n3.delete specified value.\n4.Search for a value.\n5.Display all the nodes.\n6.quit\n");
        scanf("%d", &op);

        if (op == 1)
        {
            if (head == 0)
            {
                newnode = (struct node *)malloc(sizeof(node));
                printf("Enter data:");
                scanf("%d", &newnode->data);
                head = newnode;
                newnode->next = 0;
            }
            else
            {
                newnode = (struct node *)malloc(sizeof(node));
                printf("Enter data:");
                scanf("%d", &newnode->data);
                newnode->next = head;
                head = newnode;
            }
        }

        else if (op == 2)
        {
            printf("Enter position:");
            scanf("%d", &pos);
            newnode = (struct node *)malloc(sizeof(node));
            printf("Enter data:");
            scanf("%d", &newnode->data);
            temp = head;
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else if (op == 3)
        {
            temp = head;
            pre = head;
            printf("Enter element to be deleted:");
            scanf("%d", &del);
            while (temp != 0)
            {
                if (temp->data == del)
                {
                    if (temp == head)
                        head = temp->next;
                    else
                        pre->next = temp->next;

                    free(temp);
                    printf("Element deleted successfully.\n");
                    break;
                }
                pre = temp;
                temp = temp->next;
            }

            if (temp == 0)
                printf("Element not found.\n");
        }

        else if (op == 4)
        {
            printf("Enter element to be searched:");
            scanf("%d", &ele);
            temp = head;
            while (temp->next != 0)
            {
                if (temp->data == ele)
                {
                    printf("Element found\n");
                    break;
                }
                temp = temp->next;
            }
            if (temp->next == 0)
                printf("Element not found\n");
        }

        else if (op == 5)
        {
            temp = head;
            while (temp != 0)
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }
        }

    } while (op != 6);
