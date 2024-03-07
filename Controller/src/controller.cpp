#include "controller.h"

Controller::Controller()
{
	theverifyUser = std::make_shared<verifyUser>();
}

Controller::~Controller()
{
}

std::shared_ptr<UserDm> Controller::login(int status, std::string username_)
{
	std::shared_ptr<UserDm>theUser=nullptr;
	std::shared_ptr<MemberData> temp= nullptr;
	switch(status)
	{
	case 1:
		theUser = std::make_shared<AdminDM>();
		break;
	case 2:
		temp =theverifyUser->verifyTeacherUser(username_);
		if (temp!= nullptr) {
			theUser = std::make_shared<TeacherDM>(temp->getId());
		}
		else {
			cout << "USERNAME NOT CORRECT \n";
		}
		break;
	case 3:
		temp = theverifyUser->verifyStudenttUser(username_);
		if (temp != nullptr) {
			theUser = std::make_shared<StudentDM>(temp->getId());
		}
		else {
			cout << "USERNAME NOT CORRECT \n";
		}
		break;
	default:
		break;
	}
	return theUser;
}
