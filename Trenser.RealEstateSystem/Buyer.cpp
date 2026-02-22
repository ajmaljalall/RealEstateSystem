#include "Buyer.h"

string Buyer::getBuyerId()
{
	return m_buyerId;
}
void Buyer::addRequest(Request* request)
{
    m_requests.push_back(request);
}
void Buyer::addPayment(Payment* payment)
{
    m_payments.push_back(payment);
}
void Buyer::addAgreement(Agreement* agreement)
{
    m_agreements.push_back(agreement);
}
void Buyer::addOwnedProperty(Property* property)
{
    m_ownedProperties.push_back(property);
}
vector<Request*>& Buyer::getRequests()
{
    return m_requests;
}
vector<Payment*>& Buyer::getPayments()
{
    return m_payments;
}
vector<Agreement*>& Buyer::getAgreements()
{
    return m_agreements;
}
vector<Property*>& Buyer::getOwnedProperties()
{
    return m_ownedProperties;
}
void Buyer::displayMenu()
{
	cout << "------- Buyer Menu -------" << endl;
    cout << "1. Search Available Properties\n"
        << "2. Search By Category\n"
        << "3. Search By Price Range\n"
        << "4. View All Properties\n"
        << "5. Request To Buy\n"
        << "6. View My Requests\n"
        << "7. View Owned Properties\n"
        << "8. Make Payment\n"
        << "9. Display Agreements\n"
        << "10. Display Buyer Payment History\n"
        << "11. Cancel Request\n"
        << "12. View Approved Requests\n"
        << "13. View Rejected Requests\n"
        << "14. Change User Name\n"
        << "15. Change Password\n\n"
        << "Enter your choice : ";
}
