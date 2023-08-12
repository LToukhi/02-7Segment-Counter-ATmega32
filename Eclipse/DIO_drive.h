/*
 * DIO_drive.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Al-toukhi
 */

#ifndef DIO_DRIVE_H_
#define DIO_DRIVE_H_

#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define Input   0
#define Output  1

#define Low     0
#define High    1

void DIO_Port_Mode(u8 port_ID , u8 mode) ;
void DIO_Port_State(u8 port_ID  , u8 state) ;

void DIO_Pin_Mode(u8 port_ID , u8 pin_ID , u8 mode) ;
void DIO_Pin_State(u8 port_ID , u8 pin_ID , u8 state) ;

u8 DIO_Pin_Read(u8 port_ID , u8 pin_ID ) ;

void DIO_Port_Value(u8 port_ID , u8 value) ;


#endif /* DIO_DRIVE_H_ */
