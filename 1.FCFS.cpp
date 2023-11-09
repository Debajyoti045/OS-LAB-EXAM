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
    queue<pair<int,int>>q;
    // Push 0 arrival time process.
    q.push({0,length[0]});
    vis[0] = 1;
    int time = 0;
    while(!q.empty()){
        auto it = q.front();
        int process = it.first;
        time+=it.second;
        q.pop();
      for(int i=0;i<n;i++){
         if(time>=arrival[i] && !vis[i]){
            q.push({i,length[i]});
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
// process = 5,arrival time=[0,0,2,8,12],length=[10,9,5,5,4]
//Input
// 5
// 0 10
// 0 9
// 2 5
// 8 5
// 12 4

//Output
// Waiting time:
// 0 10 17 16 17 
// TurnAround time:
// 10 19 22 21 21 
// Average Waiting Time: 12
// Average TurnAround Time: 18.6
    return 0;
}
