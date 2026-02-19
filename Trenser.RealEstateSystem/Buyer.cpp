#include "Buyer.h"

string Buyer::getBuyerId()
{
	return m_buyerId;
}
vector<Request*> Buyer::getRequests()
{
	return m_requests;
}
vector<Property*> Buyer::getOwnedProperties()
{
	return m_ownedProperties;
}
void Buyer::setRequests(vector<Request*> requests)
{
	m_requests = requests;
}
void Buyer::setProperties(vector<Property*> properties)
{
	m_ownedProperties = properties;
}
void Buyer::searchAvailablePlots()
{
}
void Buyer::searchByCategory()
{
}
void Buyer::searchByPrice()
{
}
void Buyer::viewAllProperties()
{
}
void Buyer::requestToBuy()
{
}
void Buyer::viewMyRequests()
{
}
void Buyer::viewOwnedProperties()
{
}
void Buyer::displayMenu()
{
	cout << "------- Menu -------" << endl;
	cout << "1. Search Available Properties\n2. Search By Category\n3. Search By Price\n4. View All Properties\n5. Request To Buy\n6. View My Requests\n7. View Owned Properties\n8. Make Payment\n9. Display Agreements\nEnter your choice : ";
}
