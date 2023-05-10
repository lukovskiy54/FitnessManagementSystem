#ifndef MEMBER_HPP
#define MEMBER_HPP

#include <string>
#include <iostream>
using namespace std;

class Member {
public: Member(const string & name,const string & email,const double long & phoneNumber,const string & membershipType);
    Member();
    ~Member();
    const string & getName() const;
    const string & getEmail() const;
    const  long & getPhoneNumber() const;
    const string & getMembershipType() const;
    friend ostream & operator << (ostream & os,const Member & member);
    bool operator = (const Member & other);
    bool operator == (const Member & other) const;
    bool operator != (const Member & other) const;
    bool operator < (const Member & other) const;
    bool operator > (const Member & other) const;
    bool operator <= (const Member & other) const;
    bool operator >= (const Member & other) const;
private:
    string name,email,membershipType;
    long phoneNumber;
};

#endif // MEMBER_HPP
