#include <bits/stdc++.h>
using namespace std;

struct items {
    int value;
    int weight;
};

bool compare(items &a, items &b){
    return (a.value / (double)a.weight) > (b.value / (double)b.weight);
}

double fractionalKnapsack(int W, items *Items, int n) {
    sort(Items,Items+n,compare);
    // for(int i=0;i<n;i++){
    //     cout<<Items[i].value<<" "<<Items[i].weight<<" "<<endl;
    // }
    double max_val =0;
    int cur_w = 0;

    for(int i=0;i<n;i++){
        if(cur_w + Items[i].weight <= W){
            cur_w += Items[i].weight;
            max_val += Items[i].value;
        }
        else{
            int rem_w = W - cur_w;
            max_val += Items[i].value * (rem_w / (double)Items[i].weight);
            break;
        }
    }
    return max_val;
}

int main(){
    int n;
    cin>>n;
    items Items[n];
    for(int i=0;i<n;i++){
        cin>>Items[i].value>>Items[i].weight;
    }
    int w;
    cin>>w;
    cout<<fractionalKnapsack(w, Items, n);
    return 0;
}