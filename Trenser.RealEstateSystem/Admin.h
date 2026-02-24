//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------
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
	Admin(string adminId, string userId, string userName, string password, string userType, UserStatus status) : m_adminId(adminId), User(userId, userName, password, userType, status) {};
	static const string ADMIN;
	string getAdminId();
	void displayMenu() override;
	~Admin() {}
};

