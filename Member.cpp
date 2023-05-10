#include "Member.h"

Member::Member(const string &name, const string &email, const long double &phoneNumber, const string &membershipType)
        : name(name),
          email(email),
          phoneNumber(phoneNumber),
          membershipType(membershipType) {}
Member::Member() : name("undefined"),
                   email("undefined"),
                   phoneNumber(0),
                   membershipType("undefined") {}
Member::~Member() {
}
bool Member::operator<(const Member &other) const {
    int statusThis = 0;
    int statusOther = 0;
    if (other.membershipType == "basic") {
        statusOther = 1;
    }
    if (other.membershipType == "standart") {
        statusOther = 2;
    }
    if (other.membershipType == "premium") {
        statusOther = 3;
    }
    if (this -> membershipType == "basic") {
        statusThis = 1;
    }
    if (this -> membershipType == "standart") {
        statusThis = 2;
    }
    if (this -> membershipType == "premium") {
        statusThis = 3;
    }
    return (statusThis < statusOther);
}

ostream &operator<<(ostream &os, const Member &member) {
    os << "Name: " << member.name << "; Email: " << member.email << "; PhoneNumber: " << member.phoneNumber <<
       "; MembershipType: " << member.membershipType << endl;
    return os;
}

bool Member::operator>=(const Member &other) const {
    return !(*this < other);
}

bool Member::operator<=(const Member &other) const {
    return !(other < * this);
}

bool Member::operator>(const Member &other) const {
    return (other < *this);
}

bool Member::operator!=(const Member &other) const {
    return !(other == * this);
}

bool Member::operator=(const Member &other) {
    this -> name = other.getName();
    this -> email = other.email;
    this -> phoneNumber = other.phoneNumber;
    this -> membershipType = other.membershipType;
    return true;
}

bool Member::operator==(const Member &other) const {
    return (name == other.name &&
            email == other.email &&
            phoneNumber == other.phoneNumber &&
            membershipType == other.membershipType);
}




const string &Member::getEmail() const {
    return email;
}

const  long &Member::getPhoneNumber() const {
    return phoneNumber;
}

const string &Member::getName() const {
    return name;
}

const string &Member::getMembershipType() const {
    return membershipType;
}
