#include "RealEstateController.h"

void RealEstateController::loadData()
{
    m_fileManager->loadUsers(m_allUsers);
    m_fileManager->loadProperties(m_allProperties);
    m_fileManager->loadRequests(m_allRequests);
    m_fileManager->loadPayments(m_allPayments);
    m_fileManager->loadAgreements(m_allAgreements);
    reloadingDataToVectorsInClass();
}
void RealEstateController::saveData()
{
    m_fileManager->saveUsers(m_allUsers);
    m_fileManager->saveProperties(m_allProperties);
    m_fileManager->saveRequests(m_allRequests);
    m_fileManager->savePayments(m_allPayments);
    m_fileManager->saveAgreements(m_allAgreements);
}
void RealEstateController::reloadingDataToVectorsInClass()
{
    reassignPropertiesToAgent();
    reassignPropertiesToBuyer();
    reassignPaymentsToAgentAndBuyer();
    reassignAgreementsToAgentAndBuyer();
}
void RealEstateController::reassignPropertiesToAgent()
{
    for (auto property : m_allProperties)
    {
        string agentId = property->getAgentId();
        for (auto user : m_allUsers)
        {
            if (user->getUserId() == agentId && user->getUserType() == "Agent")
            {
                Agent* agent = dynamic_cast<Agent*>(user);
                if (agent)
                {
                    agent->addProperty(property);
                }
            }
        }
    }
}
void RealEstateController::reassignPropertiesToBuyer()
{
    for (auto agreement : m_allAgreements)
    {
        string buyerId = agreement->getBuyerId();
        string propertyId = agreement->getPropertyId();
        Property* propertyPtr = nullptr;
        for (auto property : m_allProperties)
        {
            if (property->getPropertyId() == propertyId)
            {
                propertyPtr = property;
            }
        }
        for (auto user : m_allUsers)
        {
            if (user->getUserId() == buyerId)
            {
                Buyer* buyer = dynamic_cast<Buyer*>(user);
                if (buyer && propertyPtr)
                {
                    buyer->addOwnedProperty(propertyPtr);
                }
            }
        }
    }
}
void RealEstateController::reassignRequestsToAgentAndBuyer()
{
    for (auto request : m_allRequests)
    {
        string buyerId = request->getCustomerId();
        string agentId = request->getAgentId();
        for (auto user : m_allUsers)
        {
            if (user->getUserId() == buyerId && user->getUserType() == "Buyer")
            {
                Buyer* buyer = dynamic_cast<Buyer*>(user);
                if (buyer)
                {
                    buyer->addRequest(request);
                }
            }
            if (user->getUserId() == agentId && user->getUserType() == "Agent")
            {
                Agent* agent = dynamic_cast<Agent*>(user);
                if (agent)
                {
                    agent->addRequest(request);
                }
            }
        }
    }
}
void RealEstateController::reassignPaymentsToAgentAndBuyer()
{
    for (auto payment : m_allPayments)
    {
        string buyerId = payment->getBuyerId();
        string agentId = payment->getAgentId();
        for (auto user : m_allUsers)
        {
            if (user->getUserId() == buyerId && user->getUserType() == "Buyer")
            {
                Buyer* buyer = dynamic_cast<Buyer*>(user);
                if (buyer)
                {
                    buyer->addPayment(payment);
                }
            }
            if (user->getUserId() == agentId && user->getUserType() == "Agent")
            {
                Agent* agent = dynamic_cast<Agent*>(user);
                if (agent)
                {
                    agent->addPayment(payment);
                }
            }
        }
    }
}
void RealEstateController::reassignAgreementsToAgentAndBuyer()
{
    for (auto agreement : m_allAgreements)
    {
        string buyerId = agreement->getBuyerId();
        string agentId = agreement->getAgentId();
        for (auto user : m_allUsers)
        {
            if (user->getUserId() == buyerId && user->getUserType() == "Buyer")
            {
                Buyer* buyer = dynamic_cast<Buyer*>(user);
                if (buyer)
                {
                    buyer->addAgreement(agreement);
                }
            }
            if (user->getUserId() == agentId && user->getUserType() == "Agent")
            {
                Agent* agent = dynamic_cast<Agent*>(user);
                if (agent)
                {
                    agent->addAgreement(agreement);
                }
            }
        }
    }
}
void RealEstateController::mainMenu()
{
    bool flag = true;
    int choice, decision = 1;
    cout << "---- REAL ESTATE MANAGEMENT SYSTEM ----" << endl << endl;
    while (decision == 1)
    {
        try
        {
            cout << "<--------- Login / Register --------->" << endl << endl;
            cout << "1. Login\n2. Register\nEnter Choice: ";
            cin >> choice;
            if (!cin)
            {
                throw runtime_error("Enter a valid integer for choice!");
            }
            switch (choice)
            {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                cout << "<---------------- Exited --------------->" << endl;
                return;
            default:
                cout << "Enter a valid choice!" << endl;
                break;
            }
            cout << "Do you want to continue (1 - Yes / 0 - No): ";
            cin >> decision;
            if (!cin)
            {
                throw runtime_error("Enter a valid integer for choice!");
            }
            if (decision == 0)
            {
                cout << "<---------------- Exited --------------->" << endl;
            }
        }
        catch (const exception& e)
        {
            cout << "exception : " << e.what() << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            decision = 1;
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
string RealEstateController::generateNextId(string prefix, int currentSize)
{
    int nextNumber = currentSize + 1;
    string id;
    if (nextNumber < 10)
    {
        id = prefix + "0" + to_string(nextNumber);
    }
    else
    {
        id = prefix + to_string(nextNumber);
    }
    return id;
}
string RealEstateController::generateUserId()
{
    return generateNextId("U", m_allUsers.size());
}
string RealEstateController::generateRequestId()
{
    return generateNextId("R", m_allRequests.size());
}
string RealEstateController::generatePropertyId()
{
    return generateNextId("PR", m_allProperties.size());
}
string RealEstateController::generatePaymentId()
{
    return generateNextId("P", m_allPayments.size());
}
string RealEstateController::generateAgreementId()
{
    return generateNextId("A", m_allAgreements.size());
}
void RealEstateController::registerAsBuyer()
{
    string userId, userName, password;
    userId = generateUserId();
    cout << "\nAllocated UserId: " << userId << endl;
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
    cout << "---- Registration Successful ----" << endl << "---- Please Login Again ----\n" << endl;
}
void RealEstateController::registerAsAgent()
{
    string userId, userName, password;
    userId = generateUserId();
    cout << "\nAllocated UserId: " << userId << endl;
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
    cout << "---- Registration Successful ----" << endl << "---- Please Login Again ----\n" << endl;
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
        userId = generateUserId();
        cout << "\nAllocated UserId: " << userId << endl;
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
        cout << "---- Registration Successful ----" << endl << "---- Please Login Again ----\n" << endl;
    }
    else
    {
        cout << "----- Security Check Failed! ------" << endl;
    }
}
void RealEstateController::changeUserName(User* user)
{
    string userName;
    cout << "Enter new user name: ";
    cin >> userName;
    user->setUserName(userName);
    cout << "\n----- User Name Changed Successfully -----\n\n" << endl;
}
void RealEstateController::changePassword(User* user)
{
    string password;
    cout << "Enter new password: ";
    cin >> password;
    user->setPassword(password);
    cout << "\n----- Password Changed Successfully -----\n\n" << endl;
}
void RealEstateController::displayAllUsers()
{
    cout << endl << "<--------- All Users --------->" << endl;
    for (auto user : m_allUsers)
    {
        cout << "ID: " << user->getUserId() << endl;
        cout << "User Name: " << user->getUserName() << endl;
        cout << "User Type: " << user->getUserType() << endl;
        cout << "Status: " << user->getStatus() << endl << endl;;
    }
}
void RealEstateController::login()
{
    string userId, password;
    cout << "\nEnter User ID: ";
    cin >> userId;
    cout << "Enter password: ";
    cin >> password;
    User* currentUser = authenticate(userId, password);
    if (currentUser)
    {
        cout << "\n------- login successful -------" << endl << endl;
        userSession(currentUser);
    }
    else
    {
        cout << "Incorrect credentials or User does not exist!" << endl;
    }
}
User* RealEstateController::authenticate(const string& userId, const string& password)
{
    bool found = false;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); ++iterator)
    {
        if ((*iterator)->getUserId() == userId && (*iterator)->getPassword() == password)
        {
            found = true;
            return *iterator;
        }
    }
    if (!found)
    {
        return nullptr;
    }
}
void RealEstateController::userSession(User* currentUser)
{
    int choice;
    int decision = 1;
    while (decision == 1)
    {
        currentUser->displayMenu();
        cin >> choice;
        chooseOption(currentUser, choice);
        cout << "Do you want to continue (1 - Yes / 0 - No): ";
        cin >> decision;
        if (!cin)
        {
            cout << "enter a valid option!" << endl << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            decision = 1;
        }
        if (decision == 0)
        {
            cout << "<---- Logging Out ---->" << endl;
            return;
        }
        if (decision != 1)
        {
            cout << "enter a valid option!" << endl << endl;
            decision = 1;
        }
    }
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
void RealEstateController::callAdminMethod(User* user, int& choice)
{
    handleAdminUserManagement(choice);
    handleAdminPropertyManagement(user, choice);
    handleAdminReports(choice);
    handleAdminAccountSettings(user, choice);
    if (choice < 1 || choice > 16)
    {
        cout << "Enter a valid option!" << endl;
    }
}
void RealEstateController::handleAdminUserManagement(int choice)
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
    }
}
void RealEstateController::handleAdminPropertyManagement(User* user, int choice)
{
    switch (choice)
    {
    case 7: 
        addProperty(user); 
        break;
    case 8: 
        viewAllProperty(); 
        break;
    case 9: 
        viewAddedProperties(user);
        break;
    case 10: 
        searchPropertiesByAgentId(); 
        break;
    }
}
void RealEstateController::handleAdminReports(int choice)
{
    switch (choice)
    {
    case 11: 
        displayAllUsers(); 
        break;
    case 12: 
        displaySystemSummary(); 
        break;
    case 13: 
        displayAllPayments(); 
        break;
    case 14: 
        displayAllAgreements(); 
        break;
    }
}
void RealEstateController::handleAdminAccountSettings(User* user, int choice)
{
    switch (choice)
    {
    case 15: 
        changeUserName(user); 
        break;
    case 16: 
        changePassword(user); 
        break;
    }
}
void RealEstateController::callAgentMethod(User* user, int& choice)
{
    handleAgentPropertyManagement(user, choice);
    handleAgentRequestManagement(user, choice);
    handleAgentPaymentManagement(user, choice);
    handleAgentAccountSettings(user, choice);
    if (choice < 1 || choice > 12)
    {
        cout << "Enter a valid option!" << endl;
    }
}
void RealEstateController::handleAgentPropertyManagement(User* user, int choice)
{
    switch (choice)
    {
    case 1: 
        addProperty(user); 
        break;
    case 2: 
        deleteProperty(user); 
        break;
    case 6: 
        viewAddedProperties(user);
        break;
    case 10: 
        displaySoldProperties(user); 
        break;
    }
}
void RealEstateController::handleAgentRequestManagement(User* user, int choice)
{
    switch (choice)
    {
    case 3: 
        viewRequests(user); 
        break;
    case 4: 
        approveRequest(user); 
        break;
    case 5: 
        rejectRequest(user); 
        break;
    }
}
void RealEstateController::handleAgentPaymentManagement(User* user, int choice)
{
    switch (choice)
    {
    case 7: 
        verifyPayment(user); 
        break;
    case 8: 
        displayAgreements(user); 
        break;
    case 9: 
        displayAgentPaymentHistory(user); 
        break;
    }
}
void RealEstateController::handleAgentAccountSettings(User* user, int choice)
{
    switch (choice)
    {
    case 11: 
        changeUserName(user); 
        break;
    case 12: 
        changePassword(user); 
        break;
    }
}
void RealEstateController::callBuyerMethod(User* user, int& choice)
{
    handleBuyerPropertySearch(choice);
    handleBuyerRequests(user, choice);
    handleBuyerPayments(user, choice);
    handleBuyerAccountSettings(user, choice);
    if (choice < 1 || choice > 15)
    {
        cout << "Enter a valid option!" << endl;
    }
}
void RealEstateController::handleBuyerPropertySearch(int choice)
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
    }
}
void RealEstateController::handleBuyerRequests(User* user, int choice)
{
    switch (choice)
    {
    case 5: 
        requestToBuy(user); 
        break;
    case 6: 
        viewRequests(user); 
        break;
    case 11: 
        cancelBuyerRequest(user); 
        break;
    case 12: 
        viewApprovedRequests(user); 
        break;
    case 13: 
        viewRejectedRequests(user); 
        break;
    }
}
void RealEstateController::handleBuyerPayments(User* user, int choice)
{
    switch (choice)
    {
    case 7: 
        viewOwnedProperty(user); 
        break;
    case 8: 
        makePayment(user); 
        break;
    case 9: 
        displayAgreements(user); 
        break;
    case 10: 
        displayBuyerPaymentHistory(user); 
        break;
    }
}
void RealEstateController::handleBuyerAccountSettings(User* user, int choice)
{
    switch (choice)
    {
    case 14: 
        changeUserName(user); 
        break;
    case 15: 
        changePassword(user); 
        break;
    }
}
void RealEstateController::removeAdmin()
{
    string userId;
    bool found = false;
    cout << "Enter Admin Id: ";
    cin >> userId;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); iterator++)
    {
        if ((*iterator)->getUserId() == userId && (*iterator)->getUserType() == "Admin")
        {
            found = true;
            (*iterator)->setStatus(UserStatus::ACTIVE);
            cout << "Admin " << userId << " removed" << endl;
            return;
        }
    }
    if (!found)
    {
        cout << "Admin with this ID not found!" << endl;
    }
}
void RealEstateController::removeBuyer()
{
    string userId;
    bool found = false;
    cout << "Enter Buyer Id: ";
    cin >> userId;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); iterator++)
    {
        if ((*iterator)->getUserId() == userId && (*iterator)->getUserType() == "Buyer")
        {
            found = true;
            (*iterator)->setStatus("Inactive");
            cout << "Buyer " << userId << " removed" << endl;
            return;
        }
    }
    if (!found)
    {
        cout << "Buyer not found!" << endl;
    }
}
void RealEstateController::removeAgent()
{
    string userId;
    bool found = false;
    cout << "Enter Agent Id: ";
    cin >> userId;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); iterator++)
    {
        if ((*iterator)->getUserId() == userId && (*iterator)->getUserType() == "Agent")
        {
            found = true;
            (*iterator)->setStatus("Inactive");
            cout << "Agent " << userId << " removed" << endl;
            return;
        }
    }
    if (!found)
    {
        cout << "Agent not found!" << endl;
    }
}
void RealEstateController::addProperty(User* user)
{
    string propertyId, category, status, location, agentId;
    double price;
    propertyId = generatePropertyId();
    cout << "Alocated Property ID: " << propertyId << endl;
    cout << "Category: ";
    cin.ignore();
    getline(cin, category);
    cout << "Price: ";
    cin >> price;
    if (!isValidPositivePrice(price))
    {
        cout << "Invalid price!" << endl;
        return;
    }
    if (user->getUserType() == "Agent")
    {
        agentId = user->getUserId();
    }
    else
    {
        cout << "Agent Id: ";
        cin >> agentId;
        if (!isAgentIdValid(agentId))
        {
            cout << agentId << " is not an agent!" << endl;
            return;
        }
    }
    Agent* agent = findAgentById(agentId);
    if (agent == nullptr)
    {
        cout << "No Agent with Id: " << agentId << " exists" << endl;
        return;
    }
    cout << "Status: ";
    cin.ignore();
    getline(cin, status);
    cout << "Location: ";
    cin >> location;
    Property* property = new Property(propertyId, category, price, agentId, location, status);
    m_allProperties.push_back(property);
    agent->addProperty(property);
    cout << "\n------ Property Added Successfully ------\n" << endl;
}
Agent* RealEstateController::findAgentById(string agentId)
{
    for (auto user : m_allUsers)
    {
        if (user->getUserId() == agentId && user->getUserType() == "Agent")
        {
            return dynamic_cast<Agent*>(user);
        }
    }
    return nullptr;
}
void RealEstateController::viewAllProperty()
{
    if (m_allProperties.empty())
    {
        cout << "No Properties registered in the System" << endl;
        return;
    }
    cout << "------ All Properties ------" << endl << endl;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        cout << "Property ID: " << (*iterator)->getPropertyId() << endl;
        cout << "Price: " << (*iterator)->getPrice() << endl;
        cout << "Category: " << (*iterator)->getCategory() << endl;
        cout << "Status: " << (*iterator)->getStatus() << endl;
        cout << "Location: " << (*iterator)->getLocation() << endl;
        cout << "Added By: " << (*iterator)->getAgentId() << endl << endl;
    }
}
void RealEstateController::viewAddedProperties(User* user)
{
    bool found = false;
    cout << "--------- Properties Added By " << user->getUserId() << " ----------" << endl;
    for (auto iteratorTwo = m_allProperties.begin(); iteratorTwo != m_allProperties.end(); iteratorTwo++)
    {
        if ((*iteratorTwo)->getAgentId() == user->getUserId())
        {
            found = true;
            cout << "Property ID: " << (*iteratorTwo)->getPropertyId() << endl;
            cout << "Price: " << (*iteratorTwo)->getPrice() << endl;
            cout << "Category: " << (*iteratorTwo)->getCategory() << endl;
            cout << "Status: " << (*iteratorTwo)->getStatus() << endl;
            cout << "Location: " << (*iteratorTwo)->getLocation() << endl << endl;
        }
    }
    if (!found)
    {
        cout << "No Properties Added By " << user->getUserId() << endl;
    }
}
void RealEstateController::viewOwnedProperty(User* user)
{
    Buyer* buyer = dynamic_cast<Buyer*>(user);
    vector<Property*>& properties = buyer->getOwnedProperties();
    cout << "\n<------ OWNED PROPERTIES ------>\n";
    if (properties.empty())
    {
        cout << "No owned properties.\n";
        return;
    }
    for (auto property : properties)
    {
        cout << "Property ID: " << property->getPropertyId() << endl;
        cout << "Price: " << property->getPrice() << endl;
        cout << "Category: " << property->getCategory() << endl;
        cout << "Location: " << property->getLocation() << endl;
        cout << "Status: " << property->getStatus() << endl << endl;
    }
}
void RealEstateController::searchAvailableProperties()
{
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        if ((*iterator)->getStatus() == "Available")
        {
            cout << endl << "Property ID: " << (*iterator)->getPropertyId() << endl;
            cout << "Price: " << (*iterator)->getPrice() << endl;
            cout << "Category: " << (*iterator)->getCategory() << endl;
            cout << "Location: " << (*iterator)->getLocation() << endl;
            cout << "Agent ID: " << (*iterator)->getAgentId() << endl;
        }
    }
}
void RealEstateController::searchByCategory()
{
    string category;
    cout << "Enter category: ";
    cin.ignore();
    getline(cin, category);
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        if ((*iterator)->getCategory() == category)
        {
            cout << "Property ID: " << (*iterator)->getPropertyId() << endl;
            cout << "Price: " << (*iterator)->getPrice() << endl;
            cout << "Status: " << (*iterator)->getStatus() << endl;
            cout << "Location: " << (*iterator)->getLocation() << endl;
            cout << "Agent ID: " << (*iterator)->getAgentId() << endl << endl;
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
        if ((*iterator)->getPrice() <= price)
        {
            cout << "Property ID: " << (*iterator)->getPropertyId() << endl;
            cout << "Price: " << (*iterator)->getPrice() << endl;
            cout << "Category: " << (*iterator)->getCategory() << endl;
            cout << "Status: " << (*iterator)->getStatus() << endl;
            cout << "Location: " << (*iterator)->getLocation() << endl;
            cout << "Agent ID: " << (*iterator)->getAgentId() << endl << endl;
        }
    }
}
void RealEstateController::searchPropertiesByAgentId()
{
    string agentId;
    cout << "Enter Agent ID: ";
    cin >> agentId;
    if (!isUserIdAlreadyExists(agentId))
    {
        cout << "No Agent with ID: " << agentId << " exists." << endl;
        return;
    }
    if (!isAgentIdValid(agentId))
    {
        cout << agentId << " is not an Agent." << endl;
        return;
    }
    bool found = false;
    cout << "<------ Properties Under Agent : " << agentId << " ------>" << endl;
    for (auto property : m_allProperties)
    {
        if (property->getAgentId() == agentId)
        {
            found = true;
            cout << "Property ID: " << property->getPropertyId() << endl;
            cout << "Price: " << property->getPrice() << endl;
            cout << "Category: " << property->getCategory() << endl;
            cout << "Location: " << property->getLocation() << endl << endl;
        }
    }
    if (!found)
    {
        cout << "No Properties Added by Agent : " << agentId << endl << endl;
    }
}
bool RealEstateController::isAgentIdValid(string agentId)
{
    for (auto user : m_allUsers)
    {
        if (user->getUserId() == agentId && user->getUserType() != "Buyer")
        {
            return true;
        }
    }
    return false;
}
void RealEstateController::displayBuyerPaymentHistory(User* user)
{
    Buyer* buyer = dynamic_cast<Buyer*>(user);
    vector<Payment*>& payments = buyer->getPayments();
    cout << "<---------- Payment History ---------->" << endl;
    if (payments.empty())
    {
        cout << "No payments found.\n";
        return;
    }
    for (auto payment : payments)
    {
        cout << "Payment ID: " << payment->getPaymentId() << endl;
        cout << "Amount: " << payment->getAmount() << endl;
        cout << "Status: " << payment->getStatus() << endl;
        cout << "Done to: " << payment->getAgentId() << endl << endl;
    }
}
void RealEstateController::requestToBuy(User* user)
{
    cout << "<-------- Apply Request ------->" << endl;
    string propertyId, requestId, buyerId, agentId;
    requestId = generateRequestId();
    cout << "Alocated Request ID: " << requestId << endl;
    cout << "Enter Property ID : ";
    cin >> propertyId;
    Property* selectedProperty = nullptr;
    for (auto property : m_allProperties)
    {
        if (property->getPropertyId() == propertyId && property->getStatus() == "Available")
        {
            selectedProperty = property;
            break;
        }
        if (property->getPropertyId() == propertyId && property->getStatus() == "Sold")
        {
            cout << "Property already sold." << endl;
            return;
        }
        if (property->getPropertyId() == propertyId && property->getStatus() == "Unavailable")
        {
            cout << "Property is unavailable." << endl;
            return;
        }
    }
    if (selectedProperty == nullptr)
    {
        cout << "No property with Id: " << propertyId << " found" << endl;
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
    buyerId = user->getUserId();
    agentId = selectedProperty->getAgentId();
    Buyer* buyer = findBuyerById(buyerId);
    Agent* agent = findAgentById(agentId);
    if (buyer == nullptr || agent == nullptr)
    {
        cout << "System error: Buyer or Agent not found!" << endl;
        return;
    }
    Request* newRequest = new Request(requestId, propertyId, buyerId, agentId, "Waiting For Approval");
    m_allRequests.push_back(newRequest);
    buyer->addRequest(newRequest);
    agent->addRequest(newRequest);
    cout << "\n------ Request Created Successfully ------\n" << endl;
}
Buyer* RealEstateController::findBuyerById(string buyerId)
{
    for (auto user : m_allUsers)
    {
        if (user->getUserId() == buyerId && user->getUserType() == "Buyer")
        {
            return dynamic_cast<Buyer*>(user);
        }
    }
    return nullptr;
}
void RealEstateController::viewRequests(User* user)
{
    if (user->getUserType() == "Buyer")
    {
        cout << "<----- Requests initiated by " << user->getUserId() << " ----->" << endl;
        Buyer* buyer = dynamic_cast<Buyer*>(user);
        vector<Request*>& requests = buyer->getRequests();
        if (requests.empty())
        {
            cout << "No requests found.\n";
            return;
        }
        for (auto iterator = requests.begin(); iterator != requests.end(); iterator++)
        {
            printRequestDetails(*iterator);
        }
    }
    else if (user->getUserType() == "Agent")
    {
        cout << "<----- Requests received by " << user->getUserId() << " ----->" << endl;
        Agent* agent = dynamic_cast<Agent*>(user);
        vector<Request*>& requests = agent->getRequests();
        if (requests.empty())
        {
            cout << "No requests found.\n";
            return;
        }
        for (auto iterator = requests.begin(); iterator != requests.end(); iterator++)
        {
            if ((*iterator)->getStatus() != "Cancelled")
            {
                printRequestDetails(*iterator);
            }
        }
    }
}
void RealEstateController::printRequestDetails(Request* request) 
{ 
    cout << "Request ID: " << request->getRequestId() << endl;
    cout << "Property ID: " << request->getPropertyId() << endl; 
    cout << "Buyer ID: " << request->getCustomerId() << endl; 
    cout << "Agent ID: " << request->getAgentId() << endl; 
    cout << "Status: " << request->getStatus() << endl << endl; 
}
void RealEstateController::deleteProperty(User* user)
{
    string propertyId, userId;
    bool found = false;
    userId = user->getUserId();
    cout << "Enter property Id: ";
    cin >> propertyId;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++)
    {
        if ((*iterator)->getPropertyId() == propertyId && (*iterator)->getAgentId() == userId)
        {
            found = true;
            if ((*iterator)->getStatus() == "Unavailable")
            {
                cout << "Property already deleted." << endl;
                return;
            }
            if ((*iterator)->getStatus() == "Sold")
            {
                cout << "Property has been sold." << endl;
                return;
            }
            if ((*iterator)->getStatus() == "Available")
            {
                cout << "Property " << propertyId << " deleted." << endl;
                (*iterator)->setStatus("Unavailable");
                return;
            }
        }
    }
    if (!found)
    {
        cout << "Property with Id : " << propertyId << " not found" << endl;
    }
}
void RealEstateController::approveRequest(User* user)
{
    string requestId, userId;
    bool found = false;
    cout << "Enter request ID: ";
    cin >> requestId;
    userId = user->getUserId();
    for (auto iterator = m_allRequests.begin(); iterator != m_allRequests.end(); iterator++)
    {
        if ((*iterator)->getRequestId() == requestId && (*iterator)->getAgentId() == userId)
        {
            found = true;
            if ((*iterator)->getStatus() == "Approved")
            {
                cout << "Request already approved." << endl;
                return;
            }
            if ((*iterator)->getStatus() == "Rejected")
            {
                cout << "Request has already been rejected." << endl;
                return;
            }
            else
            {
                (*iterator)->setStatus("Approved");
                cout << "Request has been approved by Agent : " << userId << endl;
                return;
            }
        }
    }
    if (!found)
    {
        cout << "No request with ID : " << requestId << " found in Agent " << userId << endl;
    }
}
void RealEstateController::rejectRequest(User* user)
{
    string requestId;
    bool found = false;
    cout << "Enter request ID: ";
    cin >> requestId;
    string agentId = user->getUserId();
    for (auto iterator = m_allRequests.begin(); iterator != m_allRequests.end(); iterator++)
    {
        if ((*iterator)->getAgentId() == agentId && (*iterator)->getRequestId() == requestId)
        {
            found = true;
            if ((*iterator)->getStatus() == "Rejected")
            {
                cout << "Request has already been rejected." << endl;
                return;
            }
            if ((*iterator)->getStatus() == "Approved")
            {
                cout << "Request has already been approved." << endl;
                return;
            }
            else
            {
                (*iterator)->setStatus("Rejected");
                cout << "Request has been rejected by Agent : " << agentId << endl;
                return;
            }  
        }
    }
    if (!found)
    {
        cout << "No request by ID : " << requestId << " exists" << endl;
    }
}
void RealEstateController::makePayment(User* user)
{
    string paymentId, requestId, buyerId, agentId, type, status = "Pending", propertyId;
    double amount = 0;
    cout << "Enter request Id: ";
    cin >> requestId;
    buyerId = user->getUserId();
    Request* selectedRequest = nullptr;
    for (auto request : m_allRequests)
    {
        if (request->getRequestId() == requestId && request->getCustomerId() == buyerId)
        {
            selectedRequest = request;
            break;
        }
    }
    if (selectedRequest == nullptr)
    {
        cout << "No request with Id : " << requestId << " found" << endl;
        return;
    }
    if (selectedRequest->getStatus() == "Rejected")
    {
        cout << "Request has been rejected!" << endl;
        return;
    }
    if (selectedRequest->getStatus() == "Cancelled")
    {
        cout << "Request has been cancelled by you.!" << endl;
        return;
    }
    if (selectedRequest->getStatus() != "Approved")
    {
        cout << "Request not approved yet!" << endl;
        return;
    }
    propertyId = selectedRequest->getPropertyId();
    agentId = selectedRequest->getAgentId();
    for (auto property : m_allProperties)
    {
        if (property->getPropertyId() == propertyId)
        {
            amount = property->getPrice();
            break;
        }
    }
    paymentId = generatePaymentId();
    cout << "Allocated Payment ID: " << paymentId << endl;
    cout << "Payment Type (Full / Advance): ";
    cin >> type;
    Payment* newPayment = new Payment(paymentId, requestId, buyerId, agentId, amount, type, status, propertyId);
    m_allPayments.push_back(newPayment);
    Buyer* buyer = findBuyerById(buyerId);
    buyer->addPayment(newPayment);
    Agent* agent = findAgentById(agentId);
    agent->addPayment(newPayment);
    cout << "\n------ Payment Done Successfully ------" << endl;
    cout << "Waiting for Agent Verification..." << endl << endl;
}
void RealEstateController::verifyPayment(User* user)
{
    string paymentId, requestId, buyerId, agentId, propertyId, terms, date;
    cout << "Enter Payment ID to verify: ";
    cin >> paymentId;
    if (isPaymentAlreadyVerified(paymentId))
    {
        cout << "Payment already verified and agreement generated for the property." << endl << endl;
        return;
    }
    Payment* selectedPayment = nullptr;
    for (auto payment : m_allPayments)
    {
        if (payment->getPaymentId() == paymentId && payment->getAgentId() == user->getUserId())
        {
            selectedPayment = payment;
            break;
        }
    }
    if (selectedPayment == nullptr)
    {
        cout << "No Payment found with ID: " << paymentId << endl;
        return;
    }
    selectedPayment->setStatus("Verified");
    propertyId = selectedPayment->getPropertyId();
    buyerId = selectedPayment->getBuyerId();
    agentId = selectedPayment->getAgentId();
    Property* soldProperty = nullptr;
    for (auto property : m_allProperties)
    {
        if (property->getPropertyId() == propertyId)
        {
            soldProperty = property;
            property->setStatus("Sold");
            break;
        }
    }
    Buyer* buyer = findBuyerById(buyerId);
    Agent* agent = findAgentById(agentId);
    if (buyer == nullptr || agent == nullptr || soldProperty == nullptr)
    {
        cout << "System error during verification!" << endl;
        return;
    }
    buyer->addOwnedProperty(soldProperty);
    generateAgreement(user, paymentId, buyerId, agentId, propertyId, buyer, agent);
}
bool RealEstateController::isPaymentAlreadyVerified(string paymentId)
{
    for (auto payment : m_allPayments)
    {
        if (payment->getPaymentId() == paymentId)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void RealEstateController::generateAgreement(User* user, string paymentId, string buyerId, string agentId, string propertyId, Buyer* buyer, Agent* agent)
{
    string agreementId, terms, date;
    agreementId = generateAgreementId();
    cout << "Allocated Agreement ID: " << agreementId << endl;
    cout << "Enter Agreement terms: ";
    cin.ignore();
    getline(cin, terms);
    cout << "Enter Agreement Date: ";
    cin >> date;
    Agreement* newAgreement = new Agreement(agreementId, paymentId, buyerId, agentId, propertyId, terms, date);
    m_allAgreements.push_back(newAgreement);
    buyer->addAgreement(newAgreement);
    agent->addAgreement(newAgreement);
    cout << "\n------ Payment Verified Successfully ------" << endl;
    cout << "------ Ownership Transferred to Buyer ------" << endl;
    cout << "-------- Agreement Generated --------" << endl << endl;
}
void RealEstateController::displayAgreements(User* user)
{
    string userId = user->getUserId();
    bool found = false;
    cout << "<---- Agreements ---->" << endl;
    if (user->getUserType() == "Buyer")
    {
        Buyer* buyer = dynamic_cast<Buyer*>(user);
        vector<Agreement*>& agreements = buyer->getAgreements();
        if (agreements.empty())
        {
            cout << "No agreements found.\n";
            return;
        }
        for (auto agreement : agreements)
        {
            displayAgreementDetails(agreement);
        }
    }
    else if (user->getUserType() == "Agent")
    {
        Agent* agent = dynamic_cast<Agent*>(user);
        vector<Agreement*>& agreements = agent->getAgreements();
        if (agreements.empty())
        {
            cout << "No agreements found.\n";
            return;
        }
        for (auto agreement : agreements)
        {
            displayAgreementDetails(agreement);
        }
    }
}
void RealEstateController::displayAgreementDetails(Agreement* agreement)
{
    cout << "Agreement Id: " << agreement->getAgreementId() << endl;
    cout << "Payment Id: " << agreement->getRequestId() << endl;
    cout << "Buyer Id: " << agreement->getBuyerId() << endl;
    cout << "Agent Id: " << agreement->getAgentId() << endl;
    cout << "Property Id: " << agreement->getPropertyId() << endl;
    cout << "Terms : " << agreement->getTerms() << endl;
    cout << "Date : " << agreement->getDate() << endl << endl;
}
void RealEstateController::displayAllAgreements()
{
    if (m_allAgreements.empty())
    {
        cout << "No Agreements have been signed." << endl;
        return;
    }
    cout << "------- All Agreement Details -------" << endl;
    for (auto agreement : m_allAgreements)
    {
        displayAgreementDetails(agreement);
        cout << endl;
    }
}
void RealEstateController::displaySystemSummary()
{
    cout << "Total Users: " << m_allUsers.size() << endl;
    cout << "Total Properties: " << m_allProperties.size() << endl;
    cout << "Total Requests: " << m_allRequests.size() << endl;
    cout << "Total Payments: " << m_allPayments.size() << endl;
    cout << "Total Agreements: " << m_allAgreements.size() << endl;
}
void RealEstateController::displayAllPayments()
{
    if (m_allPayments.empty())
    {
        cout << "No Payments has been done yet." << endl;
        return;
    }
    cout << "------- All Payment Details -------" << endl;
    for (auto payment : m_allPayments)
    {
        cout << "Payment ID: " << payment->getPaymentId() << endl;
        cout << "Amount: " << payment->getAmount() << endl;
        cout << "Status: " << payment->getStatus() << endl;
        cout << "Done By: " << payment->getBuyerId() << endl;
        cout << "To : " << payment->getAgentId() << endl << endl;
    }
}
void RealEstateController::displayAgentPaymentHistory(User* user)
{
    Agent* agent = dynamic_cast<Agent*>(user);
    vector<Payment*>& payments = agent->getPayments();
    cout << "\n<------ PAYMENTS RECEIVED ------>\n";
    if (payments.empty())
    {
        cout << "No payments received.\n";
        return;
    }
    for (auto payment : payments)
    {
        cout << "Payment ID: " << payment->getPaymentId() << endl;
        cout << "Amount: " << payment->getAmount() << endl;
        cout << "Buyer ID: " << payment->getBuyerId() << endl;
        cout << "Status: " << payment->getStatus() << endl << endl;
    }
}
void RealEstateController::displaySoldProperties(User* user)
{
    bool found = false;
    cout << "<------ Properties Sold By Agent : " << user->getUserId() << " ------>" << endl;
    for (auto property : m_allProperties)
    {
        if (property->getAgentId() == user->getUserId() && property->getStatus() == "Sold")
        {
            found = true;
            cout << "Property ID: " << property->getPropertyId() << endl;
            cout << "Price: " << property->getPrice() << endl << endl;
        }
    }
    if (!found)
    {
        cout << "No Properties have been sold by Agent : " << user->getUserId() << endl << endl;
    }
}
void RealEstateController::cancelBuyerRequest(User* user)
{
    string requestId;
    cout << "Enter Request ID to cancel: ";
    cin >> requestId;
    bool found = false;
    for (auto request : m_allRequests)
    {
        if (request->getRequestId() == requestId && request->getCustomerId() == user->getUserId())
        {
            found = true;
            request->setStatus("Cancelled");
            cout << "Request cancelled!" << endl;
            return;
        }
    }
    if (!found)
    {
        cout << "Request ID : " << requestId << " not found" << endl;
    }
}
void RealEstateController::viewApprovedRequests(User* user)
{
    cout << "<------ Requests Approved ------>" << endl;
    bool found = false;
    for (auto request : m_allRequests)
    {
        if (request->getCustomerId() == user->getUserId() && request->getStatus() == "Approved")
        {
            found = true;
            printRequestDetails(request);
        }
    }
    if (!found)
    {
        cout << "------ No Request Found ------" << endl;
    }
}
void RealEstateController::viewRejectedRequests(User* user)
{
    cout << "<------ Requests Rejected ------>" << endl;
    bool found = false;
    for (auto request : m_allRequests)
    {
        if (request->getCustomerId() == user->getUserId() && request->getStatus() == "Rejected")
        {
            found = true;
            printRequestDetails(request);
        }
    }
    if (!found)
    {
        cout << "------ No Request Found ------" << endl;
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
