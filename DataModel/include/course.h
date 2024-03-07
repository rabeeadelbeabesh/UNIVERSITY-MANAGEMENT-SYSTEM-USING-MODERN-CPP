#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <Set>
class Course {

private :
	int mId;
	std::string mName;
	int mHours;
	std::set<int>mCourseStudents;
	
public :

	Course();
	~Course();
	void setId(int id_);
	void setName(std::string name_);
	void setHourse(int hours_);
	 
	void clearAllStudentFromCourse();
	void addStudentToCourse(int studentId_);
	void removeStudentFromCourse(int studentId_);
	std::set<int>getCourseStudents();
	void setCourseStudents(std::set<int> courseStudents);

	int getId();
	std::string getName();
	int getHourse();
	std::string print();

	void writeToFile(std::ofstream& outFile) const;
	void readFromFile(std::string data_);


};