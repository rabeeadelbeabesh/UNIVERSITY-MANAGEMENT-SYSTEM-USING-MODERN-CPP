#pragma once
#include<string>
class MemberData {

protected :
	int mId;
	std::string mName;
	int mAge;
	std::string mPhoneNumber;
	std::string mUserName;

public:
	MemberData();
	~MemberData();
	void setId(int id_);
	void setName(std::string name_);
	void setAge(int age_);
	void setPhoneNumber(std::string phoneNumber_);
	void setUserName(std::string userName_);

	int getId()const;
	std::string getName()const;
	int getAge()const;
	std::string getPhoneNumber()const;
	std::string getUserName();
	virtual std::string print() = 0;
};