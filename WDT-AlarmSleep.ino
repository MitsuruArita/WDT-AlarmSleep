#include "WDT-AlarmSleepManager.h"
#include <avr/wdt.h>

WDTAlarmSleepManager wdtAlarmSleepManager;
bool is_debug_mode = false;

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  wdtAlarmSleepManager.alarmSleep(WDTO_8S);
  digitalWrite(13, LOW);
  wdtAlarmSleepManager.alarmSleep(WDTO_8S);
}

ISR(WDT_vect)
{
  
}
