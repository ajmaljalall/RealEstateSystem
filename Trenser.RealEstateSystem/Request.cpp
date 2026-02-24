#include "Request.h"

string Request::getAgentId()
{
	return m_agentId;
}
string Request::getBuyerId()
{
	return m_BuyerId;
}
string Request::getPropertyId()
{
	return m_propertyId;
}
string Request::getRequestId()
{
	return m_requestId;
}
RequestStatus Request::getStatus()
{
	return m_status;
}
void Request::setStatus(RequestStatus status)
{
	m_status = status;
}