#pragma once
#include <iostream>
#include <vector>
using namespace::std;
#include "Property.h"

class User
{
private:
	string m_userId;
	string m_userName;
	string m_password;
	string m_userType;
	string m_status;
public:
	User() : m_userId(""), m_userName(""), m_password(""), m_userType(""), m_status("") {};
	User(string userId, string userName, string password, string userType) : m_userId(userId), m_userName(userName), m_password(password), m_userType(userType), m_status("Active") {};
	string getUserId();
	string getUserName();
	string getStatus();
	void setStatus(string status);
	void setUserName(string name);
	string getPassword();
	void setPassword(string password);
	string getUserType();
	virtual void displayMenu() {};
	virtual ~User() {}
};

