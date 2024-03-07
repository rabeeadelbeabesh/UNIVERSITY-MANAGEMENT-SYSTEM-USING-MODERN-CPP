#pragma once

#include  "student.h"
#include <vector>
class StudentCrud {

private:
	vector<shared_ptr<Student> >studentTable ;

public:

	StudentCrud();
   	~StudentCrud();

	void reedData();
	void writeData();
	int getStudentTableSize();
	void addStudent(shared_ptr<Student> student);

	shared_ptr<Student> findStudentById(int id_);

	void updateStudent(shared_ptr<Student> student);

	void removeStudent(shared_ptr<Student> student);
	vector<shared_ptr<Student> > findAllStudents();
	std::set<int>findAllMyCoursesforId(int id_);

	std::shared_ptr<Student>verifyStudent(string userName_);

};
