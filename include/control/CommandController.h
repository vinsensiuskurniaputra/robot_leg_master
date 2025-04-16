#ifndef COMMAND_CONTROLLER_H
#define COMMAND_CONTROLLER_H
#include "config/DataConfig.h"
#include <Arduino.h>
#include "leg_controller/NormalStep.h"
#include "leg_controller/NormalStepSlowVersion.h"
#include "leg_controller/HighStep.h"
#include "leg_controller/HighStepSlowVersion.h"
#include "leg_controller/LadderStep.h"
#include "grip_controller/GripControl.h"

class CommandController {
public:
    static void command(int a, int b, int c, int d, int e);
    static void main_robot();
};

#endif
