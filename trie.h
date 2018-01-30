#ifndef TRIE_H
#define TRIE_H
#include<map>
#include<iostream>
using namespace std;

class trienode
{
public:
	map<char,trienode*> children;
	bool isleaf;
	string meaning;
};

trienode* triegetnode();
void trieinsert(trienode *root,string key,string meaning);
string triesearch(trienode *root,string key);

#endif