/*
 * piece.h
 *
 *  Created on: Jun 8, 2021
 *      Author: victor
 */

#ifndef INC_PIECE_H_
#define INC_PIECE_H_


#include "fatfs.h"
#include <stdint.h>
#include <math.h>


#define MAX_PIECE_NAME_BYTE_SIZE 128
#define MAX_COMPOSITION_BYTE_SIZE 32768


#define CAPTURE_TICK_PERIOD_MS 50




#define LARGE 0
#define LONG 1
#define BREVE 2
#define SEMIBREVE 3 // WHOLE NOTE
#define MINIM 4
#define CROTCHET 5 // QUARTER NOTE
#define QUAVER 6
#define SEMIQUAVER 7
#define DEMISEMIQUAVER 8
#define HEMIDEMISEMIQUAVER 9
#define SEMIHEMIDEMISEMIQUAVER 10
#define DEMISEMIHEMIDEMISEMIQUAVER 11


#define G_STRING 0UL
#define D_STRING 1UL
#define A_STRING 2UL
#define E_STRING 3UL


#define G_STRING_PITCH_TICK_OFFSET 0
#define D_STRING_PITCH_TICK_OFFSET 10
#define A_STRING_PITCH_TICK_OFFSET 20
#define E_STRING_PITCH_TICK_OFFSET 30







#define FCPU 80000000.0
#define PWM_PRESCALE 8.0
#define PITCH_RESOLUTION (FCPU/PWM_PRESCALE)
#define GET_PITCH_CHZ_TICK(f_chz) ((uint16_t)(round(PITCH_RESOLUTION/(f_chz/100.0))))



extern TIM_HandleTypeDef htim1;



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




#define NUM_PITCH_TICKS 72
uint16_t pusPitchTickMap[NUM_PITCH_TICKS];





typedef struct
{
	FATFS fs;
	FATFS *pfs;
	FIL fil;
	FRESULT fres;
	DWORD fre_clust;
	uint32_t totalSpace, freeSpace;
} PieceFATFSHandle_t;


typedef struct
{
	uint32_t ulInstructionCounter;
	uint8_t usCommand;
	uint16_t uPlay;
} PieceInstructionHandle_t;


typedef struct
{
	uint8_t pusName[MAX_PIECE_NAME_BYTE_SIZE];
} PieceInformationHandle_t;



typedef struct
{
	uint8_t usMovement;
	uint16_t uBPM;
	uint8_t usDynamic;
} PieceConfigurationHandle_t;



typedef struct
{
	uint32_t ulCompositionByteSize;
	uint8_t pusComposition[MAX_COMPOSITION_BYTE_SIZE];
} PieceCompositionHandle_t;





typedef struct
{
	uint8_t bActive;
	uint8_t ucTechnique;
	uint8_t ucFingerOffset;
} PieceNoteGoalHandle_t;


typedef struct
{
	PieceNoteGoalHandle_t xGString;
	PieceNoteGoalHandle_t xDString;
	PieceNoteGoalHandle_t xAString;
	PieceNoteGoalHandle_t xEString;
} PieceGoalHandle_t;




typedef struct
{
	uint32_t ulTick;

} PieceCaptureHandle_t;




typedef struct
{
	// Information
	PieceInstructionHandle_t xPieceInstruction;
	PieceInformationHandle_t xPieceInformation;
	PieceConfigurationHandle_t xPieceConfiguration;
	PieceCompositionHandle_t xComposition;
	PieceGoalHandle_t xGoal;
	PieceCaptureHandle_t xCapture;
} PieceHandle_t;



void Piece_vInit(PieceHandle_t *pxPiece, FIL *pFil);
void Piece_vSetCompositionByteSize(PieceHandle_t *pxPiece, FIL *pFil);
void Piece_vSetComposition(PieceHandle_t *pxPiece, FIL *pFil);




void Piece_vParseCommand(PieceHandle_t *pxPiece);
void Piece_vSetMovement(PieceHandle_t *pxPiece, uint8_t usMovement);
void Piece_vSetBPM(PieceHandle_t *pxPiece, uint16_t uBPM);
void Piece_vSetDynamic(PieceHandle_t *pxPiece, uint8_t usDynamic);
void Piece_vConfigureAll(PieceHandle_t *pxPiece);


/* Returns true if is a play command rather than a configure command */
uint8_t bIsPlayCommand(uint8_t usCommand);

/* Get the tick pitch of a note based on string a finger/offset */
uint16_t Piece_usGetPitchTick(uint8_t ucString, uint8_t ucOffset);

/* Based on the current performance and goal, update scores */
void Piece_vUpdatePerformanceStats(PieceHandle_t *pxPiece);

/* Capture currently played notes (fragment) and compare to goal */
void Piece_vCaptureFragment(PieceHandle_t *pxPiece, int32_t lMSPerDemisemi);


/* Reset all note goal in preparation for setting the next goal */
void Piece_vResetGoal(PieceHandle_t *pxPiece);

/* Read and set individual note goal */
void Piece_vSetNoteGoal(PieceHandle_t *pxPiece);

/* Read and set all notes goal */
void Piece_vSetGoal(PieceHandle_t *pxPiece, uint8_t numNotes);

/* Sets the goal and periodically captures the notes played for accuracy */
void Piece_vPlayNotes(PieceHandle_t *pxPiece, uint8_t ucBeatValue, uint8_t ucNumNotes);





/* DEBUG */
void Piece_Debug_vPrintPointer(PieceHandle_t *pxPiece, FIL *pFil);
void Piece_Debug_vPrintGoal(PieceHandle_t *pxPiece);



#endif /* INC_PIECE_H_ */
