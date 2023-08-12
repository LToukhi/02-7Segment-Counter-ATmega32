/*
 * BIT_math.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Al-toukhi
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(reg,bitno)      reg = reg|(1<<bitno)
#define clr_bit(reg,bitno)      reg = reg&(~(1<<bitno))
#define toggle_bit(reg,bitno)   reg = reg^(1<<bitno)
#define set_byte(reg,value)     reg = value

#define get_bit(reg,bitno)      (reg>>bitno)&0x01


#endif /* BIT_MATH_H_ */
