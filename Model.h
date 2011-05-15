#ifndef MODEL_H
#define MODEL_H
class Model;

#include "globals.h"
#include "Graph.h"
#include "respecta.h"


class Model
{

public:
    Model();
    void deleteAll();
    void checkmainname()
    {
            MyGraphType * tmp = (*subtasks)[mainName];
            if(tmp==NULL)std::cout<<"VERYBAD"<<std::endl;
    }
    void checkname()
    {
            MyGraphType * tmp = (*subtasks)[mainName];
            std::cout<<"VERTICES:"<<boost::num_vertices(*tmp)<<"EDGES:"<<boost::num_edges(*tmp)<<std::endl;
    }
    bool checkTransCondAvailabe(BaseState * source,QString cond);
    bool checkSubtaskExists(std::string Name);
    BaseState * getState(QString name, std::string subtaskName);
    void setMainName(QString newName);
    void save(QString filename);
    void deleteTransition(Transition * transition);
    void deleteState(BaseState * state);
    bool addState(BaseState * item, std::string subtaskName);
    bool tryInsertTransition(Transition * trans);
    bool checkNameAvailable(QString name);
    void addSubtask(QString name);
    QStringList getTasksNameLists();
    QStringList getTasksNameListsWithoutMain();
    QStringList getAllStateNames(std::string sub);
    //bool checkStateNameIsAvailable( MyGraphType &G, QString given);
    void checkIfOK();
    bool checkNameAvailable(QString name, MyGraphType * G);
    std::string getSubtaskName(QString StateName);
    bool ReplaceState(BaseState * oldState, BaseState * newState,  QString oldStateName);

    void MoveTransitionUp(BaseState * st, int index);
    void MoveTransitionDown(BaseState * st, int index);

    std::vector<Transition *> getTransitions(BaseState * state);

    bool checkTransitonExists(Transition * trans);

    boost::graph_traits<MyGraphType>::edge_iterator findEdge ( MyGraphType * graph, Transition * toFind);
    boost::graph_traits<MyGraphType>::vertex_iterator findVertex ( MyGraphType * graph, BaseState * toFind);
    void printStates(MyGraphType *G, std::string FileName, bool ifMain);
    bool checkStateNameAvailable(MyGraphType *G, QString given);
    QStringList getStateNames(MyGraphType G);


    void setView(RESpecTa * newres){res=newres;}
    std::string getMainName(){return mainName;}

    bool checkTransCondAvailabe(Transition * tr,QString cond);
    signals:
    void reportError(QString);

private:
    RESpecTa * res;
    std::string mainName;
    std::map<std::string, MyGraphType *> * subtasks;
};

#endif // MODEL_H
