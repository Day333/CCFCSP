#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<double> bucketSort(vector<double>& vec){
    // 1、 得到数列的最大值和最小值，并算出差值d
    double max = vec[0];
    double min = vec[0];
    for (int i = 0; i < vec.size(); ++ i){
        if (vec[i] > max){
            max = vec[i];
        }
        if (vec[i] < min){
            min = vec[i];
        }
    }
    double d = max - min;

    //2、 初始化桶
    int bucketNum = vec.size();
    vector<vector<double>> bucketList(bucketNum, vector<double>());

    //3、 遍历原始数组，将元素分配到各个桶中
    for (int i = 0; i < vec.size(); ++ i){
        int bucketIndex = (vec[i] - min) / (d / (bucketNum - 1));
        bucketList[bucketIndex].push_back(vec[i]);
    }

    //4、对每个桶中的元素进行排序
    for (int i = 0; i < bucketNum; ++ i){
        sort(bucketList[i].begin(), bucketList[i].end());
    }

    //5、将排序后的元素写会原始数列
    int index = 0;
    for (int i = 0; i < bucketNum; ++i){
        for (int j = 0; j < bucketList[i].size(); ++j){
            vec[index++] = bucketList[i][j];
        }
    }

    return vec;
}

int main(){
    vector<double> vec = {0.1, 0.8, 0.3, 0.5, 0.2, 0.7, 0.6, 0.4};
    vector<double> sortedVec = bucketSort(vec);

    cout << "Sorted array: ";
    for (double num : sortedVec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}