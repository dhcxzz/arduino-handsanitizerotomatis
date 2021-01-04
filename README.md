# arduino-handsanitizerotomatis
Program arduino sederhana untuk alat handsanitizer otomatis
# Mikon dan Sensor
Saat pembuatan alat menggunakan :
-Arduino nano
-Sensor Ultrasonik
-LED 
-Pompa celup
-Transistor TIP32
Adaptor DC 5 volt <br>
# Rangkaian
Gambar dinamo di bawah melambangkan pompa celup, dan transistor adalah TIP32
![Gambar Rangkaian](https://github.com/dhcxzz/arduino-handsanitizerotomatis/blob/main/rangkaian.png)
# Instalasi
1. Buat rangkaian
2. Unduh software [Arduino IDE](https://www.arduino.cc/en/software) atau bisa menggunakannya online
3. Masukan kodingan
4. Sesuaikan board dan port
5. Verify dan upload
# Catatan saat Proses Pembuatan
Dalam proses setup sensor ultrasonik dengan pompa, untuk menentukan jarak yang pas, dapat menambahkan serial print <br>
```arduino
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
```
dan inisiasi serial communication di setup
```arduino
// Starts the serial communication
Serial.begin(9600); 
```
sehingga menjadi seperti ini <br>
```arduino
void setup() {
  pinMode(PUMP,OUTPUT);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  
  // Starts the serial communication
  Serial.begin(9600); 
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(10);

  if(distance !=0 && distance<10)
  {
    digitalWrite(PUMP,LOW);
    delay(250);
    digitalWrite(PUMP,HIGH);
    delay(1200);
    }
    else
    {
     digitalWrite(PUMP,HIGH); 
  }
}
```
# Sumber
Ini merupakan alat yang dibuat untuk tugas saat 2020, penulis lupa darimana sumbernya, yang jelas kodingan ini tidak dari 0 dibangun oleh penulis,
bilamana ada yang tau, bisa kontak penulis untuk nantinya ditambahkan. Terima kasih semoga bermanfaat.
