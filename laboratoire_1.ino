#include <Arduino.h>
#include <Bounce2.h>

Bounce2::Button bouton1;
Bounce2::Button bouton2;

#define BROCHE_DEL1 6
#define BROCHE_BOUTON1 5

#define BROCHE_DEL2 8
#define BROCHE_BOUTON2 7

bool etatDel = LOW;
bool etatDel2 = LOW;

void setup()
{

    // Configuration de la DEL1 et DEL2
    pinMode(BROCHE_DEL1, OUTPUT);
    digitalWrite(BROCHE_DEL1, etatDel);
    pinMode(BROCHE_DEL2, OUTPUT);
    digitalWrite(BROCHE_DEL2, etatDel);

    // Configuration du bouton1 etbouton2
    bouton1.attach(BROCHE_BOUTON1, INPUT_PULLUP);
    bouton1.setPressedState(LOW);
    bouton2.attach(BROCHE_BOUTON2, INPUT_PULLUP);
    bouton2.setPressedState(LOW);
}

void loop()
{
    bouton1.update();
    bouton2.update();

    // La DEL suit l'état physique du bouton
    if (bouton1.isPressed())
    {
        digitalWrite(BROCHE_DEL1, HIGH);
    }
    else
    {
        digitalWrite(BROCHE_DEL1, etatDel);
    }

    if (bouton2.pressed())
    {
        digitalWrite(BROCHE_DEL2, HIGH);

        if (etatDel2 == 0)
        {
            etatDel2 = 1;
        }
        else
        {
            etatDel2 = 0;
        }
    }
    else
    {
        digitalWrite(BROCHE_DEL2, etatDel2);
    }
}
