#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct EVENT
{
    int date;
    int month;
    char name[100];
    struct EVENT *next;
};
typedef struct EVENT event;

event *addevent(event *start, int date, int month, char name[50])
{
    event *new_event;
    new_event = (event *)malloc(sizeof(event));
    new_event->date = date;
    new_event->month = month;
    strcpy(new_event->name, name);
    new_event->next = start;
    start = new_event;
    return start;
}

void deleteevent(event *start, int date, int month)
{
    int n, i = 0;
    char name[20][100];
    event *ptr = start, *temp;
    printf("\nDate: ---Events---\n");
    while (ptr != NULL)
    {
        if (ptr->date == date && ptr->month == month)
        {
            printf("%d.%s\n", i + 1, ptr->name);
            strcpy(name[i], ptr->name);
            i++;
        }
        ptr = ptr->next;
    }
    if (i == 0)
    {
        printf("\nNo events found on entered date\n");
        return;
    }

    printf("\nEnter which event do you want to delete:");
    scanf("%d", &n);

    if (n - 1 < 0 || n - 1 > i)
        printf("\nInvalid event number\n");

    ptr = start;
    if (strcmp(start->name, name[n - 1]) == 0)
    {
        free(ptr);
        printf("\nEvent deleted successfully\n");
    }
    else
    {
        while (ptr != NULL && strcmp(ptr->name, name[n - 1]) != 0)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
            printf("\nEvent not found\n");
        else
        {
            temp->next = ptr->next;
            free(ptr);
            printf("\nEvent deleted successfully\n");
        }
    }
}

void display(event *start, int month)
{
    event *ptr = start;
    event *eventsOfMonth[100];
    int count = 0;
    while (ptr != NULL)
    {
        if (ptr->month == month)
        {
            eventsOfMonth[count] = ptr;
            count++;
        }
        ptr = ptr->next;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (eventsOfMonth[j]->date > eventsOfMonth[j + 1]->date)
            {
                event *temp = eventsOfMonth[j];
                eventsOfMonth[j] = eventsOfMonth[j + 1];
                eventsOfMonth[j + 1] = temp;
            }
        }
    }
    printf("\n______________________\n");
    printf("\nDate: ---Events---\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d.%s\n", eventsOfMonth[i]->date, eventsOfMonth[i]->name);
    }
    printf("\n_______________________\n");
}

int main()
{
    event *start = NULL;
    int date, month, op;
    char name[50];
    

    // January
    start = addevent(start, 1, 1, "New Year Day");
    start = addevent(start, 8, 1, "Harshitha Shankar's Birthday");
    start = addevent(start, 11, 1, "Jahnavi's Birthday");
    start = addevent(start, 12, 1, "Swami Vivekananda Jayanthi");
    start = addevent(start, 14, 1, "Makara Sankranthi");
    start = addevent(start, 26, 1, "Republic Day");

    // February
    start = addevent(start, 4, 2, "Ayush's Birthday");
    start = addevent(start, 8, 2, "Mohith's Birthday");
    start = addevent(start, 9, 2, "Krishna's Birthday");
    start = addevent(start, 14, 2, "Valentine's Day");
    start = addevent(start, 28, 2, "Mayuri patil's Birthday");

    // March
    start = addevent(start, 3, 3, "Keerthan Mada's Birthday");
    start = addevent(start, 7, 3, "Nidhi Patil's Birthday");
    start = addevent(start, 8, 3, "Maha Shivarathri");
    start = addevent(start, 10, 3, "Holi");
    start = addevent(start, 17, 3, "Ilaa ram's Birthday");
    start = addevent(start, 20, 3, "Akash's Birthday");
    start = addevent(start, 20, 3, "Impana's Birthday");
    start = addevent(start, 26, 3, "Hina Shakya's Birthday");
    start = addevent(start, 30, 3, "Kishan Kumar's Birthday");
    start = addevent(start, 30, 3, "Hithesh ST's Birthday");

    // April
       start = addevent(start, 3, 4, "Madhusudan's Biryhday");
       start = addevent(start, 5, 4, "Arman's Biryhday");
    start = addevent(start, 22, 4, "Earth Day");
    start = addevent(start, 24, 4, "Keerthana SR's Birthday");

    // May
    start = addevent(start, 1, 5, "Labour's Day");
    start = addevent(start, 19, 5, "Mallakanna Suresh's Birthday");
    start = addevent(start, 21, 5, "Kanthashree's Birthday");
      start = addevent(start, 22, 5, "Kishna Bansal's Birthday");
    start = addevent(start, 23, 5, "Harshith's Birthday");
    start = addevent(start, 24, 5, "Kiran's Birthday");
    start = addevent(start, 27, 5, "Mohan's Birthday");

    // June
    start = addevent(start, 4, 6, "Kaushal's Birthday");
    start = addevent(start, 4, 6, "Harshitha M's Birthday");
    start = addevent(start, 5, 6, "World Environment Day");
    start = addevent(start, 5, 6, "Nidhi Bhat's Birthday");
    start = addevent(start, 5, 6, "Hanumantha Naik's Birthday");
    start = addevent(start, 6, 6, "Jathin's Birthday");
    start = addevent(start, 13, 6, "Aprameya's Birthday");
    start = addevent(start, 19, 6, "Komal's Birthday");
    start = addevent(start, 20, 6, "Hemang's Birthday");
    start = addevent(start, 22, 6, "Hema CY's Birthday");

    //July
    start = addevent(start, 2, 7, "Mahima's Birthday");
    start = addevent(start, 15, 7, "Keerthana SM's Birthday");
    start = addevent(start, 16, 7, "Karthikeya's Birthday");
    start = addevent(start, 18, 7, "Himavanth's Birthday");
    start = addevent(start, 26, 7, "Himanshu's Birthday");

    // August
    start = addevent(start, 5, 8, "Hemanth's Birthday");
    start = addevent(start, 8, 8, "Jeevitha's Birthday");
    start = addevent(start, 9, 8, "Ekanth's Birthday");
    start = addevent(start, 15, 8, "Independence Day");
    start = addevent(start, 19, 8, "Raksha Bandhan");
    start = addevent(start, 26, 8, "Krishna Janmashtami");

    //september
    start = addevent(start, 2, 9, "Manisha's Birthday");
    start = addevent(start, 4, 9, "Govardhan's Birthday");
    start = addevent(start, 4, 9, "Gautham's Birthday");
    start = addevent(start, 5, 9, "Teacher's Day");
    start = addevent(start, 7, 9, "Ganesha chaturthi");
    start = addevent(start, 15, 9, "Onam");
    start = addevent(start, 15, 9, "Lenora's Birthday");
    start = addevent(start, 17, 9, "Ganesha's Birthday");

    // October
    start = addevent(start, 1, 10, "Lalith's Birthday");
    start = addevent(start, 2, 10, "Gaurav's Birthday");
    start = addevent(start, 2, 10, "Gandhi Jayanti");
    start = addevent(start, 3, 10, "Abhishek's Birthday");
    start = addevent(start, 3, 10, "Mihika's Birthday");
    start = addevent(start, 6, 10, "Harsha TD's Birthday");
    start = addevent(start, 7, 10, "Harshith's Birthday");
    start = addevent(start, 7, 10, "Hithesh Patel's Birthday");
    start = addevent(start, 28, 10, "Deepwali");

    // November
    start = addevent(start, 4, 11, "Hruthi's Birthday");
    start = addevent(start, 9, 11, "Lakshay Gupta's Birthday");
    start = addevent(start, 13, 11, "Krishna Patil's Birthday");
    start = addevent(start, 15, 11, "Harshith Sk's birthday");
    start = addevent(start, 18, 11, "Guru Nanak Jayanti");
    start = addevent(start, 28, 11, "Kush Taunk's Birthday");
    start = addevent(start, 29, 11, "Kushal patil's Birthday");
    start = addevent(start, 30, 11, "Abhinav's Birthday");

    // December
    start = addevent(start, 2, 12, "Pallavi Bai's Birthday");
    start = addevent(start, 4, 12, "Manoj JS's Birthday");
    start = addevent(start, 4, 12, "Chitrashree's Birthday");
    start = addevent(start, 15, 12, "Madan's Birthday");
    start = addevent(start, 17, 12, "Manishankar's Birthday");
    start = addevent(start, 25, 12, "Christmas");

    while (1)
    {
           printf("_______________________\n1.Add an event\n2.Delete an event\n3.Display events  of a month\n4.Exit\n_______________________\nEnter an option:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter date:");
            scanf("%d", &date);
            printf("\n1.Jan  2.Feb  3.Mar  4.Apr  5.May  6.Jun  7.Jul  8.Aug  9.Sep  10.Oct  11.Nov  12.Dec\n\nEnter month:");

            scanf("%d", &month);

            if ((date < 1 || date > 31) || (month < 1 || month > 12))
                printf("Invalid date or month\n");
            else if ((month == 2) && (date > 28))
                printf("Invalid date for February\n");
            else if ((date == 31) && (month == 4 || month == 6 || month == 9 || month == 11))
                printf("Invalid date for this month\n");
            else
            {
                printf("Enter event name:");
                getchar();
                gets(name);
                start = addevent(start, date, month, name);
            }
            break;

        case 2:
            printf("Enter date:");
            scanf("%d", &date);
            printf("\n1.Jan  2.Feb  3.Mar  4.Apr  5.May  6.Jun  7.Jul  8.Aug  9.Sep  10.Oct  11.Nov  12.Dec\n");
            printf("\nEnter month:");
            scanf("%d", &month);

            if ((date < 1 || date > 31) || (month < 1 || month > 12))
                printf("Invalid date or month\n");
            else if ((month == 2) && (date > 29))
                printf("Invalid date for February\n");
            else if ((date == 31) && (month == 4 || month == 6 || month == 9 || month == 11))
                printf("Invalid date for this month\n");
            else
                deleteevent(start, date, month);
            break;
        case 3:
            printf("\n1.Jan  2.Feb  3.Mar  4.Apr  5.May  6.Jun  7.Jul  8.Aug  9.Sep  10.Oct  11.Nov  12.Dec\n");
            printf("\nEnter month:");
            scanf("%d", &month);
            if (month <= 0 || month > 12)
                printf("\nInvalid month\n");
            else
                display(start, month);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
