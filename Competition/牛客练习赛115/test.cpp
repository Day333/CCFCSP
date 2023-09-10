#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello, World!";
    string slice = str.substr(0, 5);
    string slice2 = str.substr(5, 6);
    string slice3 = str.substr(7);
    cout << slice << endl;   // 输出 "World"
    cout << slice2 << endl;  // 输出 "Hello"
    cout << slice3 << endl;  // 输出 "World!"
    return 0;
}