#include <cstdio>
#include <iostream>

#define BigSize 20

using namespace std;

void printArray(int arr[], int size) {
    cout << "当前数组为：" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 扩展数组大小
int* resizeArray(int*& array, int size, int newSize) {
    int* newArray = new int[newSize];

    // 复制原数组的元素到新数组
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array; // 释放原数组内存
    return newArray;
}

// 插入
void biginsert(int* array, int element, int index) {
    int* a = resizeArray(array, 8, BigSize);
    a[index] = element;
    printArray(a, BigSize);
}

// 插入
void insert(int* array, int element, int index) {
    if (index < 0) {
        printf("无效索引！");
        return;
    }

    if (index >= 8) {
        biginsert(array, element, index);
        return;
    }

    for (int i = 8; i >= index; i--) {
        array[i + 1] = array[i];
    }
    array[index] = element;
}

// 删除元素
int deleteElement(int* array, int index) {
    if (index < 0 || index >= 10) {
        printf("索引错误！");
    }
    for (int i = index; i < 9; i++) {
        array[i] = array[i + 1];
    }
    return 10 - 1;
}

int main() {
    int* array = new int[10]{3, 1, 2, 5, 4, 9, 7, 2};
    // array[5] = 1;
    // printf("%d", array[5]);
    printArray(array, 10);
    // 尾部插入
    array[8] = 1;
    printArray(array, 10);
    array[8] = 0;
    // 中部插入
    insert(array, 11, 4);
    printArray(array, 10);
    // 头部插入
    insert(array, 12, 0);
    printArray(array, 10);

    // 超范围插入
    int* array1 = new int[8]{3, 1, 2, 5, 4, 9, 7, 2};
    biginsert(array1, 100, 8);

    // 删除元素
    int size = deleteElement(array, 2);
    printArray(array, size);
    return 0;
}
