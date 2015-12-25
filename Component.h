#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <string>

class Component {
public:
    virtual void receiveMessage(std::string iMessage);
};

#endif // COMPONENT_H_INCLUDED
