#include <iostream>
#include <vector>

using namespace std;

vector<int> findLostNum(vector<int> vec){
    // 用于存储2个出现奇数次的整数
    vector<int> result(2);
    // 1、第一次进行异或计算
    int xorResult = 0;
    for (int i = 0; i < vec.size(); ++ i){
        xorResult ^= vec[i];
    }
    // 如果进行异或运算的结果为0，则说明输入的数组不符合题目要求
    if (xorResult == 0){
        return {};
    }
    // 确定两个整数的不同为，以此来做分组
    int separator = 1;
    // 仅在对应的两个位都为1时才会给出1
    while (0 == (xorResult&separator)){
        separator <<= 1;
    }
    // 第2次分组进行异或运算
    for (int i = 0; i < vec.size(); ++ i){
        if (0 == (vec[i] & separator)){
            result[0] ^= vec[i];
        }else{
            result[1] ^= vec[i];
        }
    }
    return result;
}

int main(){
    vector<int> v, a = {4, 1, 2, 2, 5, 1, 4, 3};
    v = findLostNum(a);
    cout << v[0] << " " << v[1] << endl;
    
    return 0;
}