#include<sstream>
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
};

class SetType : public Type {
    public:
    map<int,list<list<SetType*> > > setPaths;
    SetType(string a);
    string getCPLEXType();
    bool errorCheck();
};

class NumberType : public Type {
    public:
    list<list<SetType*> > indices;
    NumberType(string a);
    string getCPLEXType();
    bool errorCheck();
};

#endif
