#include "Admin.h"

string Admin::getAdminId()
{
	return m_adminId;
}
void Admin::displayMenu()
{
	cout << "------- Admin Menu -------" << endl;
    cout << "1. Add Admin\n"
        << "2. Remove Admin\n"
        << "3. Add Buyer\n"
        << "4. Remove Buyer\n"
        << "5. Add Agent\n"
        << "6. Remove Agent\n"
        << "7. Add Property\n"
        << "8. View All Property\n"
        << "9. View Added Property\n"
        << "10. Search Properties By Agent Id\n"
        << "11. Display All Users\n"
        << "12. View System Summary\n"
        << "13. View All Payments\n"
        << "14. View All Agreements\n"
        << "15. Change User Name\n"
        << "16. Change Password\n\n"
        << "Enter Your Choice : ";
}