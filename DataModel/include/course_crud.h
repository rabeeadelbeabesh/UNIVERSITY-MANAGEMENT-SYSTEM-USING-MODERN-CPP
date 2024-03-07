#pragma once
#include "course.h"
#include <vector>
#include <memory>
class CourseCrud {
private:
	std::vector<std::shared_ptr<Course> >courseTable;

public:

	CourseCrud();
	~CourseCrud();

	void addCourse(std::shared_ptr<Course> student);

	std::shared_ptr<Course> findCourseById(int id_);

	void updateCourse(std::shared_ptr<Course> course);

	void removeCourse(std::shared_ptr<Course> course);
	std::vector<std::shared_ptr<Course> > findAllCourses();

	std::set<int>findAllStudentForCourseId(int id_);
	int courseTableSize();
	void reedData();
	void writeData();
};