#include<bits/stdc++.h>
using namespace std;
  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partition(int arr[], int l, int r, int x) 
{
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 


int findMedian(int arr[], int n) 
{ 
    sort(arr, arr+n);  // Sort the array 
    return arr[n/2];   // Return middle element 
} 
int fmedian(int arr[], int left, int right, int k) 
{ 
    if (k > 0 && k <= right - left + 1) 
    { 
        int n = right-left+1;
        int i, median[(n+4)/5]; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+left+i*5, 5); 
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+left+i*5, n%5);  
            i++; 
        }     
        int medianofmedians = (i == 1)? median[i-1]:fmedian(median, 0, i-1, i/2); 
        int p = partition(arr, left, right, medianofmedians); 
        if (p-left == k-1) 
            return arr[p]; 
        if (p-left > k-1)
            return fmedian(arr, left, p-1, k); 
        return fmedian(arr, p+1, right, k-p+left-1); 
    } 
    return INT_MAX; 
} 
  
int main() 
{

    int q;
    cin>>q;
    while(q--)
    {
        int n,x,y,k,k1;
        cin>>n;
        int d[n];
        for(int i = 0; i<n; i++)
        {
            cin>>x>>y;
            d[i] = x*x + y*y;
        }
        if(n%2==1)
        {
            k=(n+1)/2;
            cout <<sqrt(fmedian(d, 0, n-1, k))<<endl; 
        }
        else{
            k1=n/2;
            cout<<sqrt(fmedian(d,0,n-1,k1))<<endl;
        }
    }
    return 0; 
}
