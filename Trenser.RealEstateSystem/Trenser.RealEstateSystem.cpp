// Trenser.RealEstateSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//----------------------------------------------Author : Ajmal J S----------------------------------------------
//----------------------------------------------Date : 16-02-2026-----------------------------------------------

#include <iostream>
using namespace::std;
#include "FileManager.h"
#include "RealEstateController.h"

int main()
{
    try
    {
        RealEstateController realEstateController;
        realEstateController.mainMenu();
    }
    catch (const exception& e)
    {
        cout << "Exception : " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Exception : unknown exception" << endl;
    }
}