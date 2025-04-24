#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <functional>
#include <map>
#include <memory>

class Module {
public:
    Module(const std::string& name) : name_(name) {}
    virtual ~Module() = default;

    virtual void initialize() = 0;
    virtual void shutdown() = 0;
    const std::string& getName() const { return name_; }

private:
    std::string name_;
};

class ModuleManager {
public:
    static ModuleManager& getInstance() {
        static ModuleManager instance;
        return instance;
    }

    void registerModule(std::shared_ptr<Module> module) {
        modules_[module->getName()] = module;
    }

    void initializeAll() {
        for (auto& pair : modules_) {
            pair.second->initialize();
        }
    }

    void shutdownAll() {
        for (auto& pair : modules_) {
            pair.second->shutdown();
        }
    }

private:
    ModuleManager() = default;
    std::map<std::string, std::shared_ptr<Module>> modules_;
};

#endif // MODULE_H 