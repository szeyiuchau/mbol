#include<utilities.hpp>
#include<stdlib.h>
#include<set>
#include<list>
#include<map>
#include<vector>
#include<sstream>
#include<iostream>

#ifndef MYVISITORS
#define MYVISITORS

using namespace std;

class NumberPower;
class Constraint;
class NumberOperator;
class NumberParantheses;
class ElementParantheses;
class ElementNumbers;
class SetSize;
class ElementSet;
class ElementOperator;
class Fraction;
class ElementVariable;
class NumberVariable;
class NumberLiteral;
class VariableMap;
class ProgramVariables;
class Program;
class Objective;
class Constraints;
class TupleIndices;
class ObjectiveType;
class Equation;
class Inequality;
class Qualifiers;
class Qualifier;
class Operator;
class Indices;
class Sum;
class SumQualifiers;
class NumberExpression;
class ElementExpression;
class NumberSubexpression;
class ElementSubexpression;
class SetCreator;

class MbolElementVisitor {
  public:
  virtual void specialVisit(Program* program) {
  }
  virtual void specialVisit(Sum* sum) {
  }
  virtual void specialVisit(SetCreator* setCreator) {
  }
  virtual void visit(ElementExpression* elementExpression) {
  }
  virtual void visit(ElementOperator* elementOperator) {
  }
  virtual void visit(Qualifier* qualifier) {
  }
  virtual void visit(SetCreator* setCreator) {
  }
  virtual void visit(Equation* equation) {
  }
  virtual void visit(NumberPower* numberPower) {
}
  virtual void visit(VariableMap* variableMap) {
  }
  virtual void visit(Sum* sum) {
  }
  virtual void visit(Fraction* fraction) {
  }
  virtual void visit(NumberExpression* numberExpression) {
  }
  virtual void visit(Objective* objective) {
  }
  virtual void visit(ElementSet* elementSet) {
  }
  virtual void visit(SetSize* setSize) {
  }
  virtual void visit(ElementNumbers* elementNumbers) {
  }
  virtual void visit(Constraint* constraint) {
  }
  virtual void visit(ElementParantheses* elementParantheses) {
  }
  virtual void visit(ElementVariable* elementVariable) {
  }
  virtual void visit(ElementSubexpression* elementSubexpression) {
  }
  virtual void visit(NumberVariable* numberVariable) {
  }
  virtual void visit(TupleIndices* tupleIndices) {
  }
  virtual void visit(NumberLiteral* numberLiteral) {
  }
  virtual void visit(NumberParantheses* numberParantheses) {
  }
  virtual void visit(NumberSubexpression* numberSubexpression) {
  }
  virtual void visit(SumQualifiers* sumQualifiers) {
  }
  virtual void visit(Indices* indices) {
  }
  virtual void visit(Inequality* inequality) {
  }
  virtual void visit(NumberOperator* numberOperator) {
  }
  virtual void visit(Qualifiers* qualifiers) {
  }
  virtual void visit(Constraints* constraints) {
  }
  virtual void visit(ObjectiveType* objectiveType) {
  }
  virtual void visit(ProgramVariables* programVariables) {
  }
  virtual void visit(Program* program) {
  }
};

class MbolElementVisitorPrinter : public MbolElementVisitor {
  public:
  MbolElementVisitorPrinter();
  virtual void visit(ElementExpression* elementExpression);
  virtual void visit(Qualifier* qualifier);
  virtual void specialVisit(SetCreator* setCreator);
  virtual void visit(SetCreator* setCreator);
  virtual void visit(Equation* equation);
  virtual void visit(VariableMap* variableMap);
  virtual void specialVisit(Sum* sum);
  virtual void visit(Sum* sum);
  virtual void visit(NumberExpression* numberExpression);
  virtual void visit(Objective* objective);
  virtual void visit(ElementSet* elementSet);
  virtual void visit(Fraction* fraction);
  virtual void visit(SetSize* setSize);
  virtual void visit(ElementNumbers* elementNumbers);
  virtual void visit(Constraint* constraint);
};

class MbolElementVisitorCPLEX : public MbolElementVisitor {
  public:
  bool justDouble;
  string code;
  map<string,Type*> types;
  string className;
  bool quiet;
  MbolElementVisitorCPLEX(map<string,Type*> a,bool d,string e);
  virtual void visit(NumberPower* numberPower);
  virtual void visit(ElementExpression* elementExpression);
  virtual void visit(Program* program);
  virtual void specialVisit(Program* program);
  virtual void visit(Qualifier* qualifier);
  virtual void specialVisit(SetCreator* setCreator);
  virtual void visit(SetCreator* setCreator);
  virtual void visit(Equation* equation);
  virtual void visit(NumberParantheses* numberParantheses);
  virtual void visit(VariableMap* variableMap);
  virtual void specialVisit(Sum* sum);
  virtual void visit(Sum* sum);
  virtual void visit(NumberSubexpression* numberSubexpression);
  virtual void visit(NumberExpression* numberExpression);
  virtual void visit(Objective* objective);
  virtual void visit(ElementSet* elementSet);
  virtual void visit(Fraction* fraction);
  virtual void visit(SetSize* setSize);
  virtual void visit(ElementNumbers* elementNumbers);
  virtual void visit(Constraint* constraint);
};

struct edge {
  int weight;
  int loc;
};

class MbolElementVisitorTypeHelper : public MbolElementVisitor {
  public:
  map<string,map<string,edge> > graph;
  set<string> temporaries;
  set<string> variables;
  set<string> used;
  map<string,list<list<string> > > mapTypes;
  map<string,vector<string> > tupleTypes;
  map<string,Type*> types;
  set<string> integerConstraints;
  MbolElementVisitorTypeHelper();
  virtual void visit(ElementExpression* elementExpression);
  virtual void visit(SetCreator* setCreator);
  virtual void visit(Program* program);
  virtual void visit(Constraint* constraint);
  virtual void visit(Qualifier* qualifier);
  virtual void visit(ElementSet* elementSet);
  virtual void visit(ElementVariable* elementVariable);
  virtual void visit(ElementNumbers* elementNumbers);
  virtual void visit(NumberVariable* numberVariable);
  virtual void visit(ProgramVariables* programVariables);
  virtual void visit(VariableMap* variableMap);
  void bfs();
  void initializeTypes();
};

#endif
