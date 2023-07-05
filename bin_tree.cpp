#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include  <cstdio>

using namespace std;

struct bin_tree {
    int info;
    bin_tree* left = NULL;
    bin_tree* right = NULL;
    bin_tree* pred = NULL;
};

void init(bin_tree* root) {
    root -> left = NULL;
    root -> right = NULL;
    root -> pred = NULL;
    cout << "scanf data:\n";
    int data;
    cin >> data;
    root -> info = data;
}

void insert_tree(bin_tree* Node, int data) {
    if (Node -> info > data) {
        if (Node -> left != NULL) {
            insert_tree(Node -> left, data);
        }
        else {
            bin_tree* Node_left = new bin_tree;
            Node -> left = Node_left;
            Node_left -> pred = Node;
            Node_left -> info = data;
        }
    }
    else if (Node -> info < data)
        if (Node -> right != NULL) {
            insert_tree(Node -> right, data);
        }
        else {
            bin_tree* Node_right = new bin_tree;
            Node -> right = Node_right;
            Node_right -> pred = Node;
            Node_right -> info = data;
        }
}

void show(bin_tree* Node, int level) {
    if (Node -> left != NULL)
        show(Node -> left, level + 1);
    for (int i = 0; i < level; ++i) {
        cout << "     ";
    }
    cout << Node -> info << "\n";
    if (Node -> right != NULL)
        show(Node -> right, level + 1);
}

void dfs(bin_tree* Node, bool &flag, int data) {
    if (Node -> info == data)
        flag = true;
    if (Node -> info < data) {
        if (Node -> left != NULL && flag == false)
            dfs(Node -> left, flag, data);
    }
    if (Node -> info > data) {
        if (Node -> right != NULL && flag == false)
            dfs(Node -> right, flag, data);
    }
}

int main() {
    bin_tree* root = new bin_tree;
    root -> info = 10;
    insert_tree(root, 5);
    insert_tree(root, 8);
    insert_tree(root, 6);
    insert_tree(root, 7);
    insert_tree(root, 5);
    insert_tree(root, 4);
    insert_tree(root, 3);
    insert_tree(root, 2);
    insert_tree(root, 1);
    insert_tree(root, 9);
    show(root, 0);
}