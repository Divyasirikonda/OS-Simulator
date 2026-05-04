#include <iostream>

using namespace std;

int main() {

    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], wt[n], tat[n];

    // Input burst times
    for (int i = 0; i < n; i++) {

        cout << "Enter burst time for P" << i + 1 << ": ";
        cin >> bt[i];
    }

    // First process waiting time is 0
    wt[0] = 0;

    // Calculate waiting times
    for (int i = 1; i < n; i++) {

        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround times
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