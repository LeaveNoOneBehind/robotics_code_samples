void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  // Скидання регістрів таймера 1
  TCCR1A = 0;
  TCCR1B = 0;

  TCCR1B |= (1 << WGM12);  // Увімкнення режиму Clear Timer on Compare Match
  TCCR1B |= (1 << CS12) | (1 << CS10); 

  
  OCR1A = 7812; 

  TIMSK1 |= (1 << OCIE1A); // Увімкнення генерації переривання по збігу з OCR1A
}

void loop() {
  
}

// Обробник переривання
ISR(TIMER1_COMPA_vect) {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
