# ModuleEdge

A lightweight module system for C++ applications.

## Features
- Simple module registration and management
- Lifecycle management (initialize/shutdown)
- Singleton-based module manager
- Modern C++ design

## Building

```bash
make
```

## Running

```bash
./bin/module_demo
```

## Requirements
- C++11 or later
- GCC/G++ compiler
- Standard C++ library

## Usage Example

```cpp
// Create a new module
class MyModule : public Module {
public:
    MyModule() : Module("MyModule") {}
    
    void initialize() override {
        // Initialization code
    }
    
    void shutdown() override {
        // Cleanup code
    }
};

// Register and use the module
auto module = std::make_shared<MyModule>();
ModuleManager::getInstance().registerModule(module);
ModuleManager::getInstance().initializeAll();
```

## License
MIT License
