# dictionary

A C/C++ dictionary implementation (around 5000 entries) to compare insertion and searching time of :

1)  AVL tree
2)  SPLAY tree
3)  RED BLACK tree
4)  TRIE

To run :
download zip and compile makefile by simply typing make or makefile
and then run the executable file


RESULT:

splay tree >>>> red black tree >>>> avl ==== trie  (Insertion Time)

(quick,best)                        (slow,worst)

splay tree >>>> avl ==== trie >>>> red black tree  (Searching Time)


Comparison Between Red Black Tree and AVL Tree

For small data:

insert: RB tree & avl tree has constant number of max rotation but RB tree will be faster because on average RB tree use less rotation.

lookup: AVL tree is faster, because AVL tree has less depth.

for large data:

insert: AVL tree is faster. because you need to lookup for a particular node before insertion. as you have more data the time difference on looking up the particular node grows proportional to O(log N). but AVL tree & RB tree still only need constant number of rotation at the worst case. Thus the bottle neck will become the time you lookup for that particular node.

lookup: AVL tree is faster. (same as in small data case)
