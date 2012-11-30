#include<set>
#include<iostream>
#include<vector>
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
struct tupleintint {
    int x1;
    set<int> x2;
};
struct tupleinstintcomp {
    bool operator() (const tupleintint& lhs,const tupleintint& rhs) const {
        if(lhs.x1!=rhs.x1) {
            return lhs.x1<rhs.x1;
        }
        if(lhs.x2!=rhs.x2) {
            return lhs.x2<rhs.x2;
        }
        return 0;
    }
};
struct tuple_int_set1 {
    int e0;
    set<int> e1;
};
struct set0comp_tuple_int_set1 {
    bool operator() (const tuple_int_set1& lhs,const tuple_int_set1& rhs) const {
        if(lhs.e0!=rhs.e0) {
            return lhs.e0<rhs.e0;
        }
        if(set1comp()(lhs.e1,rhs.e1)==true||set1comp()(lhs.e1,rhs.e1)==true) {
            return set1comp()(lhs.e1,rhs.e1);
        }
        return 0;
    }
};
struct tuple_int_int {
    int e0;
    int e1;
};
struct set0comp_tuple_int_int {
    bool operator() (const tuple_int_int& lhs,const tuple_int_int& rhs) const {
        if(lhs.e0!=rhs.e0) {
            return lhs.e0<rhs.e0;
        }
        if(lhs.e1!=rhs.e1) {
            return lhs.e1<rhs.e1;
        }
        return 0;
    }
};
/*set<set<int>,set1comp> powerset(set<int> x) {
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
}*/
class Thing;

struct ThingCompare {
    bool operator() (const Thing& lhs,const Thing& rhs) const;
};


class Thing {
    public:
    bool isSet;
    bool isTuple;
    bool isInteger;
    set<Thing,ThingCompare> setThing;
    vector<Thing> tupleThing;
    int intThing;
    Thing(const int& a) {
        isTuple=false;
        isInteger=true;
        isSet=false;
        intThing=a;
    }
    Thing(const set<Thing,ThingCompare>& a) {
        isTuple=false;
        isInteger=false;
        isSet=true;
        setThing=a;
    }
    Thing(const vector<Thing>& a) {
        isTuple=true;
        isInteger=false;
        isSet=false;
        tupleThing=a;
    }
    Thing() {
        isTuple=false;
        isInteger=false;
        isSet=true;
    }
    Thing(const set<int>& a) {
        isTuple=false;
        isInteger=false;
        isSet=true;
        for(set<int>::const_iterator i=a.begin();i!=a.end();i++) {
            Thing a=*i;
            setThing.insert(a);
        }
    }
    Thing& operator=(const vector<Thing>& a) {
        isTuple=true;
        isInteger=false;
        isSet=false;
        tupleThing=a;
        return *this;
    }
    Thing& operator=(const int& a) {
        isTuple=false;
        isInteger=true;
        isSet=false;
        intThing=a;
        return *this;
    }
    Thing& operator=(const set<int>& a) {
        isTuple=false;
        isInteger=false;
        isSet=true;
        for(set<int>::const_iterator i=a.begin();i!=a.end();i++) {
            Thing a=*i;
            setThing.insert(a);
        }
        return *this;
    }
    Thing& operator=(const set<Thing,ThingCompare>& a) {
        isTuple=false;
        isInteger=false;
        isSet=true;
        setThing=a;
        return *this;
    }
    operator int() const {
        return intThing;
    }
    operator vector<Thing>() const {
        return tupleThing;
    }
    operator set<Thing,ThingCompare>() const {
        return setThing;
    }
    void print() const {
        if(isInteger) {
            cout << intThing;
        }
        if(isSet) {
            cout << "{";
            for(set<Thing,ThingCompare>::const_iterator i=setThing.begin();i!=setThing.end();i++) {
                if(i!=setThing.begin()) {
                    cout << ",";
                }
                Thing j=*i;
                j.print();
            }
            cout << "}";
        }
        if(isTuple) {
            cout << "(";
            for(int i=0;i<tupleThing.size();i++) {
                if(i>0) {
                    cout << ",";
                }
                tupleThing[i].print();
            }
            cout << ")";
        }
    }
};
bool ThingCompare::operator() (const Thing& lhs,const Thing& rhs) const {
    bool ret=false;
    if(lhs.isTuple&&rhs.isTuple) {
        if(lhs.tupleThing.size()!=rhs.tupleThing.size()) {
            cout << "tuples wrong size? problem somewhere" << endl;
            ret=lhs.tupleThing.size()<rhs.tupleThing.size();
        } else {
            for(int i=0;i<lhs.tupleThing.size();i++) {
                if(ThingCompare()(lhs.tupleThing[i],rhs.tupleThing[i])==true||ThingCompare()(lhs.tupleThing[i],rhs.tupleThing[i])==true) {
                    ret=ThingCompare()(lhs.tupleThing[i],rhs.tupleThing[i]);
                    break;
                }
            }
        }
    } else if(lhs.isSet&&rhs.isSet) {
        if(lhs.setThing.size()!=rhs.setThing.size()) {
            ret=lhs.setThing.size()<rhs.setThing.size();
        } else {
            set<Thing,ThingCompare>::iterator i,j;
            i=lhs.setThing.begin();
            j=rhs.setThing.begin();
            while(i!=lhs.setThing.end()) {
                if(ThingCompare()(*i,*j)==true||ThingCompare()(*j,*i)==true) {
                    ret=ThingCompare()(*i,*j);
                    break;
                }
                i++;
                j++;
            }
        }
    } else if(lhs.isInteger&&rhs.isInteger) {
        ret=lhs.intThing<rhs.intThing;
    } else {
        cout << "real problem" << endl;
        exit(1);
    }
    if(false) {
        lhs.print();
        if(ret) {
            cout << " < ";
        } else {
            cout << " >= ";
        }
        rhs.print();
        cout << endl;
    }
    return ret;
}
set<Thing,ThingCompare> thingConversion(set<int> a) {
    set<Thing,ThingCompare> x;
    for(set<int>::iterator i=a.begin();i!=a.end();i++) {
        Thing y=*i;
        x.insert(y);
    }
    return x;
}
set<Thing,ThingCompare> powerset(set<Thing,ThingCompare> x) {
    set<Thing,ThingCompare> pset;
    for(int i=0; i<pow(2,x.size()); i++) {
        set<Thing,ThingCompare> s;
        set<Thing,ThingCompare>::iterator k=x.begin();
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
