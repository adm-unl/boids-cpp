/* config.h
 *
 * defines the weights used for boid simulation.
 * tune these to change behaviour.
 *
 */

#ifndef CONFIG_H
#define CONFIG_H

struct BoidConfig
{
    float separation_weight{ 1.0f };
    float separation_radius{ 0.5f };
    float alignment_weight{ 8.0f };
    float cohesion_weight{ 100.0f };
    float perception_radius{ 3.0f };
    float field_of_view{ 300 };
    float max_speed{ 5.0f };
};

#endif

