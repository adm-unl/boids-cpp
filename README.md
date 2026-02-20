# boids-cpp

boids-cpp is a modern C++ library for simulating [Boids](https://en.wikipedia.org/wiki/Boids), an artificial life program which simulates the flocking behaviour of birds. 
It was developed by Craig Reynolds in 1986. The boids exhibit emergent behaviour as a result of obeying three simple rules: separation, alignment, and cohesion. 

This project provides a reusable library implementation, an example application, and unit tests using Google Test.

## Installation

Clone the repository with submodules.

```bash
git clone --recurse-submodules https://github.com/adm-unl/boids-cpp.git
cd boids-cpp
```

## Build Instructions

Build the project with CMake and run tests with CTest.
```bash
cmake -S . -B build
cmake --build build

ctest --test-dir build
```



## Usage

Simulation weights can be tuned in the config.h file to alter behaviour of boids.

```c++
#include "world.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chromo_literals;

int main()
{
    int rows{ 50 };
    int cols{ 50 };
    int num_boids{ 50 };
    World world{ num_boids, rows, cols };

    while (true)
    {
        std::cout << world;
        world.update();
        std::this_thread::sleep_for(100ms);
    }
    return 0;
}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
