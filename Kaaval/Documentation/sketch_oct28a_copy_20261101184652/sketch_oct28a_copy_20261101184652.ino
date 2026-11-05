#include <Adafruit_Fingerprint.h>

#define FINGER_RX_PIN 16
#define FINGER_TX_PIN 17

HardwareSerial fingerSerial(2);
Adafruit_Fingerprint finger(&fingerSerial);

// Student mapping
struct Student {
  uint16_t fingerprintID;
  const char* studentID;
};

Student students[] = {
  {1, "STU001"},
  {2, "STU002"},
  {3, "STU003"},
  {4, "STU004"}
};

const int STUDENT_COUNT =
  sizeof(students) / sizeof(students[0]);

// Attendance event structure
struct AttendanceEvent {
  char eventID[20];
  char studentID[20];
  uint16_t fingerprintID;
  char status[12];
  bool synced;
};

uint32_t eventCounter = 1;

// Find student
const char* findStudent(uint16_t fingerprintID) {
  for (int i = 0; i < STUDENT_COUNT; i++) {
    if (students[i].fingerprintID == fingerprintID) {
      return students[i].studentID;
    }
  }
  return nullptr;
}

// Create attendance event
void createAttendanceEvent(uint16_t fingerprintID,
                           const char* studentID) {

  AttendanceEvent event;

  snprintf(event.eventID, sizeof(event.eventID),
           "KVL-%06lu",
           (unsigned long)eventCounter++);

  snprintf(event.studentID, sizeof(event.studentID),
           "%s", studentID);

  event.fingerprintID = fingerprintID;

  snprintf(event.status, sizeof(event.status),
           "PRESENT");

  event.synced = false;

  Serial.println();
  Serial.println("===== KAAVAL ATTENDANCE EVENT =====");

  Serial.print("Event ID: ");
  Serial.println(event.eventID);

  Serial.print("Student ID: ");
  Serial.println(event.studentID);

  Serial.print("Fingerprint ID: ");
  Serial.println(event.fingerprintID);

  Serial.print("Status: ");
  Serial.println(event.status);

  Serial.print("Synced: ");
  Serial.println(event.synced ? "YES" : "NO");

  Serial.println("EVENT CREATED SUCCESSFULLY");
  Serial.println("==================================");
  Serial.println();
}

// Wait until finger is removed
void waitForFingerRemoval() {
  Serial.println("Remove finger from sensor");

  while (true) {
    uint8_t p = finger.getImage();

    if (p == FINGERPRINT_NOFINGER) {
      break;
    }

    delay(100);
  }

  Serial.println("Ready for next scan");
}

void setup() {
  Serial.begin(115200);

  fingerSerial.begin(
    57600,
    SERIAL_8N1,
    FINGER_RX_PIN,
    FINGER_TX_PIN
  );

  finger.begin(57600);

  if (!finger.verifyPassword()) {
    Serial.println("R307 NOT FOUND");

    while (1) {
      delay(100);
    }
  }

  Serial.println("KAAVAL STEP 42");
  Serial.println("R307 READY");
  Serial.println("Waiting for fingerprint...");
}

void loop() {
  uint8_t p = finger.getImage();

  if (p == FINGERPRINT_NOFINGER) {
    delay(100);
    return;
  }

  if (p != FINGERPRINT_OK) {
    Serial.println("IMAGE CAPTURE ERROR");
    delay(500);
    return;
  }

  p = finger.image2Tz();

  if (p != FINGERPRINT_OK) {
    Serial.println("IMAGE CONVERSION ERROR");
    waitForFingerRemoval();
    return;
  }

  p = finger.fingerSearch();

  if (p == FINGERPRINT_OK) {
    Serial.println("FINGERPRINT MATCH FOUND");

    Serial.print("Fingerprint ID: ");
    Serial.println(finger.fingerID);

    const char* student =
      findStudent(finger.fingerID);

    if (student != nullptr) {
      createAttendanceEvent(finger.fingerID, student);
    } else {
      Serial.println("STUDENT ID NOT REGISTERED");
    }

  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("UNKNOWN FINGERPRINT");

  } else {
    Serial.println("FINGERPRINT SEARCH ERROR");
  }

  waitForFingerRemoval();
}