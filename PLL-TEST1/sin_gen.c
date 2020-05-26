/*
 * sin_gen.c
 *
 *  Created on: 26 thg 5, 2020
 *      Author: HP
 */
#include "F28x_Project.h"
#include "F2837xD_Examples.h"
#include "Setup_PLL.h"
extern float sin_tab[];
void sin_gen(void)
{
   float  goc, sin_out;

//   InitSysCtrl();
//   GPIOsetup();
//   DINT;
//   InitPieCtrl();
//   IER = 0x0000;
//   IFR = 0x0000;
//   InitPieVectTable();
//   EALLOW;
//   PieVectTable.TIMER2_INT = &cpu_timer2_isr;
//   ConfigCpuTimer(&CpuTimer0, 200, 100);
//   CpuTimer2Regs.TCR.all = 0x4000;
//   IER |= M_INT1;
//      IER |= M_INT13;
//      IER |= M_INT14;
//      PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
//      EINT;
//      ERTM;
}

