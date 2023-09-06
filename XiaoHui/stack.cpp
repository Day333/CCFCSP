#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // 栈的容量

class Stack {
  private:
    int arr[MAX_SIZE];
    int top;

  public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_SIZE - 1; }
    void push(int value) {
        if (isFull()) {
            cout << "栈已满，无法插入新元素！" << endl;
            return;
        }
        arr[++top] = value; // 先递增栈顶索引，然后将元素插入到栈顶位置
    }
    int pop() {
        if (isEmpty()) {
            std::cout << "栈为空，无法弹出元素！" << std::endl;
            return -1;
        }
        return arr[top--]; // 返回栈顶元素后，再递减栈顶索引
    }

    int peek() {
        if (isEmpty()) {
            cout << "栈为空，无法查看栈顶元素！" << endl;
            return -1;
        }
        return arr[top]; // 返回栈顶元素，但不修改栈顶索引
    }
};

int main() {
    Stack s;

    cout << s.peek() << endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.peek() << endl;
    return 0;
}