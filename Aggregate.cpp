/*
    Aggregate.cpp

    Implementation file for aggregate functions
*/

#include "Aggregate.hpp"

// maximum of the data
double max(const std::vector<double>& data) {

    auto maximum = data[0];
    for (const auto value: data) {
        if (value > maximum)
            maximum = value;
    }

    return maximum;
}

// average of the data
double avg(const std::vector<double>& data) {

    auto total = data[0];
    for (const auto value: data) {
        total += value;
    }

    return total / data.size();
}
