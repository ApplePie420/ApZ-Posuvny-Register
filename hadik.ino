//Definujeme si jednotlivé piny a ich názvy
#define DATA 13
#define CLOCK 12
#define LATCH 11

void setup() {
  //Nastavíme DATA, CLOCK a LATCH ako výstup
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
}

byte cislo = 1;                            //Vyvtoríme premennú "cislo", s hodnotou 1
void loop() {
  if(cislo == 0) {                         //Ak nám premenná pretečie (dostane sa na deviaty, neexistujúci bit), zresetuj jej hodnotu späť na 1
    cislo = 1;
  }
  digitalWrite(LATCH, LOW);                //Vypneme LATCH, nechceme nič vidieť kým shiftujeme dáta
  shiftOut(DATA, CLOCK, MSBFIRST, cislo);  //Vyshiftujeme hodnotu premennej "cislo"
  digitalWrite(LATCH, HIGH);               //Zapneme LATCH keďže chceme vidieť výsledok
  cislo = cislo << 1;                      //Posunieme všetky bity v premennej o jedno miesto doľava. Čiže z 00000001 sa stane 00000010 a potom 00000100.
  delay(1000);                             //Delay 1 sekunda
}
