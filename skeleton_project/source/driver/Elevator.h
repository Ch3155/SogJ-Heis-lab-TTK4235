#pragma once
#include "elevio.h"
#include "stdbool.h"
#include "Lights.h"

struct Floorpanel;
struct Q_system;

/**
 * @brief Structure representing the state of an elevator.
 */
struct Elevator {   // Structure declaration
    int current_floor;
    bool door_is_open;
    MotorDirection cur_dir;
    bool stop_button_pressed;
    bool is_between_floors;
    bool is_moving;

    bool BTN_1;
    bool BTN_2;
    bool BTN_3;
    bool BTN_4;

}; // End the structure with a semicolon 

/**
 * @brief Sets the state of the elevator door and updates the corresponding lamp.
 */
void Elevator_set_door(struct Elevator* Elevator, bool value, struct Floorpanel* floorpanel, struct Q_system* q_system);

/**
*@brief Creates and initializes a global Elevator structure with default values.
*
*/
struct Elevator* Elevator_init();

/**
 * @brief Updates the state of the elevator based on sensor readings and button states.
 */
void Elevator_update(struct Elevator* Elevator);