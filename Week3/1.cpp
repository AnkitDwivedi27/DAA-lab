#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    comparisons = 0;
    shifts = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            } else {
                break;
            }
        }

        if (j + 1 != i) shifts++;
        arr[j + 1] = key;
    }
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

        int comparisons = 0, shifts = 0;
        insertionSort(arr, comparisons, shifts);

        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;

        cout << comparisons << endl;
        cout << shifts << endl;
    }

    return 0;
}
