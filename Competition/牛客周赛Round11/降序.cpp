#include <iostream>
#include <vector>

using namespace std;

bool isDescending(vector<int> vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        while (k--) {
            int a, b;
            cin >> a >> b;
            v[a - 1]++;
            v[b - 1]--;
        }
        if (isDescending(v)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
