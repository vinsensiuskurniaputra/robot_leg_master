# KRSRI Leg Module

This module is part of the KRSRI robot project and is responsible for controlling the robot's leg movements. It includes configurations, controllers, and algorithms for precise and efficient motion.

## Table of Contents

-   [Overview](#overview)
-   [Setup](#setup)
-   [File Structure](#file-structure)
-   [File Explanations](#file-explanations)
-   [Contributing](#contributing)
-   [License](#license)

## Overview

The Leg module provides functionalities to control and coordinate the movements of the robot's legs. It supports various movement patterns such as walking, turning, and climbing.

## Setup

1. Clone the repository:

    ```bash
    git clone <repository-url>
    cd polirevo/KRSRI/Leg
    ```

2. Install dependencies:

    - Ensure you have the Arduino IDE or PlatformIO installed.
    - Install required libraries such as `Adafruit_PWMServoDriver` and `ESP32Servo`.

3. Configure the module:

    - Modify configuration files in the `src/config` directory as needed.

4. Upload the code:
    - Connect your ESP32 board and upload the code using your preferred IDE.

## File Structure

```
Leg/
├── src/
│   ├── config/
│   ├── control/
│   ├── grip_controller/
│   ├── leg_controller/
│   ├── math/
│   └── main.cpp
└── README.md
```

## File Explanations

### `src/config/`

-   **`DataConfig.cpp`**: Contains global variables and calibration data for the robot's legs and grippers.
-   **`ServoConfig.cpp`**: Manages servo configurations, including initialization and angle mapping.

### `src/control/`

-   **`CommandController.cpp`**: Handles high-level commands and maps them to specific robot actions.
-   **`ESPNOWController.cpp`**: Implements ESP-NOW communication for receiving and sending commands wirelessly.
-   **`WifiController.cpp`**: Provides an HTTP server for controlling the robot via Wi-Fi.

### `src/grip_controller/`

-   **`GripControl.cpp`**: Contains functions to control the robot's gripper, including opening, closing, and partial movements.

### `src/leg_controller/`

-   **`NormalStep.cpp`**: Implements basic walking movements.
-   **`NormalStepSlowVersion.cpp`**: Implements slower versions of basic walking movements.
-   **`HighStep.cpp`**: Implements high-step movements for climbing or uneven terrain.
-   **`HighStepSlowVersion.cpp`**: Implements slower versions of high-step movements.
-   **`LadderStep.cpp`**: Implements movements for climbing ladders or similar structures.
-   **`TripodController.cpp`**: Implements tripod gait control for stable walking.

### `src/math/`

-   **`Rotation.cpp`**: Provides rotation calculations for transforming coordinates.
-   **`Trajektori.cpp`**: Implements trajectory generation for smooth leg movements.
-   **`KinematicInverse.cpp`**: Contains inverse kinematics calculations for precise leg positioning.

### `src/main.cpp`

-   The main entry point of the program. Initializes components and runs the control loop for the robot.

## Contributing

Contributions are welcome! Please follow the guidelines in the main repository.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
