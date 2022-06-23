#include <iostream>
#include "src/infrastructure/AppContext.h"
#include "src/infrastructure/cli/CommandManager.h"
#include "src/controller/AController.h"
#include "src/infrastructure/cli/command/SubManagerCommand.h"
#include "src/infrastructure/service/IService.h"


class AService{};

int main(){
    std::cout<< typeid(IService<AService>::get()).name();
}


int main1() {
    auto* context = new AppContext();
    CommandManager manager;

    manager.addCommand(new SubManagerCommand<AController>());
    manager.addCommand(new ExitCommand());

    std::string input;
    while (context->isRunning()){
        std::cout<<manager;
        std::cin>>input;
        try {
            manager.handle(context, input);
        }catch (std::runtime_error const& error){
            std::cout<<error.what()<<"\n";
        }
    }
    return 0;
}
