#include <iostream>

using namespace std;

int main() {

    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], rem_bt[n], wt[n], tat[n];

    // Input burst times
    for (int i = 0; i < n; i++) {

        cout << "Enter burst time for P" << i + 1 << ": ";
        cin >> bt[i];

        rem_bt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0;

    // Round Robin scheduling
    while (true) {

        bool done = true;

        for (int i = 0; i < n; i++) {

            if (rem_bt[i] > 0) {

                done = false;

                // Process executes fully
                if (rem_bt[i] <= tq) {

                    time += rem_bt[i];

                    wt[i] = time - bt[i];

                    rem_bt[i] = 0;
                }

                // Process executes partially
                else {

                    time += tq;

                    rem_bt[i] -= tq;
                }
            }
        }

        // Exit when all processes complete
        if (done == true)
            break;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {

        tat[i] = wt[i] + bt[i];
    }

    // Display results
    cout << "\nProcess\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {

        cout << "P" << i + 1 << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}