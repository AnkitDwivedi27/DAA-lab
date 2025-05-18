#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        bool found = false;
        for (int k = n - 1; k >= 2 && !found; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                int sum = arr[i] + arr[j];
                if (sum == arr[k]) {
                    cout << i << " " << j << " " << k << "\n";
                    found = true;
                    break;
                }
                else if (sum < arr[k]) {
                    i++;
                }
                else {
                    j--;
                }
            }
        }

        if (!found) cout << "No sequence found\n";
    }
    return 0;
}
