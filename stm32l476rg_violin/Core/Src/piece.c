/*
 * piece.c
 *
 *  Created on: Jun 8, 2021
 *      Author: victor
 */

#include "piece.h"

/*
uint16_t pusFrequencyMap[4][42] = {
		{	196,		208,		208,		220,		233,		233,		247,		262,		277,		277,
			294,		311,		311,		330,		350,		370,		370,		392,		415,		415,
			440,		466,		466,		494,		523,		554,		554,		587,		622,		622,
			659,		698,		740,		740,		784,		831,		831,		880,		932,		932,
			988,		1047},
		{ 294,		311,		311,		330,		350,		370,		370,		392,		415,		415,
			440,		466,		466,		494,		523,		554,		554,		587,		622,		622,
			659,		698,		740,		740,		784,		831,		831,		880,		932,		932,
			988,		1047,		1109,		1109,		1175,		1245,		1245,		1319,		1397,		1480,
			1480,		1568
		},
		{	440,		466,		466,		494,		523,		554,		554,		587,		622,		622,
			659,		698,		740,		740,		784,		831,		831,		880,		932,		932,
			988,		1047,		1109,		1109,		1175,		1245,		1245,		1319,		1397,		1480,
			1480,		1568,		1661,		1661,		1760,		1865,		1865,		1976,		2093,		2217,
			2217,		2349
		},
		{},
};
*/



uint16_t pusPitchTickMap[4][42] = {
		{	GET_PITCH_CHZ_TICK(G3_CHZ), 	GET_PITCH_CHZ_TICK(Gs3_CHZ),		GET_PITCH_CHZ_TICK(Ab3_CHZ),		GET_PITCH_CHZ_TICK(A3_CHZ),		GET_PITCH_CHZ_TICK(As3_CHZ),
			GET_PITCH_CHZ_TICK(Bb3_CHZ),		GET_PITCH_CHZ_TICK(B3_CHZ),		GET_PITCH_CHZ_TICK(C4_CHZ),		GET_PITCH_CHZ_TICK(Cs4_CHZ),		GET_PITCH_CHZ_TICK(Db4_CHZ),
			GET_PITCH_CHZ_TICK(D4_CHZ),		GET_PITCH_CHZ_TICK(Ds4_CHZ),		GET_PITCH_CHZ_TICK(Eb4_CHZ),		GET_PITCH_CHZ_TICK(E4_CHZ),		GET_PITCH_CHZ_TICK(F4_CHZ),
			GET_PITCH_CHZ_TICK(Fs4_CHZ),		GET_PITCH_CHZ_TICK(Gb4_CHZ),		GET_PITCH_CHZ_TICK(G4_CHZ),		GET_PITCH_CHZ_TICK(Gs4_CHZ),		GET_PITCH_CHZ_TICK(Ab4_CHZ),
			GET_PITCH_CHZ_TICK(A4_CHZ),		GET_PITCH_CHZ_TICK(As4_CHZ),		GET_PITCH_CHZ_TICK(Bb4_CHZ),		GET_PITCH_CHZ_TICK(B4_CHZ),		GET_PITCH_CHZ_TICK(C5_CHZ),
			GET_PITCH_CHZ_TICK(Cs5_CHZ),		GET_PITCH_CHZ_TICK(Db5_CHZ),		GET_PITCH_CHZ_TICK(D5_CHZ),		GET_PITCH_CHZ_TICK(Ds5_CHZ),		GET_PITCH_CHZ_TICK(Eb5_CHZ),
			GET_PITCH_CHZ_TICK(E5_CHZ),		GET_PITCH_CHZ_TICK(F5_CHZ),		GET_PITCH_CHZ_TICK(Fs5_CHZ),		GET_PITCH_CHZ_TICK(Gb5_CHZ),		GET_PITCH_CHZ_TICK(G5_CHZ),
			GET_PITCH_CHZ_TICK(Gs5_CHZ),		GET_PITCH_CHZ_TICK(Ab5_CHZ),		GET_PITCH_CHZ_TICK(A5_CHZ),		GET_PITCH_CHZ_TICK(As5_CHZ),		GET_PITCH_CHZ_TICK(Bb5_CHZ),
			GET_PITCH_CHZ_TICK(B5_CHZ),		GET_PITCH_CHZ_TICK(C6_CHZ)
		},
		{
			GET_PITCH_CHZ_TICK(D4_CHZ),		GET_PITCH_CHZ_TICK(Ds4_CHZ),		GET_PITCH_CHZ_TICK(Eb4_CHZ),		GET_PITCH_CHZ_TICK(E4_CHZ),		GET_PITCH_CHZ_TICK(F4_CHZ),
			GET_PITCH_CHZ_TICK(Fs4_CHZ),		GET_PITCH_CHZ_TICK(Gb4_CHZ),		GET_PITCH_CHZ_TICK(G4_CHZ),		GET_PITCH_CHZ_TICK(Gs4_CHZ),		GET_PITCH_CHZ_TICK(Ab4_CHZ),
			GET_PITCH_CHZ_TICK(A4_CHZ),		GET_PITCH_CHZ_TICK(As4_CHZ),		GET_PITCH_CHZ_TICK(Bb4_CHZ),		GET_PITCH_CHZ_TICK(B4_CHZ),		GET_PITCH_CHZ_TICK(C5_CHZ),
			GET_PITCH_CHZ_TICK(Cs5_CHZ),		GET_PITCH_CHZ_TICK(Db5_CHZ),		GET_PITCH_CHZ_TICK(D5_CHZ),		GET_PITCH_CHZ_TICK(Ds5_CHZ),		GET_PITCH_CHZ_TICK(Eb5_CHZ),
			GET_PITCH_CHZ_TICK(E5_CHZ),		GET_PITCH_CHZ_TICK(F5_CHZ),		GET_PITCH_CHZ_TICK(Fs5_CHZ),		GET_PITCH_CHZ_TICK(Gb5_CHZ),		GET_PITCH_CHZ_TICK(G5_CHZ),
			GET_PITCH_CHZ_TICK(Gs5_CHZ),		GET_PITCH_CHZ_TICK(Ab5_CHZ),		GET_PITCH_CHZ_TICK(A5_CHZ),		GET_PITCH_CHZ_TICK(As5_CHZ),		GET_PITCH_CHZ_TICK(Bb5_CHZ),
			GET_PITCH_CHZ_TICK(B5_CHZ),		GET_PITCH_CHZ_TICK(C6_CHZ),		GET_PITCH_CHZ_TICK(Cs6_CHZ),		GET_PITCH_CHZ_TICK(Db6_CHZ),		GET_PITCH_CHZ_TICK(D6_CHZ),
			GET_PITCH_CHZ_TICK(Ds6_CHZ),		GET_PITCH_CHZ_TICK(Eb6_CHZ),		GET_PITCH_CHZ_TICK(E6_CHZ),		GET_PITCH_CHZ_TICK(F6_CHZ),		GET_PITCH_CHZ_TICK(Fs6_CHZ),
			GET_PITCH_CHZ_TICK(Gb6_CHZ),		GET_PITCH_CHZ_TICK(G6_CHZ)
		},
		{
			GET_PITCH_CHZ_TICK(A4_CHZ),		GET_PITCH_CHZ_TICK(As4_CHZ),		GET_PITCH_CHZ_TICK(Bb4_CHZ),		GET_PITCH_CHZ_TICK(B4_CHZ),		GET_PITCH_CHZ_TICK(C5_CHZ),
			GET_PITCH_CHZ_TICK(Cs5_CHZ),		GET_PITCH_CHZ_TICK(Db5_CHZ),		GET_PITCH_CHZ_TICK(D5_CHZ),		GET_PITCH_CHZ_TICK(Ds5_CHZ),		GET_PITCH_CHZ_TICK(Eb5_CHZ),
			GET_PITCH_CHZ_TICK(E5_CHZ),		GET_PITCH_CHZ_TICK(F5_CHZ),		GET_PITCH_CHZ_TICK(Fs5_CHZ),		GET_PITCH_CHZ_TICK(Gb5_CHZ),		GET_PITCH_CHZ_TICK(G5_CHZ),
			GET_PITCH_CHZ_TICK(Gs5_CHZ),		GET_PITCH_CHZ_TICK(Ab5_CHZ),		GET_PITCH_CHZ_TICK(A5_CHZ),		GET_PITCH_CHZ_TICK(As5_CHZ),		GET_PITCH_CHZ_TICK(Bb5_CHZ),
			GET_PITCH_CHZ_TICK(B5_CHZ),		GET_PITCH_CHZ_TICK(C6_CHZ),		GET_PITCH_CHZ_TICK(Cs6_CHZ),		GET_PITCH_CHZ_TICK(Db6_CHZ),		GET_PITCH_CHZ_TICK(D6_CHZ),
			GET_PITCH_CHZ_TICK(Ds6_CHZ),		GET_PITCH_CHZ_TICK(Eb6_CHZ),		GET_PITCH_CHZ_TICK(E6_CHZ),		GET_PITCH_CHZ_TICK(F6_CHZ),		GET_PITCH_CHZ_TICK(Fs6_CHZ),
			GET_PITCH_CHZ_TICK(Gb6_CHZ),		GET_PITCH_CHZ_TICK(G6_CHZ),		GET_PITCH_CHZ_TICK(Gs6_CHZ),		GET_PITCH_CHZ_TICK(Ab6_CHZ),		GET_PITCH_CHZ_TICK(A6_CHZ),
			GET_PITCH_CHZ_TICK(As6_CHZ),		GET_PITCH_CHZ_TICK(Bb6_CHZ),		GET_PITCH_CHZ_TICK(B6_CHZ),		GET_PITCH_CHZ_TICK(C7_CHZ),		GET_PITCH_CHZ_TICK(Cs7_CHZ),
			GET_PITCH_CHZ_TICK(Db7_CHZ),		GET_PITCH_CHZ_TICK(D7_CHZ)
		},
		{
			GET_PITCH_CHZ_TICK(E5_CHZ),		GET_PITCH_CHZ_TICK(F5_CHZ),		GET_PITCH_CHZ_TICK(Fs5_CHZ),		GET_PITCH_CHZ_TICK(Gb5_CHZ),		GET_PITCH_CHZ_TICK(G5_CHZ),
			GET_PITCH_CHZ_TICK(Gs5_CHZ),		GET_PITCH_CHZ_TICK(Ab5_CHZ),		GET_PITCH_CHZ_TICK(A5_CHZ),		GET_PITCH_CHZ_TICK(As5_CHZ),		GET_PITCH_CHZ_TICK(Bb5_CHZ),
			GET_PITCH_CHZ_TICK(B5_CHZ),		GET_PITCH_CHZ_TICK(C6_CHZ),		GET_PITCH_CHZ_TICK(Cs6_CHZ),		GET_PITCH_CHZ_TICK(Db6_CHZ),		GET_PITCH_CHZ_TICK(D6_CHZ),
			GET_PITCH_CHZ_TICK(Ds6_CHZ),		GET_PITCH_CHZ_TICK(Eb6_CHZ),		GET_PITCH_CHZ_TICK(E6_CHZ),		GET_PITCH_CHZ_TICK(F6_CHZ),		GET_PITCH_CHZ_TICK(Fs6_CHZ),
			GET_PITCH_CHZ_TICK(Gb6_CHZ),		GET_PITCH_CHZ_TICK(G6_CHZ),		GET_PITCH_CHZ_TICK(Gs6_CHZ),		GET_PITCH_CHZ_TICK(Ab6_CHZ),		GET_PITCH_CHZ_TICK(A6_CHZ),
			GET_PITCH_CHZ_TICK(As6_CHZ),		GET_PITCH_CHZ_TICK(Bb6_CHZ),		GET_PITCH_CHZ_TICK(B6_CHZ),		GET_PITCH_CHZ_TICK(C7_CHZ),		GET_PITCH_CHZ_TICK(Cs7_CHZ),
			GET_PITCH_CHZ_TICK(Db7_CHZ),		GET_PITCH_CHZ_TICK(D7_CHZ), GET_PITCH_CHZ_TICK(Ds7_CHZ),		GET_PITCH_CHZ_TICK(Eb7_CHZ),		GET_PITCH_CHZ_TICK(E7_CHZ),
			GET_PITCH_CHZ_TICK(F7_CHZ),		GET_PITCH_CHZ_TICK(Fs7_CHZ),		GET_PITCH_CHZ_TICK(Gb7_CHZ),		GET_PITCH_CHZ_TICK(G7_CHZ),		GET_PITCH_CHZ_TICK(Gs7_CHZ),
			GET_PITCH_CHZ_TICK(Ab7_CHZ),		GET_PITCH_CHZ_TICK(A7_CHZ)
		}
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

	pxPiece->xPieceInstruction.ulInstructionCounter = 0;

	pxPiece->xCapture.ulTick = osKernelGetTickCount();
}


void Piece_vParseCommand(PieceHandle_t *pxPiece)
{
	memcpy(&pxPiece->xPieceInstruction.usCommand, pxPiece->xComposition.pusComposition + pxPiece->xPieceInstruction.ulInstructionCounter, sizeof(pxPiece->xPieceInstruction.usCommand));
	pxPiece->xPieceInstruction.ulInstructionCounter += 1;

	printf("Command: %u\r\n", pxPiece->xPieceInstruction.usCommand);

	switch (pxPiece->xPieceInstruction.usCommand)
	{
	case 0b00000000:
		printf("END OF COMPOSITION\r\n");
		return;
	case 0b01111111:
		Piece_vConfigureAll(pxPiece);
		break;
	default:
		if (bIsPlayCommand(pxPiece->xPieceInstruction.usCommand))
		{
			uint8_t ucNumNotes = (uint8_t)((0x07) & (pxPiece->xPieceInstruction.usCommand));
			uint8_t ucBeatValue = (uint8_t)(((0x78) & (pxPiece->xPieceInstruction.usCommand)) >> 3);
			Piece_vPlayNotes(pxPiece, ucBeatValue, ucNumNotes);
		}
		else
		{
			printf("UNKNOWN COMMAND\r\n");
		}
		break;
	}

	Piece_vParseCommand(pxPiece);
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






void Piece_vCaptureNotes(PieceHandle_t *pxPiece, int32_t lMSPerDemisemi)
{
	int count = 0;

	while (lMSPerDemisemi >= CAPTURE_TICK_PERIOD_MS)
	{
		pxPiece->xCapture.ulTick += CAPTURE_TICK_PERIOD_MS;

		count++;
		lMSPerDemisemi -= CAPTURE_TICK_PERIOD_MS;
		printf("Capture Tick %d: %d\r\n", count, CAPTURE_TICK_PERIOD_MS);
		osDelayUntil(pxPiece->xCapture.ulTick);
	}

	// Capture the remainder under the 50ms resolution
	if (lMSPerDemisemi > 0)
	{
		pxPiece->xCapture.ulTick += lMSPerDemisemi;

		count++;
		printf("Capture Tick %d: %d\r\n", count, lMSPerDemisemi);
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




void Piece_vSetNoteGoal(PieceHandle_t *pxPiece)
{
	memcpy(&pxPiece->xPieceInstruction.uPlay, pxPiece->xComposition.pusComposition + pxPiece->xPieceInstruction.ulInstructionCounter, sizeof(pxPiece->xPieceInstruction.uPlay));
	pxPiece->xPieceInstruction.ulInstructionCounter += sizeof(pxPiece->xPieceInstruction.uPlay);

	uint8_t ucTechnique = (uint8_t)(((0xFF00) & (pxPiece->xPieceInstruction.uPlay)) >> 8);
	uint8_t ucNoteBase = (uint8_t)(((0x00C0) & (pxPiece->xPieceInstruction.uPlay)) >> 6); // String
	uint8_t ucNoteOffset = (uint8_t)((0x003F) & (pxPiece->xPieceInstruction.uPlay));


	/*
	printf("Play note:\r\n");
	printf("	Technique: %u\r\n", ucTechnique);
	printf("	Note Base: %u\r\n", ucNoteBase);
	printf("	Note Offset: %u\r\n", ucNoteOffset);
	*/

	switch (ucNoteBase)
	{
	case 0:
		pxPiece->xGoal.xGString.bActive = 1;
		pxPiece->xGoal.xGString.ucTechnique = ucTechnique;
		pxPiece->xGoal.xGString.ucFingerOffset = ucNoteOffset;
		break;
	case 1:
		pxPiece->xGoal.xDString.bActive = 1;
		pxPiece->xGoal.xDString.ucTechnique = ucTechnique;
		pxPiece->xGoal.xDString.ucFingerOffset = ucNoteOffset;
		break;
	case 2:
		pxPiece->xGoal.xAString.bActive = 1;
		pxPiece->xGoal.xAString.ucTechnique = ucTechnique;
		pxPiece->xGoal.xAString.ucFingerOffset = ucNoteOffset;
		break;
	case 3:
		pxPiece->xGoal.xEString.bActive = 1;
		pxPiece->xGoal.xEString.ucTechnique = ucTechnique;
		pxPiece->xGoal.xEString.ucFingerOffset = ucNoteOffset;
		break;
	default:
		break;
	}
}


void Piece_vSetGoal(PieceHandle_t *pxPiece, uint8_t ucNumNotes)
{
	for (int16_t i = 0; i < ucNumNotes; i++)
	{
		Piece_vSetNoteGoal(pxPiece);
	}
}




void Piece_vPlayNotes(PieceHandle_t *pxPiece, uint8_t ucBeatValue, uint8_t ucNumNotes)
{
	if (ucNumNotes > 4) ucNumNotes = 4;
	printf("Play Notes: %u\r\n", ucNumNotes);
	printf("Beat Value: %u\r\n", ucBeatValue);

	Piece_vResetGoal(pxPiece);
	Piece_vSetGoal(pxPiece, ucNumNotes);
	Piece_Debug_vPrintGoal(pxPiece);


	// Wait until
	float fMSPerDemisemi = (float)((60.0/(float)pxPiece->xPieceConfiguration.uBPM)/8.0f) * 1000.0f; // Divide by 8 because 32nd beat resolution is 1/2^3 of quarter note BPM reference, for B is a quarter note
	switch (ucBeatValue)
	{
	case 0x00:
		// [!] Subtle missalignment (+/- 1ms) based on float to integer conversion. Keep track in the future
		Piece_vCaptureNotes(pxPiece, (int32_t)(fMSPerDemisemi*32.0f));
		break;
	case 0x01:
		Piece_vCaptureNotes(pxPiece, (int32_t)(fMSPerDemisemi*16.0f));
		break;
	case 0x02:
		Piece_vCaptureNotes(pxPiece, (int32_t)(fMSPerDemisemi*8.0f));
		break;
	case 0x03:
		Piece_vCaptureNotes(pxPiece, (int32_t)(fMSPerDemisemi*4.0f));
		break;
	case 0x04:
		Piece_vCaptureNotes(pxPiece, (int32_t)(fMSPerDemisemi*2.0f));
		break;
	case 0x05:
		Piece_vCaptureNotes(pxPiece, (int32_t)(fMSPerDemisemi));
		break;
	default:
		break;
	}

	// osDelay
}




uint8_t bIsPlayCommand(uint8_t usCommand)
{
	return usCommand >= 0b10000000;
}



void Piece_Debug_vPrintPointer(PieceHandle_t *pxPiece, FIL *pFil)
{
	printf("Pointer: %u\r\n", f_tell(pFil));
}



void Piece_Debug_vPrintGoal(PieceHandle_t *pxPiece)
{
	printf("GOAL:\r\n");

	if (pxPiece->xGoal.xGString.bActive)
	{
		printf("	G: %u\r\n", pusPitchTickMap[0][pxPiece->xGoal.xGString.ucFingerOffset]);
	}

	if (pxPiece->xGoal.xDString.bActive)
	{
		printf("	D: %u\r\n", pusPitchTickMap[1][pxPiece->xGoal.xDString.ucFingerOffset]);
	}

	if (pxPiece->xGoal.xAString.bActive)
	{
		printf("	A: %u\r\n", pusPitchTickMap[2][pxPiece->xGoal.xAString.ucFingerOffset]);
	}

	if (pxPiece->xGoal.xEString.bActive)
	{
		printf("	E: %u\r\n", pusPitchTickMap[3][pxPiece->xGoal.xEString.ucFingerOffset]);
	}
}

