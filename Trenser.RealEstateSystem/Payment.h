//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------
#pragma once
#include <iostream>
using namespace::std;
#include"Status.h"

class Payment
{
private:
	string m_paymentId;
	string m_requestId;
	string m_buyerId;
	string m_agentId;
	double m_amount;
	PaymentType m_type; 
	PaymentStatus m_status;
	string m_propertyId;
public:
	Payment() : m_paymentId(""), m_requestId(""), m_buyerId(""), m_agentId(""), m_amount(0), m_type(PaymentType::FULL), m_status(PaymentStatus::PENDING), m_propertyId("") {};
	Payment(string paymentId, string requestId, string buyerId, string agentId, double amount, PaymentType type, PaymentStatus status, string propertyId) : m_paymentId(paymentId), m_requestId(requestId), m_buyerId(buyerId), m_agentId(agentId), m_amount(amount), m_type(type), m_status(status), m_propertyId(propertyId) {};
	string getPaymentId();
	string getRequestId();
	string getBuyerId();
	string getAgentId();
	PaymentType getType();
	PaymentStatus getStatus();
	string getPropertyId();
	double getAmount();
	void setAmount(double amount);
	void setType(PaymentType type);
	void setStatus(PaymentStatus status);
};

