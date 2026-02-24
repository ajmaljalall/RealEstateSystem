//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------
#pragma once
#include <iostream>
#include "Status.h"
using namespace::std;

class Property
{
private:
	string m_propertyId;
	string m_category;
	double m_price;
	string m_agentId;
	string m_location;
	string m_propertyName;
	PropertyStatus m_status;
public:
	Property() : m_propertyId(""), m_propertyName(), m_category(""), m_price(0.0), m_agentId(""), m_location(""), m_status(PropertyStatus::AVAILABLE) {};
	Property(string propertyId, string propertyName, string category, double price, string agentId, string location, PropertyStatus status) : m_propertyId(propertyId), m_propertyName(propertyName), m_category(category), m_price(price), m_agentId(agentId), m_location(location), m_status(status) {};
	string getPropertyId();
	string getPropertyName();
	string getCategory();
	double getPrice();
	string getAgentId();
	string getLocation();
	PropertyStatus getStatus();
	void setCategory(string category);
	void setPrice(double price);
	void setLocation(string location);
	void setStatus(PropertyStatus status);
	void setPropertyName(string name);
};

