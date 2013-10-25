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
    assert(0);
  }
};

class ElementSet : public MbolElement {
  public:
  string value;
  ElementExpression* elementExpression;
  ElementSet(ElementExpression* a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "ElementSet";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    return x;
  }
};
class ElementParantheses : public MbolElement {
  public:
  string value;
  ElementExpression* elementExpression;
  ElementParantheses(ElementExpression* a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "ElementParantheses";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    return x;
  }
};
class ElementVariable : public MbolElement {
  public:
  string value;
  ElementVariable(string a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "ElementVariable: " + value;
  }
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
  string getName() {
    return "ElementNumbers";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    return x;
  }
};
class TupleIndices : public MbolElement {
  public:
  vector<string> indices;
  TupleIndices(string a,string b);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "TupleIndices";
  }
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
  string getName() {
    return "ElementSubexpression";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementSet);
    x.push_back((MbolElement*)setCreator);
    x.push_back((MbolElement*)elementParantheses);
    x.push_back((MbolElement*)elementVariable);
    x.push_back((MbolElement*)elementNumbers);
    return x;
  }
};
//class NumberParanthesis;
class NumberSubexpression : public MbolElement {
  public:
  string value;
NumberSubexpression() {}
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "NumberSubexpression";
  }
};
class NumberOperator : public MbolElement {
  public:
  string value;
  NumberOperator(string a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "NumberOperator: " + value;
  }
};
class Fraction : public NumberSubexpression {
  public:
  NumberExpression* numerator;
  NumberExpression* denominator;
  Fraction(NumberExpression* a,NumberExpression* b);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "Fraction";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)numerator);
    x.push_back((MbolElement*)denominator);
    return x;
  }
};
class VariableMap : public NumberSubexpression {
  public:
  string variableName;
  Indices* indices;
  VariableMap(string a,string b);
  VariableMap(string a);
  VariableMap(string a,Indices* b);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "VariableMap: " + variableName;
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)indices);
    return x;
  }
};
class SetSize : public NumberSubexpression {
  public:
  ElementExpression* elementExpression;
  SetSize(ElementExpression* a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "SetSize";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)elementExpression);
    return x;
  }
};
class NumberVariable : public NumberSubexpression {
  public:
  NumberVariable(string a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "NumberVariable";
  }
};
class NumberLiteral : public NumberSubexpression {
  public:
  string number;
  NumberLiteral(string a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "NumberLiteral: " + number;
  }
};
class NumberPower : public NumberSubexpression {
  public:
  NumberExpression* power;
  NumberExpression* base;
  NumberPower(NumberExpression* a,NumberExpression* b);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "NumberPower";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)base);
    x.push_back((MbolElement*)power);
    return x;
  }
};
class NumberParantheses : public NumberSubexpression {
  public:
  NumberExpression* numberExpression;
  NumberParantheses(NumberExpression* a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "NumberParantheses";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)numberExpression);
    return x;
  }
};
class NumberExpression : public MbolElement {
  public:
  string value;
  list<NumberSubexpression*> numberSubexpressions;
  list<NumberOperator*> numberOperators;
  NumberExpression(NumberSubexpression* a);
  void getFirstVariableName(); 
  virtual void accept(MbolElementVisitor& visitor);
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
};
class SetCreator : public MbolElement {
  public:
  string value;
  string variable;
  Qualifiers* qualifiers;
  SetCreator(string a,Qualifiers* b);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "SetCreator";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)qualifiers);
    return x;
  }
};
class Qualifiers : public MbolElement {
  public:
  list<Qualifier*> qualifiers;
  Qualifiers(Qualifier* a);
  virtual void accept(MbolElementVisitor& visitor);
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
};
class SumQualifiers : public MbolElement {
  public:
  Qualifiers* qualifiers;
  SumQualifiers(Qualifiers* a);
  SumQualifiers(string a,string b,ElementExpression* c);
  SumQualifiers(string a,string b,string c);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "SumQualifeirs";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)qualifiers);
    return x;
  }
};
class Sum : public NumberSubexpression {
  public:
  string sumType;
  SumQualifiers* sumQualifiers;
  NumberExpression* numberExpression;
  Sum(string a,SumQualifiers* b,NumberExpression* c);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "Sum";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)sumQualifiers);
    x.push_back((MbolElement*)numberExpression);
    return x;
  }
};
class ElementOperator : public MbolElement {
  public:
  string value;
  ElementOperator(string a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "ElementOperator: " + value;
  }
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
};
class Indices : public MbolElement {
  public:
  list<ElementExpression*> elementExpressions;
  Indices(ElementExpression* a);
  Indices();
  virtual void accept(MbolElementVisitor& visitor);
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
};
class Inequality : public MbolElement {
  public:
  string value;
  Inequality(string a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "Inequality: " + value;
  }
};
class Equation : public MbolElement {
  public:
  Inequality* inequality;
  NumberExpression* lhs;
  NumberExpression* rhs;
  Equation(NumberExpression* a,Inequality* b,NumberExpression* c);
  virtual void accept(MbolElementVisitor& visitor);
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
};
class Constraint : public MbolElement {
  public:
  Equation* equation;
  Equation* secondEquation;
  Qualifiers* qualifiers;
  string integerConstraint;
  Constraint(string a);
  Constraint(Equation* a);
  Constraint(Equation* a,Qualifiers* b);
  Constraint(Equation* a, Equation* b, Qualifiers* c);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "Constraint";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)equation);
    x.push_back((MbolElement*)secondEquation);
    x.push_back((MbolElement*)qualifiers);
    return x;
  }
};
class Constraints : public MbolElement {
  public:
  list<Constraint*> constraints;
  Constraints(Constraint* a);
  void add(Constraint* a);
  virtual void accept(MbolElementVisitor& visitor);
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
};
class ObjectiveType : public MbolElement {
  public:
  string value;
  ObjectiveType(string a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "ObjectiveType";
  }
};
class ProgramVariables : public MbolElement {
  public:
  list<string> variables;
  ProgramVariables(string a);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "ProgramVariables";
  }
};
class Objective : public MbolElement {
  public:
  ObjectiveType* objectiveType;
  ProgramVariables* programVariables;
  NumberExpression* numberExpression;
  Objective(ObjectiveType* a,ProgramVariables* b,NumberExpression* c);
  virtual void accept(MbolElementVisitor& visitor);
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
};
class Program : public MbolElement {
  public:
  Objective* objective;
  Constraints* constraints;
  Program(Objective* a,Constraints* b);
  virtual void accept(MbolElementVisitor& visitor);
  string getName() {
    return "Program";
  }
  list<MbolElement*> getChildren() {
    list<MbolElement*> x;
    x.push_back((MbolElement*)objective);
    x.push_back((MbolElement*)constraints);
    return x;
  }
};

#endif
