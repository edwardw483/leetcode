#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //Create the adjacency list, where forward edges have weight 1, backwards edges have weight 2
        vector<vector<pair<int, int>>> adjList(n);
        for(auto i: connections){
            adjList[i[0]].push_back(make_pair(i[1], 1)); // Forward Link: weight 1
            adjList[i[1]].push_back(make_pair(i[0], 0)); // Backward Link: weight 0
        }
        //BFS, except we only add edges to explore if it hasn't been visited before
        //Prevents duplicates, we know this is valid because it's a tree
        queue<int> toExplore;
        unordered_map<int, bool> visited;
        int toSwap = 0;
        toExplore.push(0);
        while(toExplore.size() > 0){
            int node = toExplore.front();
            toExplore.pop();
            visited[node] = true;
            for(pair<int, int> i: adjList[node]){
                if(!visited[i.first]){
                    toSwap += i.second; 
                    toExplore.push(i.first);
                }
            }
        }
        return toSwap;

    }
};