#pragma once
#include <iostream>
using namespace::std;

class Property
{
private:
	string m_propertyId;
	string m_category;
	double m_price;
	string m_agentId;
	string m_location;
	string m_status;
public:
	Property() : m_propertyId(""), m_category(""), m_price(0.0), m_agentId(""), m_location(""), m_status("") {};
	Property(string propertyId, string category, double price, string agentId, string location, string status) : m_propertyId(propertyId), m_category(category), m_price(price), m_agentId(agentId), m_location(location), m_status(status) {};
	string getPropertyId();
	string getCategory();
	double getPrice();
	string getAgentId();
	string getLocation();
	string getStatus();
	void setCategory(string category);
	void setPrice(double price);
	void setLocation(string location);
	void setStatus(string status);
	void displayDetails();
};

