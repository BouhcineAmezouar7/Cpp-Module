#pragma once

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &other); // Copy constructor
    Brain &operator=(const Brain &other); // Copy assignment operator
    ~Brain();

    std::string getIdea(int index) const; // Getter for idea at index
    void setIdea(int index, const std::string &idea); // Setter for idea at index
};
