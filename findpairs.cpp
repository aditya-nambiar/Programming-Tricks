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
#include <set>
using namespace std;
typedef pair<int,int> ii;
const int MAXINT = 1000000000;

void findpairs(int ar[],int N,int c)
{
    for(int i=0,j=N-1;i<j;)
    {
            //Move the j-pointer to the left till the sum <=c
        if(ar[i]+ar[j]>c)
        {
            j--;
            continue;
        }
        if(ar[i]+ar[j]==c)printf("%d %d\n",ar[i],ar[j]);
        do{
        i++;
        }while(i<j && ar[i]==ar[i-1]);
    }
}

int main(){
    
    int arr[6] = {1,3, 2, 2, 3,2};
    sort(arr,arr+6);
    findpairs(arr, 5, 4);
}
///////////////////////
void findtriplets(int ar[],int N)
{
  //First sort the array since the method works only for sorted arrays
  sort(ar,ar+N);

  //Loop over first element of triplet
  for(int i=0;i<N;i++)
  {
    //Discard repetitions for first element
    if((i>0)&&(ar[i]==ar[i-1]))continue;

    //This loop is essentially the same as findpairs() above.
    for(int j=i+1,k=N-1;j<k;)
    {
      if(ar[i]+ar[j]+ar[k]>0)
      {
        k--;
        continue;
      }
      if(ar[i]+ar[j]+ar[k]==0)
      {
        printf("%d %d %d\n",ar[i],ar[j],ar[k]);
      }
      do
      {
        j++;
      }while((j<k)&&(ar[j]==ar[j-1]));
    }
  }
}


