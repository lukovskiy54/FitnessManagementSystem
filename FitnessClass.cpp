#include "FitnessClass.h"
FitnessClass::FitnessClass(const string &name, const string &description, const string &instructor,
                           const string &schedule, const int &numOfmembers) : name(name),
                                                                              description(description),
                                                                              instructor(instructor),
                                                                              schedule(schedule),
                                                                              numOfmembers(numOfmembers) {
    freePlaces = true;
    group = new Member[numOfmembers];
}

bool FitnessClass::operator>=(const FitnessClass &other) const {
    return !( * this < other);
}

bool FitnessClass::operator<=(const FitnessClass &other) const {
    return !(other < * this);
}

bool FitnessClass::operator>(const FitnessClass &other) const {
    return other < * this;
}

bool FitnessClass::operator<(const FitnessClass &other) const {
    return (numOfmembers < other.numOfmembers);
}
ostream &operator<<(ostream &os, const FitnessClass &aClass) {
    os << "Name: " << aClass.name <<"\n"<< "Description: " << aClass.description <<"\n"<< "Instructor: " << aClass.instructor <<"\n"<<
       "Schedule: " << aClass.schedule << "\n"<<"Number of members: " << aClass.numOfmembers << "\n"<<"Free places: " << aClass.freePlaces << "\n";
    os << "Group: " << "\n";
    for (int i = 0; i < aClass.numOfmembers; ++i) {
        cout << aClass.group[i] << endl;
    }
    return os;
}
void FitnessClass::setFreePlaces(bool freePlaces) {
    FitnessClass::freePlaces = freePlaces;
}

bool FitnessClass::getFreePlaces() const {
    return freePlaces;
}

Member *FitnessClass::getGroup(int i) const {
    return & group[i];
}

void FitnessClass::setGroup(int i, Member member) {
    FitnessClass::group[i] = member;
}


int FitnessClass::getNumOfmembers() const {
    return numOfmembers;
}

const string &FitnessClass::getSchedule() const {
    return schedule;
}

const string &FitnessClass::getInstructor() const {
    return instructor;
}


const string &FitnessClass::getDescription() const {
    return description;
}

const string &FitnessClass::getName() const {
    return name;
}



