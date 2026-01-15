#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int main() {
    
    Node* root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = new Node();
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    
    cout << "Level Order: ";
    queue<Node*> q;
    q.push(root);
    // Level-order traversal visits each node once: O(n)
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;

    
    cout << "In-order: ";
    Node* stack[100];
    int top = -1;
    Node* curr = root;
    // Iterative in-order also touches each node once: O(n)
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

    return 0;
}


/*OUTPUT
Level Order: 1 2 3 
In-order: 2 1 3
*/