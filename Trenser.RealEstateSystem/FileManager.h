#pragma once
#include <iostream>
#include <vector>
using namespace::std;
#include "User.h"
#include "Payment.h"
#include "Property.h"
#include "Request.h"
#include "Agreement.h"

class FileManager
{
private:
	string m_usersFile = "UsersFile.txt";
	string m_paymentsFile = "Payments.txt";
	string m_propertiesFile = "Propertys.txt";
	string m_requestsFile = "RequestsFile.txt";
	string m_agreementFile = "AgreementsFile.txt";
	vector<User> users;
	vector<Payment> payments;
	vector<Property> properties;
	vector<Request> requests;
	vector<Agreement> agreements;
public:
	void load();
	void save();
};

