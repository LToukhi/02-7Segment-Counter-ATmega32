/*
 * DIO_drive.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Al-toukhi
 */

#ifndef DIO_DRIVE_C_
#define DIO_DRIVE_C_

#include "BIT_math.h"
#include "STD_types.h"
#include "DIO_drive.h"
//registers addresses///////////////////////////////

#define DIO_PORTA_Reg    *((volatile u8*) 0x3B)
#define DIO_DDRA_Reg     *((volatile u8*) 0x3A)
#define DIO_PINA_Reg     *((volatile u8*) 0x39)

#define DIO_PORTB_Reg    *((volatile u8*) 0x38)
#define DIO_DDRB_Reg     *((volatile u8*) 0x37)
#define DIO_PINB_Reg     *((volatile u8*) 0x36)

#define DIO_PORTC_Reg    *((volatile u8*) 0x35)
#define DIO_DDRC_Reg     *((volatile u8*) 0x34)
#define DIO_PINC_Reg     *((volatile u8*) 0x33)

#define DIO_PORTD_Reg    *((volatile u8*) 0x32)
#define DIO_DDRD_Reg     *((volatile u8*) 0x31)
#define DIO_PIND_Reg     *((volatile u8*) 0x30)





//port mode func///////////////////////////////////

void DIO_Port_Mode(u8 port_ID , u8 mode)
{
	if(mode == Output)
	{
		switch(port_ID)
		{
			case PORTA : set_byte(DIO_DDRA_Reg , 0xff) ; break ;
			case PORTB : set_byte(DIO_DDRB_Reg , 0xff) ; break ;
    		case PORTC : set_byte(DIO_DDRC_Reg , 0xff) ; break ;
			case PORTD : set_byte(DIO_DDRD_Reg , 0xff) ; break ;
		}
	}
	else if(mode == Input)
	{
		switch(port_ID)
		{
		    case PORTA : set_byte(DIO_DDRA_Reg , 0x00) ; break ;
		    case PORTB : set_byte(DIO_DDRB_Reg , 0x00) ; break ;
		    case PORTC : set_byte(DIO_DDRC_Reg , 0x00) ; break ;
		    case PORTD : set_byte(DIO_DDRD_Reg , 0x00) ; break ;
		}
	}
}








//port_output_state_func////////////////////////////
void DIO_Port_State(u8 port_ID , u8 state)
{
	if(state == High)
	{
		switch(port_ID)
		{
			case PORTA : set_byte(DIO_PORTA_Reg , 0xff) ; break ;
			case PORTB : set_byte(DIO_PORTB_Reg , 0xff) ; break ;
		    case PORTC : set_byte(DIO_PORTC_Reg , 0xff) ; break ;
			case PORTD : set_byte(DIO_PORTD_Reg , 0xff) ; break ;
		}
	}
	else if(state == Low)
	{
		switch(port_ID)
		{
			case PORTA : set_byte(DIO_PORTA_Reg , 0x00) ; break ;
			case PORTB : set_byte(DIO_PORTB_Reg , 0x00) ; break ;
		    case PORTC : set_byte(DIO_PORTC_Reg , 0x00) ; break ;
			case PORTD : set_byte(DIO_PORTD_Reg , 0x00) ; break ;
		}
	}
}


//port_output_value/////////////////////////////////////

void DIO_Port_Value(u8 port_ID , u8 value)
{
	switch(port_ID)
	{
		case PORTA : set_byte(DIO_PORTA_Reg , value) ; break ;
		case PORTB : set_byte(DIO_PORTB_Reg , value) ; break ;
		case PORTC : set_byte(DIO_PORTC_Reg , value) ; break ;
		case PORTD : set_byte(DIO_PORTD_Reg , value) ; break ;
	}
}



//pin_mode_func///////////////////////////////////////////////

void DIO_Pin_Mode(u8 port_ID , u8 pin_ID , u8 mode)
{
	//Output////////////////

	if(mode == Output)
	{
		switch(port_ID)
		{
			case PORTA : set_bit(DIO_DDRA_Reg , pin_ID) ; break ;
			case PORTB : set_bit(DIO_DDRB_Reg , pin_ID) ; break ;
			case PORTC : set_bit(DIO_DDRC_Reg , pin_ID) ; break ;
			case PORTD : set_bit(DIO_DDRD_Reg , pin_ID) ; break ;
		}
	}
	else if(mode == Input)
	{
		switch(port_ID)
		{
			case PORTA : clr_bit(DIO_DDRA_Reg , pin_ID) ; break ;
			case PORTB : clr_bit(DIO_DDRB_Reg , pin_ID) ; break ;
			case PORTC : clr_bit(DIO_DDRC_Reg , pin_ID) ; break ;
			case PORTD : clr_bit(DIO_DDRD_Reg , pin_ID) ; break ;
		}
	}
}





//pin_output_state_func/////////////////////////////////////

void DIO_Pin_State(u8 port_ID , u8 pin_ID , u8 state)
{
	if(state == High)
	{
		switch(port_ID)
		{
			case PORTA : set_bit(DIO_PORTA_Reg , pin_ID) ; break ;
			case PORTB : set_bit(DIO_PORTB_Reg , pin_ID) ; break ;
			case PORTC : set_bit(DIO_PORTC_Reg , pin_ID) ; break ;
			case PORTD : set_bit(DIO_PORTD_Reg , pin_ID) ; break ;
		}
	}
	else if(state == Low)
	{
		switch(port_ID)
		{
			case PORTA : clr_bit(DIO_PORTA_Reg , pin_ID) ; break ;
			case PORTB : clr_bit(DIO_PORTB_Reg , pin_ID) ; break ;
			case PORTC : clr_bit(DIO_PORTC_Reg , pin_ID) ; break ;
			case PORTD : clr_bit(DIO_PORTD_Reg , pin_ID) ; break ;
		}
	}

}





//pin_read_func////////////////////////

u8 DIO_Pin_Read(u8 port_ID , u8 pin_ID)
{
	u8 read ;
	switch(port_ID)
	{
		case PORTA : read = get_bit(DIO_PINA_Reg , pin_ID) ; break ;
		case PORTB : read = get_bit(DIO_PINB_Reg , pin_ID) ; break ;
		case PORTC : read = get_bit(DIO_PINC_Reg , pin_ID) ; break ;
		case PORTD : read = get_bit(DIO_PIND_Reg , pin_ID) ; break ;
	}
return read ;
}

#endif /* DIO_DRIVE_C_ */
