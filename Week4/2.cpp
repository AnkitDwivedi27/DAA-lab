#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

long long comparisons = 0;
long long swaps = 0;

int partition(vector<int>& arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);
    swaps++;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        comparisons = 0;
        swaps = 0;

        quickSort(arr, 0, n - 1);

        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;

        cout << comparisons << endl;
        cout << swaps << endl;
    }

    return 0;
}
