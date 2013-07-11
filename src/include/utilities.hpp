#include<sstream>
#include<vector>
#include<iostream>
#include<list>
#include<map>
#include<set>
#ifndef MBOLUTILITIES
#define MBOLUTILITIES
using namespace std;

string convert(int x);
string temporary(string val="t");
set<string> getTemporaries();

class Type {
    public:
    string name;
    bool isTemporary;
    bool isVariable;
    bool isConstant;
    bool isInteger;
    bool isSet;
    bool isNumber;
    bool isTuple;
    bool isReturn;
    Type() {
    }
    virtual string getCPLEXType() {
    }
    virtual bool errorCheck() {
    }
    virtual string print(bool plural=false) {
    }
};

class SetType : public Type {
    public:
    map<int,list<list<SetType*> > > setPaths;
    vector<SetType*> tupleIndices;
    SetType(string a);
    string getCPLEXType();
    bool errorCheck();
    string print(bool plural=false);
};

class NumberType : public Type {
    public:
    list<list<SetType*> > indices;
    NumberType(string a);
    string getCPLEXType();
    bool errorCheck();
    string print(bool plural=false);
};


#endif
