#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n, ret = 1;
    cin >> n;
    while (n--) {
        long long int a, b, c;
        cin >> a >> b >> c;
        if (a + b <= c)
            printf("Case #%d: false\n", ret);
        else
            printf("Case #%d: true\n", ret);
        ret++;
    }

    return 0;
}