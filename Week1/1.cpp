#include <iostream>
using namespace std;

int main() {
    int n, key, comparisons = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> key;
    bool found = false;
    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == key) {
            found = true;
            break;
        }
    }
    if(found)
        cout << "Key found" << endl;
    else
        cout << "Key not found" << endl;
    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
