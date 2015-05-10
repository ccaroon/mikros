#include "Charliplexing.h"
#include "indicators.h"

void indicateSimpleDirection(int direction) {
    switch (direction) {
        case CP_1:
            LedSign::Set(2,0);
            LedSign::Set(3,0);
            break;
        case CP_3:
            LedSign::Set(5,0);
            break;
        case CP_5: 
            LedSign::Set(5,4);
            break;
        case CP_7:
            LedSign::Set(5,8);
            break;
        case CP_9:
            LedSign::Set(2,8);
            LedSign::Set(3,8);
            break;
        case CP_11:
            LedSign::Set(0,8);
            break;
        case CP_13:
            LedSign::Set(0,4);
            break;
        case CP_15:
            LedSign::Set(0,0);
            break;
    }
}

void drawArrow(int direction) {

    switch (direction) {
        case CP_1:
            LedSign::Set(2,0);
            LedSign::Set(3,0);
            LedSign::Set(2,1);
            LedSign::Set(3,1);
            LedSign::Set(2,2);
            LedSign::Set(3,2);
            LedSign::Set(2,3);
            LedSign::Set(3,3);
            LedSign::Set(2,4);
            LedSign::Set(3,4);
            LedSign::Set(1,1);
            LedSign::Set(4,1);
            break;
        case CP_3:
            LedSign::Set(2,4);
            LedSign::Set(3,4);
            LedSign::Set(3,2);
            LedSign::Set(3,3);
            LedSign::Set(4,0);
            LedSign::Set(4,1);
            LedSign::Set(5,0);
            LedSign::Set(5,1);
            break;
        case CP_5: 
            LedSign::Set(2,4);
            LedSign::Set(3,4);
            LedSign::Set(4,4);
            LedSign::Set(5,4);
            LedSign::Set(4,3);
            LedSign::Set(4,5);
            break;
        case CP_7:
            LedSign::Set(2,4);
            LedSign::Set(3,4);
            LedSign::Set(3,5);
            LedSign::Set(3,6);
            LedSign::Set(4,7);
            LedSign::Set(4,8);
            LedSign::Set(5,7);
            LedSign::Set(5,8);
            break;
        case CP_9:
            LedSign::Set(2,4);
            LedSign::Set(3,4);
            LedSign::Set(2,5);
            LedSign::Set(3,5);
            LedSign::Set(2,6);
            LedSign::Set(3,6);
            LedSign::Set(2,7);
            LedSign::Set(3,7);
            LedSign::Set(2,8);
            LedSign::Set(3,8);
            LedSign::Set(1,7);
            LedSign::Set(4,7);
            break;
        case CP_11:
            LedSign::Set(2,4);
            LedSign::Set(3,4);
            LedSign::Set(2,5);
            LedSign::Set(2,6);
            LedSign::Set(1,7);
            LedSign::Set(1,8);
            LedSign::Set(0,7);
            LedSign::Set(0,8);
            break;
        case CP_13:
            LedSign::Set(0,4);
            LedSign::Set(1,4);
            LedSign::Set(2,4);
            LedSign::Set(3,4);
            LedSign::Set(1,3);
            LedSign::Set(1,5);
            break;
        case CP_15:
            LedSign::Set(2,4);
            LedSign::Set(3,4);
            LedSign::Set(2,2);
            LedSign::Set(2,3);
            LedSign::Set(0,1);
            LedSign::Set(0,2);
            LedSign::Set(1,1);
            LedSign::Set(1,2);
            break;            
        default:
            LedSign::Set(2,3);
            LedSign::Set(3,3);
            LedSign::Set(2,4);
            LedSign::Set(3,4);
            break;
    }
}

void ledOn(uint8_t led) {

    switch (led) {
        case 1:
        case 2:
            LedSign::Set(led+1,0);
            break;
        case 3:
            LedSign::Set(4,1);
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            LedSign::Set(5,led-2);
            break;
        case 9:
            LedSign::Set(4,7);
            break;
        case 10:
        case 11:
            LedSign::Set(13-led,8);
            break;
        case 12:
            LedSign::Set(1,7);
            break;
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            LedSign::Set(0,19-led);
            break;
        case 18:
            LedSign::Set(1,1);
            break;
    }
}