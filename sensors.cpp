#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    vector<int> sensors(5, 0);
    int i,val, count = 0;
    for (int i = 0; i < 20; i++) 
	{
        cin >> val;
        if (val < 10 || val > 200) 
		{
            cout << "INVALID INPUT";
            return 0;
        }
        sensors[i % 5] += val;
    }
    int max_avg = 0, max_sensor = -1;
    bool optimal = true;
    
    for (i = 0; i < 5; i++) 
	{
        sensors[i] = round(sensors[i] / 4.0);
        if (sensors[i] >= 50) 
		{
            optimal = false;
        }
        if (sensors[i] > max_avg) 
		{
            max_avg = sensors[i];
            max_sensor = i + 1;
        }
    }
    if (optimal) {
        cout << "Energy consumption is optimal.";
    } else {
        cout << "Sensor Number : " << max_sensor;
    }
    return 0;
}
