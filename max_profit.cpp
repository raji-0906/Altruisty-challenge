#include <iostream>
using namespace std;
int calculateMaxProfit(int price[], int n) {
    int i,min_p = price[0], max_profit = 0;
    for ( i = 1; i < n; i++) {
        min_p = min(min_p, price[i]);
        max_profit = max(max_profit, price[i] - min_p);
    }
    return max_profit;
}
int main() {
    int i,n;
    cin >> n;
    int price[n];
    for ( i = 0; i < n; i++)
        cin >> price[i];
    cout <<"Maximum Profit: "<< calculateMaxProfit(price, n) << endl;
    return 0;
}
