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
	vector<Property*> m_properties;
public:
	Admin() : m_adminId(""), m_properties() {};
	Admin(string adminId, string userId, string userName, string password, string userType) : m_adminId(adminId), User(userId, userName, password, userType) {};
	string getAdminId();
	vector<Property*> getProperties();
	void addBuyer();
	void removeBuyer();
	void addAgent();
	void removeAgent();
	void addProperty(Property* property);
	void displayAllProperty();
	void displayMyProperty();
	void displayMenu() override;
};

