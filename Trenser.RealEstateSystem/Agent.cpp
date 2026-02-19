#include "Agent.h"

string Agent::getAgentId()
{
	return m_agentId;
}
vector<Property*> Agent::getProperties()
{
	return m_properties;
}
vector<Request*> Agent::getRequests()
{
	return m_requests;
}
void Agent::addProperty(Property* property)
{
	m_properties.push_back(property);
}
void Agent::setRequests(vector<Request*> requests)
{
	m_requests = requests;
}
void Agent::setProperty(vector<Property*> properties)
{
	m_properties = properties;
}
void Agent::deleteProperty()
{
}
void Agent::viewRequests()
{
}
void Agent::approveRequest()
{
}
void Agent::rejectRequest()
{
}
void Agent::viewUploadedProperties()
{
}
void Agent::displayMenu()
{
	cout << "------- Menu -------" << endl;
	cout << "1. Add Property\n2. Delete Property\n3. View Requests\n4. Approve Request\n5. Reject Request\n6. View My Properties\n7. Verify Payment\n8. Display Agreements\nEnter your choice : ";
}