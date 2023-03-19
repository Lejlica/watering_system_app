#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

 

int RealyPin=D5;



//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

 


#define WIFI_SSID "Galaxy A22"
#define WIFI_PASSWORD "bdmh3918"




//#define API_KEY "AIzaSyBvPyGl-EHo4XkWEWxjQA-V_w8Qe02clqQ"
//#define DATABASE_URL "https://iotproject-38b75-default-rtdb.firebaseio.com"

 

///////////////////////////////////////////////////////////////////

 

#define API_KEY "AIzaSyBvPyGl-EHo4XkWEWxjQA-V_w8Qe02clqQ"
#define DATABASE_URL "https://iotproject-38b75-default-rtdb.firebaseio.com"


 int vr=A0;
 int sdata=0;

 

FirebaseData fbdo;

 

FirebaseAuth auth;
FirebaseConfig config;

 

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;

 

int intValue;
float floatValue;
String pumpaStatus;

 


                                  //===========================================SETUP=====================================================================\\

void setup(){
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

 

  /* Assign the api key (required) */
  config.api_key = API_KEY;

 

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

 

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

 

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

 

     
    pinMode(RealyPin, OUTPUT);
    pinMode(sdata,INPUT);
}

 

                                       //===========================================LOOP=====================================================================\\

 

void loop(){ 
 // sdata=analogRead(vr);
 // if(sdata>=9&&sdata<=450)
  //{
 // digitalWrite(RealyPin, HIGH);   // turn the LED on (HIGH is the voltage level)
   
 // Serial.print("Pumpa radi");// wait for a second
 
 //    Serial.print("Nivo vode:");
 //   Serial.println(sdata);
 // }
 // else if(sdata>450)
 // {
        // turn the LED off by making the voltage LOW
  
 //  Serial.println("Pumpa ne radi");// wait for a second
 // Serial.print("Nivo vode: ");
  //  Serial.println(sdata);
 //    digitalWrite(RealyPin, LOW); 
 //   }
 

  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();

//SET SENZOR
 
  
  
  //if (Firebase.RTDB.setInt(&fbdo, "/test/waterSensor/nivoVode",sdata)) {
  //     Serial.println("PASSED");
  // Serial.println("PATH: " + fbdo.dataPath());
  //   Serial.println("TYPE: " + fbdo.dataType());
    
  //   }
  //  else {
  //     Serial.println("FAILED");
  //    Serial.println("REASON: " + fbdo.errorReason());
 //  }



//SET PUMPA
//if (Firebase.RTDB.setString(&fbdo, "/test/stanjePumpe/pumpa","ON")) {
 //      Serial.println("PASSED");
 //    Serial.println("PATH: " + fbdo.dataPath());
//      Serial.println("TYPE: " + fbdo.dataType());
     
 //    }
 //    else {
 //      Serial.println("FAILED");
  //    Serial.println("REASON: " + fbdo.errorReason());
  //  }

 // }




                                           /////////////////////////////////////////////////////////////////////////////////GET metoda

 //GET SENZOR

//if (Firebase.RTDB.getInt(&fbdo, "/test/waterSensor/nivoVode")) {
 //     if (fbdo.dataType() == "int") {
 //       intValue= fbdo.intData();
 //      Serial.println(intValue);
     
  //   }
  //   else {
 //    Serial.println("FAILED");
  //    Serial.println("REASON: " + fbdo.errorReason());
  // }

  }
 
 
 if (Firebase.RTDB.getString(&fbdo, "/test/stanjePumpe/pumpa")) {
      if (fbdo.dataType() == "string") {
       pumpaStatus= fbdo.stringData();
       Serial.println(pumpaStatus);
     
     }
 }  

     if(pumpaStatus=="ON")
     {
      digitalWrite(RealyPin,HIGH);
     }
      else if(pumpaStatus=="OFF")
     {
      digitalWrite(RealyPin,LOW);
     }
     else{
      Serial.println("error");
     }
  
}
  
 



 
 
   

 
 
