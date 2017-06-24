#include <dht.h>
#include <SD.h>

#define SD_ChipSelectPin 4         //cs at 4

#include <TMRpcm.h>
#include <SPI.h>

dht DHT;

#define DHT11_dht 2               //sensor at 2

int chk=DHT.read11(DHT11_dht);
int temp=DHT.temperature;

TMRpcm tmrpcm;

 int redpin=6;
 int greenpin=7;
 int bluepin=8;
 
 void loop()
 { 
   Serial.begin(9600);  
   int chk=DHT.read11(DHT11_dht);
   int temp=DHT.temperature;
   Serial.println(DHT.temperature);
   pinMode(redpin,OUTPUT);
   pinMode(greenpin,OUTPUT);
   pinMode(bluepin,OUTPUT);
  
   Serial.println("led initialized"); 
   tmrpcm.speakerPin = 9;
   if (!SD.begin(4))
   {  
    Serial.println("SD is Fail");
    return;
   }
  else{
     Serial.println("SD is OK");
    }

 }


void setup()
{
    int chk=DHT.read11(DHT11_dht);
    int temp=DHT.temperature;

    Serial.println("Program starts");
    if(!tmrpcm.isPlaying())
       {
        digitalWrite(tmrpcm.speakerPin, LOW);
       }


   if(Serial.available())                               //if body open
       {
        char sData=Serial.read();
        Serial.println("DHT11 is ready to measure temp");
       if (temp<34 && temp>=32 && temp>27)                                            //if temp is bet 32 to 34 depression
         {   
             led_colour(80,0,80);
             delay(1000);
          
           int i=random(1,4);
             switch(i)
               {
                   case 1:  Serial.println("Depression mood is found");  
                            Serial.println("depa.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("depa");
                            break;
                  case 2:   Serial.println("Depression mood is found");  
                            Serial.println("depb.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("depb");
                            break;
                  case 3:   Serial.println("Depression mood is found");  
                            Serial.println("depc.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("depc");
                            break;
               
                 default:  break;
               }
           }

              
          
          else if(temp<37 && temp>=34)                                                               //temp bet 34 to 37 sadness
            {
               led_colour(0,255,0); 
               delay(1000);
             int i=random(1,4);
             switch(i)
               {
                   case 1:  Serial.println("Sadness mood is found");  
                            Serial.println("sada.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("sada");
                            break;
                  case 2:   Serial.println("Sadness mood is found");  
                            Serial.println("sadb.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("sadb");
                            break;
                  case 3:   Serial.println("Sadness mood is found");  
                            Serial.println("sadc.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("sadc");
                            break;
                  default:  break;
               }
            }


            

            else if(temp==37)                        //if temp is 37 normal
              {

                     led_colour(0,0,255);
                      delay(1000);
                 /* no song has to be placed*/

                
              }





          else if(temp>37 && temp<=39)                                            //if temp is 37 to 39 love
             { 
                led_colour(255,255,0);
                delay(1000);
             
             int i=random(1,4);
             switch(i)
               {
                   case 1:  Serial.println("Love mood is found");  
                            Serial.println("lova.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("lova");
                            break;
                  case 2:   Serial.println("Love mood is found");  
                            Serial.println("lovb.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("lovb");
                            break;
                  case 3:   Serial.println("Love mood is found");  
                            Serial.println("lovc.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("lovc");
                            break;
                  default:  break;
               }
             }



             
           else if(temp>39 && temp<=41)                                  //if temp is 39 to 41 anger
            {
               led_colour(255,0,0);
               delay(1000);                                  
              
             int i=random(1,4);
             switch(i)
               {
                   case 1:  Serial.println("Anger mood is found");  
                            Serial.println("anga.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("anga");
                            break;
                  case 2:   Serial.println("Anger mood is found");  
                            Serial.println("angb.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("angb");
                            break;
                  case 3:   Serial.println("Anger mood is found");  
                            Serial.println("angc.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("angc");
                            break;
                  default:  break;
               }
            }



            
            else if(temp>=42)   //if temp is 42 and above happiness
             {

              led_colour(0,255,255);                            //red colour
              delay(1000);
              int i=random(1,4);
             switch(i)
               {
                   case 1:  Serial.println("Happiness mood is found");  
                            Serial.println("hapa.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("hapa");
                            break;
                  case 2:   Serial.println("Happiness mood is found");  
                            Serial.println("hapb.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("hapb");
                            break;
                  case 3:   Serial.println("Happiness mood is found");  
                            Serial.println("hapc.wav");
                            tmrpcm.setVolume(6);
                            tmrpcm.play("hapc");
                            break;
                  default:  break;
               }                     //switch close
             }                       //else if close
       }                             //if close
 
 
 }



 void led_colour( int red,int green,int blue)
 {
  //# ifdef COMMON_ANODE
  //red = 255-red;
  //green = 255-green;
 // blue = 255-blue;

//  #endif
  analogWrite(redpin,red);
  analogWrite(greenpin,green);
  analogWrite(bluepin,blue);
  
 }

