#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    string s;
    int n,i;
    cin >> s >> n;
    int len = s.length();
    vector<int> treasureCount(len + 1, 0);
    for (i=0; i < len; i++) 
	{
        treasureCount[i + 1] = treasureCount[i] + (s[i] == 'T' ? 1 : 0);
    }
    while (n--) 
	{
        int l, r;
        cin >> l >> r;
        cout <<"Treasure Count: "<< (treasureCount[r] - treasureCount[l - 1]) << endl;
    }
    return 0;
}
