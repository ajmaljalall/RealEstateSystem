#include "User.h"

string User::getUserId()
{
	return m_userId;
}
string User::getUserName()
{
	return m_userName;
}
string User::getPassword()
{
	return m_password;
}
string User::getUserType()
{
	return m_userType;
}
void User::setUserName(string userName)
{
	m_userName = userName;
}
void User::setPassword(string password)
{
	m_password = password;
}
