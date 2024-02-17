#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> toExplore(0, 0);
        unordered_map<int, bool> explored(isConnected.size());
        int connectedComponents = 0;
        //Run BFS for each unvisited node in the array
        for(int i = 0; i < isConnected.size(); i++){
            //Skip if already explored
            if(explored[i]){
                continue;
            }
            //Run BFS
            toExplore.push_back(i);
            explored[i] = true;
            while(toExplore.size() != 0){
                //Get the node from the explored queue
                int node = toExplore.back();
                toExplore.pop_back();
                for(int j = 0; j < isConnected[node].size(); j++){
                    //If connected and hasn't been visited yet
                    if(isConnected[node][j] && explored[j] == false){
                        toExplore.push_back(j);
                        explored[j] = true;
                    }
                }
            }
            connectedComponents++;
        }
        return connectedComponents;
    }
};