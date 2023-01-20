#include<bits/stdc++.h>
using namespace std;

bool check(vector<bool>& safe, deque<int>& roads){
    for(int x: roads)
        if(not safe[x])
            return true;
    return false;
}

void update(vector<bool>& safe, deque<int>& roads){
    for(int x: roads)
        safe[x] = true;
}

int minCams(int N, vector<vector<int>>& roads){
    //adjacency list implementation
    vector<deque<int>> graph(N);
    for(int i =0;i < roads.size(); i++){
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }


    vector<bool> safe(N+1, false);
    int ans = 0;
    for(int i = 1; i < graph.size(); i++){
        if(not safe[i] or check(safe, graph[i])){
            ans++;
            update(safe, graph[i]);
        }
    }

    return ans;

}
int main(int argc, char const *argv[])
{
    /* code */
    int N;  cin >> N;
    vector<vector<int>> roads;
    

    return 0;
}
