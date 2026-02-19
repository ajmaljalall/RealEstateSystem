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
public:
	User() : m_userId(""), m_userName(""), m_password(""), m_userType("") {};
	User(string userId, string userName, string password, string userType) : m_userId(userId), m_userName(userName), m_password(password), m_userType(userType) {};
	string getUserId();
	/*string setUserId(string id);*/
	string getUserName();
	void setUserName(string name);
	string getPassword();
	void setPassword(string password);
	string getUserType();
	/*virtual void addProperty(Property* property) {};
	virtual vector<Property*> getProperties() {
		return vector<Property*>();
	};*/
	virtual void displayMenu() {};
};

