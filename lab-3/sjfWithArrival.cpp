#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n], wt[n], tat[n];
    int complete = 0, time = 0, shortest = 0;
    bool found = false;
    float total_wt = 0, total_tat = 0;


    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for Process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i];
    }


    while (complete != n) {
        int minm = 1e9;
        found = false;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < minm) {
                minm = rt[i];
                shortest = i;
                found = true;
            }
        }

        if (!found) {
            time++;
            continue;
        }

        rt[shortest]--;


        if (rt[shortest] == 0) {
            complete++;
            int finish_time = time + 1;
            tat[shortest] = finish_time - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        time++;
    }


    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << "\n";

    return 0;
}

