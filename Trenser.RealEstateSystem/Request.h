#pragma once
#include <iostream>
using namespace std;

class Request
{
private:
    string m_requestId;
    string m_propertyId;
    string m_customerId;
    string m_agentId;
    string m_status;
public:
    Request() : m_requestId(""), m_propertyId(""), m_customerId(""), m_agentId(""), m_status("") {}
    Request(string requestId, string propertyId, string customerId, string agentId, string status) : m_requestId(requestId), m_propertyId(propertyId), m_customerId(customerId), m_agentId(agentId), m_status(status) {};
    string getRequestId(); 
    string getPropertyId(); 
    string getCustomerId(); 
    string getAgentId(); 
    string getStatus();  
    void setRequestId(string requestId); 
    void setPropertyId(string propertyId); 
    void setCustomerId(string customerId); 
    void setAgentId(string agentId); 
    void setStatus(string status);
};
