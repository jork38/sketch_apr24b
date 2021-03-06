// hier staan alle constanten

const int sensorGlas = A0; //op deze pin is de sensor voor het glas aangesloten
const int Stop = A1; //op deze pin is de stopknop aangesloten
const int keuze1 = 2; //op deze pin is de drukknop voor de 1ste keuze aangesloten
const int keuze2 = 3; //op deze pin is de drukknop voor de 2de keuze aangesloten
const int keuze3 = 4; //op deze pin is de drukknop voor de 3de keuze aangesloten
const int Vloeistof1 = 5; // op deze pin is de 1ste vloeistof aangesloten
const int Vloeistof2 = 6; //op deze pin is de 2de vloeistof aangesloten
const int Vloeistof3 = 7; //op deze pin is de 3de vloeistof aangesloten
const int Vloeistof4 = 8; //op deze pin is de 4de vloeistof aangesloten
const int Vloeistof5 = 9; // op deze pin is de 5de vloeistof aangesloten
const int Vloeistof6 = 10; // op deze pin is de 6de vloeistof aangesloten
const int klaarVoorStart = 11; //op deze pin is het lampje "Klaar Voor Start" aangesloten (groen)
const int inWerking = 12; //op deze pin is het lampje"In Werking" aangesloten (root)
const int klaar = 13; //op deze pin is het lampje "Klaar" aangesloten (blauw)

// Hier komen alle wachttijden
const int DebounceDelay = 10;  // dit is de Debouncedelay van ALLE ingangen
const int VloeistofDelay1 = 2000;  // Dit is de wachttijd van de 1ste vloeistof
const int VloeistofDelay2 = 2000;  // Dit is de wachttijd van de 2de vloeistof
const int VloeistofDelay3 = 2000;  // Dit is de wachttijd van de 3de vloeistof
const int VloeistofDelay4 = 2000;  // Dit is de wachttijd van de 4de vloeistof
const int VloeistofDelay5 = 2000;  // Dit is de wachttijd van de 5de vloeistof
const int VloeistofDelay6 = 2000;  // Dit is de wachttijd van de 6de vloeistof
const int uitloopDelay = 1000; // dit is de tijd die de drenk krijgt om uit de darm te lopen

// hier onder komen alle functies

boolean Debounce(int drukknop)
{
  boolean State;
  boolean VorigeState;

  VorigeState = digitalRead(drukknop);// slaag de stand van de drokknop op

  for (int counter = 0;
       counter < DebounceDelay;
       counter ++)
  {
    delay(1); //wacht 1 ms
    State = digitalRead(drukknop);//lees de drukknop opnieuw
    if (State != VorigeState)
    {
      counter = 0;
      VorigeState = State;
    }
  }
  //je komt hier uit als de drukknop langer dan de debounce periode stabiel is
  if (State == HIGH)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Valve1() // hier gaat de 1ste vloeistof mee worden aangestuurd
{
  digitalWrite(Vloeistof1, HIGH);
  delay(VloeistofDelay1);
  digitalWrite(Vloeistof1, LOW);
  delay(uitloopDelay);
  // de vloeistof wordt voor de tijd van "VloeistofDelay1" aangestuurd
}

void Valve2() // hier gaat de 2de vloeistof mee worden aangestuurd
{
  digitalWrite(Vloeistof2, HIGH);
  delay(VloeistofDelay2);
  digitalWrite(Vloeistof2, LOW);
  delay(uitloopDelay);
}

void Valve3() // hier gaat de 3de vloeistof mee worden aangestuurd
{
  digitalWrite(Vloeistof3, HIGH);
  delay(VloeistofDelay3);
  digitalWrite(Vloeistof3, LOW);
  delay(uitloopDelay);
}

void Valve4() // hier zal de 4de vloeistof mee worden aangestuurd
{
  digitalWrite(Vloeistof4, HIGH);
  delay(VloeistofDelay4);
  digitalWrite(Vloeistof4, LOW);
  delay(uitloopDelay);
}

void Valve5() // hier zal de 5de vloeistof mee worden aangestuurd
{
  digitalWrite(Vloeistof5, HIGH);
  delay(VloeistofDelay5);
  digitalWrite(Vloeistof5, LOW);
  delay(uitloopDelay);
}

void Valve6() // hier zal de 6de vloeistof mee worden aangestuurd
{
  digitalWrite(Vloeistof6, HIGH);
  delay(VloeistofDelay6);
  digitalWrite(Vloeistof6, LOW);
  delay(uitloopDelay);
}

void EndFunction() // deze functie wacht tot het glas weg is voor dat deze het programma laat verder lopen
{
    digitalWrite(inWerking, LOW);
    digitalWrite(klaar, HIGH);
  while (Debounce(sensorGlas) == HIGH); {
    
  }
  if (Debounce(sensorGlas) == LOW) {
    digitalWrite(klaar, LOW);
  }
}

void setup() {
  // hier komen alle ingangen
  pinMode(sensorGlas, INPUT);
  pinMode(Stop, INPUT);
  pinMode(keuze1, INPUT);
  pinMode(keuze2, INPUT);
  pinMode(keuze3, INPUT);

  // hier komen alle output's
  pinMode(Vloeistof1, OUTPUT);
  pinMode(Vloeistof2, OUTPUT);
  pinMode(Vloeistof3, OUTPUT);
  pinMode(Vloeistof4, OUTPUT);
  pinMode(Vloeistof5, OUTPUT);
  pinMode(Vloeistof6, OUTPUT);
  pinMode(klaarVoorStart, OUTPUT);
  pinMode(inWerking, OUTPUT);
  pinMode(klaar, OUTPUT);

}


void loop() {
  if ((digitalRead(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
    digitalWrite(klaarVoorStart, HIGH);
    if ((Debounce(keuze1) == HIGH) && (Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
      digitalWrite(klaarVoorStart, LOW);
      digitalWrite(inWerking, HIGH);
      int var = 1;
      switch (var) {
        case 1:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 2;
          }
          else {
            break;
          }
        case 2:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve1();
            var = 3;
          }
          else {
            break;
          }
        case 3:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve1();
            var = 4;
          }
          else {
            break;
          }
        case 4:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve1();
            var = 5;
          }
          else {
            break;
          }
        case 5:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve1();
            var = 6;
          }
          else {
            break;
          }
        case 6:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve3();
            var = 7;
          }
          else {
            break;
          }
        case 7:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve3();
            var = 8;
          }
          else {
            break;
          }
        case 8:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve3();
            var = 9;
          }
          else {
            break;
          }
        case 9:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve2();
            var = 10;
          }
          else {
            break;
          }
        case 10:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve2();
            var = 11;
          }
          else {
            break;
          }
        case 11:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve5();
            var = 12;
          }
          else {
            break;
          }
        case 12:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve5();
            var = 13;
          }
          else {
            break;
          }
        case 13:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve5();
            var = 14;
          }
          else {
            break;
          }
        case 14:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve5();
            var = 15;
          }
          else {
            break;
          }
        case 15:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve1();
            var = 16;
          }
          else {
            break;
          }
        case 16:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve6();
            var = 17;
          }
          else {
            break;
          }
        case 17:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve6();
            var = 18;
          }
          else {
            break;
          }
        case 18:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            //Valve6();
            var = 19;
          }
          else {
            break;
          }
        case 19:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 20;
          }
          else {
            break;
          }
        case 20:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve2();
            var = 21;
          }
          else {
            break;
          }
        case 21:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve3();
            var = 22;
          }
          else {
            break;
          }
        case 22:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve4();
            var = 23;
          }
          else {
            break;
          }
        case 24:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve5();
            var = 25;
          }
          else {
            break;
          }
        case 25:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve6();
            var = 26;
          }
          else {
            break;
          }
        case 26:
          EndFunction();
          break;
      }
    }
    else if ((Debounce(keuze2) == HIGH) && (Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
      digitalWrite(klaarVoorStart, LOW);
      digitalWrite(inWerking, HIGH);
            int var = 1;
      switch (var) {
        case 1:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 2;
          }
          else {
            break;
          }
        case 2:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 3;
          }
          else {
            break;
          }
        case 3:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 4;
          }
          else {
            break;
          }
        case 4:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 5;
          }
          else {
            break;
          }
        case 5:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 6;
          }
          else {
            break;
          }
        case 6:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve3();
            var = 7;
          }
          else {
            break;
          }
        case 7:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve3();
            var = 8;
          }
          else {
            break;
          }
        case 8:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve3();
            var = 9;
          }
          else {
            break;
          }
        case 9:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve2();
            var = 10;
          }
          else {
            break;
          }
        case 10:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve2();
            var = 11;
          }
          else {
            break;
          }
        case 11:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve5();
            var = 12;
          }
          else {
            break;
          }
        case 12:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve5();
            var = 13;
          }
          else {
            break;
          }
        case 13:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve5();
            var = 14;
          }
          else {
            break;
          }
        case 14:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve5();
            var = 15;
          }
          else {
            break;
          }
        case 15:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 16;
          }
          else {
            break;
          }
        case 16:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve6();
            var = 17;
          }
          else {
            break;
          }
        case 17:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve6();
            var = 18;
          }
          else {
            break;
          }
        case 18:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve6();
            var = 19;
          }
          else {
            break;
          }
        case 19:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 20;
          }
          else {
            break;
          }
        case 20:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 21;
          }
          else {
            break;
          }
        case 21:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 22;
          }
          else {
            break;
          }
        case 22:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 23;
          }
          else {
            break;
          }
        case 24:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 25;
          }
          else {
            break;
          }
        case 25:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 26;
          }
          else {
            break;
          }
        case 26:
          EndFunction();
          break;
      }
    }
    else if ((Debounce(keuze3) == HIGH) && (Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
      digitalWrite(klaarVoorStart, LOW);
      digitalWrite(inWerking, HIGH);
            int var = 1;
      switch (var) {
        case 1:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 2;
          }
          else {
            break;
          }
        case 2:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 3;
          }
          else {
            break;
          }
        case 3:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 4;
          }
          else {
            break;
          }
        case 4:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 5;
          }
          else {
            break;
          }
        case 5:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 6;
          }
          else {
            break;
          }
        case 6:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve3();
            var = 7;
          }
          else {
            break;
          }
        case 7:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve3();
            var = 8;
          }
          else {
            break;
          }
        case 8:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve3();
            var = 9;
          }
          else {
            break;
          }
        case 9:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve2();
            var = 10;
          }
          else {
            break;
          }
        case 10:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve2();
            var = 11;
          }
          else {
            break;
          }
        case 11:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve5();
            var = 12;
          }
          else {
            break;
          }
        case 12:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve5();
            var = 13;
          }
          else {
            break;
          }
        case 13:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve5();
            var = 14;
          }
          else {
            break;
          }
        case 14:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve5();
            var = 15;
          }
          else {
            break;
          }
        case 15:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve1();
            var = 16;
          }
          else {
            break;
          }
        case 16:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve6();
            var = 17;
          }
          else {
            break;
          }
        case 17:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve6();
            var = 18;
          }
          else {
            break;
          }
        case 18:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            Valve6();
            var = 19;
          }
          else {
            break;
          }
        case 19:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 20;
          }
          else {
            break;
          }
        case 20:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 21;
          }
          else {
            break;
          }
        case 21:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 22;
          }
          else {
            break;
          }
        case 22:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 23;
          }
          else {
            break;
          }
        case 24:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 25;
          }
          else {
            break;
          }
        case 25:
          if ((Debounce(Stop) == LOW) && (Debounce(sensorGlas) == HIGH)) {
            // Valve1();
            var = 26;
          }
          else {
            break;
          }
        case 26:
          EndFunction();
          break;
      }
    }
    else {
      digitalWrite(inWerking, LOW);
    }
  }
  else {
    digitalWrite(klaarVoorStart, LOW);
  }
}
