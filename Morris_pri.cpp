#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void morrisPreorder(Node* root) {
    Node* current = root;

    while (current != nullptr) {

        if (current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
            Node* predecessor = current->left;

            while (predecessor->right != nullptr &&
                   predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                cout << current->data << " ";

                predecessor->right = current;
                current = current->left;
            }
            else {
                predecessor->right = nullptr;
                current = current->right;
            }
        }
    }
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Morris Preorder Traversal: ";

    morrisPreorder(root);

    return 0;
}
