#include <iostream>
#include<memory>
#include "controller.h"
using namespace std;
struct  Data
{
	int mId;
	std::string mName;
	int mAge;
	std::string mPhoneNumber;
	std::string mUserName;
	double mGPA;
	double  mSalary;
	int mHours;

};
int main() {
	int roleType = 0, id1 = 0, id2 = 0;
	Data temp;
	string tempstring = "";
	std::shared_ptr<TeacherDM> theTeacherDM;
	std::shared_ptr<AdminDM> theAdminDM;
	std::shared_ptr<Student>tempStudent;
	std::shared_ptr<Course>tempCourse;
	std::shared_ptr<Teacher>tempTeacher;
	shared_ptr<verifyUser>theverifyUser = make_shared<verifyUser>();
	shared_ptr<Controller>theController = make_shared<Controller>();
	bool status = true;
	while (status)
	{
		
		shared_ptr<UserDm>theUserDm;
		cout << " UNIVERSITY MANAGEMENT SYSTEM \n";
		cout << " PLEASE SELECT YOUR ROLE TYPE TO LOG IN\n";
		cout << "1 - ADMIN \n";
	    cout << "2 - TEACHER\n";
	    cout << "3 - STUDENT\n";
		cout << "4 - EXIT\n";
		std::cin >> roleType;
		switch (roleType)
		{
		case 3:
			cout << "PLEASE ENTER USERNAME \n";
			std::cin >> tempstring;
			theUserDm = theController->login(3, tempstring);
			while (theUserDm) {
				
				cout << "1 - MY PROFILE \n";
				cout << "2 - MY COURSES\n";
				cout << "3 - EXIT\n";
				std::cin >> roleType;
				switch (roleType)
				{
				case 1:
					cout << theUserDm->getCurrentUser()->print() << "\n";
					status = true;
					break;
				case 2:
					for (shared_ptr<Course> course : theUserDm->getMYCourses()) {
						cout << course->print() << "\n";
					}
					break;
				case 3:
					return 0;
					break;
				default:
					cout << " PLEASE CHOOSE THE CORRECT CHOICE\n\n";
					break;
				}
			}
			break;
		case 2:
			cout << "PLEASE ENTER USERNAME \n";
			std::cin >> tempstring;
			theUserDm = theController->login(2, tempstring);
			 theTeacherDM = std::dynamic_pointer_cast<TeacherDM>(theUserDm);
			while (theTeacherDM) {
				cout << "1 - MY PROFILE \n";
				cout << "2 - MY COURSES\n";
				cout << "3 - ADD COURSE\n";
				cout << "4 - REMOVE COURSE\n";
				cout << "5 - AVAILABLE COURSES\n";
				cout << "6 - ALL COURSES WITH STUDENTS\n";
				cout << "7 - AVAILABLE STUDENT\n";
				cout << "8 - ADD STUDENT TO COURSE\n";
				cout << "9 - REMOVE STUDENT FROM COURSE\n";
				cout << "10 - EXIT\n";
				std::cin >> roleType;
				switch (roleType)
				{
				case 1:
					cout << theTeacherDM->getCurrentUser()->print() << "\n";
					status = true;
					break;
				case 2:
					for (shared_ptr<Course> course : theTeacherDM->getMYCourses()) {
						cout << course->print() << "\n";
					}
					break;
				case 3:
					cout << " PLEASE ENTER COURSE ID TO ADDING \n";
					std::cin >> id1;
					theTeacherDM->addCourse(id1);
					break;
				case 4:
					cout << " PLEASE ENTER COURSE ID TO REMOVING \n";
					std::cin >> id1;
					 theTeacherDM->removeCourse(id1);
					break;
				case 5:
					cout << "THE AVAILABLE COURSES\n";
					for (shared_ptr<Course> tempCourse : theTeacherDM->getAvailableCourses()) {
						cout << tempCourse->print() << "\n";
					 }
					break;
				case 6:
					cout << "ALL COURSES WITH STUDENTS\n";
					for (auto temp : theTeacherDM->findAllCoursesWithStuents()) {
						cout << " THE COURSE -> ";
						cout << temp.first->print() << "\n";
						for (shared_ptr<Student>tempStudent : temp.second) {
							cout << "   -->> " << tempStudent->print() << "\n";
						}
					}
					break;
				case 7:
					cout << "ALL AVAILABLE STUDENT\n";
						for (shared_ptr<Student>tempStudent : theTeacherDM->getAvailableStudent()) {
							cout << "   -->> " << tempStudent->print() << "\n";
						}
					break;
				case 8:
					cout << "PLEASE ENTER THE ID OF THE STUDENT AND THE ID OF THE COURSE WANT TO ADD THE STUDENT TO IT\n";
					cout << "STUDENT  ID -> \n"; std::cin >> id1;
					cout << "COURSE ID -> \n"; std::cin >> id2;
					theTeacherDM->addStuentToCourse(id2, id1);
					break;
				case 9:
					cout << "PLEASE ENTER THE ID OF THE STUDENT AND THE ID OF THE COURSE WANT TO REMOVE THE STUDENT FROM IT\n";
					cout << "STUDENT  ID -> \n"; std::cin >> id1;
					cout << "COURSE ID -> \n"; std::cin >> id2;
					theTeacherDM->removeStudentFromCourse(id2, id1);
					break;
				case 10:
					
					return 0;
					break;
				default:
					cout << " PLEASE CHOOSE THE CORRECT CHOICE\n\n";
					break;
				}
			}
			break;
		case 1:
			cout << "PLEASE ENTER USERNAME \n";
			std::cin >> tempstring;
			theUserDm = theController->login(1, tempstring);
			theAdminDM = std::dynamic_pointer_cast<AdminDM>(theUserDm);
			while (theAdminDM) {
				cout << "1 - ADD STUDENT \n";
				cout << "2 - UPDATE STUDENT\n";
				cout << "3 - REMOVESTUDENT\n";
				cout << "4 - FIND STUDENT\n";
				cout << "5 - GET ALL STUDENTS\n";
				cout << "6 - ADD COURSE\n";
				cout << "7 - UPDATE COURSE\n";
				cout << "8 - REMOVE COURSE\n";
				cout << "9 - FIND COURSE\n";
				cout << "10 - GET ALL COURSES\n";
				cout << "11 - ADD TEACHER\n";
				cout << "12 - UPDATE TEACHER\n";
				cout << "13 - REMOVE TEACHER\n";
				cout << "14 - FIND TEACHER\n";
				cout << "15 - GET ALL TEACHER\n";
				cout << "16 - EXIT\n";
				std::cin >> roleType;
				switch (roleType)
				{

				case 1:
					cout << "PLEASE ENTER STUDENT DATA\n";
					cout << "STUDENT NAME : "; cin >> temp.mName;
					cout << "STUDENT USER NAME : "; cin >> temp.mUserName;
					cout << "STUDENT AGE : "; cin >> temp.mAge; 
					cout << "STUDENT PHONE NUMBER : "; cin >> temp.mPhoneNumber;
					cout << "STUDENT GPA : "; cin >> temp.mGPA; 
					tempStudent = std::make_shared<Student>();
					tempStudent->setId(theverifyUser->getStudentId());
					tempStudent->setName(temp.mName);
					tempStudent->setUserName(temp.mUserName);
					tempStudent->setAge(temp.mAge);
					tempStudent->setPhoneNumber(temp.mPhoneNumber);
					tempStudent->setGPA(temp.mGPA);
					theAdminDM->addStudent(tempStudent);
					break;
				case 2:
					cout << "PLEASE ENTER STUDENT DATA\n";
					cout << "STUDENT ID : "; cin >> temp.mId;
					cout << "STUDENT NAME : "; cin >> temp.mName;
					cout << "STUDENT USER NAME : "; cin >> temp.mUserName;
					cout << "STUDENT AGE : "; cin >> temp.mAge;
					cout << "STUDENT PHONE NUMBER : "; cin >> temp.mPhoneNumber;
					cout << "STUDENT GPA : "; cin >> temp.mGPA;
					tempStudent = std::make_shared<Student>();
					tempStudent->setId(temp.mId);
					tempStudent->setName(temp.mName);
					tempStudent->setUserName(temp.mUserName);
					tempStudent->setAge(temp.mAge);
					tempStudent->setPhoneNumber(temp.mPhoneNumber);
					tempStudent->setGPA(temp.mGPA);
					theAdminDM->updateStudent(tempStudent);
					break;
				case 3:
					cout << "PLEASE ENTER THE USER NAME OF THE STUDENT WHO YOU WANT TO REMOVE\n";
					cout << "STUDENT USER NAME : "; cin >> temp.mUserName;
					theAdminDM->removeStudent(temp.mUserName);
					break;
				case 4:
					cout << "PLEASE ENTER THE USER NAME OF THE STUDENT WHO YOU WANT TO FIND\n";
					cout << "STUDENT USER NAME : "; cin >> temp.mUserName;
					cout<<theAdminDM->findStudent(temp.mUserName)->print()<<"\n";
					break;
				case 5:
					cout << " ALL STUDENTS\n";
					for (shared_ptr<Student> tempStudent: theAdminDM->getAllStudents()) {
						cout << tempStudent->print()<<"\n";
					}
					break;
				case 6:
					cout << "PLEASE ENTER COURSE DATA\n";
					cout << "COURSE NAME : "; cin >> temp.mName;
					cout << "COURSE HOURS : "; cin >> temp.mHours;
					tempCourse = std::make_shared<Course>();
					tempCourse->setId(theverifyUser->getCourserId());
					tempCourse->setName(temp.mName);
					tempCourse->setHourse(temp.mHours);
					theAdminDM->addCourse(tempCourse);
					break;
				case 7:
					cout << "PLEASE ENTER COURSE DATA\n";
					cout << "COURSE ID : "; cin >> temp.mId;
					cout << "COURSE NAME : "; cin >> temp.mName;
					cout << "COURSE HOURS : "; cin >> temp.mHours;
					tempCourse = std::make_shared<Course>();
					tempCourse->setId(theverifyUser->getCourserId());
					tempCourse->setName(temp.mName);
					tempCourse->setHourse(temp.mHours);
					theAdminDM->updateCourse(tempCourse);
					break;
				case 8:
					cout << "PLEASE ENTER THE ID OF THE COURSE WHO YOU WANT TO REMOVE\n";
					cout << "COURSE ID : "; cin >> temp.mId;
					theAdminDM->removeCourse(temp.mId);
					break;
				case 9:
					cout << "PLEASE ENTER THE ID  OF THE COURSE WHO YOU WANT TO FIND\n";
					cout << "COURSE ID : "; cin >> temp.mId;
					cout << theAdminDM->findCourse(temp.mId)->print() << "\n";
					break;
				case 10:
					cout << " ALL COURSES\n";
					for (shared_ptr<Course> tempCourse : theAdminDM->getAllCourses()) {
						cout << tempCourse->print()<<"\n";
					}
					break;

				case 11:
					cout << "PLEASE ENTER TEACHER DATA\n";
					cout << "TEACHER NAME : "; cin >> temp.mName;
					cout << "TEACHER USER NAME : "; cin >> temp.mUserName;
					cout << "TEACHER AGE : "; cin >> temp.mAge;
					cout << "TEACHER PHONE NUMBER : "; cin >> temp.mPhoneNumber;
					cout << "TEACHER SALARY : "; cin >> temp.mSalary;
					tempTeacher = std::make_shared<Teacher>();
					tempTeacher->setId(theverifyUser->getStudentId());
					tempTeacher->setName(temp.mName);
					tempTeacher->setUserName(temp.mUserName);
					tempTeacher->setAge(temp.mAge);
					tempTeacher->setPhoneNumber(temp.mPhoneNumber);
					tempTeacher->setSalsry(temp.mSalary);
					theAdminDM->addTeacher(tempTeacher);
					break;
				case 12:
					cout << "PLEASE ENTER TEACHER DATA\n";
					cout << "TEACHER ID : "; cin >> temp.mId;
					cout << "TEACHER NAME : "; cin >> temp.mName;
					cout << "TEACHER USER NAME : "; cin >> temp.mUserName;
					cout << "TEACHER AGE : "; cin >> temp.mAge;
					cout << "TEACHER PHONE NUMBER : "; cin >> temp.mPhoneNumber;
					cout << "TEACHER SALARY : "; cin >> temp.mSalary;
					tempTeacher = std::make_shared<Teacher>();
					tempTeacher->setId(temp.mId);
					tempTeacher->setName(temp.mName);
					tempTeacher->setUserName(temp.mUserName);
					tempTeacher->setAge(temp.mAge);
					tempTeacher->setPhoneNumber(temp.mPhoneNumber);
					tempTeacher->setSalsry(temp.mSalary);
					theAdminDM->updateTeacher(tempTeacher);
					break;
				case 13:
					cout << "PLEASE ENTER THE USER NAME OF THE TEACHER WHO YOU WANT TO REMOVE\n";
					cout << "TEACHER USER NAME : "; cin >> temp.mUserName;
					theAdminDM->removeTeacher(temp.mUserName);
					break;
				case 14:
					cout << "PLEASE ENTER THE USER NAME OF THE TEACHER WHO YOU WANT TO FIND\n";
					cout << "TEACHER USER NAME : "; cin >> temp.mUserName;
					cout << theAdminDM->findTeacher(temp.mUserName)->print() << "\n";
					break;
				case 15:
					cout << " ALL TEACHERS\n";
					for (shared_ptr<Teacher> tempTeacher : theAdminDM->getAllTeacher()) {
						cout << tempTeacher->print() << "\n";
					}
					break;
				case 16:
					return 0;
					break;
				default:
					break;
				}

			}
			break;
		case 4:
			status = false;
			break;
		default:
			cout << " PLEASE CHOOSE THE CORRECT CHOICE\n\n";
			break;
		}
	}
	
	return 0;
}
