#include "readData.h"
void readGraph(vector<Graph> &G, char *name) {
    freopen(name, "r", stdin);
    char op[3];
    int id;
    int n, e;
    Container node[MAXN], edge[MAXN*MAXN/2];
    scanf("%s", op);
    while (scanf("%s%d", op, &id) && id != -1) {
        n = e = 0;
        while (scanf("%s", op) && op[0] != 't') {
            if (op[0] == 'v') {
                scanf("%d%d", &node[n].a, &node[n].b);
                ++n;
            } else {
                scanf("%d%d%d", &edge[e].a, &edge[e].b, &edge[e].c);
                ++e;
            }
        }
        Graph g(n, e);
        g.initGraph(node, edge);
        G.push_back(g);
    }
}