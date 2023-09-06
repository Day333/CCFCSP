#include <iostream>

using namespace std;

bool isPowerOf2(int num){
    return (num & num - 1) == 0;
}

int main(){
    int n;
    cin >> n;
    cout << isPowerOf2(n) << endl
    return 0;
}