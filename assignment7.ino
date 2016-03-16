#include <Smartcar.h>

Odometer encoderLeft(93), encoderRight(93); //Βάλτε τους δικούς σας παλμούς ανά μέτρο
Gyroscope gyro(18); //Βάλτε την τιμή του γυροσκόπιού σας
Car folkracer;
boolean state1Done = false;
boolean state2Done = false;

void setup() {
  gyro.attach();
  encoderLeft.attach(3); //Χρησιμοποιήστε τα σωστά pins!
  encoderRight.attach(2);
  encoderLeft.begin();
  encoderRight.begin();
  gyro.begin();
  folkracer.begin(encoderLeft, encoderRight, gyro);
  folkracer.enableCruiseControl();
  folkracer.setSpeed(0.5);
}

void loop() {
  folkracer.updateMotors();
  unsigned long distance = encoderLeft.getDistance();
  distance = distance + encoderRight.getDistance();
  if (distance > 20) {
    if (distance < 30) {
      if (state1Done == false) {
        folkracer.stop();
        folkracer.rotate(180);
        folkracer.setSpeed(0.5);
        state1Done = true;
      }
    }
  }
  //TO-DO
  //Όταν το αυτοκινητάκι έχει διανύσει από 80 μέχρι 90 εκατοστά, τότε σταματήστε το και μετά περιστρέψτε το κατά 90 μοίρες
  //στα δεξιά. Στη συνέχεια, θέστε ταχύτητα 0.5 μέτρα το δευτερόλεπτο
  
  //TO-DO
  //Όταν το αυτοκινητάκι έχει διανύσει απόσταση μεγαλύτερη των 150 εκατοστών, τότε πείτε του να σταματήσει (ή εναλλακτικά θέστε
  //ταχύτητα μηδέν)
}