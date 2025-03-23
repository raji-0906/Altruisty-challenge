#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;
int main() 
{
    int k, n;
    cout<<"k-value: ";
    cin >> k;
    cout<<"No. of elements: ";
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }
    deque<int> dq;
    vector<int> max_vals;
    for (int i = 0; i < k; i++) 
	{
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    max_vals.push_back(arr[dq.front()]);
    for (int i = k; i < n; i++)
	{
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
        max_vals.push_back(arr[dq.front()]);
    }
    int result = *min_element(max_vals.begin(), max_vals.end());
    cout<< "Minimum among the maximum brightness: "<< result << endl;
    return 0;
}
