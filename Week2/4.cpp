#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(const vector<int>& arr, int key) {
    int low = 0, high = (int)arr.size() - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;  // keep searching to the left
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int lastOccurrence(const vector<int>& arr, int key) {
    int low = 0, high = (int)arr.size() - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;  // keep searching to the right
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        int key; 
        cin >> key;

        int first = firstOccurrence(arr, key);
        if (first == -1) {
            cout << "Key not present\n";
        } else {
            int last = lastOccurrence(arr, key);
            int count = last - first + 1;
            cout << key << " " << count << "\n";
        }
    }
    return 0;
}
