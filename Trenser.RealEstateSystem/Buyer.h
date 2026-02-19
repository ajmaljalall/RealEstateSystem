#pragma once
#include <iostream>
#include <vector>
using namespace::std;
#include "User.h"
#include "Property.h"
#include "Request.h"

class Buyer
	: public User
{
private:
	string m_buyerId;
public:
	Buyer() : m_buyerId("") {};
	Buyer(string buyerId, string userId, string userName, string password, string userType) : m_buyerId(buyerId), User(userId, userName, password, userType) {};
	string getBuyerId();
	void displayMenu() override;
};

