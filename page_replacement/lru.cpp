#include <iostream>
#include <vector>

using namespace std;

int main() {

   int n;
    cin>>n;
    int pages[n];
    for(int i=0;i<n;++i){
        cin>>pages[i];
    }
    int capacity;
    cin>>capacity;

    vector<int> frames;

    int page_faults = 0;

    for (int i = 0; i < n; i++) {

        int page = pages[i];

        bool found = false;

        // Check if page already exists
        for (int j = 0; j < frames.size(); j++) {

            if (frames[j] == page) {

                found = true;

                // Move page to most recently used position
                frames.erase(frames.begin() + j);
                frames.push_back(page);

                break;
            }
        }

        // If page not found
        if (!found) {

            page_faults++;

            // If memory full remove least recently used
            if (frames.size() == capacity) {
                frames.erase(frames.begin());
            }

            frames.push_back(page);
        }

        // Display frames
        cout << "Frames: ";

        for (int x : frames) {
            cout << x << " ";
        }

        cout << endl;
    }

    cout << "\nTotal Page Faults = " << page_faults;

    return 0;
}