#include "student_dm.h"

StudentDM::StudentDM()
{
}

StudentDM::StudentDM(int id_)
{
	this->theStudent =this->theStudentCrud->findStudentById(id_);
}

StudentDM::~StudentDM()
{

}

std::shared_ptr<MemberData> StudentDM::getCurrentUser()
{
	return theStudent;
}

std::vector<shared_ptr<Course>> StudentDM::getMYCourses()
{
	std::vector<shared_ptr<Course>>theStudentCourses;
	for (int courseId : theStudent->getMyCourses()) {
		auto tempCourse = theCourseCrud->findCourseById(courseId);
		if (tempCourse != nullptr) {
			theStudentCourses.push_back(tempCourse);
		}
	}
	return theStudentCourses;
}
