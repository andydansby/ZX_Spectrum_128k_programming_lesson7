#ifndef EXTERNS_H
#define EXTERNS_H
//UNCONTENDED RAM


//VARIABLES
extern unsigned char Variable_in_contended;//found in ramlow.asm
extern unsigned char Variable_in_Bank0;//found in ram0Z.asm
extern unsigned char ada;//found in IM2.asm

//FUNCTIONS
/*
__fastcall__
 Fastcall linkage allows one parameter
 to be passed by register in a subset of DEHL.
 So if the parameter is 8-bit, the value will
 be in L.  If the parameter is 16-bit,
 the value is in HL and if it is
 32-bit the value is in DEHL.
*/

//found in ramlow > routines.h
extern unsigned char add_two_numbers (unsigned char a, unsigned char b);

//found in ram0.h
extern unsigned char subtract2numbers (unsigned char A, unsigned char B);

//found in uncontended_section.asm
extern void __FASTCALL__ border_Change_uncontended(unsigned char color);


//attention new
extern unsigned char screen1[];
extern unsigned char screen2[];
extern unsigned char screen3[];

//found in uncontended.asm
// hl = source
// de = destination
extern void __FASTCALL__ dzx0_turbo(void);
extern unsigned int zx0_source;
extern unsigned int zx0_destination;
;//attention new
//////////////////////////////////////////

//found in im2.asm
extern void __FASTCALL__ SETUP_IM2 (void);

//found in RAM0Z.asm
extern void __FASTCALL__ border_Change_RAM0(unsigned char color);


#endif
