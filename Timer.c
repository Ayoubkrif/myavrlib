/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:26:06 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "myavrlib.h"
// CLKPR |= (1 << CLKPCE) | (1 << CLKPS3) | (1 << CLKPS2) | (1 << CLKPS1) | (1 << CLKPS0); prescaler register

inline void	CTC_Toggle_Timer1(void)// mod01 ex01 
{
	// prescale de 1024
	BITSET(TCCR1B, CS10);
	BITSET(TCCR1B, CS12);
	//	CTC compara avec OCR1A
	//	0100
	BITSET(TCCR1B, WGM12);

	//mode toggle OC1A
	//01
	BITSET(TCCR1A, COM1A0);

	OCR1A = 7812;
	// 132 :
	// fOCnA = F_CPU / (2 * prescaler * (1 + OCRnA))
	// ie OCR1A = (F_CPU / 2prescaler) - 1
}

inline void	FastPWM_FFFFTOP_Timer1(void)// mod01 ex02
{
	// prescale de 1024
	// table 16-5
	BITSET(TCCR1B, CS10);
	BITSET(TCCR1B, CS12);

	// clear mode OC1A
	// set at BOTTOM
	// table 16-2
	BITSET(TCCR1A, COM1A1);

	ICR1 = 15625; // double of the previous value of OCR1A 
	OCR1A = 1562; // 10% of previous value
}

inline void	CTC_interrupt_Timer1(void)// mod02 ex01
{
	//	CTC compara avec OCR1A
	//	0100
	BITSET(TCCR1B, WGM12);
	// prescale de 1024
	BITSET(TCCR1B, CS10);
	BITSET(TCCR1B, CS12);
	// compare to 2 sec
	OCR1A = 31250;
	TIMSK1 = 0;
	BITSET(TIMSK1, OCIE1A);
}

inline void	Timer1_FastPWM_TopICR1A(void)
{
	//	fast PWM pour top ICR1A
	//	1110
	//	table 15 -5
	BITCLR(TCCR1A, WGM10);
	BITSET(TCCR1A, WGM11);
	BITSET(TCCR1B, WGM12);
	BITSET(TCCR1B, WGM13);
}

inline void	Timer1_CTC(void)
{
	//	CTC top 0cr1a
	//	0100
	//	table 15 -5
	BITCLR(TCCR1A, WGM10);
	BITCLR(TCCR1A, WGM11);
	BITSET(TCCR1B, WGM12);
	BITCLR(TCCR1B, WGM13);
}


inline void	Timer1_1024Pr(void)
{
	// 101
	BITSET(TCCR1B, CS10);
	BITCLR(TCCR1B, CS11);
	BITSET(TCCR1B, CS12);
}

inline void	Timer1_noPr(void)
{
	// 001
	BITSET(TCCR1B, CS10);
	BITCLR(TCCR1B, CS11);
	BITCLR(TCCR1B, CS12);
}

inline void	Timer1_AClearOnComp(void) // work on fast pwm
{
	//10
	BITCLR(TCCR1A, COM1A0);
	BITSET(TCCR1A, COM1A1);
}

inline void	Timer2_FastPWM(void)// mod01 ex02
{
	//	fast PWM timer2
	//	011
	//	table 17-8 p130
	//	011
	BITSET(TCCR2A, WGM20);
	BITSET(TCCR2A, WGM21);
	BITCLR(TCCR2B, WGM22);
}

inline void	Timer2_1024Pr(void)
{
	// prescale de 1024
	// 111
	BITSET(TCCR2B, CS20);
	BITSET(TCCR2B, CS21);
	BITSET(TCCR2B, CS22);
}

inline void	Timer2_noPr(void)
{
	// prescale de 1024
	// 111
	BITCLR(TCCR2B, CS20);
	BITCLR(TCCR2B, CS21);
	BITSET(TCCR2B, CS22);
}

inline void	Timer2_BClearOnComp(void) // work on fast pwm
{
	// 10
	BITCLR(TCCR2A, COM2B0);
	BITSET(TCCR2A, COM2B1);
}

inline void	Timer0_FastPWM(void)// mod01 ex02
{
	//	fast PWM timer2
	//	table 17-8 p130
	//	011
	BITSET(TCCR0A, WGM00);
	BITSET(TCCR0A, WGM01);
	BITCLR(TCCR0B, WGM02);
}

inline void	Timer0_CTC(void)// mod01 ex02
{
	//	CTC Timer0 Compare A
	//	Table 14-8. Waveform Generation Mode Bit Description p86
	//	010
	BITCLR(TCCR0A, WGM00);
	BITSET(TCCR0A, WGM01);
	BITCLR(TCCR0B, WGM02);
}

inline void	Timer0_normal(void)// mod01 ex02
{
	//	Normal Timer0
	//	Table 14-8. Waveform Generation Mode Bit Description p86
	//	000
	BITCLR(TCCR0A, WGM00);
	BITCLR(TCCR0A, WGM01);
	BITCLR(TCCR0B, WGM02);
}

inline void	Timer0_1024Pr(void)
{
	// prescale de 1024
	// Table 14-9 p87
	// 101
	BITSET(TCCR0B, CS00);
	BITCLR(TCCR0B, CS01);
	BITSET(TCCR0B, CS02);
}

inline void Timer0_64Pr(void)
{
    // Prescaler 64
    BITSET(TCCR0B, CS00);
    BITSET(TCCR0B, CS01);
    BITCLR(TCCR0B, CS02);
}

inline void	Timer0_noPr(void)
{
	// prescale de 1
	// 001
	BITCLR(TCCR0B, CS00);
	BITCLR(TCCR0B, CS01);
	BITSET(TCCR0B, CS02);
}

inline void	Timer0_AClearOnComp(void) // work on fast pwm
{
	// 10
	BITCLR(TCCR0A, COM0A0);
	BITSET(TCCR0A, COM0A1);
}

inline void	Timer0_BClearOnComp(void) // work on fast pwm
{
	// 10
	BITCLR(TCCR0A, COM0B0);
	BITSET(TCCR0A, COM0B1);
}

inline void	Timer0_Int_A_Enable(void)// mod01 ex02
{
	BITSET(TIMSK0, OCIE0A);
}

inline void	Timer0_Int_A_Disable(void)// mod01 ex02
{
	BITCLR(TIMSK0, OCIE0A);
}

inline void	Timer0_Int_Ov_Enable(void)
{
	BITSET(TIMSK0, TOIE0);
}// mod01 ex02

inline void	Timer0_Int_Ov_Disable(void)
{
	BITCLR(TIMSK0, TOIE0);
};// mod01 ex02
