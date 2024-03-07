#include "verify_user.h"

verifyUser::verifyUser()
{
    this->theStudentCrud = std::make_shared<StudentCrud>();
    this->theTeacherCrud = std::make_shared<TeacherCrud>();
    this->theCourseCrud = std::make_shared<CourseCrud>();
}

verifyUser::~verifyUser()
{

}

int verifyUser::getStudentId()
{
    return theStudentCrud->getStudentTableSize()+1;
}

int verifyUser::getTeacherId()
{
    return theTeacherCrud->getTeacherTableSize()+1;
}

int verifyUser::getCourserId()
{
    return theCourseCrud->courseTableSize()+1;
}

std::shared_ptr<Student> verifyUser::verifyStudenttUser(std::string userName_)
{
  return theStudentCrud->verifyStudent(userName_);
}

std::shared_ptr<Teacher> verifyUser::verifyTeacherUser(std::string userName_)
{
    return theTeacherCrud->verifyTeacher(userName_);
}
