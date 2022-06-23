//
// Created by Artyom on 19.06.2022.
//

#ifndef SUBMANAGERCOMMAND_H
#define SUBMANAGERCOMMAND_H

#include "../../controller/IController.h"
#include <typeinfo>
#include <iostream>
#include "../CommandManager.h"
#include "PrintCommand.h"
#include "CreateCommand.h"
#include "DeleteCommand.h"
#include "ExitCommand.h"

template<typename Controller>
class SubManagerCommand : public ICommand{
    IController<Controller> *controller;
    CommandManager *manager{};
    std::vector<ICommand*> commands;

    void init(){
        this->controller = TypeBase::get<Controller>();
        manager = new CommandManager();

        manager->addCommand(new PrintCommand<Controller>(this->controller));
        manager->addCommand(new CreateCommand(this->controller));
        manager->addCommand(new DeleteCommand(this->controller));
        for (const auto &item: this->commands){
            manager->addCommand(item);
        }
        manager->addCommand(new ExitCommand());
    }

public:

    SubManagerCommand(){
        init();
    }
    template<class ... Commands>
    explicit SubManagerCommand(Commands&& ... commands) : commands{std::forward<Commands>(commands)...}{
        init();
    }


    void handle(AppContext *context, std::vector<std::string> args) override {
        std::string input;
        while (context->isRunning()){
            std::cout<<*manager;
            std::cin>>input;
            try {
                manager->handle(context, input);
            }catch (std::runtime_error const& error){
                std::cout<<error.what()<<"\n";
            }
        }
        context->run();
    }

    std::string getName() override {
        return "manage_" + this->controller->name();
    }

    std::string getAliases() override {
        return "manage " + this->controller->name();
    }

};


#endif //SUBMANAGERCOMMAND_H
