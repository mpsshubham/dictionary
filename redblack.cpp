#include<iostream>
#include "redblack.h"
using namespace std;

redblacknode* newnode(string w,string m)
{
	redblacknode *temp=new redblacknode;
	temp->word=w;
	temp->meaning=m;
	temp->left=temp->right=temp->parent=NULL;
	return temp;
}

void redblackrightrotate(redblacknode **root,redblacknode *node,int flag)
{
	redblacknode *temp=node->left;
	node->left=temp->right;
	if(temp->right)
		temp->right->parent=node;
	temp->parent=node->parent;
	if(temp->parent==NULL)
		*root=temp;
	else if(node->parent->left==node)
		node->parent->left=temp;
	else
		node->parent->right=temp;
	temp->right=node;
	node->parent=temp;
	if(flag)
	{
		temp->color='B';
		node->color='R';
	}
}

void redblackleftrotate(redblacknode **root,redblacknode *node,int flag)
{
	redblacknode *temp=node->right;
	node->right=temp->left;
	temp->parent=node->parent;
	if(temp->left)
		temp->left->parent=node;
	if(node->parent==NULL)
		(*root)=temp;
	else if(node->parent->left==node)
		node->parent->left=temp;
	else
		node->parent->right=temp;
	temp->left=node;
	node->parent=temp;
	if(flag)
	{
		temp->color='B';
		node->color='R';
	}
}

void redblackinsertutil(redblacknode **root,redblacknode *z)
{
	while(z!=(*root) && z->parent->color=='R')
	{
		redblacknode *y=NULL;
		if(z->parent==z->parent->parent->left)
			y=z->parent->parent->right;
		else
			y=z->parent->parent->left;
		
		if(y && y->color=='R')
		{
			y->color='B';
			z->parent->color='B';
			z->parent->parent->color='R';
			z=z->parent->parent;
		}
		else
		{
			if(z->parent==z->parent->parent->left && z==z->parent->left)
				redblackrightrotate(root,z->parent->parent,1);
			else if(z->parent==z->parent->parent->left && z==z->parent->right)
			{
				redblackleftrotate(root,z->parent,0);
				redblackrightrotate(root,z->parent,1);
			}
			else if(z->parent==z->parent->parent->right && z==z->parent->right)
				redblackleftrotate(root,z->parent,1);
			else if(z->parent==z->parent->parent->right && z==z->parent->left)
			{
				redblackrightrotate(root,z->parent,0);
				redblackleftrotate(root,z->parent,1);
			}
		}
	}
	(*root)->color='B';
}

void redblackinsert(redblacknode **root,string w,string m)
{
	redblacknode *temp=newnode(w,m),*pre,*trace;
	if(*root==NULL)
	{
		temp->color='B';
		*root=temp;
		return ;
	}
	temp->color='R';
	pre=NULL;
	trace=*root;
	while(trace)
	{
		pre=trace;
		if(trace->word > w)
			trace=trace->left;
		else
			trace=trace->right;
	}
	if(pre->word > w)
		pre->left=temp;
	else
		pre->right=temp;
	temp->parent=pre;
	redblackinsertutil(root,temp);
}

void redblackpreorder(redblacknode *root)
{
	if(root==NULL)
		return;
	cout<<root->word<<" "<<root->meaning<<endl;
	redblackpreorder(root->left);
	redblackpreorder(root->right);
}

redblacknode* redblacksearch(redblacknode *root,string w)
{
	if(root==NULL)
		return NULL;
	if(root->word==w)
		return root;
	else if(root->word > w)
		return redblacksearch(root->left,w);
	else
		return redblacksearch(root->right,w);
}