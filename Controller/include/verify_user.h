#pragma once
#include<memory>
#include<string>
#include<iostream>
#include "student_crud.h"
#include "teacher_crud.h"
#include "course_crud.h"
class verifyUser {

public :
	verifyUser();
	~verifyUser();
	int getStudentId();
	int getTeacherId();
	int getCourserId();
	std::shared_ptr<Student>verifyStudenttUser(std::string userName_);
	std::shared_ptr<Teacher>verifyTeacherUser(std::string userName_);

private:
	std::shared_ptr<StudentCrud>theStudentCrud;
	std::shared_ptr<TeacherCrud>theTeacherCrud;
	std::shared_ptr<CourseCrud> theCourseCrud;
};