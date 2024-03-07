#include "course.h"

Course::Course()
{
	this->mId=0;
	this->mName="";
	this->mHours=0;
	this->mCourseStudents.clear();
}

Course::~Course()
{
}

void Course::setId(int id_)
{
	this->mId = id_;
}

void Course::setName(std::string name_)
{
	this->mName = name_;
}

void Course::setHourse(int hours_)
{
	this->mHours = hours_;

}

void Course::clearAllStudentFromCourse()
{
	this->mCourseStudents.clear();
}

void Course::addStudentToCourse(int studentId_)
{

	if (this->mCourseStudents.find(studentId_) == this->mCourseStudents.end()) {
		this->mCourseStudents.insert(studentId_);
	}
}

void Course::removeStudentFromCourse(int studentId_)
{

	if (this->mCourseStudents.find(studentId_) != this->mCourseStudents.end()) {
		this->mCourseStudents.erase(studentId_);
	}
}

std::set<int> Course::getCourseStudents()
{
	return this->mCourseStudents;
}

void Course::setCourseStudents(std::set<int> courseStudents)
{
	this->mCourseStudents = courseStudents;
}

int Course::getId()
{
	return this->mId;
}

std::string Course::getName()
{
	return this->mName;
}

int Course::getHourse()
{
	return this->mHours;
}

std::string Course::print()
{
    std::string temp = "";
    temp += "[";
    temp += std::to_string(this->mId);
    temp += "]";
	temp += "Name -> ";
    temp += this->mName;
    temp += " - ";
	temp += " numHourse -> ";
    temp += std::to_string(this->mHours);
    return temp;
}

void Course::writeToFile(std::ofstream& outFile) const
{
	outFile << this->mId << " " << this->mName << " ";
	outFile << this->mHours << " ";
	
	for (int id : this->mCourseStudents)
		outFile << id << " ";
	outFile <<"\n";
}

void Course::readFromFile(std::string data_)
{
	std::stringstream os{ data_ };
	os >> this->mId;
	os >> this->mName;
	os >> this->mHours;
	int id;
	while (os >> id) {
		this->addStudentToCourse(id);
	}

	return;
}
