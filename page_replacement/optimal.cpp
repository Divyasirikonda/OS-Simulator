#include <iostream>
#include <vector>
using namespace std;
int main() {
int n;
    cin>>n;
    vector<int>pages(n);
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
                break;
            }
        }

        // If page not found
        if (!found) {

            page_faults++;

            // If memory has space
            if (frames.size() < capacity) {

                frames.push_back(page);
            }

            // Replace optimal page
            else {

                int replace_index = 0;

                int farthest = -1;

                // Check future use of every frame page
                for (int j = 0; j < frames.size(); j++) {

                    int next_use = 1000;

                    for (int k = i + 1; k < pages.size(); k++) {

                        if (frames[j] == pages[k]) {

                            next_use = k;
                            break;
                        }
                    }

                    // Find farthest future use
                    if (next_use > farthest) {

                        farthest = next_use;
                        replace_index = j;
                    }
                }

                frames[replace_index] = page;
            }
        }

        // Display frames
        cout << "Frames: ";

        for (int x : frames) {
            cout << x << " ";
        }

        cout << endl;
    }

    cout << "\nPage Faults = " << page_faults;

    return 0;
}