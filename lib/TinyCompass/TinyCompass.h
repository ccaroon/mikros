//------------------------------------------------------------------------------
//  TinyCircuits Compass TinyShield Library
//  Using Honeywell HMC5883 in I2C mode
//------------------------------------------------------------------------------
#define HMC5883_I2CADDR     0x1E

class TinyCompass {
    private:
        int x_max = -10000;  // Starting values for hard iron calibration
        int y_max = -10000;  // We want these values to be extreme in the 
        int x_min =  10000;  // opposite direction so it calibrates nicely
        int y_min =  10000;
        int x;
        int y;
        int z;
        int degrees;

    public:
        TinyCompass();
        void init();
        void read();
        int getX();
        int getY();
        int getZ();
        int getDegrees();
};
