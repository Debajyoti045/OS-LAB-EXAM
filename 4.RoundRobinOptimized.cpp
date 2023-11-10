#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> a(n), bt(n), turnaroundTime(n), waitingTime(n);
	for(int i = 0; i < n; i++)
		cin >> a[i] >> bt[i];
	int timeQuantum;
	cin >> timeQuantum;
	queue<pair<int, int>> q;
    int i = 0, ct = 0;
    while(i < n || !q.empty())
    {
        int job = -1, left = 0;
        if(!q.empty())
        {
            job = q.front().first;
            left = q.front().second;
            turnaroundTime[job] = ct + left - a[job];
            q.pop();
        }
        if(job == -1)
        {
            ct = a[i];
            q.push({i, bt[i]});
            i++;
        }
        int mn = min(timeQuantum, left);
        ct += mn;
        left -= mn;
        while(i < n && a[i] <= ct)
        {
            q.push({i, bt[i]});
            i++;
        }
        if(left) 
			q.push({job, left});
    }

	float avgWT = 0, avgTT = 0;
	for(int i = 0; i < n; i++)
	{
		waitingTime[i] = turnaroundTime[i] - bt[i];
		avgWT += waitingTime[i];
		avgTT += turnaroundTime[i];
	}
    cout << "Waiting time:" << endl;
    for(auto x : waitingTime) 
        cout<< x <<" ";
    cout << endl;

    cout<<"TurnAround time:" << endl;
    for(auto x:turnaroundTime) 
        cout<< x <<" ";
    cout << endl;
	avgTT /= n;
	avgWT /= n;
    cout << "Average Waiting Time: " << avgWT << "\n";
    cout << "Average TurnAround Time: " << avgTT << "\n";
	return 0;
}
/*
process = 5,arrival[]={0,0,2,8,12},length[]={8,10,5,6,4},
Quantum time = 2
Input:
5
0 8
0 10
2 5
8 6
12 4
2
Output:
Waiting time:
17 23 14 17 13 
TurnAround time:
25 33 19 23 17 
Average Waiting Time: 16.8
Average TurnAround Time: 23.4
*/