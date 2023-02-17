#pragma once
#include "TextLCD.h"
#include "CostumCharacters.h"
#include "./DisplayX.h"
#include <string>

class Display : public DisplayX
{

private:
    
    bool topBarEnable;
    
    int hours;
    int minutes;
    int seconds;
    int status;
    int distance;
    int radius;
    
    bool position;
    
    std::string description;
    
    PwmOut* backlight;
    std::string emptyRow;
    TextLCD * lcd;
    CostumCharacters * costumCharacters;
    void clearScreen( void );

public:
    Display();
    void setBacklight( float lvl );
    void setTime( int hours, int minutes, int seconds );
    void topBarRedraw( void );
    void setStatusBattery( float batteryLvl );
    void setStatusGps( int gpsFix );
    void setStatusLora( int lora, int loraStatus );
    void setMenuScreen( void );
    
    virtual void setStartScreen( void );
    virtual void setMissionScreen( std::string description, int distance, int radius );
    virtual void setMessageScreen( std::string description );
    virtual void setEndScreen( void );
    void setStatusScreen( void );
    void topBar(bool topBar);
    
    void eventHandler( char key );
};

