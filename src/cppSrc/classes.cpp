#include<classes.hpp>

SetCreator::SetCreator(string a,Qualifiers* b) {
    variable=a;
    qualifiers=b;
    value=temporary("tSet");
}
void SetCreator::accept(MbolElementVisitor& visitor) {
    visitor.specialVisit(this);
    qualifiers->accept(visitor);
    visitor.visit(this);
}
ElementSet::ElementSet(ElementExpression* a) {
    elementExpression=a;
    value=temporary("tSet");
}
void ElementSet::accept(MbolElementVisitor& visitor) {
    elementExpression->accept(visitor);
    visitor.visit(this);
}
ElementParantheses::ElementParantheses(ElementExpression* a) {
    elementExpression=a;
    value=a->value;
}
void ElementParantheses::accept(MbolElementVisitor& visitor) {
    elementExpression->accept(visitor);
    visitor.visit(this);
}
ElementVariable::ElementVariable(string a) {
    value=a;
}
void ElementVariable::accept(MbolElementVisitor& visitor) {
    visitor.visit(this);
}
ElementNumbers::ElementNumbers(string a,ElementExpression* b) {
    lb=a;
    ub=b->value;
    elementExpression=b;
    value=temporary("tNumberRange");
}
ElementNumbers::ElementNumbers(string a,string b) {
    lb=a;
    ub=b;
    elementExpression=NULL;
    value=temporary("tNumberRange");
}
void ElementNumbers::accept(MbolElementVisitor& visitor) {
    if(elementExpression!=NULL) {
        elementExpression->accept(visitor);
    }
    visitor.visit(this);
}
TupleIndices::TupleIndices(string a,string b) {
    indices.push_back(a);
    indices.push_back(b);
}
void TupleIndices::accept(MbolElementVisitor& visitor) {
    visitor.visit(this);
}
ElementSubexpression::ElementSubexpression(SetCreator* a) {
    setCreator=a;
    elementSet=NULL;
    elementParantheses=NULL;
    elementVariable=NULL;
    elementNumbers=NULL;
    value=a->value;
}
ElementSubexpression::ElementSubexpression(ElementSet* a) {
    setCreator=NULL;
    elementSet=a;
    elementParantheses=NULL;
    elementVariable=NULL;
    elementNumbers=NULL;
    value=a->value;
}
ElementSubexpression::ElementSubexpression(ElementParantheses* a) {
    setCreator=NULL;
    elementSet=NULL;
    elementParantheses=a;
    elementVariable=NULL;
    elementNumbers=NULL;
    value=a->value;
}
ElementSubexpression::ElementSubexpression(ElementVariable* a) {
    setCreator=NULL;
    elementSet=NULL;
    elementParantheses=NULL;
    elementVariable=a;
    elementNumbers=NULL;
    value=a->value;
}
ElementSubexpression::ElementSubexpression(ElementNumbers* a) {
    setCreator=NULL;
    elementSet=NULL;
    elementParantheses=NULL;
    elementVariable=NULL;
    elementNumbers=a;
    value=a->value;
}
void ElementSubexpression::accept(MbolElementVisitor& visitor) {
    if(setCreator!=NULL) {
        setCreator->accept(visitor);
    }
    if(elementSet!=NULL) {
        elementSet->accept(visitor);
    }
    if(elementParantheses!=NULL) {
        elementParantheses->accept(visitor);
    }
    if(elementVariable!=NULL) {
        elementVariable->accept(visitor);
    }
    if(elementNumbers!=NULL) {
        elementNumbers->accept(visitor);
    }
    visitor.visit(this);
}
NumberOperator::NumberOperator(string a) {
    value=a;
}
void NumberOperator::accept(MbolElementVisitor& visitor) {
    visitor.visit(this);
}
Fraction::Fraction(NumberExpression* a,NumberExpression* b) {
    numerator=a;
    denominator=b;
    value=temporary("tFraction");
}
void Fraction::accept(MbolElementVisitor& visitor) {
    numerator->accept(visitor);
    denominator->accept(visitor);
    visitor.visit(this);
}
VariableMap::VariableMap(string a,string b) {
    variableName=a;
    indices=new Indices(new ElementExpression(new ElementSubexpression(new ElementVariable(b))));
    value=temporary("tVariableMap");
}
VariableMap::VariableMap(string a,Indices* b) {
    variableName=a;
    indices=b;
    value=temporary("tVariableMap");
}
void VariableMap::accept(MbolElementVisitor& visitor) {
    indices->accept(visitor);
    visitor.visit(this);
}
SetSize::SetSize(ElementExpression* a) {
    elementExpression=a;
    value=temporary("tSetSize");
}
void SetSize::accept(MbolElementVisitor& visitor) {
    elementExpression->accept(visitor);
    visitor.visit(this);
}
NumberVariable::NumberVariable(string a) {
    value=a;
}
void NumberVariable::accept(MbolElementVisitor& visitor) {
    visitor.visit(this);
}
NumberLiteral::NumberLiteral(string a) {
    number=a;
    value=temporary("tLiteral");
}
void NumberLiteral::accept(MbolElementVisitor& visitor) {
    visitor.visit(this);
}
NumberParantheses::NumberParantheses(NumberExpression* a) {
    numberExpression=a;
    value=a->value;
}
void NumberParantheses::accept(MbolElementVisitor& visitor) {
    numberExpression->accept(visitor);
    visitor.visit(this);
}
NumberSubexpression::NumberSubexpression(Fraction* a) {
    fraction=a;
    variableMap=NULL;
    setSize=NULL;
    numberLiteral=NULL;
    numberVariable=NULL;
    sum=NULL;
    numberParantheses=NULL;
    value=a->value;
}
NumberSubexpression::NumberSubexpression(VariableMap* a) {
    fraction=NULL;
    variableMap=a;
    setSize=NULL;
    numberLiteral=NULL;
    numberVariable=NULL;
    sum=NULL;
    numberParantheses=NULL;
    value=a->value;
}
NumberSubexpression::NumberSubexpression(SetSize* a) {
    fraction=NULL;
    variableMap=NULL;
    setSize=a;
    numberLiteral=NULL;
    numberVariable=NULL;
    sum=NULL;
    numberParantheses=NULL;
    value=a->value;
}
NumberSubexpression::NumberSubexpression(NumberLiteral* a) {
    fraction=NULL;
    variableMap=NULL;
    setSize=NULL;
    numberLiteral=a;
    numberVariable=NULL;
    sum=NULL;
    numberParantheses=NULL;
    value=a->value;
}
NumberSubexpression::NumberSubexpression(NumberVariable* a) {
    fraction=NULL;
    variableMap=NULL;
    setSize=NULL;
    numberLiteral=NULL;
    numberVariable=a;
    sum=NULL;
    numberParantheses=NULL;
    value=a->value;
}
NumberSubexpression::NumberSubexpression(Sum* a) {
    fraction=NULL;
    variableMap=NULL;
    setSize=NULL;
    numberLiteral=NULL;
    numberVariable=NULL;
    sum=a;
    numberParantheses=NULL;
    value=a->value;
}
NumberSubexpression::NumberSubexpression(NumberParantheses* a) {
    fraction=NULL;
    variableMap=NULL;
    setSize=NULL;
    numberLiteral=NULL;
    numberVariable=NULL;
    sum=NULL;
    numberParantheses=a;
    value=a->value;
}
void NumberSubexpression::accept(MbolElementVisitor& visitor) {
    if(sum!=NULL) {
        sum->accept(visitor);
    }
    if(setSize!=NULL) {
        setSize->accept(visitor);
    }
    if(fraction!=NULL) {
        fraction->accept(visitor);
    }
    if(variableMap!=NULL) {
        variableMap->accept(visitor);
    }
    if(numberVariable!=NULL) {
        numberVariable->accept(visitor);
    }
    if(numberLiteral!=NULL) {
        numberLiteral->accept(visitor);
    }
    if(numberParantheses!=NULL) {
        numberParantheses->accept(visitor);
    }
    visitor.visit(this);
}
NumberExpression::NumberExpression(NumberSubexpression* a) {
    numberSubexpressions.push_back(a);
    value=temporary("tNumberExpression");
}
void NumberExpression::accept(MbolElementVisitor& visitor) {
    for(list<NumberSubexpression*>::iterator i=numberSubexpressions.begin();i!=numberSubexpressions.end();i++) {
        (*i)->accept(visitor);
    }
    for(list<NumberOperator*>::iterator i=numberOperators.begin();i!=numberOperators.end();i++) {
        (*i)->accept(visitor);
    }
    visitor.visit(this);
}
Qualifier::Qualifier(Equation* a) {
    equation=a;
    elementExpression=NULL;
    tupleIndices=NULL;
    iter=temporary("tIter");
    setToIter=temporary("tSet");
}
Qualifier::Qualifier(TupleIndices* a,ElementExpression* b) {
    tupleIndices=a;
    setCreator="in";
    elementExpression=b;
    equation=NULL;
    iter=temporary("tIter");
    setToIter=temporary("tSet");
}
Qualifier::Qualifier(string a,string b,ElementExpression* c) {
    variable=a;
    setCreator=b;
    elementExpression=c;
    tupleIndices=NULL;
    equation=NULL;
    iter=temporary("tIter");
    setToIter=temporary("tSet");
}
void Qualifier::accept(MbolElementVisitor& visitor) {
    if(tupleIndices!=NULL) {
        tupleIndices->accept(visitor);
    }
    if(equation!=NULL) {
        equation->accept(visitor);
    }
    if(elementExpression!=NULL) {
        elementExpression->accept(visitor);
    }
    visitor.visit(this);
}
Qualifiers::Qualifiers(Qualifier* a) {
    qualifiers.push_back(a);
}
void Qualifiers::accept(MbolElementVisitor& visitor) {
    for(list<Qualifier*>::iterator i=qualifiers.begin();i!=qualifiers.end();i++) {
        (*i)->accept(visitor);
    }
    visitor.visit(this);
}
SumQualifiers::SumQualifiers(Qualifiers* a) {
    qualifiers=a;
}
SumQualifiers::SumQualifiers(string a,string b,ElementExpression* c) {
    qualifiers=new Qualifiers(new Qualifier(a,"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(b,c)))));
}
SumQualifiers::SumQualifiers(string a,string b,string c) {
    qualifiers=new Qualifiers(new Qualifier(a,"in",new ElementExpression(new ElementSubexpression(new ElementNumbers(b,c)))));
}
void SumQualifiers::accept(MbolElementVisitor& visitor) {
    qualifiers->accept(visitor);
    visitor.visit(this);
}
Sum::Sum(string a,SumQualifiers* b,NumberExpression* c) {
    sumType=a;
    sumQualifiers=b;
    numberExpression=c;
    value=temporary("tSetSum");
}
void Sum::accept(MbolElementVisitor& visitor) {
    visitor.specialVisit(this);
    sumQualifiers->accept(visitor);
    numberExpression->accept(visitor);
    visitor.visit(this);
}
ElementOperator::ElementOperator(string a) {
    value=a;
}
void ElementOperator::accept(MbolElementVisitor& visitor) {
    visitor.visit(this);
}
ElementExpression::ElementExpression(ElementSubexpression* a) {
    elementExpression=NULL;
    elementOperator=NULL;
    elementSubexpression=a;
    value=a->value;
}
ElementExpression::ElementExpression(ElementExpression* a,ElementOperator* b,ElementSubexpression *c) {
    elementExpression=a;
    elementOperator=b;
    elementSubexpression=c;
    value=temporary("tElement");
}
void ElementExpression::accept(MbolElementVisitor& visitor) {
    if(elementExpression!=NULL) {
        elementExpression->accept(visitor);
    }
    if(elementOperator!=NULL) {
        elementOperator->accept(visitor);
    }
    if(elementSubexpression!=NULL) {
        elementSubexpression->accept(visitor);
    }
    visitor.visit(this);
}
Indices::Indices(ElementExpression* a) {
    elementExpressions.push_back(a);
}
void Indices::accept(MbolElementVisitor& visitor) {
    for(list<ElementExpression*>::iterator i=elementExpressions.begin();i!=elementExpressions.end();i++) {
        (*i)->accept(visitor);
    }
    visitor.visit(this);
}
Inequality::Inequality(string a) {
    value=a;
}
void Inequality::accept(MbolElementVisitor& visitor) {
    visitor.visit(this);
}
Equation::Equation(NumberExpression* a,Inequality* b,NumberExpression* c) {
    lhs=a;
    inequality=b;
    rhs=c;
}
void Equation::accept(MbolElementVisitor& visitor) {
    lhs->accept(visitor);
    inequality->accept(visitor);
    rhs->accept(visitor);
    visitor.visit(this);
}
Constraint::Constraint(string a) {
    integerConstraint=a;
    equation=NULL;
    qualifiers=NULL;
}
Constraint::Constraint(Equation* a) {
    integerConstraint="";
    equation=a;
    qualifiers=NULL;
}
Constraint::Constraint(Equation* a,Qualifiers* b) {
    integerConstraint="";
    equation=a;
    qualifiers=b;
}
void Constraint::accept(MbolElementVisitor& visitor) {
    if(qualifiers!=NULL) {
        qualifiers->accept(visitor);
    }
    if(equation!=NULL) {
        equation->accept(visitor);
    } 
    visitor.visit(this);
}
Constraints::Constraints(Constraint* a) {
    constraints.push_back(a);
}
void Constraints::accept(MbolElementVisitor& visitor) {
    for(list<Constraint*>::iterator i=constraints.begin();i!=constraints.end();i++) {
        (*i)->accept(visitor);
    }
    visitor.visit(this);
}
ObjectiveType::ObjectiveType(string a) {
    value=a;
}
void ObjectiveType::accept(MbolElementVisitor& visitor) {
    visitor.visit(this);
}
ProgramVariables::ProgramVariables(string a) {
    variables.push_back(a);
}
void ProgramVariables::accept(MbolElementVisitor& visitor) {
    visitor.visit(this);
}
Objective::Objective(ObjectiveType* a,ProgramVariables* b,NumberExpression* c) {
    objectiveType=a;
    programVariables=b;
    numberExpression=c;
}
void Objective::accept(MbolElementVisitor& visitor) {
    objectiveType->accept(visitor);
    programVariables->accept(visitor);
    numberExpression->accept(visitor);
    visitor.visit(this);
}
Program::Program(Objective* a,Constraints* b) {
    objective=a;
    constraints=b;
}
void Program::accept(MbolElementVisitor& visitor) {
    visitor.specialVisit(this);
    objective->accept(visitor);
    constraints->accept(visitor);
    visitor.visit(this);
}
