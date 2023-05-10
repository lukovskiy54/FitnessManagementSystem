#ifndef HOMEWORK_FITNESSCENTERMANAGER_H
#define HOMEWORK_FITNESSCENTERMANAGER_H
#include "Member.h"
#include "FitnessClass.h"
#include "PersonalTraining.h"
#include <string>
#include <iostream>
#include <vector>

class FitnessCenterManager {
    vector <Member> memberList;
    vector <FitnessClass> fClassesList;
    vector <PersonalTraining> pTrainingList;
public:
    FitnessCenterManager();
    void printFitnessTraining();
    void printClasses();
    void printMembers();
    void addMember(const Member & member);
    void addFClass(const FitnessClass & fClass);
    void addPTraining(const PersonalTraining & ptraining);
    bool removeMember(const string & memberName);
    bool removeClass(const string & className);
    bool removePTraining(const string & pTrainingName);
    Member * searchMember(const string & memberName);
    FitnessClass * searchClass(const string & className);
    PersonalTraining * searchTraining(const string & pTrainingName);
    bool enrollMember(const string & memberName,const string & className);
};
#endif //HOMEWORK_FITNESSCENTERMANAGER_H
