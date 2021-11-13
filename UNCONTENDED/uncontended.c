// using sccz80 1.99c

//lesson for using zx0 compressor and loading compressed assets to memory
//attention, needs to be rewritten due to ZX0 being rewritten
//https://github.com/einar-saukas/ZX0

#include <arch/zx.h>
#include <stdio.h>//standard input output
#include <input.h>//used for detecting key inputs
#include <intrinsic.h>//temp to place labels
//powerful troubleshooting tool
        //intrinsic_label(border_start);
        //intrinsic_label(border_end);

#include "variables.h"
#include "externs.h"
#include "uncontended.h"


void main ()
{

    SETUP_IM2();// set up for the interrupt manager 2
    // this will point the I register to IM2 Vector

    zx_cls(PAPER_WHITE);
    printf("\x16\x01\x02");
    printf ("Main () running in uncontended\n");

    printf ("_Variable_in_contended = %d\n", Variable_in_contended);
    printf ("_Variable_in_Bank0 = %d\n", Variable_in_Bank0);

    printf ("tom = %d\n", tom);
    printf ("dick = %d\n", dick);
    printf ("harry = %d\n", harry);
    printf ("eve = %u\n", eve);
    printf ("bob = %u\n\n", bob);


    harry = add_two_numbers (tom, dick);
    printf ("Add 2 numbers %u + %u = %u\n", tom, dick, harry);

    harry = subtract2numbers (Variable_in_Bank0, eve);
    printf ("Subtract 2 numbers %u - %u = %u\n", Variable_in_Bank0, eve, harry);

    harry = multiply2numbers (Variable_in_contended, bob);
    printf ("Multiply 2 numbers %u * %u = %u\n", Variable_in_contended, bob, harry);

    harry = add_two_numbers (Variable_in_contended, Variable_in_Bank0);
    printf ("Add 2 numbers %u + %u = %u\n", Variable_in_contended, Variable_in_Bank0, harry);

    printf("\n\nPress 0-7 for Border Test\n");

    in_pause(2000);

    while(1)
    {
        //attention new
        ZX0_decompress (16384, &screen1);
        in_pause(1000);
        ZX0_decompress (16384, &screen2);
        in_pause(1000);
        ZX0_decompress (16384, &screen3);
        in_pause(1000);

        key_test();
    }
}


// must have blank line at end
