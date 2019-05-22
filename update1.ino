//enrol A, Delete D , Up B

#include <Adafruit_Fingerprint.h>
#include <Keypad.h>
#include<EEPROM.h>
#include<LiquidCrystal.h>
#define RS  9
#define EN  8
#define D4  13
#define D5  12
#define D6  11
#define D7  10
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
#include <SoftwareSerial.h>
SoftwareSerial gsm(A0,A1);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial);

char user1_pin[]="1234";
char user2_pin[]="5678";
char user3_pin[]="4321";
char user4_pin[]="8765";
char u1_name[]="Samuel";
char u2_name[]="Olajide";
char u3_name[]="Tunde";
char u4_name[]="James";
char u1_number[]="\"+2347037350226\"\r";
char u2_number[]="\"+2348124578253\"\r";
char user1_chk[4];
char user2_chk[4];
char *otp;
int i;
int randNumber;
int OTP;
char otp_toSend[5];
int t;
String con_val;
uint8_t id;
char otp_[]="    ";
 int p,q;

void checkKeys();
void Enroll();
void delet();

void sendSMS(char *txt, char *number){
      gsm.print("AT+CMGF=1\r"); delay(100);
      gsm.print("AT+CMGS=");
     // \"+2347037350226\"\r");delay(100);
      gsm.println(number);delay(100);
      gsm.print(txt);
      gsm.println(" is your OTP");
      gsm.print(char(26));  //ctrl z
      delay(100); 
  }




const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {3, 2, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() 
{
  
    lcd.begin(16,2);
    lcd.setCursor(1,0);
    lcd.print("Enhanced ATM");
    lcd.setCursor(0,1);
    lcd.print(" Authentication ");
    delay(6000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" using F_Print. ");
    lcd.setCursor(5,1);
    lcd.print("and OTP");
    delay(7000);
    Serial.begin(57600);
    gsm.begin(9600);
    lcd.clear();
    lcd.print("Finding Module");
    lcd.setCursor(0,1);
    delay(1000);
    if (finger.verifyPassword()) 
    {
      //Serial.println("Found fingerprint sensor!");
      lcd.clear();
      lcd.print("Found Module ");
      delay(2000);
    } 
    else 
    {
    //Serial.println("Did not find fingerprint sensor :(");
    lcd.clear();
    lcd.print("module not Found");
    lcd.setCursor(0,1);
    lcd.print("Check Connections");
    while (1);
    }
    lcd.clear();
    randomSeed(analogRead(0)+1512);
}

void loop() 
{
    

    lcd.print("  Insert Card  ");

     checkKeys();
     lcd.clear();
     //delay(10);
}











void checkKeys()
{ 
   char customKey = customKeypad.getKey();
   while (!customKey){customKey = customKeypad.getKey();}
   if (customKey){

    switch (customKey){

  //////////////////////////#//////////////////////////////////    
      case '#':{
        
        lcd.setCursor(0,0);
          lcd.print(" Enter Acc Mode ");
          lcd.setCursor(0,1);
          lcd.print("Mode 1 or Mode 2");
        
           char customKey = customKeypad.getKey();
           while (!customKey){customKey = customKeypad.getKey();}
           if (customKey){
        
            switch (customKey){
               
                                            //////////////////////  1  ///////////////////////////////     
                                    case '1':  
                                    lcd.clear();
                                  lcd.print("Enter pin");
                                    for( i =0; i<=3; i++){
                                     char customKey = customKeypad.getKey();
                                        while (!customKey){customKey = customKeypad.getKey();}
                                      user1_chk[i]=customKey;
                                      lcd.setCursor(i,1);
                                         lcd.print('*');
                                      }
                                              if(user1_pin[0]==user1_chk[0] && user1_pin[1]==user1_chk[1]
                                               && user1_pin[1]==user1_chk[1] && user1_pin[2]==user1_chk[2]
                                               && user1_pin[3]==user1_chk[3]){
                                                
                                               for(int i=0;i<=3;i++)
                                              {
                                                 lcd.clear();
                                                 lcd.setCursor(0,0);
                                                 lcd.print("Welcome ");lcd.print(u1_name);
                                                 lcd.setCursor(2,1);
                                                lcd.print("Place Finger");
                                                delay(4000);
                                                int result=getFingerprintIDez();
                                                
                                                if(result==0||result==1){    //user samuel finger in id 0
                                                  lcd.clear();
                                                  lcd.setCursor(0,1);
                                                  lcd.print("Success");
                                                  delay(4000);
                                                  return;
                                                  }
                                      
                                                  else {
                                                  lcd.setCursor(0,1);
                                                  lcd.print("Finger not match");delay(1000);
                                                  }
                                                 }
                                                
                                                }
                                                //////////////////////////////////////////////////
                                                
                                                else if(user2_pin[0]==user1_chk[0] && user2_pin[1]==user1_chk[1]
                                               && user2_pin[1]==user1_chk[1] && user2_pin[2]==user1_chk[2]
                                               && user2_pin[3]==user1_chk[3]){
                                                
                                               for(int i=0;i<=3;i++)
                                              {
                                                 lcd.clear();
                                                 lcd.setCursor(0,0);
                                                 lcd.print("Welcome ");lcd.print(u2_name);
                                                 lcd.setCursor(2,1);
                                                lcd.print("Place Finger");
                                                delay(4000);
                                                int result=getFingerprintIDez();
                                                if(result==2||result==3){  ///olajide finger in id 1
                                                  lcd.clear();
                                                  lcd.setCursor(0,1);
                                                  lcd.print("Success");
                                                  delay(4000);
                                                  return;
                                                  }
                                      
                                                  else {
                                                  lcd.setCursor(0,1);
                                                  lcd.print("Finger not match");delay(1000);
                                                  }
                                                 }
                                                
                                                }
                                          //////////////////////////////////////////// 
                                          
                                                else if(user3_pin[0]==user1_chk[0] && user3_pin[1]==user1_chk[1]
                                               && user3_pin[1]==user1_chk[1] && user3_pin[2]==user1_chk[2]
                                               && user3_pin[3]==user1_chk[3]){
                                                
                                               for(int i=0;i<=3;i++)
                                              {
                                                 lcd.clear();
                                                 lcd.setCursor(0,0);
                                                 lcd.print("Welcome ");lcd.print(u3_name);
                                                 lcd.setCursor(2,1);
                                                lcd.print("Place Finger");
                                                delay(4000);
                                                int result=getFingerprintIDez();
                                                if(result==4||result==5){  ///Tunde finger in id 2
                                                  lcd.clear();
                                                  lcd.setCursor(0,1);
                                                  lcd.print("Success");
                                                  delay(4000);
                                                  return;
                                                  }
                                      
                                                  else {
                                                  lcd.setCursor(0,1);
                                                  lcd.print("Finger not match");delay(1000);
                                                  }
                                                 }
                                                
                                                }
                                          ////////////////////////////////////////////    
                                          
                                                else if(user4_pin[0]==user1_chk[0] && user4_pin[1]==user1_chk[1]
                                               && user4_pin[1]==user1_chk[1] && user4_pin[2]==user1_chk[2]
                                               && user4_pin[3]==user1_chk[3]){
                                                
                                               for(int i=0;i<=3;i++)
                                              {
                                                 lcd.clear();
                                                 lcd.setCursor(0,0);
                                                 lcd.print("Welcome ");lcd.print(u4_name);
                                                 lcd.setCursor(2,1);
                                                lcd.print("Place Finger");
                                                delay(4000);
                                                int result=getFingerprintIDez();
                                                if(result==6||result==7){  ///olajide finger in id 1
                                                  lcd.clear();
                                                  lcd.setCursor(0,1);
                                                  lcd.print("Success");
                                                  delay(4000);
                                                  return;
                                                  }
                                      
                                                  else {
                                                  lcd.setCursor(0,1);
                                                  lcd.print("Finger not match");delay(1000);
                                                  }
                                                 }
                                                
                                                }
                                          //////////////////////////////////////////// 
                                        else
                                        {
                                          lcd.clear();
                                          lcd.setCursor(0,1);
                                          lcd.print("Wrong pin");delay(4000);
                                          lcd.clear();
                                          break;
                                          }
                                       delay(1000);
                                      break;
                              ////////////////////////////  2 //////////////////////////////    
                                case '2':
                                    lcd.clear();
                                  lcd.print("Enter pin");
                                
                                    for(i =0; i<=3; i++){
                                       char customKey = customKeypad.getKey();
                                        while (!customKey){customKey = customKeypad.getKey();}
                                      user2_chk[i]=customKey;
                                        lcd.setCursor(i,1);
                                         lcd.print("*");
                                      }
                                   if(user2_pin[0]==user2_chk[0] && user2_pin[1]==user2_chk[1]
                                       && user2_pin[1]==user2_chk[1] && user2_pin[2]==user2_chk[2]
                                       && user2_pin[3]==user2_chk[3])
                                    {
                              
                                        randNumber=random(1500,6000);
                                        OTP=randNumber;
                                        //sprintf(otp_toSend,"%04i",OTP);
                                        con_val=String(OTP);
                                        con_val.toCharArray(otp_toSend,5);
                                        otp_[0]=otp_toSend[0];otp_[1]=otp_toSend[1];otp_[2]=otp_toSend[2];otp_[3]=otp_toSend[3];
                                        sendSMS(otp_toSend,u2_number);delay(2000);
                                        //t=millis();
                                        //while(t < (t+60000))  //OTP valid for 1min
                                       
                                        q=0;
                                        for (p=0; p<=2; p++)
                                        {
                                          lcd.clear();
                                                 lcd.setCursor(0,0);
                                                 lcd.print("Welcome ");lcd.print(u2_name);
                                          lcd.setCursor(0,1);
                                          lcd.print("Enter OTP ");
                                              for(i =0; i<=3; i++){
                                               char customKey = customKeypad.getKey();
                                                while (!customKey){customKey = customKeypad.getKey();
                                                                        q++; delay(100); if(q>=600){q=0;goto nsr;} }//600 count is approximately 1min
                                                 user2_chk[i]=customKey;
                                                 lcd.setCursor(i+10,1);
                                                 lcd.print("*");
                                                }
                                         
                                          if(user2_chk[0]==otp_[0] && user2_chk[1]==otp_[1] &&
                                          user2_chk[2]==otp_[2] && user2_chk[3]==otp_[3]){
                                                lcd.setCursor(0,1);
                                                lcd.print("Success        ");delay(4000);
                                                return;
                                             }
                                             else
                                             {
                                               
                                                lcd.setCursor(0,1);
                                                lcd.print("Wrong OTP       ");delay(1000);
                                                lcd.clear();
                                               
                                             }
                                              delay(1000);
                                              q++;
                                              if (q>=600){
                                                q=0;
                     
                                                goto nsr;
                                                }
                                        
                                          }
                                           nsr: {
                                            
                                            
                                            lcd.clear();
                                                lcd.setCursor(0,0);
                                                lcd.print("OTP time out!!!");
                                                delay(1000);
                                            } 
                                           break;
                                   
                                      } ///first password ends here
                              
                                 else if(user1_pin[0]==user2_chk[0] && user1_pin[1]==user2_chk[1]
                                       && user1_pin[1]==user2_chk[1] && user1_pin[2]==user2_chk[2]
                                       && user1_pin[3]==user2_chk[3])
                                    {
                              
                                        randNumber=random(1500,6000);
                                        OTP=randNumber;
                                        //sprintf(otp_toSend,"%04i",OTP);
                                        con_val=String(OTP);
                                        con_val.toCharArray(otp_toSend,5);
                                        otp_[0]=otp_toSend[0];otp_[1]=otp_toSend[1];otp_[2]=otp_toSend[2];otp_[3]=otp_toSend[3];
                                        sendSMS(otp_toSend,u1_number);
                                         q=0;
                                        for (p=0; p<=3; p++)  
                                        {
                                          lcd.clear();
                                                 lcd.setCursor(0,0);
                                                 lcd.print("Welcome ");lcd.print(u1_name);
                                          lcd.setCursor(0,1);
                                          lcd.print("Enter OTP ");
                                                for(i =0; i<=3; i++){
                                                 char customKey = customKeypad.getKey();
                                                  while (!customKey){
                                                                   customKey = customKeypad.getKey();
                                                                  q++; delay(100); if(q>=600){q=0;goto nsp;} 
                                                                  }
                                                   user2_chk[i]=customKey;
                                                   lcd.setCursor(i+10,1);
                                                   lcd.print("*");
                                                 }
                                          if(user2_chk[0]==otp_[0] && user2_chk[1]==otp_[1] &&
                                          user2_chk[2]==otp_[2] &&user2_chk[3]==otp_[3]){
                                                lcd.setCursor(0,1);
                                                lcd.print("Success        "); delay(4000);
                                                return;
                                             }
                                             else
                                             {
                                               
                                                lcd.setCursor(0,1);
                                                lcd.print("Wrong OTP       ");delay(1000);
                                                lcd.clear();
                                               
                                             }
                                              delay(1000);
                                              q++;
                                              if (q>=600){
                                                q=0;
                                                
                                                goto nsp;
                                                }
                                         }
                                         nsp: {
                                         
                                            lcd.clear();
                                                lcd.setCursor(0,0);
                                                lcd.print("OTP time out!!!");
                                                delay(1000);
                                            } 
                                         break;
                                 
                                      } 
                              
                              
                                      
                                         break;
                              
                                            
                                            }

              
            }
        
        
        
        }
        break;      


//////////////////////////////////////////////////////////////////


///////////////////////// A  ////////////////////////////////
      case 'A': 
      lcd.clear();
          lcd.print("Please Wait");
          delay(1000);
          Enroll();
          lcd.clear();
          break;
      

 //////////////////////////  D  /////////////////////////////////          
     case 'D': 
     lcd.clear();
          lcd.print("Please Wait");
          delay(1000);
          delet();
          lcd.clear();;break;
  default:  break;
      
      }
   

  
   }
  
   
        
     
}

void Enroll()
{
   int count=0;
   lcd.clear();
   lcd.print("Enroll Finger    ");
   lcd.setCursor(0,1);
   lcd.print("Location:");
   while(1)
   {
     lcd.setCursor(9,1);
     lcd.print(count);
    char customKey = customKeypad.getKey();
     switch (customKey){

     case 'B':
       count++;
       if(count>25)
       count=0;
       delay(500);  break;
     

     case 'D':
          id=count;
          getFingerprintEnroll();
          return;
     break;

      case 'A':
           
          return;break;
     
   default: ;
  }
     delay(50);
 }
   
}

void delet()
{
   int count=0;
   lcd.clear();
   lcd.print("Delete Finger    ");
   lcd.setCursor(0,1);
   lcd.print("Location:");
   while(1)
   {
     lcd.setCursor(9,1);
     lcd.print(count);
      
      char customKey = customKeypad.getKey();
     switch (customKey){

     case 'B':
       count++;
       if(count>25)
       count=0;
       delay(500);  break;
     

     case 'D':
         id=count;
          deleteFingerprint(id);
          return;
     break;

      case 'A':
           
          return;break;
     
   default: ;
  }
       
          return;delay(50);

  }
 
}

uint8_t getFingerprintEnroll() 
{
  int p = -1;
  lcd.clear();
  lcd.print("finger ID:");
  lcd.print(id);
  lcd.setCursor(0,1);
  lcd.print("Place Finger");
  delay(2000);
  while (p != FINGERPRINT_OK)
  {
    p = finger.getImage();
    switch (p)
    {
    case FINGERPRINT_OK:
      //Serial.println("Image taken");
      lcd.clear();
      lcd.print("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.println("No Finger");
      lcd.clear();
      lcd.print("No Finger");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      lcd.clear();
      lcd.print("Comm Error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      //Serial.println("Imaging error");
      lcd.clear();
      lcd.print("Imaging Error");
      break;
    default:
      //Serial.println("Unknown error");
       lcd.clear();
      lcd.print("Unknown Error");
      break;
    }
  }
 
  // OK success!
 
  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image converted");
      lcd.clear();
      lcd.print("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      //Serial.println("Image too messy");
       lcd.clear();
       lcd.print("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
            lcd.clear();
      lcd.print("Comm Error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      //Serial.println("Could not find fingerprint features");
            lcd.clear();
      lcd.print("Feature Not Found");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      //Serial.println("Could not find fingerprint features");
                  lcd.clear();
      lcd.print("Feature Not Found");
      return p;
    default:
      //Serial.println("Unknown error");
                  lcd.clear();
      lcd.print("Unknown Error");
      return p;
  }
  
  //Serial.println("Remove finger");
  lcd.clear();
  lcd.print("Remove Finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  //Serial.print("ID "); //Serial.println(id);
  p = -1;
  //Serial.println("Place same finger again");
   lcd.clear();
      lcd.print("Place Finger");
      lcd.setCursor(0,1);
      lcd.print("   Again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      //Serial.println("Imaging error");
      break;
    default:
      //Serial.println("Unknown error");
      return p;
    }
  }
 
  // OK success!
 
  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      //Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      //Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      //Serial.println("Could not find fingerprint features");
      return p;
    default:
      //Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  //Serial.print("Creating model for #");  //Serial.println(id);
  
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    //Serial.println("Prints matched!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    //Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    //Serial.println("Fingerprints did not match");
    return p;
  } else {
    //Serial.println("Unknown error");
    return p;
  }   
  
  //Serial.print("ID "); //Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    //Serial.println("Stored!");
    lcd.clear();
    lcd.print("Stored!");
    delay(2000);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    //Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    //Serial.println("Could not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    //Serial.println("Error writing to flash");
    return p;
  }
  else {
    //Serial.println("Unknown error");
    return p;
  }   
}
 
int getFingerprintIDez()
{
  uint8_t p = finger.getImage();
  
  if (p != FINGERPRINT_OK)  
  return -1;
 
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  
  return -1;
 
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)
  {
   lcd.clear();
   lcd.print("Finger Not Found");
   lcd.setCursor(0,1);
   lcd.print("Try Later");
   delay(2000);  
  return -1;
  }
  // found a match!
  //Serial.print("Found ID #"); 
  //Serial.print(finger.fingerID); 
  return finger.fingerID; 
}
 
uint8_t deleteFingerprint(uint8_t id) 
{
  uint8_t p = -1;  
  lcd.clear();
  lcd.print("Please wait");
  p = finger.deleteModel(id);
  if (p == FINGERPRINT_OK) 
  {
    //Serial.println("Deleted!");
    lcd.clear();
    lcd.print("Figer Deleted");
    lcd.setCursor(0,1);
    lcd.print("Successfully");
    delay(1000);
  } 
  
  else 
  {
    //Serial.print("Something Wrong"); 
    lcd.clear();
    lcd.print("Something Wrong");
    lcd.setCursor(0,1);
    lcd.print("Try Again Later");
    delay(2000);
    return p;
  }   
}






















