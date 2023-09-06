#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class BinaryHeap{
private:
    vector<int> heap;
    
    int parent(int index){
        if (!index){
            throw out_of_range("发生寻找根节点父亲节点的错误！");
        }
        return (index - 1) /2;
    }

    int leftChild(int index){
        return 2 * index + 1;
    }

    int rightChild(int index){
        return 2 * index + 2;
    }

    void heapifyUp(int index){
        while (index > 0 && heap[index] > heap[parent(index)]){
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index){
        int n = heap.size();
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < n && heap[left] > heap[largest]){
            largest = left;
        }
        if (right < n && heap[right] > heap[largest]){
            largest = right;
        }

        if (largest != index){
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
public:
    void insert(int value){
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int remove(){
        // 这段代码删除了栈顶元素
        if (heap.empty()){
            throw out_of_range("二叉堆为空！");
        }

        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(0);

        return root;
    }

    void buildHeap(vector<int> array){
        heap = move(array); // 此时，array的内容将移动到heap，array将为空
        int n = heap.size();
        // n / 2 - 1最后一个非叶子节点
        for (int i = n / 2 - 1; i >= 0; --i){
            heapifyDown(i);
        }
    }

    void printHeap(){
        for (int i = 0; i < heap.size(); ++i){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    BinaryHeap binaryheap;

    // 插入
    binaryheap.insert(5);
    binaryheap.insert(8);
    binaryheap.insert(3);
    binaryheap.insert(10);

    cout << "此时二叉堆：";
    binaryheap.printHeap();

    // 删除元素
    int root = binaryheap.remove();
    cout << "删除元素：" << root << endl;

    cout << "此时的二叉堆：" << endl;
    binaryheap.printHeap();

    // 构建二叉堆
    vector<int> array = {9,4,2,7,1};
    binaryheap.buildHeap(array);

    cout << "堆构建后：";
    binaryheap.printHeap(); 

    return 0;
}