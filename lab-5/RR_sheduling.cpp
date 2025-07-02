#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int pid;
    int bt;
    int wt;
    int tat;
};

int main()
 {
    int n = 3;
    int tq = 5;
    Process p[n] =
    {
        {1, 24, 0, 0},
        {2, 13,  0, 0},
        {3,  9,  0, 0}
    };

    queue<int> q;
    int time = 0;
    int rem_bt[n];
    int start[n] = {0};

    for (int i = 0; i < n; i++)
    {

        q.push(i);
        rem_bt[i] = p[i].bt;
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        if (rem_bt[i] > 0) {

            if (rem_bt[i] == p[i].bt)
                start[i] = time;

            if (rem_bt[i] > tq) {
                time += tq;
                rem_bt[i] -= tq;
                q.push(i);
            } else {
                time += rem_bt[i];
                p[i].wt = time - p[i].bt;
                p[i].tat = time;
                rem_bt[i] = 0;

            }
        }
    }


    float total_wt = 0, total_tat = 0;
    cout << "PID\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        cout << "P" << p[i].pid << "\t" << p[i].bt << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n;

    return 0;
}

