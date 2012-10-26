#include<MaxFlow.hpp>;
MaxFlow::init() {
    IloModel model(env);
    g_env=env;
    try {
        IloExpr t1(env);
        for(set<int>::iterator t0=V.begin();t0!=V.end();t0++) {
            int j=*t0;
            IloExpr t2(env);
            t2=t2+f[s][j];
            t1=t1+t2;
        }
        IloExpr objExp(env);
        objExp=objExp+t1;
        IloObjective obj=IloMaximize(env,objExp);
        model.add(obj);
        set<int> t9;
        t9.insert(s);
        set<int> t10;
        t10.insert(t);
        set<int> t11=t9;
        t11.insert(t10.begin(),t10.end());
        set<int> t12=V;
        for(set<int>::iterator iter=(t11).begin();iter!=(t11).end();iter++) {
            t12.erase(*iter);
        }
        for(set<int>::iterator t13=t12.begin();t13!=t12.end();t13++) {
            int i=*t13;
            {
                IloExpr t4(env);
                for(set<int>::iterator t3=V.begin();t3!=V.end();t3++) {
                    int j=*t3;
                    IloExpr t5(env);
                    t5=t5+f[i][j];
                    t4=t4+t5;
                }
                IloExpr exp1(env);
                exp1=exp1+t4;
                IloExpr t7(env);
                for(set<int>::iterator t6=V.begin();t6!=V.end();t6++) {
                    int j=*t6;
                    IloExpr t8(env);
                    t8=t8+f[j][i];
                    t7=t7+t8;
                }
                IloExpr exp2(env);
                exp2=exp2+t7;
                model.add(exp1==exp2);
            }
        }
        {
            for(set<int>::iterator t14=V.begin();t14!=V.end();t14++) {
                int i=*t14;
                for(set<int>::iterator t15=V.begin();t15!=V.end();t15++) {
                    int j=*t15;
                    {
                        IloExpr exp1(env);
                        exp1=exp1+f[i][j];
                        IloExpr exp2(env);
                        exp2=exp2+w[i][j];
                        model.add(exp1<=exp2);
                    }
                }
            }
        }
        {
            for(set<int>::iterator t16=V.begin();t16!=V.end();t16++) {
                int i=*t16;
                {
                    IloExpr exp1(env);
                    exp1=exp1+f[i][s];
                    IloExpr exp2(env);
                    exp2=exp2+0;
                    model.add(exp1==exp2);
                }
            }
        }
        {
            for(set<int>::iterator t17=V.begin();t17!=V.end();t17++) {
                int i=*t17;
                {
                    IloExpr exp1(env);
                    exp1=exp1+f[t][i];
                    IloExpr exp2(env);
                    exp2=exp2+0;
                    model.add(exp1==exp2);
                }
            }
        }
        cplex=new IloCplex(model);
    }
    catch(IloException& ex) {
        cout << ex << endl;
        return true;
    }
    env.end();
    return retValue;
}
bool solve() {
    cplex.solve();
    return true;
}
double objValue() {
    return cplex.getValue(objExp);
    for(map<int,map<int,MyIloNumVar> >::iterator iter0=f.begin();iter0!=f.end();iter0++) {
        for(map<int,MyIloNumVar>::iterator iter1=iter0->second.begin();iter1!=iter0->second.end();iter1++) {
            retValue.f[iter0->first][iter1->first]=cplex.getValue(iter1->second);
        }
    }
