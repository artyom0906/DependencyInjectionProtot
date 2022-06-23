//
// Created by Artyom on 22.06.2022.
//

#ifndef CLI_ACONTROLLER_H
#define CLI_ACONTROLLER_H


#include "../infrastructure/controller/AbstractStorageController.h"
#include "../model/A.h"

class AController : public AbstractStorageController<AController, A>{

public:
    void print() override {

    }

    std::string name() override {
        return "AModel";
    }

    void create() override {

    }

    void remove() override {

    }

};

Init(AController)


#endif //CLI_ACONTROLLER_H
