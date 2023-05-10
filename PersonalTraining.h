#ifndef HOMEWORK_PERSONALTRAINING_H
#define HOMEWORK_PERSONALTRAINING_H
#include <string>
#include <iostream>
#include "FitnessClass.h"
#include "Member.h"
class PersonalTraining: public FitnessClass {
public:
    PersonalTraining(const string & name,const string & description,const string & instructor);
    void setSchedule(const string & schedule);
    bool operator < (const PersonalTraining & other) const;
};


#endif //HOMEWORK_PERSONALTRAINING_H
