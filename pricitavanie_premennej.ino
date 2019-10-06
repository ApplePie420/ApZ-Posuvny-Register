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

byte cislo = 1;                             //Vyvtoríme premennú "cislo", s hodnotou 1
void loop() {
  if(arr == 0) {                            //Ak nám premenná pretečie (dostane sa na 256, nemožnú hodnotu, jej binárna hodnota bude 100000000, deviaty bit odpadne takže zostane 00000000), zresetuj jej hodnotu späť na 1
    arr = 1;
  }
  digitalWrite(LATCH, LOW);                 //Vypneme LATCH, nechceme nič vidieť kým shiftujeme dáta
  shiftOut(DATA, CLOCK, MSBFIRST, cislo);   //Vyshiftujeme hodnotu premennej "cislo"
  digitalWrite(LATCH, HIGH);                //Zapneme LATCH keďže chceme vidieť výsledok
  cislo += 1;                               //Pričítame k premennej "cislo" 1
  delay(1000);                              //Delay 1 sekunda
}
