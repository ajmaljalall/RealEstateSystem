#include "Buyer.h"

string Buyer::getBuyerId()
{
	return m_buyerId;
}
void Buyer::displayMenu()
{
	cout << "------- Menu -------" << endl;
	cout << "1. Search Available Properties\n2. Search By Category\n3. Search By Price\n4. View All Properties\n5. Request To Buy\n6. View My Requests\n7. View Owned Properties\n8. Make Payment\n9. Display Agreements\n10. Display Buyer Payment History\n\nEnter your choice : ";
}
