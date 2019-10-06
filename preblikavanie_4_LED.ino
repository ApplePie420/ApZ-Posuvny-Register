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
digitalWrite(LATCH, LOW);                     //Vypneme LATCH, nechceme nič vidieť kým shiftujeme dáta
shiftOut(DATA, CLOCK, MSBFIRST, B00001111);   //Vyshiftujeme binárnu hodnotu, kde posledné 4 LEDky sú zapnuté ("1")
digitalWrite(LATCH, HIGH);                    //Zapneme LATCH keďže chceme vidieť výsledok
delay(1000);                                  //Delay 1 sekunda
digitalWrite(LATCH, LOW);                     //Kód zopakujeme
shiftOut(DATA, CLOCK, MSBFIRST, B11110000);   //Akurát miesto posledných 4 LEDiek rozsvietime prvé 4
digitalWrite(LATCH, HIGH);
delay(1000);
}
