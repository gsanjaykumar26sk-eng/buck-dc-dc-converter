// ============================================
// Buck DC-DC Converter — Gate Drive PWM
// 50kHz PWM using Arduino Timer1 (Pin 9)
// Author: Sanjay Kumar G (24BEE1256)
// VIT Chennai — BEEE301L Power Electronics
// ============================================

// Timer1 Fast PWM configuration for 50kHz on Pin 9
// Formula: f_PWM = f_clk / (prescaler × (ICR1 + 1))
// 50kHz = 16,000,000 / (1 × (319 + 1)) = 50,000 Hz ✓

void setup() {
  pinMode(9, OUTPUT);

  // Configure Timer1 for Fast PWM, TOP = ICR1
  TCCR1A = _BV(COM1A1)   // Non-inverting PWM on OC1A (pin 9)
         | _BV(WGM11);   // Fast PWM, part 1

  TCCR1B = _BV(WGM13)    // Fast PWM, part 2
         | _BV(WGM12)    // Fast PWM, part 3
         | _BV(CS10);    // No prescaler (clk/1)

  ICR1  = 319;   // TOP value → sets frequency to 50kHz
  OCR1A = 159;   // Compare match → 50% duty cycle (D = 0.5)

  Serial.begin(9600);
  Serial.println("50kHz PWM Gate Drive Active on Pin 9");
  Serial.print("Duty Cycle: ");
  Serial.print((float)OCR1A / ICR1 * 100);
  Serial.println("%");
}

void loop() {
  // Timer1 handles PWM autonomously — no loop code needed
  // To change duty cycle, update OCR1A:
  //   OCR1A = 0    → 0%  duty cycle
  //   OCR1A = 159  → 50% duty cycle (nominal)
  //   OCR1A = 319  → 100% duty cycle
}
