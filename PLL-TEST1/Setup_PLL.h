/*
 * Setup_PLL.h
 *
 *  Created on: 26 thg 5, 2020
 *      Author: HP
 */

#ifndef SETUP_PLL_H_
#define SETUP_PLL_H_
void SetupADCSoftware(void);
void ConfigureDAC(void);
void sin_gen(void );
__interrupt void cpu_timer0_isr(void);
__interrupt void cpu_timer1_isr(void);
__interrupt void cpu_timer2_isr(void);


#endif /* SETUP_PLL_H_ */
