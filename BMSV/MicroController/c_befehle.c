/* Pin einlesen
   1. Data Register auf Input
   2. Wert in Variable schreiben
   n = Pin nummer
*/
// Gesamter Port
DDRA = 0x00;
var = PINA;
// Ein eizelner Pin wert
#define INPUT_MASK 0x01;
DDRA &= ~(1 << n);
var = (PINB >> n) & INPUT_MASK;

/* Wert auf Pin Ausschrieben
   1. Data Register auf Output
   2. Wert auf Port schreiben
*/
// Größerer Wert
DDRA = 0xFF;
PORTA = var;
// Einzelnes Bit -> Pin Einschalten

/* Pin Einschalten
   1. Data register auf Output
   2. Auf Port schreiben
   n = Pin nummer
*/
DDRA |= (1 << n);
PORTA |= (1 << n);

/* Pin Ausschalten
   1. Data Register auf Output
   2. Auf Port schreiben
   n = Pin nummer
   &= : Wert im Register überschreiben
   ~() : Invertieren
*/
DDRA |= (1 << n);
PORTA &= ~(1 << n);

/* Pin Togglen
   1. Data Register auf Output
   2. 1 auf Pin schreiben
   n = Pin nummer
*/
DDRA |= (1 << n);
PINA = (1 << n);

/* Pull Up einschalten
   1. Data Register auf Input // Bei interrupt bzw wenn davor nicht benutzt nix tun 
   2. 1 auf Port schreiben
   n = pin nummer
*/
DDRA &= ~(1 << n);
PORTA |= (1 << n);

/* Interrupt einschalten
   1. Setzten des Trigger Modus
   2. Einschalten des Interrupts
   3. Aktivieren aller Interrupts
   4. Interrupt Service Routine
*/
// Powerpoint folie 45
EICRA |= 0x0A;
// Powerpoint folie 46
EIMSK |= (1 << INT0);
sei();
ISR(INT0_vect)
{
}
