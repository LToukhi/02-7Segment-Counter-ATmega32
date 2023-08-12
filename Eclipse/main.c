/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Al-toukhi
 */

#include <avr/io.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_drive.h"
#include <util/delay.h>



void main()
{
	DIO_Port_Mode(PORTC , Output) ;

	while(1)
	{
		for(u8 value=0 ; value<=9 ; value++ )
		{
			DIO_Port_Value(PORTC , value) ;
			_delay_ms(50) ;
			DIO_Port_State(PORTC , Low) ;
		}
	}
}

