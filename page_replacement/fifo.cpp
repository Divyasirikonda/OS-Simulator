#include <iostream>
#include <queue>
#include <unordered_set>

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

    queue<int> q;
    unordered_set<int> s;

    int page_faults = 0;

    for (int i = 0; i < n; i++) {

        if (s.find(pages[i]) == s.end()) {

            if (q.size() == capacity) {
                int val = q.front();
                q.pop();
                s.erase(val);
            }

            q.push(pages[i]);
            s.insert(pages[i]);

            page_faults++;
        }

        cout << "Frames: ";

        queue<int> temp = q;

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }

    cout << "\nTotal Page Faults = " << page_faults;

    return 0;
}