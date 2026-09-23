#include <Arduino.h>
#include <Bounce2.h>

Bounce2::Button bouton1; //classe bouton1
Bounce2::Button bouton2; //classe bouton2

#define BROCHE_DEL1 5 //D3 sur l'arduino (position)
#define BROCHE_BOUTON1 6 //D2 sur l'arduino

#define BROCHE_DEL2 7 //D5 sur l'arduino (position)
#define BROCHE_BOUTON2 8 //D4 sur l'arduino

bool etatDel = LOW;
bool etatDel2 = LOW;

void setup() {
    Serial.begin(115200); //Initalize la vitesse de communication 

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

void loop() {
 bouton1.update();
 bouton2.update();

 // La DEL suit l'état physique du bouton
    if (bouton1.isPressed())
    {
        digitalWrite(BROCHE_DEL1, HIGH); //lumière est allumée
        Serial.print("bouton1"); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(1); // Valeur
        Serial.println(); // Saut de ligne
    }
    else
    {
        digitalWrite(BROCHE_DEL1, etatDel); //lumière est éteinte
    }

    if (bouton2.pressed())
    {
        digitalWrite(BROCHE_DEL2, HIGH); //lumière est allumée
        Serial.print("bouton2"); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(2); // Valeur
        Serial.println(); // Saut de ligne
        
        if ( etatDel2 == 0 ) {
            etatDel2 = 1;
        } else {
            etatDel2 = 0;    
        }
    }
    else
    {
        digitalWrite(BROCHE_DEL2, etatDel2); //lumière est éteinte
    }
}

