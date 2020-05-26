#include "Solar_F.h"
#include"math.h"
#include "Setup_PLL.h"
#include "F28x_Project.h"
#include "F2837xD_Examples.h"
extern float sin_tab[];
void GPIOsetup(void);
#define GRID_FREQ 50
#define ISR_FREQUENCY 20000
#define PI 3.14159265359
SPLL_1ph_SOGI_F spll1;
int count = 0 ;
float  goc, sin_in;
int index = 0 ;
void main(void)
{
       InitSysCtrl();
       GPIOsetup();

       SetupADCSoftware();
       ConfigureDAC();
       DINT;

       InitPieCtrl();
       IER = 0x0000;
       IFR = 0x0000;
       InitPieVectTable();
       EALLOW;
//       PieVectTable.TIMER0_INT = &cpu_timer0_isr;
       PieVectTable.TIMER1_INT = &cpu_timer1_isr;
       PieVectTable.TIMER2_INT = &cpu_timer2_isr;
       EDIS;
       InitCpuTimers();
//       ConfigCpuTimer(&CpuTimer0, 200,5000);
       ConfigCpuTimer(&CpuTimer1, 200,50);
       ConfigCpuTimer(&CpuTimer2, 200, 100);
      CpuTimer0Regs.TCR.all = 0x4000;
       CpuTimer1Regs.TCR.all = 0x4000;
       CpuTimer2Regs.TCR.all = 0x4000;

          IER |= M_INT1;
          IER |= M_INT13;
          IER |= M_INT14;
          PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
          EINT;
          ERTM;
          ConfigureDAC();
    SPLL_1ph_SOGI_F_init(GRID_FREQ,((float)(1.0/ISR_FREQUENCY)),&spll1);
    SPLL_1ph_SOGI_F_coeff_update(((float)(1.0/ISR_FREQUENCY)),(float)(2*PI*GRID_FREQ),&spll1);

    while(1)
    {
        DacbRegs.DACVALS.all = spll1.sin  *1500 + 1500 ;
//        DacaRegs.DACVALS.all = spll1.sin * 1500 + 1500  ;// output PLL
        DacaRegs.DACVALS.all = sin_in * 1500 + 1500  ;// output PLL

    }
}
void GPIOsetup(void)
{
 EALLOW;
      GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;// I/O
      GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;// I/O
      GpioCtrlRegs.GPBDIR.bit.GPIO34  = 1;// Output
      GpioCtrlRegs.GPADIR.bit.GPIO31  = 1;// Output

  EDIS;
}


__interrupt void cpu_timer2_isr(void)
   {
      CpuTimer2.InterruptCount++;
      count++;
      if (count <=5000)
      {
          GpioDataRegs.GPBDAT.bit.GPIO34 = 0;
          GpioDataRegs.GPADAT.bit.GPIO31 = 1;
      }
      else
      {
          GpioDataRegs.GPBDAT.bit.GPIO34 = 1;
          GpioDataRegs.GPADAT.bit.GPIO31 = 0;
          if (count >=10000)
              count = 0;
      }

      if (goc >2*PI)
          goc = 0;

          goc = goc + 50 * 2* PI *  0.0001;

          index = (int) (goc*2047/ (2*PI)) ;
      sin_in = sin_tab[index] ;


      PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
   }
__interrupt void cpu_timer1_isr(void)
{
    CpuTimer1.InterruptCount++;
    spll1.u[0]=(float32)sin_in;
    SPLL_1ph_SOGI_F_FUNC(&spll1);
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
void ConfigureDAC(void)
{
    EALLOW;
    DacbRegs.DACCTL.bit.DACREFSEL = 1;          // Use ADC references
    DacbRegs.DACCTL.bit.LOADMODE = 0;           // Load on next SYSCLK
                    // Set mid-range
    DacbRegs.DACOUTEN.bit.DACOUTEN = 1;         // Enable DAC

    DacaRegs.DACCTL.bit.DACREFSEL = 1;          // Use ADC references
    DacaRegs.DACCTL.bit.LOADMODE = 0;           // Load on next SYSCLK
                    // Set mid-range
    DacaRegs.DACOUTEN.bit.DACOUTEN = 1;         // Enable DAC

    DaccRegs.DACCTL.bit.DACREFSEL = 1;          // Use ADC references
    DaccRegs.DACCTL.bit.LOADMODE = 0;           // Load on next SYSCLK
                        // Set mid-range
    DaccRegs.DACOUTEN.bit.DACOUTEN = 1;         // Enable DAC
    EDIS;
}
//void ConfigureADC(void)
//{
//    EALLOW;
//    //write configurations
//    AdcaRegs.ADCCTL2.bit.PRESCALE = 6; //set ADCCLK divider to /4
//    AdcSetMode(ADC_ADCA, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);
//    AdcSetMode(ADC_ADCB, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);
//    //Set pulse positions to late
//    AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;
//    //power up the ADCs
//    AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1;
//    AdcbRegs.ADCCTL1.bit.ADCPWDNZ = 1;
//    //delay for 1ms to allow ADC time to power up
//    DELAY_US(1000);
//    EDIS;
//}

// SetupADCSoftware - Setup ADC channels and acquisition window
void SetupADCSoftware(void)
{
    //Select the channels to convert and end of conversion flag ADCA
    EALLOW;
    AdcaRegs.ADCSOC0CTL.bit.CHSEL = 0;  //SOC0 will convert pin A0
    AdcaRegs.ADCSOC0CTL.bit.ACQPS = 19; //sample window is acqps +
    AdcaRegs.ADCSOC1CTL.bit.CHSEL = 1;
    AdcaRegs.ADCSOC1CTL.bit.ACQPS = 19;

    AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 1; //end of SOC1 will set INT1 flag
    AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1;   //enable INT1 flag
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; //make sure INT1 flag is cleared
    EDIS;
}

