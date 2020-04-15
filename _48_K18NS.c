#include <stdio.h>
struct stud
{
	//student id
    int Sid;
    //taken time
    int Food_time;
    //For waiting time
    int WT;
    // for Turnaround time
    int TAtime;
};

void accept(struct stud list[], int s);
void display(struct stud list[], int s);
void scheduling(struct stud list[], int s);
void waitingTime(struct stud list[], int n);
void turnAroundTime(struct stud list[], int n);
#include <stdio.h>
struct stud
{
	//student id
    int Sid;
    //taken time
    int Food_time;
    //For waiting time
    int WT;
    // for Turnaround time
    int TAtime;
};

void accept(struct stud list[], int s);
void display(struct stud list[], int s);
void scheduling(struct stud list[], int s);
void waitingTime(struct stud list[], int n);
void turnAroundTime(struct stud list[], int n);

int main()
{
    struct stud data[30];
    int n,i;
    char c='n';
    do
	{
    printf("enter the No. of Students who will eat in mess? : ");
    scanf("%d", &n);
    accept(data, n);
    scheduling(data, n);
    waitingTime(data,n);
    turnAroundTime(data,n);
    display(data, n);
    printf("for Next data  or else to quit'1' : ");
    scanf("%s",&c);
    }while(c=='1');
    return 0;
} 
