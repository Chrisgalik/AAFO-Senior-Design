/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

//SETTING PIN NUMBERS USING   " #define "
//Analog
#define BLIFE_IN A0
#define FSR1_IN A1
#define FSR2_IN A2

#define EMG_IN A3 
#define TEMP1_IN A4
#define TEMP2_IN A5

//Digital
#define BLIFE_LED1 1
#define BLIFE_LED2 2
#define BLIFE_LED3 3
#define BLIFE_LED4 4

#define FSR1_OUT 5
#define FSR2_OUT 6

#define MOTOR_LED 7
#define TEMP1_LED 8
#define TEMP2_LED 9
#define EMG_LED 10

#define HB_EN 11
#define HB3_OUT 12
#define HB4_OUT 13

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

////SETTING PIN NUMBERS USING   " int "
////Analog
//int BLIFE_IN = 0;
//int FSR1_IN = 1;
//int FSR2_IN = 2;
//
//int EMG_IN = 3;
//int TEMP1_IN = 4;
//int TEMP2_IN = 5;
//
////Digital
//int BLIFE_LED1 = 1;
//int BLIFE_LED2 = 2;
//int BLIFE_LED3 = 3;
//int BLIFE_LED4 = 4;
//
//int FSR1_OUT = 5;
//int FSR2_OUT = 6;
//
//int MOTOR_LED = 7;
//int TEMP1_LED = 8;
//int TEMP2_LED = 9;
//int EMG_LED = 10;
//
//int HB_EN = 11;
//int HB3_OUT = 12;
//int HB4_OUT = 13;

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////








/////////////////////////////////////////////////////////
// VARIABLE NOTATION ////////////////////////////////////
/////////////////////////////////////////////////////////

//reference sensor value        (rsv_...)
//previous values               (psv_...)
//active sensor values          (asv_...)
//maximum value                 (max_...)
//minimum value                 (min_...)
//threshhold value              (thv_...)
//minimum threshhold value      (minTHV_...)
//maximum threshhold value      (maxTHV_...)
//volt value                    (vv_...)
//degree celsius                (dC_...)
//degrees fahrenheit            (dF_...)
//minimum calibration           (...Calmin)
//maximum calibration           (...Calmax)

/////////////////////////////////////////////////////////
// BATTERY INITIALIZATION ///////////////////////////////
/////////////////////////////////////////////////////////
int psv_BLIFE = 20;
int asv_BLIFE = 20;
float vv_BLIFE;
float max_BLIFE = (12.6)*(1024.0)*(0.2)/(2.8);
float min_BLIFE = (9.0)*(1024.0)*(0.2)/(2.8);

/////////////////////////////////////////////////////////
// SENSOR INITIALIZATION ////////////////////////////////
/////////////////////////////////////////////////////////
int psv_FSR1 = 20;
int psv_FSR2 = 20;
int psv_EMG = 20;

int asv_FSR1 = 20;
int asv_FSR2 = 20;
int asv_EMG = 20;

int max_FSR1 = 0;
int max_FSR2 = 0;
int max_EMG = 0;

int min_FSR1 = 1000;
int min_FSR2 = 1000;
int min_EMG = 1000;

int thv_FSR1 = 0;    
int thv_FSR2 = 0;   
int thv_EMG = 0;      
 
int minTHV_FSR1 = 1000;
int minTHV_FSR2 = 1000;
int minTHV_EMG = 1000;

int maxTHV_FSR1;
int maxTHV_FSR2;
int maxTHV_EMG;

float vv_FSR1;   
float vv_FSR2;   
float vv_EMG;  

/////////////////////////////////////////////////////////
// TEMPERATURE INITIALIZATION ///////////////////////////
/////////////////////////////////////////////////////////
int psv_TEMP1 = 20;
int psv_TEMP2 = 20;

int asv_TEMP1 = 20;
int asv_TEMP2 = 20; 

int minTHV_TEMP1 = round((0.5)*(1024.0)*(0.2) + ((100 - 32)*(5.0/9.0))*(1024.0)*(0.2)*(0.01));
int minTHV_TEMP2 = round((0.5)*(1024.0)*(0.2) + ((100 - 32)*(5.0/9.0))*(1024.0)*(0.2)*(0.01));

int maxTHV_TEMP1 = round((0.5)*(1024.0)*(0.2) + ((115 - 32)*(5.0/9.0))*(1024.0)*(0.2)*(0.01));
int maxTHV_TEMP2 = round((0.5)*(1024.0)*(0.2) + ((115 - 32)*(5.0/9.0))*(1024.0)*(0.2)*(0.01));
  
float vv_TEMP1;
float vv_TEMP2;

float dC_TEMP1;
float dC_TEMP2;

float dF_TEMP1;
float dF_TEMP2;

/////////////////////////////////////////////////////////
// FSR BOOLEANS /////////////////////////////////////////
/////////////////////////////////////////////////////////
bool HealFlag = LOW; 
bool ToeFlag = LOW;

/////////////////////////////////////////////////////////
// H-BRIDGE BOOLEANS ////////////////////////////////////
/////////////////////////////////////////////////////////
bool HB3_bool = LOW;
bool HB4_bool = LOW;

/////////////////////////////////////////////////////////
// TOO HOT BOOLEAN //////////////////////////////////////
/////////////////////////////////////////////////////////
bool tooHOT_bool = LOW;

/////////////////////////////////////////////////////////
// LED BOOLEANS /////////////////////////////////////////
/////////////////////////////////////////////////////////
bool BLIFE_bool1 = LOW;
bool BLIFE_bool2 = LOW;
bool BLIFE_bool3 = LOW;
bool BLIFE_bool4 = LOW;
bool MOTOR_bool = LOW;
bool TEMP1_bool = LOW;
bool TEMP2_bool = LOW;
bool EMG_bool = LOW;

/////////////////////////////////////////////////////////
// MOTOR BOOLEANS ///////////////////////////////////////
/////////////////////////////////////////////////////////
bool MOTOR_ON = LOW;

/////////////////////////////////////////////////////////
// CALIBRATION BOOLEANS /////////////////////////////////
/////////////////////////////////////////////////////////
bool CALIBRATION_bool = HIGH;

/////////////////////////////////////////////////////////
// HEEL INT /////////////////////////////////////////////
/////////////////////////////////////////////////////////
int HeelFlag = 0;

unsigned long TIME;
//int myFSR1[30];
//int myFSR2[30];
//int myEMG[30];
//int i = 0;
/////////////////////////////////////////////////////////
// INITIALIZATION END ///////////////////////////////////
/////////////////////////////////////////////////////////












/////////////////////////////////////////////////////////
// SETUP ////////////////////////////////////////////////
/////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  TCCR0B = TCCR0B & B11111000 | B00000001;

  
  /////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////
  // SET PINMODES /////////////////////////////////////////
  /////////////////////////////////////////////////////////
  pinMode(BLIFE_IN, INPUT);
  pinMode(FSR1_IN, INPUT);
  pinMode(FSR2_IN, INPUT);
  pinMode(EMG_IN, INPUT);
  pinMode(TEMP1_IN, INPUT);
  pinMode(TEMP2_IN, INPUT);


  pinMode(BLIFE_LED1, OUTPUT);
  pinMode(BLIFE_LED2, OUTPUT);
  pinMode(BLIFE_LED3, OUTPUT);
  pinMode(BLIFE_LED4, OUTPUT);
  
  pinMode(FSR1_OUT, OUTPUT);
  pinMode(FSR2_OUT, OUTPUT);

  pinMode(MOTOR_LED, OUTPUT);
  pinMode(TEMP1_LED, OUTPUT);
  pinMode(TEMP2_LED, OUTPUT);
  pinMode(EMG_LED, OUTPUT);

  pinMode(HB_EN, OUTPUT);
  pinMode(HB3_OUT, OUTPUT);
  pinMode(HB4_OUT, OUTPUT);


 




  /////////////////////////////////////////////////////////
  // FUTURE CALIBRATION ///////////////////////////////////
  /////////////////////////////////////////////////////////
  //// two calibrtion stages.
  //// one for standing still
  //// one for walking 

}

/////////////////////////////////////////////////////////
// SET UP END ///////////////////////////////////////////
/////////////////////////////////////////////////////////



















/////////////////////////////////////////////////////////
// LOOP /////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void loop() {


  /////////////////////////////////////////////////////////
  // SENSOR CALIBRATION ///////////////////////////////////
  /////////////////////////////////////////////////////////
  while (CALIBRATION_bool == HIGH) {
    TIME = millis();
    digitalWrite(EMG_LED, HIGH); delay(8000); digitalWrite(EMG_LED, LOW); delay(8000);



    
    /////////////////////////////////////////////////////////
    // FSR CODE /////////////////////////////////////////////
    /////////////////////////////////////////////////////////
  
    //---- write PWM signal to the FSR sensors ----//
    analogWrite(FSR1_OUT, 127);
    analogWrite(FSR2_OUT, 127);
  
    //---- read active sensor value from the FSR sensors ----//
    asv_FSR1 = analogRead(FSR1_IN);
    if (asv_FSR1 <= 19) {asv_FSR1 = psv_FSR1;}
    asv_FSR2 = analogRead(FSR2_IN);
    asv_EMG = analogRead(EMG_IN);
  
    //---- calculate voltage values for the FSR sensors ----//
    vv_FSR1 = asv_FSR1 * (5.0 / 1024.0);
    vv_FSR2 = asv_FSR2 * (5.0 / 1024.0);

    //---- determine new max or min of FSR1 ----//
    if (asv_FSR1 > max_FSR1)  {max_FSR1 = asv_FSR1;}
    if (asv_FSR1 < min_FSR1)  {min_FSR1 = asv_FSR1;}
    //---- determine new max or min of FSR2 ----//
    if (asv_FSR2 > max_FSR2)  {max_FSR2 = asv_FSR2;}
    if (asv_FSR2 < min_FSR2)  {min_FSR2 = asv_FSR2;}
    //---- determine new max or min of EMG ----//
    if (asv_EMG > max_EMG) {max_EMG = asv_EMG;}
    if (asv_EMG < min_EMG) {min_EMG = asv_EMG;}

    if ((TIME < 1000000))  {CALIBRATION_bool = HIGH;}
    if ((TIME >= 1000000)) {CALIBRATION_bool = LOW;}
  
//    Serial.print("TIME:   "); Serial.print(TIME); Serial.print(" \n");
//    Serial.print("ACTIVE SENSOR VALUE FSR1: "); Serial.print(asv_FSR1); Serial.print(" \n");
//    Serial.print("ACTIVE SENSOR VALUE FSR2: "); Serial.print(asv_FSR2); Serial.print(" \n");
//    Serial.print("ACTIVE SENSOR VALUE EMG: "); Serial.print(asv_EMG); Serial.print(" \n");
//
//    Serial.print("MAXIMUM SENSOR VALUE FSR1: "); Serial.print(max_FSR1); Serial.print(" \n");
//    Serial.print("MAXIMUM SENSOR VALUE FSR2: "); Serial.print(max_FSR2); Serial.print(" \n");
//    Serial.print("MAXIMUM SENSOR VALUE EMG: "); Serial.print(max_EMG); Serial.print(" \n");
//
//    Serial.print("MINIMUM SENSOR VALUE FSR1: "); Serial.print(min_FSR1); Serial.print(" \n");
//    Serial.print("MINIMUM SENSOR VALUE FSR2: "); Serial.print(min_FSR2); Serial.print(" \n");  Serial.print(" \n"); 
  

    /////////////////////////////////////////////////////////
    // VARIABLE CALCULATION /////////////////////////////////
    /////////////////////////////////////////////////////////
    thv_EMG = ((max_EMG - min_EMG)*0.5 + min_EMG);
    thv_FSR1 = ((max_FSR1 - min_FSR1)*0.70 + min_FSR1);
    thv_FSR2 = ((max_FSR2 - min_FSR1)*0.40 + min_FSR2);
    minTHV_FSR2 = ((max_FSR2 - min_FSR1)*0.25 + min_FSR2);


    


  
  }








  /////////////////////////////////////////////////////////
  // MAIN CODE ////////////////////////////////////////////
  /////////////////////////////////////////////////////////
  while (CALIBRATION_bool == LOW) {





  /////////////////////////////////////////////////////////
  // TEMPERATURE CODE /////////////////////////////////////
  /////////////////////////////////////////////////////////
  //---- read and calculate temperature values ----//
  asv_TEMP1 = analogRead(TEMP1_IN);  
  vv_TEMP1 = (asv_TEMP1)*5;
    vv_TEMP1 /= 1024;
  dC_TEMP1 = (vv_TEMP1 - 0.5)*100;
  dF_TEMP1 = (dC_TEMP1*9.0/5.0) + 32.0;
  //-------------------------------------------------
  asv_TEMP2 = analogRead(TEMP2_IN);
  vv_TEMP2 = (asv_TEMP2)*5;
    vv_TEMP2 /= 1024;
  dC_TEMP2 = (vv_TEMP2 - 0.5)*100;
  dF_TEMP2 = dC_TEMP2*(9.0/5.0) + 32.0;
  //---- evaluate if too hot ----//
  if (dF_TEMP1 >= 115 || dF_TEMP2  >= 115)     {tooHOT_bool = HIGH;}
  else if (dF_TEMP1 < 115 && dF_TEMP2  < 115)  {tooHOT_bool = LOW;}








  /////////////////////////////////////////////////////////
  // TOO HOT CODE /////////////////////////////////////////
  ///////////////////////////////////////////////////////// 
  while (tooHOT_bool == HIGH) {
    //---- turn motor off ----//
    HB3_bool = LOW; digitalWrite(HB3_OUT, HB3_bool);
    HB4_bool = LOW; digitalWrite(HB4_OUT, HB4_bool);
    //---- write to temperature LEDs ----//
    if (dF_TEMP1 >= 115 && dF_TEMP2 >= 115) {
      digitalWrite(TEMP1_LED, HIGH); digitalWrite(TEMP2_LED, HIGH); delay(5000);
      digitalWrite(TEMP1_LED, LOW); digitalWrite(TEMP2_LED, LOW); delay(5000); tooHOT_bool = HIGH;}
    //-------------------------------------  
    else if (dF_TEMP1 >= 115) {digitalWrite(TEMP1_LED, HIGH); delay(5000); digitalWrite(TEMP1_LED, LOW); delay(5000); tooHOT_bool = HIGH;
      if (dF_TEMP2 >= 100) {digitalWrite(TEMP2_LED, HIGH);}
      else if (dF_TEMP2 < 100) {digitalWrite(TEMP2_LED, LOW);}}
    //-------------------------------------  
    else if (dF_TEMP2 >= 115) {digitalWrite(TEMP2_LED, HIGH); delay(5000); digitalWrite(TEMP2_LED, LOW); delay(5000); tooHOT_bool = HIGH;
      if (dF_TEMP1 >= 100) {digitalWrite(TEMP1_LED, HIGH); }
      else if (dF_TEMP1 < 100) {digitalWrite(TEMP1_LED, LOW);}}
    //-------------------------------------  
    else if (dF_TEMP1 < 115 && dF_TEMP2  < 115)  {
      if (dF_TEMP1 >= 100) {digitalWrite(TEMP1_LED, HIGH);}
      else if (dF_TEMP1 < 100) {digitalWrite(TEMP1_LED, LOW);}
      if (dF_TEMP2 >= 100) {digitalWrite(TEMP2_LED, HIGH);}
      else if (dF_TEMP2 < 100) {digitalWrite(TEMP2_LED, LOW);}
      tooHOT_bool = LOW;}
    //---- read and calculate temperature values ----//
    asv_TEMP1 = analogRead(TEMP1_IN);  
    vv_TEMP1 = (asv_TEMP1)*5;
      vv_TEMP1 /= 1024;
    dC_TEMP1 = (vv_TEMP1 - 0.5)*100;
    dF_TEMP1 = (dC_TEMP1*9.0/5.0) + 32.0;
    //-------------------------------------------------
    asv_TEMP2 = analogRead(TEMP2_IN);
    vv_TEMP2 = (asv_TEMP2)*5;
      vv_TEMP2 /= 1024;
    dC_TEMP2 = (vv_TEMP2 - 0.5)*100;
    dF_TEMP2 = dC_TEMP2*(9.0/5.0) + 32.0;
    //---- evaluate if stil/ too hot ----//
    if ((dF_TEMP1 >= 115) || (dF_TEMP2  >= 115))     {tooHOT_bool = HIGH;}
    else if ((dF_TEMP1 < 115) && (dF_TEMP2  < 115))  {tooHOT_bool = LOW;}
    //---- this while loop repeats if still too hot----//
    }






  /////////////////////////////////////////////////////////
  // TEMPERATURE LED CODE /////////////////////////////////
  /////////////////////////////////////////////////////////
  //---- write to temperature LEDs ----//
  if (dF_TEMP1 >= 100) {digitalWrite(TEMP1_LED, HIGH); tooHOT_bool = LOW;}
  if (dF_TEMP1 < 100) {digitalWrite(TEMP1_LED, LOW); tooHOT_bool = LOW;}
  //-------------------------------------
  if (dF_TEMP2 >= 100) {digitalWrite(TEMP2_LED, HIGH); tooHOT_bool = LOW;}
  if (dF_TEMP2 < 100) {digitalWrite(TEMP2_LED, LOW); tooHOT_bool = LOW;}
















////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//  //TEMPERATURE LED CODE      (For one Temperature LED)                         //
//  while (dF_TEMP1 >= 115 || dF_TEMP2 >= 115) {                                  //
//    digitalWrite(TEMP1_LED, HIGH); digitalWrite(TEMP2_LED, HIGH); delay(100);   //
//    digitalWrite(TEMP1_LED, LOW); digitalWrite(TEMP2_LED, LOW); delay(100);     //
//    tooHOT_bool = HIGH;}                                                        //
//                                                                                //
//                                                                                //
//  if (dF_TEMP1 > 100 || dF_TEMP2 > 100) {                                       //
//    digitalWrite(TEMP1_LED, HIGH);                                              //
//    digitalWrite(TEMP2_LED, HIGH);                                              //
//    tooHOT_bool = LOW;}                                                         //
//  else if (dF_TEMP1 <= 100 || dF_TEMP2 <= 100) {                                //
//    digitalWrite(TEMP1_LED, LOW);                                               //  
//    digitalWrite(TEMP2_LED, LOW);                                               //
//    tooHOT_bool = LOW;}                                                         //  
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

 



















  /////////////////////////////////////////////////////////
  // BATTERY LIFE CODE ////////////////////////////////////
  /////////////////////////////////////////////////////////
  //---- read active sensor value from battery ----//
  asv_BLIFE = analogRead(BLIFE_IN);
  //---- determine percentage of battery life left ----//
  if (asv_BLIFE < (0.05*max_BLIFE)) {
     BLIFE_bool1 = LOW;
     BLIFE_bool2 = LOW;
     BLIFE_bool3 = LOW;
     BLIFE_bool4 = LOW;}
  else if (asv_BLIFE < (0.25*max_BLIFE)) {
    BLIFE_bool1 = HIGH;
    BLIFE_bool2 = LOW;
    BLIFE_bool3 = LOW;
    BLIFE_bool4 = LOW;}
  else if (asv_BLIFE < (0.50*max_BLIFE)) {
    BLIFE_bool1 = HIGH;
    BLIFE_bool2 = HIGH;
    BLIFE_bool3 = LOW;
    BLIFE_bool4 = LOW;}
  else if (asv_BLIFE < (0.75*max_BLIFE)) {
    BLIFE_bool1 = HIGH;
    BLIFE_bool2 = HIGH;
    BLIFE_bool3 = HIGH;
    BLIFE_bool4 = LOW;}
  else {
    BLIFE_bool1 = HIGH;
    BLIFE_bool2 = HIGH;
    BLIFE_bool3 = HIGH;
    BLIFE_bool4 = HIGH;}

  //---- write to battery life LEDs ----//
  digitalWrite(BLIFE_LED1, BLIFE_bool1);
  digitalWrite(BLIFE_LED2, BLIFE_bool2);
  digitalWrite(BLIFE_LED3, BLIFE_bool3);
  digitalWrite(BLIFE_LED4, BLIFE_bool4); 
  vv_BLIFE = asv_BLIFE * (5.0 / 1024.0);












///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
//  if (BatteryLife == 0) {                          //
//     BLIFE_bool1 = LOW;                            //
//     BLIFE_bool2 = LOW;                            //
//     BLIFE_bool3 = LOW;                            //
//     BLIFE_bool4 = LOW;}                           //
//  else if (BatteryLife == 1) {                     //
//     BLIFE_bool1 = HIGH;                           //
//     BLIFE_bool2 = LOW;                            //
//     BLIFE_bool3 = LOW;                            //
//     BLIFE_bool4 = LOW;}                           //
//  else if (BatteryLife == 2) {                     //
//     BLIFE_bool1 = HIGH;                           //
//     BLIFE_bool2 = HIGH;                           //
//     BLIFE_bool3 = LOW;                            //
//     BLIFE_bool4 = LOW;}                           //
//  else if (BatteryLife == 3) {                     //
//     BLIFE_bool1 = HIGH;                           //
//     BLIFE_bool2 = HIGH;                           //
//     BLIFE_bool3 = HIGH;                           //  
//     BLIFE_bool4 = LOW;}                           //  
//  else if (BatteryLife == 4) {                     //
//     BLIFE_bool1 = HIGH;                           //
//     BLIFE_bool2 = HIGH;                           //
//     BLIFE_bool3 = HIGH;                           //
//     BLIFE_bool4 = HIGH;}                          //
//      digitalWrite(BLIFE_LED1, BLIFE_bool1);       //
//      digitalWrite(BLIFE_LED2, BLIFE_bool2);       //
//      digitalWrite(BLIFE_LED3, BLIFE_bool3);       //
//      digitalWrite(BLIFE_LED4, BLIFE_bool4);       //
//  switch(BatteryLife) {                            //
//    case 0:                                        //
//      digitalWrite(BLIFE_LED1, LOW);               //
//      digitalWrite(BLIFE_LED2, LOW);               //
//      digitalWrite(BLIFE_LED3, LOW);               //
//      digitalWrite(BLIFE_LED4, LOW);               //
//      break;                                       //
//    break;                                         //
//    case 1: {                                      //
//      digitalWrite(BLIFE_LED1, HIGH);              //
//      digitalWrite(BLIFE_LED2, LOW);               //
//      digitalWrite(BLIFE_LED3, LOW);               //
//      digitalWrite(BLIFE_LED4, LOW);               //
//      break;                                       //
//    }                                              //
//    case 2: {                                      //
//      digitalWrite(BLIFE_LED1, HIGH);              //
//      digitalWrite(BLIFE_LED2, HIGH);              //
//      digitalWrite(BLIFE_LED3, LOW);               //
//      digitalWrite(BLIFE_LED4, LOW);               //
//      break;                                       //
//    }                                              //
//    case 3: {                                      //
//      digitalWrite(BLIFE_LED1, HIGH);              //
//      digitalWrite(BLIFE_LED2, HIGH);              //
//      digitalWrite(BLIFE_LED3, HIGH);              //
//      digitalWrite(BLIFE_LED4, LOW);               //
//      break;                                       //
//    }                                              //
//    case 4: {                                      //
//      digitalWrite(BLIFE_LED1, HIGH);              //
//      digitalWrite(BLIFE_LED2, HIGH);              //
//      digitalWrite(BLIFE_LED3, HIGH);              //
//      digitalWrite(BLIFE_LED4, HIGH);              //
//      break;                                       //
//    }                                              //
//  }                                                //
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////




















  /////////////////////////////////////////////////////////
  // FSR CODE /////////////////////////////////////////////
  /////////////////////////////////////////////////////////
  //---- write PWM signal to the FSR sensors ----//
  analogWrite(FSR1_OUT, 127);
  analogWrite(FSR2_OUT, 127);
  //---- read active sensor value from the FSR sensors ----//
  asv_FSR1 = analogRead(FSR1_IN);
  asv_FSR2 = analogRead(FSR2_IN);
  asv_EMG = analogRead(EMG_IN);
  //---- calculate voltage values for the FSR sensors ----//
  float vv_FSR1 = asv_FSR1 * (5.0 / 1024.0);
  float vv_FSR2 = asv_FSR2 * (5.0 / 1024.0);
  //---- set heel flag based on FSR1 ----//
  if (asv_FSR1 >= thv_FSR1)      {HeelFlag = HIGH;}
  else if (asv_FSR1 <= thv_FSR1) {HeelFlag = LOW;} 
  //---- set toe flag based on FSR2 ----//
  if (asv_FSR2 >= thv_FSR2)      {ToeFlag = HIGH;}
  else if (asv_FSR2 <= thv_FSR2) {ToeFlag = LOW;}
  //---- determine if motor is off ----//
  if ((HeelFlag == HIGH) && (asv_FSR2 < thv_FSR2)) {MOTOR_ON = LOW;} 
  else {MOTOR_ON = HIGH;}





  /////////////////////////////////////////////////////////
  // MOTOR FORWARD, REVERSE, REST CODE ////////////////////
  /////////////////////////////////////////////////////////
  //---- write to enablePin of the motor ----//
  digitalWrite(HB_EN, HIGH);
  //---- determine phase and write to the motor ----//
  if (ToeFlag == HIGH) { // repel
    HB3_bool = LOW;  digitalWrite(HB3_OUT, HB3_bool);
    HB4_bool = HIGH; digitalWrite(HB4_OUT, HB4_bool);
    MOTOR_ON = HIGH;}
  else if (MOTOR_ON == LOW) { // rest
    HB3_bool = LOW; digitalWrite(HB3_OUT, HB3_bool); 
    HB4_bool = LOW; digitalWrite(HB4_OUT, HB4_bool);
    MOTOR_ON = LOW;}
  else { // attract
    HB3_bool = HIGH; digitalWrite(HB3_OUT, HB3_bool);
    HB4_bool = LOW;  digitalWrite(HB4_OUT, HB4_bool);
    MOTOR_ON = HIGH;}
  //---- write to motor LED ----//
  if (MOTOR_ON == HIGH) {digitalWrite(MOTOR_LED, HIGH);}
  if (MOTOR_ON == LOW)  {digitalWrite(MOTOR_LED, LOW);}




  /////////////////////////////////////////////////////////
  // EMG CODE /////////////////////////////////////////////
  /////////////////////////////////////////////////////////
  //---- write to EMG LED ----//
  asv_EMG = analogRead(EMG_IN);
  if (asv_EMG > thv_EMG) {EMG_bool = HIGH;}
  if (asv_EMG < thv_EMG) {EMG_bool = LOW;}
  if (EMG_bool == HIGH)  {digitalWrite(EMG_LED, EMG_bool);}
  if (EMG_bool == LOW)   {digitalWrite(EMG_LED, EMG_bool);}









//  /////////////////////////////////////////////////////////
//  // TEMPERATURE 1 PRINTING ///////////////////////////////
//  /////////////////////////////////////////////////////////
//  Serial.print(" \n"); Serial.print(" \n"); Serial.print(" \n");
//  Serial.print("--------------------------TEMPERATURE 1--------------------------"); Serial.print(" \n");
//  Serial.print("PREVIOUS VALUE:             "); Serial.print(psv_TEMP1); Serial.print(" \n");
//  Serial.print("ACTIVE VALUE:               "); Serial.print(asv_TEMP1); Serial.print(" \n");
//  Serial.print("MINIMUM THRESHOLD VALUE:    "); Serial.print(minTHV_TEMP1); Serial.print(" \n");
//  Serial.print("MAXIMUM THRESHOLD VALUE:    "); Serial.print(maxTHV_TEMP1); Serial.print(" \n");
//  Serial.print("VOLTAGE VALUE:              "); Serial.print(vv_TEMP1); Serial.print("   V"); Serial.print(" \n");
//  Serial.print("FAHRENHEIT:                 "); Serial.print(dF_TEMP1); Serial.print(" º F"); Serial.print(" \n");
//  Serial.print("CELSIUS:                    "); Serial.print(dC_TEMP1); Serial.print(" º C"); Serial.print(" \n");
//  Serial.print("IS THE MOTOR TOO HOT?       "); 
//  if (tooHOT_bool == HIGH) {Serial.print("YES");}
//  else if (tooHOT_bool == LOW) {Serial.print("NO");} Serial.print(" \n");
//  Serial.print("-----------------------------------------------------------------"); Serial.print(" \n");
//
//  /////////////////////////////////////////////////////////
//  // TEMPERATURE 2 PRINTING ///////////////////////////////
//  /////////////////////////////////////////////////////////
//  Serial.print(" \n"); Serial.print(" \n"); Serial.print(" \n");
//  Serial.print("--------------------------TEMPERATURE 2--------------------------"); Serial.print(" \n");
//  Serial.print("PREVIOUS VALUE:             "); Serial.print(psv_TEMP2); Serial.print(" \n");
//  Serial.print("ACTIVE VALUE:               "); Serial.print(asv_TEMP2); Serial.print(" \n");
//  Serial.print("MINIMUM THRESHOLD VALUE:    "); Serial.print(minTHV_TEMP2); Serial.print(" \n");
//  Serial.print("MAXIMUM THRESHOLD VALUE:    "); Serial.print(maxTHV_TEMP2); Serial.print(" \n");
//  Serial.print("VOLTAGE VALUE:              "); Serial.print(vv_TEMP2); Serial.print("   V"); Serial.print(" \n");
//  Serial.print("FAHRENHEIT:                 "); Serial.print(dF_TEMP2); Serial.print(" º F"); Serial.print(" \n");
//  Serial.print("CELSIUS:                    "); Serial.print(dC_TEMP2); Serial.print(" º C"); Serial.print(" \n");
//  Serial.print("IS THE MOTOR TOO HOT?       "); 
//  if (tooHOT_bool == HIGH) {Serial.print("YES");}
//  else if (tooHOT_bool == LOW) {Serial.print("NO");} Serial.print(" \n");
//  Serial.print("-----------------------------------------------------------------"); Serial.print(" \n");
//
//  /////////////////////////////////////////////////////////
//  // BATTERY PRINTING /////////////////////////////////////
//  /////////////////////////////////////////////////////////
//  Serial.print(" \n"); Serial.print(" \n"); Serial.print(" \n");
//  Serial.print("--------------------------BATTERY LIFE--------------------------"); Serial.print(" \n");
//  Serial.print("PREVIOUS VALUE:             "); Serial.print(psv_BLIFE); Serial.print(" \n");
//  Serial.print("ACTIVE VALUE:               "); Serial.print(asv_BLIFE); Serial.print(" \n");
//  Serial.print("MAXIMUM VALUE:              "); Serial.print(max_BLIFE); Serial.print(" \n");
//  Serial.print("MINIMUM VALUE:              "); Serial.print(min_BLIFE); Serial.print(" \n");
//  Serial.print("VOLTAGE VALUE:              "); Serial.print(vv_BLIFE); Serial.print("   V"); Serial.print(" \n");
//  if (asv_BLIFE < (0.05*max_BLIFE)) {Serial.print("BATTERY LIFE IS LESS THAN 5%"); Serial.print(" \n");}
//  else if (asv_BLIFE < (0.25*max_BLIFE)) {Serial.print("BATTERY LIFE IS LESS THAN 25%"); Serial.print(" \n");}
//  else if (asv_BLIFE < (0.5*max_BLIFE)) {Serial.print("BATTERY LIFE IS LESS THAN 50%"); Serial.print(" \n");}
//  else if (asv_BLIFE < (0.75*max_BLIFE)) {Serial.print("BATTERY LIFE IS LESS THAN 75%"); Serial.print(" \n");}
//  else {Serial.print("BATTERY LIFE IS MORE THAN 75%"); Serial.print(" \n");}
//  Serial.print("----------------------------------------------------------------"); Serial.print(" \n");
//
//  /////////////////////////////////////////////////////////
//  // FSR1 PRINTING ////////////////////////////////////////
//  /////////////////////////////////////////////////////////
//  Serial.print(" \n"); Serial.print(" \n"); Serial.print(" \n");
//  Serial.print("--------------------------FSR1--------------------------"); Serial.print(" \n");
//  Serial.print("PREVIOUS VALUE:             "); Serial.print(psv_FSR1); Serial.print(" \n");
//  Serial.print("ACTIVE VALUE:               "); Serial.print(asv_FSR1); Serial.print(" \n");
//  Serial.print("MAXIMUM VALUE:              "); Serial.print(max_FSR1); Serial.print(" \n");
//  Serial.print("MINIMUM VALUE:              "); Serial.print(min_FSR1); Serial.print(" \n");
//  Serial.print("THRESHOLD VALUE:            "); Serial.print(thv_FSR1); Serial.print(" \n");
//  Serial.print("MINIMUM THRESHOLD VALUE:    "); Serial.print(minTHV_FSR1); Serial.print(" \n");
//  Serial.print("MAXIMUM THRESHOLD VALUE:    "); Serial.print(maxTHV_FSR1); Serial.print(" \n");
//  Serial.print("VOLTAGE VALUE:              "); Serial.print(vv_FSR1); Serial.print("   V"); Serial.print(" \n");
//  Serial.print("--------------------------------------------------------"); Serial.print(" \n");
//
//  /////////////////////////////////////////////////////////
//  // FSR2 PRINTING ////////////////////////////////////////
//  /////////////////////////////////////////////////////////
//  Serial.print(" \n"); Serial.print(" \n"); Serial.print(" \n");
//  Serial.print("--------------------------FSR2--------------------------"); Serial.print(" \n");
//  Serial.print("PREVIOUS VALUE:             "); Serial.print(psv_FSR2); Serial.print(" \n");
//  Serial.print("ACTIVE VALUE:               "); Serial.print(asv_FSR2); Serial.print(" \n");
//  Serial.print("MAXIMUM VALUE:              "); Serial.print(max_FSR2); Serial.print(" \n");
//  Serial.print("MINIMUM VALUE:              "); Serial.print(min_FSR2); Serial.print(" \n");
//  Serial.print("THRESHOLD VALUE:            "); Serial.print(thv_FSR2); Serial.print(" \n");
//  Serial.print("MINIMUM THRESHOLD VALUE:    "); Serial.print(minTHV_FSR2); Serial.print(" \n");
//  Serial.print("MAXIMUM THRESHOLD VALUE:    "); Serial.print(maxTHV_FSR2); Serial.print(" \n");
//  Serial.print("VOLTAGE VALUE:              "); Serial.print(vv_FSR2); Serial.print("   V"); Serial.print(" \n");
//  Serial.print("--------------------------------------------------------"); Serial.print(" \n");
//
//  /////////////////////////////////////////////////////////
//  // EMG PRINTING /////////////////////////////////////////
//  /////////////////////////////////////////////////////////
//  Serial.print(" \n"); Serial.print(" \n"); Serial.print(" \n");
//  Serial.print("--------------------------EMG--------------------------"); Serial.print(" \n");
//  Serial.print("PREVIOUS VALUE:             "); Serial.print(psv_EMG); Serial.print(" \n");
//  Serial.print("ACTIVE VALUE:               "); Serial.print(asv_EMG); Serial.print(" \n");
//  Serial.print("MAXIMUM VALUE:              "); Serial.print(max_EMG); Serial.print(" \n");
//  Serial.print("MINIMUM VALUE:              "); Serial.print(min_EMG); Serial.print(" \n");
//  Serial.print("THRESHOLD VALUE:            "); Serial.print(thv_EMG); Serial.print(" \n");
//  Serial.print("MINIMUM THRESHOLD VALUE:    "); Serial.print(minTHV_EMG); Serial.print(" \n");
//  Serial.print("MAXIMUM THRESHOLD VALUE:    "); Serial.print(maxTHV_EMG); Serial.print(" \n");
//  Serial.print("VOLTAGE VALUE:              "); Serial.print(vv_EMG); Serial.print("   V"); Serial.print(" \n");
//  Serial.print("-------------------------------------------------------"); Serial.print(" \n");
//
//  /////////////////////////////////////////////////////////
//  // BOOLEAN PRINTING /////////////////////////////////////
//  /////////////////////////////////////////////////////////
//  Serial.print(" \n"); Serial.print(" \n"); Serial.print(" \n");
//  Serial.print("--------------------------BOOLEANS--------------------------"); Serial.print(" \n");
//  Serial.print("HealFlag:             "); Serial.print(HealFlag); Serial.print(" \n");
//  Serial.print("ToeFlag:              "); Serial.print(ToeFlag); Serial.print(" \n");
//  Serial.print("HB3_bool:             "); Serial.print(HB3_bool); Serial.print(" \n");
//  Serial.print("HB4_bool:             "); Serial.print(HB4_bool); Serial.print(" \n");
//  Serial.print("tooHOT_bool:          "); Serial.print(tooHOT_bool); Serial.print(" \n");
//  Serial.print("BLIFE_bool1:          "); Serial.print(BLIFE_bool1); Serial.print(" \n");
//  Serial.print("BLIFE_bool2:          "); Serial.print(BLIFE_bool2); Serial.print(" \n");
//  Serial.print("BLIFE_bool3:          "); Serial.print(BLIFE_bool3); Serial.print(" \n");
//  Serial.print("BLIFE_bool4:          "); Serial.print(BLIFE_bool4); Serial.print(" \n");
//  Serial.print("MOTOR_bool:           "); Serial.print(MOTOR_bool); Serial.print(" \n");
//  Serial.print("TEMP1_bool:           "); Serial.print(TEMP1_bool); Serial.print(" \n");
//  Serial.print("TEMP2_bool:           "); Serial.print(TEMP2_bool); Serial.print(" \n");
//  Serial.print("EMG_bool:             "); Serial.print(EMG_bool); Serial.print(" \n");
//  Serial.print("MOTOR_ON:             "); Serial.print(MOTOR_ON); Serial.print(" \n");
//  Serial.print("CALIBRATION_bool:     "); Serial.print(CALIBRATION_bool); Serial.print(" \n");
//  Serial.print("------------------------------------------------------------"); Serial.print(" \n");
//
//  /////////////////////////////////////////////////////////
//  // MOTOR STATE PRINTING /////////////////////////////////
//  /////////////////////////////////////////////////////////
//  Serial.print(" \n"); Serial.print(" \n"); Serial.print(" \n");
//  Serial.print("--------------------------MOTOR STATE--------------------------"); Serial.print(" \n");
//  if (ToeFlag == HIGH) {Serial.print("REPEL \n");}
//  else if((HeelFlag == HIGH) && (asv_FSR2 < thv_FSR2)){Serial.print("REST \n");} 
//  else {Serial.print("ATTRACT \n");}
//  Serial.print("---------------------------------------------------------------"); Serial.print(" \n");
//  Serial.print("\n "); Serial.print("\n "); Serial.print("\n "); 
//  Serial.print("\n "); Serial.print("\n "); Serial.print("\n ");

   psv_BLIFE = asv_BLIFE;
   psv_FSR1 = asv_FSR1;
   psv_FSR2 = asv_FSR2;
   psv_EMG = asv_EMG;
   psv_TEMP1 = asv_TEMP1;
   psv_TEMP2 = asv_TEMP2;
   
   //delay(100000);
   }
}
