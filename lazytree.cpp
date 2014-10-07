#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <deque>
#include <math.h>
#include <string>
#include <queue>
#include <string>
#include <limits.h>
#include <stack>
#include <list>
#include <set>
using namespace std;
vector<long> ans;
typedef pair<set<long> ::iterator, set<long> :: iterator>  ps;
const long maxlong = 1000000000;


vector<long> arr;
vector<long> seg;
vector<long> lazy;
long build( long ss, long se, long si){
    
    if(ss ==se){
        seg[si]=arr[ss];
        return seg[si];
    }
    long mid = (se+ss)/2;
    seg[si]= build(ss,mid,2*si+1)+build(mid+1,se,2*si+2);
    return seg[si];
    
}

void update(long ss, long se, long si, long i, long j, long val){
    
    if(lazy[si]!=0){
        seg[si]+=(lazy[si] * (se-ss+1));
        
        if(ss!=se){//not leaf node
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
       }
        lazy[si]=0;
    }
    
    if(ss>se || ss>j || se<i)return; //out of range
    
    if(i<=ss && j>= se){//segment is fully in range
        
        seg[si] += (val * (se-ss+1));
        if(se!=ss){
        lazy[2*si+1]+=val;
        lazy[2*si+2]+=val;
        }
        return;
    }
    
    if(ss!=se){
        long mid = (se+ss)/2;
        update(ss,mid,2*si+1,i,j,val);
        update(mid+1,se,2*si+2,i,j,val);
        seg[si]= seg[2*si+1]+seg[2*si+2];
        
    }
    else{
        seg[si]+=val;
    }
    
}

long getSum(long ss, long se, long qs, long qe,long si){
    
    if( qs>se || qe<ss)return 0;
    long ans=0;
    
        if(lazy[si]!=0){
            seg[si]+=lazy[si]*(se-ss+1);
            
            if(ss!=se){
                lazy[2*si+1]+=lazy[si];
                lazy[2*si+2]+=lazy[si];
            }
            
            lazy[si]=0;
        }
        
    if(qs <= ss && qe >= se){
        return seg[si];
    }
    
    long a=0,b=0;
        long mid = (ss+se)/2;
        a = getSum(ss,mid,qs,qe,2*si+1);
        b = getSum(mid+1,se,qs,qe,2*si+2);
    return a+b;
    
}
int main(){
    
    long t;
    cin>>t;
    while(t--){
        long N,C;
        cin>>N>>C;
        arr.resize(N);
        
        long f = (long)(ceil(log2(N)));
        long max_size = 2* pow(2,f) -1;
        seg.resize(max_size,0);
        lazy.resize(max_size,0);
        for(long i=0; i<C; i++){
            long a;
            cin>>a;
            if(a==0){//update tree
                long rl,rr,val;
                cin>>rl>>rr>>val;
                update(0,N-1,0,rl-1,rr-1,val);
            }
            else{ //query tree
                long rl,rr;
                cin>>rl>>rr;
                
                cout<<getSum(0, N-1, rl-1, rr-1, 0)<<endl;;
                
                
            }
        }
        
    }
}