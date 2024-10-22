#include <iostream>

using namespace std;

struct node
{
    node* left;
    node* right;
    int value;
};


class Tree {
    private:
        node* root;
    public:
        void insert_node (int val);
        void delete_node (int val);
        Tree() : root(nullptr) {};
};


// 1 3 5 8 6
void Tree::insert_node (int val) {
    if (this->root == nullptr) {
        root = new node;
        root->value = val;
        return;
    }
    node** cur = &root;                                              //1
    while (*cur != nullptr) {                                                   //
        node& nodie = **cur;                                             //
        if (val > nodie.value) {                                             //
            *cur = nodie.right;                                             //
        }                                                                   //
        else if (val < nodie.value) {
            *cur = nodie.left;
        }
        else {
            return;
        }       
    }
    (*cur)->value = val;
}

int main () {

}