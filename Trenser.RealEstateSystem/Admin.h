#pragma once
#include <iostream>
#include <vector>
using namespace::std;
#include "User.h"
#include "Property.h"

class Admin
	: public User
{
private:
	string m_adminId;
public:
	Admin() : m_adminId("") {};
	Admin(string adminId, string userId, string userName, string password, string userType) : m_adminId(adminId), User(userId, userName, password, userType) {};
	string getAdminId();
	void displayMenu() override;
};

