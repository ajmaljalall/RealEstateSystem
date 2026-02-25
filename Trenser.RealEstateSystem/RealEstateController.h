//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------
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
#include "FileManager.h"
#include "Status.h"

class RealEstateController
{
private:
    vector<User*> m_allUsers;
    vector<Property*> m_allProperties;
    vector<Request*> m_allRequests;
    vector<Payment*> m_allPayments;
    vector<Agreement*> m_allAgreements;
    FileManager* m_fileManager;
    RealEstateController() : m_allUsers(), m_allProperties(), m_allRequests(), m_allPayments(), m_allAgreements(), m_fileManager(nullptr) {};
    RealEstateController(FileManager* fileManager) : m_fileManager(fileManager) {};
public:
    RealEstateController(const RealEstateController&) = delete;
    RealEstateController& operator=(const RealEstateController&) = delete;
    static RealEstateController& getInstanceDefault();
    static RealEstateController& getInstance(FileManager* fileManager);
    ~RealEstateController();
    void loadData();
    void saveData();
    void reloadingDataToVectorsInClass();
    void reassignPropertiesToAgent();
    void reassignPropertiesToBuyer();
    void reassignRequestsToAgentAndBuyer();
    void reassignPaymentsToAgentAndBuyer();
    void reassignAgreementsToAgentAndBuyer();
    void run();
    void login();
    User* authenticateUser(const string& userId, const string& password);
    void userSession(User* currentUser);
    void registerUser();
    void registerAsBuyer();
    void registerAsAgent();
    void registerAsAdmin();
    void changeUserName(User* user);
    void changePassword(User* user);
    int menuChoiceValidation();
    void chooseOption(User* user, int& choice);
    void callAdminMenu(User* user, int& choice);
    void callAgentMenu(User* user, int& choice);
    void callBuyerMenu(User* user, int& choice);
    void handleAdminUserManagement(User* user, int choice);
    void handleAdminPropertyManagement(User* user, int choice);
    void handleAdminReports(int choice);
    void handleAdminAccountSettings(User* user, int choice);
    void handleAgentPropertyManagement(User* user, int choice);
    void handleAgentRequestManagement(User* user, int choice);
    void handleAgentPaymentManagement(User* user, int choice);
    void handleAgentAccountSettings(User* user, int choice);
    void handleBuyerPropertySearch(int choice);
    void handleBuyerRequests(User* user, int choice);
    void handleBuyerPayments(User* user, int choice);
    void handleBuyerAccountSettings(User* user, int choice);
    string generateNextId(string prefix, int currentSize);
    string generateUserId();
    string generateRequestId();
    string generatePropertyId();
    string generatePaymentId();
    string generateAgreementId();
    void removeAdmin(User* user);
    bool securityKeyCheck();
    void removeBuyer();
    void removeAgent();
    void displayAllUsers();
    void displaySystemSummary();
    void addProperty(User* user);
    void createAndStoreProperty(string agentId, string propertyId, CategoryType category, double price);
    void viewAllProperty();
    void searchPropertiesByAgentName();
    void deleteProperty(User* user);
    void showAvailableProperties();
    void searchByCategory();
    void searchByPrice();
    void viewAddedProperties(User* user);
    void viewOwnedProperty(User* user);
    void displaySoldProperties(User* user);
    void displayPropertyDetails(Property* property);
    void requestToBuy(User* user);
    Property* validatePropertySelection(string& propertyId);
    void createRequest(User* user, Property* property);
    void viewRequests(User* user);
    void viewRequestsOfBuyer(User* user);
    void viewRequestsOfAgent(User* user);
    void approveRequest(User* user);
    void approveAndRejectOthers(Request* approved, string agentId);
    void rejectRequest(User* user);
    void viewApprovedRequests(User* user);
    void viewRequestHistory(User* user);
    void cancelBuyerRequest(User* user);
    void printRequestDetails(Request* requestPointer);
    void makePayment(User* user);
    void processPayment(User* user, Request* request);
    void attachPaymentToUsers(Payment* payment);
    void verifyPayment(User* user);
    void completePaymentVerification(Payment* payment);
    void displayPaymentDetails(Payment* payment);
    void displayBuyerPaymentHistory(User* user);
    void displayAgentPaymentHistory(User* user);
    void displayAllPayments();
    void displayPendingPayments(Agent* agent);
    void generateAgreement(User* user, string paymentId, string buyerId, string agentId, string propertyId, Buyer* buyer, Agent* agent);
    void displayAgreements(User* user);
    void displayBuyerAgreements(User* user);
    void displayAgentAgreements(User* user);
    void displayAllAgreements();
    void displayAgreementDetails(Agreement* agreement);
    Agent* findAgentById(string agentId);
    Buyer* findBuyerById(string buyerId);
    bool isUserIdAlreadyExists(string userId);
    bool isPropertyIdAlreadyExists(string propertyId);
    bool isRequestIdAlreadyExists(string requestId);
    bool isPaymentIdAlreadyExists(string paymentId);
    bool isValidPositivePrice(double price);
    bool isAgentIdValid(string agentId);
    bool isPaymentAlreadyVerified(string paymentId);
    string findUserNameById(string id);
    User* findUserById(string id);
    Property* findPropertyById(string id);
    Request* findRequestById(string id);
    Payment* findPaymentById(string id);
    bool isRequestProcessable(Request* request);
    bool isPaymentAlreadyDone(string requestId);
    bool isDuplicateRequest(User* user, string propertyId);
    bool handleRequestCancellation(Request* request, string requestId, User* user);
    bool isSetUserStatusToInactive(string userId);
};
