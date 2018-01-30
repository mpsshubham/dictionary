#ifndef AVL_H
#define AVL_H
#include<iostream>
using namespace std;

class avlnode
{
public:
	string word;
	string meaning;
    avlnode *left;
    avlnode *right;
    int height;
};


int avlheight(avlnode *n);
avlnode* avlnewnode(string w,string m);
avlnode* avlrightrotate(avlnode *y);
avlnode* avlleftrotate(avlnode *x);
int avlgetbalance(avlnode *n);
avlnode* avlinsert(avlnode *node,string w,string m);
avlnode* avlsearch(avlnode *node,string w);
void avlpreorder(avlnode *root);

#endif // AVL_H
