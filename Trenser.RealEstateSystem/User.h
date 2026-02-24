//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------
#pragma once
#include <iostream>
#include <vector>
using namespace::std;
#include "Property.h"
#include "Status.h"

class User
{
private:
	string m_userId;
	string m_userName;
	string m_password;
	string m_userType;
	UserStatus m_status;
public:
	User() : m_userId(""), m_userName(""), m_password(""), m_userType(""), m_status(UserStatus::ACTIVE) {};
	User(string userId, string userName, string password, string userType, UserStatus status) : m_userId(userId), m_userName(userName), m_password(password), m_userType(userType), m_status(status) {};
	string getUserId();
	string getUserName();
	UserStatus getStatus();
	void setStatus(UserStatus status);
	void setUserName(string name);
	string getPassword();
	void setPassword(string password);
	string getUserType();
	virtual void displayMenu() {};
	virtual ~User() {}
};

