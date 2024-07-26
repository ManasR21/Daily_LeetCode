#include <bits/stdc++.h>

using namespace std;


// Problem: Find the City With the Smallest Number of Neighbors at a Threshold Distance

// Approach: Floyd-Warshall algorithm
// Intuition: The problem is asking us to find the city with the smallest number of cities that are reachable within distanceThreshold from it. We can solve this problem by using the Floyd-Warshall algorithm to find the shortest distance between all pairs of cities. Then, we can iterate through all the cities and count the number of cities that are reachable within distanceThreshold from each city. Finally, we can return the city with the smallest number of reachable cities.

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2)); // INT_MAX/2 to avoid overflow
        for (int i = 0; i < n; i++)
            dist[i][i] = 0; // distance from node to itself is
        for (auto &e : edges)
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2]; // distance between two nodes is the weight of the edge
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // Floyd-Warshall algorithm
        int res = -1, minCnt = n;                                          // res is the city with the smallest number of cities that are reachable within distanceThreshold from it and minCnt is the number of cities that are reachable from res
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (dist[i][j] <= distanceThreshold) // if the distance between two cities is less than or equal to distanceThreshold, then they are reachable from each other
                    cnt++;
            if (cnt <= minCnt) // if the number of cities reachable from i is less than or equal to minCnt, then update res and minCnt
            {
                minCnt = cnt;
                res = i;
            }
        }
        return res;
    }
};