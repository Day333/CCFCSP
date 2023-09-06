#include <iostream>
#include <vector>

using namespace std;

void bubble(vector<int>& array) {
    for (int i = 0; i < array.size() - 1; ++i) {
        for (int j = 0; j < array.size() - 1; ++j) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void bubble1(vector<int>& array) {
    for (int i = 0; i < array.size() - 1; ++i) {
        bool isSorted = true;
        for (int j = 0; j < array.size() - 1 - i; ++j) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}

void bubble2(vector<int>& array) {
    int sortBorder = array.size() - 1;
    int lastExchangeIndex = 0;
    for (int i = 0; i < array.size() - 1; ++i) {
        bool isSorted = true;
        for (int j = 0; j < sortBorder; ++j) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
                isSorted = false;
                lastExchangeIndex = j;
            }
        }
        sortBorder = lastExchangeIndex;
        if (isSorted)
            break;
    }
}

void cocktail(vector<int>& array) {
    for (int i = 0; i < array.size() / 2; ++i) {
        bool isSorted = true;
        for (int j = i; j < array.size() - 1 - i; ++j) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
        isSorted = true;
        for (int j = array.size() - i - 1; j > i; --j) {
            if (array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}

int main() {
    vector<int> myVector = {3, 2, 5, 7, 12, 2, 4};

    // 双重循环
    bubble(myVector);
    for (int i = 0; i < myVector.size(); ++i)
        cout << myVector[i] << " ";
    cout << endl;

    // 提前判断是否有序
    bubble1(myVector);
    for (int i = 0; i < myVector.size(); ++i)
        cout << myVector[i] << " ";
    cout << endl;

    // 减少重复排序
    bubble1(myVector);
    for (int i = 0; i < myVector.size(); ++i)
        cout << myVector[i] << " ";
    cout << endl;

    // 鸡尾酒排序，双向冒泡排序
    cocktail(myVector);
    for (int i = 0; i < myVector.size(); ++i)
        cout << myVector[i] << " ";
    cout << endl;

    return 0;
}