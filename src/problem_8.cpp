#include <iostream>
#include <vector>

enum Color { RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node *root;

    void leftRotate(Node *x) {
    }

    void rightRotate(Node *y) {
    }

    void insertFixup(Node *z) {
    }

    void deleteFix(Node *x) {
    }

    Node *treeMinimum(Node *node) {
    }

    void transplant(Node *u, Node *v) {
    }

    void deleteNode(Node *z) {
    }

    void inorderTraversal(Node *node, std::vector<int> &values) {
        if (node != nullptr) {
            inorderTraversal(node->left, values);
            values.push_back(node->data);
            inorderTraversal(node->right, values);
        }
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value) {
    }

    void median() {
        std::vector<int> values;
        inorderTraversal(root, values);

        int size = values.size();
        if (size % 2 == 0) {
            int mid1 = values[size / 2 - 1];
            int mid2 = values[size / 2];
            std::cout << "Median: " << mid1 << " and " << mid2 << "\n";
        } else {
            int mid = values[size / 2];
            std::cout << "Median: " << mid << "\n";
        }
    }
};

int main() {
    int N;
    std::cin >> N;

    RedBlackTree tree;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        tree.insert(value);
    }

    tree.median();

    return 0;
}