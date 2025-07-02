#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], bt[n], wt[n], tat[n];


    for (i = 0; i < n; i++)
    {
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> bt[i];
        pid[i] = i + 1;
    }


    wt[0] = 0;


    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }


    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }


    float total_wt = 0, total_tat = 0;

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++)
    {
        cout << pid[i] << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n;

    return 0;
}

