// hack to make VS Code work
#ifndef ARDUINO
#define ARDUINO 189
#endif

#include <Arduino.h>
#include <Mouse.h>
#undef round

#define PIN_IN_RANDOM_SEED 0
#define PIN_OUT_LED_PWR 11
#define PIN_OUT_LED_ACTIVE 13
#define PIN_IN_ENABLE 12

#define MIN_LOOP_DELAY 3000
#define MAX_LOOP_DELAY 10001

#define MIN_MOVE_COUNT 2
#define MAX_MOVE_COUNT 6

#define MIN_MOVE_DELAY 100
#define MAX_MOVE_DELAY 2001

#define MIN_MOVE_VAL -200
#define MAX_MOVE_VAL 200

#define ALWAYS_ENABLED false

void setup()
{
    randomSeed(analogRead(PIN_IN_RANDOM_SEED));
    Mouse.begin();
    pinMode(PIN_OUT_LED_PWR, OUTPUT);
    pinMode(PIN_OUT_LED_ACTIVE, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(PIN_IN_ENABLE, INPUT_PULLUP);
    digitalWrite(PIN_OUT_LED_PWR, HIGH);
    digitalWrite(PIN_OUT_LED_ACTIVE, LOW);
}

void moveMouse()
{
    digitalWrite(PIN_OUT_LED_ACTIVE, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    int moveCount = random(MIN_MOVE_COUNT, MAX_MOVE_COUNT);
    for (size_t i = 0; i < moveCount; i++)
    {
        int xVal = random(MIN_MOVE_VAL, MAX_MOVE_VAL);
        int yVal = random(MIN_MOVE_VAL, MAX_MOVE_VAL);
        Mouse.move(xVal, yVal, 0);

        if (i + 1 < moveCount)
        {
            delay(random(MIN_MOVE_DELAY, MAX_MOVE_DELAY));
        }
    }
    digitalWrite(PIN_OUT_LED_ACTIVE, LOW);
    digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
    if (ALWAYS_ENABLED || digitalRead(PIN_IN_ENABLE) == LOW)
    {
        moveMouse();
        int delayTime = random(MIN_LOOP_DELAY, MAX_LOOP_DELAY);
        delay(delayTime);
    }
}
