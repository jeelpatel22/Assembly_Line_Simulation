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



#include "Utilities.h"

namespace sdds {

    // size_t Utilities::m_widthField = 1;
    char Utilities::m_delimiter = ',';

    std::string Utilities::extractToken(const std::string& str,
        size_t& next_pos,
        bool& more) {
        size_t startPos = next_pos;
        size_t endPos = str.find(m_delimiter, next_pos);

        if (endPos != std::string::npos) {
            next_pos = endPos + 1;
            more = true;
        }
        else {
            endPos = str.length();
            more = false;
        }

        if (startPos == endPos) {
            more = false;
            throw std::runtime_error("a delimiter is found at next_pos");
        }

        std::string token = str.substr(startPos, endPos - startPos);
        if (!token.empty() && token[0] == ' ')
            token.erase(0, token.find_first_not_of(' '));
        if (!token.empty() && token[token.length() - 1] == ' ')
            token.erase(token.find_last_not_of(' ') + 1);
        if (token.length() > m_widthField)
            m_widthField = token.length();

        return token;
    }
}  // namespace sdds