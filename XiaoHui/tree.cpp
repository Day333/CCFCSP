#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// 创建新节点
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// 插入节点, 查找二叉树
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// 在二叉树中搜索值，递归实现
bool searchNode(Node* root, int data) {
    if (root == nullptr) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data <= root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// 输出二叉树的节点（中序遍历）
void printTree(Node* root){
    if (root == nullptr){
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

// 输出二叉树的节点（前序遍历）
void printTree1(Node* root){
    if (root == nullptr){
        return;
    }
    cout << root->data << " ";
    printTree1(root->left);
    printTree1(root->right);
}
// 后序遍历
void printTree2(Node* root){
    if (root == nullptr){
        cout << "二叉树为空！" << endl;
        return;
    }
    printTree(root->left);
    printTree(root->right);
    cout << root->data << " ";
}


// 非递归前序遍历
void iterativePreorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<Node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        Node* currentNode = nodeStack.top();
        std::cout << currentNode->data << " ";
        nodeStack.pop();

        if (currentNode->right) {
            nodeStack.push(currentNode->right);
        }
        if (currentNode->left) {
            nodeStack.push(currentNode->left);
        }
    }
    cout << endl;
}

// 层序遍历
void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        Node* currentNode = nodeQueue.front();
        std::cout << currentNode->data << " ";
        nodeQueue.pop();

        if (currentNode->left) {
            nodeQueue.push(currentNode->left);
        }
        if (currentNode->right) {
            nodeQueue.push(currentNode->right);
        }
    }
}

int main() {
    Node* root = nullptr;

    // 插入节点
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    // 输出二叉树中的节点
    cout << "二叉树节点的值：";
    printTree1(root);
    cout << endl;
     
    // 搜索节点 
    int searchValue = 4;
    if (searchNode(root, searchValue)) {
        cout << "节点 " << searchValue << " 存在于二叉树中。" << endl;
    } else {
        cout << "节点 " << searchValue << " 不存在于二叉树中。" << endl;
    }

    // 非递归前序遍历
    iterativePreorder(root);

    //层序遍历
    levelOrderTraversal(root);
    return 0; 
}