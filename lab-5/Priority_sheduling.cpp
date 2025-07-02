#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int bt;
    int priority;
    int wt;
    int tat;
};

bool compare(Process a, Process b) {
    return a.priority < b.priority;
}

int main() {
    int n = 5;
    Process p[] = {
        {1, 10, 3, 0, 0},
        {2,  1, 1, 0, 0},
        {3,  2, 4, 0, 0},
        {4,  1, 5, 0, 0},
        {5,  5, 2, 0, 0}
    };


    sort(p, p + n, compare);

    p[0].wt = 0;
    p[0].tat = p[0].bt;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }


    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t" << p[i].priority << "\t\t"
             << p[i].bt << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n;

    return 0;
}

