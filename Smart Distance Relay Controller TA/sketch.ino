// Mendeklarasikan pin untuk relay dan sensor
const int relayPin = 23; // Pin GPIO untuk relay
const int trigPin = 25;  // Pin untuk Trig
const int echoPin = 26;  // Pin untuk Echo

void setup() {
  Serial.begin(115200);
  
  // Mengatur pin sebagai OUTPUT untuk relay dan INPUT untuk sensor
  pinMode(relayPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;

  // Mengatur Trigger untuk mengukur jarak
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Membaca durasi dari Echo
  duration = pulseIn(echoPin, HIGH);
  
  // Menghitung jarak (cm)
  distance = (duration * 0.0343) / 2; // Kecepatan suara 0.0343 cm/µs

  // Menampilkan jarak di Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Mengaktifkan relay jika jarak kurang dari 10 cm
  if (distance < 10) {
    digitalWrite(relayPin, HIGH); // Menyalakan relay
    Serial.println("Relay ON");
  } else {
    digitalWrite(relayPin, LOW); // Mematikan relay
    Serial.println("Relay OFF");
  }

  delay(1000); // Menunggu 1 detik sebelum pengukuran berikutnya


  // Logika untuk mengontrol relay
  if (distance < 50) { // Jika jarak kurang dari 50 cm
    digitalWrite(relayPin, HIGH); // Nyalakan relay
    Serial.println("Relay ON");
  } else {
    digitalWrite(relayPin, LOW); // Matikan relay
    Serial.println("Relay OFF");
  }

  delay(1000); // Menunggu 1 detik sebelum pengukuran berikutnya
}