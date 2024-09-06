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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include <stdexcept>
#include <string>

namespace sdds {
    class Utilities {
    private:
        // static size_t m_widthField;
        size_t m_widthField = 1;
        static char m_delimiter;

    public:
        static void setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

        static char getDelimiter() { return m_delimiter; }

        void setFieldWidth(size_t newWidth) { m_widthField = newWidth; }

        size_t getFieldWidth() const { return m_widthField; }

        std::string extractToken(const std::string& str,
            size_t& next_pos,
            bool& more);
    };
}  // namespace sdds

#endif