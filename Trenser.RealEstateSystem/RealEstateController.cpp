#include "RealEstateController.h"

void RealEstateController::mainMenu()
{
    bool flag = true;
    int choice;
    cout << "---- REAL ESTATE MANAGEMENT SYSTEM ----" << endl;
    while (flag)
    {
        cout << "1. Login\n2. Register\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            registerUser();
            break;
        default:
            cout << "Enter a valid choice!" << endl;
            break;
        }
        cout << "Do you want to continue (1 / 0): ";
        cin >> choice;
        if (choice == 0)
        {
            cout << "---- Exited ----" << endl;
            flag = false;
        }
    }
}

void RealEstateController::registerUser()
{
    int choice;
    cout << endl << "1. Register as Buyer\n2. Register as Agent\n3. Register as Admin\nEnter Your Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        registerAsBuyer();
        break;
    case 2:
        registerAsAgent();
        break;
    case 3:
        registerAsAdmin();
        break;
    default:
        cout << "Enter a valid choice!" << endl;
        break;
    }
}

void RealEstateController::registerAsBuyer()
{
    string userId, userName, password;
    cout << endl << "Enter UserId: ";
    cin >> userId;
    if (isUserIdAlreadyExists(userId))
    {
        cout << "User ID already exists!" << endl;
        return;
    }
    cout << "Enter user name: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;
    m_allUsers.push_back(new Buyer(userId, userId, userName, password, "Buyer"));
    cout << "---- Registration Successful ----" << endl << "--- Please Login Again ---" << endl;
}

void RealEstateController::registerAsAgent()
{
    string userId, userName, password;
    cout << endl << "Enter User Id: ";
    cin >> userId;
    if (isUserIdAlreadyExists(userId))
    {
        cout << "User ID already exists!" << endl;
        return;
    }
    cout << "Enter user name: ";
    cin >> userName;
    cout << "Enter Password: ";
    cin >> password;
    m_allUsers.push_back(new Agent(userId, userId, userName, password, "Agent"));
    cout << "---- Registration Successful ----" << endl << "--- Please Login Again ---" << endl;
}

void RealEstateController::registerAsAdmin()
{
    string securityKey = "T20200";
    string userId, userName, password, inputKey;
    cout << "Enter the Security Key: ";
    cin >> inputKey;
    if (inputKey == securityKey)
    {
        cout << endl << "---- Security check success ----" << endl;
        cout << "Enter User Id: ";
        cin >> userId;
        if (isUserIdAlreadyExists(userId))
        {
            cout << "User ID already exists!" << endl;
            return;
        }
        cout << "Enter user name: ";
        cin >> userName;
        cout << "Enter Password: ";
        cin >> password;
        m_allUsers.push_back(new Admin(userId, userId, userName, password, "Admin"));
        cout << "---- Registration Successful ----" << endl << "--- Please Login Again ---" << endl;
        return;
    }
    cout << "----- Security Check Failed! ------" << endl;
}

void RealEstateController::login()
{
    string userId, password;
    int choice;
    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter password: ";
    cin >> password;
    int decision = 1;
    auto iterator = m_allUsers.begin();
    while (iterator != m_allUsers.end())
    {
        if ((*iterator)->getUserId() == userId && (*iterator)->getPassword() == password)
        {
            cout << "--- login successful ---" << endl << endl;
            User* currentUser = *iterator;
            while (decision == 1)
            {
                currentUser->displayMenu();
                cin >> choice;
                chooseOption(currentUser, choice);
                cout << "Do you want to continue (1 / 0): ";
                cin >> decision;
                if (decision == 0)
                {
                    cout << "<---- Logging Out ---->" << endl;
                    return;
                }
            }
        }
        iterator++;
    }
    cout << "User does not exist!" << endl;
}

void RealEstateController::chooseOption(User* user, int& choice)
{
    string type = user->getUserType();
    if (type == "Admin")
    {
        callAdminMethod(user, choice);
    }
    else if (type == "Agent")
    {
        callAgentMethod(user, choice);
    }
    else if (type == "Buyer")
    {
        callBuyerMethod(user, choice);
    }
}

void RealEstateController::callAdminMethod(User* user,int& choice)
{
    switch (choice)
    {
    case 1:
        registerAsAdmin();
        break;
    case 2:
        removeAdmin();
        break;
    case 3:
        registerAsBuyer();
        break;
    case 4:
        removeBuyer();
        break;
    case 5:
        registerAsAgent();
        break;
    case 6:
        removeAgent();
        break;
    case 7:
        addProperty(user);
        break;
    case 8:
        viewAllProperty();
        break;
    case 9:
        viewMyProperty(user);
        break;
    default:
        cout << "Enter a valid option!" << endl;
        break;
    }
}

void RealEstateController::callAgentMethod(User* user, int& choice)
{
    switch (choice)
    {
    case 1:
        addProperty(user);
        break;
    case 2:
        deleteProperty(user);
        break;
    case 3:
        viewMyRequests(user);
        break;
    case 4:
        approveRequest(user);
        break;
    case 5:
        rejectRequest(user);
        break;
    case 6:
        viewMyProperty(user);
        break;
    case 7:
        verifyPayment(user);
        break;
    case 8:
        displayAgreements(user);
        break;
    default:
        cout << "Enter a valid option!" << endl;
        break;
    }
}

void RealEstateController::callBuyerMethod(User* user, int& choice)
{
    switch (choice)
    {
    case 1:
        searchAvailableProperties();
        break;
    case 2:
        searchByCategory();
        break;
    case 3:
        searchByPrice();
        break;
    case 4:
        viewAllProperty();
        break;
    case 5:
        requestToBuy(user);
        break;
    case 6:
        viewMyRequests(user);
        break;
    case 7:
        viewOwnedProperty(user);
        break;
    case 8:
        makePayment(user);
        break;
    case 9:
        displayAgreements(user);
        break;
    default:
        cout << "Enter a valid option!" << endl;
        break;
    }
}

void RealEstateController::removeAdmin()
{
    string userId;
    cout << "Enter Admin Id: ";
    cin >> userId;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); iterator++)
    {
        if ((*iterator)->getUserId() == userId && (*iterator)->getUserType() == "Admin")
        {
            delete* iterator;
            m_allUsers.erase(iterator);
            cout << "Admin " << userId << " removed" << endl;
            return;
        }
    }
    cout << "Admin with this ID not found!" << endl;
}

void RealEstateController::removeBuyer()
{
    string userId;
    cout << "Enter Buyer Id: ";
    cin >> userId;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); iterator++)
    {
        if ((*iterator)->getUserId() == userId && (*iterator)->getUserType() == "Buyer")
        {
            delete *iterator;
            m_allUsers.erase(iterator); 
            cout << "Buyer " << userId << " removed" << endl;
            return;
        }
    }
    cout << "Buyer not found!" << endl;
}

void RealEstateController::removeAgent()
{
    string userId;
    cout << "Enter Agent Id: ";
    cin >> userId;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); iterator++)
    {
        if ((*iterator)->getUserId() == userId && (*iterator)->getUserType() == "Agent")
        {
            delete* iterator;
            m_allUsers.erase(iterator);
            cout << "Agent " << userId << " removed" << endl;
            return;
        }
    }
    cout << "Agent not found!" << endl;
}

void RealEstateController::addProperty(User* user)
{
    string propertyId, category, status, location, agentId;
    double price;
    cout << "Enter Property ID: ";
    cin >> propertyId;
    if (isPropertyIdAlreadyExists(propertyId))
    {
        cout << "Property ID already exists!" << endl;
        return;
    }
    cout << "Category: ";
    cin >> category;
    cout << "Price: ";
    cin >> price;
    if (!isValidPositivePrice(price))
    {
        cout << "Invalid price!" << endl;
        return;
    }
    cout << "Agent Id: ";
    cin >> agentId;
    cout << "Status: ";
    cin >> status;
    cout << "Location: ";
    cin >> location;
    Property* property = new Property(propertyId, category, price, agentId, location, status);
    m_allProperties.push_back(property);
}

void RealEstateController::viewAllProperty()
{
    cout << "------ All Properties ------" << endl << endl;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        cout << "Property ID: " << (*iterator)->getPropertyId() << endl;
        cout << "Price: " << (*iterator)->getPrice() << endl;
        cout << "Category: " << (*iterator)->getCategory() << endl;
        cout << "Status: " << (*iterator)->getStatus() << endl;
        cout << "Location: " << (*iterator)->getLocation() << endl << endl;
    }
}

void RealEstateController::viewMyProperty(User* user)
{
    cout << "--------- Properties Added By " << user->getUserId() << " ----------" << endl;
    for (auto iteratorTwo = m_allProperties.begin(); iteratorTwo != m_allProperties.end(); iteratorTwo++)
    {
        if ((*iteratorTwo)->getAgentId() == user->getUserId())
        {
            cout << "Property ID: " << (*iteratorTwo)->getPropertyId() << endl;
            cout << "Price: " << (*iteratorTwo)->getPrice() << endl;
            cout << "Category: " << (*iteratorTwo)->getCategory() << endl;
            cout << "Status: " << (*iteratorTwo)->getStatus() << endl;
            cout << "Location: " << (*iteratorTwo)->getLocation() << endl << endl;
        }
    }
}

void RealEstateController::viewOwnedProperty(User* user)
{
    cout << "<--- Properties Owned by " << user->getUserName() << " --->" << endl;
    bool found = false;
    for (auto iterator = m_allAgreements.begin(); iterator != m_allAgreements.end(); iterator++)
    {
        if ((*iterator)->getBuyerId() == user->getUserId())
        {
            found = true;
            for (auto iteratorTwo = m_allProperties.begin(); iteratorTwo != m_allProperties.end(); iteratorTwo++)
            {
                if ((*iteratorTwo)->getPropertyId() == (*iterator)->getPropertyId())
                {
                    cout << "Property ID: " << (*iteratorTwo)->getPropertyId() << endl;
                    cout << "Price: " << (*iteratorTwo)->getPrice() << endl;
                    cout << "Category: " << (*iteratorTwo)->getCategory() << endl;
                    cout << "Status: " << (*iteratorTwo)->getStatus() << endl;
                    cout << "Location: " << (*iteratorTwo)->getLocation() << endl << endl;
                    break;
                }
            }
        }
    }
    if (!found)
    {
        cout << "No owned properties found." << endl;
    }
}

void RealEstateController::searchAvailableProperties()
{
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        if ((*iterator)->getStatus() == "Available")
        {
            cout << "Property ID: " << (*iterator)->getPropertyId() << endl;
            cout << "Price: " << (*iterator)->getPrice() << endl;
            cout << "Category: " << (*iterator)->getCategory() << endl;
            cout << "Location: " << (*iterator)->getLocation() << endl << endl;
        }
    }
}

void RealEstateController::searchByCategory()
{
    string category;
    cout << "Enter category: ";
    cin >> category;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        if ((*iterator)->getCategory() == category)
        {
            cout << "Property ID: " << (*iterator)->getPropertyId() << endl;
            cout << "Price: " << (*iterator)->getPrice() << endl;
            cout << "Status: " << (*iterator)->getStatus() << endl;
            cout << "Location: " << (*iterator)->getLocation() << endl << endl;
        }
    }
}

void RealEstateController::searchByPrice()
{
    double price;
    cout << "Enter price: ";
    cin >> price;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        if ((*iterator)->getPrice() == price)
        {
            cout << "Property ID: " << (*iterator)->getPropertyId() << endl;
            cout << "Price: " << (*iterator)->getPrice() << endl;
            cout << "Category: " << (*iterator)->getCategory() << endl;
            cout << "Status: " << (*iterator)->getStatus() << endl;
            cout << "Location: " << (*iterator)->getLocation() << endl << endl;
        }
    }
}

void RealEstateController::searchPropertiesByAgentId()
{
    string agentId;
    cout << "Enter Agent ID: ";
    cin >> agentId;
    for (auto property : m_allProperties)
    {
        if (property->getAgentId() == agentId)
        {
            cout << "Property ID: " << property->getPropertyId() << endl;
            cout << "Price: " << property->getPrice() << endl;
            cout << "Category: " << property->getCategory() << endl;
            cout << "Location: " << property->getLocation() << endl << endl;
        }
    }
}

void RealEstateController::displayBuyerPaymentHistory(User* user)
{
    cout << "Payment History:" << endl;
    for (auto payment : m_allPayments)
    {
        if (payment->getBuyerId() == user->getUserId())
        {
            cout << "Payment ID: " << payment->getPaymentId() << endl;
            cout << "Amount: " << payment->getAmount() << endl;
            cout << "Status: " << payment->getStatus() << endl << endl;
        }
    }
}

void RealEstateController::requestToBuy(User* user)
{
    cout << "<-------- Apply Request ------->" << endl;
    string propertyId, requestId;
    cout << "Enter Property ID : ";
    cin >> propertyId;
    cout << "Enter Request ID: ";
    cin >> requestId;
    if (isRequestIdAlreadyExists(requestId))
    {
        cout << "Request ID already exists!" << endl;
        return;
    }
    for (auto request : m_allRequests)
    {
        if (request->getPropertyId() == propertyId && request->getCustomerId() == user->getUserId())
        {
            cout << "You have already requested this property!" << endl;
            return;
        }
    }
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        if ((*iterator)->getPropertyId() == propertyId)
        {
            m_allRequests.push_back(new Request(requestId, propertyId, user->getUserId(), (*iterator)->getAgentId(), "Pending"));
            cout << "Request created successfully!" << endl;
            return;
        }
    }
    cout << "No property with Id: " << propertyId << " found" << endl;
}

void RealEstateController::viewMyRequests(User* user)
{
    cout << "<----- Requests initiated by " << user->getUserId() << " ----->" << endl;
    if (user->getUserType() == "Agent")
    {
        for (auto iterator = m_allRequests.begin(); iterator != m_allRequests.end(); iterator++)
        {
            if (user->getUserId() == (*iterator)->getAgentId())
            {
                cout << "Request ID: " << (*iterator)->getRequestId() << endl;
                cout << "Property ID: " << (*iterator)->getPropertyId() << endl;
                cout << "Buyer ID: " << (*iterator)->getCustomerId() << endl;
                cout << "Agent ID: " << (*iterator)->getAgentId() << endl;
                cout << "Status: " << (*iterator)->getStatus() << endl << endl;
            }
        }
    }
    else if (user->getUserType() == "Buyer")
    {
        for (auto iterator = m_allRequests.begin(); iterator != m_allRequests.end(); iterator++)
        {
            if (user->getUserId() == (*iterator)->getCustomerId())
            {
                cout << "Request ID: " << (*iterator)->getRequestId() << endl;
                cout << "Property ID: " << (*iterator)->getPropertyId() << endl;
                cout << "Customer ID: " << (*iterator)->getCustomerId() << endl;
                cout << "Agent ID: " << (*iterator)->getAgentId() << endl;
                cout << "Status: " << (*iterator)->getStatus() << endl << endl;
            }
        }
    }
}

void RealEstateController::deleteProperty(User* user)
{
    string propertyId, userId;
    userId = user->getUserId();
    cout << "Enter property Id: ";
    cin >> propertyId;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        if ((*iterator)->getPropertyId() == propertyId && (*iterator)->getAgentId() == userId)
        {
            cout << "<----- Property " << propertyId << " deleted ----->" << endl;
            delete *iterator;
            m_allProperties.erase(iterator);
            return;
        }
    }
    cout << "Property with Id : " << propertyId << " not found" << endl;
}

void RealEstateController::approveRequest(User* user)
{
    string requestId, userId;
    cout << "Enter request ID: ";
    cin >> requestId;
    userId = user->getUserId();
    for (auto iterator = m_allRequests.begin(); iterator != m_allRequests.end(); iterator++)
    {
        if ((*iterator)->getRequestId() == requestId && (*iterator)->getAgentId() == userId)
        {
            (*iterator)->setStatus("Approved");
            cout << "<------ Request Approved ------>" << endl;
            return;
        }
    }
    cout << "No request with ID : " << requestId << " found in Agent " << userId << endl;
}

void RealEstateController::rejectRequest(User* user)
{
    string requestId;
    cout << "Enter request ID: ";
    cin >> requestId;
    string agentId = user->getUserId();
    for (auto iterator = m_allRequests.begin(); iterator != m_allRequests.end(); iterator++)
    {
        if ((*iterator)->getAgentId() == agentId && (*iterator)->getRequestId() == requestId)
        {
            delete (*iterator);
            m_allRequests.erase(iterator);
            cout << "Request has been deleted by " << " Agent : " << agentId << endl;
            return;
        }
    }
    cout << "No request by ID : " << requestId << " exists" << endl;
}

void RealEstateController::makePayment(User* user)
{
    string paymentId, requestId, buyerId, agentId, type, status = "Pending", propertyId;
    double amount = 0;
    cout << "Enter request Id: ";
    cin >> requestId;
    buyerId = user->getUserId();
    for (auto iterator = m_allRequests.begin(); iterator != m_allRequests.end(); iterator++)
    {
        if ((*iterator)->getRequestId() == requestId && (*iterator)->getCustomerId() == buyerId)
        {
            if ((*iterator)->getStatus() != "Approved")
            {
                cout << "Request not approved yet!" << endl;
                return;
            }
            cout << "Payment ID: ";
            cin >> paymentId;
            if (isPaymentIdAlreadyExists(paymentId))
            {
                cout << "Payment ID already exists!" << endl;
                return;
            }
            agentId = (*iterator)->getAgentId();
            for (auto iteratorTwo = m_allProperties.begin(); iteratorTwo != m_allProperties.end(); iteratorTwo++)
            {
                if ((*iteratorTwo)->getPropertyId() == (*iterator)->getPropertyId())
                {
                    amount = (*iteratorTwo)->getPrice();
                    propertyId = (*iteratorTwo)->getPropertyId();
                    break;
                }
            }
            cout << "Payment Type (Full / Advance): ";
            cin >> type;
            m_allPayments.push_back(new Payment(paymentId, requestId, buyerId, agentId, amount, type, status, propertyId));
            cout << "Payment of " << amount << " has been done" << endl;
            cout << "Waiting for confirmation from Agent." << endl;
            return;
        }
    }
    cout << "No request with Id : " << requestId << " found" << endl;
}

void RealEstateController::verifyPayment(User* user)
{
    string paymentId, requestId, buyerId, agentId, propertyId;
    cout << "Enter Payment ID: ";
    cin >> paymentId;
    for (auto iterator = m_allPayments.begin(); iterator != m_allPayments.end(); iterator++)
    {
        if ((*iterator)->getAgentId() == user->getUserId() && (*iterator)->getPaymentId() == paymentId)
        {
            cout << "--- Payment Verified ---" << endl;
            (*iterator)->setStatus("Verified");
            string propertyId = (*iterator)->getPropertyId();
            for (auto property : m_allProperties)
            {
                if (property->getPropertyId() == propertyId)
                {
                    property->setStatus("Sold");
                    break;
                }
            }
            requestId = (*iterator)->getRequestId();
            buyerId = (*iterator)->getBuyerId();
            agentId = (*iterator)->getAgentId();
            propertyId = (*iterator)->getPropertyId();
            generateAgreement(user, paymentId, buyerId, agentId, propertyId);
            return;
        }
    }
    cout << "No Payment with ID: " << paymentId << " found" << endl;
}

void RealEstateController::generateAgreement(User* user, string paymentId, string buyerId, string agentId, string propertyId)
{
    string agreementId, terms, date;
    cout << "Enter Agreement ID: ";
    cin >> agreementId;
    cout << "Enter the terms: ";
    cin.ignore();
    getline(cin, terms);
    cout << "Date: ";
    cin >> date;
    cout << "<---- Agreement Signed ---->" << endl;
    m_allAgreements.push_back(new Agreement(agreementId, paymentId, buyerId, agentId, propertyId, terms, date));
}

void RealEstateController::displayAgreements(User* user)
{
    string userId = user->getUserId();
    cout << "<---- Agreements ---->" << endl;
    for (auto iterator = m_allAgreements.begin(); iterator != m_allAgreements.end(); iterator++)
    {
        if (user->getUserType() == "Agent" && userId == (*iterator)->getAgentId())
        {
            cout << "Agreement Id: " << (*iterator)->getAgreementId() << endl;
            cout << "Payment Id: " << (*iterator)->getRequestId() << endl;
            cout << "Buyer Id: " << (*iterator)->getBuyerId() << endl;
            cout << "Agent Id: " << (*iterator)->getAgentId() << endl;
            cout << "Property Id: " << (*iterator)->getPropertyId() << endl;
            cout << "Terms : " << (*iterator)->getTerms() << endl;
            cout << "Date : " << (*iterator)->getDate() << endl;
        }
        else if (user->getUserType() == "Buyer" && userId == (*iterator)->getBuyerId())
        {
            cout << "Agreement Id: " << (*iterator)->getAgreementId() << endl;
            cout << "Request Id: " << (*iterator)->getRequestId() << endl;
            cout << "Buyer Id: " << (*iterator)->getBuyerId() << endl;
            cout << "Agent Id: " << (*iterator)->getAgentId() << endl;
            cout << "Property Id: " << (*iterator)->getPropertyId() << endl;
            cout << "Terms : " << (*iterator)->getTerms() << endl;
            cout << "Date : " << (*iterator)->getDate() << endl;
        }
    }
    if (m_allAgreements.empty())
    {
        cout << "No Agrements found for User : " << userId << endl;
    }
}

bool RealEstateController::isUserIdAlreadyExists(string userId)
{
    for (auto user : m_allUsers)
    {
        if (user->getUserId() == userId)
        {
            return true;
        }
    }       
    return false;
}

bool RealEstateController::isPropertyIdAlreadyExists(string propertyId)
{
    for (auto property : m_allProperties)
    {
        if (property->getPropertyId() == propertyId)
        {
            return true;
        }
    }       
    return false;
}

bool RealEstateController::isRequestIdAlreadyExists(string requestId)
{
    for (auto request : m_allRequests)
    {
        if (request->getRequestId() == requestId)
        {
            return true;
        }
    }    
    return false;
}

bool RealEstateController::isPaymentIdAlreadyExists(string paymentId)
{
    for (auto payment : m_allPayments)
    {
        if (payment->getPaymentId() == paymentId)
        {
            return true;
        }
    }       
    return false;
}

bool RealEstateController::isValidPositivePrice(double price)
{
    return price > 0;
}

RealEstateController::~RealEstateController()
{
    for (auto user : m_allUsers)
    {
        delete user;
    }
    for (auto property : m_allProperties)
    {
        delete property;
    }
    for (auto request : m_allRequests)
    {
        delete request;
    }
    for (auto payment : m_allPayments)
    {
        delete payment;
    }
    for (auto agreement : m_allAgreements)
    {
        delete agreement;
    }
}
