#include <iostream>
#include <algorithm>
#include <cmath>

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

    // Jump to beginning
    if (index != 0) {

        cout << head << " -> "
             << req[0]
             << " = "
             << abs(head - req[0])
             << endl;

        total_seek += abs(head - req[0]);

        head = req[0];
    }

    // Continue RIGHT again
    for (int i = 1; i < index; i++) {

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