//
// Created by Artyom on 19.06.2022.
//

#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#include <map>

#define Init(Typename) \
    template<> \
    Typename IController<Typename>::instance = Typename();

struct TypeBase{
    static std::map<std::string, void*> m_container;
    template<typename T>
    static T* get(){
        return (T*)m_container[typeid(T).name()];
    }
};

template<typename T>
std::tuple<const char*, T, std::tuple<>> t;


std::map<std::string, void*> TypeBase::m_container;


template<typename DeriveType>
class IController {

public:
    static inline DeriveType instance;
    constexpr IController(){
        TypeBase::m_container[typeid(DeriveType).name()] = &instance;
        //this->obj.print();
    }


    virtual void print() = 0;
    virtual std::string name() = 0;
    virtual void create() = 0;
    virtual void remove() = 0;
};

#endif //ICONTROLLER_H
