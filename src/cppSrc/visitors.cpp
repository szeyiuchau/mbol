#include <execinfo.h>
#include<visitors.hpp>
#include<classes.hpp>
#include<utilities.hpp>

MbolElementVisitorPrinter::MbolElementVisitorPrinter() {
  out.open("/tmp/mbol-ast");
  out << "digraph {\n";
}
void MbolElementVisitorPrinter::makeNode(MbolElement* a, string label) {
  if (mapping.count(a) == 0) {
    mapping[a] = mapping.size();
  }
  out << mapping[a] << " [label=\"" << label << "\\n" << "Line: " << a->lineno << "\"];\n";
}
void MbolElementVisitorPrinter::makeEdge(MbolElement* a, MbolElement* b) {
  if (a == NULL || b == NULL) {
    return;
  }
  if (mapping.count(a) == 0) {
    mapping[a] = mapping.size();
  }
  if (mapping.count(b) == 0) {
    mapping[b] = mapping.size();
  }
  out << mapping[a] << " -> " << mapping[b] << ";\n";
}
void MbolElementVisitorPrinter::defaultVisit(MbolElement* element) {
  makeNode(element, element->getName());
  list<MbolElement*> x = element->getChildren();
  for (list<MbolElement*>::iterator i = x.begin(); i != x.end(); i++) {
    makeEdge(element, *i);
  }
}
void MbolElementVisitorPrinter::end() {
  out << "}" << endl;
  out.close();
  int dontcare = system("dot -Tps -O /tmp/mbol-ast");
  dontcare = system("evince /tmp/mbol-ast.ps");
}

void MbolElementVisitorCPLEX::specialVisit(Program* program) {
  // start making all the code
  //#include<ilcplex/ilocplex.h>\n
  code = "#include<set>\n#include<map>\n#include<mbol.hpp>\nusing namespace std;\n#ifndef MBOL_" + className + "\n#define MBOL_" + className + "\nclass " + className + " {\npublic:\nbool init();\nbool solve();\n" + className + "();\n~" + className + "();\nbool hasInitialized;\nMBOLSolver solver;\ndouble objValue;\nMBOLExpr objExp;\n";
  
  // create struct for returning variables
  /*
  code+="// Variable results\n";
  for(map<string,Type*>::iterator i=types.begin();i!=types.end();i++) {
    if(i->second->isConstant) {
      code+=i->second->getCPLEXType()+" "+i->first+"_ret;\n";
    }
  }*/
  
  // making arguments which are constants in the program
  code += "// Constants in the program that you must initialize\n";
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isConstant) {
      code += i->second->getCPLEXType() + " " + i->first + ";\n";
    }
  }
  
  // declare CPLEX variables (actual variables in program)
  code += "// Variables used by the CPLEX program\n";
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isVariable) {
      code += i->second->getCPLEXType() + " " + i->first + ";\n";
    }
  }
  
  code += "// Variable results\n";
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isVariable) {
      string name = i->first + "_ret";
      if(i->second->isSet) {
        types[name] = new SetType(name);
        ((SetType*)types[name])->setPaths = ((SetType*)i->second)->setPaths;
      }
      if(i->second->isNumber) {
        types[name] = new NumberType(name);
        ((NumberType*)types[name])->indices = ((NumberType*)i->second)->indices;
        types[name]->isInteger = i->second->isInteger;
      }
      types[name]->isReturn = true;
      code += types[name]->getCPLEXType() + " " + name + ";\n";
    }
  }
  
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isConstant) {
      code += "void read_" + i->first + "(list<string>& tokens);\n";
    }
  }
  
  code += "void readAll(string f);\n";
  
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isVariable) {
      code += "void write_" + i->first + "(ofstream& out);\n";
    }
  }
  
  code += "void writeObj(ofstream& out);\n";
  
  code += "void writeAll(string f);\n";
  
  code += "};\n#endif\n";
  code += className + "::" + className + "() {\nhasInitialized = false;\n}\nbool " + className + "::init() {\n";
  code += "MBOLModel model;\n";
//try {\n     }";
  
  // take care of simple variables
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isVariable && i->second->isNumber && ((NumberType*)i->second)->indices.front().size() == 0) {
      if(i->second->isInteger) {
        code += "MBOLIntVar";
      } else {
        code += "MBOLNumVar";
      }
      code += " temp" + i->first + ";\n" + i->first + "=temp" + i->first + ";\n";
    }
  }
  
  code += "MBOLExpr tempObj;\n";
  code += "objExp = tempObj;\n";
}

void MbolElementVisitorCPLEX::visit(Program* program) {
  
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isVariable) {
      NumberType* t = (NumberType*)i->second;
      list<SetType*> example = t->indices.front();
      int tVal = 0;
      string prev = i->first;
      string indices = "";
      for(int j = 0; j < example.size(); j++) {
        code += "for(";
        int temp = 0;
        for(list<SetType*>::iterator k = example.begin(); k != example.end(); k++) {
          temp++;
          if(temp > j) {
            if((*k)->setPaths.begin()->first == 0) {
              code += "map<int,";
            }
            if((*k)->setPaths.begin()->first == 1) {
              code += "map<set<Element,ElementCompare>,";
            }
          }
        }
        if(t->isInteger) {
          code += "MBOLIntVar";
        } else {
          code += "MBOLNumVar";
        }
        temp = example.size() - j;
        for(list<SetType*>::reverse_iterator k = example.rbegin(); k != example.rend(); k++) {
          temp--;
          if(temp >= 0) {
            if((*k)->setPaths.begin()->first == 0) {
              if(code[code.size() - 1] == '>') {
                code += " ";
              }
              code += ">";
            }
            if((*k)->setPaths.begin()->first == 1) {
              code += ",ElementCompare>";
            }
          }
        }
        code += "::iterator iter" + convert(tVal) + " = " + prev + ".begin(); iter" + convert(tVal) + " != " + prev + ".end(); iter" + convert(tVal) + "++) {\n";
        indices += "+string(\"_\") + convert(iter" + convert(tVal) + "->first)";
        prev = "iter" + convert(tVal) + "->second";
        tVal++;
      }
      code += "variableConversion[" + prev + ".name] = string(\"" + i->first + "\")" + indices + ";\n";
      for(list<SetType*>::iterator j = example.begin(); j != example.end(); j++) {
        code += "}\n";
      }
    }
  }
  
  code += "MBOLSolver tempSolver(model);\nsolver = tempSolver;\n";
  if(quiet) {
    //        code+="solver.setOut(env.getNullStream());\n";
    code += "solver.quiet();\n";
  }
  //    code+="}\ncatch(IloException& ex) {\ncout << ex << endl;\nreturn false;\n}\n";
  code += "hasInitialized = true;\nreturn true;\n}\n";
  
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isConstant) {
      code += "void " + className + "::read_" + i->first + "(list<string>& tokens) {\n";
      if(i->second->isSet) {
        SetType* sType = (SetType*)i->second;
        if(sType->setPaths.begin()->first == 0) {
          code += i->first + " = readIntegerElement(tokens);\n";
        } else {
          code += i->first + " = readSetElement(tokens);\n";
        }
        //code+="cout << Element("+i->first+").print() << endl;\n";
      } else if(i->second->isNumber) {
        NumberType* nType = (NumberType*)i->second;
        code += "while (!tokens.empty() && !isVariable(tokens.front())) {\n";
        list<SetType*> example = nType->indices.front();
        int num = 0;
        for(list<SetType*>::iterator j = example.begin(); j != example.end(); j++) {
          if((*j)->setPaths.begin()->first == 0) {
            code += "int index" + convert(num++) + " = readIntegerElement(tokens);\n";
          } else {
            code += "set<Element,ElementCompare> index" + convert(num++) + " = readSetElement(tokens);\n";
          }
        }
        num = 0;
        code += i->first;
        for(list<SetType*>::iterator j = example.begin(); j != example.end(); j++) {
          code += "[index" + convert(num++) + "]";
        }
        code += " = atof(tokens.front().c_str());\n";
        code += "tokens.pop_front();\n";
        code += "}\n";
      }
      code += "}\n";
    }
  }
  
  code += "void " + className + "::readAll(string f) {\n";
  code += "list<string> tokens = getTokens(f.c_str());\n";
  code += "while(!tokens.empty()) {\n";
  
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isConstant) {
      code += "if (tokens.front() == \"" + i->first + "\") {\n";
      code += "tokens.pop_front();\n";
      code += "read_" + i->first + "(tokens);\n";
      code += "}\n";
    }
  }
  
  code += "}\n";
  code += "}\n";
  
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isVariable) {
      code += "void " + className + "::write_" + i->first + "(ofstream& out) {\n";
      code += "out << \"" + i->first + "\" << endl;\n";
      NumberType* t = (NumberType*)i->second;
      list<SetType*> example = t->indices.front();
      int tVal = 0;
      string prev = i->first;
      string indices = "";
      for(int j = 0; j < example.size(); j++) {
        code += "for (";
        int temp = 0;
        for(list<SetType*>::iterator k = example.begin(); k != example.end(); k++) {
          temp++;
          if(temp > j) {
            if((*k)->setPaths.begin()->first == 0) {
              code += "map<int,";
            }
            if((*k)->setPaths.begin()->first == 1) {
              code += "map<set<Element,ElementCompare>,";
            }
          }
        }
        if(t->isInteger) {
          code += "MBOLIntVar";
        } else {
          code += "MBOLNumVar";
        }
        temp = example.size() - j;
        for(list<SetType*>::reverse_iterator k = example.rbegin(); k != example.rend(); k++) {
          temp--;
          if(temp >= 0) {
            if((*k)->setPaths.begin()->first == 0) {
              if(code[code.size() - 1] == '>') {
                code += " ";
              }
              code += ">";
            }
            if((*k)->setPaths.begin()->first == 1) {
              code += ",ElementCompare>";
            }
          }
        }
        code += "::iterator iter" + convert(tVal) + "=" + prev + ".begin();iter" + convert(tVal) + "!=" + prev + ".end();iter" + convert(tVal) + "++) {\n";
        indices += "Element(iter" + convert(tVal) + "->first).print() << \" \" << ";
        prev = "iter" + convert(tVal) + "->second";
        tVal++;
      }
      code += "out << " + indices + "solver.getValue(" + prev + ") << endl;\n";
      for(list<SetType*>::iterator j = example.begin(); j != example.end(); j++) {
        code += "}\n";
      }
      code += "}\n";
    }
  }
  
  code += "void " + className + "::writeObj(ofstream& out) {\n";
  code += "out << \"objValue\" << endl;\n";
  code += "out << objValue << endl;\n";
  code += "}\n";
  
  code += "void " + className + "::writeAll(string f) {\n";
  code += "ofstream out(f.c_str());\n";
  code += "writeObj(out);\n";
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isVariable) {
      code += "out << endl;\n";
      code += "write_" + i->first + "(out);\n";
    }
  }
  
  code += "}\n";
  
  code += "bool " + className + "::solve() {\nif (!hasInitialized) {\ninit();\n}\nif (!hasInitialized) {\nreturn false;\n}\n";
//try{\n     }
  code += "solver.solve();\nobjValue = solver.getValue(objExp);\n";
  
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isReturn) {
      NumberType* t = (NumberType*)i->second;
      list<SetType*> example = t->indices.front();
      int tVal = 0;
      string prev = i->first.substr(0, i->first.size() - 4);
      string indices = "";
      for(int j = 0; j < example.size(); j++) {
        code += "for(";
        int temp = 0;
        for(list<SetType*>::iterator k = example.begin(); k != example.end(); k++) {
          temp++;
          if(temp > j) {
            if((*k)->setPaths.begin()->first == 0) {
              code += "map<int,";
            }
            if((*k)->setPaths.begin()->first == 1) {
              code += "map<set<Element,ElementCompare>,";
            }
          }
        }
        if(t->isInteger) {
          code += "MBOLIntVar";
        } else {
          code += "MBOLNumVar";
        }
        temp = example.size() - j;
        for(list<SetType*>::reverse_iterator k = example.rbegin(); k != example.rend(); k++) {
          temp--;
          if(temp >= 0) {
            if((*k)->setPaths.begin()->first == 0) {
              if(code[code.size() - 1] == '>') {
                code += " ";
              }
              code += ">";
            }
            if((*k)->setPaths.begin()->first == 1) {
              code += ",ElementCompare>";
            }
          }
        }
        code += "::iterator iter" + convert(tVal) + " = " + prev + ".begin(); iter" + convert(tVal) + " != " + prev + ".end(); iter" + convert(tVal) + "++) {\n";
        indices += "[iter" + convert(tVal) + "->first]";
        prev = "iter" + convert(tVal) + "->second";
        tVal++;
      }
      code += i->first + indices + "=solver.getValue(" + prev + ");\n";
      for(list<SetType*>::iterator j = example.begin(); j != example.end(); j++) {
        code += "}\n";
      }
    }
    
  }
  
  code += "return true;\n}\n" + className + "::~" + className + "() {\n}\n";
  
}
MbolElementVisitorCPLEX::MbolElementVisitorCPLEX(map<string, Type*> a, bool d, string e) {
  types = a;
  quiet = d;
  className = e;
  justDouble = false;
  code = "";
}
void MbolElementVisitorCPLEX::visit(ElementExpression* elementExpression) {
  if(elementExpression->elementOperator != NULL) {
    code += types[elementExpression->value]->getCPLEXType() + " " + elementExpression->value + ";\n";
    if(elementExpression->elementOperator->value == "+") {
      code += elementExpression->value + " = " + elementExpression->elementExpression->value + " + " + elementExpression->elementSubexpression->value + ";\n";
    } else {
      if(elementExpression->elementOperator->value == "reduce" || elementExpression->elementOperator->value == "union") {
        code += elementExpression->value + "=" + elementExpression->elementExpression->value + ";\n";
      }
      code += "for(" + types[elementExpression->value]->getCPLEXType() + "::iterator iter=" + elementExpression->elementSubexpression->value + ".begin();iter!=" + elementExpression->elementSubexpression->value + ".end();iter++) {\n";
      if(elementExpression->elementOperator->value == "intersect") {
        code += "if(" + elementExpression->elementExpression->value + ".count(*iter)&&" + elementExpression->elementSubexpression->value + ".count(*iter)) {\n";
        code += elementExpression->value + ".insert(*iter);\n";
        code += "}\n";
      }
      if(elementExpression->elementOperator->value == "union") {
        code += elementExpression->value + ".insert(*iter);\n";
      }
      if(elementExpression->elementOperator->value == "reduce") {
        code += elementExpression->value + ".erase(*iter);\n";
      }
      code += "}\n";
    }
  }
}
void MbolElementVisitorCPLEX::visit(NumberPower* numberPower) {
  numberPower->value = "pow(" + numberPower->base->value + ", " + numberPower->power->value + ")";
}
void MbolElementVisitorCPLEX::visit(Qualifier* qualifier) {
  if(qualifier->inequality != NULL) {
    code += "if(" + qualifier->lhs + " " + qualifier->inequality->value + " " + qualifier->rhs + ") {\n";
  }
  if(qualifier->elementExpression != NULL) {
    if(qualifier->setCreator == "subset" || qualifier->setCreator == "subsetequal") {
      code += types[qualifier->setToIter]->getCPLEXType() + " " + qualifier->setToIter + " = powerset(" + qualifier->elementExpression->value + ");\n";
      if(qualifier->setCreator == "subset") {
        code += qualifier->setToIter + ".erase(" + qualifier->elementExpression->value + ");\n";
      }
    }
    if(qualifier->setCreator == "in") {
      code += types[qualifier->setToIter]->getCPLEXType() + " " + qualifier->setToIter + "=" + qualifier->elementExpression->value + ";\n";
    }
    code += "for(" + types[qualifier->iter]->getCPLEXType() + "::iterator " + qualifier->iter + "=" + qualifier->setToIter + ".begin();" + qualifier->iter + "!=" + qualifier->setToIter + ".end();" + qualifier->iter + "++) {\n";
    if(qualifier->tupleIndices == NULL) {
      code += types[qualifier->variable]->getCPLEXType() + " " + qualifier->variable + "=*" + qualifier->iter + ";\n";
    } else {
      for(int i = 0; i < qualifier->tupleIndices->indices.size(); i++) {
        code += types[qualifier->tupleIndices->indices[i]]->getCPLEXType() + " " + qualifier->tupleIndices->indices[i] + "=" + qualifier->iter + "->tupleElement[" + convert(i) + "];\n";
      }
    }
  }
}
void MbolElementVisitorCPLEX::specialVisit(SetCreator* setCreator) {
  code += types[setCreator->value]->getCPLEXType() + " " + setCreator->value + ";\n";
}
void MbolElementVisitorCPLEX::visit(SetCreator* setCreator) {
  code += setCreator->value + ".insert(" + setCreator->variable + ");\n";
  for(list<Qualifier*>::iterator i = setCreator->qualifiers->qualifiers.begin(); i != setCreator->qualifiers->qualifiers.end(); i++) {
    code += "}\n";
  }
}
void MbolElementVisitorCPLEX::visit(Equation* equation) {
}
void MbolElementVisitorCPLEX::visit(NumberParantheses* numberParantheses) {
  numberParantheses->value = "(" + numberParantheses->numberExpression->value + ")";
}
void MbolElementVisitorCPLEX::visit(VariableMap* variableMap) {
  /*if(justDouble) {
    code += "double " + variableMap->value + "=0;\n";
  } else {
    code += "MBOLExpr " + variableMap->value + ";\n";
  }
  code += variableMap->value + "=" + variableMap->value + "+" + variableMap->variableName;
  for(list<ElementExpression*>::iterator i = variableMap->indices->elementExpressions.begin(); i != variableMap->indices->elementExpressions.end(); i++) {
    code += "[" + (*i)->value + "]";
  }
  code += ";\n";*/
  variableMap->value = variableMap->variableName;
  for(list<ElementExpression*>::iterator i = variableMap->indices->elementExpressions.begin(); i != variableMap->indices->elementExpressions.end(); i++) {
    variableMap->value += "[" + (*i)->value + "]";
  }
}
void MbolElementVisitorCPLEX::specialVisit(Sum* sum) {
  code += "MBOLExpr " + sum->value + " = ";
  if(sum->sumType == "+") {
    code += "0";
  } else {
    code += "1";
  }
  code += ";\n";
}
void MbolElementVisitorCPLEX::visit(Sum* sum) {
  code += sum->value + " = " + sum->value + " " + sum->sumType + sum->numberExpression->value + ";\n";
  for(list<Qualifier*>::iterator i = sum->sumQualifiers->qualifiers->qualifiers.begin(); i != sum->sumQualifiers->qualifiers->qualifiers.end(); i++) {
    code += "}\n";
  }
}
void MbolElementVisitorCPLEX::visit(NumberSubexpression* numberSubexpression) {
  cout << "SHOULDNT HAPPEN??" << endl;
  //numberSubexpression->value = numberSubexpression->variableMap->value;
}
void MbolElementVisitorCPLEX::visit(NumberExpression* numberExpression) {
  /*if(justDouble) {
    code += "double " + numberExpression->value + "=0;\n";
  } else {
    code += "MBOLExpr " + numberExpression->value + ";\n";
  }
  code += numberExpression->value + "=" + numberExpression->value + "+";*/
  numberExpression->value = "";
  list<NumberOperator*>::const_iterator j = numberExpression->numberOperators.begin();
  for(list<NumberSubexpression*>::const_iterator i = numberExpression->numberSubexpressions.begin(); i != numberExpression->numberSubexpressions.end(); i++) {
    if(i != numberExpression->numberSubexpressions.begin()) {
      numberExpression->value += " " + (*j)->value + " ";
      j++;
    }
    numberExpression->value += (*i)->value;
  }
  //  code += ";\n";
}
void MbolElementVisitorCPLEX::visit(Objective* objective) {
  code += "objExp=" + objective->numberExpression->value + ";\n";
  code += "model.";
  if(objective->objectiveType->value == "max") {
    code += "maximize";
  }
  if(objective->objectiveType->value == "min") {
    code += "minimize";
  }
  code += "(objExp);\n";
}
void MbolElementVisitorCPLEX::visit(ElementSet* elementSet) {
  code += types[elementSet->value]->getCPLEXType() + " " + elementSet->value + ";\n";
  code += elementSet->value + ".insert(" + elementSet->elementExpression->value + ");\n";
}
void MbolElementVisitorCPLEX::visit(Fraction* fraction) {
  fraction->value = "(" + fraction->numerator->value + ") / (" + fraction->denominator->value + ")";
}
void MbolElementVisitorCPLEX::visit(SetSize* setSize) {
  setSize->value = "(int)" + setSize->elementExpression->value + ".size()";
}
void MbolElementVisitorCPLEX::visit(ElementNumbers* elementNumbers) {
  code += types[elementNumbers->value]->getCPLEXType() + " " + elementNumbers->value + ";\n";
  code += "for (int iter=" + elementNumbers->lb + "; iter <= " + elementNumbers->ub + "; iter++) {\n";
  code += elementNumbers->value + ".insert(iter);\n";
  code += "}\n";
}
void MbolElementVisitorCPLEX::visit(Constraint* constraint) {
  if(constraint->equation != NULL) {
    code += "model.add(" + constraint->equation->lhs->value + " " + constraint->equation->inequality->value + " " + constraint->equation->rhs->value + ");\n";
  }
  if(constraint->qualifiers != NULL) {
    for(list<Qualifier*>::iterator i = constraint->qualifiers->qualifiers.begin(); i != constraint->qualifiers->qualifiers.end(); i++) {
      code += "}\n";
    }
  }
  //  code += "}\n";
}


MbolElementVisitorTypeHelper::MbolElementVisitorTypeHelper() {
  set<string> tempTemporaries = getTemporaries();
  for(set<string>::iterator i = tempTemporaries.begin(); i != tempTemporaries.end(); i++) {
    temporaries.insert(*i);
  }
}
void MbolElementVisitorTypeHelper::visit(Program* program) {
  for(map<string, map<string, edge> >::iterator i = graph.begin(); i != graph.end(); i++) {
    types[i->first] = new SetType(i->first);
    if(mapTypes.count(i->first)) {
      //           cout << "ERROR: " << i->first << " used as an element and a number" << endl;
      //           exit(1);
    }
  }
  for(map<string, list<list<string> > >::iterator i = mapTypes.begin(); i != mapTypes.end(); i++) {
    if(graph.count(i->first) == 0) {
      types[i->first] = new NumberType(i->first);
    }
  }
  bfs();
  for(map<string, vector<string> >::iterator i = tupleTypes.begin(); i != tupleTypes.end(); i++) {
    types[i->first]->isTuple = true;
    for(int j = 0; j < i->second.size(); j++) {
      ((SetType*)types[i->first])->tupleIndices.push_back((SetType*)types[i->second[j]]);
    }
  }
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->isNumber) {
      for(list<list<string> >::iterator j = mapTypes[i->first].begin(); j != mapTypes[i->first].end(); j++) {
        list<SetType*> temp;
        for(list<string>::iterator k = (*j).begin(); k != (*j).end(); k++) {
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
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(integerConstraints.count(i->first)) {
      types[i->first]->isInteger = true;
    }
    if(variables.count(i->first)) {
      types[i->first]->isVariable = true;
    }
    if(temporaries.count(i->first)) {
      types[i->first]->isTemporary = true;
    }
    if(used.count(i->first) && !variables.count(i->first) && !temporaries.count(i->first)) {
      types[i->first]->isConstant = true;
    }
  }
  bool isError = false;
  for(map<string, Type*>::iterator i = types.begin(); i != types.end(); i++) {
    if(i->second->errorCheck()) {
      isError = true;
    }
  }
  if(isError) {
    exit(1);
  }
}
void MbolElementVisitorTypeHelper::visit(Qualifier* qualifier) {
  if(qualifier->elementExpression != NULL) {
    /*cout << qualifier << endl;
    cout << qualifier->variable << endl;
    cout << qualifier->setToIter << endl;*/
    graph[qualifier->variable][qualifier->setToIter].weight = 1;
    graph[qualifier->variable][qualifier->iter].weight = 1;
    graph[qualifier->iter][qualifier->setToIter].weight = 0;
    graph[qualifier->setToIter][qualifier->iter].weight = 0;
    if(qualifier->setCreator == "subset" || qualifier->setCreator == "subsetequal") {
      graph[qualifier->variable][qualifier->elementExpression->value].weight = 0;
      graph[qualifier->elementExpression->value][qualifier->variable].weight = 0;
    }
    if(qualifier->setCreator == "in") {
      graph[qualifier->variable][qualifier->elementExpression->value].weight = 1;
    }
  }
  if(qualifier->tupleIndices != NULL) {
    if(!tupleTypes[qualifier->variable].empty()) {
      cout << "bad usage of tuples, something terribly wrong has occured" << endl;
    }
    for(int i = 0; i < qualifier->tupleIndices->indices.size(); i++) {
      temporaries.insert(qualifier->tupleIndices->indices[i]);
      tupleTypes[qualifier->variable].push_back(qualifier->tupleIndices->indices[i]);
    }
  } else {
    temporaries.insert(qualifier->variable);
  }
}
void MbolElementVisitorTypeHelper::visit(SetCreator* setCreator) {
  graph[setCreator->variable][setCreator->value].weight = 1;
  graph[setCreator->value];
  temporaries.insert(setCreator->variable);
}
void MbolElementVisitorTypeHelper::visit(ElementSet* elementSet) {
  graph[elementSet->elementExpression->value][elementSet->value].weight = 1;
}
void MbolElementVisitorTypeHelper::visit(ElementVariable* elementVariable) {
  graph[elementVariable->value];
  used.insert(elementVariable->value);
}
void MbolElementVisitorTypeHelper::visit(ProgramVariables* programVariables) {
  for(list<string>::const_iterator i = programVariables->variables.begin(); i != programVariables->variables.end(); i++) {
    variables.insert(*i);
  }
}
void MbolElementVisitorTypeHelper::visit(Constraint* constraint) {
  if(constraint->integerConstraint != "") {
    integerConstraints.insert(constraint->integerConstraint);
  }
}
void MbolElementVisitorTypeHelper::visit(NumberVariable* numberVariable) {
  list<string> indices;
  mapTypes[numberVariable->value].push_back(indices);
  used.insert(numberVariable->value);
}
void MbolElementVisitorTypeHelper::visit(ElementNumbers* elementNumbers) {
  graph[elementNumbers->value];
}
void MbolElementVisitorTypeHelper::visit(ElementExpression* elementExpression) {
  if(elementExpression->elementOperator != NULL) {
    graph[elementExpression->value][elementExpression->elementExpression->value].weight = 0;
    graph[elementExpression->elementExpression->value][elementExpression->elementSubexpression->value].weight = 0;
    graph[elementExpression->elementSubexpression->value][elementExpression->value].weight = 0;
  }
}
void MbolElementVisitorTypeHelper::visit(VariableMap* variableMap) {
  list<string> indices;
  for(list<ElementExpression*>::iterator i = variableMap->indices->elementExpressions.begin(); i != variableMap->indices->elementExpressions.end(); i++) {
    indices.push_back((*i)->value);
  }
  mapTypes[variableMap->variableName].push_back(indices);
  used.insert(variableMap->variableName);
}
void MbolElementVisitorTypeHelper::bfs() {
  set<string> startNodes;
  for(map<string, map<string, edge> >::iterator i = graph.begin(); i != graph.end(); i++) {
    startNodes.insert(i->first);
    for(map<string, edge>::iterator j = i->second.begin(); j != i->second.end(); j++) {
      startNodes.insert(j->first);
    }
  }
  set<string> toRemove;
  for(set<string>::iterator i = startNodes.begin(); i != startNodes.end(); i++) {
    map<int, list<list<string> > > toVisit;
    set<string> visited;
    list<string> initialPath;
    initialPath.push_back(*i);
    toVisit[0].push_back(initialPath);
    while(!toVisit.empty()) {
      list<string> x = toVisit.begin()->second.front();
      int length = toVisit.begin()->first;
      toVisit.begin()->second.pop_front();
      while(!toVisit.empty() && toVisit.begin()->second.empty()) {
        toVisit.erase(toVisit.begin());
      }
      if(length != 0) {
        toRemove.insert(x.back());
      }
      if(visited.count(x.back())) {
        continue;
      }
      visited.insert(x.back());
      for(map<string, edge>::iterator i = graph[x.back()].begin(); i != graph[x.back()].end(); i++) {
        list<string> y = x;
        y.push_back(i->first);
        toVisit[length + i->second.weight].push_back(y);
      }
    }
  }
  for(set<string>::iterator i = toRemove.begin(); i != toRemove.end(); i++) {
    startNodes.erase(*i);
  }
  map<int, list<list<string> > > toVisit;
  set<string> visited;
  for(set<string>::iterator i = startNodes.begin(); i != startNodes.end(); i++) {
    list<string> temp;
    temp.push_back(*i);
    toVisit[0].push_back(temp);
  }
  while(!toVisit.empty()) {
    list<string> x = toVisit.begin()->second.front();
    int length = toVisit.begin()->first;
    toVisit.begin()->second.pop_front();
    while(!toVisit.empty() && toVisit.begin()->second.empty()) {
      toVisit.erase(toVisit.begin());
    }
    list<SetType*> path;
    for(list<string>::iterator i = x.begin(); i != x.end(); i++) {
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
    for(map<string, edge>::iterator i = graph[x.back()].begin(); i != graph[x.back()].end(); i++) {
      list<string> y = x;
      y.push_back(i->first);
      toVisit[length + i->second.weight].push_back(y);
    }
  }
}
