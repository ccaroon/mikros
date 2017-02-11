# DC Motor
Some example code for controlling a DC motor using an L293D H-Bridge IC chip

### Connection

    Arduino         L293D           Motor       Note
    ------------------------------------------------
    5V      -->     P8  (+Vmotor)               Motor Power
    5V      -->     P16 (+V)                    Chip Power
    P9      -->     P2  (IN1)                   Direction
    P10     -->     P7  (IN2)                   Direction
    P11     -->     P1  (EN1)                   Speed
    GND     -->     P4  (GND)                   Ground
                    P3  (OUT1)      LEAD1       Power or Ground
                    P6  (OUT2)      LEAD2       Power or Ground
