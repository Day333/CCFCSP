#include <iostream>
#include <unordered_set>


using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}


// 哈希表实现
bool hasCycle1(Node* head) {
    std::unordered_set<Node*> visited;

    Node* curr = head;
    while (curr != nullptr) {
        if (visited.find(curr) != visited.end()) {
            return true;  // 发现环
        }
        visited.insert(curr);  // 将当前节点插入HashSet中
        curr = curr->next;
    }

    return false;
}

int CycleSize(Node* head){
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;
    int ret = 0;
    int count = 0;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (count > 0){
            ret += 1;
        }

        if (slow == fast) {
            if (count > 0){
                break;
            }else{
                count += 1;
            }
        }
    }

    return ret;
}

int CycleNode(Node* head){
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            break;
        }
    }

    int ret = 0;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
        ret ++;
        if (slow == fast) {
            break;
        }
    }

    return ret;
}

int main() {
    // 创建链表节点
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    Node* node5 = new Node();

    // 设置节点的值和指针指向
    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = node4;

    node4->data = 4;
    node4->next = node5;

    node5->data = 4;
    node5->next = node3;  // 构造环，node4 的下一个节点指向 node2

    // 检查链表是否有环
    bool cycle = hasCycle(node1);
    if (cycle) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list does not have a cycle." << std::endl;
    }

    cout << CycleSize(node1) << endl;

    cout << CycleNode(node1) << endl;
    // 释放链表内存
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}