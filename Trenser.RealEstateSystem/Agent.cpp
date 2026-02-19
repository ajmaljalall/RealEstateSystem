#include "Agent.h"

string Agent::getAgentId()
{
	return m_agentId;
}
void Agent::displayMenu()
{
	cout << "------- Menu -------" << endl;
	cout << "1. Add Property\n2. Delete Property\n3. View Requests\n4. Approve Request\n5. Reject Request\n6. View My Properties\n7. Verify Payment\n8. Display Agreements\nEnter your choice : ";
}