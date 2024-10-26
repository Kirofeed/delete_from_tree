#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    node* left = nullptr;
    node* right = nullptr;
    int value;
    public:
        node(int value) : value(value) {}
};




class Tree {
    private:
        node* root;
        void printing(node* nodie, ostream& os);
    public:
        void insert_node (int val);
        void delete_node (int val);
        void print_tree (ostream& os);
        Tree() : root(0) {};
};

// 1 3 5 8 6
void Tree::insert_node (int val) {
    node** cur = &root;                                              //1
    while (*cur != nullptr) {                                               //
        node& nodie = **cur;                                                       //
        if (val > nodie.value) {                                             //
            cur = &nodie.right; 
            continue;                                            //
        }                                                                   //
        if (val < nodie.value) {
            cur = &nodie.left;
            continue;
        }
        return;
    }
    (*cur) = new node(val);
}

void Tree::delete_node(int val) {
    node** cur = &root;
    
    while (*cur != nullptr && (*cur)->value != val) {
        if (val < (*cur)->value) {
            cur = &((*cur)->left);
        } else {
            cur = &((*cur)->right);
        }
    }
    
    if (*cur == nullptr) {
        return;
    }

    node* del = *cur;

    if (del->left == nullptr && del->right == nullptr) {
        *cur = nullptr;
        delete del;
    }
    else if (del->left == nullptr) {
        *cur = del->right;
        delete del;
    }
    else if (del->right == nullptr) {
        *cur = del->left;
        delete del;
    }
    else {
        node** r = &(del->right);
        node* min_parent = del;
        
        while ((*r)->left != nullptr) {
            min_parent = *r;
            r = &((*r)->left);
        }
        
        del->value = (*r)->value;

        node* temp = *r;
        if (min_parent->left == *r) {
            min_parent->left = (*r)->right;
        } else {
            min_parent->right = (*r)->right;
        }
        delete temp;
    }
}


void Tree::printing(node* nodie, ostream& os) {
    if (nodie == nullptr) {
        return;
    }
    os << nodie->value << endl;
    printing(nodie->left, os);
    printing(nodie->right, os);
    return;
}

void Tree::print_tree (ostream& os) {
    printing(this->root, os);
}


int main () {
    int val;
    int del;
    ifstream in("input.txt");
    in >> del;
    Tree tree;
    while (in >> val) {
        tree.insert_node(val);
    }
    in.close();
    tree.delete_node(del);
    ofstream out("output.txt");
    tree.print_tree(out);
    out.close();
    return 0;
}