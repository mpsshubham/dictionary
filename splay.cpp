#include<iostream>
#include "splay.h"
using namespace std;

splaynode* splaynewnode(string w,string m)
{
	splaynode* node=new splaynode;
	node->word=w;
	node->meaning=m;
	node->left=node->right=NULL;
	return node;
}

splaynode* splayrightrotate(splaynode *x)
{
	splaynode *y=x->left;
	x->left=y->right;
	y->right=x;
	return y;
}

splaynode* splayleftrotate(splaynode *x)
{
	splaynode *y=x->right;
	x->right=y->left;
	y->left=x;
	return y;
}

splaynode* splay(splaynode *root,string w)
{
	if(root==NULL || root->word==w)
		return root;
	
	if(root->word > w)
	{
		if(root->left==NULL)
			return root;
		
		if(root->left->word > w)
		{
			root->left->left=splay(root->left->left,w);
			root=splayrightrotate(root);
		}
		else if(root->left->word < w)
		{
			root->left->right=splay(root->left->right,w);
			if(root->left->right!=NULL)
				root->left=splayleftrotate(root->left);
		}
		return (root->left==NULL)? root : splayrightrotate(root);
	}
	
	else
	{
		if(root->right==NULL)
			return root;
		
		if(root->right->word > w)
		{
			root->right->left=splay(root->right->left,w);
			if(root->right->left != NULL)
				root->right=splayrightrotate(root->right);
		}
		
		else if(root->right->word < w)
		{
			root->right->right=splay(root->right->right,w);
			root=splayleftrotate(root);
		}
		return (root->right==NULL)? root:splayleftrotate(root);
	}	
}

splaynode* splayinsert(splaynode *root,string w,string m)
{
	if(root==NULL)
		return splaynewnode(w,m);
	root=splay(root,w);
	if(root->word==w)
		return root;
	
	splaynode *newnode=splaynewnode(w,m);
	if(root->word > w)
	{
		newnode->right=root;
		newnode->left=root->left;
		root->left=NULL;
	}
	else
	{
		newnode->left=root;
		newnode->right=root->right;
		root->right=NULL;
	}
	return newnode;	
}

splaynode* splaysearch(splaynode *root,string w)
{
	return splay(root,w);
}

void splaypreorder(splaynode *root)
{
	if(root!=NULL)
	{
		cout<<root->word<<" "<<root->meaning<<endl;
		splaypreorder(root->left);
		splaypreorder(root->right);
	}
}