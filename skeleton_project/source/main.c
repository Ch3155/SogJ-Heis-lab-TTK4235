#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "driver/Elevator.h"
#include "driver/MotorControl.h"
#include "driver/Lights.h"
#include "driver/floorpanel.h"




int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(DIRN_STOP);
    struct Floorpanel* Floorpanel;
    Floorpanel_update(Floorpanel);
    struct Elevator* Elevator=Elevator_init(Elevator);
    Lights_init();

    

    while(1){
        
        Floorpanel_update(Floorpanel);
        Lights_update(*Floorpanel, *Elevator);  
        Elevator_update(Elevator);

        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }
    

    return 0;
}
