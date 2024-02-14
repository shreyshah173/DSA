#include <iostream>
#include <algorithm>
using namespace std;

int Knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int k[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                k[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                k[i][w] = max(k[i - 1][w - wt[i - 1]] + val[i - 1], k[i - 1][w]);
            } else {
                k[i][w] = k[i - 1][w];
            }
        }
    }
    return k[n][W];
}

int main() {
    int val[] = {2, 3, 1, 4};
    int wt[] = {3, 4, 6, 5};
    int W = 8;
    int n = sizeof(val) / sizeof(val[0]);
    cout << Knapsack(W, wt, val, n) << endl;
    return 0;
}
