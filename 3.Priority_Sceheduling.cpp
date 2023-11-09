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
    // priority vector
    vector<int>priority(n);
    for(int i=0;i<n;i++){
        cin>>arrival[i];
        cin>>length[i];
        cin>>priority[i];
    }
    vector<int>vis(n,0);
    //Waiting,Turnaround
    vector<int>waitingTime(n);
    vector<int>TurnAroundTime(n);
    priority_queue< pair<int,int>>q;
    // Push 0 arrival time process(priority).
    q.push({priority[0],0});
    vis[0] = 1;
    int time = 0;
    while(!q.empty()){
        auto it = q.top();
        int process = it.second;
        time+=length[process];
        q.pop();
      for(int i=0;i<n;i++){
         if(time>=arrival[i] && !vis[i]){
            q.push({priority[i],i});
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
// process = 5,arrival[]={0,1,2,3,4},length[]={4,3,1,5,2},
// priority[]={2,3,4,5,6}

// Input:
// 5
// 0 4 2
// 1 3 3
// 2 1 4
// 3 5 5
// 4 2 6
// output:
// Waiting time:
// 0 11 9 3 0 
// TurnAround time:
// 4 14 10 8 2 
// Average Waiting Time: 4.6
// Average TurnAround Time: 7.6
    return 0;
}
