#include <iostream>
#include "graph.h"
#include "State.h"
#include "vf2.h"
#include "readData.h"
#include <ctime>
#include <cstdlib>
using namespace std;
void test() {
    srand(time(NULL));
    vector<Graph> G1, G2;
    char path1[100] = "/Users/philokey/ClionProjects/VF2/graphDB/mygraphdb.data";
    char path2[100] = "/Users/philokey/ClionProjects/VF2/graphDB/Q4.my";

    readGraph(G1, path1);
    readGraph(G2, path2);
    int c1 = 0;
    time_t totalTime, startT;
    int sz1 = G1.size();
    //for (auto g2 : G2) {
    for (int i = 0; i < G2.size(); ++i) {
        Graph &g2 = G2[i];
        ++c1;
        //if (c1 == 542 || c1 == 543) continue;
        int rg = rand()%sz1;
        Graph &g1 = G1[rg];
        State s(g1.getSize(), g2.getSize());
        cout<<i<<" "<<rg<<endl;
        startT = clock();
        match(g1, g2, s);
        totalTime += clock() - startT;
    }
    printf("Average: %.3f\n", totalTime*1.0/c1/ CLOCKS_PER_SEC * 1000);
}
int main() {
    test();
    return  0;
    vector<Graph> G1, G2;
    char path1[100] = "/Users/philokey/ClionProjects/VF2/in.txt";
    char path2[100] = "/Users/philokey/ClionProjects/VF2/in2.txt";
    //char path1[100] = "/Users/philokey/ClionProjects/VF2/graphDB/mygraphdb.data";
    //char path2[100] = "/Users/philokey/ClionProjects/VF2/graphDB/Q16.my";
    readGraph(G1, path1);
    readGraph(G2, path2);
    int c1, c2;
    time_t totalTime, startT;
    double t = 0;
    c1 = c2 = 0;
    totalTime = 0;
    for (auto g1 : G1) {
        c2 = 0;
        totalTime = 0;
        //for(int j = 41; j <= 41; ++j) {
            //Graph &g2 = G2[j];
        for (auto g2 : G2) {
            State s(g1.getSize(), g2.getSize());
            printf("%d %d\n", c1, c2);
            startT = clock();
            if (match(g1, g2, s)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            totalTime += clock() - startT;
            //printf("%.3f\n", totalTime*1000.0 / CLOCKS_PER_SEC/(c2+1));
            ++c2;
        }
        printf("%.3f\n", totalTime*1000.0 / CLOCKS_PER_SEC/(c2+1));
        t += totalTime * 1000.0 / CLOCKS_PER_SEC/c2;
        ++c1;
    }
    printf("Average: %.3f\n", t / c1);
    return 0;
}