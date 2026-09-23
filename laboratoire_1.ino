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
bool lectureBoucle = false;


void setup() {
    Serial.begin(115200); //Initalize la vitesse de communication
      // Configuration de la DEL
    pinMode(BROCHE_DEL1, OUTPUT);
    digitalWrite(BROCHE_DEL1, LOW);

    pinMode(BROCHE_DEL2, OUTPUT);
    digitalWrite(BROCHE_DEL2, LOW);

    // Configuration du bouton
    bouton1.attach(BROCHE_BOUTON1, INPUT_PULLUP);
    bouton1.setPressedState(LOW);

    bouton2.attach(BROCHE_BOUTON2, INPUT_PULLUP);
    bouton2.setPressedState(LOW);
}

void loop() {
    bouton1.update();

    if (bouton1.isPressed()) {

        if (lectureBoucle == true) {
            lectureBoucle = false;
        } else {
            lectureBoucle = true;
        }

        digitalWrite(BROCHE_DEL1, HIGH);
        Serial.print("bouton6"); //description du bouton
        Serial.print(" "); // espace
        Serial.print(2); // valeur
        Serial.println(); // saut de ligne
    } else {
        digitalWrite(BROCHE_DEL1, LOW);
    }

    bouton2.update();

    if (bouton2.pressed()) {

        digitalWrite(BROCHE_DEL2, HIGH); //lumière est allumée
        Serial.print("bouton8"); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(1); // Valeur
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