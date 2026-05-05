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

    bool visited[n] = {false};

    cout << "\nHead Movement:\n";

    // Process all requests
    for (int i = 0; i < n; i++) {

        int min_distance = 100000;

        int index = -1;

        // Find nearest request
        for (int j = 0; j < n; j++) {

            if (!visited[j]) {

                int distance = abs(req[j] - head);

                if (distance < min_distance) {

                    min_distance = distance;
                    index = j;
                }
            }
        }

        // Move head
        cout << head << " -> "
             << req[index]
             << " = "
             << min_distance << endl;

        total_seek += min_distance;

        head = req[index];

        visited[index] = true;
    }

    cout << "\nTotal Seek Time = "
         << total_seek;

    return 0;
}