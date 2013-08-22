#include<utilities.hpp>
#include<list>
#include<sstream>
#include<visitors.hpp>
#ifndef MYCLASSES
#define MYCLASSES
using namespace std;

extern int yylineno;

class MbolElement {
  public:
  virtual void accept(MbolElementVisitor& visitor) {
  }
};

class SetCreator : public MbolElement {
  public:
  string value;
  string variable;
  Qualifiers* qualifiers;
  SetCreator(string a,Qualifiers* b);
  virtual void accept(MbolElementVisitor& visitor);
};
class ElementSet : public MbolElement {
  public:
  string value;
  ElementExpression* elementExpression;
  ElementSet(ElementExpression* a);
  virtual void accept(MbolElementVisitor& visitor);
};
class ElementParantheses : public MbolElement {
  public:
  string value;
  ElementExpression* elementExpression;
  ElementParantheses(ElementExpression* a);
  virtual void accept(MbolElementVisitor& visitor);
};
class ElementVariable : public MbolElement {
  public:
  string value;
  ElementVariable(string a);
  virtual void accept(MbolElementVisitor& visitor);
};
class ElementNumbers : public MbolElement {
  public:
  string value;
  string lb;
  string ub;
  ElementExpression* elementExpression;
  ElementNumbers(string a,ElementExpression* b);
  ElementNumbers(string a,string b);
  virtual void accept(MbolElementVisitor& visitor);
};
class TupleIndices : public MbolElement {
  public:
  vector<string> indices;
  TupleIndices(string a,string b);
  virtual void accept(MbolElementVisitor& visitor);
};
class ElementSubexpression : public MbolElement {
  public:
  string value;
  SetCreator* setCreator;
  ElementSet* elementSet;
  ElementParantheses* elementParantheses;
  ElementVariable* elementVariable;
  ElementNumbers* elementNumbers;
  ElementSubexpression(SetCreator* a);
  ElementSubexpression(ElementSet* a);
  ElementSubexpression(ElementParantheses* a);
  ElementSubexpression(ElementVariable* a);
  ElementSubexpression(ElementNumbers* a);
  virtual void accept(MbolElementVisitor& visitor);
};
class NumberOperator : public MbolElement {
  public:
  string value;
  NumberOperator(string a);
  virtual void accept(MbolElementVisitor& visitor);
};
class Fraction : public MbolElement {
  public:
  string value;
  NumberExpression* numerator;
  NumberExpression* denominator;
  Fraction(NumberExpression* a,NumberExpression* b);
  virtual void accept(MbolElementVisitor& visitor);
};
class VariableMap : public MbolElement {
  public:
  string value;
  string variableName;
  Indices* indices;
  VariableMap(string a,string b);
  VariableMap(string a);
  VariableMap(string a,Indices* b);
  virtual void accept(MbolElementVisitor& visitor);
};
class SetSize : public MbolElement {
  public:
  string value;
  ElementExpression* elementExpression;
  SetSize(ElementExpression* a);
  virtual void accept(MbolElementVisitor& visitor);
};
class NumberVariable : public MbolElement {
  public:
  string value;
  NumberVariable(string a);
  virtual void accept(MbolElementVisitor& visitor);
};
class NumberLiteral : public MbolElement {
  public:
  string value;
  string number;
  NumberLiteral(string a);
  virtual void accept(MbolElementVisitor& visitor);
};
class NumberPower : public MbolElement {
  public:
  string value;
  NumberExpression* power;
  NumberExpression* base;
  NumberPower(NumberExpression* a,NumberExpression* b);
  virtual void accept(MbolElementVisitor& visitor);
};
class NumberParantheses : public MbolElement {
  public:
  string value;
  NumberExpression* numberExpression;
  NumberParantheses(NumberExpression* a);
  virtual void accept(MbolElementVisitor& visitor);
};
class NumberSubexpression : public MbolElement {
  public:
  string value;
  Fraction* fraction;
  VariableMap* variableMap;
  SetSize* setSize;
  NumberLiteral* numberLiteral;
  NumberVariable* numberVariable;
  NumberPower* numberPower;
  Sum* sum;
  NumberParantheses* numberParantheses;
  NumberSubexpression(Fraction* a);
  NumberSubexpression(VariableMap* a);
  NumberSubexpression(SetSize* a);
  NumberSubexpression(NumberLiteral* a);
  NumberSubexpression(NumberVariable* a);
  NumberSubexpression(Sum* a);
  NumberSubexpression(NumberParantheses* a);
  NumberSubexpression(NumberPower* a);
  virtual void accept(MbolElementVisitor& visitor);
};
class NumberExpression : public MbolElement {
  public:
  string value;
  list<NumberSubexpression*> numberSubexpressions;
  list<NumberOperator*> numberOperators;
  NumberExpression(NumberSubexpression* a);
  void getFirstVariableName(); 
  virtual void accept(MbolElementVisitor& visitor);
};
class Qualifier : public MbolElement {
  public:
  ElementExpression* elementExpression;
  TupleIndices* tupleIndices;
  SetSize* setSize;
  Inequality* inequality;
  string lhs,rhs;
  string variable;
  string setCreator;
  string iter;
  string setToIter;
  Qualifier(TupleIndices* a,ElementExpression* b);
  Qualifier(string a,Inequality* b,SetSize* c);
  Qualifier(string a,Inequality* b,string c);
  Qualifier(Equation* a);
  Qualifier(string a,string b,ElementExpression* c);
  virtual void accept(MbolElementVisitor& visitor);
};
class Qualifiers : public MbolElement {
  public:
  list<Qualifier*> qualifiers;
  Qualifiers(Qualifier* a);
  virtual void accept(MbolElementVisitor& visitor);
};
class SumQualifiers : public MbolElement {
  public:
  Qualifiers* qualifiers;
  SumQualifiers(Qualifiers* a);
  SumQualifiers(string a,string b,ElementExpression* c);
  SumQualifiers(string a,string b,string c);
  virtual void accept(MbolElementVisitor& visitor);
};
class Sum : public MbolElement {
  public:
  string value;
  string sumType;
  SumQualifiers* sumQualifiers;
  NumberSubexpression* numberSubexpression;
  Sum(string a,SumQualifiers* b,NumberSubexpression* c);
  virtual void accept(MbolElementVisitor& visitor);
};
class ElementOperator : public MbolElement {
  public:
  string value;
  ElementOperator(string a);
  virtual void accept(MbolElementVisitor& visitor);
};
class ElementExpression : public MbolElement {
  public:
  string value;
  ElementExpression* elementExpression;
  ElementOperator* elementOperator;
  ElementSubexpression* elementSubexpression;
  ElementExpression(ElementSubexpression* a);
  ElementExpression(ElementExpression* a,ElementOperator* b,ElementSubexpression *c);
  virtual void accept(MbolElementVisitor& visitor);
};
class Indices : public MbolElement {
  public:
  list<ElementExpression*> elementExpressions;
  Indices(ElementExpression* a);
  Indices();
  virtual void accept(MbolElementVisitor& visitor);
};
class Inequality : public MbolElement {
  public:
  string value;
  Inequality(string a);
  virtual void accept(MbolElementVisitor& visitor);
};
class Equation : public MbolElement {
  public:
  Inequality* inequality;
  NumberExpression* lhs;
  NumberExpression* rhs;
  Equation(NumberExpression* a,Inequality* b,NumberExpression* c);
  virtual void accept(MbolElementVisitor& visitor);
};
class Constraint : public MbolElement {
  public:
  Equation* equation;
  Qualifiers* qualifiers;
  string integerConstraint;
  Constraint(string a);
  Constraint(Equation* a);
  Constraint(Equation* a,Qualifiers* b);
  virtual void accept(MbolElementVisitor& visitor);
};
class Constraints : public MbolElement {
  public:
  list<Constraint*> constraints;
  Constraints(Constraint* a);
  void add(Constraint* a);
  virtual void accept(MbolElementVisitor& visitor);
};
class ObjectiveType : public MbolElement {
  public:
  string value;
  ObjectiveType(string a);
  virtual void accept(MbolElementVisitor& visitor);
};
class ProgramVariables : public MbolElement {
  public:
  list<string> variables;
  ProgramVariables(string a);
  virtual void accept(MbolElementVisitor& visitor);
};
class Objective : public MbolElement {
  public:
  ObjectiveType* objectiveType;
  ProgramVariables* programVariables;
  NumberExpression* numberExpression;
  Objective(ObjectiveType* a,ProgramVariables* b,NumberExpression* c);
  virtual void accept(MbolElementVisitor& visitor);
};
class Program : public MbolElement {
  public:
  Objective* objective;
  Constraints* constraints;
  Program(Objective* a,Constraints* b);
  virtual void accept(MbolElementVisitor& visitor);
};

#endif
