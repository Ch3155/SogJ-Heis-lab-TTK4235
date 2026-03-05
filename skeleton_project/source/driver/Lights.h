struct Lights {
    bool BTN_FLR_4_DWN;
    bool BTN_FLR_3_DWN;
    bool BTN_FLR_3_UP;
    bool BTN_FLR_2_DWN;
    bool BTN_FLR_2_UP;
    bool BTN_FLR_1_UP;

    bool doorOpenLamp;
    bool stopLamp;

    bool floor1Lamp;
    bool floor2Lamp;
    bool floor3Lamp;
    bool floor4Lamp;

    bool btn1Lamp;
    bool btn2Lamp;
    bool btn3Lamp;
    bool btn4Lamp;
};


struct Lights* Lights_init();
void Lights_update(struct Lights* lights, struct Elevator elevator, struct Floorpanel floorpanel);








