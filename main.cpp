#define ANALOG A0
//=============functions prototypes===========//
// Auxiliar==============//
void settingUpPins();
void turnOffAllLayers();
void turnOnAllLayers();
void turnOffAllColumns();
void turnOnSequencialLayers();

//===============Effects//
void sequencial();
void randLights();
void pet();
void propeller();
void propellerPair();
void gradualLighUp();

//=====================setup==================//
void setup() {
  settingUpPins();
  turnOffAllLayers();
  randomSeed(analogRead(ANALOG));
}

//======================loop==================//
void loop() {
  sequencial();
  delay(500);
  randLights();
  delay(500);
  pet();
  delay(500);
  propeller();
  delay(100);
  propellerPair();
  delay(200);
  gradualLighUp();
  delay(200);
}

//==========Auxiliar functions=============//
void turnOffAllLayers() {
  for (int x = 9; x <= 11; x++) {
    digitalWrite(x, HIGH);
  }
}

void turnOnAllLayers() {
  for (int x = 9; x <= 11; x++) {
    digitalWrite(x, LOW);
  }
}

void turnOffAllColumns() {
  for (int x = 0; x < 9; x++) {
    digitalWrite(x, LOW);
  }
}

void settingUpPins() {
  for (int x = 0; x <= 11; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(ANALOG, INPUT);
}

void turnOnSequencialLayers() {
  for (int x = 9; x < 12; x++) {
    digitalWrite(x, LOW);
    delay(250);
    digitalWrite(x, HIGH);
  }
}

//===================Effects==================//
void sequencial() {
  for (int l = 9; l < 12; l++) {
    // Activating layer
    digitalWrite(l, LOW);

    for (int c = 0; c < 9; c++) {
      digitalWrite(c, HIGH);
      delay(100);
      digitalWrite(c, LOW);
    }

    // Deactvating layer
    digitalWrite(l, HIGH);
  }
}

//========================================//
void randLights() {
  int randColumn = 0;
  int randLayer = 0;

  for (int x = 0; x <= 33; x++) {
    randColumn = random(0, 9);
    randLayer = random(9, 12);

    digitalWrite(randColumn, HIGH);
    digitalWrite(randLayer, LOW);
    delay(100);

    digitalWrite(randColumn, LOW);
    digitalWrite(randLayer, HIGH);
    delay(100);
  }
}

//========================================//
void pet() {
  int p[7] = {0, 1, 2, 3, 4, 5, 6};
  int e[8] = {0, 1, 2, 3, 4, 6, 7, 8};
  int t[5] = {0, 1, 2, 4, 7};

  for (int x = 0; x <= sizeof(p) / 2; x++) {
    digitalWrite(p[x], HIGH);
  }

  turnOnSequencialLayers();
  delay(250);
  turnOffAllColumns();

  for (int x = 0; x < sizeof(e) / 2; x++) {
    digitalWrite(e[x], HIGH);
  }

  turnOnSequencialLayers();
  delay(250);
  turnOffAllColumns();

  for (int x = 0; x < sizeof(t) / 2; x++) {
    digitalWrite(t[x], HIGH);
  }

  turnOnSequencialLayers();
  delay(250);
  turnOffAllColumns();
}

//========================================//
void propeller() {
  int center = 4;
  int columns[8] = {0, 1, 2, 5, 8, 7, 6, 3};

  turnOnAllLayers();
  digitalWrite(center, HIGH);

  for (int x = 0; x < sizeof(columns) / 2; x++) {
    digitalWrite(columns[x], HIGH);
    delay(200);
    digitalWrite(columns[x], LOW);
  }
  turnOffAllLayers();
  digitalWrite(center, LOW);
}

//========================================//
void propellerPair() {
  int pairs[4][2] = {{0, 8}, {1, 7}, {2, 6}, {3, 5}};

  int l = 9;
  for (int x = 0; x <= 6; x++) {
    if (x % 2 == 0) {
      digitalWrite(l, LOW);
      l++;
    }
    for (int y = 0; y < 4; y++) {
      digitalWrite(pairs[y][0], HIGH);
      digitalWrite(pairs[y][1], HIGH);
      delay(200);
      digitalWrite(pairs[y][0], LOW);
      digitalWrite(pairs[y][1], LOW);
    }
  }
  turnOffAllLayers();
}

//========================================//
void gradualLighUp() {
  turnOnAllLayers();
  for (int x = 0; x < 9; x++) {
    digitalWrite(x, HIGH);
    delay(200);
  }
  for (int x = 0; x < 9; x++) {
    digitalWrite(x, LOW);
    delay(200);
  }
  turnOffAllLayers();
}
