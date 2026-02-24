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
        FileManager fileManager;
        RealEstateController& controller = RealEstateController::getInstance(&fileManager);
        controller.loadData(); 
        controller.run();
        controller.saveData(); 
    }
    catch (...)
    {
        cout << "Exception : unknown exception" << endl;
    }
}