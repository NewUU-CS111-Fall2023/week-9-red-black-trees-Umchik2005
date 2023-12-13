#include <iostream>
#include <vector>
#include <map>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
private:
    Node *root;

    int countSubtreeNodes(Node *node, std::map<Node*, int>& subtreeNodeCount) {
        if (!node) return 0;

        int leftCount = countSubtreeNodes(node->left, subtreeNodeCount);
        int rightCount = countSubtreeNodes(node->right, subtreeNodeCount);
        int totalCount = leftCount + rightCount + 1;

        subtreeNodeCount[node] = totalCount;
        return totalCount;
    }

public:
    RBTree() : root(nullptr) {}

    void insert(const int &data) {

    }

    std::map<Node*, int> countSubtreeNodes() {
        std::map<Node*, int> subtreeNodeCount;
        countSubtreeNodes(root, subtreeNodeCount);
        return subtreeNodeCount;
    }

    void printSubtreeNodeCounts() {
        auto subtreeNodeCount = countSubtreeNodes();
        for (const auto &entry : subtreeNodeCount) {
            std::cout << entry.first->data << " - " << entry.second << std::endl;
        }
    }
};

int main() {
    RBTree tree;
    tree.printSubtreeNodeCounts();

    return 0;
}