#include<iostream>
using namespace std;
void countsort(int arr[],int n,int div)
{
    int m=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
        }
    }
    int countt[m]={0};
    for(int i=0;i<n;i++)
    {
        countt[(arr[i]/div)%10]++;
    }
    for(int i=1;i<=m;i++)
    {
         countt[i]+=countt[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[--countt[(arr[i]/div)%10]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
void radix(int arr[],int n)
{
    int m=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
        }
    }
    for(int div=1;(m/div)>0;div=div*10)
    {
        countsort(arr,n,div);
    }
}
void print(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int main()
{
    int n ;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];
for(int i=0;i<n;i++){
    cout<<"Enter the element "<<i+1<<" : ";
    cin>>a[i];

}


    
    radix(a,n);
    cout<<endl<<"Sorted Array : "<<endl;
    print(a,n);


}