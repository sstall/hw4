//Binary Tree
//Samuel Stall
//Data Structures and Algorithms
//hw4

#ifndef BinaryTree_H
#define BinaryTree_H
#include <stdexcept>
#include <iostream>

namespace cop3530 {

template <typename E>
class BinaryTree {
public:
     BinaryTree();
     ~BinaryTree();

     void add_node(E element);
     void print_prefix(std::ostream &O);
     void print_infix(std::ostream &O);
     void print_postfix(std::ostream &O);
     void morris_prefix(std::ostream &O);
     void morris_infix(std::ostream &O);

private:
     struct node {
          E value;
          node* left = nullptr;
          node* right = nullptr;
     };

     node* root;
     void delete_tree(node*curr);
     void T_add_node(E element, node* curr);
     node* T_iop(node* curr);
     void T_print_prefix(std::ostream &O, node* curr);
     void T_print_infix(std::ostream &O, node* curr);
     void T_print_postfix(std::ostream &O, node* curr);
};

template <typename E>
BinaryTree<E>::BinaryTree() {
     root = nullptr;
}

template <typename E>
BinaryTree<E>::~BinaryTree() {
     delete_tree(root);
}

template <typename E>
void BinaryTree<E>::delete_tree(node* curr) {
     if(curr->left) delete_tree(curr->left);
     if(curr->right) delete_tree(curr->right);
     delete curr;
}

template <typename E>
void BinaryTree<E>::add_node(E element) {

     if(!root) {
          root = new node;
          root->value = element;
     }
     else {
          T_add_node(element, root);
     }
}

template <typename E>
void BinaryTree<E>::T_add_node(E element, node* curr) {

     if(element > curr->value) {
          if(curr->right) {
               T_add_node(element, curr->right);
          }
          else {
               curr->right = new node;
               curr->right->value = element;
          }
     }
     else if(element < curr->value) {
          if(curr->left) {
               T_add_node(element, curr->left);
          }
          else {
               curr->left = new node;
               curr->left->value = element;
          }
     }
     else {
          std::cout << element << " already in tree\n";
     }
}

template <typename E>
void BinaryTree<E>::print_prefix(std::ostream &O) {

     O << "Print prefix recursively:  ";

     if(!root) {
          O << "Empty Tree";
     }
     else {
          T_print_prefix(O, root);
     }

     O << "\n";
}

template <typename E>
void BinaryTree<E>::T_print_prefix(std::ostream &O, node* curr) {

     O << curr->value << " ";
     if(curr->left) {
          T_print_prefix(O, curr->left);
     }
     if(curr->right) {
          T_print_prefix(O, curr->right);
     }
}

template <typename E>
void BinaryTree<E>::print_infix(std::ostream &O) {

     O << "Print infix recursively:   ";

     if(!root) {
          O << "Empty Tree";
     }
     else {
          T_print_infix(O, root);
     }

     O << "\n";
}

template <typename E>
void BinaryTree<E>::T_print_infix(std::ostream &O, node* curr) {\

     if(curr->left) {
          T_print_infix(O, curr->left);
     }
     O << curr->value << " ";
     if(curr->right) {
          T_print_infix(O, curr->right);
     }
}

template <typename E>
void BinaryTree<E>::print_postfix(std::ostream &O) {

     O << "Print postfix recursively: ";

     if(!root) {
          O << "Empty Tree";
     }
     else {
          T_print_postfix(O, root);
     }

     O << "\n";
}

template <typename E>
void BinaryTree<E>::T_print_postfix(std::ostream &O, node* curr) {

     if(curr->left) {
          T_print_postfix(O, curr->left);
     }
     if(curr->right) {
          T_print_postfix(O, curr->right);
     }
     O << curr->value << " ";
}

template <typename E>
void BinaryTree<E>::morris_prefix(std::ostream &O) {

     O << "Morris's Solution prefix:  ";

     node* anchor = root;
     while(anchor) {
          if(!anchor->left) {
               O << anchor->value << " ";
               anchor = anchor->right;
          }
          else {
               node* curr = anchor->left;
               //Find in order predeccesor
               while(curr->right && curr->right != anchor) {
                    curr = curr->right;
               }

               if(curr->right == anchor) {
                    curr->right = nullptr;
                    anchor = anchor->right;
               }
               else {
                    O << anchor->value << " ";
                    curr->right = anchor;
                    anchor = anchor->left;
               }
          }
     }

     O << "\n";
}

template <typename E>
void BinaryTree<E>::morris_infix(std::ostream &O) {

     O << "Morris's Solution infix:   ";

     node* anchor = root;
     while(anchor) {
          if(!anchor->left) {
               O << anchor->value << " ";
               anchor = anchor->right;
          }
          else {
               node* curr = anchor->left;
               //Find in order predeccesor
               while(curr->right && curr->right != anchor) {
                    curr = curr->right;
               }

               if(curr->right == anchor) {
                    curr->right = nullptr;
                    O << anchor->value << " ";
                    anchor = anchor->right;
               }
               else {
                    curr->right = anchor;
                    anchor = anchor->left;
               }
          }
     }

     O << "\n";
}



}

#endif
