//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------
#pragma once
#include <iostream>
#include <vector>
using namespace::std;
#include "User.h"
#include "Property.h"
#include "Request.h"
#include "Payment.h"
#include "Agreement.h"

class Agent
	: public User
{
private:
	string m_agentId;
	vector<Property*> m_properties;
	vector<Request*> m_receivedRequests;
	vector<Payment*> m_receivedPayments;
	vector<Agreement*> m_agreements;
public:
	Agent() : m_agentId(""), m_properties(), m_receivedPayments(), m_receivedRequests(), m_agreements() {};
	Agent(string agentId, string userId, string userName, string password, string userType, UserStatus status) : m_agentId(agentId), User(userId, userName, password, userType, status) {};
	string getAgentId();
	void displayMenu() override;
	void addProperty(Property* property);
	void addRequest(Request* request);
	void addPayment(Payment* payment);
	void addAgreement(Agreement* agreement);
	vector<Property*>& getProperties();
	vector<Request*>& getRequests();
	vector<Payment*>& getPayments();
	vector<Agreement*>& getAgreements();
};

