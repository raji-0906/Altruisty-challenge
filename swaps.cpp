#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minAdjacentSwaps(string a, string b)
{
    if (a.length() != b.length()) return -1;
    string sortedA = a, sortedB = b;
    sort(sortedA.begin(), sortedA.end());
    sort(sortedB.begin(), sortedB.end());
    if (sortedA != sortedB) return -1;
    int swaps = 0;
    int n = a.length();
    for (int i = 0; i < n; i++) 
	{
        if (a[i] != b[i]) {
            int j = i;
            while (j < n && a[j] != b[i]) 
                j++;  
            if (j == n) return -1;
            while (j > i) {
                swap(a[j], a[j - 1]);
                swaps++;
                j--;
            }
        }
    }
    return swaps;
}
int main() 
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    cout << minAdjacentSwaps(a, b) << endl;
    return 0;
}

