#include <Arduino.h>
#include <OneButton.h>
int mode1=0;
int flag=0;
#include <TM1637Display.h>
#define CLK 12
#define DIO 11
OneButton button(A0, true);  
TM1637Display display(CLK, DIO);
int sec;
int num_display;
int out =0; 


const uint8_t done[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

const uint8_t display_30[] = {
  SEG_G,          
  SEG_A | SEG_B | SEG_C | SEG_D| SEG_G ,   
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E| SEG_F,                        
  SEG_G,        
};

const uint8_t display_05[] = {
  SEG_G,          
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   
  SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,                        
  SEG_G,        
};

const uint8_t display_15[] = {
  SEG_G,          
  SEG_B | SEG_C ,   
  SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,                        
  SEG_G,        
};

const uint8_t display_45[] = {
  SEG_G,          
  SEG_B | SEG_C | SEG_F | SEG_G ,   
  SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,                        
  SEG_G,        
};
//const uint8_t SEG_DONE[] = {
//  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
//  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
//  SEG_C | SEG_E | SEG_G,                           // n
//  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
//  };
void setup() {
            // link the function to be called on a doubleclick event.
button.attachClick(singleclick);                  // link the function to be called on a singleclick event.
button.attachLongPressStop(longclick); 

  // put your setup code here, to run once:

}

void loop()
{

button.tick();   
delay(10);
display.setBrightness(1); 

int i;
int a;


if (mode1==0)
{
display.setSegments(display_30);
if (flag==1)
{
for (int i = 30; i > 0; i--) 
{
 display.showNumberDec(i); 
  delay(60000);
}
while ( 1==1)
{
display.clear();
delay(500);
display.setSegments(done);
delay(500);
}
flag=0 ;

}




}
else if (mode1==1)
{
display.setSegments(display_05);
if (flag==1){
display_time(5);
}
}
else if (mode1==2)
{
display.setSegments(display_15);
if (flag==1){
display_time(15);
}
}
else if (mode1==3)
{
display.setSegments(display_45);
if (flag==1){
display_time(45);
}
}
else if (mode1==4)
{
mode1=0;
}



}

void singleclick()
{                                 // what happens when the button is clicked
  mode1++;
  delay(100);                              // turn off the gren led
}
 
void longclick()
{                                   // what happens when buton is long-pressed
flag=1;
delay(100);
}

void doubleclick()
{                                // what happens when button is double-clicked
 out==1;                // turn off green LED
} 
 
void display_time(int time_min)
{

for (int i=time_min-1; i > -1; i--) 
{
for (int m=59;m>0;m--)
{
num_display=(i*100)+m;
display.showNumberDecEx(num_display, 0b11100000, false, 4, 0); 
delay(1000);
}
}

while ( 1==1)
{
display.clear();
delay(500);
display.setSegments(done);
delay(500);
}



flag=0 ;
}
