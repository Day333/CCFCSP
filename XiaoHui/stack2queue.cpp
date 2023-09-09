#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    std::stack<int> stackA;
    std::stack<int> stackB;
public:
    void enQueue(int element){
        stackA.push(element);
    }
    int deQueue(){
        if (stackB.empty()){
            if (stackA.empty()){
                return 0; // 或者根据具体需求返回其他值表示队列为空
            }
            transfer();
        }
        int frontElement = stackB.top();
        stackB.pop();
        return frontElement;
    }
    void transfer(){
        while (!stackA.empty()) {
            stackB.push(stackA.top());
            stackA.pop();
        }
    }
};

int main(){
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(5);
    q.enQueue(3);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    
    return 0;
}