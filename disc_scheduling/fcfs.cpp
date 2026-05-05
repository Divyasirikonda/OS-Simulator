#include <iostream>
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

    int total_seek = 0;

    cout << "\nHead Movement:\n";

    for (int i = 0; i < n; i++) {

        int movement = abs(req[i] - head);

        cout << head << " -> " << req[i]
             << " = " << movement << endl;

        total_seek += movement;

        head = req[i];
    }

    cout << "\nTotal Seek Time = "
         << total_seek;

    return 0;
}