#include <iostream>
using namespace std;

const int N = 100000;

void quickSort(int q[],int l,int r){

    if(l >= r) return;
    int x = q[(l + r) / 2],i = l - 1,j = r + 1;
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i],q[j]);
    }

    quickSort(q,l,j);
    quickSort(q,j + 1,r);
}

int main(int argc, char const *argv[])
{
    int n,index;
    int q[N];
    scanf("%d %d",&n,&index);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&q[i]);
    }
    quickSort(q,0,n-1);
    printf("%d",q[index - 1]);
    return 0;
}
