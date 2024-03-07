#include "teacher_crud.h"

TeacherCrud::TeacherCrud()
{
	reedData();
}

TeacherCrud::~TeacherCrud()
{
	writeData();
}

void TeacherCrud::addTeacher(shared_ptr<Teacher> Teacher)
{

	this->teacherTable.push_back(Teacher);

}

void TeacherCrud::reedData()
{
	std::ifstream inf{ "teacherTable.txt" };
	if (!inf) {
	//	std::cout << "Data not loadoing \n";
		return;
	}

	std::string strinput{};

	while (std::getline(inf, strinput)) {
		std::shared_ptr<Teacher> tempTeacher = std::make_shared<Teacher>();
		tempTeacher->readFromFile(strinput);
		this->teacherTable.push_back(tempTeacher);
	}
}

void TeacherCrud::writeData()
{
	// Remove existing file
	//if (std::remove("teacherTable.txt") != 0) {
	//	//std::perror("Error deleting file");
	//}
	//else {
	//	std::cout << "File deleted successfully\n";
	//}

	// Open new file
	std::ofstream out{ "teacherTable.txt" };
	if (!out) {
		//std::cout << "Error creating new file\n";
		return; // Exit function if file creation fails
	}

	// Write data to the new file
	for (const auto& teacher : teacherTable) {
		teacher->writeToFile(out);
	}

	out.close();

}

int TeacherCrud::getTeacherTableSize()
{
	return (int)this->teacherTable.size();
}

shared_ptr<Teacher> TeacherCrud::findTeacherById(int id_)
{
	for (auto& Teacher : this->teacherTable) {
		if (id_ == Teacher->getId()) {
			return Teacher;
		}
	}
	return nullptr;
}
void TeacherCrud::updateTeacher(shared_ptr<Teacher> Teacher)
{
	for (auto& TeacherData : this->teacherTable) {
		if (TeacherData->getId() == Teacher->getId()) {
			TeacherData->setName(Teacher->getName());
			TeacherData->setUserName(Teacher->getUserName());
			TeacherData->setAge(Teacher->getAge());
			TeacherData->setPhoneNumber(Teacher->getPhoneNumber());
			TeacherData->setSalsry(Teacher->getSalary());
			break;
		}
	}
}
void TeacherCrud::removeTeacher(shared_ptr<Teacher> Teacher)
{
	for (auto& TeacherData : this->teacherTable) {
		if (TeacherData->getId() == Teacher->getId()) {
			TeacherData->setName(this->teacherTable.back()->getName());
			TeacherData->setUserName(this->teacherTable.back()->getUserName());
			TeacherData->setAge(this->teacherTable.back()->getAge());
			TeacherData->setPhoneNumber(this->teacherTable.back()->getPhoneNumber());
			TeacherData->setSalsry(this->teacherTable.back()->getSalary());

			this->teacherTable.pop_back();
			break;
		}
	}

}

vector<shared_ptr<Teacher>> TeacherCrud::findAllTeacher()
{
	return this->teacherTable;
}

std::set<int> TeacherCrud::findAllMyCourses(int id_)
{
	shared_ptr<Teacher> tempTeacher = findTeacherById(id_);
	if (tempTeacher != nullptr) {
		return tempTeacher->getAllCourses();
	}
	return {};
}

std::shared_ptr<Teacher> TeacherCrud::verifyTeacher(string userName_)
{
	for (auto& Teacher : this->teacherTable) {
		if (userName_ == Teacher->getUserName()) {
			return Teacher;
		}
	}
	return nullptr;
}
