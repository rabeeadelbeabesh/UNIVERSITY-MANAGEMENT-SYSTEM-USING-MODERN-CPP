#pragma once
#include <iostream>
#include "admin_dm.h";
#include "student_dm.h";
#include "teacher_dm.h";
#include "verify_user.h"
#include<memory>
#include<string>
class Controller {
public :
	Controller();
	~Controller();
	std::shared_ptr<UserDm>login(int status, std::string username_);

private :
	std::shared_ptr<verifyUser>theverifyUser;
};