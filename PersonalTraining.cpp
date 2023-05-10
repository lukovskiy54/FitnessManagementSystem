#include <string>
#include "PersonalTraining.h"
PersonalTraining::PersonalTraining(const string &name, const string &description, const string &instructor) : FitnessClass(name, description, instructor, "not set yet", 1) {}

void PersonalTraining::setSchedule(const string &schedule) {
    this -> FitnessClass::schedule = schedule;
}

bool PersonalTraining::operator<(const PersonalTraining &other) const {
    return (this -> getDescription().length() < other.getDescription().length());
}