#include "student_crud.h"

StudentCrud::StudentCrud()
{
	reedData();
}

StudentCrud::~StudentCrud()
{
	writeData();
}

void StudentCrud::reedData()
{
	std::ifstream inf{ "studentTable.txt" };
	if (!inf) {
	//	std::cout << "Data not loadoing \n";
		return;
	}

	std::string strinput{};

	while (std::getline(inf, strinput)) {
		std::shared_ptr<Student> tempTeacher = std::make_shared<Student>();
		tempTeacher->readFromFile(strinput);
		this->studentTable.push_back(tempTeacher);
	}
}

void StudentCrud::writeData()
{
	// Remove existing file 
	//if (std::remove("studentTable.txt") != 0) {
	//	std::perror("Error deleting file");
	//}
	//else {
	//	std::cout << "File deleted successfully\n";
	//}

	// Open new file
	std::ofstream out{ "studentTable.txt" };
	if (!out) {
		//std::cout << "Error creating new file\n";
		return; // Exit function if file creation fails
	}

	// Write data to the new file
	for (const auto& student : studentTable) {
		student->writeToFile(out);
	}

	out.close();
}

int StudentCrud::getStudentTableSize()
{
	return (int)this->studentTable.size();
}

void StudentCrud::addStudent(shared_ptr<Student> student)
{
	
   this->studentTable.push_back(student);
       
}

shared_ptr<Student> StudentCrud::findStudentById(int id_)
{
	for (auto &student : this->studentTable) {
		if (id_ == student->getId()) {
			return student;
		}
	}
	return nullptr;
}
void StudentCrud::updateStudent(shared_ptr<Student> student)
{
	for (auto &studentData : this->studentTable) {
		if (studentData->getId() == student->getId()) {
			studentData->setName(student->getName());
			studentData->setUserName(student->getUserName());
			studentData->setAge(student->getAge());
			studentData->setPhoneNumber(student->getPhoneNumber());
			studentData->setGPA(student->getGPA());
			studentData->setMyCourses(student->getMyCourses());
			break;
		}
	}
}
void StudentCrud::removeStudent(shared_ptr<Student> student)
{
	for (auto& studentData : this->studentTable) {
		if (studentData->getId() == student->getId()) {
			studentData->setName(this->studentTable.back()->getName());
			studentData->setUserName(this->studentTable.back()->getUserName());
			studentData->setAge(this->studentTable.back()->getAge());
			studentData->setPhoneNumber(this->studentTable.back()->getPhoneNumber());
			studentData->setGPA(this->studentTable.back()->getGPA());
			studentData->setMyCourses(this->studentTable.back()->getMyCourses());
			this->studentTable.pop_back();
			break;
		}
	}

}

vector<shared_ptr<Student>> StudentCrud::findAllStudents()
{
	return this->studentTable;
}

std::set<int> StudentCrud::findAllMyCoursesforId(int id_)
{
	shared_ptr<Student> tempStudent = findStudentById(id_);
	if (tempStudent != nullptr) {
		return tempStudent->getMyCourses();
	}
	return {};
}

 std::shared_ptr<Student> StudentCrud::verifyStudent(string userName_)
{
	for (auto& student : this->studentTable) {
		if (userName_ == student->getUserName()) {
			return student;
		}
	}
	return nullptr;
}

