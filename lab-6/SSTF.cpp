#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> requestQueue = {12, 34, 52, 14, 25, 68, 39};
    int head = 53;
    int totalHeadMovement = 0;

    vector<bool> visited(requestQueue.size(), false);
    int current = head;

    for (int i = 0; i < requestQueue.size(); i++) {
        int closest = -1;
        int minDistance = INT_MAX;

        // Find the closest unvisited request
        for (int j = 0; j < requestQueue.size(); j++) {
            if (!visited[j]) {
                int distance = abs(current - requestQueue[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    closest = j;
                }
            }
        }

        // Move head to the closest request
        totalHeadMovement += abs(current - requestQueue[closest]);
        current = requestQueue[closest];
        visited[closest] = true;
    }

    cout << "Total Head Movements (SSTF): " << totalHeadMovement << " moves\n";

    return 0;
}
