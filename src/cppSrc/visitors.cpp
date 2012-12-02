#include<visitors.hpp>
#include<classes.hpp>
#include<utilities.hpp>

MbolElementVisitorPrinter::MbolElementVisitorPrinter() {
}
void MbolElementVisitorPrinter::visit(const ElementExpression* elementExpression) {
    cout << "element expression" << endl;
}
void MbolElementVisitorPrinter::visit(const Qualifier* qualifier) {
    cout << "qualifier" << endl;
}
void MbolElementVisitorPrinter::specialVisit(const SetCreator* setCreator) {
    cout << "set creator" << endl;
}
void MbolElementVisitorPrinter::visit(const SetCreator* setCreator) {
    cout << "set creator" << endl;
}
void MbolElementVisitorPrinter::visit(const Equation* equation) {
    cout << "equation" << endl;
}
void MbolElementVisitorPrinter::visit(const VariableMap* variableMap) {
    cout << "variablemap" << endl;
}
void MbolElementVisitorPrinter::specialVisit(const Sum* sum) {
    cout << "sum" << endl;
}
void MbolElementVisitorPrinter::visit(const Sum* sum) {
    cout << "sum" << endl;
}
void MbolElementVisitorPrinter::visit(const NumberExpression* numberExpression) {
    cout << "numberexpression" << endl;
}
void MbolElementVisitorPrinter::visit(const Objective* objective) {
    cout << "objective" << endl;
}
void MbolElementVisitorPrinter::visit(const ElementSet* elementSet) {
    cout << "elementset" << endl;
}
void MbolElementVisitorPrinter::visit(const Fraction* fraction) {
    cout << "fraction" << endl;
}
void MbolElementVisitorPrinter::visit(const SetSize* setSize) {
    cout << "setsize" << endl;
}
void MbolElementVisitorPrinter::visit(const ElementNumbers* elementNumbers) {
    cout << "elementnumbers" << endl;
}
void MbolElementVisitorPrinter::visit(const Constraint* constraint) {
    cout << "constraint" << endl;
}


void MbolElementVisitorCPLEX::specialVisit(const Program* program) {
    
    // start making all the code
    code="#include<set>\n#include<map>\n#include<ilcplex/ilocplex.h>\n#include<mbol.hpp>\nusing namespace std;\n#ifndef MBOL_"+className+"\n#define MBOL_"+className+"\nclass "+className+" {\npublic:\nbool init();\nbool solve();\n"+className+"();\n~"+className+"();\nbool hasInitialized;\nIloCplex cplex;\nIloEnv env;\ndouble objValue;\nIloExpr objExp;\n";
    
    // create struct for returning variables 
    /*
    code+="// Variable results\n";
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isConstant) {
            code+=i->second->getCPLEXType()+" "+i->first+"_ret;\n";
        }
    }*/
    
    // making arguments which are constants in the program
    code+="// Constants in the program that you must initialize\n";
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isConstant) {
            code+=i->second->getCPLEXType()+" "+i->first+";\n";
        }
    }
    
    // declare CPLEX variables (actual variables in program)
    code+="// Variables used by the CPLEX program\n";
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isVariable) {
            code+=i->second->getCPLEXType()+" "+i->first+";\n";
        }
    }
    
    code+="// Variable results\n";
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isVariable) {
            string name=i->first+"_ret";
            if(i->second->isSet) {
                types[name]=new SetType(name);
                ((SetType*)types[name])->setPaths=((SetType*)i->second)->setPaths;
            }
            if(i->second->isNumber) {
                types[name]=new NumberType(name);
                ((NumberType*)types[name])->indices=((NumberType*)i->second)->indices;
                types[name]->isInteger=i->second->isInteger;
            }
            types[name]->isReturn=true;
            code+=types[name]->getCPLEXType()+" "+name+";\n";
        }
    }
    
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isConstant) {
            code+="void read_"+i->first+"();\n";
        }
    }
    
    code+="void readAll();\n";
    
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isVariable) {
            code+="void write_"+i->first+"();\n";
        }
    }
    
    code+="void writeObj();\n";
    
    code+="void writeAll();\n";
    
    code+="};\n#endif\n";
    code+=className+"::"+className+"() {\nhasInitialized=false;\n}\nbool "+className+"::init() {\n";
    code+="IloModel model(env);\ng_env=env;\ntry {\n";
    
    
    // take care of simple variables
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isVariable&&i->second->isNumber&&((NumberType*)i->second)->indices.front().size()==0) {
            if(i->second->isInteger) {
                code+="MyIloIntVar";
            } else {
                code+="MyIloNumVar";
            }
            code+=" temp"+i->first+";\n"+i->first+"=temp"+i->first+";\n";
        }
    }
    
    code+="IloExpr tempObj(env);\n";
    code+="objExp=tempObj;\n";
}    

void MbolElementVisitorCPLEX::visit(const Program* program) {
    code+="IloCplex tempCplex(model);\ncplex=tempCplex;\n";
    if(quiet) {
        code+="cplex.setOut(env.getNullStream());\n";
    }
    code+="}\ncatch(IloException& ex) {\ncout << ex << endl;\nreturn false;\n}\nhasInitialized=true;\nreturn true;\n}\n";
    
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isConstant) {
            code+="void "+className+"::read_"+i->first+"() {\n";
            code+="list<string> tokens=getTokens(\""+i->first+".var\");\n";
            if(i->second->isSet) {
                SetType* sType=(SetType*)i->second;
                if(sType->setPaths.begin()->first==0) {
                    code+=i->first+"=readIntegerThing(tokens);\n";
                } else {
                    code+=i->first+"=readSetThing(tokens);\n";
                }
            } else if(i->second->isNumber) {
                NumberType* nType=(NumberType*)i->second;
                code+="while(!tokens.empty()) {\n";
                list<SetType*> example=nType->indices.front();
                int num=0;
                for(list<SetType*>::iterator j=example.begin();j!=example.end();j++) {
                    if((*j)->setPaths.begin()->first==0) {
                        code+="int index"+convert(num++)+"=readIntegerThing(tokens);\n";
                    } else {
                        code+="set<Thing,ThingCompare> index"+convert(num++)+"=readSetThing(tokens);\n";
                    }
                }
                num=0;
                code+=i->first;
                for(list<SetType*>::iterator j=example.begin();j!=example.end();j++) {
                    code+="[index"+convert(num++)+"]";
                }
                code+="=atof(tokens.front().c_str());\n";
                code+="tokens.pop_front();\n";
                code+="}\n";
            }
            code+="}\n";
        }
    }
    
    code+="void "+className+"::readAll() {\n";
    
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isConstant) {
            code+="read_"+i->first+"();\n";
        }
    }
    
    code+="}\n";
    
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isVariable) {
            code+="void "+className+"::write_"+i->first+"() {\n";
            code+="ofstream out(\""+i->first+".var\");\n";
            NumberType* t=(NumberType*)i->second;
            list<SetType*> example=t->indices.front();
            int tVal=0;
            string prev=i->first;
            string indices="";
            for(int j=0;j<example.size();j++) {
                code+="for(";
                int temp=0;
                for(list<SetType*>::iterator k=example.begin();k!=example.end();k++) {
                    temp++;
                    if(temp>j) {
                        if((*k)->setPaths.begin()->first==0) {
                            code+="map<int,";
                        }
                        if((*k)->setPaths.begin()->first==1) {
                            code+="map<set<Thing,ThingCompare>,";
                        }
                    }
                }
                if(t->isInteger) {
                    code+="MyIloIntVar";
                } else {
                    code+="MyIloNumVar";
                }
                temp=example.size()-j;
                for(list<SetType*>::reverse_iterator k=example.rbegin();k!=example.rend();k++) {
                    temp--;
                    if(temp>=0) {
                        if((*k)->setPaths.begin()->first==0) {
                            if(code[code.size()-1]=='>') {
                                code+=" ";
                            }
                            code+=">";
                        }
                        if((*k)->setPaths.begin()->first==1) {
                            code+=",ThingCompare>";
                        }
                    }
                }
                code+="::iterator iter"+convert(tVal)+"="+prev+".begin();iter"+convert(tVal)+"!="+prev+".end();iter"+convert(tVal)+"++) {\n";
                indices+="Thing(iter"+convert(tVal)+"->first).print() << \" \" << ";
                prev="iter"+convert(tVal)+"->second";
                tVal++;
            }
            code+="out << "+indices+"cplex.getValue("+prev+") << endl;\n";
            for(list<SetType*>::iterator j=example.begin();j!=example.end();j++) {
                code+="}\n";
            }
            code+="}\n";
        }
    }
    
    code+="void "+className+"::writeObj() {\n";
    code+="ofstream out(\"obj.var\");\n";
    code+="out << objValue << endl;\n";
    code+="}\n";
    
    code+="void "+className+"::writeAll() {\n";
    
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isVariable) {
            code+="write_"+i->first+"();\n";
        }
code+="writeObj();\n";
    }
    
    code+="}\n";
    
    code+="bool "+className+"::solve() {\nif(!hasInitialized) {\ninit();\n}\nif(!hasInitialized) {\nreturn false;\n}\ntry{\ncplex.solve();\nobjValue=cplex.getValue(objExp);\n";
    
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isReturn) {
            NumberType* t=(NumberType*)i->second;
            list<SetType*> example=t->indices.front();
            int tVal=0;
            string prev=i->first.substr(0,i->first.size()-4);
            string indices="";
            for(int j=0;j<example.size();j++) {
                code+="for(";
                int temp=0;
                for(list<SetType*>::iterator k=example.begin();k!=example.end();k++) {
                    temp++;
                    if(temp>j) {
                        if((*k)->setPaths.begin()->first==0) {
                            code+="map<int,";
                        }
                        if((*k)->setPaths.begin()->first==1) {
                            code+="map<set<Thing,ThingCompare>,";
                        }
                    }
                }
                if(t->isInteger) {
                    code+="MyIloIntVar";
                } else {
                    code+="MyIloNumVar";
                }
                temp=example.size()-j;
                for(list<SetType*>::reverse_iterator k=example.rbegin();k!=example.rend();k++) {
                    temp--;
                    if(temp>=0) {
                        if((*k)->setPaths.begin()->first==0) {
                            if(code[code.size()-1]=='>') {
                                code+=" ";
                            }
                            code+=">";
                        }
                        if((*k)->setPaths.begin()->first==1) {
                            code+=",ThingCompare>";
                        }
                    }
                }
                code+="::iterator iter"+convert(tVal)+"="+prev+".begin();iter"+convert(tVal)+"!="+prev+".end();iter"+convert(tVal)+"++) {\n";
                indices+="[iter"+convert(tVal)+"->first]";
                prev="iter"+convert(tVal)+"->second";
                tVal++;
            }
            code+=i->first+indices+"=cplex.getValue("+prev+");\n";
            for(list<SetType*>::iterator j=example.begin();j!=example.end();j++) {
                code+="}\n";
            }
        }
        
    }
    
    code+="} catch(IloException& ex) {\ncout << ex << endl;\nreturn false;\n}\nreturn true;\n}\n"+className+"::~"+className+"() {\nenv.end();\n}\n";
    
}
MbolElementVisitorCPLEX::MbolElementVisitorCPLEX(map<string,Type*> a,bool d,string e) {
    types=a;
    quiet=d;
    className=e;
    justDouble=false;
    code="";
}
void MbolElementVisitorCPLEX::visit(const ElementExpression* elementExpression) {
    if(elementExpression->elementOperator!=NULL) {
        code+=types[elementExpression->value]->getCPLEXType()+" "+elementExpression->value+";\n";
        if(elementExpression->elementOperator->value=="reduce"||elementExpression->elementOperator->value=="union") {
            code+=elementExpression->value+"="+elementExpression->elementExpression->value+";\n";
        }
        code+="for("+types[elementExpression->value]->getCPLEXType()+"::iterator iter="+elementExpression->elementSubexpression->value+".begin();iter!="+elementExpression->elementSubexpression->value+".end();iter++) {\n";
        if(elementExpression->elementOperator->value=="intersect") {
            code+="if("+elementExpression->elementExpression->value+".count(*iter)&&"+elementExpression->elementSubexpression->value+".count(*iter) {\n";
            code+=elementExpression->value+".insert(*iter);\n";
            code+="}\n";
        }
        if(elementExpression->elementOperator->value=="union") {
            code+=elementExpression->value+".insert(*iter);\n";
        }
        if(elementExpression->elementOperator->value=="reduce") {
            code+=elementExpression->value+".erase(*iter);\n";
        }
        code+="}\n";
    }
}
void MbolElementVisitorCPLEX::specialVisit(const NumberPower* numberPower) {
    justDouble=true;
}
void MbolElementVisitorCPLEX::visit(const NumberPower* numberPower) {
    justDouble=false;
    code+="double "+numberPower->value+";\n";
    code+=numberPower->value+"=pow("+numberPower->base->value+","+numberPower->power->value+");\n";
}
void MbolElementVisitorCPLEX::visit(const NumberLiteral* numberLiteral) {
    code+="IloExpr "+numberLiteral->value+"(env);\n";
    code+=numberLiteral->value+"="+numberLiteral->value+"+"+numberLiteral->number+";\n";
}
void MbolElementVisitorCPLEX::visit(const Qualifier* qualifier) {
    if(qualifier->inequality!=NULL) {
        code+="if("+qualifier->lhs+qualifier->inequality->value+qualifier->rhs+") {\n";
    }
    if(qualifier->elementExpression!=NULL) {
        if(qualifier->setCreator=="subset"||qualifier->setCreator=="subsetequal") {
            code+=types[qualifier->setToIter]->getCPLEXType()+" "+qualifier->setToIter+"=powerset("+qualifier->elementExpression->value+");\n";
            if(qualifier->setCreator=="subset") {
                code+=qualifier->setToIter+".erase("+qualifier->elementExpression->value+");\n";
            }
        }
        if(qualifier->setCreator=="in") {
            code+=types[qualifier->setToIter]->getCPLEXType()+" "+qualifier->setToIter+"="+qualifier->elementExpression->value+";\n";
        }
        code+="for("+types[qualifier->iter]->getCPLEXType()+"::iterator "+qualifier->iter+"="+qualifier->setToIter+".begin();"+qualifier->iter+"!="+qualifier->setToIter+".end();"+qualifier->iter+"++) {\n";
        if(qualifier->tupleIndices==NULL) {
            code+=types[qualifier->variable]->getCPLEXType()+" "+qualifier->variable+"=*"+qualifier->iter+";\n";
        } else {
            for(int i=0;i<qualifier->tupleIndices->indices.size();i++) {
                code+=types[qualifier->tupleIndices->indices[i]]->getCPLEXType()+" "+qualifier->tupleIndices->indices[i]+"="+qualifier->iter+"->tupleThing["+convert(i)+"];\n";
            }
        }
    }
}
void MbolElementVisitorCPLEX::specialVisit(const SetCreator* setCreator) {
    code+=types[setCreator->value]->getCPLEXType()+" "+setCreator->value+";\n";
}
void MbolElementVisitorCPLEX::visit(const SetCreator* setCreator) {
    code+=setCreator->value+".insert("+setCreator->variable+");\n";
    for(list<Qualifier*>::iterator i=setCreator->qualifiers->qualifiers.begin();i!=setCreator->qualifiers->qualifiers.end();i++) {
        code+="}\n";
    }
}
void MbolElementVisitorCPLEX::visit(const Equation* equation) {
}
void MbolElementVisitorCPLEX::visit(const VariableMap* variableMap) {
    code+="IloExpr "+variableMap->value+"(env);\n";
    code+=variableMap->value+"="+variableMap->value+"+"+variableMap->variableName;
    for(list<ElementExpression*>::iterator i=variableMap->indices->elementExpressions.begin();i!=variableMap->indices->elementExpressions.end();i++) {
        code+="["+(*i)->value+"]";
    }
    code+=";\n";
}
void MbolElementVisitorCPLEX::specialVisit(const Sum* sum) {
    code+="IloExpr "+sum->value+"(env);\n";
    if(sum->sumType=="*") {
        code+=sum->value+"="+sum->value+"+1;\n";
    }
}
void MbolElementVisitorCPLEX::visit(const Sum* sum) {
    code+=sum->value+"="+sum->value+sum->sumType+sum->numberExpression->value+";\n";
    for(list<Qualifier*>::iterator i=sum->sumQualifiers->qualifiers->qualifiers.begin();i!=sum->sumQualifiers->qualifiers->qualifiers.end();i++) {
        code+="}\n";
    }
}
void MbolElementVisitorCPLEX::visit(const NumberExpression* numberExpression) {
    if(justDouble) {
        code+="double "+numberExpression->value+";\n";
    } else {
        code+="IloExpr "+numberExpression->value+"(env);\n";
    }
    code+=numberExpression->value+"="+numberExpression->value+"+";
    list<NumberOperator*>::const_iterator j=numberExpression->numberOperators.begin();
    for(list<NumberSubexpression*>::const_iterator i=numberExpression->numberSubexpressions.begin();i!=numberExpression->numberSubexpressions.end();i++) {
        if(i!=numberExpression->numberSubexpressions.begin()) {
            code+=(*j)->value;
            j++;
        }
        code+=(*i)->value;
    }
    code+=";\n";
}
void MbolElementVisitorCPLEX::visit(const Objective* objective) {
    code+="objExp="+objective->numberExpression->value+";\n";
    code+="IloObjective obj=Ilo";
    if(objective->objectiveType->value=="max") {
        code+="Maximize";
    }
    if(objective->objectiveType->value=="min") {
        code+="Minimize";
    }
    code+="(env,objExp);\n";
    code+="model.add(obj);\n";
}
void MbolElementVisitorCPLEX::visit(const ElementSet* elementSet) {
    code+=types[elementSet->value]->getCPLEXType()+" "+elementSet->value+";\n";
    code+=elementSet->value+".insert("+elementSet->elementExpression->value+");\n";
}
void MbolElementVisitorCPLEX::visit(const Fraction* fraction) {
    if(justDouble) {
        code+="double "+fraction->value+"=0;\n";
    } else {
        code+="IloExpr "+fraction->value+"(env);\n";
    }
    code+=fraction->value+"="+fraction->value+"+"+fraction->numerator->value+"/"+fraction->denominator->value+";\n";
}
void MbolElementVisitorCPLEX::visit(const SetSize* setSize) {
    code+="int "+setSize->value+"="+setSize->elementExpression->value+".size();\n";
}
void MbolElementVisitorCPLEX::visit(const ElementNumbers* elementNumbers) {
    code+=types[elementNumbers->value]->getCPLEXType()+" "+elementNumbers->value+";\n";
    code+="for(int iter="+elementNumbers->lb+";iter<="+elementNumbers->ub+";iter++) {\n";
    code+=elementNumbers->value+".insert(iter);\n";
    code+="}\n";
}
void MbolElementVisitorCPLEX::visit(const Constraint* constraint) {
    if(constraint->equation!=NULL) {
        code+="model.add("+constraint->equation->lhs->value+constraint->equation->inequality->value+constraint->equation->rhs->value+");\n";
    }
    if(constraint->qualifiers!=NULL) {
        for(list<Qualifier*>::iterator i=constraint->qualifiers->qualifiers.begin();i!=constraint->qualifiers->qualifiers.end();i++) {
            code+="}\n";
        }
    }
}


MbolElementVisitorTypeHelper::MbolElementVisitorTypeHelper() {
    set<string> tempTemporaries=getTemporaries();
    for(set<string>::iterator i=tempTemporaries.begin();i!=tempTemporaries.end();i++) {
        temporaries.insert(*i);
    }
}
void MbolElementVisitorTypeHelper::visit(const Program* program) {
    for(map<string,map<string,edge> >::iterator i=graph.begin();i!=graph.end();i++) {
        types[i->first]=new SetType(i->first);
        if(mapTypes.count(i->first)) {
            //           cout << "ERROR: " << i->first << " used as an element and a number" << endl;
            //           exit(1);
        }
    }
    for(map<string,list<list<string> > >::iterator i=mapTypes.begin();i!=mapTypes.end();i++) {
        if(graph.count(i->first)==0) {
            types[i->first]=new NumberType(i->first);
        }
    }
    bfs();
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->isNumber) {
            for(list<list<string> >::iterator j=mapTypes[i->first].begin();j!=mapTypes[i->first].end();j++) {
                list<SetType*> temp;
                for(list<string>::iterator k=(*j).begin();k!=(*j).end();k++) {
                    if(!types[*k]->isSet) {
                        cout << "ERROR: indice " << (*k) << " of " << i->second->name << " is not an element" << endl;
                        exit(1);
                    }
                    temp.push_back((SetType*)types[*k]);
                }
                ((NumberType*)(types[i->first]))->indices.push_back(temp);
            }
        }
    }
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(integerConstraints.count(i->first)) {
            types[i->first]->isInteger=true;
        }
        if(variables.count(i->first)) {
            types[i->first]->isVariable=true;
        }
        if(temporaries.count(i->first)) {
            types[i->first]->isTemporary=true;
        }
        if(used.count(i->first)&&!variables.count(i->first)&&!temporaries.count(i->first)) {
            types[i->first]->isConstant=true;
        }
    }
    bool isError=false;
    for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
        if(i->second->errorCheck()) {
            isError=true;
        }
    }
    if(isError) {
        exit(1);
    }
}
void MbolElementVisitorTypeHelper::visit(const Qualifier* qualifier) {
    if(qualifier->elementExpression!=NULL) {
        /*cout << qualifier << endl;
        cout << qualifier->variable << endl;
        cout << qualifier->setToIter << endl;*/
        graph[qualifier->variable][qualifier->setToIter].weight=1;
        graph[qualifier->variable][qualifier->iter].weight=1;
        graph[qualifier->iter][qualifier->setToIter].weight=0;
        graph[qualifier->setToIter][qualifier->iter].weight=0;
        if(qualifier->setCreator=="subset"||qualifier->setCreator=="subsetequal") {
            graph[qualifier->variable][qualifier->elementExpression->value].weight=0;
            graph[qualifier->elementExpression->value][qualifier->variable].weight=0;
        }
        if(qualifier->setCreator=="in") {
            graph[qualifier->variable][qualifier->elementExpression->value].weight=1;
        }
    }
    temporaries.insert(qualifier->variable);
}
void MbolElementVisitorTypeHelper::visit(const SetCreator* setCreator) {
    graph[setCreator->variable][setCreator->value].weight=1;
    graph[setCreator->value];
    temporaries.insert(setCreator->variable);
}
void MbolElementVisitorTypeHelper::visit(const ElementSet* elementSet) {
    graph[elementSet->elementExpression->value][elementSet->value].weight=1;
}
void MbolElementVisitorTypeHelper::visit(const ElementVariable* elementVariable) {
    graph[elementVariable->value];
    used.insert(elementVariable->value);
}
void MbolElementVisitorTypeHelper::visit(const ProgramVariables* programVariables) {
    for(list<string>::const_iterator i=programVariables->variables.begin();i!=programVariables->variables.end();i++) {
        variables.insert(*i);
    }
}
void MbolElementVisitorTypeHelper::visit(const Constraint* constraint) {
    if(constraint->integerConstraint!="") {
        integerConstraints.insert(constraint->integerConstraint);
    }
}
void MbolElementVisitorTypeHelper::visit(const NumberVariable* numberVariable) {
    list<string> indices;
    mapTypes[numberVariable->value].push_back(indices);
    used.insert(numberVariable->value);
}
void MbolElementVisitorTypeHelper::visit(const ElementNumbers* elementNumbers) {
    graph[elementNumbers->value];
}
void MbolElementVisitorTypeHelper::visit(const ElementExpression* elementExpression) {
    if(elementExpression->elementOperator!=NULL) {
        graph[elementExpression->value][elementExpression->elementExpression->value].weight=0;
        graph[elementExpression->elementExpression->value][elementExpression->elementSubexpression->value].weight=0;
        graph[elementExpression->elementSubexpression->value][elementExpression->value].weight=0;
    }
}
void MbolElementVisitorTypeHelper::visit(const VariableMap* variableMap) {
    list<string> indices;
    for(list<ElementExpression*>::iterator i=variableMap->indices->elementExpressions.begin();i!=variableMap->indices->elementExpressions.end();i++) {
        indices.push_back((*i)->value);
    }
    mapTypes[variableMap->variableName].push_back(indices);
    used.insert(variableMap->variableName);
}
void MbolElementVisitorTypeHelper::bfs() {
    set<string> startNodes;
    for(map<string,map<string,edge> >::iterator i=graph.begin();i!=graph.end();i++) {
        startNodes.insert(i->first);
        for(map<string,edge>::iterator j=i->second.begin();j!=i->second.end();j++) {
            startNodes.insert(j->first);
        }
    }
    set<string> toRemove;
    for(set<string>::iterator i=startNodes.begin();i!=startNodes.end();i++) {
        map<int,list<list<string> > > toVisit;
        set<string> visited;
        list<string> initialPath;
        initialPath.push_back(*i);
        toVisit[0].push_back(initialPath);
        while(!toVisit.empty()) {
            list<string> x=toVisit.begin()->second.front();
            int length=toVisit.begin()->first;
            toVisit.begin()->second.pop_front();
            while(!toVisit.empty()&&toVisit.begin()->second.empty()) {
                toVisit.erase(toVisit.begin());
            }
            if(length!=0) {
                toRemove.insert(x.back());
            }
            if(visited.count(x.back())) {
                continue;
            }
            visited.insert(x.back());
            for(map<string,edge>::iterator i=graph[x.back()].begin(); i!=graph[x.back()].end(); i++) {
                list<string> y=x;
                y.push_back(i->first);
                toVisit[length+i->second.weight].push_back(y);
            }
        }
    }
    for(set<string>::iterator i=toRemove.begin();i!=toRemove.end();i++) {
        startNodes.erase(*i);
    }
    map<int,list<list<string> > > toVisit;
    set<string> visited;
    for(set<string>::iterator i=startNodes.begin();i!=startNodes.end();i++) {
        list<string> temp;
        temp.push_back(*i);
        toVisit[0].push_back(temp);
    }
    while(!toVisit.empty()) {
        list<string> x=toVisit.begin()->second.front();
        int length=toVisit.begin()->first;
        toVisit.begin()->second.pop_front();
        while(!toVisit.empty()&&toVisit.begin()->second.empty()) {
            toVisit.erase(toVisit.begin());
        }
        list<SetType*> path;
        for(list<string>::iterator i=x.begin();i!=x.end();i++) {
            if(!types[*i]->isSet) {
                cout << "ERROR: unknown something bad about " << types[*i]->name << endl;
                exit(1);
            }
            path.push_back((SetType*)types[*i]);
        }
        ((SetType*)(types[x.back()]))->setPaths[length].push_back(path);
        if(visited.count(x.back())) {
            continue;
        }
        visited.insert(x.back());
        for(map<string,edge>::iterator i=graph[x.back()].begin(); i!=graph[x.back()].end(); i++) {
            list<string> y=x;
            y.push_back(i->first);
            toVisit[length+i->second.weight].push_back(y);
        }
    }
}
