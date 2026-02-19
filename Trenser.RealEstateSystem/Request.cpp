#include "Request.h"

string Request::getAgentId()
{
	return m_agentId;
}
string Request::getCustomerId()
{
	return m_customerId;
}
string Request::getPropertyId()
{
	return m_propertyId;
}
string Request::getRequestId()
{
	return m_requestId;
}
string Request::getStatus()
{
	return m_status;
}
void Request::setStatus(string status)
{
	m_status = status;
}