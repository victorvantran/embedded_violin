/*
 * piece.c
 *
 *  Created on: Jun 8, 2021
 *      Author: victor
 */

#include "piece.h"



uint16_t pusNoteToPitchMap[NUM_PITCH_TICKS] = {
		GET_PITCH_CHZ_TICK(G3_CHZ), 	GET_PITCH_CHZ_TICK(Gs3_CHZ),		GET_PITCH_CHZ_TICK(Ab3_CHZ),		GET_PITCH_CHZ_TICK(A3_CHZ),		GET_PITCH_CHZ_TICK(As3_CHZ),
		GET_PITCH_CHZ_TICK(Bb3_CHZ),		GET_PITCH_CHZ_TICK(B3_CHZ),		GET_PITCH_CHZ_TICK(C4_CHZ),		GET_PITCH_CHZ_TICK(Cs4_CHZ),		GET_PITCH_CHZ_TICK(Db4_CHZ),
		GET_PITCH_CHZ_TICK(D4_CHZ),		GET_PITCH_CHZ_TICK(Ds4_CHZ),		GET_PITCH_CHZ_TICK(Eb4_CHZ),		GET_PITCH_CHZ_TICK(E4_CHZ),		GET_PITCH_CHZ_TICK(F4_CHZ),
		GET_PITCH_CHZ_TICK(Fs4_CHZ),		GET_PITCH_CHZ_TICK(Gb4_CHZ),		GET_PITCH_CHZ_TICK(G4_CHZ),		GET_PITCH_CHZ_TICK(Gs4_CHZ),		GET_PITCH_CHZ_TICK(Ab4_CHZ),
		GET_PITCH_CHZ_TICK(A4_CHZ),		GET_PITCH_CHZ_TICK(As4_CHZ),		GET_PITCH_CHZ_TICK(Bb4_CHZ),		GET_PITCH_CHZ_TICK(B4_CHZ),		GET_PITCH_CHZ_TICK(C5_CHZ),
		GET_PITCH_CHZ_TICK(Cs5_CHZ),		GET_PITCH_CHZ_TICK(Db5_CHZ),		GET_PITCH_CHZ_TICK(D5_CHZ),		GET_PITCH_CHZ_TICK(Ds5_CHZ),		GET_PITCH_CHZ_TICK(Eb5_CHZ),
		GET_PITCH_CHZ_TICK(E5_CHZ),		GET_PITCH_CHZ_TICK(F5_CHZ),		GET_PITCH_CHZ_TICK(Fs5_CHZ),		GET_PITCH_CHZ_TICK(Gb5_CHZ),		GET_PITCH_CHZ_TICK(G5_CHZ),
		GET_PITCH_CHZ_TICK(Gs5_CHZ),		GET_PITCH_CHZ_TICK(Ab5_CHZ),		GET_PITCH_CHZ_TICK(A5_CHZ),		GET_PITCH_CHZ_TICK(As5_CHZ),		GET_PITCH_CHZ_TICK(Bb5_CHZ),
		GET_PITCH_CHZ_TICK(B5_CHZ),		GET_PITCH_CHZ_TICK(C6_CHZ),		GET_PITCH_CHZ_TICK(Cs6_CHZ),		GET_PITCH_CHZ_TICK(Db6_CHZ),		GET_PITCH_CHZ_TICK(D6_CHZ),
		GET_PITCH_CHZ_TICK(Ds6_CHZ),		GET_PITCH_CHZ_TICK(Eb6_CHZ),		GET_PITCH_CHZ_TICK(E6_CHZ),		GET_PITCH_CHZ_TICK(F6_CHZ),		GET_PITCH_CHZ_TICK(Fs6_CHZ),
		GET_PITCH_CHZ_TICK(Gb6_CHZ),		GET_PITCH_CHZ_TICK(G6_CHZ),		GET_PITCH_CHZ_TICK(Gs6_CHZ),		GET_PITCH_CHZ_TICK(Ab6_CHZ),		GET_PITCH_CHZ_TICK(A6_CHZ),
		GET_PITCH_CHZ_TICK(As6_CHZ),		GET_PITCH_CHZ_TICK(Bb6_CHZ),		GET_PITCH_CHZ_TICK(B6_CHZ),		GET_PITCH_CHZ_TICK(C7_CHZ),		GET_PITCH_CHZ_TICK(Cs7_CHZ),
		GET_PITCH_CHZ_TICK(Db7_CHZ),		GET_PITCH_CHZ_TICK(D7_CHZ), GET_PITCH_CHZ_TICK(Ds7_CHZ),		GET_PITCH_CHZ_TICK(Eb7_CHZ),		GET_PITCH_CHZ_TICK(E7_CHZ),
		GET_PITCH_CHZ_TICK(F7_CHZ),		GET_PITCH_CHZ_TICK(Fs7_CHZ),		GET_PITCH_CHZ_TICK(Gb7_CHZ),		GET_PITCH_CHZ_TICK(G7_CHZ),		GET_PITCH_CHZ_TICK(Gs7_CHZ),
		GET_PITCH_CHZ_TICK(Ab7_CHZ),		GET_PITCH_CHZ_TICK(A7_CHZ)
};



// [!] Check if base note and actual note difference <= 29. [You are not allowed to play an A7 on the G string]

/*
uint8_t pucStringNoteToFingerMap[NUM_FINGERINGS] = {
		0,	1,1,	2,	3,3,	4,	5,	6,6,	7,	8,8,	9,	10,	11,11,	12,	13,13,	14,	15,15,	16,	17,	18,18,	19,	20,20,	21,	22,	23,23,	24,	25,25,	26,	27,27,	28,	29,
		0,	1,1,	2,	3,	4,4,	5,	6,6,	7,	8,8,	9,	10,	11,11,	12,	13,13,	14,	15,	16,16,	17,	18,18,	19,	20,20,	21,	22,	23,23,	24,	25,25,	26,	27,	28,28,	29,
		0,	1,1,	2,	3,	4,4,	5,	6,6,	7,	8,	9,9,	10,	11,11,	12,	13,13,	14,	15,	16,16,	17,	18,18,	19,	20,	21,21,	22, 23,23,	24,	25,25,	26,	27,	28,28,	29,
		0,	1,	2,2,	3,	4,4,	5,	6,6,	7,	8,	9,9,	10,	11,11,	12,	13,	14,14,	15, 16,16,	17,	18,18,	19,	20,	21,21,	22, 23,23,	24,	25,	26,26,	27,	28,28,	29
};
*/


FingerOffset_t pucStringNoteToFingerMap[NUM_NOTES_PER_STRING] =
{
		{0, 0, 0, 0}, {1, 1, 1, 1}, {1, 1, 1, 2}, {2, 2, 2, 2}, {3, 3, 3, 3}, {3, 4, 4, 4},
		{4, 4, 4, 4}, {5, 5, 5, 5}, {6, 6, 6, 6}, {6, 6, 6, 6}, {7, 7, 7, 7}, {8, 8, 8, 8},
		{8, 8, 9, 9}, {9, 9, 9, 9}, {10, 10, 10, 10}, {11, 11, 11, 11}, {11, 11, 11, 11}, {12, 12, 12, 12},
		{13, 13, 13, 13}, {13, 13, 13, 14}, {14, 14, 14, 14}, {15, 15, 15, 15}, {15, 16, 16, 16}, {16, 16, 16, 16},
		{17, 17, 17, 17}, {18, 18, 18, 18}, {18, 18, 18, 18}, {19, 19, 19, 19}, {20, 20, 20, 20}, {20, 20, 21, 21},
		{21, 21, 21, 21}, {22, 22, 22, 22}, {23, 23, 23, 23}, {23, 23, 23, 23}, {24, 24, 24, 24}, {25, 25, 25, 25},
		{25, 25, 25, 26}, {26, 26, 26, 26}, {27, 27, 27, 27}, {27, 28, 28, 28}, {28, 28, 28, 28}, {29, 29, 29, 29}
};






void Piece_vInit(PieceHandle_t *pxPiece, FIL *pFil)
{
	uint32_t ulNumBytesRead;
	f_read(pFil, pxPiece->xPieceInformation.pusName, sizeof(pxPiece->xPieceInformation.pusName), &ulNumBytesRead);
	printf("Name: %s\r\n", pxPiece->xPieceInformation.pusName);
}


void Piece_vSetCompositionByteSize(PieceHandle_t *pxPiece, FIL *pFil)
{
	uint32_t ulNumBytesRead;
	f_read(pFil, &(pxPiece->xComposition.ulCompositionByteSize), sizeof(pxPiece->xComposition.ulCompositionByteSize), &ulNumBytesRead);
	printf("Composition size: %u\r\n", pxPiece->xComposition.ulCompositionByteSize);
}


void Piece_vSetComposition(PieceHandle_t *pxPiece, FIL *pFil)
{
	Piece_vSetCompositionByteSize(pxPiece, pFil);

	uint32_t ulNumBytesRead;
	f_read(pFil, pxPiece->xComposition.pusComposition,
			pxPiece->xComposition.ulCompositionByteSize < sizeof(pxPiece->xComposition.pusComposition) ? pxPiece->xComposition.ulCompositionByteSize : sizeof(pxPiece->xComposition.pusComposition),
			&ulNumBytesRead);


	printf("Number of bytes read: %lu\r\n", ulNumBytesRead);

	pxPiece->xPieceInstruction.ulInstructionCounter = 0;

	pxPiece->xCapture.ulTick = osKernelGetTickCount();
}


uint8_t Piece_ucParseBeatValue(PieceHandle_t *pxPiece)
{
	memcpy(&pxPiece->xPieceInstruction.usBeat, pxPiece->xComposition.pusComposition + pxPiece->xPieceInstruction.ulInstructionCounter, sizeof(pxPiece->xPieceInstruction.usBeat));
	pxPiece->xPieceInstruction.ulInstructionCounter += sizeof(pxPiece->xPieceInstruction.usBeat);

	return pxPiece->xPieceInstruction.usBeat;
}


void Piece_vParseCommand(PieceHandle_t *pxPiece)
{
	uint8_t endCommand = 0;

	while (!endCommand)
	{
		memcpy(&pxPiece->xPieceInstruction.usCommand, pxPiece->xComposition.pusComposition + pxPiece->xPieceInstruction.ulInstructionCounter, sizeof(pxPiece->xPieceInstruction.usCommand));
		pxPiece->xPieceInstruction.ulInstructionCounter += sizeof(pxPiece->xPieceInstruction.usCommand);

		printf("Command Line: %u\r\n", pxPiece->xPieceInstruction.ulInstructionCounter);
		printf("Command: %u\r\n", pxPiece->xPieceInstruction.usCommand);

		switch (pxPiece->xPieceInstruction.usCommand)
		{
		case 0b00000000:
			endCommand = 1;
			break;
		case 0b01111111:
			Piece_vConfigureAll(pxPiece);
			break;
		default:
			if (bIsPlayCommand(pxPiece->xPieceInstruction.usCommand))
			{
				uint8_t ucNumNotes = (uint8_t)((0x07) & (pxPiece->xPieceInstruction.usCommand));
				//uint8_t ucBeatValue = (uint8_t)(((0x78) & (pxPiece->xPieceInstruction.usCommand)) >> 3);
				uint8_t ucBeatValue = Piece_ucParseBeatValue(pxPiece);
				Piece_vPlayNotes(pxPiece, ucBeatValue, ucNumNotes);
			}
			else
			{
				printf("UNKNOWN COMMAND\r\n");
			}
			break;
		}
	}



	printf("END OF COMPOSITION\r\n");
	HAL_TIM_PWM_Stop_IT(&G_TIMER_HANDLE, G_TIMER_CHANNEL);
	HAL_TIM_PWM_Stop_IT(&D_TIMER_HANDLE, D_TIMER_CHANNEL);
	HAL_TIM_PWM_Stop_IT(&A_TIMER_HANDLE, A_TIMER_CHANNEL);
	HAL_TIM_PWM_Stop_IT(&E_TIMER_HANDLE, E_TIMER_CHANNEL);
}



void Piece_vSetMovement(PieceHandle_t *pxPiece, uint8_t usMovement)
{
	pxPiece->xPieceConfiguration.usMovement = usMovement;
	printf("Movement: %u\r\n", pxPiece->xPieceConfiguration.usMovement);
}

void Piece_vSetBPM(PieceHandle_t *pxPiece, uint16_t uBPM)
{
	pxPiece->xPieceConfiguration.uBPM = uBPM;
	printf("BPM: %u\r\n", pxPiece->xPieceConfiguration.uBPM);
}

void Piece_vSetDynamic(PieceHandle_t *pxPiece, uint8_t usDynamic)
{
	pxPiece->xPieceConfiguration.usDynamic = usDynamic;
	printf("Dynamic: %u\r\n", pxPiece->xPieceConfiguration.usDynamic);
}

void Piece_vConfigureAll(PieceHandle_t *pxPiece)
{
	printf("Configuring All piece...\r\n");

	uint8_t usMovement;
	memcpy(&usMovement, pxPiece->xComposition.pusComposition + pxPiece->xPieceInstruction.ulInstructionCounter, sizeof(usMovement));
	pxPiece->xPieceInstruction.ulInstructionCounter += sizeof(usMovement);

	uint16_t uBPM;
	memcpy(&uBPM, pxPiece->xComposition.pusComposition + pxPiece->xPieceInstruction.ulInstructionCounter, sizeof(uBPM));
	pxPiece->xPieceInstruction.ulInstructionCounter += sizeof(uBPM);

	uint8_t usDynamic;
	memcpy(&usDynamic, pxPiece->xComposition.pusComposition + pxPiece->xPieceInstruction.ulInstructionCounter, sizeof(usDynamic));
	pxPiece->xPieceInstruction.ulInstructionCounter += sizeof(usDynamic);


	Piece_vSetMovement(pxPiece, usMovement);
	Piece_vSetBPM(pxPiece, uBPM);
	Piece_vSetDynamic(pxPiece, usDynamic);
}






void Piece_vCaptureFragment(PieceHandle_t *pxPiece, int32_t lMSPerDemisemi)
{
	int count = 0;

	// Capture in CAPTURE_TICK_PERIOD_MS resolution
	while (lMSPerDemisemi >= CAPTURE_TICK_PERIOD_MS)
	{
		pxPiece->xCapture.ulTick += CAPTURE_TICK_PERIOD_MS;
		count++;
		lMSPerDemisemi -= CAPTURE_TICK_PERIOD_MS;
		printf("Capture Tick %d: %d\r\n", count, CAPTURE_TICK_PERIOD_MS);
		//Piece_vUpdatePerformanceStats(pxPiece);
		osDelayUntil(pxPiece->xCapture.ulTick);
	}

	// Capture the remainder under the CAPTURE_TICK_PERIOD_MS resolution
	if (lMSPerDemisemi > 0)
	{
		pxPiece->xCapture.ulTick += lMSPerDemisemi;

		count++;
		printf("Capture Tick %d: %d\r\n", count, lMSPerDemisemi);
		//Piece_vUpdatePerformanceStats(pxPiece);
		osDelayUntil(pxPiece->xCapture.ulTick);
	}

	lMSPerDemisemi = 0;
}





void Piece_vResetGoal(PieceHandle_t *pxPiece)
{
	pxPiece->xGoal.xGString.bActive = 0;
	pxPiece->xGoal.xDString.bActive = 0;
	pxPiece->xGoal.xAString.bActive = 0;
	pxPiece->xGoal.xEString.bActive = 0;
}




void Piece_vParseNoteGoal(PieceHandle_t *pxPiece)
{
	memcpy(&pxPiece->xPieceInstruction.uPlay, pxPiece->xComposition.pusComposition + pxPiece->xPieceInstruction.ulInstructionCounter, sizeof(pxPiece->xPieceInstruction.uPlay));
	pxPiece->xPieceInstruction.ulInstructionCounter += sizeof(pxPiece->xPieceInstruction.uPlay);

	/*
	uint8_t ucTechnique = (uint8_t)(((0xFF00) & (pxPiece->xPieceInstruction.uPlay)) >> 8);
	uint8_t ucNoteBase = (uint8_t)(((0x00C0) & (pxPiece->xPieceInstruction.uPlay)) >> 6); // String
	uint8_t ucNoteOffset = (uint8_t)((0x003F) & (pxPiece->xPieceInstruction.uPlay));
	*/

	uint8_t ucTechnique = (uint8_t)(((0x00FF) & (pxPiece->xPieceInstruction.uPlay)));
	uint8_t ucNoteBase = (uint8_t)(((0xC000) & (pxPiece->xPieceInstruction.uPlay)) >> (6 + 8)); // String
	uint8_t ucNoteOffset = (uint8_t)(((0x3F00) & (pxPiece->xPieceInstruction.uPlay)) >> 8);


	switch (ucNoteBase)
	{
	case G_STRING:
		pxPiece->xGoal.xGString.bActive = 1;
		pxPiece->xGoal.xGString.ucTechnique = ucTechnique;
		pxPiece->xGoal.xGString.ucFingerOffset = ucNoteOffset;
		break;
	case D_STRING:
		pxPiece->xGoal.xDString.bActive = 1;
		pxPiece->xGoal.xDString.ucTechnique = ucTechnique;
		pxPiece->xGoal.xDString.ucFingerOffset = ucNoteOffset;
		break;
	case A_STRING:
		pxPiece->xGoal.xAString.bActive = 1;
		pxPiece->xGoal.xAString.ucTechnique = ucTechnique;
		pxPiece->xGoal.xAString.ucFingerOffset = ucNoteOffset;
		break;
	case E_STRING:
		pxPiece->xGoal.xEString.bActive = 1;
		pxPiece->xGoal.xEString.ucTechnique = ucTechnique;
		pxPiece->xGoal.xEString.ucFingerOffset = ucNoteOffset;
		break;
	default:
		break;
	}
}


void Piece_vParseGoal(PieceHandle_t *pxPiece, uint8_t ucNumNotes)
{
	if (ucNumNotes > 4) ucNumNotes = 4;
	// [!] Should throw error and abort if ucNumNotes > 4

	for (int16_t i = 0; i < ucNumNotes; i++)
	{
		Piece_vParseNoteGoal(pxPiece);
	}
}




void Piece_vPlayNotes(PieceHandle_t *pxPiece, uint8_t ucBeatValue, uint8_t ucNumNotes)
{
	printf("Play Notes: %u\r\n", ucNumNotes);
	printf("Beat Value: %u\r\n", ucBeatValue);

	Piece_vResetGoal(pxPiece);
	Piece_vParseGoal(pxPiece, ucNumNotes);
	Piece_Debug_vPrintGoal(pxPiece);

	float fTupletScale;
	switch (ucBeatValue)
	{
	case NOPELET:
		fTupletScale = NOPELET_SCALE;
		break;
	case TRIPLET:
		fTupletScale = TRIPLET_SCALE;
		break;
	case QUINTUPLET:
		fTupletScale = QUINTUPLET_SCALE;
		break;
	case SEXTUPLET:
		fTupletScale = SEXTUPLET_SCALE;
		break;
	case SEPTUPLET:
		fTupletScale = SEPTUPLET_SCALE;
		break;
	default:
		fTupletScale = NOPELET_SCALE;
		break;
	}

	uint32_t ulMSPerBeatValue;
	float fMSPerChrochet = (float)((60.0/(float)pxPiece->xPieceConfiguration.uBPM)) * 1000.0f; // Divide by 8 because 32nd beat resolution is 1/2^3 of quarter note BPM reference, for B is a quarter note
	switch (ucBeatValue)
	{
	case LARGE:
		// [!] Subtle missalignment (+/- 1ms) based on float to integer conversion. Keep track in the future
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*LARGE_SCALE*fTupletScale);
		break;
	case LONG:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*LONG_SCALE*fTupletScale);
		break;
	case BREVE:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*BREVE_SCALE*fTupletScale);
		break;
	case SEMIBREVE:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*SEMIBREVE_SCALE*fTupletScale);
		break;
	case MINIM:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*MINIM_SCALE*fTupletScale);
		break;
	case CROTCHET:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*CROTCHET_SCALE*fTupletScale);
		break;
	case QUAVER:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*QUAVER_SCALE*fTupletScale);
		break;
	case SEMIQUAVER:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*SEMIQUAVER_SCALE*fTupletScale);
		break;
	case DEMISEMIQUAVER:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*DEMISEMIQUAVER_SCALE*fTupletScale);
		break;
	case HEMIDEMISEMIQUAVER:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*HEMIDEMISEMIQUAVER_SCALE*fTupletScale);
		break;
	case SEMIHEMIDEMISEMIQUAVER:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*SEMIHEMIDEMISEMIQUAVER_SCALE*fTupletScale);
		break;
	case DEMISEMIHEMIDEMISEMIQUAVER:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*DEMISEMIHEMIDEMISEMIQUAVER_SCALE*fTupletScale);
		break;
	default:
		ulMSPerBeatValue = (int32_t)(fMSPerChrochet*CROTCHET_SCALE*fTupletScale);
		break;
	}


	if (ucNumNotes == 0)
	{
		printf("REST\r\n");
	}

	Piece_vCaptureFragment(pxPiece, ulMSPerBeatValue);
}


uint8_t bIsPlayCommand(uint8_t usCommand)
{
	return usCommand >= 0b10000000;
}



uint16_t Piece_usGetPitchTick(uint8_t ucString, uint8_t ucOffset)
{
	uint8_t ucPitchTickIndex;

	switch (ucString)
	{
	case G_STRING:
		ucPitchTickIndex = G_STRING_PITCH_TICK_OFFSET;
		break;
	case D_STRING:
		ucPitchTickIndex = D_STRING_PITCH_TICK_OFFSET;
		break;
	case A_STRING:
		ucPitchTickIndex = A_STRING_PITCH_TICK_OFFSET;
		break;
	case E_STRING:
		ucPitchTickIndex = E_STRING_PITCH_TICK_OFFSET;
		break;
	default:
		ucPitchTickIndex = G_STRING_PITCH_TICK_OFFSET;
		break;
	}

	ucPitchTickIndex += ucOffset;
	ucPitchTickIndex = (ucPitchTickIndex < NUM_PITCH_TICKS) ? ucPitchTickIndex : NUM_PITCH_TICKS - 1;

	return pusNoteToPitchMap[ucPitchTickIndex];
}



uint8_t Piece_ucGetFingeringIndex(uint8_t ucString, uint8_t ucOffset)
{
	uint8_t ucFingeringIndex;

	// [!] assert ucOffset [0, 29]

	switch (ucString)
	{
	case G_STRING:
		ucFingeringIndex = G_STRING_FINGER_OFFSET - pucStringNoteToFingerMap[ucOffset].ucG;
		break;
	case D_STRING:
		ucFingeringIndex = D_STRING_FINGER_OFFSET + pucStringNoteToFingerMap[ucOffset].ucD;
		break;
	case A_STRING:
		ucFingeringIndex = A_STRING_FINGER_OFFSET - pucStringNoteToFingerMap[ucOffset].ucA;
		break;
	case E_STRING:
		ucFingeringIndex = E_STRING_FINGER_OFFSET + pucStringNoteToFingerMap[ucOffset].ucE;
		break;
	default:
		// [!] error light
		ucFingeringIndex = G_STRING_FINGER_OFFSET;
		break;
	}

	return ucFingeringIndex;
}



void Piece_vSetFingerboardLight(PieceHandle_t *pxPiece)
{
	if (pxPiece->xGoal.xGString.bActive)
	{
		uint8_t ucGFingeringOffset = Piece_ucGetFingeringIndex(G_STRING, pxPiece->xGoal.xGString.ucFingerOffset);
	}

	if (pxPiece->xGoal.xDString.bActive)
	{
		uint8_t ucDFingeringOffset = Piece_ucGetFingeringIndex(D_STRING, pxPiece->xGoal.xDString.ucFingerOffset);
	}

	if (pxPiece->xGoal.xAString.bActive)
	{
		uint8_t ucAFingeringOffset = Piece_ucGetFingeringIndex(A_STRING, pxPiece->xGoal.xAString.ucFingerOffset);
	}

	if (pxPiece->xGoal.xEString.bActive)
	{
		uint8_t ucEFingeringOffset = Piece_ucGetFingeringIndex(E_STRING, pxPiece->xGoal.xEString.ucFingerOffset);
	}
}



void Piece_Debug_vPrintPointer(PieceHandle_t *pxPiece, FIL *pFil)
{
	printf("Pointer: %u\r\n", f_tell(pFil));
}



extern WS2812BHandle_t xWS2812B;


void Piece_Debug_vPrintGoal(PieceHandle_t *pxPiece)
{
	printf("GOAL:\r\n");

	if (pxPiece->xGoal.xGString.bActive)
	{
		printf("	G: %u, %u\r\n", pxPiece->xGoal.xGString.ucFingerOffset, Piece_usGetPitchTick(G_STRING, pxPiece->xGoal.xGString.ucFingerOffset));

		G_TIMER_HANDLE.Instance->ARR = Piece_usGetPitchTick(G_STRING, pxPiece->xGoal.xGString.ucFingerOffset);
		G_TIMER_HANDLE.Instance->CCR1 = G_TIMER_HANDLE.Instance->ARR/2;
		HAL_TIM_PWM_Start_IT(&G_TIMER_HANDLE, G_TIMER_CHANNEL);


		uint8_t ucGFingeringOffset = Piece_ucGetFingeringIndex(G_STRING, pxPiece->xGoal.xGString.ucFingerOffset);
		WS2812B_vSetLED(&xWS2812B, ucGFingeringOffset, 255, 0, 0);
    WS2812B_vSetBrightness(&xWS2812B, 1);
    WS2812B_vSend(&xWS2812B);
    WS2812B_vResetLEDs(&xWS2812B);

	}
	else
	{
		HAL_TIM_PWM_Stop_IT(&G_TIMER_HANDLE, G_TIMER_CHANNEL);
	}

	if (pxPiece->xGoal.xDString.bActive)
	{
		printf("	D: %u, %u\r\n", pxPiece->xGoal.xDString.ucFingerOffset, Piece_usGetPitchTick(D_STRING, pxPiece->xGoal.xDString.ucFingerOffset));

		D_TIMER_HANDLE.Instance->ARR = Piece_usGetPitchTick(D_STRING, pxPiece->xGoal.xDString.ucFingerOffset);
		D_TIMER_HANDLE.Instance->CCR1 = D_TIMER_HANDLE.Instance->ARR/2;
		HAL_TIM_PWM_Start_IT(&D_TIMER_HANDLE, D_TIMER_CHANNEL);
	}
	else
	{
		HAL_TIM_PWM_Stop_IT(&D_TIMER_HANDLE, D_TIMER_CHANNEL);
	}

	if (pxPiece->xGoal.xAString.bActive)
	{
		printf("	A: %u, %u\r\n", pxPiece->xGoal.xAString.ucFingerOffset, Piece_usGetPitchTick(A_STRING, pxPiece->xGoal.xAString.ucFingerOffset));

		A_TIMER_HANDLE.Instance->ARR = Piece_usGetPitchTick(A_STRING, pxPiece->xGoal.xAString.ucFingerOffset);
		A_TIMER_HANDLE.Instance->CCR1 = A_TIMER_HANDLE.Instance->ARR/2;
		HAL_TIM_PWM_Start_IT(&A_TIMER_HANDLE, A_TIMER_CHANNEL);
	}
	else
	{
		HAL_TIM_PWM_Stop_IT(&A_TIMER_HANDLE, A_TIMER_CHANNEL);
	}

	if (pxPiece->xGoal.xEString.bActive)
	{
		printf("	E: %u, %u\r\n", pxPiece->xGoal.xEString.ucFingerOffset, Piece_usGetPitchTick(E_STRING, pxPiece->xGoal.xEString.ucFingerOffset));

		E_TIMER_HANDLE.Instance->ARR = Piece_usGetPitchTick(E_STRING, pxPiece->xGoal.xEString.ucFingerOffset);
		E_TIMER_HANDLE.Instance->CCR1 = E_TIMER_HANDLE.Instance->ARR/2;
		HAL_TIM_PWM_Start_IT(&E_TIMER_HANDLE, E_TIMER_CHANNEL);
	}
	else
	{
		HAL_TIM_PWM_Stop_IT(&E_TIMER_HANDLE, E_TIMER_CHANNEL);
	}
}

