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
    virtual void specialVisit(const Program* program) {
    }
    virtual void specialVisit(const Sum* sum) {
    }
    virtual void specialVisit(const SetCreator* setCreator) {
    }
    virtual void visit(const ElementExpression* elementExpression) {
    }
    virtual void visit(const ElementOperator* elementOperator) {
    }
    virtual void visit(const Qualifier* qualifier) {
    }
    virtual void visit(const SetCreator* setCreator) {
    }
    virtual void visit(const Equation* equation) {
    }
    virtual void visit(const VariableMap* variableMap) {
    }
    virtual void visit(const Sum* sum) {
    }
    virtual void visit(const Fraction* fraction) {
    }
    virtual void visit(const NumberExpression* numberExpression) {
    }
    virtual void visit(const Objective* objective) {
    }
    virtual void visit(const ElementSet* elementSet) {
    }
    virtual void visit(const SetSize* setSize) {
    }
    virtual void visit(const ElementNumbers* elementNumbers) {
    }
    virtual void visit(const Constraint* constraint) {
    }
    virtual void visit(const ElementParantheses* elementParantheses) {
    }
    virtual void visit(const ElementVariable* elementVariable) {
    }
    virtual void visit(const ElementSubexpression* elementSubexpression) {
    }
    virtual void visit(const NumberVariable* numberVariable) {
    }
    virtual void visit(const TupleIndices* tupleIndices) {
    }
    virtual void visit(const NumberLiteral* numberLiteral) {
    }
    virtual void visit(const NumberParantheses* numberParantheses) {
    }
    virtual void visit(const NumberSubexpression* numberSubexpression) {
    }
    virtual void visit(const SumQualifiers* sumQualifiers) {
    }
    virtual void visit(const Indices* indices) {
    }
    virtual void visit(const Inequality* inequality) {
    }
    virtual void visit(const NumberOperator* numberOperator) {
    }
    virtual void visit(const Qualifiers* qualifiers) {
    }
    virtual void visit(const Constraints* constraints) {
    }
    virtual void visit(const ObjectiveType* objectiveType) {
    }
    virtual void visit(const ProgramVariables* programVariables) {
    }
    virtual void visit(const Program* program) {
    }
};

class MbolElementVisitorPrinter : public MbolElementVisitor {
    public:
    MbolElementVisitorPrinter();
    virtual void visit(const ElementExpression* elementExpression);
    virtual void visit(const Qualifier* qualifier);
    virtual void specialVisit(const SetCreator* setCreator);
    virtual void visit(const SetCreator* setCreator);
    virtual void visit(const Equation* equation);
    virtual void visit(const VariableMap* variableMap);
    virtual void specialVisit(const Sum* sum);
    virtual void visit(const Sum* sum);
    virtual void visit(const NumberExpression* numberExpression);
    virtual void visit(const Objective* objective);
    virtual void visit(const ElementSet* elementSet);
    virtual void visit(const Fraction* fraction);
    virtual void visit(const SetSize* setSize);
    virtual void visit(const ElementNumbers* elementNumbers);
    virtual void visit(const Constraint* constraint);
};

class MbolElementVisitorCPLEX : public MbolElementVisitor {
    public:
    string code;
    map<string,Type*> types;
    string className;
    bool quiet;
    MbolElementVisitorCPLEX(map<string,Type*> a,bool d,string e);
    virtual void visit(const ElementExpression* elementExpression);
    virtual void visit(const Program* program);
    virtual void specialVisit(const Program* program);
    virtual void visit(const Qualifier* qualifier);
    virtual void specialVisit(const SetCreator* setCreator);
    virtual void visit(const NumberLiteral* numberLiteral);
    virtual void visit(const SetCreator* setCreator);
    virtual void visit(const Equation* equation);
    virtual void visit(const VariableMap* variableMap);
    virtual void specialVisit(const Sum* sum);
    virtual void visit(const Sum* sum);
    virtual void visit(const NumberExpression* numberExpression);
    virtual void visit(const Objective* objective);
    virtual void visit(const ElementSet* elementSet);
    virtual void visit(const Fraction* fraction);
    virtual void visit(const SetSize* setSize);
    virtual void visit(const ElementNumbers* elementNumbers);
    virtual void visit(const Constraint* constraint);
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
    virtual void visit(const ElementExpression* elementExpression);
    virtual void visit(const SetCreator* setCreator);
    virtual void visit(const Program* program);
    virtual void visit(const Constraint* constraint);
    virtual void visit(const Qualifier* qualifier);
    virtual void visit(const ElementSet* elementSet);
    virtual void visit(const ElementVariable* elementVariable);
    virtual void visit(const ElementNumbers* elementNumbers);
    virtual void visit(const NumberVariable* numberVariable);
    virtual void visit(const ProgramVariables* programVariables);
    virtual void visit(const VariableMap* variableMap);
    void bfs();
    void initializeTypes();
};

#endif
