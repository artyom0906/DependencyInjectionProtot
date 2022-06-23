//
// Created by Artyom on 14.06.2022.
//

#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include <map>
#include "controller/IController.h"

class AppContext {
public:
    AppContext() = default;

    template<typename T>
    T get(){
        //return this->objects[typeid(T).name()];
        return TypeBase::get<T>();
    }

    bool isRunning() const {
        return this->work;
    }
    void run(){
        this->work = true;
    }

    void stop(){
        this->work = false;
    }
private:
    std::map<std::string, void*> objects;
    bool work = true;
};


#endif //APPCONTEXT_H
