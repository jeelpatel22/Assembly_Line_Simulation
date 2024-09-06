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



#include "LineManager.h"

namespace sdds {

    LineManager::LineManager(const std::string& file,
        const std::vector<Workstation*>& stations) {
        ifstream writeFile(file);

        if (file.empty()) {
            throw string("  Unable to open file: " + file);
        }

        string line;

        while (getline(writeFile, line)) {
            string currntStation = line.substr(0, line.find_first_of('|'));
            string nextStation = line.erase(0, currntStation.size() + 1);

            // find the matching name and push in active line
            auto station =
                find_if(stations.begin(), stations.end(), [&](Workstation* station) {
                return station->getItemName() == currntStation;
                    });

            m_activeLine.push_back(*station);

            // for the next work station
            if (!nextStation.empty()) {
                for_each(stations.begin(), stations.end(), [&](Workstation* station) {
                    if (station->getItemName() == nextStation)
                    m_activeLine.back()->setNextStation(station);
                    });
            }
            else {
                m_activeLine.back()->setNextStation(nullptr);
            }
        }

        // identifies the first station
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
            auto findFirst = find_if(
                m_activeLine.begin(), m_activeLine.end(),
                [&](Workstation* ws) { return station == ws->getNextStation(); });
        if (findFirst == m_activeLine.end()) {
            m_firstStation = station;
        }
            });

        // update order number
        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations() {
        // std::sort(m_activeLine.begin(), m_activeLine.end(),
        //           [](const Workstation* cur, const Workstation* next) {
        //             return cur->getItemName() < next->getItemName();
        //           });

        std::vector<Workstation*> tempStations;

        tempStations.push_back(m_firstStation);
        if (m_firstStation->getNextStation() != nullptr)
            tempStations.push_back(m_firstStation->getNextStation());

        std::for_each(m_activeLine.begin(), m_activeLine.end() - 2,
            [&](Workstation* station) {
                tempStations.push_back(tempStations.back()->getNextStation());
            });

        m_activeLine = tempStations;
    }

    bool LineManager::run(std::ostream& os) {
        static size_t count = 0;
        ++count;

        os << "Line Manager Iteration: " << count << std::endl;

        // Move front order in g_pending to m_firstStation and remove from g_pending
        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        for_each(m_activeLine.begin(), m_activeLine.end(),
            [&](Workstation* station) { station->fill(os); });

        for_each(m_activeLine.begin(), m_activeLine.end(),
            [&](Workstation* station) { station->attemptToMoveOrder(); });

        // all customer orders have been filled or cannot be filled ?
        return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
    }

    void LineManager::display(std::ostream& os) const {
        for_each(m_activeLine.begin(), m_activeLine.end(),
            [&](const Workstation* station) { station->display(os); });
    }

}  // namespace sdds