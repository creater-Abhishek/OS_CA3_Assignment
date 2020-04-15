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
