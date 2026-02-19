#include "Property.h"

string Property::getPropertyId()
{
	return m_propertyId;
}
string Property::getAgentId()
{
	return m_agentId;
}
string Property::getCategory()
{
	return m_category;
}
string Property::getStatus()
{
	return m_status;
}
double Property::getPrice()
{
	return m_price;
}
string Property::getLocation()
{
	return m_location;
}
void Property::setCategory(string category)
{
	m_category = category;
}
void Property::setLocation(string location)
{
	m_location = location;
}
void Property::setPrice(double price)
{
	m_price = price;
}
void Property::setStatus(string status)
{
	m_status = status;
}

