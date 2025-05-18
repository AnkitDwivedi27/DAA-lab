#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        int K; cin >> K;

        unordered_set<int> s(arr.begin(), arr.end());
        int count = 0;

        for (int x : arr) {
            if (s.find(x + K) != s.end()) {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
