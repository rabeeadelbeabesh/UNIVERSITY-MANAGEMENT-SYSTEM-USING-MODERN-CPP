#pragma once
#include "student_crud.h"
#include "course_crud.h"
#include "teacher_crud.h"

class UserDm  {
public:
	UserDm();
	~UserDm();
	virtual std::shared_ptr<MemberData>getCurrentUser()=0;
	virtual std::vector<shared_ptr<Course>>getMYCourses()=0;
protected:
	std::shared_ptr<StudentCrud>theStudentCrud;
	std::shared_ptr<TeacherCrud>theTeacherCrud;
	std::shared_ptr<CourseCrud>theCourseCrud;
};