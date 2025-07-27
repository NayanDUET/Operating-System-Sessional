#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int at;     // Arrival time
    int bt;     // Burst time
    int priority;
    int wt;     // Waiting time
    int tat;    // Turnaround time
    bool completed = false; // To mark if process is completed
};

// Custom comparator for sorting by arrival time, then priority
bool arrivalPriorityCompare(Process a, Process b) {
    if (a.at == b.at)
        return a.priority < b.priority;
    return a.at < b.at;
}

int main() {
    int n = 5;
    Process p[] = {
        {1, 0, 10, 3},
        {2, 1,  1, 1},
        {3, 2,  2, 4},
        {4, 3,  1, 5},
        {5, 4,  5, 2}
    };

    int completed = 0;
    int current_time = 0;
    float total_wt = 0, total_tat = 0;

    vector<Process> schedule;

    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        // Find the next process with highest priority and has arrived
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= current_time) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                } else if (p[i].priority == highest_priority) {
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            p[idx].wt = current_time - p[idx].at;
            if (p[idx].wt < 0) p[idx].wt = 0;

            current_time += p[idx].bt;
            p[idx].tat = p[idx].wt + p[idx].bt;
            p[idx].completed = true;
            completed++;
        } else {
            current_time++;
        }
    }

    // Output results
    cout << "PID\tAT\tBT\tPriority\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].priority << "\t\t" << p[i].wt << "\t" << p[i].tat << "\n";
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n;

    return 0;
}
