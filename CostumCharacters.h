#pragma once
#include "TextLCD.h"

class CostumCharacters
{
private:
    TextLCD * lcd;

public:

    CostumCharacters( TextLCD * lcd );
    
    void setBatteryIcon( int lvl );
    void setGpsIcon( int gpsFix );
    void setLoraIcon( int lora );
    void setLoraStatusIcon( int loraStatus );
    


};

