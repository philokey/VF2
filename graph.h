#ifndef VF2_GRAPH_H
#define VF2_GRAPH_H

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <assert.h>
using namespace std;
const int MAXN = 305;

struct Edge {
    int v, w, next;
};
struct Container {
    int a, b, c;
};
class Graph {
private:
    vector<int> head;
    vector<int> rhead;
    int en; //edge number
    vector<int> node;
    int n, e;
    void addedge(int u, int v, int w);
public:
    int getNodeLabel(int i)const;
    void initGraph(Container *cnode, Container *cedge);
    int getSize()const;
    int getHead(int i)const;
    int getRhead(int i)const;
    vector<unordered_set<int>> pred, succ;
    vector<Edge> edge;
    vector<Edge> redge;
    Graph();
    Graph(int _n, int _e);
};

#endif //VF2_GRAPH_H
