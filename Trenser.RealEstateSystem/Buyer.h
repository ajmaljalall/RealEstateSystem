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
	vector<Request*> m_requests;
	vector<Property*> m_ownedProperties;
public:
	Buyer() : m_buyerId(""), m_requests(), m_ownedProperties() {};
	Buyer(string buyerId, string userId, string userName, string password, string userType) : m_buyerId(buyerId), m_requests(), m_ownedProperties(), User(userId, userName, password, userType) {};
	string getBuyerId();
	vector<Request*> getRequests();
	vector<Property*> getOwnedProperties();
	void setRequests(vector<Request*> requests);
	void setProperties(vector<Property*> properties);
	void searchAvailablePlots();
	void searchByCategory();
	void searchByPrice();
	void viewAllProperties();
	void requestToBuy();
	void viewMyRequests();
	void viewOwnedProperties();
	void displayMenu() override;
};

