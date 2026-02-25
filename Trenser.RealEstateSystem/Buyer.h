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

class Buyer
	: public User
{
private:
	string m_buyerId;
	vector<Request*> m_requests;
	vector<Payment*> m_payments;
	vector<Agreement*> m_agreements;
	vector<Property*> m_ownedProperties;
public:
	Buyer() : m_buyerId(""), m_requests(), m_payments(), m_agreements(), m_ownedProperties() {};
	Buyer(string buyerId, string userId, string userName, string password, string userType, UserStatus status) : m_buyerId(buyerId), User(userId, userName, password, userType, status) {};
	string getBuyerId();
	void displayMenu() override;
	void addRequest(Request* request);
	void addPayment(Payment* payment);
	void addAgreement(Agreement* agreement);
	void addOwnedProperty(Property* property);
	vector<Request*>& getRequests();
	vector<Payment*>& getPayments();
	vector<Agreement*>& getAgreements();
	vector<Property*>& getOwnedProperties();
};

