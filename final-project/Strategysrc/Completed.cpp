#include "../Strategyheaders/Completed.hpp"
#include "../Task/Task.hpp"
#include "../Project/Project.hpp"
#include <typeinfo>

#include <iostream>
using std::cout; using std::endl;

Completed::Completed(Tasks* t2): Prioritize(t2){}
Tasks* Completed::sort(){ 
	if(typeid(Task)==typeid(*myTask)){return myTask;}
	if(typeid(Project) == typeid(*myTask)){ //insertion sort
		Project* tasks = dynamic_cast<Project*>(myTask);
		vector<Tasks*>* v = tasks->getTasks();
		
		if(v->size() == 0){ return tasks;}
		if(v->size() ==1){
			if(typeid(Project) == typeid(*v->at(0))){
				Tasks* temp = v->at(0);
				v->at(0) = (new Completed(temp))->sort(); v->at(0)->setParent(tasks);
			}
			return tasks;
		}

		for(int i=1; i<v->size(); ++i ){
			if(typeid(Project) == typeid(*v->at(i))){
				Tasks* temp = v->at(i);
                                v->at(i) = (new Completed(v->at(i)))->sort(); v->at(i)->setParent(tasks);
                        }
			for(int j = i-1; j >=0; --j){
				if((v->at(j+1)->getStatus()==false)&&(v->at(j)->getStatus())){
					Tasks* temp = v->at(j+1);
					v->at(j+1) = v->at(j);
					v->at(j) = temp;
				}else{break;}
			}
			 if(typeid(Project) == typeid(*v->at(i))){
                                Tasks* temp = v->at(i);
                                v->at(i) = (new Completed(v->at(i)))->sort(); v->at(i)->setParent(tasks);
                        }


		}
	}return myTask;
	
}

