#include <stdio.h>

/*
  @ Description: A 8 point 1-D AAN DCT
  @ Author:      Pratyush Kumar Ranjan
  @ Date:        15 Aug 2013
*/

typedef struct{
int row0;
int row1;
int row2;
int row3;
int row4;
int row5;
int row6;
int row7;
} dct_stage;

void dct_aan(int*, int* );
void dct_aan(int* input, int* output){
  
  int iter;
  int temp_buff;
 
  dct_stage stage1;
  dct_stage stage2;
  dct_stage stage3;
  dct_stage stage4;
  dct_stage stage5;
 
  //stage 1
  stage1.row0 = input[0] + input[6];
  stage1.row1 = input[1] + input[5];
  stage1.row2 = input[2] + input[4];
  stage1.row3 = input[3]           ;
  stage1.row4 = input[2] - input[4];
  stage1.row5 = input[1] - input[5];
  stage1.row6 = input[0] - input[6];
  stage1.row7 = input[7]           ;
  
  
  //stage 2
  stage2.row0 = stage1.row0 + stage1.row3;
  stage2.row1 = stage1.row1 + stage1.row2;
  stage2.row2 = stage1.row1 - stage1.row2;
  stage2.row3 = stage1.row0 - stage1.row3;
  stage2.row4 = stage1.row4 + stage1.row5;
  stage2.row5 = stage1.row5 + stage1.row6;
  stage2.row6 = stage1.row6 + stage1.row7;
  stage2.row7 = stage1.row7              ;
  
  //stage 3
  stage3.row0 = stage2.row0 + stage2.row1;
  stage3.row1 = stage2.row0 - stage2.row1;
  stage3.row2 = stage2.row2 + stage2.row3;
  stage3.row3 = stage2.row3              ;
  stage3.row4 = stage2.row4              ;
  stage3.row5 = stage2.row5              ;
  stage3.row6 = stage2.row6              ;
  stage3.row7 = stage2.row7              ;
  
  //stage 4 
  // a1 = 0.707 0.10110101
  // a2 = 0.541 0.10001010
  // a3 = 0.707 0.10110101
  // a4 = 1.307 1.01001111
  // a5 = 0.383 0.01100010
  stage4.row0 = stage3.row0                     ;
  stage4.row1 = stage3.row1                     ;
  stage4.row2 = (stage3.row2>>1)+(stage3.row2>>3)+(stage3.row2>>4)+((stage3.row2+32)>>6)+((stage3.row2+128)>>8);
  stage4.row3 = stage3.row3                     ;
  
  temp_buff   = stage3.row4 + stage3.row6;
  temp_buff   = (temp_buff>>2)+(temp_buff>>3)+((temp_buff+64)>>7);
  stage4.row4 = (stage3.row4>>1)+((stage3.row4+16)>>5)+((stage3.row4+64)>>7)- temp_buff;
  stage4.row5 = (stage3.row5>>1)+(stage3.row5>>3)+(stage3.row5>>4)+((stage3.row5+32)>>6)+((stage3.row5+128)>>8);
  stage4.row6 = stage3.row6+(stage3.row6>>2)+(stage3.row6>>5)+(stage3.row6>>6)+(stage3.row6>>7)+(stage3.row6>>8)-temp_buff;
  stage4.row7 = stage3.row7                     ;
  
  //stage 5
  stage5.row0 = stage4.row0              ;
  stage5.row1 = stage4.row1              ;
  stage5.row2 = stage4.row3 + stage4.row2;
  stage5.row3 = stage4.row3 - stage4.row2;
  stage5.row4 = stage4.row4              ;
  stage5.row5 = stage4.row5 + stage4.row7;
  stage5.row6 = stage4.row6              ;
  stage5.row7 = stage4.row7 - stage4.row5;

  //stage 6 Output
  output[0] = stage5.row0              ;
  output[4] = stage5.row1              ;
  output[2] = stage5.row2              ;
  output[6] = stage5.row3              ;
  output[5] = stage5.row4 + stage5.row7;
  output[1] = stage5.row5 + stage5.row6;
  output[7] = stage5.row5 - stage5.row6;
  output[3] = stage5.row4 + stage5.row7;

  }
  
//Driver

void main(){
  int intput[8] = {0,1,2,3,4,5,6,7};
  int output[8] = {0};
  int flag = 0;
  dct_aan(input,output);
  printf("transform complete, print out Output values to see the output");
}
