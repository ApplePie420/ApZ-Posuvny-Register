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

void loop() {
  digitalWrite(LATCH, LOW);               //Vypneme LATCH, nechceme nič vidieť kým shiftujeme dáta
  shiftOut(DATA, CLOCK, MSBFIRST, 0x55);  //Vyshiftujeme 0x55 (10101010), bit s najväčšou váhou ako prvý (MSBFIRST)
  digitalWrite(LATCH, HIGH);              //Zapneme LATCH keďže chceme vidieť výsledok
  delay(1000);                            //Delay 1 sekunda
  digitalWrite(LATCH, LOW);               //Blok zopakujeme
  shiftOut(DATA, CLOCK, MSBFIRST, 0xAA);  //Vyshiftujeme 0xAA (01010101), čo je opak 0x55.
  digitalWrite(LATCH, HIGH);
  delay(1000);
}
