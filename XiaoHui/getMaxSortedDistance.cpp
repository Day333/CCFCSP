#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Bucket{
public:
    int min = 0;
    int max = 0;
};

int getMaxSortedDistance(vector<int> vec){
    int max = *max_element(vec.begin(), vec.end());
    int min = *min_element(vec.begin(), vec.end());
    
    int d = max - min;
    if (d == 0){
        return 0;
    }
    int bucketNum = vec.size();
    vector<Bucket> buckets(bucketNum);
    for (int i = 0; i < bucketNum; ++ i){
        buckets.push_back(Bucket());
    }

    // 遍历原始数组，确定每个桶的最大最小值
    for (int i = 0; i < vec.size(); ++ i){
        int index = ((vec[i] - min) * (bucketNum - 1) / d);

        if (buckets[index].min == 0 || buckets[index].min > vec[i]){
            buckets[index].min = vec[i];
        }
        if (buckets[index].max == 0 || buckets[index].max < vec[i]){
            buckets[index].max = vec[i];
        }
    }

    // 遍历桶，找到最大值
    int leftMax = buckets[0].max;
    int maxDistance = 0;
    for (int i = 1; i < buckets.size(); ++ i){
        if (buckets[i].min == 0){
            continue;
        }
        if (buckets[i].min - leftMax > maxDistance){
            maxDistance = buckets[i].min - leftMax;
        }
        leftMax = buckets[i].max;
    }

    return maxDistance;
}

int main(){
    vector<int> v = {2,6,3,4,5,10,9};
    cout << getMaxSortedDistance(v) << endl;
    
    return 0;
}