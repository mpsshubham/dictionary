#include<iostream>
#include<string.h>
#include<map>
using namespace std;
#include "trie.h"

trienode* triegetnode()
{
	trienode *p=NULL;
	p=new trienode;
	if(p)
		p->isleaf=false;
	return p;
}

void trieinsert(trienode *root,string key,string meaning)
{
	trienode *p=root;
	map<char,trienode*>::iterator it;
	int level;
	int length=key.length();
	for(level=0;level<length;level++)
	{
		char ch=key[level];
		it=p->children.find(ch);
		trienode *node=NULL;
		if(it!=p->children.end())
			node=it->second;
		else
		{
			node=triegetnode();
			p->children.insert(pair<char,trienode*>(ch,node));
		}
		p=node;
	}
	p->isleaf=true;
	p->meaning=meaning;
}

string triesearch(trienode *root,string key)
{
	int level;
	int length=key.length();
	trienode *p=root;
	map<char,trienode*>::iterator it;
	for(level=0;level<length;level++)
	{
		char ch=key[level];
		it=p->children.find(ch);
		trienode *node=NULL;
		if(it!=p->children.end())
		{
			p=it->second;
			continue;
		}
		else
			return "not found";
	}
	if(p!=NULL && p->isleaf)
		return p->meaning;
	else
		return "not found";
}