#include "Admin.h"

string Admin::getAdminId()
{
	return m_adminId;
}
void Admin::displayMenu()
{
	cout << "------- Menu -------" << endl;
	cout << "1. Add Admin\n2. Remove Admin\n3. Add Buyer\n4. Remove Buyer\n5. Add Agent\n6. Remove Agent\n7. Add Plot\n8. View All Plots\n9. View Added Plots\nEnter Your Choice : ";
}