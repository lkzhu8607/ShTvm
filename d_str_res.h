
#ifndef K1__d_str_res_H
#define K1__d_str_res_H

#include "2.h" 


//string resoureces
//用excel粘贴进来
#define SR_HELLO 2
#define SR_IN_SERVICE 3
#define SR_OUT_OF_SERVICE 4
#define SR_COIN_ONLY 5
#define SR_NOTE_ONLY 6
#define SR_NO_CHANGE 7




//
extern void SetLanguageCh(); 
extern void SetLanguageEn(); 
extern int GetLanguageState();
extern const char * GetStrRes( int idx ); 




#endif

