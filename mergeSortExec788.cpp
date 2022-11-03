#include <iostream>

using namespace std;

const int N = 100000;

int q[N],tmp[N];
long long res = 0;

int mergeSort(int q[],int l,int r){
    if(l >= r)return 0;
    int mid = (l + r) / 2;
    res = mergeSort(q,l,mid) + mergeSort(q,mid + 1,r);
    int k = 0,i = l,j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]){
            tmp[k++] = q[i++];
        }else{
            tmp[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    for(int i = l,j = 0;i <= r;i++, j++) q[i] = tmp[j];
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    mergeSort(q,0,n-1);
    cout<<res;
    return 0;
}