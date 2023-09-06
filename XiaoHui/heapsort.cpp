#include <iostream>
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
    BinaryHeap(vector<int> array){
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
    vector<int> heap = {1, 4, 5, 2, 22, 3, 4, 5};
    BinaryHeap heap1(heap);

    heap1.printHeap();

    return 0;
}