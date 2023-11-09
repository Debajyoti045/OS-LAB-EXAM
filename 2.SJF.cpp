#include <bits/stdc++.h>
using namespace std;
int main()
{
    //No of processes
    int n;
    cin>>n;
    // Arrival Time
    vector<int>arrival(n);
    // Burst Time
    vector<int>length(n);
    for(int i=0;i<n;i++){
        cin>>arrival[i];
        cin>>length[i];
    }
    vector<int>vis(n,0);
    //Waiting,Turnaround
    vector<int>waitingTime(n);
    vector<int>TurnAroundTime(n);
    priority_queue< pair<int,int>,vector< pair<int,int>>,greater< pair<int,int>>>q;
    // Push 0 arrival time process(min).
    int process = 0;
    int len = length[0];
    q.push({len,process});
    vis[process] = 1;
    int time = 0;
    while(!q.empty()){
        auto it = q.top();
        int process = it.second;
        time+=it.first;
        q.pop();
      for(int i=0;i<n;i++){
         if(time>=arrival[i] && !vis[i]){
            q.push({length[i],i});
            vis[i] = 1;
         }
      }
      TurnAroundTime[process] = time - arrival[process];
      waitingTime[process] = TurnAroundTime[process] - length[process];
    }
    cout<<"Waiting time:"<<endl;
    for(auto it:waitingTime) cout<<it<<" ";
    cout<<endl;
    cout<<"TurnAround time:"<<endl;
    for(auto it:TurnAroundTime) cout<<it<<" ";
    cout<<endl;
    cout<<"Average Waiting Time: ";
    float averageWait = 0.0;
    for(auto it:waitingTime) averageWait+=it;
    cout<<(float)(averageWait/n)<<endl;
    

    cout<<"Average TurnAround Time: ";
    float averageTurn = 0.0;
    for(auto it:TurnAroundTime) averageTurn+=it;
    cout<<(float)(averageTurn/n)<<endl;

// process = 5,arrival[] = {0,0,2,8,12},length[] = {9,10,5,5,4}

// input:
// 5
// 0 9
// 0 10
// 2 5
// 8 5
// 12 4

// output:
// Waiting time:
// 0 23 7 10 2 
// TurnAround time:
// 9 33 12 15 6 
// Average Waiting Time: 8.4
// Average TurnAround Time: 15
    return 0;
}
