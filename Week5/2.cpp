#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasPairWithSum(vector<int>& arr, int key) {
    sort(arr.begin(), arr.end()); // O(n log n)
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == key)
            return true;
        else if (sum < key)
            left++;
        else
            right--;
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int key;
        cin >> key;

        if (hasPairWithSum(arr, key))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
