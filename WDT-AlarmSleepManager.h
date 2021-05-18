#ifndef WDT_ALARM_SLEEP_MANAGER_H_
#define WDT_ALARM_SLEEP_MANAGER_H_

#include <Arduino.h>

class WDTAlarmSleepManager{
public:
    WDTAlarmSleepManager();
    void alarmSleep(byte wdt_prescale);
    void setSleepMode(byte sleep_mode);
private:
    void wdtSetInterruptMode(byte wdt_prescale);
    void wdtSetStoppedMode();
    void sleep();
};

#endif