#include<classes.hpp>

SetCreator::SetCreator(string a, Qualifiers* b) {
  variable = a;
  qualifiers = b;
  value = temporary("tSet");
}
ElementSet::ElementSet(ElementExpression* a) {
  elementExpression = a;
  value = temporary("tSet");
}
ElementParantheses::ElementParantheses(ElementExpression* a) {
  elementExpression = a;
  value = a->value;
}
ElementVariable::ElementVariable(string a) {
  value = a;
}
ElementNumbers::ElementNumbers(string a, ElementExpression* b) {
  lb = a;
  ub = b->value;
  elementExpression = b;
  value = temporary("tNumberRange");
}
ElementNumbers::ElementNumbers(string a, string b) {
  lb = a;
  ub = b;
  elementExpression = NULL;
  value = temporary("tNumberRange");
}
TupleIndices::TupleIndices(string a, string b) {
  indices.push_back(a);
  indices.push_back(b);
}
NumberOperator::NumberOperator(string a) {
  value = a;
}
Fraction::Fraction(NumberExpression* a, NumberExpression* b) {
  numerator = a;
  denominator = b;
}
VariableMap::VariableMap(string a, string b) {
  variableName = a;
  indices = new Indices(new ElementExpression(new ElementVariable(b)));
}
VariableMap::VariableMap(string a) {
  variableName = a;
  indices = new Indices();
}
VariableMap::VariableMap(string a, Indices* b) {
  variableName = a;
  indices = b;
}
SetSize::SetSize(ElementExpression* a) {
  elementExpression = a;
}
NumberPower::NumberPower(NumberExpression* a, NumberExpression* b) {
  base = a;
  power = b;
}
NumberVariable::NumberVariable(string a) {
  value = a;
}
NumberLiteral::NumberLiteral(string a) {
  number = a;
  value = a;
}
NumberParantheses::NumberParantheses(NumberExpression* a) {
  numberExpression = a;
}
NumberExpression::NumberExpression(NumberSubexpression* a) {
  numberSubexpressions.push_back(a);
}
Qualifier::Qualifier(string a, Inequality* b, string c) {
  lhs = a;
  inequality = b;
  rhs = c;
  setSize = NULL;
  elementExpression = NULL;
  tupleIndices = NULL;
}
Qualifier::Qualifier(string a, Inequality* b, SetSize* c) {
  lhs = a;
  inequality = b;
  rhs = c->value;
  setSize = c;
  elementExpression = NULL;
  tupleIndices = NULL;
}
Qualifier::Qualifier(TupleIndices* a, ElementExpression* b) {
  tupleIndices = a;
  setCreator = "in";
  elementExpression = b;
  inequality = NULL;
  setSize = NULL;
  variable = temporary("tTuple");
  iter = temporary("tIter");
  setToIter = temporary("tSet");
}
Qualifier::Qualifier(string a, string b, ElementExpression* c) {
  variable = a;
  setCreator = b;
  elementExpression = c;
  inequality = NULL;
  tupleIndices = NULL;
  setSize = NULL;
  iter = temporary("tIter");
  setToIter = temporary("tSet");
}
Qualifiers::Qualifiers(Qualifier* a) {
  qualifiers.push_back(a);
}
SumQualifiers::SumQualifiers(Qualifiers* a) {
  qualifiers = a;
}
SumQualifiers::SumQualifiers(string a, string b, ElementExpression* c) {
  qualifiers = new Qualifiers(new Qualifier(a, "in", new ElementExpression(new ElementNumbers(b, c))));
}
SumQualifiers::SumQualifiers(string a, string b, string c) {
  qualifiers = new Qualifiers(new Qualifier(a, "in", new ElementExpression(new ElementNumbers(b, c))));
}
Sum::Sum(string a, SumQualifiers* b, NumberExpression* c) {
  sumType = a;
  sumQualifiers = b;
  numberExpression = c;
  value = temporary("tSetSum");
}
ElementOperator::ElementOperator(string a) {
  value = a;
}
ElementExpression::ElementExpression(ElementSubexpression* a) {
  elementExpression = NULL;
  elementOperator = NULL;
  elementSubexpression = a;
  value = a->value;
}
ElementExpression::ElementExpression(ElementExpression* a, ElementOperator* b, ElementSubexpression *c) {
  elementExpression = a;
  elementOperator = b;
  elementSubexpression = c;
  value = temporary("tElement");
}
Indices::Indices() {
}
Indices::Indices(ElementExpression* a) {
  elementExpressions.push_back(a);
}
Inequality::Inequality(string a) {
  value = a;
}
Equation::Equation(NumberExpression* a, Inequality* b, NumberExpression* c) {
  lhs = a;
  inequality = b;
  rhs = c;
}
Constraint::Constraint(string a) {
  integerConstraint = a;
  equation = NULL;
  secondEquation = NULL;
  qualifiers = NULL;
}
Constraint::Constraint(Equation* a) {
  integerConstraint = "";
  equation = a;
  secondEquation = NULL;
  qualifiers = NULL;
}
Constraint::Constraint(Equation* a, Qualifiers* b) {
  integerConstraint = "";
  equation = a;
  qualifiers = b;
  secondEquation = NULL;
}
Constraint::Constraint(Equation* a, Equation* b, Qualifiers* c) {
  integerConstraint = "";
  equation = a;
  secondEquation = b;
  qualifiers = c;
}
Constraints::Constraints(Constraint* a) {
  constraints.push_back(a);
}
void Constraints::add(Constraint* a) {
  constraints.push_back(a);
}
ObjectiveType::ObjectiveType(string a) {
  value = a;
}
ProgramVariables::ProgramVariables(string a) {
  variables.push_back(a);
}
Objective::Objective(ObjectiveType* a, ProgramVariables* b, NumberExpression* c) {
  objectiveType = a;
  programVariables = b;
  numberExpression = c;
}
Program::Program(Objective* a, Constraints* b) {
  objective = a;
  constraints = b;
}
