#include "../include/module.h"
#include <iostream>

class SampleModule : public Module {
public:
    SampleModule() : Module("SampleModule") {}

    void initialize() override {
        std::cout << "Initializing " << getName() << std::endl;
    }

    void shutdown() override {
        std::cout << "Shutting down " << getName() << std::endl;
    }
};

int main() {
    // Create and register the sample module
    auto module = std::make_shared<SampleModule>();
    ModuleManager::getInstance().registerModule(module);

    // Initialize all modules
    std::cout << "Initializing modules..." << std::endl;
    ModuleManager::getInstance().initializeAll();

    // Do some work...
    std::cout << "Module system is running..." << std::endl;
    std::cout << "Press Enter to shutdown..." << std::endl;
    std::cin.get();

    // Shutdown all modules
    std::cout << "Shutting down modules..." << std::endl;
    ModuleManager::getInstance().shutdownAll();

    return 0;
} 