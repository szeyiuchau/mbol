#include<set>
#include<assert.h>
#include<list>
#include<iostream>
#include<vector>
#include<fstream>
#include<iostream>
#include<math.h>
#include<map>
#include<sstream>
using namespace std;
#ifndef CPLEX_SETUP_STUFF
#define CPLEX_SETUP_STUFF
#include<lex.yy.c>
string convert(double x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
string convert(int x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
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
class Element;

struct ElementCompare {
    bool operator() (const Element& lhs,const Element& rhs) const;
};


class Element {
    public:
    bool isSet;
    bool isTuple;
    bool isInteger;
    set<Element,ElementCompare> setElement;
    vector<Element> tupleElement;
    int intElement;
    Element(const int& a) {
        isTuple=false;
        isInteger=true;
        isSet=false;
        intElement=a;
    }
    Element(const set<Element,ElementCompare>& a) {
        isTuple=false;
        isInteger=false;
        isSet=true;
        setElement=a;
    }
    Element(const vector<Element>& a) {
        isTuple=true;
        isInteger=false;
        isSet=false;
        tupleElement=a;
    }
    Element() {
        isTuple=false;
        isInteger=false;
        isSet=true;
    }
    Element(const set<int>& a) {
        isTuple=false;
        isInteger=false;
        isSet=true;
        for(set<int>::const_iterator i=a.begin();i!=a.end();i++) {
            Element a=*i;
            setElement.insert(a);
        }
    }
    Element& operator=(const vector<Element>& a) {
        isTuple=true;
        isInteger=false;
        isSet=false;
        tupleElement=a;
        return *this;
    }
    Element& operator=(const int& a) {
        isTuple=false;
        isInteger=true;
        isSet=false;
        intElement=a;
        return *this;
    }
    Element& operator=(const set<int>& a) {
        isTuple=false;
        isInteger=false;
        isSet=true;
        for(set<int>::const_iterator i=a.begin();i!=a.end();i++) {
            Element a=*i;
            setElement.insert(a);
        }
        return *this;
    }
    Element& operator=(const set<Element,ElementCompare>& a) {
        isTuple=false;
        isInteger=false;
        isSet=true;
        setElement=a;
        return *this;
    }
    operator int() const {
        return intElement;
    }
    operator vector<Element>() const {
        return tupleElement;
    }
    operator set<Element,ElementCompare>() const {
        return setElement;
    }
    string print() const {
        string x="";
        if(isInteger) {
            x+=convert(intElement);
        }
        if(isSet) {
            x+="{";
            for(set<Element,ElementCompare>::const_iterator i=setElement.begin();i!=setElement.end();i++) {
                if(i!=setElement.begin()) {
                    x+=",";
                }
                Element j=*i;
                x+=j.print();
            }
            x+="}";
        }
        if(isTuple) {
            x+="(";
            for(int i=0;i<tupleElement.size();i++) {
                if(i>0) {
                    x+=",";
                }
                x+=tupleElement[i].print();
            }
            x+=")";
        }
        return x;
    }
};
bool ElementCompare::operator() (const Element& lhs,const Element& rhs) const {
    bool ret=false;
    if(lhs.isTuple&&rhs.isTuple) {
        if(lhs.tupleElement.size()!=rhs.tupleElement.size()) {
            cout << "tuples wrong size? problem somewhere" << endl;
            ret=lhs.tupleElement.size()<rhs.tupleElement.size();
        } else {
            for(int i=0;i<lhs.tupleElement.size();i++) {
                if(ElementCompare()(lhs.tupleElement[i],rhs.tupleElement[i])==true||ElementCompare()(lhs.tupleElement[i],rhs.tupleElement[i])==true) {
                    ret=ElementCompare()(lhs.tupleElement[i],rhs.tupleElement[i]);
                    break;
                }
            }
        }
    } else if(lhs.isSet&&rhs.isSet) {
        if(lhs.setElement.size()!=rhs.setElement.size()) {
            ret=lhs.setElement.size()<rhs.setElement.size();
        } else {
            set<Element,ElementCompare>::iterator i,j;
            i=lhs.setElement.begin();
            j=rhs.setElement.begin();
            while(i!=lhs.setElement.end()) {
                if(ElementCompare()(*i,*j)==true||ElementCompare()(*j,*i)==true) {
                    ret=ElementCompare()(*i,*j);
                    break;
                }
                i++;
                j++;
            }
        }
    } else if(lhs.isInteger&&rhs.isInteger) {
        ret=lhs.intElement<rhs.intElement;
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
set<Element,ElementCompare> thingConversion(set<int> a) {
    set<Element,ElementCompare> x;
    for(set<int>::iterator i=a.begin();i!=a.end();i++) {
        Element y=*i;
        x.insert(y);
    }
    return x;
}
set<Element,ElementCompare> powerset(set<Element,ElementCompare> x) {
    set<Element,ElementCompare> pset;
    for(int i=0; i<pow(2,x.size()); i++) {
        set<Element,ElementCompare> s;
        set<Element,ElementCompare>::iterator k=x.begin();
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
Element getElement(list<string>& x);
vector<Element> readTupleElement(list<string>& x) {
    vector<Element> y;
    x.pop_front();
    while(x.front()!=")") {
        if(x.front()==",") {
            x.pop_front();
        }
        y.push_back(getElement(x));
    }
    x.pop_front();
    return y;
}
Element readIntegerElement(list<string>& x) {
    Element a=(atoi(x.front().c_str()));
    x.pop_front();
    return a;
}
set<Element,ElementCompare> readSetElement(list<string>& x) {
    set<Element,ElementCompare> y;
    x.pop_front();
    while(x.front()!="}") {
        if(x.front()==",") {
            x.pop_front();
        }
        y.insert(getElement(x));
    }
    x.pop_front();
    return y;
}
Element getElement(list<string>& x) {
    Element y;
    if(x.front()=="{") {
        y=readSetElement(x);
    } else if(x.front()=="(") {
        y=readTupleElement(x);
    } else {
        y=readIntegerElement(x);
    }
    return y;
}
bool isVariable(string x) {
    int y=(int)x[0];
    return (y>=97&&y<=122)||(y>=65&&y<=90);
}

map<string,string> variableConversion;
//#define CPLEX

#ifdef CPLEX

#include<ilcplex/ilocplex.h>

typedef IloExpr MBOLExpr;
typedef IloEnv MBOLEnv;
//typedef IloCplex MBOLSolver;
MBOLEnv g_env;
class MBOLModel : public IloModel {
    public:
    MBOLModel() : IloModel(g_env) {
    }
    void maximize(MBOLExpr a) {
        IloObjective obj=IloMaximize(g_env,a);
        add(obj);
    }
    void minimize(MBOLExpr a) {
        IloObjective obj=IloMinimize(g_env,a);
        add(obj);
    }
};
class MBOLSolver : public IloCplex {
    public:
    MBOLSolver() : IloCplex() {
    }
    MBOLSolver(MBOLModel a) : IloCplex(a) {
    }
    void quiet() {
        setOut(g_env.getNullStream());
    }
};
class MBOLIntVar : public IloIntVar {
    public:
    string name;
    MBOLIntVar() : IloIntVar(g_env) {
    }
};
class MBOLNumVar : public IloNumVar {
    public:
    string name;
    MBOLNumVar() : IloNumVar(g_env,-1*IloInfinity,IloInfinity) {
    }
};

#else

set<string> MBOLIntegers;
int MBOLIndexCounter=0;

class MBOLEnv {
    public:
    MBOLEnv() {
    }
    void end() {
    }
};

MBOLEnv g_env;

class MBOLExpr {
    public:
    string name;
enum EXPR_TYPE {EXPR,INT,NUM};
    EXPR_TYPE type;
    double constant;
    map<string,double> expressions;
    MBOLExpr() {
        type=EXPR;
        constant=0;
    }
    MBOLExpr(MBOLEnv a) {
        constant=0;
    }
    MBOLExpr& operator=(const int& a) {
        constant=a;
        return *this;
    }
    MBOLExpr& operator=(const double& a) {
        constant=a;
        return *this;
    }
    MBOLExpr(const double& a) {
        constant=a;
    }
    MBOLExpr& operator=(const MBOLExpr& a) {
        constant=a.constant;
        expressions=a.expressions;
        return *this;
    }
    operator string() const {
        return "just makin stuff compile";
    }
    void simplify() {
        list<string> toRemove;
        for(map<string,double>::const_iterator i=expressions.begin();i!=expressions.end();i++) {
            if(i->second==0) {
                toRemove.push_back(i->first);
            }
        }
        for(list<string>::iterator i=toRemove.begin();i!=toRemove.end();i++) {
            expressions.erase(*i);
        }
    }
    void print() {
        cout << constant;
        for(map<string,double>::const_iterator i=expressions.begin();i!=expressions.end();i++) {
            cout << "+" << i->second << "*" << i->first;
        }
    }
};

MBOLExpr operator*(const MBOLExpr& a,const MBOLExpr& b) {
    MBOLExpr x;
    if(!a.expressions.empty()&&!b.expressions.empty()) {
        cout << "nonlinear" << endl;
    }
    x.constant=a.constant*b.constant;
    for(map<string,double>::const_iterator i=a.expressions.begin();i!=a.expressions.end();i++) {
        x.expressions[i->first]=i->second*b.constant;
    }
    for(map<string,double>::const_iterator i=b.expressions.begin();i!=b.expressions.end();i++) {
        x.expressions[i->first]+=i->second*a.constant;
    }
    x.simplify();
    return x;
}
MBOLExpr operator/(const MBOLExpr& a,const MBOLExpr& b) {
    MBOLExpr x;
    if(!b.expressions.empty()) {
        cout << "nonlinear" << endl;
    }
    x.constant=a.constant/b.constant;
    for(map<string,double>::const_iterator i=a.expressions.begin();i!=a.expressions.end();i++) {
        x.expressions[i->first]=i->second/b.constant;
    }
    x.simplify();
    return x;
}

MBOLExpr operator+(const MBOLExpr& a,const MBOLExpr& b) {
    MBOLExpr x;
    x.constant=a.constant+b.constant;
    for(map<string,double>::const_iterator i=a.expressions.begin();i!=a.expressions.end();i++) {
        x.expressions[i->first]=i->second;
    }
    for(map<string,double>::const_iterator i=b.expressions.begin();i!=b.expressions.end();i++) {
        x.expressions[i->first]+=i->second;
    }
    x.simplify();
    return x;
}
MBOLExpr operator-(const MBOLExpr& a,const MBOLExpr& b) {
    MBOLExpr x;
    MBOLExpr temp=-1;
    x=a+temp*b;
    return x;
}
MBOLExpr operator-(const MBOLExpr& a,const double& b) {
    MBOLExpr x;
    MBOLExpr temp=b;
    x=a-temp;
    return x;
}
MBOLExpr operator+(const MBOLExpr& a,const double& b) {
    MBOLExpr x;
    MBOLExpr temp=b;
    x=a+temp;
    return x;
}
MBOLExpr operator*(const MBOLExpr& a,const double& b) {
    MBOLExpr x;
    MBOLExpr temp=b;
    x=a*temp;
    return x;
}
MBOLExpr operator/(const MBOLExpr& a,const double& b) {
    MBOLExpr x;
    MBOLExpr temp=b;
    x=a/temp;
    return x;
}
MBOLExpr operator-(const double& a,const MBOLExpr& b) {
    return (b-a)*(-1);
}
MBOLExpr operator*(const double& a,const MBOLExpr& b) {
    return b*a;
}
MBOLExpr operator+(const double& a,const MBOLExpr& b) {
    return b+a;
}
MBOLExpr operator/(const double& a,const MBOLExpr& b) {
    MBOLExpr x;
    MBOLExpr temp=a;
    x=temp/b;
    return x;
}

class MBOLEquation {
    public:
    MBOLExpr lhs;
    MBOLExpr rhs;
    string type;
    MBOLEquation(MBOLExpr a,string b,MBOLExpr c) {
        rhs.constant=c.constant-a.constant;
        a.constant=0;
        c.constant=0;
        lhs=a-c;
        type=b;
    }
    void print() {
        lhs.print();
        cout << type;
        rhs.print();
    }
};

MBOLEquation operator==(const MBOLExpr& a,const MBOLExpr& b) {
    MBOLEquation x(a,"E",b);
    return x;
}
MBOLEquation operator<=(const MBOLExpr& a,const MBOLExpr& b) {
    MBOLEquation x(a,"L",b);
    return x;
}
MBOLEquation operator>=(const MBOLExpr& a,const MBOLExpr& b) {
    MBOLEquation x(a,"G",b);
    return x;
}

class MBOLModel {
    public:
    string type;
    MBOLExpr obj;
    list<MBOLEquation> constraints;
    MBOLModel() {
    }
    void add(MBOLEquation a) {
        constraints.push_back(a);
    }
    void maximize(MBOLExpr a) {
        obj=a*(-1);
        type="MAX";
    }
    void minimize(MBOLExpr a) {
        obj=a;
        type="MIN";
    }
    void print() {
        obj.print();
        cout << endl;
        for(list<MBOLEquation>::iterator i=constraints.begin();i!=constraints.end();i++) {
            i->print();
            cout << endl;
        }
    }
};
int problem=0;

class MBOLSolver {
    public:
    double objective;
    map<string,string> results;
    string mps;
double multiplier;
    MBOLSolver() {
    }
    MBOLSolver(MBOLModel a) {
        mps="NAME THING\n";
if(a.type=="MAX") {
multiplier=-1;
} else {
multiplier=1;
}
        mps+="OBJSENSE\n";
        mps+=" "+a.type+"\n";
        mps+="ROWS\n";
        mps+=" N  OBJ\n";
        int num=0;
        for(list<MBOLEquation>::iterator i=a.constraints.begin();i!=a.constraints.end();i++) {
            mps+=" "+i->type+"  CONSTRAINT"+convert(num++)+"\n";
        }
        mps+="COLUMNS\n";
        set<string> active;
        for(int i=0;i<MBOLIndexCounter;i++) {
            string var="t"+convert(i);
            num=0;
            for(list<MBOLEquation>::iterator i=a.constraints.begin();i!=a.constraints.end();i++) {
                string constraint="CONSTRAINT"+convert(num++);
                if(i->lhs.expressions.count(var)&&i->lhs.expressions[var]) {
                    active.insert(var);
if(variableConversion.count(var)==0) {
cout << var << endl;
}
                    mps+="    "+variableConversion[var]+" "+constraint+" "+convert(i->lhs.expressions[var])+"\n"; //
                }
            }
            if(a.obj.expressions.count(var)) {
if(variableConversion.count(var)==0) {
cout << var << endl;
}
                mps+="    "+variableConversion[var]+" OBJ "+convert(a.obj.expressions[var])+"\n"; //
            }
        }
        mps+="RHS\n";
        num=0;
        for(list<MBOLEquation>::iterator i=a.constraints.begin();i!=a.constraints.end();i++) {
            string constraint="CONSTRAINT"+convert(num++);
            mps+="    RHS1 "+constraint+" "+convert(i->rhs.constant)+"\n";
        }
        mps+="BOUNDS\n";
        for(set<string>::iterator i=MBOLIntegers.begin();i!=MBOLIntegers.end();i++) {
            if(active.count(*i)) {
assert(variableConversion.count(*i)==1);
                mps+=" LI BOUND "+variableConversion[(*i)]+" 0\n"; //
            }
        }
        mps+="ENDATA\n";
    }
    void solve() {
        ofstream out("/tmp/problem.mps");
        out << mps << endl;
        out.close();
        system("symphony -F /tmp/problem.mps > /tmp/solution.txt");
        ifstream in("/tmp/solution.txt");
        string dummy;
        string prev="";
        while(in >> dummy) {
            if(dummy=="Cost:"&&prev=="Solution") {
                break;
            }
            prev=dummy;
        }
        in >> objective;
        for(int i=0;i<11;i++) {
            in >> dummy;
        }
        string key,val;
        while(in >> key >> val) {
            results[key]=val;
        }
        in.close();
    }
    void quiet() {
    }
    double getValue(MBOLExpr a) {
        if(a.type==MBOLExpr::INT) {
            return atof(results[variableConversion[a.name]].c_str());
        } else if(a.type==MBOLExpr::NUM) {
            return atof(results[variableConversion[a.name]].c_str());
        } else if(a.type==MBOLExpr::EXPR) {
            return multiplier*objective;
        } else {
            assert(0);
        }
    }
};

class MBOLIntVar : public MBOLExpr {
    public:
    MBOLIntVar() {
        type=INT;
        string val="t"+convert(MBOLIndexCounter++);
        MBOLIntegers.insert(val);
        name=val;
        expressions[val]=1;
    }
};

class MBOLNumVar : public MBOLExpr {
    public:
    MBOLNumVar() {
        type=NUM;
        string val="t"+convert(MBOLIndexCounter++);
        name=val;
        expressions[val]=1;
    }
};

#endif

#endif
