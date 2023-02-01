#include<bits/stdc++.h>
using namespace std;


void swap_array(int *a , int *b){
    int temp=*a;
    *a = *b;
    *b = temp;

    return;
}

//Haore's Partition
int partition(int arr[], int low ,int high){

    // Link - GeeksForGeeks
    
    int i=low-1,j=high+1; //check
    int pivot = arr[low];
    
    while(true){

        do{             //finds the index whose value is greater than or equal to the pivot
            i++;
        }while(arr[i]<pivot);

        do{             //finds the index whose value in less than or equal to the pivot /////check...other conditions create errors
            j--;
        }while(arr[j]>pivot);

        if(i>=j) {
            return j;
        }

        swap_array(&arr[i],&arr[j]);
        
/*
        int temp =arr[i];
        arr[i] = arr[j];
        arr[j] = temp; */
    }
    

}

void quick_sort(int arr[], int lower_bound, int upper_bound){
    
    if(lower_bound < upper_bound){
        int pivot = partition(arr,lower_bound,upper_bound);
        quick_sort(arr,lower_bound,pivot); //check
        quick_sort(arr,pivot+1,upper_bound); 
    }

    return;

    /* Time complexity : Average Case : O(nlog(n))
                         Worst Case   : O(n^2)

      Space Complexity : Worst Case   : O(n)
    */
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
    scanf("%d",&n);

    int arr[n];

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    
    quick_sort(arr,0,n-1);      /* usually the fastest sorting algorithm at average case....most in-built sort fuctions are 
                                     //implementation of quick sort algo..  */
    

    //sort(arr,arr+n);

    view_output(arr,n);

    return 0;
}