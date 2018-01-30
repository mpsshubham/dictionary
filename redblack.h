#ifndef REDBLACK_H
#define REDBLACK_H
#include<iostream>
using namespace std;

class redblacknode
{
public:
	string word;
	string meaning;
	redblacknode *left,*right,*parent;
	char color;
};

redblacknode* redblacknewnode(string w,string m);
void redblackrightrotate(redblacknode **root,redblacknode *node,int flag);
void redblackleftrotate(redblacknode **root,redblacknode *node,int flag);
void redblackinsertutil(redblacknode **root,redblacknode *z);
void redblackinsert(redblacknode **root,string w,string m);
void redblackpreorder(redblacknode *root);
redblacknode* redblacksearch(redblacknode *root,string w);

#endif