//Test Tree
//Samuel Stall

#include "BinaryTree.h"

using namespace cop3530;

int main() {
     BinaryTree<int> Tree = BinaryTree<int>();

     Tree.add_node(5);

     Tree.add_node(4);

     Tree.add_node(1);

     Tree.add_node(3);

     Tree.add_node(2);

     Tree.add_node(7);

     Tree.add_node(6);
     Tree.add_node(9);
     Tree.add_node(8);

     Tree.print_infix(std::cout);
     Tree.morris_infix(std::cout);

     Tree.print_postfix(std::cout);

     Tree.print_prefix(std::cout);

     Tree.morris_prefix(std::cout);

     BinaryTree<int> Tree1 = BinaryTree<int>();

     for(unsigned int i = 14; i < 20; i++) {
          Tree1.add_node(i);
     }

     for(unsigned int i = 1; i < 14; i++) {
          Tree1.add_node(i);
     }

     Tree1.print_infix(std::cout);
     Tree1.morris_infix(std::cout);

     Tree1.print_prefix(std::cout);
     Tree1.morris_prefix(std::cout);

     BinaryTree<char> TreeC = BinaryTree<char>();

     TreeC.add_node('D');
     TreeC.add_node('B');
     TreeC.add_node('C');
     TreeC.add_node('A');
     TreeC.add_node('G');
     TreeC.add_node('E');
     TreeC.add_node('F');
     TreeC.add_node('J');

     TreeC.print_infix(std::cout);
     TreeC.morris_infix(std::cout);




     return 0;
}
