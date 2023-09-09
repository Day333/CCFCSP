#include <iostream>
using namespace std;

int f(int L, int R, int x) {
    int cnt = 0;
    while (L <= R) {
        cnt++;
        int mid = (L + R) / 2;
        if (mid == x)
            break;
        else if (mid < x)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return cnt;
}

int findX(int L, int R, int cnt) {
    int low = L;
    int high = R;
    while (low <= high) {
        int mid = (low + high) / 2;
        int num = f(L, R, mid);
        if (num == cnt)
            return mid;
        else if (num < cnt)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int L, R, cnt;
        cin >> L >> R >> cnt;
        
        int result = findX(L, R, cnt);
        cout << result << endl;
    }
    
    return 0;
}
