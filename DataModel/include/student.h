#pragma once
#include "member_data.h"
#include <fstream>
#include <iostream>
#include <string> 
#include <set>
#include <sstream>
using namespace std;

class Student:public MemberData{

private:
	double mGPA;
    std::set<int>mMyCourses;

public:
	Student();
	~Student();
	void setGPA(double gpa_);
	double getGPA();

	set<int> getMyCourses();
	void  setMyCourses(set<int> myCourses_);
	void addCourse(int courseId_);
	void removeCourse(int courseId_);
	void writeToFile(std::ofstream& outFile) const;
	void readFromFile(string data_);
	string print() override;

};