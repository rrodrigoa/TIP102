// Unit6_Session2_BinaryTrees_Pt2.cpp : Defines the entry point for the application.
//

#include <stack>
#include "Unit6_Session2_BinaryTrees_Pt2.h"

int indent_level = 0;

// The node tree structure for the binary tree
struct TreeNode {
    int value;
    TreeNode* leftNode;
    TreeNode* rightNode;

    TreeNode(int _value, TreeNode* _left, TreeNode* _right)
        : value(_value), leftNode(_left), rightNode(_right) {}
};

// Adds operator << for struct TreeNode so its value can be printed to output
std::ostream& operator<<(std::ostream& os, const TreeNode& node) {
    os << node.value;
    return os;
}

// Creates a Happy Case Tree as seen on slides
//        1
//      /   \
//     2     3
//    /   \
//   4     5
struct TreeNode* happy_case_tree() {
    TreeNode* node4 = new TreeNode(4, nullptr, nullptr);
    TreeNode* node5 = new TreeNode(5, nullptr, nullptr);
    TreeNode* node3 = new TreeNode(3, nullptr, nullptr);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node1 = new TreeNode(1, node2, node3);

    return node1;
}

// Creates an empty tree with nullptr as root
//      nullptr
TreeNode* empty_tree() {
    return nullptr;
}

// Creates a single node tree
//      1
TreeNode* single_node_tree() {
    TreeNode* node1 = new TreeNode(1, nullptr, nullptr);
    return node1;
}

// Print PreOrder of a Tree using recursion
void PrintPreOrder(TreeNode* root) {
    INDENT_MORE();

    if (root == nullptr) {
        DEBUG_MSG("nullptr");
        INDENT_LESS();

        return;
    }

    std::cout << root->value << std::endl;
    DEBUG_VAR(root->value);

    PrintPreOrder(root->leftNode);
    PrintPreOrder(root->rightNode);

    INDENT_LESS();
}

// Print PreOrder of a Tree using a stack
void PrintPreOrderStack(TreeNode* root) {
    std::stack<TreeNode*> stack;
    stack.push(root);

    while (stack.empty() == false) {
        TreeNode* top = stack.top();
        stack.pop();

        if (top == nullptr) {
            continue;
        }

        std::cout << top->value << " " << std::endl;
        stack.push(top->rightNode);
        stack.push(top->leftNode);
    }
}

int main()
{
    TreeNode* root = happy_case_tree();

    PrintPreOrder(root);

    PrintPreOrderStack(root);

    return 0;
}
