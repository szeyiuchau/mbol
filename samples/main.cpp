#include<ChromaticNumber.hpp>
#include<HelloWorld.hpp>
#include<MaxFlow.hpp>
#include<NodeDisjointPaths.hpp>
#include<map>
#include<set>
using namespace std;
set<int> V;
map<int,map<int,double> > w;
map<int,map<int,double> > e;
void addEdge(int a,int b) {
    w[a][b]=rand()%5+1;
    w[b][a]=w[a][b];
    e[a][b]=1;
    e[b][a]=e[a][b];
}
void makeGraph() {
    int n=15;
    for(int i=1;i<=15;i++) {
        V.insert(i);
    }
    addEdge(1,3);
    addEdge(1,9);
    addEdge(1,8);
    addEdge(4,12);
    addEdge(1,10);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(2,6);
    addEdge(3,7);
    addEdge(3,8);
    addEdge(4,9);
    addEdge(5,15);
    addEdge(6,13);
    addEdge(7,12);
    addEdge(8,11);
    addEdge(9,10);
    addEdge(10,11);
    addEdge(11,13);
    addEdge(12,15);
    addEdge(13,14);
    addEdge(14,5);
}
void writeGraph() {
    ofstream out("graph.dot");
    out << "graph test {\n";
    for(set<int>::iterator i=V.begin();i!=V.end();i++) {
        out << (*i) << " [label=\"" << (*i) << "\",width=.5,height=.5,shape=circle];\n";
    }
    for(map<int,map<int,double> >::iterator i=w.begin();i!=w.end();i++) {
        for(map<int,double>::iterator j=i->second.begin();j!=i->second.end();j++) {
            if(i->first < j->first && j->second!=0) {
                out << i->first << "--" << j->first << "[label=\"" << j->second << "\"];" << endl;
            }
        }
    }
    out << "}\n";
    out.close();
}
int main(int argc,char* argv[]) {
    makeGraph();
    if(argc==2&&string(argv[1])=="justgraph") {
        writeGraph();
        exit(0);
    }
    cout << "HelloWorld:" << endl;;
    {
        HelloWorld hw;
        hw.e=5.8;
        hw.r=1.23;
        hw.W=2;
        hw.l=1;
        hw.o=1.713;
        cout << "Constant values:" << endl;
        cout << "  e: " << hw.e << endl;
        cout << "  r: " << hw.r << endl;
        cout << "  W: " << hw.W << endl;
        cout << "  l: " << hw.l << endl;
        cout << "  o: " << hw.o << endl;
hw.init();
bool ret=hw.solve();
        if(ret) {
            cout << "Optimal objective value: " << hw.objValue << endl;
            cout << "Optimal solution:" << endl;
            cout << "  H: " << hw.H << endl;
            cout << "  d: " << hw.d << endl;
        } else {
            cout << "CPLEX ERROR OCCURRED\n";
        }
    }
    cout << "\nGraph algorithms computed on the graph shown in graph.pdf." << endl;
    cout << "\nChromaticNumber:" << endl;
    {
        ChromaticNumber cn;
        cn.V=V;
        cn.e=e;
        cn.solve();
        cout << "Chromatic number is " << cn.objValue << endl;
        cout << "Color map is " << endl;
        for(map<int,map<int,int> >::iterator i=cn.c.begin();i!=cn.c.end();i++) {
            for(map<int,int>::iterator j=i->second.begin();j!=i->second.end();j++) {
                if(j->second>0.5) {
                    cout << "  color " << setw(2) << i->first << " assigned to node " << setw(2) << j->first << endl;
                }
            }
        }
    }
    cout << "\nMaxFlow:" << endl;;
    {
        MaxFlow mf;
        mf.s=1;
        mf.t=5;
        mf.V=V;
        mf.w=w;
        mf.init();
        mf.solve();
        cout << "Maxflow from " << setw(2) << mf.s << " to " << setw(2) << mf.t << " is " << mf.objValue << endl;
    }
    {
        MaxFlow mf;
        mf.s=7;
        mf.t=14;
        mf.V=V;
        mf.w=w;
        mf.init();
        mf.solve();
        cout << "Maxflow from " << setw(2) << mf.s << " to " << setw(2) << mf.t << " is " << mf.objValue << endl;
    }
    cout << "\nNodeDisjointPaths:" << endl;;
    {
        NodeDisjointPaths ndp;
        ndp.s=1;
        ndp.t=5;
        ndp.V=V;
        ndp.e=e;
        ndp.init();
        ndp.solve();
        cout << "Node disjoint Paths from " << setw(2) << ndp.s << " to " << setw(2) << ndp.t << " is " << ndp.objValue << endl;
    }
    {
        NodeDisjointPaths ndp;
        ndp.s=7;
        ndp.t=14;
        ndp.V=V;
        ndp.e=e;
        ndp.init();
        ndp.solve();
        cout << "Node disjoint Paths from " << setw(2) << ndp.s << " to " << setw(2) << ndp.t << " is " << ndp.objValue << endl;
    }
}
