#pragma once
#pragma once
#include <sstream>
#include <fstream>
#include "member_data.h"
#include <iostream>
#include <string> 
#include<Set>
using namespace std;

class Teacher :public MemberData{

private:
	double  mSalary;
	std::set<int>mTeacherCourses;
public:
	Teacher();
	~Teacher();
	Teacher(shared_ptr<Teacher> otherTeacher);
	void operator = (shared_ptr<Teacher> otherTeacher);
	void clearAllCourses();
	void addCourse(int studentId_);
	void removeCourse(int studentId_);
	std::set<int>getAllCourses();


	void setAllCourses(std::set<int> Courses);
	void setSalsry(double salary_);
	double getSalary()const;
	void writeToFile(std::ofstream& outFile) const;
	void readFromFile(string data_) ;
	string print()override;



};