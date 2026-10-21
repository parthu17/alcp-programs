#include <bits/stdc++.h>
using namespace std;
// Bounding function: can vertex v take colour c, given the colours
// already chosen for vertices 0 .. v-1 ?
bool isSafe(int v, int c, vector<vector<int>> &graph, vector<int> &colors) {
for (int u = 0; u < v; u++) {
if (graph[v][u] == 1 && colors[u] == c) return false;
}
return true;
}
bool mColoringBnB(vector<vector<int>> &graph, int n, int m,
vector<int> &answer, int &nodesCreated) {
queue<vector<int>> live; // each node = colours of vertices 0..k-1
live.push({}); // root: nothing coloured yet
nodesCreated = 1;
while (!live.empty()) {
vector<int> state = live.front(); live.pop();
// FIFO: oldest live node first
int v = state.size(); if (v == n) { answer = state;
return true;
// next vertex to colour
// every vertex has a colour
}
for (int c = 1; c <= m; c++) { // branch: try each colour
if (isSafe(v, c, graph, state)) { vector<int> child = state;
child.push_back(c);
live.push(child);
nodesCreated++;
// bound: prune clashes
}
}
}
return false; // no live nodes left
}
int main() {
int n, m;
cout << "Enter number of vertices: ";
cin >> n;
vector<vector<int>> graph(n, vector<int>(n));
cout << "Enter the " << n << "x" << n << " adjacency matrix:\n";
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
cin >> graph[i][j];
cout << "Enter number of colours m: ";
cin >> m;
vector<int> answer;
int nodesCreated = 0;
if (mColoringBnB(graph, n, m, answer, nodesCreated)) {
cout << "Colouring possible with " << m << " colours:\n";
for (int i = 0; i < n; i++)
cout << "Vertex " << i << " -> Colour " << answer[i] << endl;
} else {
cout << "Not possible with " << m << " colours." << endl;
}
cout << "State space nodes created: " << nodesCreated << endl;
return 0;
}
