#pragma once
#include <iostream>
#include <vector>
using namespace::std;
#include "User.h"
#include "Property.h"
#include "Request.h"

class Agent
	: public User
{
private:
	string m_agentId;
	vector<Property*> m_properties;
	vector<Request*> m_requests;
public:
	Agent() : m_agentId(""), m_properties(), m_requests() {};
	Agent(string agentId, string userId, string userName, string password, string userType) : m_agentId(agentId), User(userId, userName, password, userType) {};
	string getAgentId();
	vector<Property*> getProperties();
	vector<Request*> getRequests();
	void setRequests(vector<Request*> requests);
	void setProperty(vector<Property*> properties);
	void addProperty(Property* property);
	void deleteProperty();
	void viewRequests();
	void approveRequest();
	void rejectRequest();
	void viewUploadedProperties();
	void displayMenu() override;
};

