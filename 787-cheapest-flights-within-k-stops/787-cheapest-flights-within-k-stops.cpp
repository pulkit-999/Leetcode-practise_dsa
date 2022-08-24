class Solution {
public:
    int dijkstra(int n, unordered_map<int, list<pair<int, int>>>& adj, int src, int dst, int k){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minheap;
        // {level, {distance, node}}
		// here i have marked the no. of stoppages in the name of levels (bfs levels)
        minheap.push({-1, {0, src}});
        vector<int> distance(n, INT_MAX);
        while(!minheap.empty()){
            int level = minheap.top().first;
            int cost = minheap.top().second.first;
            int node = minheap.top().second.second;
            minheap.pop();
            
			// if no of stoppages exceed k, then don't consider it
            if(level+1 > k) continue;
            for(auto& next:adj[node]){
                int d = cost + next.second;
                if(d < distance[next.first]){
                    distance[next.first] = d;
                    minheap.push({level+1, {d, next.first}});
                }
            }
        }
        return (distance[dst]==INT_MAX)?-1:distance[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(auto& flight:flights){
            int u = flight[0], v = flight[1], wt = flight[2];
            adj[u].push_back({v, wt});
        }
        return dijkstra(n, adj, src, dst, k);
    }
       
};