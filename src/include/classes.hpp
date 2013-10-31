#include<utilities.hpp>
#include<assert.h>
#include<list>
#include<sstream>
#include<visitors.hpp>
#ifndef MYCLASSES
#define MYCLASSES
using namespace std;

extern int yylineno;
extern char* yytext;

class MbolElement {
  public:
  string token;
  int lineno;
  MbolElement() {
    token = string(yytext);
    lineno = yylineno;
  }
  virtual string getName() {
    return "no name";
  }
  virtual list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    return x;
  }
  virtual void accept(MbolElementVisitor& visitor) {
    list<MbolElement*> x = getChildren();
    specialVisit(visitor);
    for (list<MbolElement*>::iterator i = x.begin(); i != x.end(); i++) {
      if (*i != NULL) {
        (*i)->accept(visitor);
      }
    }
    visit(visitor);
  }
  virtual void specialVisit(MbolElementVisitor& visitor) {
  }
  virtual void visit(MbolElementVisitor& visitor) {
    assert(0);
  }
};
class ElementSubexpression : public MbolElement {
  public:
  string value;
ElementSubexpression() {}
  string getName() {
    return "ElementSubexpression";
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((ElementSubexpression*)this);
  }
};
class ElementSet : public ElementSubexpression {
  public:
  ElementExpression* elementExpression;
  ElementSet(ElementExpression* a);
  string getName() {
    return "ElementSet";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((ElementSet*)this);
  }
};
class ElementParantheses : public ElementSubexpression {
  public:
  ElementExpression* elementExpression;
  ElementParantheses(ElementExpression* a);
  string getName() {
    return "ElementParantheses";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((ElementParantheses*)this);
  }
};
class ElementVariable : public ElementSubexpression {
  public:
  ElementVariable(string a);
  string getName() {
    return "ElementVariable: " + value;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((ElementVariable*)this);
  }
};
class ElementNumbers : public ElementSubexpression {
  public:
  string lb;
  string ub;
  ElementExpression* elementExpression;
  ElementNumbers(string a, ElementExpression* b);
  ElementNumbers(string a, string b);
  string getName() {
    return "ElementNumbers: [" + lb + ", " + ub + "]";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((ElementNumbers*)this);
  }
};
class TupleIndices : public MbolElement {
  public:
  vector<string> indices;
  TupleIndices(string a, string b);
  string getName() {
    return "TupleIndices";
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((TupleIndices*)this);
  }
};
class NumberSubexpression : public MbolElement {
  public:
  string value;
NumberSubexpression() {}
  string getName() {
    return "NumberSubexpression";
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((NumberSubexpression*)this);
  }
};
class NumberOperator : public MbolElement {
  public:
  string value;
  NumberOperator(string a);
  string getName() {
    return "NumberOperator: " + value;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((NumberOperator*)this);
  }
};
class Fraction : public NumberSubexpression {
  public:
  NumberExpression* numerator;
  NumberExpression* denominator;
  Fraction(NumberExpression* a, NumberExpression* b);
  string getName() {
    return "Fraction";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)numerator);
    x.push_back((MbolElement*)denominator);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Fraction*)this);
  }
};
class VariableMap : public NumberSubexpression {
  public:
  string variableName;
  Indices* indices;
  VariableMap(string a, string b);
  VariableMap(string a);
  VariableMap(string a, Indices* b);
  string getName() {
    return "VariableMap: " + variableName;
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)indices);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((VariableMap*)this);
  }
};
class SetSize : public NumberSubexpression {
  public:
  ElementExpression* elementExpression;
  SetSize(ElementExpression* a);
  string getName() {
    return "SetSize";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((SetSize*)this);
  }
};
class NumberVariable : public NumberSubexpression {
  public:
  NumberVariable(string a);
  string getName() {
    return "NumberVariable";
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((NumberVariable*)this);
  }
};
class NumberLiteral : public NumberSubexpression {
  public:
  string number;
  NumberLiteral(string a);
  string getName() {
    return "NumberLiteral: " + number;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((NumberLiteral*)this);
  }
};
class NumberPower : public NumberSubexpression {
  public:
  NumberExpression* power;
  NumberExpression* base;
  NumberPower(NumberExpression* a, NumberExpression* b);
  string getName() {
    return "NumberPower";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)base);
    x.push_back((MbolElement*)power);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((NumberPower*)this);
  }
};
class NumberParantheses : public NumberSubexpression {
  public:
  NumberExpression* numberExpression;
  NumberParantheses(NumberExpression* a);
  string getName() {
    return "NumberParantheses";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)numberExpression);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((NumberParantheses*)this);
  }
};
class NumberExpression : public MbolElement {
  public:
  string value;
  list<NumberSubexpression*> numberSubexpressions;
  list<NumberOperator*> numberOperators;
  NumberExpression(NumberSubexpression* a);
  void getFirstVariableName();
  string getName() {
    return "NumberExpression";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    list<NumberOperator*>::iterator j = numberOperators.begin();
    for (list<NumberSubexpression*>::iterator i = numberSubexpressions.begin(); i != numberSubexpressions.end(); i++) {
      if (i != numberSubexpressions.begin()) {
        x.push_back((MbolElement*)(*j));
        j++;
      }
      x.push_back((MbolElement*)(*i));
    }
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((NumberExpression*)this);
  }
};
class Qualifier : public MbolElement {
  public:
  ElementExpression* elementExpression;
  TupleIndices* tupleIndices;
  SetSize* setSize;
  Inequality* inequality;
  string lhs, rhs;
  string variable;
  string setCreator;
  string iter;
  string setToIter;
  Qualifier(TupleIndices* a, ElementExpression* b);
  Qualifier(string a, Inequality* b, SetSize* c);
  Qualifier(string a, Inequality* b, string c);
  Qualifier(Equation* a);
  Qualifier(string a, string b, ElementExpression* c);
  string getName() {
    return "Qualifier: " + variable;
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    x.push_back((MbolElement*)tupleIndices);
    x.push_back((MbolElement*)setSize);
    x.push_back((MbolElement*)inequality);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Qualifier*)this);
  }
};
class SetCreator : public ElementSubexpression {
  public:
  string variable;
  Qualifiers* qualifiers;
  SetCreator(string a, Qualifiers* b);
  string getName() {
    return "SetCreator";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)qualifiers);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((SetCreator*)this);
  }
  virtual void specialVisit(MbolElementVisitor& visitor) {
    visitor.specialVisit((SetCreator*)this);
  }
};
class Qualifiers : public MbolElement {
  public:
  list<Qualifier*> qualifiers;
  Qualifiers(Qualifier* a);
  string getName() {
    return "Qualifiers";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    for (list<Qualifier*>::iterator i = qualifiers.begin(); i != qualifiers.end(); i++) {
      x.push_back((MbolElement*)(*i));
    }
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Qualifiers*)this);
  }
};
class SumQualifiers : public MbolElement {
  public:
  Qualifiers* qualifiers;
  SumQualifiers(Qualifiers* a);
  SumQualifiers(string a, string b, ElementExpression* c);
  SumQualifiers(string a, string b, string c);
  string getName() {
    return "SumQualifeirs";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)qualifiers);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((SumQualifiers*)this);
  }
};
class Sum : public NumberSubexpression {
  public:
  string sumType;
  SumQualifiers* sumQualifiers;
  NumberExpression* numberExpression;
  Sum(string a, SumQualifiers* b, NumberExpression* c);
  string getName() {
    return "Sum";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)sumQualifiers);
    x.push_back((MbolElement*)numberExpression);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Sum*)this);
  }
  virtual void specialVisit(MbolElementVisitor& visitor) {
    visitor.specialVisit((Sum*)this);
  }
};
class ElementOperator : public MbolElement {
  public:
  string value;
  ElementOperator(string a);
  string getName() {
    return "ElementOperator: " + value;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((ElementOperator*)this);
  }
};
class ElementExpression : public MbolElement {
  public:
  string value;
  ElementExpression* elementExpression;
  ElementOperator* elementOperator;
  ElementSubexpression* elementSubexpression;
  ElementExpression(ElementSubexpression* a);
  ElementExpression(ElementExpression* a, ElementOperator* b, ElementSubexpression *c);
  string getName() {
    return "ElementExpression";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    x.push_back((MbolElement*)elementOperator);
    x.push_back((MbolElement*)elementSubexpression);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((ElementExpression*)this);
  }
};
class Indices : public MbolElement {
  public:
  list<ElementExpression*> elementExpressions;
  Indices(ElementExpression* a);
  Indices();
  string getName() {
    return "Indices";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    for (list<ElementExpression*>::iterator i = elementExpressions.begin(); i != elementExpressions.end(); i++) {
      x.push_back((MbolElement*)(*i));
    }
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Indices*)this);
  }
};
class Inequality : public MbolElement {
  public:
  string value;
  Inequality(string a);
  string getName() {
    return "Inequality: " + value;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Inequality*)this);
  }
};
class Equation : public MbolElement {
  public:
  Inequality* inequality;
  NumberExpression* lhs;
  NumberExpression* rhs;
  Equation(NumberExpression* a, Inequality* b, NumberExpression* c);
  string getName() {
    return "Equation";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)lhs);
    x.push_back((MbolElement*)inequality);
    x.push_back((MbolElement*)rhs);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Equation*)this);
  }
};
class Constraint : public MbolElement {
  public:
  Equation* equation;
  Equation* secondEquation;
  Qualifiers* qualifiers;
  string integerConstraint;
  Constraint(string a);
  Constraint(Equation* a);
  Constraint(Equation* a, Qualifiers* b);
  Constraint(Equation* a, Equation* b, Qualifiers* c);
  string getName() {
    return "Constraint";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)qualifiers);
    x.push_back((MbolElement*)equation);
    x.push_back((MbolElement*)secondEquation);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Constraint*)this);
  }
};
class Constraints : public MbolElement {
  public:
  list<Constraint*> constraints;
  Constraints(Constraint* a);
  void add(Constraint* a);
  string getName() {
    return "Constraints";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    for (list<Constraint*>::iterator i = constraints.begin(); i != constraints.end(); i++) {
      x.push_back((MbolElement*)(*i));
    }
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Constraints*)this);
  }
};
class ObjectiveType : public MbolElement {
  public:
  string value;
  ObjectiveType(string a);
  string getName() {
    return "ObjectiveType";
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((ObjectiveType*)this);
  }
};
class ProgramVariables : public MbolElement {
  public:
  list<string> variables;
  ProgramVariables(string a);
  string getName() {
    return "ProgramVariables";
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((ProgramVariables*)this);
  }
};
class Objective : public MbolElement {
  public:
  ObjectiveType* objectiveType;
  ProgramVariables* programVariables;
  NumberExpression* numberExpression;
  Objective(ObjectiveType* a, ProgramVariables* b, NumberExpression* c);
  string getName() {
    return "Objective";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)objectiveType);
    x.push_back((MbolElement*)programVariables);
    x.push_back((MbolElement*)numberExpression);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Objective*)this);
  }
};
class Program : public MbolElement {
  public:
  Objective* objective;
  Constraints* constraints;
  Program(Objective* a, Constraints* b);
  string getName() {
    return "Program";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)objective);
    x.push_back((MbolElement*)constraints);
    return x;
  }
  virtual void visit(MbolElementVisitor& visitor) {
    visitor.visit((Program*)this);
  }
  virtual void specialVisit(MbolElementVisitor& visitor) {
    visitor.specialVisit((Program*)this);
  }
};

#endif
