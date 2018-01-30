#include<iostream>
#include<fstream>
#include<time.h>
#include<string.h>
#include "avl.h"
#include "trie.h"
#include "splay.h"
#include "redblack.h"
using namespace std;

int main()
{
    cout<<"\t\tDICTIONARY IMPLEMENTATION"<<endl<<endl;
	cout<<"TOTAL TIME FOR CREATING DICTIONARY"<<endl<<endl;
	string str;
	ifstream f;
    char buff[1000],*k,*m;
	string word;
	int cnt=0;
    avlnode *avlroot=NULL;
    f.open("words2.txt");
	clock_t begin_time = clock();
    if(!f)
    {
        cout<<"FILE OPEN FAILED"<<endl;
        return 1; //terminate main with error status
    }
    while(!f.eof())
    {
        f.getline(buff,sizeof(buff));
        k=strtok(buff,"\t");
        m=strtok(NULL,"\n");
        avlroot=avlinsert(avlroot,k,m);
		cnt++;
    }
	cout<<"AVL TREE      : "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
	//avlpreorder(avlroot);
	f.close();

	cnt=0;
	f.open("words2.txt");
	begin_time=clock();
	trienode *trieroot=triegetnode();
	if(!f)
	{
		cout<<"FILE OPEN FAILED"<<endl;
		return 1;
	}
	while(!f.eof())
	{
		f.getline(buff,sizeof(buff));
		k=strtok(buff,"\t");
		m=strtok(NULL,"\n");
		trieinsert(trieroot,k,m);
		cnt++;
	}
	cout<<"TRIE          : "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
	f.close();
	
	cnt=0;
	f.open("words2.txt");
	begin_time=clock();
	splaynode *splayroot=NULL;
	if(!f)
	{
		cout<<"FILE OPEN FAILED"<<endl;
		return 1;
	}
	while(!f.eof())
	{
		f.getline(buff,sizeof(buff));
		k=strtok(buff,"\t");
		m=strtok(NULL,"\n");
		splayroot=splayinsert(splayroot,k,m);
		cnt++;
	}
	cout<<"SPLAY TREE    : "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
	//splaypreorder(splayroot);
	f.close();
	
	cnt=0;
	f.open("words2.txt");
	begin_time=clock();
	redblacknode *redblackroot=NULL;
	if(!f)
	{
		cout<<"FILE OPEN FAILED"<<endl;
		return 1;
	}
	while(!f.eof())
	{
		f.getline(buff,sizeof(buff));
		k=strtok(buff,"\t");
		m=strtok(NULL,"\n");
		redblackinsert(&redblackroot,k,m);
		cnt++;
	}
	cout<<"REDBLACK TREE : "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl<<endl;
	//redblackpreorder(redblackroot);
	f.close();
	
	cout<<"AVERAGE SEARCH TIME FOR 5048 ENTRIES "<<endl<<endl;
	
	f.open("words2.txt");
	avlnode *avlroot1;
	begin_time = clock();
    if(!f)
    {
        cout<<"FILE OPEN FAILED";
        return 1; //terminate main with error status
    }
    while(!f.eof())
    {
        f.getline(buff,sizeof(buff));
        k=strtok(buff,"\t");
        m=strtok(NULL,"\n");
        avlroot1=avlsearch(avlroot,k);
    }
	cout<<"AVL TREE      : "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
	f.close();
	
	f.open("words2.txt");
	begin_time = clock();
	if(!f)
	{
		cout<<"FILE OPEN FAILED"<<endl;
		return 1;
	}
	while(!f.eof())
	{
		f.getline(buff,sizeof(buff));
		k=strtok(buff,"\t");
		m=strtok(NULL,"\n");
		str=triesearch(trieroot,k);
	}
	cout<<"TRIE          : "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
	f.close();
	
	f.open("words2.txt");
	begin_time = clock();
	if(!f)
	{
		cout<<"FILE OPEN FAILED"<<endl;
		return 1;
	}
	while(!f.eof())
	{
		f.getline(buff,sizeof(buff));
		k=strtok(buff,"\t");
		m=strtok(NULL,"\n");
		splayroot=splaysearch(splayroot,k);
	}
	cout<<"SPLAY TREE    : "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
	f.close();
	
	f.open("words2.txt");
	begin_time=clock();
	redblacknode *redblackroot1;
	if(!f)
	{
		cout<<"FILE OPEN FAILED"<<endl;
		return 1;
	}
	while(!f.eof())
	{
		f.getline(buff,sizeof(buff));
		k=strtok(buff,"\t");
		m=strtok(NULL,"\n");
		redblackroot1=redblacksearch(redblackroot,k);
		//cout<<endl<<redblackroot1->word<<" "<<redblackroot1->meaning<<endl;
	}
	cout<<"REDBLACK TREE : "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl<<endl;
	//redblackpreorder(redblackroot);
	f.close();
	
	
	cout<<"ENTER WORD TO SEARCH "<<endl;
	cin>>word;
	
	avlroot1=avlsearch(avlroot,word);
	cout<<"AVL TREE      : ";
	if(avlroot1==NULL)
		cout<<word<<" not found"<<endl;
	else
		cout<<avlroot1->word<<" "<<avlroot1->meaning<<endl;
	
	str=triesearch(trieroot,word);
	cout<<"TRIE          : ";
	cout<<word<<" "<<str<<endl;
	
	splayroot=splaysearch(splayroot,word);
	cout<<"SPLAY TREE    : ";
	cout<<splayroot->word<<" "<<splayroot->meaning<<endl;
	
	redblackroot1=redblacksearch(redblackroot,word);
	cout<<"REDBLACK TREE : ";
	if(redblackroot1==NULL)
		cout<<word<<" not found"<<endl;
	else
		cout<<redblackroot1->word<<" "<<redblackroot1->meaning<<endl;
	
	return 0;
}
