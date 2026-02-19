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
public:
	Agent() : m_agentId("") {};
	Agent(string agentId, string userId, string userName, string password, string userType) : m_agentId(agentId), User(userId, userName, password, userType) {};
	string getAgentId();
	void displayMenu() override;
};

