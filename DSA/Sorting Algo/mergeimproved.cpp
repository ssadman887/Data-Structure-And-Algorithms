#include<bits/stdc++.h>
using namespace std;


//for dividing and merging the arrays to sort them....this one is more flexible for comparators

void divide_and_merge(int arr[], int start, int mid, int end){
    
    int nL,nR;

    nL = mid - start + 1;
    nR = end - mid ;

    int leftArr[nL];
    int rightArr[nR];

    for(int i=0;i<nL;i++){
        leftArr[i]=arr[start + i];
    }

    for(int j=0;j<nR;j++){
        rightArr[j]=arr[mid + 1 + j];
    }

    int i,j,k;

    i = 0;
    j = 0;
    k = start;

    while(i<nL && j<nR){

        if(leftArr[i]<rightArr[j]){
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        else if(leftArr[i]>=rightArr[j]){
            arr[k] = rightArr[j];
            j++;
            k++;
        }

    }

    while(i<nL){
        arr[k] = leftArr[i];
        i++;
        k++;
        
    }

    while(j<nR){
        arr[k] = rightArr[j];
        j++;
        k++;
        
    }

    
}

void merge_sort(int arr[], int start, int end){

    if(start < end){   //base case

        int mid = start + (end - start)/2;

        merge_sort(arr,start, mid);
        merge_sort(arr,mid + 1,end);
        divide_and_merge(arr,start,mid,end);

    }

    //Time Complexity- O(nlog(n))
    //Space Complexity- O(n)
}





void view_output(int a[], int n){
    int i;

    for(i=0;i<n;i++)printf("%d ",a[i]);

    cout<<endl;
    return;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i;
    //scanf("%d",&n);

    cin>>n;

    int arr[n];

    for(i=0;i<n;i++){
        //scanf("%d",&arr[i]);

        cin>>arr[i];
    }

    
    merge_sort(arr,0,n-1);          //officially the fastest sorting algorithm
    

    view_output(arr,n);

    return 0;
}