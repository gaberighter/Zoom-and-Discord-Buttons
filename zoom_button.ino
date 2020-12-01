const int switchPin1 = D1;
const int switchPin2 = D2;
const int switchPin3 = D3;
const int ledPin1 = D4;
const int ledPin2 = D0;

int switchState1 = 0;
int switchState2 = 0;
int switchState3 = 0;

STARTUP(Keyboard.begin());

void zoomMute(){
    Keyboard.press(KEY_LCTRL);
    Keyboard.press(KEY_LALT);
    Keyboard.press(KEY_LSHIFT);
    Keyboard.releaseAll();
    Keyboard.press(KEY_LALT);
    Keyboard.press(KEY_A);
    Keyboard.releaseAll();
}

void discordMute(){
    Keyboard.press(KEY_RCTRL);
    Keyboard.press(KEY_LALT);
    Keyboard.releaseAll();
}

void discordDeafen(){
    Keyboard.press(KEY_RCTRL);
    Keyboard.press(KEY_RALT);
    Keyboard.releaseAll();
}

void setup() {
  Serial.begin(9600);
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2, HIGH);
}

void loop() {
  switchState1 = digitalRead(switchPin1);
switchState2 = digitalRead(switchPin2);
switchState3 = digitalRead(switchPin3);

if(switchState1 == HIGH){
    Serial.println("button 1 pressed");
    digitalWrite(ledPin1, HIGH);
    zoomMute();
    Serial.println("muted zoom");
    delay(500);
  }else{
  digitalWrite(ledPin1, LOW);
  }

if(switchState2 == HIGH){
    Serial.println("button 2 pressed");
    digitalWrite(ledPin1, HIGH);
    discordMute();
    Serial.println("discord muted");
    delay(500);
  }else{
  digitalWrite(ledPin1, LOW);
  }

  if(switchState3 == HIGH){
    Serial.println("button 3 pressed");
    digitalWrite(ledPin1, HIGH);
    discordDeafen();
    Serial.println("discord deafened");
    delay(500);
  }else{
  digitalWrite(ledPin1, LOW);
  }
}
