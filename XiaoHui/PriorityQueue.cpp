#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class PriorityQueue{
private:
    vector<int> prqueue;
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
        while (index > 0 && prqueue[index] > prqueue[parent(index)]){
            swap(prqueue[index], prqueue[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index){
        int n = prqueue.size();
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < n && prqueue[left] > prqueue[largest]){
            largest = left;
        }
        if (right < n && prqueue[right] > prqueue[largest]){
            largest = right;
        }

        if (largest != index){
            swap(prqueue[index], prqueue[largest]);
            heapifyDown(largest);
        }
    }
public:
    void enQueue(int value){
        prqueue.push_back(value);
        heapifyUp(prqueue.size() - 1);
    }

    int deQueue(){
        // 这段代码删除了栈顶元素
        if (prqueue.empty()){
            throw out_of_range("优先队列为空！");
        }

        int root = prqueue[0];
        prqueue[0] = prqueue[prqueue.size() - 1];
        prqueue.pop_back();
        heapifyDown(0);

        return root;
    }

    void printQueue(){
        for (int i = 0; i < prqueue.size(); ++i){
            cout << prqueue[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    PriorityQueue priorityqueue;
    priorityqueue.enQueue(3);
    priorityqueue.enQueue(5);
    priorityqueue.enQueue(10);
    priorityqueue.enQueue(2);
    priorityqueue.enQueue(7);

    priorityqueue.printQueue();

    cout << "出队元素：" << priorityqueue.deQueue() << endl;
    priorityqueue.printQueue();
    cout << "出队元素：" << priorityqueue.deQueue() << endl;

    return 0;
}