#pragma once
#include <stdbool.h>

struct Floorpanel {
    bool BTN_FLR_4_DWN;
    bool BTN_FLR_3_DWN;
    bool BTN_FLR_3_UP;
    bool BTN_FLR_2_DWN;
    bool BTN_FLR_2_UP;
    bool BTN_FLR_1_UP;
};

void Floorpanel_update(struct Floorpanel* floorpanel);
