/*
  Titre      : Clavier Matricielle
  Auteur     : Duvalier Tsagmo
  Date       : 20/03/2022
  Description: permettre de selectionner et de controler une intensiter de LED avec un clavier Matricielle
  Version    : 0.0.1
*/

#include <Arduino.h>
//#include "WIFIConnector_MKR1000.h"
//#include "MQTTConnector.h"

// Libraries
#include <Keypad.h> //https://github.com/Chris--A/Keypad

// Constants
#define ROWS 4
#define COLS 4

// Parameters

const int LED_0 = 0;
const int LED_1 = 1;
const int LED_2 = 2;
const int LED_3 = 3;
char boutton, dernierBoutton;
int led_Allum, valeur_Intensite, intensiteAllumLed;

const char kp4x4Keys[ROWS][COLS] = {{'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};
byte rowKp4x4Pin[4] = {11, 10, 9, 8};
byte colKp4x4Pin[4] = {7, 6, 5, 4};

// Variables
Keypad kp4x4 = Keypad(makeKeymap(kp4x4Keys), rowKp4x4Pin, colKp4x4Pin, ROWS, COLS);

void setup()
{

    // Init Serial USB
    Serial.begin(9600);
    Serial.println(F("Initialize System"));

    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
}

void loop()
{
    boutton = kp4x4.getKey();

    switch (boutton)

    {
    case 'A':
        dernierBoutton = 'A';
        break;

    case 'B':
        dernierBoutton = 'B';
        break;

    case 'C':
        dernierBoutton = 'C';
        break;

    case 'D':
        dernierBoutton = 'D';
        break;
    }

    if (boutton == '*')
    {
        switch (dernierBoutton)
        {
        case 'A':
            led_Allum = LED_0;
            break;

        case 'B':
            led_Allum = LED_1;
            break;

        case 'C':
            led_Allum = LED_2;
            break;

        case 'D':
            led_Allum = LED_3;
            break;
        }
    }

    switch (boutton)
    {
    case '0':
        valeur_Intensite = 0;
        break;

    case '1':
        valeur_Intensite = 1;
        break;

    case '2':
        valeur_Intensite = 2;
        break;

    case '3':
        valeur_Intensite = 3;
        break;

    case '4':
        valeur_Intensite = 4;
        break;

    case '5':
        valeur_Intensite = 5;
        break;

    case '6':
        valeur_Intensite = 6;
        break;

    case '7':
        valeur_Intensite = 7;
        break;

    case '8':
        valeur_Intensite = 8;
        break;

    case '9':
        valeur_Intensite = 9;
        break;
    }

    if (boutton == '#')
    {
        intensiteAllumLed = map(valeur_Intensite, 0, 9, 0, 255);
        analogWrite(led_Allum, intensiteAllumLed);
    }

    appendPayload("Pompe", Pompe);
    appendPayload("ValeurSensor", ValeurSensor);
    sendPayload();
}