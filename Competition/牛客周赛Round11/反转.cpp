#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        int weight1 = 0;
        int weight2 = 0;
        for (int j = i; j < n; j++) {
            if (j % 2 == 0) {
                if (s[j] != '0') {
                    weight1 += 1;
                }
                if (s[j] != '1') {
                    weight2 += 1;
                }
            } else {
                if (s[j] != '1') {
                    weight1 += 1;
                }
                if (s[j] != '0') {
                    weight2 += 1;
                }
            }
            total_weight += min(weight1, weight2);
        }
    }

    cout << total_weight << endl;

    return 0;
}
