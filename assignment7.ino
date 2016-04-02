/* Διαβάστε τον κώδικα, προσπαθήστε να καταλάβετε τι κάνει από μόνοι σας (σκοπίμως δεν έχουν μπει σχόλια που να εξηγούν
τι κάνουν οι διάφορες εντολές) και μετά γράψτε μόνοι σας το υπόλοιπο πρόγραμμα με τις οδηγίες που θα βρείτε στα σχόλια.
Χρησιμοποιήστε της μεταβλητές αληθείας (boolean) ώστε οι εντολές της κάθε κατάστασης (state) να εκτελούνται μόνο μια φορά.
Ο σκοπός σας είναι, να τελειώσετε το πρόγραμμα στο σπίτι και όταν το δοκιμάσετε στο αμαξάκι, το αμαξάκι να επιδείξει
την εξής συμπεριφορά:
Θα προχωρήσει περίπου 20 εκατοστά και θα στρίψει 180 μοίρες (αυτό είναι ήδη έτοιμο για εσάς).
Θα προχωρήσει ΕΠΙΠΛΕΟΝ περίπου 60 εκατοστά (δηλαδή πόσα απ' την αρχή της λειτουργίας του;) και θα στρίψει 90 μοίρες προς
τα αριστερά...
Τέλος, θα συνεχίσει να κινείται ευθεία, μέχρι να διανύσει συνολικά (από την αρχή δηλαδή της λειτουργίας του) 150 εκατοστά. */
#include <Smartcar.h>

Odometer encoderLeft(93), encoderRight(93); //Βάλτε τους δικούς σας παλμούς ανά μέτρο
Gyroscope gyro(18); //Βάλτε την κατάλληλη τιμή σύμφωνα με το γυροσκόπιό σας
Car folkracer;//Το όνομα του αυτοκινήτου
boolean state1Done = false;//Η κατάσταση του 1Done είναι false(0)
boolean state2Done = false;//Η κατάσταση του 2Done είναι false(0)

void setup() {
  gyro.attach(18);//sundeoumai to guroskopio
  encoderLeft.attach(3); //sundeoumai to aristero encoder
  encoderRight.attach(2);//?
  encoderLeft.begin(93);//?
  encoderRight.begin(93);//?
  gyro.begin(18);//?
  folkracer.begin(encoderLeft, encoderRight, gyro);//το αμάξι λειτουργεί με τα encoderLeft, encoderRight, gyro
  folkracer.enableCruiseControl();//?
  folkracer.setSpeed(0.5);//το αμάξι έχει ταχύτητα 0,5
}

void loop() {
  folkracer.updateMotors();//?
  unsigned long distance = encoderLeft.getDistance();//?
  distance = distance + encoderRight.getDistance();//?
  distance = distance / 2;
  if (distance > 20) {//εαν η απόσταση που εχει διανυσει είναι >20
    if (distance < 30) {//εαν η απόσταση εχει διανυσει είναι <30 τότε:
      if (state1Done == false) {//εαν το 1Done είναι false(0) 
        folkracer.stop();//Το αμάξι σταματάει
        folkracer.rotate(180);//το αμάξι στριβει 180 μοίρες
        folkracer.setSpeed(0.5);//το αμάξι εχει ταχύτητα 0,5
        state1Done = true;//το 1Done ειναι true(1)
      }
    }
  }
  //TO-DO
  if(distance==80||90){ //an h apostash einai 80 h 90 kane kati
   folkracer.stop(); //to amaxi tha stamatisei
   folkracer.rotate(90); //to amaxi tha stripsei 90 moires
   folkracer.setSpeed(0,5); //h taxithta pou tha proxoraei to amaxi
  }
  //Όταν το αυτοκινητάκι έχει διανύσει από 80 μέχρι 90 εκατοστά, τότε σταματήστε το και μετά περιστρέψτε το κατά 90 μοίρες
  //στα δεξιά. Στη συνέχεια, θέστε ταχύτητα 0.5 μέτρα το δευτερόλεπτο
  
  //TO-DO
  if(distance >150){
   folkracer.stop()
   state2Done=true;
  }
  //Όταν το αυτοκινητάκι έχει διανύσει απόσταση μεγαλύτερη των 150 εκατοστών, τότε πείτε του να σταματήσει (ή εναλλακτικά θέστε       
  //ταχύτητα μηδέν)
}
