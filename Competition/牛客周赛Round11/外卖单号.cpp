//根据题意，我们可以看出订单编号的范围在1到m之间。当一个订单的编号达到m时，
//下一个订单的编号会回到1。所以，为了求第x个订单的编号，我们只需要求x对m
//取余的结果。如果余数为0，则表示订单编号为m，否则订单编号为x对m的余数。

#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        long long m, x;
        cin >> m >> x;
        long long result = x % m;
        if(result == 0) {
            cout << m << endl;
        } else {
            cout << result << endl;
        }
    }
    return 0;
}
