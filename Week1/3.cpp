#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, key, comparisons = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> key;

        int step = sqrt(n);
        int prev = 0;
        bool found = false;

        while (arr[min(step, n) - 1] < key) {
            comparisons++;
            prev = step;
            step += sqrt(n);
            if (prev >= n) {
                break;
            }
        }

        for (int i = prev; i < min(step, n); i++) {
            comparisons++;
            if (arr[i] == key) {
                found = true;
                break;
            }
        }

        if (found)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }
    return 0;
}
