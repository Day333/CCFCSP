#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class Queue {
  private:
    int arr[MAX_SIZE];
    int rear, front;

  public:
    Queue() { rear = front = 0; }
    void enQueue(int element) {
        if ((rear + 1) % MAX_SIZE == front) {
            cout << "队列已满，无法填充！" << endl;
            return;
        }
        arr[rear] = element;
        rear = (rear + 1) % MAX_SIZE;
    }
    int deQueue() {
        if (rear == front) {
            cout << "队列为空，无元素弹出！" << endl;
            return -1;
        }
        int deQueueElement = arr[front];
        front = (front + 1) % MAX_SIZE;
        return deQueueElement;
    }
    void printQueue() {
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    q.printQueue();
    return 0;
}