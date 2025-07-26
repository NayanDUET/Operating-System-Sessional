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

    // Add end of disk to simulate going to the end
    right.push_back(diskSize - 1);

    sort(left.begin(), left.end(), greater<int>());
    sort(right.begin(), right.end());

    int current = head;

    // Move toward higher tracks
    for (auto track : right) {
        totalHeadMovement += abs(current - track);
        current = track;
    }

    // Then reverse and move toward smaller tracks
    for (auto track : left) {
        totalHeadMovement += abs(current - track);
        current = track;
    }

    cout << "Total Head Movements (SCAN): " << totalHeadMovement << " moves\n";

    return 0;
}
