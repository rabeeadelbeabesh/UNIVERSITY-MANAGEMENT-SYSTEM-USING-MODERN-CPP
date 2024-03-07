#include "teacher_dm.h"

TeacherDM::TeacherDM()
{
}
TeacherDM::TeacherDM(int id_)
{
	this->theTeacher = this->theTeacherCrud->findTeacherById(id_);
}

TeacherDM::~TeacherDM()
{
}

std::shared_ptr<MemberData> TeacherDM::getCurrentUser()
{
	return this->theTeacher;
}

std::vector<shared_ptr<Course>> TeacherDM::getMYCourses()
{
	std::vector<std::shared_ptr<Course>> theCourses;
	for (int courseID : this->theTeacher->getAllCourses()) {
		auto temp = this->theCourseCrud->findCourseById(courseID);
		if (temp != nullptr) {
			theCourses.push_back(temp);
		}
	}
	return theCourses;
}

void TeacherDM::addCourse(int courseId_)
{
	this->theTeacher->addCourse(courseId_);

}

void TeacherDM::removeCourse(int courseId_)
{
	this->theTeacher->removeCourse(courseId_);
}

std::vector<std::shared_ptr<Course>> TeacherDM::getAvailableCourses()
{
	return  this->theCourseCrud->findAllCourses();
}

std::map<std::shared_ptr<Course>, vector<std::shared_ptr<Student>>> TeacherDM::findAllCoursesWithStuents()
{
	std::map<std::shared_ptr<Course>, vector<std::shared_ptr<Student>>> AllCoursesWithStuents;

	for (int courseID : this->theTeacher->getAllCourses()) {
		auto tempCourse = theCourseCrud->findCourseById(courseID);
		for (int studentid : tempCourse->getCourseStudents()) {

			auto tempStudent = theStudentCrud->findStudentById(studentid);
			AllCoursesWithStuents[tempCourse].push_back(tempStudent);
		}
		
	}
	return AllCoursesWithStuents;
}

std::vector<std::shared_ptr<Student>> TeacherDM::getAvailableStudent()
{
	return theStudentCrud->findAllStudents();
}

void TeacherDM::addStuentToCourse(int idCourse, int idStudent)
{
	auto tempStudent = theStudentCrud->findStudentById(idStudent);
	auto tempCourse = theCourseCrud->findCourseById(idCourse);

	tempCourse->addStudentToCourse(tempStudent->getId());
	tempStudent->addCourse(tempCourse->getId());

	theCourseCrud->updateCourse(tempCourse);
	theStudentCrud->updateStudent(tempStudent);

}

void TeacherDM::removeStudentFromCourse(int idCourse, int idStudent)
{
	auto tempStudent = theStudentCrud->findStudentById(idStudent);
	auto tempCourse = theCourseCrud->findCourseById(idCourse);

	tempCourse->removeStudentFromCourse(tempStudent->getId());
	tempStudent->removeCourse(tempCourse->getId());

	theCourseCrud->updateCourse(tempCourse);
	theStudentCrud->updateStudent(tempStudent);

}
