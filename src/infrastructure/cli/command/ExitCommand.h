//
// Created by Artyom on 14.06.2022.
//

#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H


#include "../ICommand.h"

class ExitCommand : public ICommand{

public:
    void handle(AppContext *context, std::vector<std::string> args) override {
        context->stop();
    }

    std::string getName() override {
        return "exit";
    }

    std::string getAliases() override {
        return "back or exit";
    }
};


#endif //EXITCOMMAND_H
