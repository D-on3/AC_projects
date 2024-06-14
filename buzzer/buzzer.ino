// Define the piezo buzzer pin
#define PIEZO_PIN 8

// Define the notes and their corresponding frequencies
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880

#define NOTE_REST 0 // Use 0 for a rest

// Define the melody using the note frequencies
int melody[] = {
  NOTE_G5, NOTE_REST, NOTE_G5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_E5, NOTE_REST, NOTE_E5, NOTE_REST,
  NOTE_G5, NOTE_REST, NOTE_G5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_E5, NOTE_REST, NOTE_E5, NOTE_REST,
  NOTE_G5, NOTE_REST, NOTE_G5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_E5, NOTE_REST, NOTE_E5, NOTE_REST,
  NOTE_G5, NOTE_REST, NOTE_G5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_E5, NOTE_REST, NOTE_E5, NOTE_REST,
  NOTE_F5, NOTE_REST, NOTE_F5, NOTE_REST, NOTE_E5, NOTE_REST, NOTE_E5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_A5, NOTE_REST,
  NOTE_G5, NOTE_REST, NOTE_G5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_A5, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_B4, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_D5, NOTE_REST, NOTE_E5, NOTE_REST, NOTE_E5, NOTE_REST
};

// Define the note durations (in milliseconds)
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};

void setup() {
  // Set the piezo buzzer pin as an output
  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  // Iterate through the melody
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 1000 / noteDurations[i]; // Convert duration to time in milliseconds
    tone(PIEZO_PIN, melody[i], noteDuration); // Play the note
    delay(noteDuration * 1.30); // Delay between notes (add a bit extra for a better rhythm)
    noTone(PIEZO_PIN); // Stop the tone to avoid overlap
  }
}
