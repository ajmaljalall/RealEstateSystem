//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------
#pragma once
#include <iostream>
using namespace std;
#include "Status.h"

class Request
{
private:
    string m_requestId;
    string m_propertyId;
    string m_customerId;
    string m_agentId;
    RequestStatus m_status;
public:
    Request() : m_requestId(""), m_propertyId(""), m_customerId(""), m_agentId(""), m_status(RequestStatus::PENDING) {}
    Request(string requestId, string propertyId, string customerId, string agentId, RequestStatus status) : m_requestId(requestId), m_propertyId(propertyId), m_customerId(customerId), m_agentId(agentId), m_status(status) {};
    string getRequestId(); 
    string getPropertyId(); 
    string getCustomerId(); 
    string getAgentId(); 
    RequestStatus getStatus();  
    void setStatus(RequestStatus status);
};
