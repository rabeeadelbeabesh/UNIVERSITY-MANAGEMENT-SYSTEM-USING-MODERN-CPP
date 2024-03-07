#pragma once
#include "student_crud.h"
#include "course_crud.h"
#include  "user_dm.h"
#include<memory>
#include<vector>
class StudentDM :public UserDm {
public :
	StudentDM();
	StudentDM(int id_);
	~StudentDM();
	std::shared_ptr<MemberData>getCurrentUser()override;
	std::vector<shared_ptr<Course>>getMYCourses()override;
private:
	std::shared_ptr<Student>theStudent;

};