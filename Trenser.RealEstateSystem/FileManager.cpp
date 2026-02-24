#include "FileManager.h"

void FileManager::loadUsers(vector<User*>& users)
{
    ifstream file(M_USERSFILE);
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
        if (type == Buyer::BUYER)
        {
            users.push_back(new Buyer(id, id, name, password, type, stringToUserStatus(status)));
        }
        else if (type == Agent::AGENT)
        {
            users.push_back(new Agent(id, id, name, password, type, stringToUserStatus(status)));
        }
        else
        {
            users.push_back(new Admin(id, id, name, password, type, stringToUserStatus(status)));
        }
    }
    file.close();
}
void FileManager::saveUsers(vector<User*>& users)
{
    ofstream file(M_USERSFILE);
    for (auto user : users)
    {
        file << user->getUserId() << ","
            << user->getUserName() << ","
            << user->getPassword() << ","
            << user->getUserType() << ","
            << convertingUserStatusToString(user->getStatus()) << endl;
    }
    file.close();
}
void FileManager::loadProperties(vector<Property*>& properties)
{
    ifstream file(M_PROPERTIESFILE);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string id, name, category, priceString, agentId, location, status;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, category, ',');
        getline(ss, priceString, ',');
        getline(ss, agentId, ',');
        getline(ss, location, ',');
        getline(ss, status, ',');
        double price = stod(priceString);
        properties.push_back(new Property(id, name,stringToCategoryType(category), price, agentId, location, stringToPropertyStatus(status)));
    }
    file.close();
}
void FileManager::saveProperties(vector<Property*>& properties)
{
    ofstream file(M_PROPERTIESFILE);
    for (auto property : properties)
    {
        file << property->getPropertyId() << ","
            << property->getPropertyName() << ","
            << convertingCategoryTypeToString(property->getCategory()) << ","
            << property->getPrice() << ","
            << property->getAgentId() << ","
            << property->getLocation() << ","
            << convertingPropertyStatusToString(property->getStatus()) << endl;
    } 
    file.close();
}
void FileManager::loadRequests(vector<Request*>& requests)
{
    ifstream file(M_REQUESTSFILE);
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
        requests.push_back(new Request(id, propertyId, buyerId, agentId, stringToRequestStatus(status)));
    }
    file.close();
}
void FileManager::saveRequests(vector<Request*>& requests)
{
    ofstream file(M_REQUESTSFILE);
    for (auto request : requests)
    {
        file << request->getRequestId() << ","
            << request->getPropertyId() << ","
            << request->getBuyerId() << ","
            << request->getAgentId() << ","
            << convertingRequestStatusToString(request->getStatus()) << endl;
    }
    file.close();
}
void FileManager::loadPayments(vector<Payment*>& payments)
{
    ifstream file(M_PAYMENTSFILE);
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
        payments.push_back(new Payment(id, requestId, buyerId, agentId, amount, stringToPaymentType(type), stringToPaymentStatus(status), propertyId));
    }
    file.close();
}
void FileManager::savePayments(vector<Payment*>& payments)
{
    ofstream file(M_PAYMENTSFILE);
    for (auto payment : payments)
    {
        file << payment->getPaymentId() << ","
            << payment->getRequestId() << ","
            << payment->getBuyerId() << ","
            << payment->getAgentId() << ","
            << payment->getAmount() << ","
            << convertingPaymentTypeToString((payment->getType())) << ","
            << convertingPaymentStatusToString(payment->getStatus()) << ","
            << payment->getPropertyId() << endl;
    }
    file.close();
}
void FileManager::loadAgreements(vector<Agreement*>& agreements)
{
    ifstream file(M_AGREEMENTSFILE);
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
    ofstream file(M_AGREEMENTSFILE);
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

