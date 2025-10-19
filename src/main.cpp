#include <Arduino.h>

bool pass_check(String);

void setup() {
  int versuche = 0; 
  Serial.begin(115200);
  for(versuche = 0; versuche < 3; versuche ++ )
  {
    Serial.print("Password: ");
    while (Serial.available() == 0){}
    String password = Serial.readString();
    password.trim();

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

  if (versuche == 3)
  {
    Serial.println("Zugang verweigert");
  }
}

void loop() {
}

bool pass_check(String eingabe) 
{
  if (eingabe == "Atanasij")
  {
    return true;
  }else{
    return false;
  }
}