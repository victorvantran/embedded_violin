/*
 * violin.h
 *
 *  Created on: Jul 6, 2021
 *      Author: victor
 */

#ifndef INC_VIOLIN_H_
#define INC_VIOLIN_H_


/*
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim15;
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;


#define G_TIMER htim1
#define D_TIMER htim15
#define A_TIMER htim16
#define E_TIMER htim17


#define G_TIMER_CHANNEL TIM_CHANNEL_1
#define D_TIMER_CHANNEL TIM_CHANNEL_1
#define A_TIMER_CHANNEL TIM_CHANNEL_1
#define E_TIMER_CHANNEL TIM_CHANNEL_1








#define G_STRING 0UL
#define D_STRING 1UL
#define A_STRING 2UL
#define E_STRING 3UL


#define G_STRING_PITCH_TICK_OFFSET 0
#define D_STRING_PITCH_TICK_OFFSET 10
#define A_STRING_PITCH_TICK_OFFSET 20
#define E_STRING_PITCH_TICK_OFFSET 30


#define G_STRING_FINGER_OFFSET 29
#define D_STRING_FINGER_OFFSET 30
#define A_STRING_FINGER_OFFSET 89
#define E_STRING_FINGER_OFFSET 90






#define FCPU 80000000.0
#define PWM_PRESCALE 8.0
#define PITCH_RESOLUTION (FCPU/PWM_PRESCALE)
#define GET_PITCH_CHZ_TICK(f_chz) ((uint16_t)(round(PITCH_RESOLUTION/(f_chz/100.0))))






typedef enum
{

	G3_CHZ 	= 19600,

	Gs3_CHZ = 20765,
	Ab3_CHZ = 20765,

	A3_CHZ 	= 22000,

	As3_CHZ = 23308,
	Bb3_CHZ = 23308,

	B3_CHZ 	= 24694,

	C4_CHZ 	= 26163,

	Cs4_CHZ = 27718,
	Db4_CHZ = 27718,

	D4_CHZ 	= 29366,

	Ds4_CHZ = 31113,
	Eb4_CHZ =	31113,

	E4_CHZ 	= 32963,

	F4_CHZ 	= 34923,

	Fs4_CHZ = 36999,
	Gb4_CHZ = 36999,

	G4_CHZ 	= 39200,

	Gs4_CHZ = 41530,
	Ab4_CHZ = 41530,

	A4_CHZ 	= 44000,

	As4_CHZ = 46616,
	Bb4_CHZ = 46616,

	B4_CHZ 	= 49388,

	C5_CHZ 	= 52325,

	Cs5_CHZ = 55437,
	Db5_CHZ = 55437,

	D5_CHZ 	= 58733,


	Ds5_CHZ = 62225,
	Eb5_CHZ = 62225,

	E5_CHZ 	= 65925,

	F5_CHZ 	= 69846,

	Fs5_CHZ = 73999,
	Gb5_CHZ = 73999,

	G5_CHZ 	= 78399,

	Gs5_CHZ = 83061,
	Ab5_CHZ = 83061,

	A5_CHZ 	= 88000,

	As5_CHZ = 93233,
	Bb5_CHZ = 93233,

	B5_CHZ 	= 98777,

	C6_CHZ 	= 104650,

	Cs6_CHZ = 110873,
	Db6_CHZ = 110873,

	D6_CHZ 	= 117466,

	Ds6_CHZ = 124451,
	Eb6_CHZ = 124451,

	E6_CHZ 	= 131851,

	F6_CHZ 	= 139691,

	Fs6_CHZ = 147998,
	Gb6_CHZ = 147998,

	G6_CHZ 	= 156798,

	Gs6_CHZ = 166122,
	Ab6_CHZ = 166122,

	A6_CHZ 	= 176000,

	As6_CHZ = 186466,
	Bb6_CHZ = 186466,

	B6_CHZ 	= 197553,

	C7_CHZ 	= 209300,

	Cs7_CHZ = 221746,
	Db7_CHZ = 221746,

	D7_CHZ 	= 234932,

	Ds7_CHZ = 248902,
	Eb7_CHZ = 248902,

	E7_CHZ 	= 263702,

	F7_CHZ 	= 279383,

	Fs7_CHZ = 295996,
	Gb7_CHZ = 295996,

	G7_CHZ 	= 313596,

	Gs7_CHZ = 332244,
	Ab7_CHZ = 332244,

	A7_CHZ 	= 352000

} NoteFrequencyCHZ_t;


#define NUM_STRINGS 4
#define NUM_FINGERINGS 120


#define NUM_PITCH_TICKS 72
uint16_t pusNoteToPitchMap[NUM_PITCH_TICKS];




typedef struct
{
	uint8_t ucG;
	uint8_t ucD;
	uint8_t ucA;
	uint8_t ucE;
} FingerOffset_t;

#define NUM_NOTES_PER_STRING 42 // A#/Bb count as 2 notes
FingerOffset_t pucStringNoteToFingerMap[NUM_NOTES_PER_STRING];





typedef struct
{

} ViolinStateHandle_t;






*/


#endif /* INC_VIOLIN_H_ */
