#include<iostream>
using namespace std;
#include "avl.h"

int avlheight(avlnode *n)
{
    if(n==NULL)
        return 0;
    return n->height;
}

avlnode* avlnewnode(string w,string m)
{
    avlnode *node=new avlnode;
    node->word=w;
	node->meaning=m;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return (node);
}

avlnode* avlrightrotate(avlnode *y)
{

    avlnode *x=y->left;
    avlnode *t=x->right;
    x->right=y;
    y->left=t;
    y->height=max(avlheight(y->left),avlheight(y->right))+1;
    x->height=max(avlheight(x->left),avlheight(x->right))+1;
    return x;
}

avlnode* avlleftrotate(avlnode *x)
{
    avlnode *y=x->right;
    avlnode *t=y->left;
    y->left=x;
    x->right=t;
    x->height=max(avlheight(x->left),avlheight(x->right))+1;
    y->height=max(avlheight(y->left),avlheight(y->right))+1;
    return y;
}

int avlgetbalance(avlnode *n)
{
    if(n==NULL)
        return 0;
    return avlheight(n->left)-avlheight(n->right);
}

avlnode* avlinsert(avlnode *node,string w,string m)
{
    if(node==NULL)
        return (avlnewnode(w,m));
    if(w < node->word)
        node->left=avlinsert(node->left,w,m);
    else if(w > node->word)
        node->right=avlinsert(node->right,w,m);
    else
        return node;
    node->height=1+max(avlheight(node->left),avlheight(node->right));
    int bal=avlgetbalance(node);

    if(bal > 1 && w < node->left->word)
        return avlrightrotate(node);

    if(bal < -1 && w > node->right->word)
        return avlleftrotate(node);

    if(bal > 1 && w > node->left->word)
    {
        node->left=avlleftrotate(node->left);
        return avlrightrotate(node);
    }

    if(bal < -1 && w < node->right->word)
    {
        node->right=avlrightrotate(node->right);
        return avlleftrotate(node);
    }
    return node;
}

avlnode* avlsearch(avlnode *node,string w)
{
	if(node==NULL)
		return NULL;
	if(node->word==w)
		return node;
	else if(node->word > w)
		return avlsearch(node->left,w);
	else
		return avlsearch(node->right,w);
}

void avlpreorder(avlnode *root)
{
	if(root!=NULL)
	{
		cout<<root->word<<" "<<root->meaning<<endl;
		avlpreorder(root->left);
		avlpreorder(root->right);
	}
}
