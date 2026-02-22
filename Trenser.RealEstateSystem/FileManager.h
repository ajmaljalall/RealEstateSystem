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
	string m_usersFile = "UsersFile.txt";
	string m_paymentsFile = "Payments.txt";
	string m_propertiesFile = "Propertys.txt";
	string m_requestsFile = "RequestsFile.txt";
	string m_agreementsFile = "AgreementsFile.txt";
public:
    // LOAD FUNCTIONS
    void loadUsers(vector<User*>& users);
    void loadProperties(vector<Property*>& properties);
    void loadRequests(vector<Request*>& requests);
    void loadPayments(vector<Payment*>& payments);
    void loadAgreements(vector<Agreement*>& agreements);

    // SAVE FUNCTIONS
    void saveUsers(vector<User*>& users);
    void saveProperties(vector<Property*>& properties);
    void saveRequests(vector<Request*>& requests);
    void savePayments(vector<Payment*>& payments);
    void saveAgreements(vector<Agreement*>& agreements);
};

