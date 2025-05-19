#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];

    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    vector<int> common;
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (a[i] == b[j]) {
            common.push_back(a[i]);
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (int val : common)
        cout << val << " ";
    cout << endl;

    return 0;
}
