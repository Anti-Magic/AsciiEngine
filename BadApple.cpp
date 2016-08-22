#include "BadApple.h"
#include "Math.h"

void BadApple::start() {
    image = new Image();
}

void BadApple::update(double dlt) {
    static int x = 0;
    static char name[256];
    sprintf(name, "/Users/staff/Documents/imgs/ba%04d.jpg", x);
    x = x + 1;
    
    if(x > 5450) {
        x = 0;
    }
    
    image->loadFromJpg(name);
    image->drawBinary(frame, 'O', ' ');
}
