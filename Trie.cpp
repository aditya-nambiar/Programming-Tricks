
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;


typedef unsigned int UI;
struct Trie {
    Trie * child[2];
    short mask;
    bool val;
    
Trie() {
    mask =-1;
    for(int i = 0; i < 2; ++i)
        child[i] = NULL;
}


void addWord(UI add, short pos, short mask) {
    if( pos ==  mask) {
        this->mask = mask+1;
        return;
    }
    bool temp =((add & (1<<(31-pos)) )!=0) ;
    Trie *t = child[ temp ];
        //  cout<<(add & (1<<(32-pos)))!=0)<<endl;
    if(t == NULL){ // Did not exist earlier
        t = child[temp] = new Trie();
        t->val = temp;
        t->addWord(add,pos+1,mask);
        
    }
    else{ // Existed earlier
        t->addWord(add,pos+1,mask);
        
    }
    
}

int find(UI f,short pos, short ans){
    
    Trie * t = child[(f & (1<<(31-pos)))!=0];
    if(mask != -1)ans = pos;
    if(t==NULL)return ans;
    else{
        return t->find(f, pos+1, ans);
    }
}
};
