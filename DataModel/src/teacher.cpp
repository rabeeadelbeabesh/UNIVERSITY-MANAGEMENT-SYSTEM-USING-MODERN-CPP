#include "teacher.h"

Teacher::Teacher()
{
    this->mSalary = 0.0;
    this->mTeacherCourses.clear();
}

Teacher::~Teacher() {

}
Teacher::Teacher(shared_ptr<Teacher> otherTeacher)
{
    this->setId(otherTeacher->mId);
    this->setName(otherTeacher->getName());
    this->setUserName(otherTeacher->getUserName());
    this->setAge(otherTeacher->getAge());
    this->setPhoneNumber(otherTeacher->getPhoneNumber());
    this->setAllCourses(otherTeacher->getAllCourses());
}
void Teacher::operator=(shared_ptr<Teacher> otherTeacher)
{
    this->setId(otherTeacher->mId);
    this->setName(otherTeacher->getName());
    this->setUserName(otherTeacher->getUserName());
    this->setAge(otherTeacher->getAge());
    this->setPhoneNumber(otherTeacher->getPhoneNumber());
    this->setAllCourses(otherTeacher->getAllCourses());
}
void Teacher::setAllCourses(std::set<int> Courses)
{
    this->mTeacherCourses = Courses;
}
void Teacher::setSalsry(double gpa_)
{
    this->mSalary = gpa_;
}

double Teacher::getSalary()const
{
    return this->mSalary;
}
void Teacher::writeToFile(std::ofstream& outFile) const {

    outFile << this->getId() << " " << this->getName() << " " << this->mUserName << " ";
    outFile << this->getAge() << " " << this->getPhoneNumber() << " ";
    outFile << this->mSalary << " ";
    for(int id:this->mTeacherCourses)
        outFile << id<< " ";
    outFile << endl;
}

void  Teacher::readFromFile(string data_)
{
    std::stringstream os{ data_ };
    os >> this->mId;
    os >> this->mName;
    os >> this->mUserName;
    os >> this->mAge;
    os >> this->mPhoneNumber;
    os >> this->mSalary;
    int id;
    while (os >> id) {
        this->addCourse(id);
    }
  
    return;
}

string Teacher::print()
{
    string temp = "";
    temp += "[";
    temp += to_string(this->getId());
    temp += "] Name -> ";
    temp += this->getName();
    temp += "- UserName -> ";
    temp += this->getUserName();
    temp += " - Age -> ";
    temp += to_string(this->getAge());
    temp += " - phoneNumber -> ";
    temp += this->getPhoneNumber();
    temp += " - mSalary -> ";
    temp += to_string(this->mSalary);
    temp += " - mTeacherCourses ->{ ";
    for (int idCourses : this->mTeacherCourses) {
        temp += to_string(idCourses);
        temp += " - ";
    }
    temp += " }";
    return temp;
}

void Teacher::clearAllCourses()
{
    this->mTeacherCourses.clear();
}

void Teacher::addCourse(int courseId_)
{

    if (this->mTeacherCourses.find(courseId_) == this->mTeacherCourses.end()) {
        this->mTeacherCourses.insert(courseId_);
    }
}

void Teacher::removeCourse(int courseId_)
{

    if (this->mTeacherCourses.find(courseId_) != this->mTeacherCourses.end()) {
        this->mTeacherCourses.erase(courseId_);
    }
}

std::set<int> Teacher::getAllCourses()
{
    return this->mTeacherCourses;
}