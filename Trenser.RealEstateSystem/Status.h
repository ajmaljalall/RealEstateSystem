#pragma once
#pragma once
#include <string>
using namespace std;

static const string USERTYPEONE = "Admin";
static const string USERTYPETWO = "Agent";
static const string USERTYPETHREE = "Buyer";
static const string ADDADMINSECURITYKEY = "T20200";
static const string REMOVEADMINSECURITYKEY = "T10100";

enum class UserStatus
{
    ACTIVE,
    INACTIVE
};
enum class RequestStatus
{
    PENDING,
    APPROVED,
    REJECTED,
    CANCELLED
};
enum class PaymentStatus
{
    PENDING,
    VERIFIED
};
enum class PropertyStatus
{
    AVAILABLE,
    UNAVAILABLE,
    SOLD
};
enum class CategoryType
{
    VILLA,
    FLAT,
    PLOT,
    WAREHOUSE,
    SHOWROOM
};
enum class PaymentType
{
    FULL,
    ADVANCE
};
inline string convertingUserStatusToString(UserStatus status)
{
    switch (status)
    {
    case UserStatus::ACTIVE:   
        return "Active";
    case UserStatus::INACTIVE: 
        return "Inactive";
    default:
        return "";
    }
}
inline UserStatus stringToUserStatus(const string& inputString)
{
    if (inputString == "Active")
    {
        return UserStatus::ACTIVE;
    }
    if (inputString == "Inactive")
    {
        return UserStatus::INACTIVE;
    }
    else
    {
        return UserStatus::ACTIVE; 
    }
}
inline string convertingRequestStatusToString(RequestStatus status)
{
    switch (status)
    {
    case RequestStatus::PENDING:
    {
        return "Pending";
    }
    case RequestStatus::APPROVED:
    {
        return "Approved";
    }
    case RequestStatus::REJECTED:
    {
        return "Rejected";
    }
    case RequestStatus::CANCELLED:
    {
        return "Cancelled";
    }
    default:
        return "";
    }
}
inline RequestStatus stringToRequestStatus(const string& inputString)
{
    if (inputString == "Pending")
    {
        return RequestStatus::PENDING;
    }
    if (inputString == "Approved")
    {
        return RequestStatus::APPROVED;
    }
    if (inputString == "Rejected")
    {
        return RequestStatus::REJECTED;
    }
    if (inputString == "Cancelled")
    {
        return RequestStatus::CANCELLED;
    }
    else
    {
        return RequestStatus::PENDING;
    }
}
inline string convertingPaymentStatusToString(PaymentStatus status)
{
    switch (status)
    {
    case PaymentStatus::PENDING:
    {
        return "Pending";
    }
    case PaymentStatus::VERIFIED:
    {
        return "Verified";
    }
    default:
        return "";
    }
}
inline PaymentStatus stringToPaymentStatus(const string& inputString)
{
    if (inputString == "Pending")
    {
        return PaymentStatus::PENDING;
    }
    if (inputString == "Verified")
    {
        return PaymentStatus::VERIFIED;
    }
    else
    {
        return PaymentStatus::PENDING;
    }
}
inline string convertingPropertyStatusToString(PropertyStatus status)
{
    switch (status)
    {
    case PropertyStatus::AVAILABLE:
    {
        return "Available";
    }
    case PropertyStatus::UNAVAILABLE:
    {
        return "Unavailable";
    }
    case PropertyStatus::SOLD:
    {
        return "Sold";
    }
    default:
        return "";
    }
}
inline PropertyStatus stringToPropertyStatus(const string& inputString)
{
    if (inputString == "Available")
    {
        return PropertyStatus::AVAILABLE;
    }
    if (inputString == "Unavailable")
    {
        return PropertyStatus::UNAVAILABLE;
    }
    if (inputString == "Sold")
    {
        return PropertyStatus::SOLD;
    }
    else
    {
        return PropertyStatus::AVAILABLE;
    }
}
inline CategoryType stringToCategoryType(const string& inputString)
{
    if (inputString == "Showroom")
    {
        return CategoryType::SHOWROOM;
    }
    if (inputString == "Villa")
    {
        return CategoryType::VILLA;
    }
    if (inputString == "Flat")
    {
        return CategoryType::FLAT;
    }
    if (inputString == "Plot")
    {
        return CategoryType::PLOT;
    }
    else
    {
        return CategoryType::WAREHOUSE;
    }
}
inline string convertingCategoryTypeToString(CategoryType category)
{
    switch (category)
    {
    case CategoryType::SHOWROOM:
        return "Showroom";
    case CategoryType::VILLA:
        return "Villa";
    case CategoryType::FLAT:
        return "Flat";
    case CategoryType::PLOT:
        return "Plot";
    case CategoryType::WAREHOUSE:
        return "Warehouse";
    default:
        return "";
    }
}
inline CategoryType ChoiceToCategoryType(const int& choice)
{
    if (choice == 1)
    {
        return CategoryType::SHOWROOM;
    }
    if (choice == 2)
    {
        return CategoryType::VILLA;
    }
    if (choice == 3)
    {
        return CategoryType::FLAT;
    }
    if (choice == 4)
    {
        return CategoryType::PLOT;
    }
    else
    {
        return CategoryType::WAREHOUSE;
    }
}
inline string convertingPaymentTypeToString(PaymentType payment)
{
    switch (payment)
    {
    case PaymentType::FULL:
        return "Full";
    case PaymentType::ADVANCE:
        return "Advance";
    default:
        return "";
    }
}
inline PaymentType choiceToPaymentType(const int& choice)
{
    if (choice == 1)
    {
        return PaymentType::FULL;
    }
    if (choice == 2)
    {
        return PaymentType::ADVANCE;
    }
}
inline PaymentType stringToPaymentType(const string& inputString)
{
    if (inputString == "Full")
    {
        return PaymentType::FULL;
    }
    if (inputString == "Advance")
    {
        return PaymentType::ADVANCE;
    }
}