#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<char> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int freq[26] = {0};

        for (int i = 0; i < n; ++i)
            freq[arr[i] - 'a']++;

        int maxFreq = 0;
        char maxChar = 'a';

        for (int i = 0; i < 26; ++i) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = 'a' + i;
            }
        }

        cout << maxChar << endl;
    }

    return 0;
}
