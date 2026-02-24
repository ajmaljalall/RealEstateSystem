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
    string m_BuyerId;
    string m_agentId;
    RequestStatus m_status;
public:
    Request() : m_requestId(""), m_propertyId(""), m_BuyerId(""), m_agentId(""), m_status(RequestStatus::PENDING) {}
    Request(string requestId, string propertyId, string buyerId, string agentId, RequestStatus status) : m_requestId(requestId), m_propertyId(propertyId), m_BuyerId(buyerId), m_agentId(agentId), m_status(status) {};
    string getRequestId(); 
    string getPropertyId(); 
    string getBuyerId();
    string getAgentId(); 
    RequestStatus getStatus();  
    void setStatus(RequestStatus status);
};
