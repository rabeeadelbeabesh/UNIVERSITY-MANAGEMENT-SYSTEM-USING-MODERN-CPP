#pragma once
#include "student_crud.h"
#include "course_crud.h"
#include "teacher_crud.h"
#include "user_dm.h"
#include <memory>
#include <map>
#include<vector>
class TeacherDM :public UserDm {

public :
	TeacherDM();
	TeacherDM(int id_);
	~TeacherDM();
	std::shared_ptr<MemberData>getCurrentUser()override;
	std::vector<shared_ptr<Course>>getMYCourses()override;

	void addCourse(int courseId);
	void removeCourse(int courseId);
	std::vector<std::shared_ptr<Course>> getAvailableCourses();

	std::map<std::shared_ptr<Course>, vector<std::shared_ptr<Student>>>findAllCoursesWithStuents();

	std::vector<std::shared_ptr<Student>> getAvailableStudent();

	void addStuentToCourse(int idCourse, int idStudent);
	void removeStudentFromCourse(int idCourse, int idStudent);

private:
	std::shared_ptr<Teacher>theTeacher;
 
};
