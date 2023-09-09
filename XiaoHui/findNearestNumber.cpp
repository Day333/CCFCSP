#include <iostream>
#include <vector>

using namespace std;

int findTransferpoint(vector<int>& numbers){
    for (int i = numbers.size() - 1; i > 0; -- i){
        if (numbers[i] > numbers[i-1]){
            return i;
        }
    }
    return 0;
}

void exchangeHead(vector<int>& numbers, int index){
    int head = numbers[index - 1];
    for (int i = numbers.size() - 1; i > 0; -- i){
        if (head < numbers[i]){
            numbers[index-1] = numbers[i];
            numbers[i] = head;
            break;
        }
    }
}

vector<int> findNearestNumber(vector<int> numbers){
    // 1、从后向前查看逆序区域，找到逆序区域的前一位，也就是数字置换的边界
    int index = findTransferpoint(numbers);
    //如果数字置换边界是0，说明整个数组已经逆序，无法得到更大相同数字组成的整数返回-1
    if (index == 0){
        return {-1};
    }
    //2、把逆序区域的前一位和逆序区域中刚刚大于它的数字交换位置复制并入参，避免直接修改入参
    vector<int> numbersCopy;
    numbersCopy.assign(numbers.begin(), numbers.end());
    exchangeHead(numbersCopy, index);
    //3、把原来的逆序区域转为顺序
    return numbersCopy;
}

int main(){
    vector<int> v = {1,2,3,4,5};
    vector<int>v1 = findNearestNumber(v);
    for (int i = 0; i < v1.size(); ++ i){
        cout << v1[i] << " ";
    }
    return 0;
}