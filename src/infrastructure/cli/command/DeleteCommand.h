//
// Created by Artyom on 19.06.2022.
//

#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H
#include <utility>
#include "../ICommand.h"
#include "../../controller/IController.h"

template<typename Controller>
class DeleteCommand : public ICommand{
    IController<Controller>* controller;
public:
    explicit DeleteCommand(IController<Controller>* controller) : controller(controller) {}

    void handle(AppContext *context, std::vector<std::string> args) override {
        controller->remove();
    }

    std::string getName() override {
        return "delete";
    }

    std::string getAliases() override {
        return "delete " + controller->name();
    }

};

#endif //DELETECOMMAND_H
