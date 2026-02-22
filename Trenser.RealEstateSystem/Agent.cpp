#include "Agent.h"

string Agent::getAgentId()
{
	return m_agentId;
}
void Agent::addProperty(Property* property)
{
    m_properties.push_back(property);
}
void Agent::addRequest(Request* request)
{
    m_receivedRequests.push_back(request);
}
void Agent::addPayment(Payment* payment)
{
    m_receivedPayments.push_back(payment);
}
void Agent::addAgreement(Agreement* agreement)
{
    m_agreements.push_back(agreement);
}
vector<Property*>& Agent::getProperties()
{
    return m_properties;
}
vector<Request*>& Agent::getRequests()
{
    return m_receivedRequests;
}
vector<Payment*>& Agent::getPayments()
{
    return m_receivedPayments;
}
vector<Agreement*>& Agent::getAgreements()
{
    return m_agreements;
}
void Agent::displayMenu()
{
	cout << "------- Agent Menu -------" << endl;
    cout << "1. Add Property\n"
        << "2. Delete Property\n"
        << "3. View Requests\n"
        << "4. Approve Request\n"
        << "5. Reject Request\n"
        << "6. View My Properties\n"
        << "7. Verify Payment\n"
        << "8. Display Agreements\n"
        << "9. View Payment History\n"
        << "10. View Sold Properties\n"
        << "11. Change User Name\n"
        << "12. Change Password\n\n"
        << "Enter your choice : ";
}