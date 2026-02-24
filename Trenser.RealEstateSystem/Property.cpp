#include "Property.h"

string Property::getPropertyId()
{
	return m_propertyId;
}
string Property::getPropertyName()
{
	return m_propertyName;
}
string Property::getAgentId()
{
	return m_agentId;
}
CategoryType Property::getCategory()
{
	return m_category;
}
PropertyStatus Property::getStatus()
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
void Property::setCategory(CategoryType category)
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
void Property::setStatus(PropertyStatus status)
{
	m_status = status;
}

void Property::setPropertyName(string name)
{
	m_propertyName = name;
}

