#include "Admin.h"

string Admin::getAdminId()
{
	return m_adminId;
}
vector<Property*> Admin::getProperties()
{
	return m_properties;
}
void Admin::addBuyer()
{

}
void Admin::removeBuyer()
{
}
void Admin::addAgent()
{
}
void Admin::removeAgent()
{
}
void Admin::addProperty(Property* property)
{
	m_properties.push_back(property);
}
void Admin::displayAllProperty()
{
}
void Admin::displayMyProperty()
{
}
void Admin::displayMenu()
{
	cout << "------- Menu -------" << endl;
	cout << "1. Add Admin\n2. Remove Buyer\n3. Add Buyer\n4. Remove Buyer\n5. Add Agent\n6. Remove Agent\n7. Add Plot\n8. View All Plots\n9. View Added Plots\nEnter Your Choice : ";
}