#include "FileManager.h"

void FileManager::loadUsers(vector<User*>& users)
{
    ifstream file(m_usersFile);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string id, name, password, type, status;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, type, ',');
        getline(ss, status, ',');
        if (type == "Buyer")
        {
            users.push_back(new Buyer(id, id, name, password, type));
        }
        else if (type == "Agent")
        {
            users.push_back(new Agent(id, id, name, password, type));
        }
        else
        {
            users.push_back(new Admin(id, id, name, password, type));
        }
    }
    file.close();
}

void FileManager::saveUsers(vector<User*>& users)
{
    ofstream file(m_usersFile);
    for (auto user : users)
    {
        file << user->getUserId() << ","
            << user->getUserName() << ","
            << user->getPassword() << ","
            << user->getUserType() << ","
            << user->getStatus() << endl;
    }
    file.close();
}

void FileManager::loadProperties(vector<Property*>& properties)
{
    ifstream file(m_propertiesFile);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string id, category, priceString, agentId, location, status;
        getline(ss, id, ',');
        getline(ss, category, ',');
        getline(ss, priceString, ',');
        getline(ss, agentId, ',');
        getline(ss, location, ',');
        getline(ss, status, ',');
        double price = stod(priceString);
        properties.push_back(new Property(id, category, price, agentId, location, status));
    }
    file.close();
}

void FileManager::saveProperties(vector<Property*>& properties)
{
    ofstream file(m_propertiesFile);
    for (auto property : properties)
    {
        file << property->getPropertyId() << ","
            << property->getCategory() << ","
            << property->getPrice() << ","
            << property->getAgentId() << ","
            << property->getLocation() << ","
            << property->getStatus() << endl;
    }
    file.close();
}

void FileManager::loadRequests(vector<Request*>& requests)
{
    ifstream file(m_requestsFile);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string id, propertyId, buyerId, agentId, status;
        getline(ss, id, ',');
        getline(ss, propertyId, ',');
        getline(ss, buyerId, ',');
        getline(ss, agentId, ',');
        getline(ss, status, ',');
        requests.push_back(new Request(id, propertyId, buyerId, agentId, status));
    }
    file.close();
}

void FileManager::saveRequests(vector<Request*>& requests)
{
    ofstream file(m_requestsFile);
    for (auto request : requests)
    {
        file << request->getRequestId() << ","
            << request->getPropertyId() << ","
            << request->getCustomerId() << ","
            << request->getAgentId() << ","
            << request->getStatus() << endl;
    }
    file.close();
}

void FileManager::loadPayments(vector<Payment*>& payments)
{
    ifstream file(m_paymentsFile);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string id, requestId, buyerId, agentId, amountString, type, status, propertyId;
        getline(ss, id, ',');
        getline(ss, requestId, ',');
        getline(ss, buyerId, ',');
        getline(ss, agentId, ',');
        getline(ss, amountString, ',');
        getline(ss, type, ',');
        getline(ss, status, ',');
        getline(ss, propertyId, ',');
        double amount = stod(amountString);
        payments.push_back(new Payment(id, requestId, buyerId, agentId, amount, type, status, propertyId));
    }
    file.close();
}

void FileManager::savePayments(vector<Payment*>& payments)
{
    ofstream file(m_paymentsFile);
    for (auto payment : payments)
    {
        file << payment->getPaymentId() << ","
            << payment->getRequestId() << ","
            << payment->getBuyerId() << ","
            << payment->getAgentId() << ","
            << payment->getAmount() << ","
            << payment->getType() << ","
            << payment->getStatus() << ","
            << payment->getPropertyId() << endl;
    }
    file.close();
}

void FileManager::loadAgreements(vector<Agreement*>& agreements)
{
    ifstream file(m_agreementsFile);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string id, paymentId, buyerId, agentId, propertyId, terms, date;
        getline(ss, id, ',');
        getline(ss, paymentId, ',');
        getline(ss, buyerId, ',');
        getline(ss, agentId, ',');
        getline(ss, propertyId, ',');
        getline(ss, terms, ',');   
        getline(ss, date, ',');
        agreements.push_back(new Agreement(id, paymentId, buyerId, agentId, propertyId, terms, date));
    }
    file.close();
}

void FileManager::saveAgreements(vector<Agreement*>& agreements)
{
    ofstream file(m_agreementsFile);
    for (auto agreement : agreements)
    {
        file << agreement->getAgreementId() << ","
            << agreement->getRequestId() << ","
            << agreement->getBuyerId() << ","
            << agreement->getAgentId() << ","
            << agreement->getPropertyId() << ","
            << agreement->getTerms() << ","
            << agreement->getDate() << endl;
    }
    file.close();
}

