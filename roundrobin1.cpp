#include<iostream>
using namespace std;

void WaitingTime(int processes[], int n,int bt[], int wt[], int quantum_time )
{
    // Make a copy of burst times bt[] to store remaining burst times.
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = bt[i];
 
    int t = 0; // initial  time
 
    
    while (1)
    {
        bool done = true;
 
        for (int i = 0 ; i < n; i++)
        {
            // If burst time of a process is greater than 0 then only need to process further
            if (rem_bt[i] > 0)
            {
                done = false; 
 
                if (rem_bt[i] > quantum_time)
                {
                    // Increase the value of t, 
                    // how much time a process has been processed
                    t += quantum_time;
 
                    // Decrease the burst_time of current process
                    // by quantum time
                    rem_bt[i] -= quantum_time;
                }
 
                // If burst time is smaller than or equal to quantum time. Last cycle for this process
                else
                {
                    // Increase the value of t it shows how much time a process has been processed
                    t = t + rem_bt[i];
 
                    // Waiting time is current time minus time use by this process
                    wt[i] = t - bt[i];
 
                    // As the process gets fully execute its remaining burst time = 0
                    rem_bt[i] = 0;
                }
            }
        }
 
        // If all processes are done
        if (done == true)
        break;
    }
}
 
// Function to calculate turn around time
void TurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 

void avgTime(int processes[],int n,int bt[],int quantum_time)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // Function to find waiting time of all processes
    WaitingTime(processes, n, bt, wt, quantum_time);
 
    // Function to find turn around time for all processes
    TurnAroundTime(processes, n, bt, wt, tat);
 
    // Display processes along with all details
    cout <<"Processes "<<" Burst time "<<" Waiting time "<<" Turn around time\n";
 
    // Calculate total waiting time and total turn
    // around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
            << wt[i] <<"\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
 
int main()
{
    int processes[] = { 1,2,3,4,5};
    int n = sizeof processes / sizeof processes[0];
 
    int burst_time[] = {4,9,3,6,7};
 
    
    int quantum_time = 2;
    avgTime(processes, n, burst_time, quantum_time);
    return 0;
}