#pragma once
#pragma once
#include <string>
using namespace std;

/* ================= USER STATUS ================= */

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

inline UserStatus stringToUserStatus(const string& str)
{
    if (str == "Active") 
    {
        return UserStatus::ACTIVE;
    }
    if (str == "Inactive")
    {
        return UserStatus::INACTIVE;
    }
    else
    {
        return UserStatus::ACTIVE; // default safety
    }
}

/* ================= REQUEST STATUS ================= */



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

inline RequestStatus stringToRequestStatus(const string& str)
{
    if (str == "Pending")
    {
        return RequestStatus::PENDING;
    }
    if (str == "Approved")
    {
        return RequestStatus::APPROVED;
    }
    if (str == "Rejected")
    {
        return RequestStatus::REJECTED;
    }
    if (str == "Cancelled")
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

inline PaymentStatus stringToPaymentStatus(const string& str)
{
    if (str == "Pending")
    {
        return PaymentStatus::PENDING;
    }
    if (str == "Verified")
    {
        return PaymentStatus::VERIFIED;
    }
    else
    {
        return PaymentStatus::PENDING;
    }
}

/* ================= PROPERTY STATUS ================= */

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

inline PropertyStatus stringToPropertyStatus(const string& str)
{
    if (str == "Available")
    {
        return PropertyStatus::AVAILABLE;
    }
    if (str == "Unavailable")
    {
        return PropertyStatus::UNAVAILABLE;
    }
    if (str == "Sold")
    {
        return PropertyStatus::SOLD;
    }
    else
    {
        return PropertyStatus::AVAILABLE;
    }
}
