/*
file main.cpp
Autor: Atanasij Hristovski
Date: 19.10.2025
Version:        1.0
Licence:         MIT
*/
#include <Arduino.h>
// Funktionsdeklaration: Prüft, ob das eingegebene Passwort korrekt ist
bool pass_check(String);

void setup() {
  int versuche = 0; // Zähler für die Anzahl der Passwortversuche
  Serial.begin(115200);
  // Schleife für maximal 3 Versuche
  for(versuche = 0; versuche < 3; versuche ++ )
  {
    Serial.print("Password: ");
    while (Serial.available() == 0){}// Warten, bis der Benutzer etwas über die serielle Schnittstelle eingibt
    String password = Serial.readString(); // Lese die Eingabe als String
    password.trim(); // Entfernt führende und nachgestellte Leerzeichen oder Steuerzeichen

    if(pass_check(password) == true)
    {
      Serial.println("");
      Serial.println("Zugang erlaubt :)");
      break;
    }else{
      Serial.println("");
      Serial.println("Falsch nochmal versuchen");
    }
  }
 // Wenn alle 3 Versuche fehlschlagen
  if (versuche == 3)
  {
    Serial.println("Zugang verweigert");
  }
}

void loop() {
}
// Funktion, die das eingegebene Passwort überprüft
bool pass_check(String eingabe) 
{
  if (eingabe == "Atanasij")
  {
    return true;
  }else{
    return false;
  }
}