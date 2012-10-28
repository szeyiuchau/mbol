#include<set>
#include<map>
#include<ilcplex/ilocplex.h>
using namespace std;
#ifndef CPLEX_SETUP_STUFF
#define CPLEX_SETUP_STUFF
IloEnv g_env;
class MyIloIntVar : public IloIntVar {
    public:
MyIloIntVar() : IloIntVar(g_env) {}
};
class MyIloNumVar : public IloNumVar {
    public:
MyIloNumVar() : IloNumVar(g_env,-1*IloInfinity,IloInfinity) {}
};
struct set1comp {
    bool operator() (const set<int>& lhs,const set<int>& rhs) const {
        if(lhs.size()!=rhs.size()) {
            return lhs.size()<rhs.size();
        }
        set<int>::iterator i,j;
        i=lhs.begin();
        j=rhs.begin();
        while(i!=lhs.end()) {
            if(*i!=*j) {
                return *i<*j;
            }
            i++;
            j++;
        }
        return 0;
    }
};
struct set2comp {
    bool operator() (const set<set<int>,set1comp>& lhs,const set<set<int>,set1comp>& rhs) const {
        if(lhs.size()!=rhs.size()) {
            return lhs.size()<rhs.size();
        }
        set<set<int>,set1comp>::iterator i,j;
        i=lhs.begin();
        j=rhs.begin();
        while(i!=lhs.end()) {
            if(set1comp()(*i,*j)==true||set1comp()(*j,*i)==true) {
                return set1comp()(*i,*j);
            }
            i++;
            j++;
        }
        return 0;
    }
};
set<set<int>,set1comp> powerset(set<int> x) {
    set<set<int>,set1comp> pset;
    for(int i=0; i<pow(2,x.size()); i++) {
        set<int> s;
        set<int>::iterator k=x.begin();
        for(int j=0; j<x.size(); j++) {
            if(((i >> j)&1)==1) {
                s.insert(*k);
            }
            k++;
        }
        pset.insert(s);
    }
    return pset;
}
#endif

