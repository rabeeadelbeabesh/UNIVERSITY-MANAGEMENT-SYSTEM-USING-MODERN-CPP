#include "admin_dm.h"

AdminDM::AdminDM()
{
}

AdminDM::~AdminDM()
{
}

std::shared_ptr<MemberData> AdminDM::getCurrentUser()
{
	return std::shared_ptr<MemberData>();
}

std::vector<shared_ptr<Course>> AdminDM::getMYCourses()
{
	return std::vector<shared_ptr<Course>>();
}

void AdminDM::addStudent(std::shared_ptr<Student> student_)
{
	this->theStudentCrud->addStudent(student_);
}

void AdminDM::updateStudent(std::shared_ptr<Student> student_)
{
	this->theStudentCrud->updateStudent(student_);
}

void AdminDM::removeStudent(std::string userName_)
{
	std::shared_ptr<Student> student_ = theStudentCrud->verifyStudent(userName_);
	this->theStudentCrud->removeStudent(student_);
}

std::shared_ptr<Student> AdminDM::findStudent(std::string userName_)
{
	return 	this->theStudentCrud->verifyStudent(userName_);
}

vector<std::shared_ptr<Student>> AdminDM::getAllStudents()
{
	return 	this->theStudentCrud->findAllStudents();
}

void AdminDM::addCourse(std::shared_ptr<Course> course_)
{
	this->theCourseCrud->addCourse(course_);
}

void AdminDM::updateCourse(std::shared_ptr<Course> course_)
{
	this->theCourseCrud->updateCourse(course_);
}

void AdminDM::removeCourse(int id_)
{
	std::shared_ptr<Course> course_ = theCourseCrud->findCourseById(id_);
	this->theCourseCrud->removeCourse(course_);
}

std::shared_ptr<Course> AdminDM::findCourse(int id_)
{
	return this->theCourseCrud->findCourseById(id_);
}

vector<std::shared_ptr<Course>> AdminDM::getAllCourses()
{
	return this->theCourseCrud->findAllCourses();
}

void AdminDM::addTeacher(std::shared_ptr<Teacher> teacher_)
{
	this->theTeacherCrud->addTeacher(teacher_);
}

void AdminDM::updateTeacher(std::shared_ptr<Teacher> teacher_)
{
	this->theTeacherCrud->updateTeacher(teacher_);
}

void AdminDM::removeTeacher(std::string userName_)
{
	std::shared_ptr<Teacher> teacher_ = theTeacherCrud->verifyTeacher(userName_);
	this->theTeacherCrud->removeTeacher(teacher_);
}

std::shared_ptr<Teacher> AdminDM::findTeacher(std::string userName_)
{
	return 	this->theTeacherCrud->verifyTeacher(userName_);
}

std::vector<std::shared_ptr<Teacher>> AdminDM::getAllTeacher()
{
	return 	this->theTeacherCrud->findAllTeacher();
}
