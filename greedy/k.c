#include<stdio.h>

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int greedy_algo(int x[],int c[],int y[],int r[],int m,int n,int b){
    int f[m];
    int d[n];
    int t[(m+n)];
    for(int i=0;i<m;i++){
        f[i]=x[i]*c[i];
        t[i]=f[i];
    }

    for(int i=0;i<n;i++){
        d[i]=y[i]*r[i];
        t[i+m]=d[i];
    }

    int total=m+n;

    int arr[m+n];
    for(int i=0;i<(m+n);i++){
        arr[i]=i;
    }
    for(int i=0;i<total;i++){
        for(int j=0;j<total-i-1;j++){
            if(t[j]>t[j+1]){
                swap(&t[j],&t[j+1]);
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

    int count=0;
    for(int i=0;i<total;i++){
        if(b>0 && t[i]<=b){
            b=b-t[i];
            count++;
        }
    }

    for(int i=0;i<count;i++){
        if(arr[i]>m-1){
            printf("%d(d)-->",arr[i]-m+1);
        }

        else{
            printf("%d(f)-->",arr[i]+1);
        }
    }

    return count;

}
int main()
{
    int x[]={2,1,2};
    int c[]={10,20,30};
    int y[]={1,3,2,1};
    int r[]={20,50,30,40};

    int num=greedy_algo(x,c,y,r,3,4,100);
    printf("\n");
    printf("Maximum items:%d",num);

    
return 0;
}