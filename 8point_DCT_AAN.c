
#include <stdio.h>

/*
  @ Description: A 8 point 1-D AAN DCT
  @ Author:      Pratyush Kumar Ranjan
  @ Email:       pratyushkmr@live.com
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

void 8point_dct_aan(int*, int* );
void 8point_dct_aan(int* input, int* output){
  
  int iter;
  int temp_buff;
 
  dct_stage stage1;
  dct_stage stage2;
  dct_stage stage3;
  dct_stage stage4;
  dct_stage stage5;
  dct_stage stage6;
 
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
  
  //stage 4 to Update
  stage4.row0 = stage3.row0                     ;
  stage4.row1 = stage3.row1                     ;
  stage4.row2 = stage3.row2*[a1]                ;
  stage4.row3 = stage3.row3                     ;
  temp_buff   = a[5]*(stage3.row4 + stage3.row6);
  stage4.row4 = stage3.row4[a2]- temp_buff      ;
  stage4.row5 = stage3.row5*a3                  ;
  stage4.row6 = stage3.row6*a4 - temp_buff      ;
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

  //stage 6
  stage6.row0 = stage5.row0              ;
  stage6.row1 = stage5.row1              ;
  stage6.row2 = stage5.row2              ;
  stage6.row3 = stage5.row3              ;
  stage6.row4 = stage5.row4 + stage5.row7;
  stage6.row5 = stage5.row5 + stage5.row6;
  stage6.row6 = stage5.row5 - stage5.row6;
  stage6.row7 = stage5.row4 + stage5.row7;

  //output
  output
  output
  output
  output

  
  }
  
//Driver

void main(){

}
