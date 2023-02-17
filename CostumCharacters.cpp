#include "CostumCharacters.h"
#include "TextLCD.h"
#include <string>

  
CostumCharacters::CostumCharacters( TextLCD * lcd )
{
    this->lcd = lcd;
}

void CostumCharacters::setBatteryIcon( int lvl )
{
    switch( lvl ) {
      case 0:
            {
            char batteryIcon0[] = {0x0E, 0x1F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1F};
            lcd->defineChar( 1, batteryIcon0 );
            }
        break;
      case 1:
            {
            char batteryIcon1[8] = {0x0E, 0x1F, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x1F};
            lcd->defineChar( 1, batteryIcon1 );
            }
        break;
      case 2:
            {
            char batteryIcon2[8] = {0x0E, 0x1F, 0x11, 0x11, 0x11, 0x1F, 0x1F, 0x1F};
            lcd->defineChar( 1, batteryIcon2 );
            }
        break;
      case 3:
            {
            char batteryIcon3[8] = {0x0E, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F};
            lcd->defineChar( 1, batteryIcon3 );
            }
        break;
      case 4:
            {
            char batteryIcon4[8] = {0x0E, 0x1F, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
            lcd->defineChar( 1, batteryIcon4 );
            }
        break;
      case 5:
            {
            char batteryIcon5[8] = {0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
            lcd->defineChar( 1, batteryIcon5 );
            }
        break;
    }
}

void CostumCharacters::setGpsIcon( int gpsFix )
{
    switch( gpsFix ) {
      case 0:
            {
            char gpsIcon0[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            lcd->defineChar( 2, gpsIcon0 );
            }
        break;
      case 1:
            {
            char gpsIcon1[8] = {0x00, 0x0E, 0x1B, 0x11, 0x1B, 0x0E, 0x0E, 0x04};
            lcd->defineChar( 2, gpsIcon1 );
            }
        break;
    }
}

void CostumCharacters::setLoraIcon( int lora )
{
    switch( lora ) {
      case 0:
            {
            char loraIcon0[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            lcd->defineChar( 3, loraIcon0 );
            }
        break;
      case 1:
            {
            char loraIcon1[8] = {0x00, 0x1F, 0x0E, 0x04, 0x04, 0x04, 0x04, 0x04};
            lcd->defineChar( 3, loraIcon1 );
            }
        break;
    }
}

void CostumCharacters::setLoraStatusIcon( int loraStatus )
{
    switch( loraStatus ) {
      case 0:
            {
            char loraStatus0[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            lcd->defineChar( 4, loraStatus0 );
            }
        break;
      case 1:
            {
            char loraStatus1[8] = {0x04, 0x0E, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04};
            lcd->defineChar( 4, loraStatus1 );
            }
        break;
      case 2:
            {
            char loraStatus2[8] = {0x04, 0x04, 0x04, 0x04, 0x04, 0x1F, 0x0E, 0x04};
            lcd->defineChar( 4, loraStatus2 );
            }
        break;
    }
}

