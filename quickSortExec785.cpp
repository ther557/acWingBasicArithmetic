// acwing第785题 快速排序

#include <iostream>

using namespace std;

const int N = 100000;

int n;
int q[N];

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
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&q[i]);
    }
    quickSort(q,0,n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",q[i]);
    }
    
    return 0;
    
}
