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

void accept(struct stud list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\nEnter data for Student #%d", i + 1);
        
        printf("\nEnter Student id : ");
        scanf("%d", &list[i].Sid);

        printf("Enter time taken for food (minuts): ");
        scanf("%d", &list[i].Food_time);
    } 
}

void display(struct stud list[80], int s)
{
    int i,AvgWT=0,AvgTAtime=0;
	int TotalWatingTime=0,TotalTAtime=0;
    printf("\n\n\t\t\tLRTF OUTPUT\n");
  
    printf("\n|Student id\tFood_time\tWaitingTime\tTurnaroundtime  |");
    
    for (i = 0; i < s; i++)
    {
        printf("\n|   %d     \t   %d        \t  %d       \t  %d             |", list[i].Sid, list[i].Food_time,list[i].WT,list[i].TAtime);
        printf("\a\n|---------------------------------------------------------------|");
		TotalWatingTime= TotalWatingTime+list[i].WT;
		TotalTAtime= TotalTAtime+list[i].TAtime;
	} 
	printf("\n\n   Total Waiting Time is: = %d",TotalWatingTime);
	printf("\n   Total Turn around Time is: = %d\n\n",TotalTAtime);
	printf("\n\n   Average Waiting Time is: = %d",TotalWatingTime/s);
	printf("\n   Average Turn around Time is: = %d\n\n",TotalTAtime/s);
}

void scheduling(struct stud list[80], int s)
{
    int i, j;
    struct stud temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].Food_time < list[j + 1].Food_time)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
            else if(list[j].Food_time == list[j + 1].Food_time)
            {
            	if(list[j].Sid > list[j + 1].Sid)
            	{
            	temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                }
			}
        }
    }
}
// funtion for calculation of TurnAROUND TIME with no return value
void turnAroundTime(struct stud list[80], int n)
{
	int j,total;
    
    for(j=0;j<n;j++)
    {
        list[j].TAtime=list[j].WT+list[j].Food_time;
    }
}

//Funtion for calculation of Waiting time with no return Value
void waitingTime(struct stud list[80], int n)
{
	int j,total;
    list[0].WT=0;
    for(j=1;j<n;j++)
    {
        list[j].WT=list[j-1].WT+list[j-1].Food_time;
    }
}


