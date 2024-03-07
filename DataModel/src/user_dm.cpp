#include "user_dm.h"

UserDm::UserDm()
{
	this->theStudentCrud = std::make_shared<StudentCrud>();
	this->theTeacherCrud = std::make_shared<TeacherCrud>();
	this->theCourseCrud = std::make_shared<CourseCrud>();
}

UserDm::~UserDm()
{
}
