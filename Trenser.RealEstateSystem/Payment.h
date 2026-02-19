#pragma once
#include <iostream>
using namespace::std;

class Payment
{
private:
	string m_paymentId;
	string m_requestId;
	string m_buyerId;
	string m_agentId;
	double m_amount;
	string m_type;
	string m_status;
	string m_propertyId;
public:
	Payment() : m_paymentId(""), m_requestId(""), m_buyerId(""), m_agentId(""), m_amount(0), m_type(""), m_status(""), m_propertyId("") {};
	Payment(string paymentId, string requestId, string buyerId, string agentId, double amount, string type, string status, string propertyId) : m_paymentId(paymentId), m_requestId(requestId), m_buyerId(buyerId), m_agentId(agentId), m_amount(amount), m_type(type), m_status(status), m_propertyId(propertyId) {};
	string getPaymentId();
	string getRequestId();
	string getBuyerId();
	string getAgentId();
	string getType();
	string getStatus();
	string getPropertyId();
	void setAmount(double amount);
	void setType(string type);
	void setStatus(string status);
	void makePayment();
	void verifyPayment();
};

