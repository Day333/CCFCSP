#include <iostream>
using namespace std;

// 二分查找
int binarySearch(int L, int R, int cnt) {
    int l = L, r = R;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int curCnt = f(L, R, mid);
        
        if (curCnt < cnt) {
            l = mid + 1;
        } else if (curCnt > cnt) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    
    return -1;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int L, R, cnt;
        cin >> L >> R >> cnt;
        
        int result = binarySearch(L, R, cnt);
        cout << result << endl;
    }
    
    return 0;
}
