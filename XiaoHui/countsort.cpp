#include <iostream>
#include <vector>

using namespace std;

int* countSort(vector<int>& array) {
    // 1、得到数列的最大值
    int max = array[0];
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    // 2、根据数列最大值确定统计数组的长度
    int* countArray = new int[max + 1]();
    // 3、遍历数列，填充统计数组
    for (int i = 0; i < array.size(); ++i) {
        countArray[array[i]]++;
    }
    // 4、遍历统计数组，输出结果
    int index = 0;
    int* sortedArray = new int[array.size()];
    for (int i = 0; i <= max; ++i) {
        for (int j = 0; j < countArray[i]; j++) {
            sortedArray[index++] = i;
        }
    }
    delete[] countArray;
    return sortedArray;
}

// 优化：1. 统计数组的大小改为最大值-最小值+1；2. 相同值的排序问题
int* countSort1(vector<int>& array) {
    // 1、得到数列的最大值
    int max = array[0];
    int min = array[0];
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    int d = max - min;
    // 2、根据数列最大值确定统计数组的长度
    int* countArray = new int[d + 1]();
    for (int i = 0; i < array.size(); ++i) {
        countArray[array[i] - min]++;
    }
    // 3、统计数组做变形，后面的元素等于前面元素之和
    for (int i = 1; i < d + 1; ++ i){
        countArray[i] += countArray[i-1];
    }

    // 4、倒序遍历原始数列，从统计数组找到正确位置，输出到结果数列
    int* sortedArray = new int[array.size()];
    for (int i = array.size() - 1; i >= 0; -- i){
        sortedArray[countArray[array[i]-min]-1]=array[i];
        countArray[array[i]-min] --;
    }
    delete[] countArray;
    return sortedArray;
}

int main() {
    vector<int> vec = {1, 4, 5, 2, 22, 3, 4, 5};
    int* res = countSort1(vec);

    int size = vec.size();
    for (int i = 0; i < size; ++i)
        cout << res[i] << " ";

    // 释放排序后的数组内存
    delete[] res;
    return 0;
}