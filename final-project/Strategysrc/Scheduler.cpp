#include "../Strategyheaders/Scheduler.hpp"
#include "../Project/Project.hpp"
#include "../Task/Task.hpp"
#include <typeinfo>
using std::cout;
using std::endl;
Scheduler::Scheduler(Tasks* t2) : Prioritize(t2){ }
Tasks* Scheduler::sort(){
                        if(typeid(Task)==typeid(*myTask)){return myTask;}
                        if (typeid(Project) == typeid(*myTask)){
                                Project* tasks = dynamic_cast<Project*>(myTask);
                                vector<Tasks*>* v = tasks->getTasks();
                                if(v->size() ==0){return tasks;}
                                if(v->size() ==1){
                                        if(typeid(Project) == typeid(*v->at(0))){
                                                Tasks* temp = v->at(0);
                                                v->at(0) = (new Scheduler(temp))->sort();
                                                v->at(0)->setParent(tasks);
                                        }
                                        return tasks;
                                }

                                string key = "";
                                for(int i=1; i<v->size(); ++i){
                                        if(typeid(Project) == typeid(*v->at(i))){
                                                Tasks* temp = v->at(i);
                                                v->at(i) = (new Scheduler(v->at(i)))->sort(); v->at(i)->setParent(tasks);
                                                key = v->at(i)->findClosestDeadline();
                                        }
                                        else {key = v->at(i)->getDeadline();}

                                        for(int j = i-1; j>=0; --j){
                                                if(tasks->isLessThan(v->at(i)->getDeadline(),key )){
                                                        Tasks* swap = v->at(j+1);
                                                        v->at(j+1) = v->at(j);
                                                        v->at(j) = swap;
                                                }
                                                else{break;}
                                        }

                                }
                                return tasks;
                        }
                        return myTask;
}

