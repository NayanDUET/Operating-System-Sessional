#include <bits/stdc++.h>
using namespace std;

// Sample page reference string
vector<int> pageReferences = {
    1, 2, 3, 4, 2, 1, 5, 6, 2, 1,
    2, 3, 7, 6, 3, 2, 1, 2, 3, 6
};

// FIFO Page Replacement Algorithm
int fifoPageFaults(int frameCount) {
    queue<int> frameQueue;
    unordered_set<int> pagesInMemory;
    int faults = 0;

    for (auto page : pageReferences) {
        if (pagesInMemory.find(page) == pagesInMemory.end()) {
            faults++;
            if ((int)pagesInMemory.size() == frameCount) {
                int oldestPage = frameQueue.front(); frameQueue.pop();
                pagesInMemory.erase(oldestPage);
            }
            frameQueue.push(page);
            pagesInMemory.insert(page);
        }
    }

    return faults;
}

// LRU Page Replacement Algorithm
int lruPageFaults(int frameCount) {
    vector<int> memory;
    int faults = 0;

    for (auto page : pageReferences) {
        auto it = find(memory.begin(), memory.end(), page);

        if (it == memory.end()) {
            faults++;
            if ((int)memory.size() == frameCount) {
                memory.erase(memory.begin());  // Remove least recently used
            }
        } else {
            memory.erase(it);  // Move accessed page to the end (most recently used)
        }

        memory.push_back(page);
    }

    return faults;
}

// Optimal Page Replacement Algorithm
int optimalPageFaults(int frameCount) {
    vector<int> memory;
    int faults = 0;

    for (int i = 0; i < (int)pageReferences.size(); ++i) {
        int currentPage = pageReferences[i];

        // If page already in memory, continue
        if (find(memory.begin(), memory.end(), currentPage) != memory.end()) {
            continue;
        }

        faults++;

        // If memory has space, just add the page
        if ((int)memory.size() < frameCount) {
            memory.push_back(currentPage);
            continue;
        }

        // Find the page with the farthest future use
        int indexToReplace = -1, farthestUse = -1;

        for (int j = 0; j < (int)memory.size(); ++j) {
            int nextUse = -1;

            for (int k = i + 1; k < (int)pageReferences.size(); ++k) {
                if (pageReferences[k] == memory[j]) {
                    nextUse = k;
                    break;
                }
            }

            if (nextUse == -1) { // Not used again
                indexToReplace = j;
                break;
            } else if (nextUse > farthestUse) {
                farthestUse = nextUse;
                indexToReplace = j;
            }
        }

        memory[indexToReplace] = currentPage;
    }

    return faults;
}

// Main program
int main() {
    cout << "Frame\tFIFO\tLRU\tOptimal\n";
    for (int frames = 1; frames <= 7; ++frames) {
        int fifoFaults = fifoPageFaults(frames);
        int lruFaults = lruPageFaults(frames);
        int optimalFaults = optimalPageFaults(frames);

        cout << frames << "\t" << fifoFaults << "\t" << lruFaults << "\t" << optimalFaults << '\n';
    }

    return 0;
}
