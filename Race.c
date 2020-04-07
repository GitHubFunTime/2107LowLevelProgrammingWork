#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#define RAND_MIN 1
#define RAND_MAXX 10
 
// function prototypes
void moveTortoise( int* tortPtr );
void moveHare( int* harePtr );
void printPosition( const int* const tortPtr, const int* const harePtr );
  
int main( void ){
   int TortPos = 1, HarePos = 1;
    
   srand((unsigned)time(NULL));
    
   //beginning
   puts("ON YOUR MARK, GET SET");
   printf("BANG !!!!!\n");
   printf("AND THEY'RE OFF !!!!\n");

   while(TortPos != 70 && HarePos != 70){
      moveTortoise( &TortPos );
      moveHare( &HarePos );
      sleep(1);
      printPosition( &TortPos, &HarePos ); 
   }
    
   //the result
   if(TortPos > HarePos){
      printf("TORTOISE WINS!!! YAY !!\n");         
   }else if(TortPos< HarePos){
      printf("Hare wins. Yuch.\n");      
   }
   else{
       printf("TORTOISE WINS!!! YAY !!\n");
   }

}
 
void moveTortoise( int* tortPtr ){
   int t;
    
   t= rand() % (RAND_MAXX+1)+ RAND_MIN;
    
   if(t >= 1 && t <= 5){
      *tortPtr += 3; 
   }else if(t >= 6 && t <= 7){
      *tortPtr -= 6; 
   }else{
      *tortPtr += 1; 
   }
    
   if(*tortPtr < 1) //resets the position of turtle if it goes to 0 or less
      *tortPtr = 1;
   else if(*tortPtr > 70)
      *tortPtr = 70;
}
 
void moveHare( int* harePtr ){
   int h;
    
   h= rand() % (RAND_MAXX+1)+ RAND_MIN;
    
   if(h>= 1 && h <= 2){
      //does nothing  
   }else if(h >= 3 && h <= 4){
      *harePtr += 9;   
   }else if(h == 5){
      *harePtr -= 12;
   }else if(h >= 6 && h<= 8){
      *harePtr += 1;
   }else{
      *harePtr -= 2;      
   }
    
   if(*harePtr < 1)
      *harePtr = 1;
   else if(*harePtr > 70)
      *harePtr = 70;
}
 
void printPosition( const int* const tortPtr, const int* const harePtr ){
   int i;
   if(*tortPtr == *harePtr){
      for(i = 1; i < *tortPtr; i++){
         printf("%s", " " );
      }
      printf("OUCH!!!");   
   }
   else if(*tortPtr < *harePtr){
      for(i = 1; i < *tortPtr; i++ ){
         printf("%s", " " );
      }   
      printf("T");
       
      for(i = 1; i < (*harePtr - *tortPtr); i++){
         printf("%s", " " );
      }
      printf("H");
   }
   else{
      for(i = 1; i < *harePtr; i++){
         printf("%s", " ");      
      }     
      printf("H");
       
      for( i = 0; i < (*tortPtr - *harePtr); i++){
         printf("%s", " " );     
      }
      printf("T");
   }
    
   printf("\n");
}