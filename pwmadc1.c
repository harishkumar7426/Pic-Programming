  void main() {
  unsigned int adcValue;  // Declare ADC reading variable (0-1023)
  unsigned char duty;     // Declare PWM duty cycle variable (0-255)

  TRISC.F2 = 0;        // Set RC2 (CCP1) as output (PWM output)
  TRISA.F1 = 1;        // Set RA1 (AN1) as input (potentiometer input)

  ADC_Init();          // Initialize ADC
  PWM1_Init(5000);     // Initialize PWM at 5KHz
  PWM1_Start();        // Start PWM

  while(1) {
    adcValue = ADC_Read(1);   // Read from AN1

    if (adcValue <= 204)
      duty = (30 * 255) / 100;
    else if (adcValue <= 409)
      duty = (50 * 255) / 100;
    else if (adcValue <= 613)
      duty = (70 * 255) / 100;
    else if (adcValue <= 818)
      duty = (90 * 255) / 100;
    else
      duty = 255;

    PWM1_Set_Duty(duty);
    Delay_ms(100);
  }
}