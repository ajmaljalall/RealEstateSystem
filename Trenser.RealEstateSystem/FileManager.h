//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace::std;
#include "User.h"
#include "Buyer.h"
#include "Agent.h"
#include "Admin.h"
#include "Payment.h"
#include "Property.h"
#include "Request.h"
#include "Agreement.h"

class FileManager
{
private:
	const string M_USERSFILE = "UsersFile.txt";
	const string M_PAYMENTSFILE = "Payments.txt";
	const string M_PROPERTIESFILE = "Propertys.txt";
	const string M_REQUESTSFILE = "RequestsFile.txt";
	const string M_AGREEMENTSFILE = "AgreementsFile.txt";
public:
    void loadUsers(vector<User*>& users);
    void loadProperties(vector<Property*>& properties);
    void loadRequests(vector<Request*>& requests);
    void loadPayments(vector<Payment*>& payments);
    void loadAgreements(vector<Agreement*>& agreements);
    void saveUsers(vector<User*>& users);
    void saveProperties(vector<Property*>& properties);
    void saveRequests(vector<Request*>& requests);
    void savePayments(vector<Payment*>& payments);
    void saveAgreements(vector<Agreement*>& agreements);
};

