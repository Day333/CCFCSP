#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

const int Max_Size = 10;

class MinStack{
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int element){
        mainStack.push(element);

        if (minStack.empty() || element <= minStack.top()){
            minStack.push(element);
        }
    }

    void pop(){
        if (mainStack.top() == minStack.top()){
            minStack.pop();
        }

        return mainStack.pop();
    }

    int getMin(){
        if (mainStack.empty()){
            throw "stack is empty";
        }
        return minStack.top();
    }
};


int main(){
    MinStack stack;
    stack.push(4);
    stack.push(9);
    stack.push(7);
    stack.push(3);
    stack.push(8);
    stack.push(5);
    
    cout << stack.getMin() << endl;

    stack.pop();
    stack.pop();
    stack.pop();

    cout << stack.getMin() << endl;

    return 0;
}