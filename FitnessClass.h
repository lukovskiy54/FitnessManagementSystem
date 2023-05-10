
#ifndef HOMEWORK_FITNESSCLASS_H
#define HOMEWORK_FITNESSCLASS_H
#include <string>
#include <iostream>
#include "Member.h"

using namespace std;

class FitnessClass {
public: FitnessClass(const string & name,
                     const string & description,
                     const string & instructor,
                     const string & schedule,
                     const int & numOfmembers);

    const string & getName() const;


    const string & getDescription() const;


    const string & getInstructor() const;


    const string & getSchedule() const;
    friend ostream & operator << (ostream & os,const FitnessClass & aClass);

    Member * getGroup(int i) const;

    void setGroup(int i, Member member);

    int getNumOfmembers() const;

    bool getFreePlaces() const;

    void setFreePlaces(bool freePlaces);

    bool operator < (const FitnessClass & other) const;

    bool operator > (const FitnessClass & other) const;

    bool operator <= (const FitnessClass & other) const;

    bool operator >= (const FitnessClass & other) const;

private: string name,description,instructor;
    int numOfmembers;
    Member * group;
    bool freePlaces;
protected:
    string schedule;
};


#endif //HOMEWORK_FITNESSCLASS_H
