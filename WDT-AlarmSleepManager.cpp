#include "WDT-AlarmSleepManager.h"
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <Arduino.h>

WDTAlarmSleepManager::WDTAlarmSleepManager()
{
    setSleepMode(SLEEP_MODE_PWR_DOWN);
}

void WDTAlarmSleepManager::alarmSleep(byte wdt_prescale)
{
    wdtSetInterruptMode(wdt_prescale);
    wdt_reset();
    sleep();
    wdtSetStoppedMode();
}

void WDTAlarmSleepManager::setSleepMode(byte sleep_mode)
{
    set_sleep_mode(sleep_mode);
}

void WDTAlarmSleepManager::wdtSetInterruptMode(byte wdt_prescale)
{
    wdt_prescale = ((0b00001000 & wdt_prescale) << 2) | (0b00000111 & wdt_prescale);
    wdt_prescale |= 0b00010000;
    MCUSR &= 0b11110111;
    WDTCSR |= 0b00011000;
    WDTCSR = wdt_prescale;
    //割込みを許可
    WDTCSR |= 0b01000000;
}

void WDTAlarmSleepManager::wdtSetStoppedMode()
{
    byte b = 0;
    b |= 0b00010000;
    MCUSR &= 0b11110111;
    WDTCSR |= 0b00011000;
    WDTCSR = b;
    //割込みを許可
    WDTCSR |= 0b1011111;
}

void WDTAlarmSleepManager::sleep()
{
    //AD変換無効化
    ADCSRA &= 0b01111111;
    sleep_enable();
    sleep_cpu();
    //ここで復帰
    sleep_disable();
}
