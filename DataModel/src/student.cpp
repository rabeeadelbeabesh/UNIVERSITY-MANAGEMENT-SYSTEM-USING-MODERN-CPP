#include "student.h"
#include <string.h>
Student::Student() {  
    this->mGPA = 0;
    this->mMyCourses.clear();
 
}
Student::~Student() {

}

void Student::setGPA(double gpa_)
{
    this->mGPA = gpa_;
}

double Student::getGPA()
{
    return this->mGPA;
}

set<int> Student::getMyCourses()
{
    return this->mMyCourses;
}

void Student::setMyCourses(set<int> myCourses_)
{
    this->mMyCourses = myCourses_;
}

void Student::addCourse(int courseId_)
{
    if (this->mMyCourses.find(courseId_) == this->mMyCourses.end()) {
        this->mMyCourses.insert(courseId_);
    }
}

void Student::removeCourse(int courseId_)
{
    if (this->mMyCourses.find(courseId_) != this->mMyCourses.end()) {
        this->mMyCourses.erase(courseId_);
    }
}

void Student::writeToFile(std::ofstream& outFile) const
{
    outFile << this->getId() << " " << this->getName() << " " << this->mUserName<< " ";
    outFile << this->getAge() << " " << this->getPhoneNumber() << " ";
    outFile << this->mGPA << " ";
    for (int id : this->mMyCourses)
        outFile << id << " ";
    outFile << endl;
}

void Student::readFromFile(string data_)
{
    std::stringstream os{ data_ };
    os >> this->mId;
    os >> this->mName;
    os >> this->mUserName;
    os >> this->mAge;
    os >> this->mPhoneNumber;
    os >> this->mGPA;
    int id;
    while (os >> id) {
        this->addCourse(id);
    }
    return;
}

string Student::print() 
{
    string temp = "";
    temp += "[";
    temp += to_string(this->getId());
    temp += "] - Name -> ";
    temp += this->getName();
    temp += "- UserName -> ";
    temp += this->getUserName();
    temp += " - Age ->";
    temp += to_string(this->getAge());
    temp += " - PhoneNumber -> ";
    temp += this->getPhoneNumber();
    temp += " - GPA -> ";
    temp += to_string(this->getGPA());
    temp += " - mMyCourses -> { ";
    for (int course_id : mMyCourses) {
        temp += to_string(course_id) +" ,";
    }
    temp += "} ";
   
    return temp;
}
