
#include<iostream>
using namespace std;
 
void WaitingTime(int processes[], int n, int bt[], int wt[])
{
    
    wt[0] = 0;  // waiting time for first process is 0
 
    //  waiting time calculation
    for (int  i = 1; i < n ; i++ )
        wt[i] = bt[i-1] + wt[i-1] ;
}
 

void TurnAroundTime( int processes[],int n,int bt[],int wt[],int tat[] )
{
    // calculating turnaroundtime
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 

void avgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    //total waiting time of all processes
    WaitingTime(processes, n, bt, wt);
 
    // totalturnaround time of all processes
    TurnAroundTime(processes, n, bt, wt, tat);
 
    //Displaying details of processes
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";
 
    //  total waiting time and total turn around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
 

int main()
{
    int processes[] = { 1,2,3,4,5 };
    int n = sizeof processes / sizeof processes[0];
 
    // burst time of all processes
    int  burst_time[] = {1,6,12,14,7};
 
    avgTime(processes,n,burst_time);
    return 0;
}