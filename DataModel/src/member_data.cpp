#include "member_data.h"


MemberData::MemberData() {


    this->mId = 0;
    this->mName = "";
    this->mAge = 0;
    this->mPhoneNumber = "";
    this->mUserName = "";

}
MemberData::~MemberData() {

}

void MemberData::setId(int id_) {
    this->mId = id_;
}

void MemberData::setName(std::string name_)
{
    this->mName = name_;
}

void MemberData::setAge(int age_)
{
    this->mAge = age_;
}

void MemberData::setPhoneNumber(std::string phoneNumber_)
{
    this->mPhoneNumber = phoneNumber_;
}

void MemberData::setUserName(std::string userName_)
{
    this->mUserName = userName_;
}


int MemberData::getId()const{
    return this->mId;
}

std::string MemberData::getName()const
{
    return this->mName;
}

int MemberData::getAge()const
{
    return this->mAge;
}

std::string MemberData::getPhoneNumber()const
{
    return this->mPhoneNumber;
}

std::string MemberData::getUserName()
{
    return this->mUserName;
}
