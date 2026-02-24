#include "Payment.h"

string Payment::getPaymentId()
{
	return m_paymentId;
}
string Payment::getAgentId()
{
	return m_agentId;
}
string Payment::getBuyerId()
{
	return m_buyerId;
}
string Payment::getRequestId()
{
	return m_requestId;
}
PaymentStatus Payment::getStatus()
{
	return m_status;
}
string Payment::getPropertyId()
{
	return m_propertyId;
}
void Payment::setAmount(double amount)
{
	m_amount = amount;
}
void Payment::setType(PaymentType type)
{
	m_type = type;
}
void Payment::setStatus(PaymentStatus status)
{
	m_status = status;
}
PaymentType Payment::getType()
{
	return m_type;
}
double Payment::getAmount()
{
	return m_amount;
}
