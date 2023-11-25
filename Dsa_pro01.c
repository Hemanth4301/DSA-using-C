//lab01

//finding largest integer
// #include<stdio.h>
// int find(int *a,int *b,int *c)
// {
//     if(*a>*b && *a>*c)
//     return *a;

//     else if(*b>*a && *b>*c)
//     return *b;
    
//     else
//     return *c;
// }
// int main()
// {
//     int a,b,c;
//     printf("Enter 3 integers:");
//     scanf("%d %d %d",&a,&b,&c);
//     printf("%d is the largest integer",find(&a,&b,&c));
//     return 0;
// }


//searching an element in an array
// #include<stdio.h>
// int main()
// {
//     int n,*ptr,ele,i;
//     printf("Enter size of the array:");
//     scanf("%d",&n);
//     int a[n];
//     ptr=a;

//     printf("Enter array elements:");
//     for(i=0;i<n;i++)
//     scanf("%d",&a[i]);

//     printf("Enter element to be searched:");
//     scanf("%d",&ele);
//     i=0;
//     while(i<n)
//     {
//         if(ele==*ptr)
//         {
//             printf("%d exist in the array",ele);
//             break;
//         }
//         ptr++;
//         i++;
//     }

//     if(i==n)
//     printf("%d isn't exist in the array",ele);
//     return 0;
// }

//finding maximum element in each row of the matrix
// #include<stdio.h>
// int main()
// {
//     int m,n,max,*ptr;
//     printf("Enter number of rows and columns of the matrix:");
//     scanf("%d %d",&m,&n);
//     int a[m][n];
//     ptr=a;
    
//     printf("Enter the elements of the matrix:");
//     for(int i=0;i<m;i++)
//     {
//         for(int j=0;j<n;j++)
//         scanf("%d",&a[i][j]);
//     }
    
//     printf("Given matrix:\n");
//     for(int i=0;i<m;i++)
//     {
//         for(int j=0;j<n;j++)
//         printf("%d ",a[i][j]);
//         printf("\n");
//     }

//     for(int i=0;i<m;i++)
//     {
//         max=0;
//         for(int j=0;j<n;j++)
//         {
//             if(*ptr>max)
//             max=*ptr;
//             ptr++;
//         }
//         printf("Maximum element in %d row:%d\n",(i+1),max);
//     }
//     return 0;
// }


//lab02
//TIME reading and displaying
// #include<Stdio.h>
// #include<stdlib.h>
// struct TIME
// {
//     int hour,min,sec;
//     struct TIME*next;
// };
// void display(struct TIME *x)
// {
//     printf("%d:%d:%d",x->hour,x->min,x->sec);
   
// }

// int main()
// {
//     struct TIME *time1=(struct TIME*)malloc(sizeof(struct TIME));
//     struct TIME *time2=(struct TIME*)malloc(sizeof(struct TIME));
//     time1->next=time2;
//     printf("Enter hours,minutes,seconds of time1:");
//     scanf("%d %d %d",&time1->hour,&time1->min,&time1->sec);

//     printf("Enter hours,minutes,seconds of time2:");
//     scanf("%d %d %d",&time2->hour,&time2->min,&time2->sec);

//     printf("Time 1:");
//     display(time1);

//     printf("Time 2:");
//     display(time2);

//     return 0;
// }


//student details reading 
// #include<stdio.h>
// #include<string.h>

// struct student
// {
//     char name[30];
//     int usn,m1,m2,m3;
//     float avg;
// };
// int main()
// {
//     int n,t1,t2,t3,t4;
//     float t5;
//     char temp[30];
//     printf("Enter number of students:");
//     scanf("%d",&n);
//     struct student a[n],x;
//     for(int i=0;i<n;i++)
//     {
//         printf("Enter details of student %d:\n",(i+1));
//         printf("Enter name:");
//         scanf("%s",a[i].name);

//         printf("Enter USN:");
//         scanf("%d",&a[i].usn);

//         printf("Enter 3 subjects marks out of 100:\n");
//         scanf("%d %d %d",&a[i].m1,&a[i].m2,&a[i].m3);

//         a[i].avg=(a[i].m1+a[i].m2+a[i].m3)/3;
//     }

//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=0;j<n-1-i;j++)
//         {
//             if(a[j+1].avg>a[j].avg)
//             {
//                 t5=a[j+1].avg;
//                 a[j+1].avg=a[j].avg;
//                 a[j].avg=t5;

                
//                 t1=a[j+1].m1;
//                 a[j+1].m1=a[j].m1;
//                 a[j].m1=t1;
                
//                 t2=a[j+1].m2;
//                 a[j+1].m2=a[j].m2;
//                 a[j].m2=t2;

//                 t3=a[j+1].m3;
//                 a[j+1].m3=a[j].m3;
//                 a[j].m3=t3;

//                 t4=a[j+1].usn;
//                 a[j+1].usn=a[j].usn;
//                 a[j].usn=t4;

//                 strcpy(temp,a[j].name);
//                 strcpy(a[j].name,a[j+1].name);
//                 strcpy(a[j+1].name,temp);
//             }
//         }
//     }



//     printf("Details of the student\n");
//     for(int i=0;i<n;i++)
//     {
//         printf("\nstudent %d:\n",(i+1));
//         printf("Name:%s\n",a[i].name);
//         printf("Usn:%d\n",a[i].usn);
//         printf("subject 1 marks:%d\nsubject 2 marks:%d\nsubject 3 marks: %d\n",a[i].m1,a[i].m2,a[i].m3);
//         printf("Total marks:%.d\n",(a[i].m1+a[i].m2+a[i].m3));

//     }

//     return 0;
// }