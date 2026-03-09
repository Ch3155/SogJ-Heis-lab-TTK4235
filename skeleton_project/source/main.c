#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "driver/Elevator.h"
#include "driver/MotorControl.h"
#include "driver/Lights.h"
#include "driver/floorpanel.h"
#include "driver/q_system.h"
#include "driver/ElevatorControl.h"



struct ElevatorControl* elevator_control;


int main(){
    elevio_init();
    elevator_control = ElevatorControl_init();
    
    printf("=== Johannes and Signes awesome Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    ElevatorControl_run(elevator_control);
    

    return 0;
}
