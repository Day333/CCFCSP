#include <iostream>

using namespace std;

int main() {
    int n, ret = 0;
    cin >> n;
    while (n != 1) {
        ret ++;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
    }
    cout << ret << endl;
    return 0;
}