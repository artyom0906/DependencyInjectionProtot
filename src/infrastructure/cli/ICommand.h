//
// Created by Artyom on 14.06.2022.
//

#ifndef ICOMMAND_H
#define ICOMMAND_H


#include <string>
#include <vector>
#include "../AppContext.h"

class ICommand {
public:
    virtual void handle(AppContext* context, std::vector<std::string> args) = 0;
    virtual std::string getName() = 0;
    virtual std::string getAliases(){return "";};
};


#endif //ICOMMAND_H
