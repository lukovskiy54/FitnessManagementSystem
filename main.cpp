#include <iostream>
#include "Member.h"
#include "Member.cpp"
#include "FitnessClass.h"
#include "FitnessClass.cpp"
#include "PersonalTraining.h"
#include "PersonalTraining.cpp"
#include "FitnessCenterManager.h"
#include "FitnessCenterManager.cpp"
using namespace std;

int main() {
    FitnessCenterManager fitnessCenter;
    //Operator overloading example
   /* Member Andrew("Andrew", "krolik@net", 5485245, "premium");
    Member Roman("Roman", "krosh@net", 9589383, "premium");
    Member Vadim("Vadim", "tankist@com", 155697, "standart");
    fitnessCenter.addMember(Andrew);
    fitnessCenter.addMember(Roman);
    fitnessCenter.addMember(Vadim);

    PersonalTraining SelfDefence("Self defence", "learning how to defend yourself", "Chun Hui Hai");
    PersonalTraining SelfDefence_another("Self defence", "learning how to defend yourself", "Chun Hui Hai");
    FitnessClass basketball("basketball", "basketball", "Oleg", "thursday and saturday", 2);
    fitnessCenter.addPTraining(SelfDefence);
    fitnessCenter.addPTraining(SelfDefence_another);
    fitnessCenter.addFClass(basketball);


    cout << (Andrew >= Roman) << endl;
    cout << (Andrew <= Roman) << endl;
    cout << (Vadim < Roman) << endl;
    cout << (Vadim > Roman) << endl;
    cout << (Andrew == Roman) << endl;
    cout << (Andrew != Roman) << endl;
    cout << (basketball < SelfDefence) << endl;
    cout << (SelfDefence_another >= SelfDefence) << endl;*/
}