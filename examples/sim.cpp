/* main.cpp
 *
 * implements main loop logic for simulation.
 *
 */

#include "world.h"

#include <iostream>
#include <thread>


int main()
{
    int num_boids{ 100 };
    int n_rows{ 50 };
    int n_cols{ 50 };
    World w{num_boids, n_rows, n_cols};

    using namespace std::chrono_literals;

    while (true)
    {
        std::cout << w;
        w.update();
        std::this_thread::sleep_for(50ms);
    }

    return 0;
}
