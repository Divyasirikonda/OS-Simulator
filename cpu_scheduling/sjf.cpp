#include <iostream>

using namespace std;

int main() {

    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], wt[n], tat[n], p[n];

    // Input burst times
    for (int i = 0; i < n; i++) {

        p[i] = i + 1;

        cout << "Enter burst time for P" << i + 1 << ": ";
        cin >> bt[i];
    }

    // Sort according to burst time
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (bt[j] > bt[j + 1]) {

                swap(bt[j], bt[j + 1]);
                swap(p[j], p[j + 1]);
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0;

    for (int i = 1; i < n; i++) {

        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {

        tat[i] = wt[i] + bt[i];
    }

    // Display
    cout << "\nProcess\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {

        cout << "P" << p[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}