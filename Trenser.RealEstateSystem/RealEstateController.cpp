#include "RealEstateController.h"

RealEstateController& RealEstateController::getInstanceDefault() {
    static RealEstateController realEstateController;
    return realEstateController;
}
RealEstateController& RealEstateController::getInstance(FileManager* fileManager) {
    static RealEstateController realEstateController(fileManager);
    return realEstateController;
}
void RealEstateController::loadData() {
    m_fileManager->loadUsers(m_allUsers);
    m_fileManager->loadProperties(m_allProperties);
    m_fileManager->loadRequests(m_allRequests);
    m_fileManager->loadPayments(m_allPayments);
    m_fileManager->loadAgreements(m_allAgreements);
    reloadingDataToVectorsInClass();
}
void RealEstateController::saveData() {
    m_fileManager->saveUsers(m_allUsers);
    m_fileManager->saveProperties(m_allProperties);
    m_fileManager->saveRequests(m_allRequests);
    m_fileManager->savePayments(m_allPayments);
    m_fileManager->saveAgreements(m_allAgreements);
}
void RealEstateController::reloadingDataToVectorsInClass() {
    reassignPropertiesToAgent();
    reassignPropertiesToBuyer();
    reassignPaymentsToAgentAndBuyer();
    reassignAgreementsToAgentAndBuyer();
    reassignRequestsToAgentAndBuyer();
}
void RealEstateController::reassignPropertiesToAgent() {
    for (auto property : m_allProperties) {
        string agentId = property->getAgentId();
        for (auto user : m_allUsers) {
            if (user->getUserId() == agentId && user->getUserType() == USERTYPETWO) {
                Agent* agent = dynamic_cast<Agent*>(user);
                if (agent) {
                    agent->addProperty(property);
                }
            }
        }
    }
}
void RealEstateController::reassignPropertiesToBuyer() {
    for (auto agreement : m_allAgreements) {
        string buyerId = agreement->getBuyerId();
        string propertyId = agreement->getPropertyId();
        Property* propertyPtr = nullptr;
        for (auto property : m_allProperties) {
            if (property->getPropertyId() == propertyId) {
                propertyPtr = property;
            }
        }
        for (auto user : m_allUsers) {
            if (user->getUserId() == buyerId) {
                Buyer* buyer = dynamic_cast<Buyer*>(user);
                if (buyer && propertyPtr) {
                    buyer->addOwnedProperty(propertyPtr);
                }
            }
        }
    }
}
void RealEstateController::reassignRequestsToAgentAndBuyer() {
    for (auto request : m_allRequests) {
        string buyerId = request->getBuyerId();
        string agentId = request->getAgentId();
        for (auto user : m_allUsers) {
            if (user->getUserId() == buyerId && user->getUserType() == USERTYPETHREE) {
                Buyer* buyer = dynamic_cast<Buyer*>(user);
                if (buyer) {
                    buyer->addRequest(request);
                }
            }
            if (user->getUserId() == agentId && user->getUserType() == USERTYPETWO) {
                Agent* agent = dynamic_cast<Agent*>(user);
                if (agent) {
                    agent->addRequest(request);
                }
            }
        }
    }
}
void RealEstateController::reassignPaymentsToAgentAndBuyer() {
    for (auto payment : m_allPayments) {
        string buyerId = payment->getBuyerId();
        string agentId = payment->getAgentId();
        for (auto user : m_allUsers) {
            if (user->getUserId() == buyerId && user->getUserType() == USERTYPETHREE) {
                Buyer* buyer = dynamic_cast<Buyer*>(user);
                if (buyer)
                {
                    buyer->addPayment(payment);
                }
            }
            if (user->getUserId() == agentId && user->getUserType() == USERTYPETWO) {
                Agent* agent = dynamic_cast<Agent*>(user);
                if (agent) {
                    agent->addPayment(payment);
                }
            }
        }
    }
}
void RealEstateController::reassignAgreementsToAgentAndBuyer() {
    for (auto agreement : m_allAgreements) {
        string buyerId = agreement->getBuyerId();
        string agentId = agreement->getAgentId();
        for (auto user : m_allUsers) {
            if (user->getUserId() == buyerId && user->getUserType() == USERTYPETHREE) {
                Buyer* buyer = dynamic_cast<Buyer*>(user);
                if (buyer) {
                    buyer->addAgreement(agreement);
                }
            }
            if (user->getUserId() == agentId && user->getUserType() == USERTYPETWO) {
                Agent* agent = dynamic_cast<Agent*>(user);
                if (agent) {
                    agent->addAgreement(agreement);
                }
            }
        }
    }
}
void RealEstateController::run() {
    bool flag = true;
    int choice, decision = 1;
    cout << "---- REAL ESTATE MANAGEMENT SYSTEM ----" << endl << endl;
    while (decision == 1) {
        cout << "<--------- Login / Register --------->" << endl << endl;
        cout << "1. Login\n2. Register\nEnter Choice: ";
        choice = menuChoiceValidation();
        switch (choice) {
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
        decision = menuChoiceValidation();
        if (decision != 0 && decision != 1) {
            cout << "enter a valid choice (1 - Yes / 0 - No)!" << endl;
            decision = 1;
        }
        if (decision == 0) {
            cout << "<---------------- Exited --------------->" << endl;
        }
    }
}
void RealEstateController::registerUser() {
    int choice;
    cout << endl << "1. Register as Buyer\n2. Register as Agent\n3. Register as Admin\nEnter Your Choice: ";
    choice = menuChoiceValidation();
    switch (choice) {
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
string RealEstateController::generateNextId(string prefix, int currentSize) {
    int nextNumber = currentSize + 1;
    string id;
    if (nextNumber < 10) {
        id = prefix + "0" + to_string(nextNumber);
    }
    else {
        id = prefix + to_string(nextNumber);
    }
    return id;
}
string RealEstateController::generateUserId() {
    return generateNextId("U", m_allUsers.size());
}
string RealEstateController::generateRequestId() {
    return generateNextId("R", m_allRequests.size());
}
string RealEstateController::generatePropertyId() {
    return generateNextId("PR", m_allProperties.size());
}
string RealEstateController::generatePaymentId() {
    return generateNextId("P", m_allPayments.size());
}
string RealEstateController::generateAgreementId() {
    return generateNextId("A", m_allAgreements.size());
}
void RealEstateController::registerAsBuyer() {
    string userId, userName, password;
    userId = generateUserId();
    cout << "\nAllocated UserId: " << userId << endl;
    cout << "Enter user name: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;
    m_allUsers.push_back(new Buyer(userId, userId, userName, password, USERTYPETHREE, UserStatus::ACTIVE));
    cout << "---- Registration Successful ----" << endl << "---- Please Login Again ----\n" << endl;
}
void RealEstateController::registerAsAgent() {
    string userId, userName, password;
    userId = generateUserId();
    cout << "\nAllocated UserId: " << userId << endl;
    cout << "Enter user name: ";
    cin >> userName;
    cout << "Enter Password: ";
    cin >> password;
    m_allUsers.push_back(new Agent(userId, userId, userName, password, USERTYPETWO, UserStatus::ACTIVE));
    cout << "---- Registration Successful ----" << endl << "---- Please Login Again ----\n" << endl;
}
void RealEstateController::registerAsAdmin() {
    string userId, userName, password, inputKey;
    cout << "Enter the Security Key: ";
    cin >> inputKey;
    if (inputKey == ADDADMINSECURITYKEY) {
        cout << endl << "---- Security check success ----" << endl;
        userId = generateUserId();
        cout << "\nAllocated UserId: " << userId << endl;
        cout << "Enter user name: ";
        cin >> userName;
        cout << "Enter Password: ";
        cin >> password;
        m_allUsers.push_back(new Admin(userId, userId, userName, password, USERTYPEONE, UserStatus::ACTIVE));
        cout << "---- Registration Successful ----" << endl << "---- Please Login Again ----\n" << endl;
    }
    else {
        cout << "----- Security Check Failed! ------" << endl;
    }
}
void RealEstateController::changeUserName(User* user) {
    string userName;
    cout << "Enter new user name: ";
    cin >> userName;
    user->setUserName(userName);
    cout << "\n----- User Name Changed Successfully -----\n\n" << endl;
}
void RealEstateController::changePassword(User* user) {
    string password;
    cout << "Enter new password: ";
    cin >> password;
    user->setPassword(password);
    cout << "\n----- Password Changed Successfully -----\n\n" << endl;
}
void RealEstateController::displayAllUsers() {
    cout << endl << "<--------- All Users --------->" << endl;
    for (auto user : m_allUsers) {
        if (user->getStatus() == UserStatus::ACTIVE) {
            cout << "ID: " << user->getUserId() << endl;
            cout << "User Name: " << user->getUserName() << endl;
            cout << "User Type: " << user->getUserType() << endl;
            cout << "Status: " << convertingUserStatusToString(user->getStatus()) << endl << endl;
        }
    }
}
void RealEstateController::login() {
    string userId, password;
    cout << "\nEnter User ID: ";
    cin >> userId;
    cout << "Enter password: ";
    cin >> password;
    User* currentUser = authenticateUser(userId, password);
    if (currentUser) {
        cout << "\n------- login successful -------" << endl << endl;
        userSession(currentUser);
    }
    else {
        cout << "Incorrect credentials or User does not exist!" << endl;
    }
}
User* RealEstateController::authenticateUser(const string& userId, const string& password) {
    bool found = false;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); ++iterator) {
        if ((*iterator)->getUserId() == userId && (*iterator)->getPassword() == password) {
            found = true;
            return *iterator;
        }
    }
    if (!found) {
        return nullptr;
    }
}
void RealEstateController::userSession(User* currentUser) {
    int choice;
    int decision = 1;
    while (decision == 1) {
        currentUser->displayMenu();
        choice = menuChoiceValidation();
        chooseOption(currentUser, choice);
        cout << "Do you want to continue (1 - Yes / 0 - No): ";
        cin >> decision;
        if (!cin) {
            cout << "enter a valid option!" << endl << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            decision = 1;
        }
        if (decision == 0) {
            cout << "<---- Logging Out ---->" << endl;
            return;
        }
        if (decision != 1) {
            cout << "enter a valid option!" << endl << endl;
            decision = 1;
        }
    }
}
void RealEstateController::chooseOption(User* user, int& choice) {
    string type = user->getUserType();
    if (type == USERTYPEONE) {
        callAdminMenu(user, choice);
    }
    else if (type == USERTYPETWO) {
        callAgentMenu(user, choice);
    }
    else if (type == USERTYPETHREE) {
        callBuyerMenu(user, choice);
    }
}
void RealEstateController::callAdminMenu(User* user, int& choice) {
    handleAdminUserManagement(user, choice);
    handleAdminPropertyManagement(user, choice);
    handleAdminReports(choice);
    handleAdminAccountSettings(user, choice);
    if (choice < 1 || choice > 15) {
        cout << "Enter a valid option!" << endl;
    }
}
void RealEstateController::handleAdminUserManagement(User* user, int choice) {
    switch (choice) {
    case 1: 
        registerAsAdmin(); 
        break;
    case 2: 
        removeAdmin(user); 
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
void RealEstateController::handleAdminPropertyManagement(User* user, int choice) {
    switch (choice) {
    case 7: 
        addProperty(user); 
        break;
    case 8: 
        viewAllProperty(); 
        break;
    case 9: 
        searchPropertiesByAgentName(); 
        break;
    }
}
void RealEstateController::handleAdminReports(int choice) {
    switch (choice) {
    case 10: 
        displayAllUsers(); 
        break;
    case 11: 
        displaySystemSummary(); 
        break;
    case 12: 
        displayAllPayments(); 
        break;
    case 13: 
        displayAllAgreements(); 
        break;
    }
}
void RealEstateController::handleAdminAccountSettings(User* user, int choice) {
    switch (choice) {
    case 14: 
        changeUserName(user); 
        break;
    case 15: 
        changePassword(user); 
        break;
    }
}
void RealEstateController::callAgentMenu(User* user, int& choice) {
    handleAgentPropertyManagement(user, choice);
    handleAgentRequestManagement(user, choice);
    handleAgentPaymentManagement(user, choice);
    handleAgentAccountSettings(user, choice);
    if (choice < 1 || choice > 13) {
        cout << "Enter a valid option!" << endl;
    }
}
void RealEstateController::handleAgentPropertyManagement(User* user, int choice) {
    switch (choice) {
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
void RealEstateController::handleAgentRequestManagement(User* user, int choice) {
    switch (choice) {
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
void RealEstateController::handleAgentPaymentManagement(User* user, int choice) {
    switch (choice) {
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
void RealEstateController::handleAgentAccountSettings(User* user, int choice) {
    switch (choice) {
    case 11: 
        changeUserName(user); 
        break;
    case 12: 
        changePassword(user); 
        break;
    case 13:
        viewRequestHistory(user);
        break;
    }
}
void RealEstateController::callBuyerMenu(User* user, int& choice) {
    handleBuyerPropertySearch(choice);
    handleBuyerRequests(user, choice);
    handleBuyerPayments(user, choice);
    handleBuyerAccountSettings(user, choice);
    if (choice < 1 || choice > 15) {
        cout << "Enter a valid option!" << endl;
    }
}
void RealEstateController::handleBuyerPropertySearch(int choice) {
    switch (choice) {
    case 1: 
        showAvailableProperties(); 
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
void RealEstateController::handleBuyerRequests(User* user, int choice) {
    switch (choice) {
    case 5: 
        requestToBuy(user); 
        break;
    case 6: 
        viewRequests(user); 
        break;
    case 11: 
        cancelBuyerRequest(user); 
        break;
    }
}
void RealEstateController::handleBuyerPayments(User* user, int choice) {
    switch (choice) {
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
void RealEstateController::handleBuyerAccountSettings(User* user, int choice) {
    switch (choice) {
    case 12: 
        changeUserName(user); 
        break;
    case 13: 
        changePassword(user); 
        break;
    case 14:
        viewRequestHistory(user);
        break;
    case 15:
        searchPropertiesByAgentName();
        break;
    }
}
void RealEstateController::removeAdmin(User* user) {
    string userId;
    bool found = false;
    if (!securityKeyCheck()) {
        return;
    }
    cout << "Enter Admin Id: ";
    cin >> userId;
    if (userId == user->getUserId()) {
        cout << "Cannot delete your own account!" << endl;
        return;
    }
    if (!isSetUserStatusToInactive(userId)) {
        cout << "Admin with this ID not found!" << endl;
    }
}
bool RealEstateController::securityKeyCheck() {
    string inputKey;
    cout << "Enter security key: ";
    cin >> inputKey;
    if (inputKey == REMOVEADMINSECURITYKEY) {
        cout << "Security check success." << endl << endl;
        return true;
    }
    else {
        cout << "security check failed." << endl << endl;
        return false;
    }
}
bool RealEstateController::isSetUserStatusToInactive(string userId) {
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); iterator++) {
        if ((*iterator)->getUserId() == userId && (*iterator)->getUserType() == USERTYPEONE) {
            (*iterator)->setStatus(UserStatus::INACTIVE);
            cout << "Admin " << userId << " removed" << endl;
            return true;
        }
    }
    return false;
}
void RealEstateController::removeBuyer() {
    string userId;
    bool found = false;
    cout << "Enter Buyer Id: ";
    cin >> userId;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); iterator++) {
        if ((*iterator)->getUserId() == userId && (*iterator)->getUserType() == USERTYPETHREE) {
            found = true;
            (*iterator)->setStatus(UserStatus::INACTIVE);
            cout << "Buyer " << userId << " removed" << endl;
            return;
        }
    }
    if (!found) {
        cout << "Buyer not found!" << endl;
    }
}
void RealEstateController::removeAgent() {
    string userId;
    bool found = false;
    cout << "Enter Agent Id: ";
    cin >> userId;
    for (auto iterator = m_allUsers.begin(); iterator != m_allUsers.end(); iterator++) {
        if ((*iterator)->getUserId() == userId && (*iterator)->getUserType() == USERTYPETWO) {
            found = true;
            (*iterator)->setStatus(UserStatus::INACTIVE);
            cout << "Agent " << userId << " removed" << endl;
            return;
        }
    }
    if (!found) {
        cout << "Agent not found!" << endl;
    }
}
void RealEstateController::addProperty(User* user) {
    string propertyId, agentId;
    int choice;
    double price;
    propertyId = generatePropertyId();
    cout << "Alocated Property ID: " << propertyId << endl;
    cout << "<---- Category ---->\n1. Showroom\n2. Villa\n3. Flat\n4. Plot\n5. Warehouse\nEnter Your choice: ";
    choice = menuChoiceValidation();
    CategoryType category = ChoiceToCategoryType(choice);
    cout << "Price: ";
    cin >> price;
    if (!isValidPositivePrice(price)) {
        cout << "Invalid price!" << endl;
        return;
    }
    if (user->getUserType() == USERTYPETWO) {
        agentId = user->getUserId();
    }
    else {
        cout << "Agent Id: ";
        cin >> agentId;
        if (!isAgentIdValid(agentId)) {
            cout << agentId << " is not an agent!" << endl;
            return;
        }
    }
    createAndStoreProperty(agentId, propertyId, category, price);
}
void RealEstateController::createAndStoreProperty(string agentId, string propertyId, CategoryType category, double price) {
    string propertyName, location;
    Agent* agent = findAgentById(agentId);
    if (agent == nullptr) {
        cout << "No Agent with Id: " << agentId << " exists" << endl;
        return;
    }
    cout << "Property Name: ";
    cin.ignore();
    getline(cin, propertyName);
    cout << "Location: ";
    cin >> location;
    Property* property = new Property(propertyId, propertyName, category, price, agentId, location, PropertyStatus::AVAILABLE);
    m_allProperties.push_back(property);
    agent->addProperty(property);
    cout << "\n------ Property Added Successfully ------\n" << endl;
}
void RealEstateController::deleteProperty(User* user) {
    string propertyId, userId;
    bool found = false;
    userId = user->getUserId();
    viewAddedProperties(user);
    cout << endl << "Enter property Id: ";
    cin >> propertyId;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++) {
        if ((*iterator)->getPropertyId() == propertyId && (*iterator)->getAgentId() == userId) {
            found = true;
            if ((*iterator)->getStatus() == PropertyStatus::UNAVAILABLE) {
                cout << "Property already deleted." << endl;
                return;
            }
            if ((*iterator)->getStatus() == PropertyStatus::SOLD) {
                cout << "Property has been sold." << endl;
                return;
            }
            if ((*iterator)->getStatus() == PropertyStatus::AVAILABLE) {
                cout << "Property " << propertyId << " deleted." << endl;
                (*iterator)->setStatus(PropertyStatus::UNAVAILABLE);
                return;
            }
        }
    }
    if (!found) {
        cout << "Property with Id : " << propertyId << " not found" << endl;
    }
}
void RealEstateController::viewAllProperty() {
    if (m_allProperties.empty()) {
        cout << "No Properties registered in the System" << endl;
        return;
    }
    cout << "------ All Properties ------" << endl << endl;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++) {
        if ((*iterator)->getStatus() == PropertyStatus::AVAILABLE) {
            displayPropertyDetails((*iterator));
            cout << "Added By: " << (*iterator)->getAgentId() << endl << endl;
        }
    }
}
void RealEstateController::viewAddedProperties(User* user) {
    bool found = false;
    cout << "--------- Properties Added By " << user->getUserId() << " ----------" << endl;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++) {
        if ((*iterator)->getAgentId() == user->getUserId() && (*iterator)->getStatus() != PropertyStatus::UNAVAILABLE) {
            found = true;
            displayPropertyDetails((*iterator));
        }
    }
    if (!found) {
        cout << "No Properties Added By " << user->getUserId() << endl;
    }
}
void RealEstateController::viewOwnedProperty(User* user) {
    Buyer* buyer = dynamic_cast<Buyer*>(user);
    vector<Property*>& properties = buyer->getOwnedProperties();
    cout << "\n<------ OWNED PROPERTIES ------>\n";
    if (properties.empty()) {
        cout << "No owned properties.\n";
        return;
    }
    for (auto property : properties) {
        displayPropertyDetails(property);
    }
}
void RealEstateController::showAvailableProperties() {
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++) {
        if ((*iterator)->getStatus() == PropertyStatus::AVAILABLE) {
            displayPropertyDetails((*iterator));
            cout << "Agent ID: " << (*iterator)->getAgentId() << endl;
        }
    }
}
void RealEstateController::searchByCategory() {
    int choice;
    bool found = false;
    cout << "<---- Select Categroy ---->\n1. Showroom\n2. Villa\n3. Flat\n4. Plot\n5. Warehouse\nEnter Your choice: ";
    choice = menuChoiceValidation();
    CategoryType category = ChoiceToCategoryType(choice);
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++) {
        if ((*iterator)->getCategory() == category && (*iterator)->getStatus() != PropertyStatus::UNAVAILABLE) {
            found = true;
            displayPropertyDetails((*iterator));
            cout << "Agent ID: " << (*iterator)->getAgentId() << endl << endl;
        }
    }
    if (!found) {
        cout << "No property registered in this category." << endl;
    }
}
void RealEstateController::searchByPrice() {
    double price;
    cout << "Enter price: ";
    cin >> price;
    for (auto iterator = m_allProperties.begin(); iterator != m_allProperties.end(); iterator++) {
        if ((*iterator)->getPrice() <= price && (*iterator)->getStatus() != PropertyStatus::UNAVAILABLE) {
            displayPropertyDetails((*iterator));
            cout << "Agent ID: " << (*iterator)->getAgentId() << endl << endl;
        }
    }
}
void RealEstateController::searchPropertiesByAgentName() {
    string agentName;
    cout << "Enter Agent Name: ";
    cin >> agentName;
    bool found = false;
    cout << "<------ Properties Under Agent : " << agentName << " ------>" << endl << endl;
    for (auto property : m_allProperties) {
        if (findUserNameById(property->getAgentId()) == agentName) {
            found = true;
            displayPropertyDetails((property));
        }
    }
    if (!found) {
        cout << "No Properties Added by Agent : " << agentName << endl << endl;
    }
}
void RealEstateController::displayPropertyDetails(Property* property) {
    cout << endl << "Property ID: " << property->getPropertyId() << endl;
    cout << "Property Name: " << property->getPropertyName() << endl;
    cout << "Price: " << property->getPrice() << endl;
    cout << "Category: " << convertingCategoryTypeToString(property->getCategory()) << endl;
    cout << "Status: " << convertingPropertyStatusToString(property->getStatus()) << endl;
    cout << "Location: " << property->getLocation() << endl;
}
void RealEstateController::displayBuyerPaymentHistory(User* user) {
    Buyer* buyer = dynamic_cast<Buyer*>(user);
    vector<Payment*>& payments = buyer->getPayments();
    cout << "<---------- Payment History ---------->" << endl;
    if (payments.empty()) {
        cout << "No payments found.\n";
        return;
    }
    for (auto payment : payments) {
        displayPaymentDetails(payment);
    }
}
void RealEstateController::displayPaymentDetails(Payment* payment) {
    cout << "Payment ID: " << payment->getPaymentId() << endl;
    cout << "Property Sold: " << payment->getPropertyId() << endl;
    cout << "Amount: " << payment->getAmount() << endl;
    cout << "Status: " << convertingPaymentStatusToString(payment->getStatus()) << endl;
    cout << "Done to: " << payment->getAgentId() << endl << endl;
}
void RealEstateController::requestToBuy(User* user) {
    showAvailableProperties();
    string propertyId;
    cout << "Enter Property ID: ";
    cin >> propertyId;
    Property* property = validatePropertySelection(propertyId);
    if (!property) {
        cout << "Property Not available" << endl;
        return;
    }
    if (isDuplicateRequest(user, propertyId)) {
        return;
    }
    createRequest(user, property);
}
Property* RealEstateController::validatePropertySelection(string& propertyIdentifier) {
    bool found = false;
    for (auto propertyPointer : m_allProperties) {
        if (propertyPointer->getPropertyId() == propertyIdentifier) {
            if (propertyPointer->getStatus() == PropertyStatus::AVAILABLE) {
                found = true;
                return propertyPointer;
            }
            else if (propertyPointer->getStatus() == PropertyStatus::SOLD) {
                cout << "Property already sold." << endl;
                return nullptr;
            }
            else if (propertyPointer->getStatus() == PropertyStatus::UNAVAILABLE) {
                cout << "Property is unavailable." << endl;
                return nullptr;
            }
        }
    }
    if (!found) {
        return nullptr;
    }
}
bool RealEstateController::isDuplicateRequest(User* user, string propertyId) {
    for (auto req : m_allRequests) {
        if (req->getPropertyId() == propertyId && req->getBuyerId() == user->getUserId()) {
            cout << "Already requested!" << endl;
            return true;
        }
    } 
    return false;
}
void RealEstateController::createRequest(User* user, Property* property) {
    string id = generateRequestId();
    Request* request = new Request(id,property->getPropertyId(),user->getUserId(),property->getAgentId(),RequestStatus::PENDING);
    m_allRequests.push_back(request);
    findBuyerById(user->getUserId())->addRequest(request);
    findAgentById(property->getAgentId())->addRequest(request);
    cout << "Request created successfully!" << endl;
}
void RealEstateController::viewRequests(User* user) {
    if (user->getUserType() == USERTYPETHREE) {
        cout << "<----- Requests initiated by " << user->getUserId() << " ----->" << endl;
        Buyer* buyer = dynamic_cast<Buyer*>(user);
        vector<Request*>& requests = buyer->getRequests();
        if (requests.empty()) {
            cout << "No requests found.\n";
            return;
        }
        for (auto iterator = requests.begin(); iterator != requests.end(); iterator++) {
            if ((*iterator)->getStatus() == RequestStatus::PENDING || (*iterator)->getStatus() == RequestStatus::APPROVED) {
                printRequestDetails(*iterator);
            }
        }
    }
    else if (user->getUserType() == USERTYPETWO) {
        cout << "<----- Requests received by " << user->getUserId() << " ----->" << endl;
        Agent* agent = dynamic_cast<Agent*>(user);
        vector<Request*>& requests = agent->getRequests();
        if (requests.empty()) {
            cout << "No requests found.\n";
            return;
        }
        for (auto iterator = requests.begin(); iterator != requests.end(); iterator++) {
            if ((*iterator)->getStatus() == RequestStatus::PENDING) {
                printRequestDetails(*iterator);
            }
        }
    }
}
void RealEstateController::viewRequestHistory(User* user) {
    if (user->getUserType() == USERTYPETHREE) {
        viewRequestsOfBuyer(user);
    }
    else if (user->getUserType() == USERTYPETWO) {
        viewRequestsOfAgent(user);
    }
}
void RealEstateController::viewRequestsOfBuyer(User* user) {
    cout << "<----- Requests History Of " << user->getUserId() << " ----->" << endl;
    Buyer* buyer = dynamic_cast<Buyer*>(user);
    vector<Request*>& requests = buyer->getRequests();
    if (requests.empty()) {
        cout << "No requests found.\n";
        return;
    }
    for (auto iterator = requests.begin(); iterator != requests.end(); iterator++) {
        printRequestDetails(*iterator);
    }
}
void RealEstateController::viewRequestsOfAgent(User* user) {
    cout << "<----- Requests History Of " << user->getUserId() << " ----->" << endl;
    Agent* agent = dynamic_cast<Agent*>(user);
    vector<Request*>& requests = agent->getRequests();
    if (requests.empty()) {
        cout << "No requests found.\n";
        return;
    }
    for (auto iterator = requests.begin(); iterator != requests.end(); iterator++) {
        if ((*iterator)->getStatus() != RequestStatus::CANCELLED) {
            printRequestDetails(*iterator);
        }
    }
}
void RealEstateController::printRequestDetails(Request* request)  { 
    cout << "Request ID: " << request->getRequestId() << endl;
    cout << "Property ID: " << request->getPropertyId() << endl; 
    cout << "Buyer ID: " << request->getBuyerId() << endl; 
    cout << "Agent ID: " << request->getAgentId() << endl; 
    cout << "Status: " << convertingRequestStatusToString(request->getStatus()) << endl << endl; 
}

void RealEstateController::approveRequest(User* user) {
    viewRequests(user);
    cout << "Enter request ID: ";
    string id;
    cin >> id;
    Request* request = findRequestById(id);
    if (!request || !isRequestProcessable(request)) {
        return;
    }
    approveAndRejectOthers(request, user->getUserId());
}
void RealEstateController::approveAndRejectOthers(Request* approved, string agentId) {
    approved->setStatus(RequestStatus::APPROVED);
    for (auto request : m_allRequests) {
        if (request->getPropertyId() == approved->getPropertyId() && request->getBuyerId() != approved->getBuyerId()) {
            request->setStatus(RequestStatus::REJECTED);
        }
    }
    cout << "Request approved successfully!" << endl;
}
void RealEstateController::rejectRequest(User* user) {
    string requestId;
    bool found = false;
    viewRequests(user);
    cout << "Enter request ID: ";
    cin >> requestId;
    string agentId = user->getUserId();
    for (auto iterator = m_allRequests.begin(); iterator != m_allRequests.end(); iterator++) {
        if ((*iterator)->getAgentId() == agentId && (*iterator)->getRequestId() == requestId) {
            found = true;
            if ((*iterator)->getStatus() == RequestStatus::REJECTED) {
                cout << "Request has already been rejected." << endl;
                return;
            }
            if ((*iterator)->getStatus() == RequestStatus::APPROVED) {
                cout << "Request has already been approved." << endl;
                return;
            }
            else {
                (*iterator)->setStatus(RequestStatus::REJECTED);
                cout << "Request has been rejected by Agent : " << agentId << endl;
                return;
            }  
        }
    }
    if (!found) {
        cout << "No request by ID : " << requestId << " exists" << endl;
    }
}
void RealEstateController::makePayment(User* user) {
    string requestId;
    viewApprovedRequests(user);
    cout << "Enter request Id: ";
    cin >> requestId;
    if (isPaymentAlreadyDone(requestId)) {
        return;
    }
    Request* request = findRequestById(requestId);
    if (!isRequestProcessable(request)) {
        return;
    }
    processPayment(user, request);
}
bool RealEstateController::isPaymentAlreadyDone(string requestId) {
    for (auto payment : m_allPayments) {
        if (payment->getRequestId() == requestId) {
            cout << "Payment already done!" << endl;
            return true;
        }
    } 
    return false;
}
void RealEstateController::processPayment(User* user, Request* request) {
    string paymentId = generatePaymentId();
    cout << "Allocated Payment ID: " << paymentId << endl;
    int choice;
    cout << "1.Full  2.Advance: ";
    choice = menuChoiceValidation();
    PaymentType type = choiceToPaymentType(choice);
    double amount = findPropertyById(request->getPropertyId())->getPrice();
    Payment* payment = new Payment(paymentId,request->getRequestId(),user->getUserId(),request->getAgentId(),amount, type,PaymentStatus::PENDING,request->getPropertyId());
    m_allPayments.push_back(payment);
    attachPaymentToUsers(payment);
}
void RealEstateController::attachPaymentToUsers(Payment* payment) {
    findBuyerById(payment->getBuyerId())->addPayment(payment);
    findAgentById(payment->getAgentId())->addPayment(payment);
    cout << "Payment done successfully!" << endl;
}
void RealEstateController::verifyPayment(User* user) {
    Agent* agent = dynamic_cast<Agent*>(user);
    displayPendingPayments(agent);
    cout << "Enter Payment ID to verify: ";
    string paymentId;
    cin >> paymentId;
    if (isPaymentAlreadyVerified(paymentId)) {
        cout << "Already verified!" << endl;
        return;
    }
    Payment* payment = findPaymentById(paymentId);
    if (!payment) {
        return;
    }
    completePaymentVerification(payment);
}
void RealEstateController::completePaymentVerification(Payment* payment) {
    payment->setStatus(PaymentStatus::VERIFIED);
    Property* property = findPropertyById(payment->getPropertyId());
    property->setStatus(PropertyStatus::SOLD);
    Buyer* buyer = findBuyerById(payment->getBuyerId());
    Agent* agent = findAgentById(payment->getAgentId());
    buyer->addOwnedProperty(property);
    generateAgreement(nullptr,payment->getPaymentId(),payment->getBuyerId(),payment->getAgentId(),payment->getPropertyId(),buyer, agent);
}
bool RealEstateController::isPaymentAlreadyVerified(string paymentId) {
    for (auto payment : m_allPayments) {
        if (payment->getPaymentId() == paymentId && payment->getStatus() == PaymentStatus::VERIFIED) {
            return true;
        }
    }
    return false;
}
void RealEstateController::generateAgreement(User* user, string paymentId, string buyerId, string agentId, string propertyId, Buyer* buyer, Agent* agent) {
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
void RealEstateController::displayAgreements(User* user) {
    string userId = user->getUserId();
    bool found = false;
    cout << "<---- Agreements ---->" << endl;
    if (user->getUserType() == USERTYPETHREE) {
        displayBuyerAgreements(user);
    }
    else if (user->getUserType() == USERTYPETWO) {
        displayAgentAgreements(user);
    }
}
void RealEstateController::displayBuyerAgreements(User* user) {
    Buyer* buyer = dynamic_cast<Buyer*>(user);
    vector<Agreement*>& agreements = buyer->getAgreements();
    if (agreements.empty()) {
        cout << "No agreements found.\n";
        return;
    }
    for (auto agreement : agreements) {
        displayAgreementDetails(agreement);
    }
}
void RealEstateController::displayAgentAgreements(User* user) {
    Agent* agent = dynamic_cast<Agent*>(user);
    vector<Agreement*>& agreements = agent->getAgreements();
    if (agreements.empty()) {
        cout << "No agreements found.\n";
        return;
    }
    for (auto agreement : agreements) {
        displayAgreementDetails(agreement);
    }
}
void RealEstateController::displayAgreementDetails(Agreement* agreement) {
    cout << "Agreement Id: " << agreement->getAgreementId() << endl;
    cout << "Payment Id: " << agreement->getRequestId() << endl;
    cout << "Buyer Id: " << agreement->getBuyerId() << endl;
    cout << "Agent Id: " << agreement->getAgentId() << endl;
    cout << "Property Id: " << agreement->getPropertyId() << endl;
    cout << "Terms : " << agreement->getTerms() << endl;
    cout << "Date : " << agreement->getDate() << endl << endl;
}
void RealEstateController::displayAllAgreements() {
    if (m_allAgreements.empty()) {
        cout << "No Agreements have been signed." << endl;
        return;
    }
    cout << "------- All Agreement Details -------" << endl;
    for (auto agreement : m_allAgreements) {
        displayAgreementDetails(agreement);
        cout << endl;
    }
}
void RealEstateController::displaySystemSummary() {
    cout << "Total Users: " << m_allUsers.size() << endl;
    cout << "Total Properties: " << m_allProperties.size() << endl;
    cout << "Total Requests: " << m_allRequests.size() << endl;
    cout << "Total Payments: " << m_allPayments.size() << endl;
    cout << "Total Agreements: " << m_allAgreements.size() << endl;
}
void RealEstateController::displayAllPayments() {
    if (m_allPayments.empty()) {
        cout << "No Payments has been done yet." << endl;
        return;
    }
    cout << "------- All Payment Details -------" << endl;
    for (auto payment : m_allPayments) {
        cout << "Payment ID: " << payment->getPaymentId() << endl;
        cout << "Property Id: " << payment->getPropertyId() << endl;
        cout << "Amount: " << payment->getAmount() << endl;
        cout << "Status: " << convertingPaymentStatusToString(payment->getStatus()) << endl;
        cout << "Done By: " << payment->getBuyerId() << endl;
        cout << "To : " << payment->getAgentId() << endl << endl;
    }
}
void RealEstateController::displayAgentPaymentHistory(User* user) {
    Agent* agent = dynamic_cast<Agent*>(user);
    vector<Payment*>& payments = agent->getPayments();
    cout << "\n<------ PAYMENTS RECEIVED ------>\n";
    if (payments.empty()) {
        cout << "No payments received.\n";
        return;
    }
    for (auto payment : payments) {
        cout << "Payment ID: " << payment->getPaymentId() << endl;
        cout << "Amount: " << payment->getAmount() << endl;
        cout << "Buyer ID: " << payment->getBuyerId() << endl;
        cout << "Received From: " << payment->getBuyerId() << endl;
        cout << "Status: " << convertingPaymentStatusToString(payment->getStatus()) << endl << endl;
    }
}
void RealEstateController::displaySoldProperties(User* user) {
    bool found = false;
    cout << "<------ Properties Sold By Agent : " << user->getUserId() << " ------>" << endl;
    for (auto property : m_allProperties) {
        if (property->getAgentId() == user->getUserId() && property->getStatus() == PropertyStatus::SOLD) {
            found = true;
            cout << "Property ID: " << property->getPropertyId() << endl;
            cout << "Price: " << property->getPrice() << endl << endl;
        }
    }
    if (!found) {
        cout << "No Properties have been sold by Agent : " << user->getUserId() << endl << endl;
    }
}
void RealEstateController::cancelBuyerRequest(User* user) {
    string requestId;
    bool found = false;
    cout << "<---- Requests ---->" << endl;
    viewRequests(user);
    cout << "Enter Request ID to cancel: ";
    cin >> requestId;
    for (auto request : m_allRequests) {
        if (handleRequestCancellation(request, requestId, user)) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Request ID : " << requestId << " not found" << endl;
    }
}
bool RealEstateController::handleRequestCancellation(Request* request,string requestId,User* user) {
    if (request->getRequestId() != requestId || request->getBuyerId() != user->getUserId()) {
        return false;
    }
    if (request->getStatus() == RequestStatus::PENDING) {
        request->setStatus(RequestStatus::CANCELLED);
        cout << "Request cancelled!" << endl;
        return true;
    }
    if (request->getStatus() == RequestStatus::APPROVED) {
        cout << "Request already approved!" << endl;
        return true;
    }
    return false;
}
void RealEstateController::viewApprovedRequests(User* user) {
    cout << "<------ Requests Approved ------>" << endl;
    bool found = false;
    for (auto request : m_allRequests) {
        if (request->getBuyerId() == user->getUserId() && request->getStatus() == RequestStatus::APPROVED) {
            found = true;
            printRequestDetails(request);
        }
    }
    if (!found) {
        cout << "------ No Request Found ------" << endl;
    }
}
User* RealEstateController::findUserById(string id) {
    for (auto user : m_allUsers) {
        if (user->getUserId() == id) {
            return user;
        }
    }
    return nullptr;
}
Property* RealEstateController::findPropertyById(string id) {
    for (auto property : m_allProperties) {
        if (property->getPropertyId() == id) {
            return property;
        }
    }
    return nullptr;
}
Request* RealEstateController::findRequestById(string id) {
    for (auto request : m_allRequests) {
        if (request->getRequestId() == id) {
            return request;
        }
    }
    return nullptr;
}
Payment* RealEstateController::findPaymentById(string id) {
    for (auto payment : m_allPayments) {
        if (payment->getPaymentId() == id) {
            return payment;
        }
    }
    return nullptr;
}
bool RealEstateController::isRequestProcessable(Request* request) {
    if (!request) {
        cout << "No request with ID: " << request->getRequestId() << " found." << endl;
        return false;
    }
    if (request->getStatus() == RequestStatus::REJECTED) {
        cout << "Request rejected!" << endl;
        return false;
    }
    return true;
}
void RealEstateController::displayPendingPayments(Agent* agent) {
    for (auto payment : agent->getPayments()) {
        if (payment->getStatus() == PaymentStatus::PENDING) {
            cout << "Payment Id: " << payment->getPaymentId() << endl;
            cout << "Property Id: " << payment->getPropertyId() << endl;
            cout << "Amount: " << payment->getAmount() << endl;
            cout << "Done By: " << payment->getBuyerId() << endl << endl;
        }
    }
}
Agent* RealEstateController::findAgentById(string agentId) {
    for (auto user : m_allUsers) {
        if (user->getUserId() == agentId && user->getUserType() == USERTYPETWO) {
            return dynamic_cast<Agent*>(user);
        }
    }
    return nullptr;
}
string RealEstateController::findUserNameById(string id) {
    for (auto user : m_allUsers) {
        if (user->getUserId() == id) {
            return user->getUserName();
        }
    }
    return "";
}
bool RealEstateController::isAgentIdValid(string agentId) {
    for (auto user : m_allUsers) {
        if (user->getUserId() == agentId && user->getUserType() != USERTYPETHREE) {
            return true;
        }
    }
    return false;
}
bool RealEstateController::isUserIdAlreadyExists(string userId) {
    for (auto user : m_allUsers) {
        if (user->getUserId() == userId) {
            return true;
        }
    }       
    return false;
}
bool RealEstateController::isPropertyIdAlreadyExists(string propertyId) {
    for (auto property : m_allProperties) {
        if (property->getPropertyId() == propertyId) {
            return true;
        }
    }       
    return false;
}
bool RealEstateController::isRequestIdAlreadyExists(string requestId) {
    for (auto request : m_allRequests) {
        if (request->getRequestId() == requestId) {
            return true;
        }
    }    
    return false;
}
bool RealEstateController::isPaymentIdAlreadyExists(string paymentId) {
    for (auto payment : m_allPayments) {
        if (payment->getPaymentId() == paymentId) {
            return true;
        }
    }       
    return false;
}
bool RealEstateController::isValidPositivePrice(double price) {
    return price > 0;
}
int RealEstateController::menuChoiceValidation() {
    int choice;
    while (true) {
        try {
            if (!(cin >> choice)) {
                throw runtime_error("Invalid input! Please enter a number.\n");
            }
            return choice;
        }
        catch (const exception& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\tError :" << e.what() << endl;
            cout << "Enter a valid input :";
        }
    }
}
Buyer* RealEstateController::findBuyerById(string buyerId) {
    for (auto user : m_allUsers) {
        if (user->getUserId() == buyerId && user->getUserType() == USERTYPETHREE) {
            return dynamic_cast<Buyer*>(user);
        }
    }
    return nullptr;
}
RealEstateController::~RealEstateController() {
    for (auto user : m_allUsers) {
        delete user;
    }
    for (auto property : m_allProperties) {
        delete property;
    }
    for (auto request : m_allRequests) {
        delete request;
    }
    for (auto payment : m_allPayments) {
        delete payment;
    }
    for (auto agreement : m_allAgreements) {
        delete agreement;
    }
}