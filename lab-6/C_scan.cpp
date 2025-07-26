#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> requestQueue = {12, 34, 52, 14, 25, 68, 39};
    int head = 53;
    int diskSize = 91; // 0 to 90

    vector<int> left, right;
    int totalHeadMovement = 0;

    for (auto req : requestQueue) {
        if (req < head)
            left.push_back(req);
        else
            right.push_back(req);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int current = head;

    // Move forward to higher requests
    for (auto track : right) {
        totalHeadMovement += abs(current - track);
        current = track;
    }

    // Go to end of disk
    totalHeadMovement += abs(current - (diskSize - 1));
    // Jump to beginning (simulate circular)
    totalHeadMovement += (diskSize - 1); // from end (90) to 0
    current = 0;

    // Now serve requests from beginning
    for (auto track : left) {
        totalHeadMovement += abs(current - track);
        current = track;
    }

    cout << "Total Head Movements (C-SCAN): " << totalHeadMovement << " moves\n";

    return 0;
}
