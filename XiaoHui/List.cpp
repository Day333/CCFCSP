#include <cstdio>
#include <iostream>

using namespace std;

// 链表节点结构体
struct Node {
    int data;   // 节点数据
    Node* next; // 指向下一个节点的指针
};

// 打印链表节点的值
void printList(Node* head) {
    Node* currNode = head;
    while (currNode != nullptr) {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
    }
    std::cout << std::endl;
}

// 在链表尾部插入新节点
void insertNode(Node** head, int newData) {
    Node* newNode = new Node(); // 创建新节点
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        // 如果链表为空，将新节点设为头节点
        *head = newNode;
    } else {
        // 遍历到链表尾部
        Node* currNode = *head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        // 插入新节点到尾部
        currNode->next = newNode;
    }
}

// 查找节点
void search(Node* head, int pos) {
    if (head == nullptr) {
        cout << "列表为空，无法查找！" << endl;
        return;
    }
    pos--;
    while (pos) {
        pos--;
        head = head->next;
        if (head == nullptr) {
            printf("查找索引错误！\n");
            return;
        }
    }
    cout << head->data << endl;
}

// 更新节点
void updateList(Node** head, int pos, int value) {
    if (head == nullptr) {
        cout << "列表为空，无法更新！" << endl;
        return;
    }
    pos--;
    Node* currNode = *head;
    while (pos) {
        pos--;
        currNode = currNode->next;
        if (currNode == nullptr) {
            printf("索引错误！\n");
            return;
        }
    }
    currNode->data = value;
}

// 插入节点
void insertList(Node** head, Node* element, int pos) {
    if (pos == 1) {
        element->next = *head;
        *head = element;
        return;
    }
    Node* currNode = *head;
    pos--;
    while (--pos) {
        if (currNode->next == nullptr) {
            if (pos > 0) {
                printf("插入索引错误！\n");
                return;
            }
        }
        currNode = currNode->next;
    }
    element->next = currNode->next;
    currNode->next = element;
}

// 删除节点
void deleteNode(Node** head, int pos){
    if (head == nullptr) {
        cout << "列表为空，无法删除！" << endl;
        return;
    }
    Node* currNode = *head;
    if (pos == 1){
        *head = currNode->next;
        return;
    }
    pos--;
    while (--pos) {
        if (currNode->next == nullptr) {
            if (pos > 0) {
                printf("插入索引错误！\n");
                return;
            }
        }
        currNode = currNode->next;
    }
    currNode->next = currNode->next->next;
}

int main() {
    Node* node = nullptr;
    insertNode(&node, 1);
    insertNode(&node, 2);
    insertNode(&node, 3);
    insertNode(&node, 4);
    printList(node);

    // 查找节点
    search(node, 1);
    search(node, 3);
    search(node, 5);

    //更新节点
    updateList(&node, 1, 2);
    printList(node);

    //插入节点
    Node* element = nullptr;
    insertNode(&element, 10);
    insertList(&node, element, 5);
    printList(node);

    // 删除节点
    deleteNode(&node, 5);
    printList(node);
    return 0;
}