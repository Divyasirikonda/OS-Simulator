#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n;

    cout << "Enter number of requests: ";
    cin >> n;

    int req[n];

    // Input requests
    for (int i = 0; i < n; i++) {

        cout << "Enter request " << i + 1 << ": ";
        cin >> req[i];
    }

    int head;

    cout << "Enter initial head position: ";
    cin >> head;

    // Sort requests
    sort(req, req + n);

    int total_seek = 0;

    cout << "\nHead Movement:\n";

    int index;

    // Find first request greater than head
    for (index = 0; index < n; index++) {

        if (req[index] > head)
            break;
    }

    // Move RIGHT
    for (int i = index; i < n; i++) {

        cout << head << " -> "
             << req[i]
             << " = "
             << abs(req[i] - head)
             << endl;

        total_seek += abs(req[i] - head);

        head = req[i];
    }

    // Move LEFT
    for (int i = index - 1; i >= 0; i--) {

        cout << head << " -> "
             << req[i]
             << " = "
             << abs(req[i] - head)
             << endl;

        total_seek += abs(req[i] - head);

        head = req[i];
    }

    cout << "\nTotal Seek Time = "
         << total_seek;

    return 0;
}