#pragma once
#include <vector>
#include "teacher.h"
#include <fstream>
#include <string>
#include <sstream>
class TeacherCrud {

private:
	vector<shared_ptr<Teacher> >teacherTable;

public:

	TeacherCrud();
	~TeacherCrud();

	void addTeacher(shared_ptr<Teacher> teacher);
	void reedData();
	void writeData();
	int getTeacherTableSize();
	shared_ptr<Teacher> findTeacherById(int id_);

	void updateTeacher(shared_ptr<Teacher> teacher);

	void removeTeacher(shared_ptr<Teacher> teacher);

	vector<shared_ptr<Teacher> > findAllTeacher();

	std::set<int>findAllMyCourses(int id_);
	std::shared_ptr<Teacher>verifyTeacher(string userName_);
};