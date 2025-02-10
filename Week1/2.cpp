#include <iostream>
using namespace std;

int main() {
    int n, key, comparisons = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> key;
    int low = 0, high = n - 1;
    bool found = false;
    while(low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) {
            found = true;
            break;
        } else if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if(found)
        cout << "Key found" << endl;
    else
        cout << "Key not found" << endl;
    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
