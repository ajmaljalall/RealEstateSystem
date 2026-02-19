#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "User.h"
#include "Buyer.h"
#include "Admin.h"
#include "Agent.h"
#include "Property.h"
#include "Request.h"
#include "Payment.h"
#include "Agreement.h"

class RealEstateController
{
private:
    vector<User*> m_allUsers;
    vector<Property*> m_allProperties;
    vector<Request*> m_allRequests;
    vector<Payment*> m_allPayments;
    vector<Agreement*> m_allAgreements;

public:
    RealEstateController() : m_allUsers(), m_allProperties(), m_allRequests(), m_allPayments(), m_allAgreements() {};
    ~RealEstateController();

    void mainMenu();
    void login();
    void registerUser();
    void registerAsBuyer();
    void registerAsAgent();
    void registerAsAdmin();

    void chooseOption(User* user, int& choice);
    void callAdminMethod(User* user, int& choice);
    void callAgentMethod(User* user, int& choice);
    void callBuyerMethod(User* user, int& choice);

    void removeAdmin();
    void removeBuyer();
    void removeAgent();
    void addProperty(User* user);
    void viewAllProperty();
    void viewMyProperty(User* user);

    void searchAvailableProperties();
    void searchByCategory();
    void searchByPrice();
    void requestToBuy(User* user);
    void viewMyRequests(User* user);
    void viewOwnedProperty(User* user);

    void deleteProperty(User* user);
    void approveRequest(User* user);
    void rejectRequest(User* user);

    void makePayment(User* user);
    void verifyPayment(User* user);
    void generateAgreement(User* user, string paymentId, string buyerId, string agentId, string propertyId);
    void displayAgreements(User* user);

    bool isUserIdAlreadyExists(string userId);
    bool isPropertyIdAlreadyExists(string propertyId);
    bool isRequestIdAlreadyExists(string requestId);
    bool isPaymentIdAlreadyExists(string paymentId);
    bool isValidPositivePrice(double price);

    void searchPropertiesByAgentId();
    void displayBuyerPaymentHistory(User* user);
};
