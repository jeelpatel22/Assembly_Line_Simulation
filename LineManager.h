/*************************
// Intro. to Object Oriented Programming
// Milestone 3
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name :Jeelkumar Vinodkumar Patel           Date : 02-12-2023           Reason
//Student ID: 115766222
//Student mail: jpatel391@myseneca.ca


//Authentication Declaration:

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
*************************/




#pragma once
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Utilities.h"
#include "Workstation.h"

namespace sdds {
    class LineManager {
    private:
        std::vector<Workstation*> m_activeLine;
        size_t m_cntCustomerOrder{ 0 };
        Workstation* m_firstStation{ nullptr };

    public:
        LineManager() = default;
        LineManager(const std::string& file,
            const std::vector<Workstation*>& stations);
        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
}  // namespace sdds

#endif