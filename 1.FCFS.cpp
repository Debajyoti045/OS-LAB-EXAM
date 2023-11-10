#include <bits/stdc++.h>
using namespace std;
// fcfs
signed main()
{
	int n;
	cin >> n;
	vector<int> arrival(n), burstTime(n), turnaroundTime(n), waitingTime(n);
	for(int i = 0; i < n; i++)
		cin >> arrival[i] >> burstTime[i];
	int currentTime = 0;
	float avgWT = 0, avgTT = 0;
	for(int i = 0; i < n; i++)
	{
		currentTime = max(currentTime, arrival[i]);
		currentTime += burstTime[i];
		turnaroundTime[i] = currentTime - arrival[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        avgTT += turnaroundTime[i];
        avgWT += waitingTime[i];
	}
	avgWT /= n;
    avgTT /= n;
    cout << "Waiting time:" << endl;
    for(auto x : waitingTime) 
        cout<< x <<" ";
    cout << endl;

    cout<<"TurnAround time:" << endl;
    for(auto x:turnaroundTime) 
        cout<< x <<" ";
    cout << endl;

    cout << "Average Waiting Time: " << avgWT << "\n";
    cout << "Average TurnAround Time: " << avgTT << "\n";
	return 0;
}