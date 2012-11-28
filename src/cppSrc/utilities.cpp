#include<utilities.hpp>

set<string> globalTemporaries;
map<string,int> temporaryIdentifiers;
string convert(int x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
string temporary(string val) {
    string temp=val+convert(temporaryIdentifiers[val]++);
    globalTemporaries.insert(temp);
    return temp;
}
set<string> getTemporaries() {
    return globalTemporaries;
}


SetType::SetType(string a) {
    name=a;
    isReturn=false;
    isVariable=false;
    isTemporary=false;
    isConstant=false;
    isNumber=false;
    isSet=true;
    isTuple=false;
    isInteger=false;
}
string SetType::getCPLEXType() {
    string type="";
    Type* base=setPaths.begin()->second.front().front();
    int length=setPaths.begin()->first;
    if(base->isTuple) {
        for(int i=0;i<length;i++) {
            type+="set<";
        }
        type+="TODOTUPLES_";
        for(int i=0;i<length;i++) {
            type+=",set"+convert(i)+"cmp_TODOTUPLES_>";
        }
    } else {
        for(int i=0;i<length;i++) {
            type+="set<";
        }
        type+="int";
        for(int i=0;i<length;i++) {
            if(i==0) {
                type+=">";
            } else {
                type+=",set"+convert(i)+"comp>";
            }
        }
    }
    return type;
}
bool SetType::errorCheck() {
    bool ret=false;
    if(isTemporary&&isConstant) {
        cout << "ERROR: " << name << " is used as a constant and temporary" << endl;
        ret=true;
    }
    if(isTemporary&&isVariable) {
        cout << "ERROR: " << name << " is used as a variable and temporary" << endl;
        ret=true;
    }
    if(setPaths.size()>1) {
        /* set<int> lines;
        string prev;
        prev="";
        for(list<string>::iterator i=x.begin();i!=x.end();i++) {
            if(prev!="") {
                lines.insert(graph[prev][*i].loc);
            }
            prev=*i;
        }
        prev="";
        for(list<string>::iterator i=foundPaths[x.back()].begin();i!=foundPaths[x.back()].end();i++) {
            if(prev!="") {
                lines.insert(graph[prev][*i].loc);
            }
            prev=*i;
        }
        cout << "ERROR: inconsistent types for element " << x.back() << " on line";
        if(lines.size()>1) {
            cout << "s";
        }
        for(set<int>::iterator i=lines.begin();i!=lines.end();i++) {
            cout << " " << *i;
        }
        cout << endl;*/
        cout << "ERROR: inconsistent usage of element " << name << endl;
        for(map<int,list<list<SetType*> > >::iterator i=setPaths.begin();i!=setPaths.end();i++) {
            cout << i->first << ":";
            for(list<SetType*>::iterator j=i->second.front().begin();j!=i->second.front().end();j++) {
                cout << " " << (*j)->name;
            }
            cout << endl;
        }
        ret=true;
    }
    return ret;
}

NumberType::NumberType(string a) {
    name=a;
    isReturn=false;
    isTemporary=false;
    isVariable=false;
    isConstant=false;
    isNumber=true;
    isSet=false;
    isTuple=false;
    isInteger=false;
}
string NumberType::getCPLEXType() {
    string pre="";
    list<SetType*> example=indices.front();
    for(list<SetType*>::iterator j=example.begin();j!=example.end();j++) {
        if((*j)->setPaths.begin()->first==0) {
            pre+="map<int,";
        }
        if((*j)->setPaths.begin()->first==1) {
            pre+="map<set<int>,";
        }
    }
    string post="";
    for(list<SetType*>::reverse_iterator j=example.rbegin();j!=example.rend();j++) {
        if((*j)->setPaths.begin()->first==0) {
            if(post[post.size()-1]=='>') {
                post+=" ";
            }
            post+=">";
        }
        if((*j)->setPaths.begin()->first==1) {
            post+=",set1comp>";
        }
    }
    if(isVariable) {
        if(isInteger) {
            return pre+"MyIloIntVar"+post;
        } else {
            return pre+"MyIloNumVar"+post;
        }
    } else {
        if(isInteger) {
            return pre+"int"+post;
        } else {
            return pre+"double"+post;
        }
    }
    return "uh oh !?!?!?!?";
}
bool NumberType::errorCheck() {
    bool ret=false;
    bool A=true;
    bool B=true;
    if(isTemporary&&isConstant) {
        cout << "ERROR: " << name << " is used as a constant and temporary" << endl;
        ret=true;
    }
    if(isTemporary&&isVariable) {
        cout << "ERROR: " << name << " is used as a variable and temporary" << endl;
        ret=true;
    }
    if(indices.empty()) {
        cout << "ERROR: " << name << " no examples of indices for number??" << endl;
        return true;
    }
    list<SetType*> example=indices.front();
    //list<int>::iterator rs=mapTypeReasons[i->first].begin();
    for(list<list<SetType*> >::iterator j=indices.begin();j!=indices.end();j++) {
        bool different=false;
        if(j->size()!=example.size()) {
            different=true;
        } else {
            list<SetType*>::iterator kk=example.begin();
            for(list<SetType*>::iterator k=j->begin();k!=j->end();k++) {
                if(!((*k)->isSet)) {
                    if(A) {
                        cout << "ERROR: indice " << (*k)->name << " of " << name << " is not an element" << endl;
                        ret=true;
                        A=false;
                    }
                }
                int depth1=(*k)->setPaths.begin()->first;
                int depth2=(*kk)->setPaths.begin()->first;
                if(depth1!=depth2) {
                    different=true;
                }
                kk++;
            }
        }
        if(different) {
            /*set<int> lines;
            lines.insert(mapTypeReasons[i->first].front());
            cout << "ERROR: inconsistent use of indices for "+stripVar(i->first)+" on line";
            int first=mapTypeReasons[i->first].front();
            if(*rs!=first) {
                cout << "s " << first;
            }
            cout << " " << *rs << endl;*/
            if(B) {
                cout << "ERROR: inconsistent use of indices for " << name << endl;
                ret=true;
                B=false;
            }
        }
    }
    return ret;
}

