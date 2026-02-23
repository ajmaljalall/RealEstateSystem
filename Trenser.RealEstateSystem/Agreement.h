//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------
#pragma once
#include <iostream>
using namespace::std;

class Agreement
{
private:
	string m_agreementId;
	string m_requestId;
	string m_buyerId;
	string m_agentId;
	string m_propertyId;
	string m_terms;
	string m_date;
public:
	Agreement() : m_agreementId(""), m_requestId(""), m_buyerId(""), m_agentId(""), m_propertyId(""), m_terms(""), m_date("") {};
	Agreement(string agreementId, string requestId, string buyerId, string agentId, string propertyId, string terms, string date) : m_agreementId(agreementId), m_requestId(requestId), m_buyerId(buyerId), m_agentId(agentId), m_propertyId(propertyId), m_terms(terms), m_date(date) {};
	string getAgreementId();
	string getRequestId();
	string getBuyerId();
	string getAgentId();
	string getPropertyId();
	string getTerms();
	string getDate();
};

