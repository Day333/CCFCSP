#include <iostream>
#include <string>

using namespace std;

string removeZero(string num);

string removeDigits(string num, int k) {
    string numNew = num;
    for (int i = 0; i < k; ++i) {
        bool hasCut = false;
        for (int j = 0; j < numNew.length() - 1; ++j) {
            if (numNew[j] > numNew[j + 1]) {
                numNew = numNew.substr(0, j) + numNew.substr(j + 1);
                hasCut = true;
                break;
            }
        }
        if (!hasCut) {
            numNew = numNew.substr(0, numNew.length() - 1);
        }
        numNew = removeZero(numNew);
    }
    if (numNew.length() == 0) {
        return "0";
    }
    return numNew;
}

string removeZero(string num) {
    for (int i = 0; i < num.length(); ++i) {
        if (num[0] != '0') {
            break;
        }
        num = num.substr(1);
    }
    return num;
}

int main() {
    string s = "";
    s = removeDigits("1593212", 3);
    cout << s << endl;
    s = removeDigits("30200", 1);
    cout << s << endl;

    return 0;
}
