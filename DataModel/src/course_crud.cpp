#include "course_crud.h"

CourseCrud::CourseCrud()
{
	reedData();
}

CourseCrud::~CourseCrud()
{
	writeData();
}

void CourseCrud::addCourse(std::shared_ptr<Course> course)
{

	this->courseTable.push_back(course);

}

std::shared_ptr<Course> CourseCrud::findCourseById(int id_)
{
	for (auto& course : this->courseTable) {
		if (id_ == course->getId()) {
			return course;
		}
	}
	return nullptr;
}
void CourseCrud::updateCourse(std::shared_ptr<Course> course)
{
	for (auto& courseData : this->courseTable) {
		if (courseData->getId() == course->getId()) {
			courseData->setName(course->getName());
			courseData->setHourse(course->getHourse());
			courseData->setCourseStudents(course->getCourseStudents());
			break;
		}
	}
}
void CourseCrud::removeCourse(std::shared_ptr<Course> course)
{
	for (auto& courseData : this->courseTable) {
		if (courseData->getId() == course->getId()) {
			courseData->setName(this->courseTable.back()->getName());
			courseData->setHourse(this->courseTable.back()->getHourse());
	    	this->courseTable.pop_back();
			break;
		}
	}

}

std::vector<std::shared_ptr<Course>> CourseCrud::findAllCourses()
{
	return this->courseTable;
}

std::set<int> CourseCrud::findAllStudentForCourseId(int id_)
{
	std::shared_ptr<Course> tempCourse =findCourseById(id_);
	if (tempCourse != nullptr) {
		return tempCourse->getCourseStudents();
	}
	return {};
}

int CourseCrud::courseTableSize()
{
	return (int)courseTable.size();
}

void CourseCrud::reedData()
{
	std::ifstream inf{ "courseTable.txt" };
	if (!inf) {
		//std::cout << "Data not loadoing \n";
		return;
	}

	std::string strinput{};

	while (std::getline(inf, strinput)) {
		std::shared_ptr<Course> tempcourse = std::make_shared<Course>();
		tempcourse->readFromFile(strinput);
		this->courseTable.push_back(tempcourse);
	}
}

void CourseCrud::writeData()
{
	// Remove existing file
	/*if (std::remove("courseTable.txt") != 0) {
		std::perror("Error deleting file");
	}
	else {
		std::cout << "File deleted successfully\n";
	}*/

	// Open new file
	std::ofstream out{ "courseTable.txt" };
	if (!out) {
		//std::cout << "Error creating new file\n";
		return; // Exit function if file creation fails
	}

	// Write data to the new file
	for (const auto& course : courseTable) {
		course->writeToFile(out);
	}

	out.close();
}
