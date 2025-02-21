int butonFonksiyon[4] = {0}; // Butona atanacak olan fonksiyonların tutulacağı dizi

bool atamaDurum = false;

void setup() {
  Serial.begin(9600);

  	for(int i = 2;i<11;i++){
    	pinMode(i,INPUT); // Dijital pinlere veri girişi yapılacak
  }

	Serial.println("Atama modunu aktif etmek icin ortadaki butona basiniz");
}

void loop() {
  if(digitalRead(10) == 1){
    atamaDurum = !atamaDurum;

    delay(200);

    if(atamaDurum == true){
      	Serial.println("Atama modu aktif.");
    	delay(1000);
      	Serial.println("Sag taraftaki atama yapmak istediginiz butona basiniz: ");
      
      	delay(1000);
    }else{
      Serial.println("Atama modu kapali.");
      Serial.println("Yapilan degisisklikler kaydedildi.");
    }
  }

  if(atamaDurum == true){ // Atanmak istenen butona basılıp değerinin girildiği bölüm
    for(int i = 6; i<10;i++){
      
      if(digitalRead(i) == 1){
        Serial.println("Atamak istediginiz degeri giriniz: ");
        while(Serial.available() == 0);
        
        butonFonksiyon[i-6] = Serial.parseInt();

        Serial.print("Yeni buton degeri: "); Serial.println(butonFonksiyon[i-6]);
        
        Serial.println("Atama islemine devam etmek icin atama islemi yapmak istediginiz butona basiniz.");
        Serial.println("Atama isleminden cikmak icin ortadaki butona basiniz");
      }
    }
  }else{ // Butonunlara basıldığında değerleri Serial monitöre yazdıran bölüm
    for(int i = 2;i<11;i++){
      if(i >5 && i <10){
        if(digitalRead(i) == 1){
          Serial.print("Buton deger: "); Serial.println(butonFonksiyon[i-6]);
          delay(100);
        }
    }else if(i > 1 && i < 6){
      if(digitalRead(i) == 1){
        switch(i){
          case 2:
            Serial.println("Ileri butonu aktif.");
            break;
          case 3:
            Serial.println("Sol butonu aktif.");
            break;
          case 4:
            Serial.println("Geri butonu aktif.");
            break;
          case 5:
            Serial.println("Sag butonu aktif.");
            break;
          default: 
            Serial.println("Bir seyler ters gitti...");
            break;
        }
      }
    }
  }
}

}
