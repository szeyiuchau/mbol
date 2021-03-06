#include<fstream>
#include<iostream>
#include<ChromaticNumber.hpp>
#include<iomanip>
#include<VertexCover.hpp>
#include<HelloWorld.hpp>
#include<MaxFlow.hpp>
#include<NodeDisjointPaths.hpp>
#include<SVMSoftMargin.hpp>
#include<SVMHardMargin.hpp>
#include<map>
#include<set>
using namespace std;
set<int> VV;
map<int, map<int, double> > w;
map<int, map<int, double> > e;
void addEdge(int a, int b) {
  w[a][b] = rand() % 5 + 1;
  w[b][a] = w[a][b];
  e[a][b] = 1;
  e[b][a] = e[a][b];
}
void makeGraph() {
  for (int i = 1; i <= 10; i++) {
    VV.insert(i);
  }
  addEdge(1, 3);
  addEdge(1, 9);
  addEdge(1, 8);
  addEdge(1, 10);
  addEdge(2, 4);
  addEdge(2, 5);
  addEdge(2, 6);
  addEdge(3, 7);
  addEdge(3, 8);
  addEdge(4, 9);
  addEdge(6, 7);
  addEdge(9, 10);
}
void writeGraph() {
  ofstream out("misc-files/graph.dot");
  out << "graph test {\n";
  for (set<int>::iterator i = VV.begin(); i != VV.end(); i++) {
    out << (*i) << " [label=\"" << (*i) << "\",width=.5,height=.5,shape=circle];\n";
  }
  for (map<int, map<int, double> >::iterator i = w.begin(); i != w.end(); i++) {
    for (map<int, double>::iterator j = i->second.begin(); j != i->second.end(); j++) {
      if (i->first < j->first && j->second != 0) {
        out << i->first << "--" << j->first << "[label=\"" << j->second << "\"];" << endl;
      }
    }
  }
  out << "}\n";
  out.close();
}
int main(int argc, char* argv[]) {
  makeGraph();
  if (argc == 2 && string(argv[1]) == "justgraph") {
    writeGraph();
    exit(0);
  }
  set<Element, ElementCompare> V = thingConversion(VV);
  {
    cout << "Element test:" << endl;
    Element a = 5;
    Element b = 4;
    Element e = 3;
    Element f = 9;
    set<Element, ElementCompare> c;
    c.insert(a);
    c.insert(b);
    Element d = c;
    vector<Element> g;
    g.push_back(d);
    g.push_back(e);
    vector<Element> i;
    i.push_back(d);
    i.push_back(f);
    Element k = g;
    Element l = i;
    set<Element, ElementCompare> h;
    h.insert(k);
    h.insert(l);
    Element j = h;
    cout << l.print() << " and " << k.print() << " are tuples in the set " << j.print() << endl;
  }
  cout << "\nHelloWorld:" << endl;
  {
    HelloWorld hw;
    hw.e = 5.8;
    hw.r = 1.23;
    hw.W = 2;
    hw.l = 1;
    hw.o = 1.713;
    cout << "Constant values:" << endl;
    cout << "  e: " << hw.e << endl;
    cout << "  r: " << hw.r << endl;
    cout << "  W: " << hw.W << endl;
    cout << "  l: " << hw.l << endl;
    cout << "  o: " << hw.o << endl;
    hw.init();
    bool ret = hw.solve();
    if (ret) {
      cout << "Optimal objective value: " << hw.objValue << endl;
      cout << "Optimal solution:" << endl;
      cout << "  H: " << hw.H_ret << endl;
      cout << "  d: " << hw.d_ret << endl;
    } else {
      cout << "CPLEX ERROR OCCURRED\n";
    }
  }
  cout << "\nGraph algorithms computed on the graph shown in graph.pdf." << endl;
  cout << "\nVertexCover:" << endl;
  {
    set<Element, ElementCompare> E;
    for (map<int, map<int, double> >::iterator i = e.begin(); i != e.end(); i++) {
      for (map<int, double>::iterator j = i->second.begin(); j != i->second.end(); j++) {
        if (j->second > 0.5) {
          vector<Element> temp;
          temp.push_back(i->first);
          temp.push_back(j->first);
          E.insert(temp);
        }
      }
    }
    VertexCover vc;
    vc.V = V;
    vc.E = E;
    vc.solve();
    cout << "Vertices required to cover is " << vc.objValue << endl;
    cout << "Vertices covered ";
    for (map<int, int>::iterator i = vc.x_ret.begin(); i != vc.x_ret.end(); i++) {
      if (i->second > 0.5) {
        cout << i->first << " ";
      }
    }
    cout << endl;
  }
  cout << "\nChromaticNumber:" << endl;
  {
    ChromaticNumber cn;
    cn.V = V;
    cn.e = e;
    cn.solve();
    cout << "Chromatic number is " << cn.objValue << endl;
    cout << "Color map is " << endl;
    for (map<int, map<int, int> >::iterator i = cn.c_ret.begin(); i != cn.c_ret.end(); i++) {
      for (map<int, int>::iterator j = i->second.begin(); j != i->second.end(); j++) {
        if (j->second > 0.5) {
          cout << "  color " << setw(2) << i->first << " assigned to node " << setw(2) << j->first << endl;
        }
      }
    }
  }
  cout << "\nMaxFlow:" << endl;
  {
    MaxFlow mf;
    mf.s = 1;
    mf.t = 5;
    mf.V = V;
    mf.w = w;
    mf.init();
    mf.solve();
    cout << "Maxflow from " << setw(2) << mf.s << " to " << setw(2) << mf.t << " is " << mf.objValue << endl;
  }
  {
    MaxFlow mf;
    mf.s = 2;
    mf.t = 3;
    mf.V = V;
    mf.w = w;
    mf.init();
    mf.solve();
    cout << "Maxflow from " << setw(2) << mf.s << " to " << setw(2) << mf.t << " is " << mf.objValue << endl;
  }
  cout << "\nNodeDisjointPaths:" << endl;
  {
    NodeDisjointPaths ndp;
    ndp.s = 1;
    ndp.t = 5;
    ndp.V = V;
    ndp.e = e;
    ndp.init();
    ndp.solve();
    cout << "Node disjoint Paths from " << setw(2) << ndp.s << " to " << setw(2) << ndp.t << " is " << ndp.objValue << endl;
  }
  {
    NodeDisjointPaths ndp;
    ndp.s = 2;
    ndp.t = 3;
    ndp.V = V;
    ndp.e = e;
    ndp.init();
    ndp.solve();
    cout << "Node disjoint Paths from " << setw(2) << ndp.s << " to " << setw(2) << ndp.t << " is " << ndp.objValue << endl;
  }
  cout << "\nSVMHardMargin:" << endl;
  {
    SVMHardMargin svm;
    ofstream out1("misc-files/svm-hardmargin.plot");
    ofstream out2("misc-files/svm-hardmargin.data");
    svm.n = 20;
    svm.d = 2;
    for (int i = 1; i <= svm.n; i++) {
      svm.P[i][1] = 1.*rand() / RAND_MAX;
      svm.P[i][2] = 1.*rand() / RAND_MAX;
      svm.N[i][1] = -1.*rand() / RAND_MAX;
      svm.N[i][2] = -1.*rand() / RAND_MAX;
      out2 << svm.P[i][1] << " " << svm.P[i][2] << " " << svm.N[i][1] << " " << svm.N[i][2] << endl;
    }
    if (svm.solve()) {
      cout << "successful SVM solve" << endl;
    }
    cout << "SVM soln: " << svm.objValue << endl;
    cout << svm.w_ret[1] << " " << svm.w_ret[2] << " " << svm.b_ret << endl;
    out1 << "set terminal postscript eps enhanced color\n";
    out1 << "f(x)=(" << svm.w_ret[1] << "*x+" << svm.b_ret << ")/(-1*" << svm.w_ret[2] << ")\n";
    out1 << "g(x)=(" << svm.w_ret[1] << "*x+1+" << svm.b_ret << ")/(-1*" << svm.w_ret[2] << ")\n";
    out1 << "h(x)=(" << svm.w_ret[1] << "*x-1+" << svm.b_ret << ")/(-1*" << svm.w_ret[2] << ")\n";
    out1 << "set output 'svm-hardmargin.eps'\n";
    out1 << "unset key\n";
    out1 << "plot 'misc-files/svm-hardmargin.data' u 1:2,'misc-files/svm-hardmargin.data' u 3:4,f(x) lt 1 linecolor rgb 'black',g(x) lt 2 linecolor rgb 'black',h(x) lt 2 linecolor rgb 'black'\n";
  }
  cout << "\nSVMSoftMargin:" << endl;
  {
    SVMSoftMargin svm;
    ofstream out1("misc-files/svm-softmargin.plot");
    svm.n = 14;
    svm.d = 2;
    svm.alpha = 1. / 6;
    for (int i = 1; i <= 4; i++) {
      svm.P[i][1] = 10.*rand() / RAND_MAX - 5;
      svm.P[i][2] = 2.*rand() / RAND_MAX - 1;
      svm.N[i][1] = 10.*rand() / RAND_MAX - 5;
      svm.N[i][2] = 2.*rand() / RAND_MAX - 1;
    }
    for (int i = 5; i <= svm.n; i++) {
      svm.P[i][1] = 10.*rand() / RAND_MAX - 5;
      svm.P[i][2] = 7.*rand() / RAND_MAX + 3;
      svm.N[i][1] = 10.*rand() / RAND_MAX - 5;
      svm.N[i][2] = -7.*rand() / RAND_MAX - 3;
    }
    if (svm.solve()) {
      cout << "successful SVM solve" << endl;
    }
    cout << "SVM soln: " << svm.objValue << endl;
    cout << svm.w_ret[1] << " " << svm.w_ret[2] << " " << svm.b_ret << endl;
    ofstream out2("misc-files/svm-softmargin.pos");
    ofstream out3("misc-files/svm-softmargin.neg");
    ofstream out4("misc-files/svm-softmargin.igpos");
    ofstream out5("misc-files/svm-softmargin.igneg");
    bool igpos = false;
    bool igneg = false;
    for (int i = 1; i <= svm.n; i++) {
      if (!svm.Y_ret[i]) {
        out3 << svm.N[i][1] << " " << svm.N[i][2] << endl;
      } else {
        out5 << svm.N[i][1] << " " << svm.N[i][2] << endl;
        igneg = true;
      }
      if (!svm.X_ret[i]) {
        out2 << svm.P[i][1] << " " << svm.P[i][2] << endl;
      } else {
        out4 << svm.P[i][1] << " " << svm.P[i][2] << endl;
        igpos = true;
      }
    }
    out1 << "set terminal postscript eps enhanced color\n";
    out1 << "f(x)=(" << svm.w_ret[1] << "*x+" << svm.b_ret << ")/(-1*" << svm.w_ret[2] << ")\n";
    out1 << "g(x)=(" << svm.w_ret[1] << "*x+1+" << svm.b_ret << ")/(-1*" << svm.w_ret[2] << ")\n";
    out1 << "h(x)=(" << svm.w_ret[1] << "*x-1+" << svm.b_ret << ")/(-1*" << svm.w_ret[2] << ")\n";
    out1 << "set output 'svm-softmargin.eps'\n";
    out1 << "unset key\n";
    out1 << "plot 'misc-files/svm-softmargin.pos' u 1:2:(.1) linecolor rgb 'red' w circles fill solid,'misc-files/svm-softmargin.neg' u 1:2:(.1) linecolor rgb 'blue' w circles fill solid,";
    if (igpos) {
      out1 << "'misc-files/svm-softmargin.igpos' u 1:2:(.1) linecolor rgb 'red' w circles,";
    }
    if (igneg) {
      out1 << "'misc-files/svm-softmargin.igneg' u 1:2:(.1) linecolor rgb 'blue' w circles,";
    }
    out1 << "f(x) lt 1 linecolor rgb 'black',g(x) lt 2 linecolor rgb 'black',h(x) lt 2 linecolor rgb 'black'\n";
  }
}
