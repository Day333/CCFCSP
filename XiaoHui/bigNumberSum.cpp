#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string bigNumSum(string bigNumA, string bigNumB) {
    int maxLength = max(bigNumA.length(), bigNumB.length());
    vector<int> vecA(maxLength + 1);
    for (int i = 0; i < bigNumA.length(); ++i) {
        vecA[i] = bigNumA[bigNumA.length() - 1 - i] - '0';
    }
    vector<int> vecB(maxLength + 1);
    for (int i = 0; i < bigNumB.length(); ++i) {
        vecB[i] = bigNumB[bigNumB.length() - 1 - i] - '0';
    }
    vector<int> result(maxLength + 1);
    for (int i = 0; i < result.size(); ++i) {
        int temp = result[i];
        temp += vecA[i];
        temp += vecB[i];
        if (temp >= 10) {
            temp = temp - 10;
            result[i + 1] = 1;
        }
        result[i] = temp;
    }
    reverse(result.begin(), result.end());
    bool findFirst = false;
    string sr = "";
    for (int i = 0; i < result.size(); ++i) {
        if (!findFirst) {
            if (result[i] == 0) {
                continue;
            }
            findFirst = true;
        }
        sr += char(result[i] + '0');
    }
    return sr;
}

int main() {
    string s = "";
    s = bigNumSum("1234", "1234");
    cout << s << endl;
    return 0;
}
