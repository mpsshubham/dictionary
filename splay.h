#ifndef SPLAY_H
#define SPLAY_H
#include<iostream>
using namespace std;

class splaynode
{
public:
	string word;
	splaynode *left;
	splaynode *right;
	string meaning;
};

splaynode* splaynewnode(string w,string m);
splaynode* splayrightrotate(splaynode *x);
splaynode* splayleftrotate(splaynode *x);
splaynode* splayinsert(splaynode *root,string w,string m);
splaynode* splay(splaynode *root,string w);
splaynode* splaysearch(splaynode *root,string w);
void splaypreorder(splaynode *root);

#endif