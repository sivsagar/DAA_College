#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void printLevelOrder(Node* root) {
    cout << "Level Order: ";
    if (!root) {
        cout << "<empty>" << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

void printInOrder(Node* root) {
    cout << "In-order: ";
    Node* stack[100];
    int top = -1;
    Node* curr = root;
    while (curr || top >= 0) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // Build a simple BST:  2
    //                    /   \
    //                   1     3
    Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    // Before deletion
    printLevelOrder(root);
    printInOrder(root);

    // Perform deletion of one key (change as needed)
    int keyToDelete = 2; 
    cout << "Deleting: " << keyToDelete << endl;
    root = deleteNode(root, keyToDelete);

    // After deletion
    printLevelOrder(root);
    printInOrder(root);

    freeTree(root);
    return 0;
}
