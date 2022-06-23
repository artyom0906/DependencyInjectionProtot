//
// Created by Artyom on 19.06.2022.
//

#ifndef CREATECOMMAND_H
#define CREATECOMMAND_H

#include <utility>
#include "../ICommand.h"

template<typename Controller>
class CreateCommand : public ICommand{
    IController<Controller>* controller;
public:
    CreateCommand(IController<Controller>* controller) : controller(controller) {}

    void handle(AppContext *context, std::vector<std::string> args) override {
        controller->create();
    }

    std::string getName() override {
        return "create";
    }

    std::string getAliases() override {
        return "create " + controller->name();
    }

};
#endif //CREATECOMMAND_H
