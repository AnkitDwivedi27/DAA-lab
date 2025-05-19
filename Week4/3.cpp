#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find median of a small group
int findMedian(vector<int>& arr, int left, int n) {
    sort(arr.begin() + left, arr.begin() + left + n);
    return arr[left + n / 2];
}

// Partition function using pivot
int partition(vector<int>& arr, int left, int right, int pivot) {
    int i;
    for (i = left; i < right; ++i) {
        if (arr[i] == pivot) {
            swap(arr[i], arr[right]);
            break;
        }
    }

    i = left;
    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[right]);
    return i;
}

// Median of Medians (Worst-case O(n) selection)
int kthSmallest(vector<int>& arr, int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) {
        int n = right - left + 1;
        vector<int> medians;

        for (int i = 0; i < n / 5; i++)
            medians.push_back(findMedian(arr, left + i * 5, 5));

        if (n % 5 != 0)
            medians.push_back(findMedian(arr, left + (n / 5) * 5, n % 5));

        int medOfMed = (medians.size() == 1) ? medians[0] : kthSmallest(medians, 0, medians.size() - 1, medians.size() / 2);

        int pos = partition(arr, left, right, medOfMed);

        if (pos - left == k - 1)
            return arr[pos];
        if (pos - left > k - 1)
            return kthSmallest(arr, left, pos - 1, k);

        return kthSmallest(arr, pos + 1, right, k - pos + left - 1);
    }

    return -1; // "not present"
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

        int K;
        cin >> K;

        if (K < 1 || K > n) {
            cout << "not present" << endl;
        } else {
            int result = kthSmallest(arr, 0, n - 1, K);
            cout << result << endl;
        }
    }

    return 0;
}
