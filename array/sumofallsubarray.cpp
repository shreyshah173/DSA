#include <iostream>
#include <climits>
using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int maxSum = INT_MIN;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            int sum = 0;
            for(int k=i;k<j;k++){
                sum+=arr[k];
            }
            maxSum = max(sum , maxSum);
        }
    }
    return 0;
}