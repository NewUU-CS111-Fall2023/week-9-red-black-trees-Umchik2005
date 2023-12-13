#include <iostream>

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }

        return node;
    }

    void printInOrder(Node* node) {
        if (node != nullptr) {
            printInOrder(node->left);
            std::cout << node->data << " ";
            printInOrder(node->right);
        }
    }

    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return std::max(leftHeight, rightHeight) + 1;
    }

    int getDepth(Node* node, int value, int depth) {
        if (node == nullptr) {
            return -1;
        }

        if (value == node->data) {
            return depth;
        } else if (value < node->data) {
            return getDepth(node->left, value, depth + 1);
        } else {
            return getDepth(node->right, value, depth + 1);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void print() {
        printInOrder(root);
        std::cout << std::endl;
    }

    int height() {
        return getHeight(root);
    }

    int depth(int value) {
        return getDepth(root, value, 0);
    }

    Node* convertToAVL(Node* node) {
        return node;
    }
};

int main() {
    BinarySearchTree bst;

    int N;
    std::cin >> N;

    std::cout << std::endl;
    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        bst.insert(value);
    }

    bst.print();

    std::cout << bst.height() << std::endl;

    int valueToFindDepth;
    std::cin >> valueToFindDepth;
    int depth = bst.depth(valueToFindDepth);
    if (depth != -1) {
        std::cout << valueToFindDepth << ": " << depth << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    bst.print();

    return 0;
}