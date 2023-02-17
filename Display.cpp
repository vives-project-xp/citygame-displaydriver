#include "Display.h"
#include "TextLCD.h"
#include "CostumCharacters.h"
#include <string>
#include <sstream>

Display::Display() 
{
    topBarEnable = 0;
    
    hours = 0;
    minutes = 0;
    seconds = 0;
    distance = 0;
    radius = 0;
    position = 0;
    description = "";
    
    status = 0;
    
    backlight = new PwmOut(PTB19);
    backlight->period(0.001f);      //frequentie pwm
    backlight->write(0.75f);        //duty cycle
    
    emptyRow = "                    ";
    
    lcd = new TextLCD( PTC5, PTC7, PTC0, PTC9, PTC8, PTC1, TextLCD::LCD20x4 );
    costumCharacters = new CostumCharacters( lcd );
    
    costumCharacters->setBatteryIcon( 0 );
    costumCharacters->setGpsIcon( 0 );
    costumCharacters->setLoraIcon( 1 );
    costumCharacters->setLoraStatusIcon( 0 );
    
    lcd->cls();
    lcd->locate(0,0);
}

void Display::topBar(bool topBarEnable)
{
    if(topBarEnable)
    {
        Display::topBarRedraw();
    }
    
    if( this->topBarEnable == 1 && topBarEnable == 0 )
    {
        lcd->locate(0,0);
        lcd->printf( emptyRow.c_str() );
    }
    this->topBarEnable = topBarEnable;
}

void Display::setTime(int hours, int minutes, int seconds)
{    
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    Display::topBarRedraw();
}
    
void Display::topBarRedraw( void )
{ 
    if(topBarEnable)
    {

    char buffer[10];
    std::string time = "";
    
    if(this->hours <= 9) { time.append( "0" ); }
    std::sprintf(buffer, "%d", this->hours);
    time.append( std::string(buffer) );

    time.append( ":" );
    
    if(this->minutes <= 9) { time.append( "0" ); }
    std::sprintf(buffer, "%d", this->minutes);
    time.append( std::string(buffer) );
    
    time.append( ":" );

    if(this->seconds <= 9) { time.append( "0" ); }
    std::sprintf(buffer, "%d", this->seconds);
    time.append( std::string(buffer) );
    
    lcd->locate(0,0);
    lcd->printf( emptyRow.c_str() );
    lcd->locate(0,0);
    lcd->printf("\3\4");
    lcd->locate(18,0);
    lcd->printf("\2\1");
    lcd->locate(6,0);
    lcd->printf( time.c_str());
    }
}

void Display::setStatusBattery( float batteryLvl )
{
    if ( 1 >= batteryLvl && batteryLvl >= 0 )
    {
        int lvl;
        batteryLvl = batteryLvl * 5;         //get size of replace 5
        lvl = (int) batteryLvl;       
        costumCharacters->setBatteryIcon( lvl );
    }
}

void Display::setStatusLora( int lora, int loraStatus )
{  
    costumCharacters->setLoraIcon( lora );
    costumCharacters->setLoraStatusIcon( loraStatus );
}

void Display::setStatusGps( int gpsFix )
{
    costumCharacters->setGpsIcon( gpsFix );
}

void Display::setStartScreen( void )
{
    this->status = 0;
    
    Display::topBar( 0 );
    Display::clearScreen();
    
    for(int i = 13; i >= 0; i--)
    {
    lcd->locate( 0, 0 );
    lcd->printf( "                    " );
    lcd->locate( i, 0 );
    lcd->printf( "Welcome" );
    ThisThread::sleep_for(std::chrono::milliseconds(20));
    }
    for(int i = 14; i >= 0; i--)
    {
    lcd->locate( 0, 1 );
    lcd->printf( "                    " );
    lcd->locate( i, 1 );
    lcd->printf( "to the" );
    ThisThread::sleep_for(std::chrono::milliseconds(20));
    }
    for(int i = 15; i >= 0; i--)
    {
    lcd->locate( 0, 2 );
    lcd->printf( "                    " );
    lcd->locate( i, 2 );
    lcd->printf( "Vives" );
    ThisThread::sleep_for(std::chrono::milliseconds(20));
    }
    for(int i = 11; i >= 0; i--)
    {
    lcd->locate( 0, 3 );
    lcd->printf( "                    " );
    lcd->locate( i, 3 );
    lcd->printf( "City Game" );
    ThisThread::sleep_for(std::chrono::milliseconds(20));
    }
    lcd->locate( 19, 3 );
    lcd->putc( (char) 126 );
}

void Display::setMissionScreen( std::string description, int distance, int radius )
{
    this->description = description;
    this->distance = distance;
    this->radius = radius;
    
    if( this->status == 3 )
    {
    
    
    Display::clearScreen();
    Display::topBar( 1 );
    
    lcd->locate( 0, 1 );
    lcd->printf( description.c_str() );
    
    char buffer[10];
    std::string distanceString = "";
    distanceString.append( "Dist:" );
    std::sprintf(buffer, "%d", distance);
    distanceString.append( std::string(buffer) );
    distanceString.append( "m" );
    
    lcd->locate( 0, 3 );
    lcd->printf( distanceString.c_str() );
    
    char buffer2[10];
    std::string radString = "";
    radString.append( "Rad:" );
    std::sprintf(buffer2, "%d", radius);
    radString.append( std::string(buffer2) );
    radString.append( "m" );
    
    lcd->locate( 12, 3 );
    lcd->printf( radString.c_str() );
    
    Display::topBarRedraw();
    }
}

void Display::setEndScreen( void )
{
    Display::topBar( 0 );
    Display::clearScreen();
    
    for(int i = 0; i < 7; i++)
    {
    lcd->locate( 2, 0 );
    lcd->printf( "Congratulations!" );
    ThisThread::sleep_for(std::chrono::milliseconds(120));
    Display::clearScreen();
    ThisThread::sleep_for(std::chrono::milliseconds(100));
    }
    
    lcd->locate( 2, 0 );
    lcd->printf( "Congratulations!" );
    lcd->locate( 3, 1 );
    lcd->printf( "You completed" );
    lcd->locate( 6, 2 );
    lcd->printf( "all the" );
    lcd->locate( 5, 3 );
    lcd->printf( "missions!" );
    
}

void Display::clearScreen( void )
{
    if( topBarEnable )
    {
        lcd->locate(0,1);
        lcd->printf( emptyRow.c_str() );
        lcd->locate(0,2);
        lcd->printf( emptyRow.c_str() );
        lcd->locate(0,3);
        lcd->printf( emptyRow.c_str());
    }
    else
    {
        lcd->cls();
    }
}

void Display::setMessageScreen( std::string message )
{
    if( this->status == 3 )
    {
    Display::clearScreen();
    
    if(topBarEnable)
    {
        lcd->locate(0,1);
    }
    else
    {
        lcd->locate(0,0);
    }
    lcd->printf( message.c_str() );
    }
}

void Display::setMenuScreen( void )
{
    position = ! position;
    
    Display::clearScreen();
    Display::topBar( 1 );
    
    
    if( position )
    {
        lcd->locate(0,2);
    }
    else
    {
        lcd->locate(0,3);
    }
    lcd->putc( (char) 126 );
    
    lcd->locate(0,1);
    lcd->printf( "Menu:" );
    lcd->locate(1,2);
    lcd->printf( "Start game" );
    lcd->locate(1,3);
    lcd->printf( "Status screen" );
   
}

void Display::eventHandler( char key )
{
    switch( status )
    {
      case 0:           //Welcome screen
            {
                Display::setMenuScreen();
                this->status = 1;
            }
        break;
      case 1:           //Menu screen
            {
                switch( key )
                {
                    case '2':
                    {
                        Display::setMenuScreen();
                    }
                break;
                    case '5':
                    {
                        if( position )
                        {
                            this->status = 3;
                            Display::setMissionScreen( this->description, this->distance, this->radius );
                        }
                        else
                        {
                            this->status = 2;
                            Display::setStatusScreen();
                        }
                        
                    }
                    break;
                    case '8':
                    {
                        Display::setMenuScreen();
                    }
                    break;
                }
            }
        break;
      case 2:
            {
                this->status = 1;
                Display::setMenuScreen();
            }
        break;
      case 3:
            {

            }
        break;
    }
}

void Display::setStatusScreen( void )
{
    Display::clearScreen();
    Display::topBar( 1 );
    
    lcd->locate(0,2);
    lcd->printf( "Battery" );
    lcd->locate(0,3);
    lcd->printf( "Voltage: " );
}