#include <iostream>
#include <string>

using namespace std;

// 计算两位数中0的数量
int countZeroInTwoDigits(int num) {
    int count = 0;
    if (num < 10) count++;  // 如果小于10，十位为0
    if (num % 10 == 0) count++;  // 判断个位是否为0
    return count;
}

int main() {
    string s;
    cin >> s;

    int a_score = 0, b_score = 0;
    int zero_count = 0;

    for (char c : s) {
        if (c == 'a') {
            a_score++;
        } else {
            b_score++;
        }
        zero_count += countZeroInTwoDigits(a_score) + countZeroInTwoDigits(b_score);
    }

    cout << zero_count << endl;

    return 0;
}
