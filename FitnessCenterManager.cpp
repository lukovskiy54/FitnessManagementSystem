#include "FitnessCenterManager.h"
#include <stdlib.h>

void FitnessCenterManager::printFitnessTraining() {
    cout << "\n" << "PRINTING PERSONAL TRAINING LIST" << endl;
    for (int i = 0; i < pTrainingList.size(); ++i) {
        cout << pTrainingList[i] << endl;
    }
    cout<<"FINISHED PRINTING PERSONAL TRAINING LIST"<<endl;
}

void FitnessCenterManager::printClasses() {
    cout << "\n" << "PRINTING CLASSES LIST" << endl;
    for (int i = 0; i < fClassesList.size(); ++i) {
        cout << fClassesList[i] << endl;
    }
    cout<<"FINISHED PRINTING CLASSES LIST"<<endl;
}
void FitnessCenterManager::printMembers() {
    cout << "\n" << "PRINTING MEMBER LIST" << endl;
    for (int i = 0; i < memberList.size(); ++i) {
        cout << memberList[i] << endl;
    }
    cout<<"FINISHED PRINTING MEMBER LIST"<<endl;
}

void FitnessCenterManager::addMember(const Member &member) {
    memberList.push_back(member);
}

void FitnessCenterManager::addFClass(const FitnessClass &fClass) {
    fClassesList.push_back(fClass);
}

void FitnessCenterManager::addPTraining(const PersonalTraining &ptraining) {
    pTrainingList.push_back(ptraining);
}

bool FitnessCenterManager::removeMember(const string &memberName) {
    Member def = Member();//default member
    //equating given member of each group in classes to default
    for (int i = 0; i < fClassesList.size(); ++i) {
        for (int j = 0; j < fClassesList[i].getNumOfmembers(); ++j) {
            if (fClassesList[i].getGroup(j) -> getName() == memberName) {
                fClassesList[i].setGroup(j, def);
                fClassesList[i].setFreePlaces(true);
            }
        }
    }
    //equating given member of each personal training to default
    for (int i = 0; i < pTrainingList.size(); ++i) {
        for (int j = 0; j < pTrainingList[i].getNumOfmembers(); ++j) {
            if (pTrainingList[i].getGroup(j) -> getName() == memberName) {
                pTrainingList[i].setGroup(j, def);
                pTrainingList[i].setSchedule("not set yet");
                pTrainingList[i].setFreePlaces(true);
            }
        }
    }
    //erasing given member from list of all members
    for (auto it = memberList.begin(); it != memberList.end(); ++it) {
        if (it -> getName() == memberName) {
            memberList.erase(it);
            cout<<"SUCCESSFULLY REMOVED"<<endl;
            return true;
        }
    }
    return false;
}

bool FitnessCenterManager::removeClass(const string &className) {
    for (auto it = fClassesList.begin(); it != fClassesList.end(); ++it) {
        if (it -> getName() == className) {
            fClassesList.erase(it);
            cout<<"SUCCESSFULLY REMOVED"<<endl;
            return true;
        }
    }
    return false;
}

bool FitnessCenterManager::removePTraining(const string &pTrainingName) {
    for (auto it = pTrainingList.begin(); it != pTrainingList.end(); ++it) {
        if (it -> getName() == pTrainingName) {
            pTrainingList.erase(it);
            cout<<"SUCCESSFULLY REMOVED"<<endl;
            return true;
        }
    }
    return false;
}

Member *FitnessCenterManager::searchMember(const string &memberName) {

    for (auto it = memberList.begin(); it != memberList.end(); ++it) {
        if (it -> getName() == memberName) {
            return & * it;
        }
    }
}

FitnessClass *FitnessCenterManager::searchClass(const string &className) {
    for (auto it = fClassesList.begin(); it != fClassesList.end(); ++it) {
        if (it -> getName() == className) {
            return & * it;
        }
    }
}

PersonalTraining *FitnessCenterManager::searchTraining(const string &pTrainingName) {
    for (auto it = pTrainingList.begin(); it != pTrainingList.end(); ++it) {
        if (it -> getName() == pTrainingName) {
            return & * it;
        }
    }
}

bool FitnessCenterManager::enrollMember(const string &memberName, const string &className) {
    for (int i = 0; i < fClassesList.size(); ++i) {
        cout <<"\n"<< "Enrolling " << memberName << " to " << className<<"\n" ;
        //finds class with provided name
        if (fClassesList[i].getName() == className) {
            if (fClassesList[i].getFreePlaces()) {
                for (int j = 0; j < fClassesList[i].getNumOfmembers(); ++j) {

                    //checks, if member with provided name already attending class
                    if (fClassesList[i].getGroup(j) -> getName() == memberName) {
                        cout << memberName << " is already attending " << className << endl;
                        break;
                    }
                    //if no such members are found, looks for the first free place in the training
                    if (fClassesList[i].getGroup(j) -> getName() == "undefined") {
                        fClassesList[i].setGroup(j, * searchMember(memberName));
                        cout << "SUCCESSFULLY ENROLLED " <<memberName << " to " << className<<"\n";
                        return true;
                    }

                }
                cout << "Cant enroll " << memberName << " to " << className <<
                     ". There is no more places in this class" << "\n" << endl;
                fClassesList[i].setFreePlaces(false);
            }
        }
    }
    for (int i = 0; i < pTrainingList.size(); ++i) {
        //finds training with provided name
        if (pTrainingList[i].getName() == className) {
            if (pTrainingList[i].getFreePlaces()) {
                for (int j = 0; j < pTrainingList[i].getNumOfmembers(); ++j) {
                    //checks, if member with provided name already attending training
                    if (pTrainingList[i].getGroup(j) -> getName() == memberName) {
                        cout << memberName << " is already attending " << className << endl;
                        break;
                    }
                    //if no such members are found, looks for the first free place in the training
                    if (pTrainingList[i].getGroup(j) -> getName() == "undefined") {
                        string schedule;
                        cout << "Please, enter suitable day" << endl;
                        cin >> schedule;
                        pTrainingList[i].setSchedule(schedule);
                        pTrainingList[i].setGroup(j, * searchMember(memberName));
                        cout << "SUCCESSFULLY ENROLLED " <<memberName << " to " << className<<"\n";
                        return true;
                    }

                }

                cout << "Cant enroll " << memberName << " to " << className << ". Training is already taken" <<
                     "\n" << endl;
                pTrainingList[i].setFreePlaces(false);
            }
        }
    }
    return false;
}
//User interface as part of Fitness Center constructor
FitnessCenterManager::FitnessCenterManager() {
    cout<<"Welcome to Fitness Center Managment system"<<endl;
    _sleep(1000);
    cout<<"List of commands:"<<endl;
    cout<<"/help\n"
          "/addMember\n"
          "/removeMember\n"
          "/addFitnessClass\n"
          "/removeFitnessClass\n"
          "/addPersonalTraining\n"
          "/removePersonalTraining\n"
          "/printMember\n"
          "/printFitnessClass\n"
          "/printPersonalTraining\n"
          "/enrollMember\n"
          "/printClassesList\n"
          "/printTrainingList\n"
          "/printMemberList\n"
          "/exit\n";
    bool exit = false;
    while(!exit){
        string command;
        cout<<"Please enter command"<<endl;
        cin>>command;
        if(command == "/help"){
            cout<<"List of commands:"<<endl;
            cout<<"/help\n"
                  "/addMember\n"
                  "/removeMember\n"
                  "/addFitnessClass\n"
                  "/removeFitnessClass\n"
                  "/addPersonalTraining\n"
                  "/removePersonalTraining\n"
                  "/printMember\n"
                  "/printFitnessClass\n"
                  "/printPersonalTraining\n"
                  "/enrollMember\n"
                  "/printClassesList\n"
                  "/printTrainingList\n"
                  "/printMemberList\n"
                  "/exit\n";
        }
        if(command == "/exit"){
            exit= true;
        }
        if(command == "/addMember"){
            cin.clear();
            cout<<"Enter member name:"<<endl;
            string name;
            cin>>name;
            cin.clear();
            cout<<"Enter member email:"<<endl;
            string email;
            cin>>email;
            cin.clear();
            cout<<"Enter member phone number:"<<endl;
            long phone;
            cin>>phone;
            cin.clear();
            cout<<"Enter member membership type"<<endl;
            string membersipType;
            cin>>membersipType;
            Member member(name, email, phone, membersipType);
            addMember(member);
            cout << "SUCCESSFULLY ADDED " <<name<<"\n";
        }
        if(command == "/removeMember"){
            cin.clear();
            cout<<"Enter member name:"<<endl;
            string name;
            cin>>name;
            cin.clear();
            removeMember(name);
        }
        if(command == "/addFitnessClass"){
            cin.clear();
            cout<<"Enter class name:"<<endl;
            string name;
            cin>>name;
            cin.clear();
            cout<<"Enter class description:"<<endl;
            string description;
            cin>>description;
            cin.clear();
            cout<<"Enter class instructor:"<<endl;
            string instructor;
            cin>>instructor;
            cin.clear();
            cout<<"Enter class schedule"<<endl;
            string schedule;
            cin>>schedule;
            cin.clear();
            cout<<"Enter class number of members:"<<endl;
            int number;
            cin>>number;
            cin.clear();
            FitnessClass fClass(name,description,instructor,schedule,number);
            addFClass(fClass);
            cout << "SUCCESSFULLY ADDED " <<name<<"\n";
        }
        if(command == "/removeFitnessClass"){
            cin.clear();
            cout<<"Enter class name:"<<endl;
            string cName;
            cin>>cName;
            cin.clear();
            removeClass(cName);
        }
        if(command == "/addPersonalTraining"){
            cout<<"Enter training name:"<<endl;
            string name;
            cin>>name;
            cin.clear();
            cout<<"Enter class description:"<<endl;
            string description;
            cin>>description;
            cin.clear();
            cout<<"Enter class instructor:"<<endl;
            string instructor;
            cin>>instructor;
            cin.clear();
            PersonalTraining pTraining(name,description,instructor);
            addPTraining(pTraining);
            cout << "SUCCESSFULLY ADDED " <<name<<"\n";
        }
        if(command == "/removePersonalTraining"){
            cin.clear();
            cout<<"Enter training name:"<<endl;
            string tName;
            cin>>tName;
            cin.clear();
            removePTraining(tName);
        }
        if(command == "/printMember"){
            cin.clear();
            cout<<"Enter member name:"<<endl;
            string mName;
            cin>>mName;
            cin.clear();
            cout<<searchMember(mName)<<endl;
        }
        if(command == "/printFitnessClass"){
            cin.clear();
            cout<<"Enter class name:"<<endl;
            string cName;
            cin>>cName;
            cin.clear();
            cout<<searchClass(cName)<<endl;
        }
        if(command == "/printPersonalTraining"){
            cin.clear();
            cout<<"Enter training name:"<<endl;
            string pName;
            cin>>pName;
            cin.clear();
            cout<<searchTraining(pName)<<endl;
        }
        if(command == "/enrollMember"){
            cin.clear();
            cout<<"Enter member name:"<<endl;
            string memberName;
            cin>>memberName;
            cin.clear();
            cout<<"Enter class/training name:"<<endl;
            string ctName;
            cin>>ctName;
            cin.clear();
            enrollMember(memberName,ctName);
        }
        if(command == "/printClassesList"){
            printClasses();
        }
        if(command == "/printTrainingList"){
            printFitnessTraining();
        }
        if(command == "/printMemberList"){
            printMembers();
        }
    }
}
