typedef struct {
    int x;
    int y;
} Location;

class TinyJoystick {
    private:
        bool LB; // Left Button
        bool RB; // Right Button

        Location rightStick;
        Location leftStick;

        // int     RX; // Right Stick X
        // int     RY; // Right Stick Y
        // int     LX; // Left Stick X
        // int     LY; // Left Stick Y

    public:
        TinyJoystick();
        void read();
        bool leftButtonPressed();
        bool rightButtonPressed();
        Location getLeftStick();
        Location getRightStick();
};
