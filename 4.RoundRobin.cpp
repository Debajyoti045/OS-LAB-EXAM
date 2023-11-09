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
    vector<int>dupLength(length);
    // Quantun time
    int qt;
    cin>>qt;
    vector<int>vis(n,0);
    //Waiting,Turnaround
    vector<int>waitingTime(n);
    vector<int>TurnAroundTime(n);
    
    int time = 0;
    queue<int>q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int process = q.front();
        q.pop();
        if(length[process]>qt){
           length[process] = length[process] - qt;
           time+=qt;
          for(int i=0;i<n;i++){
            if(time>=arrival[i] && !vis[i]){
                q.push(i);
                vis[i] = 1;
            }
          }
          q.push(process);
        }
        else{
            time+=length[process];
         for(int i=0;i<n;i++){
            if(time>=arrival[i] && !vis[i]){
                q.push(i);
                vis[i] = 1;
            }
          }

        TurnAroundTime[process] = time - arrival[process];
          waitingTime[process] = TurnAroundTime[process] - dupLength[process];
        }
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
// process = 5,arrival[]={0,0,2,8,12},length[]={8,10,5,6,4},
// Quantum time = 2
// Input:
// 5
// 0 8
// 0 10
// 2 5
// 8 6
// 12 4
// 2
// Output:
// Waiting time:
// 17 23 14 17 13 
// TurnAround time:
// 25 33 19 23 17 
// Average Waiting Time: 16.8
// Average TurnAround Time: 23.4
    return 0;
}
