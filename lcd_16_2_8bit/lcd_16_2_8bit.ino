
// Pin definitions
#define RS  11
#define EN  10
#define D0  2 
#define D1  3
#define D2  4
#define D3  5
#define D4  6
#define D5  7
#define D6  8
#define D7  9
// Function prototypes
void lcd_enable(void);
void lcd_cmd(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_init(void);
void lcd_string(char *ptr);
void setup() {
  // Configure pins as outputs
  for(int i = 2; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  lcd_init(); // Initialize LCD
}
void loop() {
  lcd_cmd(0x80);              // Move cursor to first line, first position
  lcd_string("Jayavardhan");  // Print string
  while(1);                   // Stop repeating
}
// Send a command to LCD
void lcd_cmd(uint8_t cmd) {
  digitalWrite(RS, LOW); // Command mode
  for(int i = 0; i < 8; i++) {
    digitalWrite(D0+i, (cmd >> i) & 0x01);
  }
  lcd_enable();
}
// Send data (character) to LCD
void lcd_data(uint8_t data) {
  digitalWrite(RS, HIGH); // Data mode
  for(int i = 0; i < 8; i++) {
    digitalWrite(D0+i, (data >> i) & 0x01);
  }
  lcd_enable();
}
// Pulse the Enable pin to latch data/command
void lcd_enable(void) {
  digitalWrite(EN, HIGH);
  delayMicroseconds(2);
  digitalWrite(EN, LOW);
  delay(2);
}
// Initialize LCD with standard settings
void lcd_init(void) {
  delay(20);        // Wait for LCD power up
  lcd_cmd(0x38);    // 8-bit, 2 line, 5x7 dots
  lcd_cmd(0x0C);    // Display ON, cursor OFF
  lcd_cmd(0x06);    // Entry mode: auto-increment
  lcd_cmd(0x01);    // Clear display
  delay(2);
}
// Print a string to LCD
void lcd_string(char *ptr) {
  while(*ptr) {
    lcd_data(*ptr++);
  }
}
