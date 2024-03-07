#pragma once
#include <vector>
#include <memory>
#include<iostream>
#include "student_crud.h"
#include "course_crud.h"
#include "teacher_crud.h"
#include "user_dm.h"
class AdminDM :public UserDm {

public :
	AdminDM();
	~AdminDM();
	 std::shared_ptr<MemberData>getCurrentUser() override;
	 std::vector<shared_ptr<Course>>getMYCourses() override;

	void addStudent(std::shared_ptr<Student>student_);
	void updateStudent(std::shared_ptr<Student>student_);
	void removeStudent(std::string userName_);
	std::shared_ptr<Student> findStudent(std::string userName_);
	std::vector<std::shared_ptr<Student>>getAllStudents();


	void addCourse(std::shared_ptr<Course>course_);
	void updateCourse(std::shared_ptr<Course>course_);
	void removeCourse(int id_);
	std::shared_ptr<Course> findCourse(int id_);
	vector<std::shared_ptr<Course>>getAllCourses();


	void addTeacher(std::shared_ptr<Teacher>teacher_);
	void updateTeacher(std::shared_ptr<Teacher>teacher_);
	void removeTeacher(std::string userName_);
	std::shared_ptr<Teacher> findTeacher(std::string userName_);
	std::vector<std::shared_ptr<Teacher>>getAllTeacher();


};