// Programa em C++ para exemplificar 
#include <bits/stdc++.h>
using namespace std;
 
// function to determine the edge colors
void colorEdges(int ptr, vector<vector<pair<int, int> > >& gra,
                vector<int>& edgeColors, bool isVisited[])
{
    queue<int> q;
    int c = 0;
 
    unordered_set<int> colored;
 
    // return if isVisited[ptr] is true
    if (isVisited[ptr])
        return;
 
    // Mark the current node visited
    isVisited[ptr] = 1;
 
    // Traverse all edges of current vertex
    for (int i = 0; i < gra[ptr].size(); i++) {
        // if already colored, insert it into the set
        if (edgeColors[gra[ptr][i].second] != -1)
            colored.insert(edgeColors[gra[ptr][i].second]);
    }
 
    for (int i = 0; i < gra[ptr].size(); i++) {
        // if not visited, inset into the queue
        if (!isVisited[gra[ptr][i].first])
            q.push(gra[ptr][i].first);
 
        if (edgeColors[gra[ptr][i].second] == -1) {
            // if col vector -> negative
            while (colored.find(c) != colored.end())
 
                // increment the color
                c++;
 
            // copy it in the vector
            edgeColors[gra[ptr][i].second] = c;
 
            // then add it to the set
            colored.insert(c);
            c++;
        }
    }
 
    // while queue's not empty
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
 
        colorEdges(temp, gra, edgeColors, isVisited);
    }
 
    return;
}
 
// Driver Function
int main()
{
    set<int> empty;
 
    // declaring vector of vector of pairs, to define Graph
    vector<vector<pair<int, int> > > gra;
 
    vector<int> edgeColors;
 
    bool isVisited[100000] = { 0 };
 
    // Enter the Number of Vertices
    // and the number of edges
    int ver = 4;
    int edge = 4;
 
    gra.resize(ver);
    edgeColors.resize(edge, -1);
 
    // Enter edge & vertices of edge
    // x--; y--;
    // Since graph is undirected, push both pairs
    // (x, y) and (y, x)
    // graph[x].push_back(make_pair(y, i));
    // graph[y].push_back(make_pair(x, i));
    gra[0].push_back(make_pair(1, 0));
    gra[1].push_back(make_pair(0, 0));
 
    gra[1].push_back(make_pair(2, 1));
    gra[2].push_back(make_pair(1, 1));
 
    gra[2].push_back(make_pair(3, 2));
    gra[3].push_back(make_pair(2, 2));
 
    gra[0].push_back(make_pair(3, 3));
    gra[3].push_back(make_pair(0, 3));
 
    colorEdges(0, gra, edgeColors, isVisited);
 
    // printing all the edge colors
    for (int i = 0; i < edge; i++)
        cout << "Edge " << i + 1 << " is of color "
             << edgeColors[i] + 1 << "\n";
 
    return 0;
}