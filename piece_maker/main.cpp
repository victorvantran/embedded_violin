#include <iostream>
#include <stdio.h>
#include <string.h>

#include <fstream>

#define COMPOSITION_SIZE			(uint32_t)566 //(uint32_t)2882400018


enum Note
{
	G3 = 0,
	Gs3,
	Ab3,
	A3,
	As3,
	Bb3,
	B3,
	C4,
	Cs4,
	Db4,
	D4,
	Ds4,
	Eb4,
	E4,
	F4,
	Fs4,
	Gb4,
	G4,
	Gs4,
	Ab4,
	A4,
	As4,
	Bb4,
	B4,
	C5,
	Cs5,
	Db5,
	D5,
	Ds5,
	Eb5,
	E5,
	F5,
	Fs5,
	Gb5,
	G5,
	Gs5,
	Ab5,
	A5,
	As5,
	Bb5,
	B5,
	C6,
	Cs6,
	Db6,
	D6,
	Ds6,
	Eb6,
	E6,
	F6,
	Fs6,
	Gb6,
	G6,
	Gs6,
	Ab6,
	A6,
	As6,
	Bb6,
	B6,
	C7,
	Cs7,
	Db7,
	D7,
	Ds7,
	Eb7,
	E7,
	F7,
	Fs7,
	Gb7,
	G7,
	Gs7,
	Ab7,
	A7
};



#define G (uint8_t)0
#define D (uint8_t)1
#define A (uint8_t)2
#define E (uint8_t)3



#define G_BASE (uint8_t)G3
#define D_BASE (uint8_t)D4
#define A_BASE (uint8_t)A4
#define E_BASE (uint8_t)E5





#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 



#define BYTE2_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define BYTE2_TO_BINARY(byte)  \
	( byte & 0x8000 ? '1' : '0' ), \
	( byte & 0x4000 ? '1' : '0' ), \
	( byte & 0x2000 ? '1' : '0' ), \
	( byte & 0x1000 ? '1' : '0' ), \
	( byte & 0x0800 ? '1' : '0' ), \
	( byte & 0x0400 ? '1' : '0' ), \
	( byte & 0x0200 ? '1' : '0' ), \
	( byte & 0x0100 ? '1' : '0' ), \
	( byte & 0x0080 ? '1' : '0' ), \
	( byte & 0x0040 ? '1' : '0' ), \
	( byte & 0x0020 ? '1' : '0' ), \
	( byte & 0x0010 ? '1' : '0' ), \
	( byte & 0x0008 ? '1' : '0' ), \
	( byte & 0x0004 ? '1' : '0' ), \
	( byte & 0x0002 ? '1' : '0' ), \
	( byte & 0x0001 ? '1' : '0' )




#define COMMAND_CONFIGURE_BIT	0
#define COMMAND_PLAY_BIT		1


#define HEADER_SIZE_BYTE 128
#define MAX_FRAGMENTS 4


#define PIANISSISSIMO	(uint8_t)0
#define PIANISSIMO		(uint8_t)1
#define PIANO			(uint8_t)2
#define MEZZO_PIANO		(uint8_t)3
#define MEZZO_FORTE		(uint8_t)4
#define FORTE			(uint8_t)5
#define FORTISSIMO		(uint8_t)6
#define FIRTISSISSIMO	(uint8_t)7




#define LARGE						(uint8_t)0
#define LONG						(uint8_t)1
#define BREVE						(uint8_t)2
#define SEMIBREVE					(uint8_t)3
#define MINIM						(uint8_t)4
#define CROTCHET					(uint8_t)5
#define QUAVER						(uint8_t)6
#define SEMIQUAVER					(uint8_t)7
#define DEMISEMIQUAVER				(uint8_t)8
#define HEMIDEMISEMIQUAVER			(uint8_t)9
#define SEMIHEMIDEMISEMIQUAVER		(uint8_t)10
#define DEMISEMIHEMIDEMISEMIQUAVER	(uint8_t)11


#define NOPELET			(uint8_t)0
#define TRIPLET			(uint8_t)1
#define QUINTUPLET		(uint8_t)2
#define SEXTUPLET		(uint8_t)3
#define SEPTUPLET		(uint8_t)4

// Check this to signify another 16 bit command for n-plet
#define CUSTOMPLET		(uint8_t)0x0F





uint8_t bigEndianify( uint8_t data )
{
	return data;
}


uint16_t bigEndianify( uint16_t data )
{
	return ( uint16_t )( ( ( uint16_t )( ( 0x00FF ) & data ) << 8 ) | ( ( uint16_t )( ( 0xFF00 ) & data ) >> 8 ) );
}



uint32_t bigEndianify( uint32_t data )
{
	return ( uint32_t )( ( ( uint32_t )( ( 0x000000FF ) & data ) << 24 ) | ( ( uint32_t )( ( 0x0000FF00 ) & data ) << 8 ) | ( ( uint32_t )( ( 0x00FF0000 ) & data ) >> 8 ) | ( ( uint32_t )( ( 0xFF000000 ) & data ) >> 24 ) );
}





struct NoteFragment
{
	NoteFragment( uint8_t ucBase, uint8_t ucNote, uint8_t ucTechnique) : ucBase(ucBase), ucTechnique(ucTechnique)
	{
		/*[!] Get offset from note with error check to see if offset not possible*/
		// ucOffset;

		if ( ucBase == G )
		{
			this->ucOffset = ucNote - G_BASE;
		}
		else if ( ucBase == D )
		{
			this->ucOffset = ucNote - D_BASE;
		}
		else if ( ucBase == A )
		{
			this->ucOffset = ucNote - A_BASE;
		}
		else if ( ucBase == E )
		{
			this->ucOffset = ucNote - E_BASE;
		}
		else
		{
			std::cout << "ERROR: ucBase not G, D, A, or E" << std::endl;
		}

		if ( ucOffset > 41 )
		{
			std::cout << "ERROR: ucOffset > 41" << std::endl;
		}
	}
	~NoteFragment() {}
	bool bActive;
	uint8_t ucBase;
	uint8_t ucOffset;
	uint8_t ucTechnique;
};


struct Fragment
{
private:
	uint8_t ucBeatValue;
	uint8_t ucNoteFragmentIndex = 0;
	NoteFragment noteFragments[MAX_FRAGMENTS];
public:
	Fragment() : noteFragments{ {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }
	{

	}

	~Fragment()
	{

	}


	uint8_t getBeatValue()
	{
		return this->ucBeatValue;
	}


	uint8_t getNoteFragmentIndex()
	{
		return this->ucNoteFragmentIndex;
	}


	NoteFragment* getNoteFragments()
	{
		return this->noteFragments;
	}


	void reset()
	{
		std::cout << "Reset" << std::endl;

		this->ucNoteFragmentIndex = 0;
		this->ucBeatValue = 0;

		for (int i = 0; i < MAX_FRAGMENTS; i++)
		{
			this->noteFragments[i].bActive = false;
		}
	}


	// Base
	template<typename T>
	void setNoteFragment( T xNoteFragment )
	{
		std::cout << "Set Note Fragment" << std::endl;
		xNoteFragment.bActive = true;
		this->noteFragments[this->ucNoteFragmentIndex++] = xNoteFragment;
	}
	
	template<typename T, typename ...TPack>
	void setNoteFragment( T xNoteFragment, TPack... noteFragmentPack )
	{
		std::cout << "Set Note Fragment" << std::endl;
		xNoteFragment.bActive = true;
		this->noteFragments[this->ucNoteFragmentIndex++] = xNoteFragment;
		setNoteFragment( noteFragmentPack... );
	}


	// Base (rest)
	template<typename T>
	void setBeatValue( T ucBeatValue )
	{
		std::cout << "Set Beat Value" << std::endl;
		this->ucBeatValue = ucBeatValue;
	}


	template<typename T1, typename ...T2Pack>
	void setBeatValue( T1 ucBeatValue, T2Pack... noteFragmentPack )
	{
		std::cout << "Set Beat Value" << std::endl;
		this->ucBeatValue = ucBeatValue;
		setNoteFragment( noteFragmentPack... );
	}


	template<typename T1, typename ...T2Pack>
	void set( T1 ucBeatValue, T2Pack... noteFragmentPack )
	{
		reset();
		setBeatValue( ucBeatValue, noteFragmentPack... );
	}
};




struct Piece
{
private:
	std::string xName;
	//FILE* pxOut;
	std::ofstream xOut;
	Fragment xFragment;

    uint32_t ulCompositionSize;
public:
	Piece(const std::string& xName ) : xName(xName), xFragment(), ulCompositionSize(0) {}
	~Piece() {}

    uint32_t getCompositionSize()
    {
        return this->ulCompositionSize;
    }

	void vStartComposition()
	{
		xOut.open( xName.c_str(), std::ios::out | std::ios::binary );
		if ( !xOut.is_open() )
		{
			std::cout << "ERROR: Faield to open" << std::endl;
		}


		/*
		fopen_s( &this->pxOut, xName.c_str(), "wb" );
		if ( this->pxOut == NULL )
		{
			std::cout << "FAIL" << std::endl;
		}
		*/
	}

	void vEndComposition()
	{
		//fclose( this->pxOut );
		xOut.close();
	}


	void vWriteHeader()
	{
		static const uint8_t testData = 0x00;
		for ( int i = 0; i < HEADER_SIZE_BYTE; i++ )
		{
			xOut.write( (const char*)&testData, sizeof( testData ) );
			//fwrite( &testData, sizeof( testData ), 1, this->pxOut );
		}
	}


	void vWriteCompositionSize( uint32_t ulCompositionSize )
	{
		xOut.write( ( const char* )&ulCompositionSize, sizeof( ulCompositionSize ) );
		//fwrite( &ulCompositionSize, sizeof( ulCompositionSize ), 1, this->pxOut );
	}


	/* Later have flags indicating Movement, BPM, Dynamic, etc.
	* For now just implictly include all and configure all
	*/
	void vWriteResetConfig()
	{
		uint8_t ucResetConfigCommand = 0x7F;
		uint8_t ucMovement = 2;
		uint16_t usBPM = 56;
		uint8_t ucDynamic = PIANO;

		//fwrite( &ucResetConfigCommand, sizeof( ucResetConfigCommand ), 1, this->pxOut );
		//fwrite( &ucMovement, sizeof( ucMovement ), 1, this->pxOut );
		//fwrite( &usBPM, sizeof( usBPM ), 1, this->pxOut );
		//fwrite( &ucDynamic, sizeof( ucDynamic ), 1, this->pxOut );

		xOut.write( ( const char* )&ucResetConfigCommand, sizeof( ucResetConfigCommand ) );
        this->ulCompositionSize += sizeof( ucResetConfigCommand );

		xOut.write( ( const char* )&ucMovement, sizeof( ucMovement ) );
        this->ulCompositionSize += sizeof( ucMovement );

		xOut.write( ( const char* )&usBPM, sizeof( usBPM ) );
        this->ulCompositionSize += sizeof( usBPM );

		xOut.write( ( const char* )&ucDynamic, sizeof( ucDynamic ) );
        this->ulCompositionSize += sizeof( ucDynamic );
	}


	template<typename ...TPack>
	void vWriteFragment(uint8_t ucTupletValue, uint8_t ucBeatValue, TPack... noteFragmentPack )
	{
		// Set the stage for fragment commands
		xFragment.set( ((ucTupletValue << 4) | (ucBeatValue)), noteFragmentPack... );



		// Write Play Command
		// [!] Handle case of beat value = 0 and num fragments = 0 (rest!) on embedded application
		uint8_t ucWriteNumFragments = this->xFragment.getNoteFragmentIndex();
		// [!] error for numFragments > 4
		if ( ucWriteNumFragments > 4 )
		{
			std::cout << "ERROR: ucWriteNumFragments > 4" << std::endl;
		}
		uint8_t ucPlayCommand = ( COMMAND_PLAY_BIT << 7 ) | /*( ucWriteBeatValue << 3 ) MISCELLANEOUS FOR NOW |*/ ( ucWriteNumFragments << 0 );
		//fwrite( &ucPlayCommand, sizeof( ucPlayCommand ), 1, this->pxOut );
		xOut.write( ( const char* )&ucPlayCommand, sizeof( ucPlayCommand ) );
		this->ulCompositionSize += sizeof( ucPlayCommand );
		
		
		// Write Beat value
		uint8_t ucWriteBeatValue = this->xFragment.getBeatValue();
		xOut.write( ( const char* )&ucWriteBeatValue, sizeof( ucWriteBeatValue ) );
        this->ulCompositionSize += sizeof( ucWriteBeatValue );

		
		// Write Fragments
		bool isRest = (this->xFragment.getNoteFragmentIndex() == 0);
		uint16_t usFragmentInformation = 0x0000;
		NoteFragment* pxNoteFragments = this->xFragment.getNoteFragments();

		if ( isRest )
		{
			std::cout << "REST COMMAND" << std::endl; // No need to send a fragment (just use information from write play command (stall for the beat value)
		}
		else
		{
			for ( int i = 0; i < MAX_FRAGMENTS; i++ )
			{
				if ( pxNoteFragments[i].bActive )
				{
					usFragmentInformation = ( ( uint16_t )pxNoteFragments[i].ucBase << ( 8 + 6 ) ) | ( ( uint16_t )pxNoteFragments[i].ucOffset << 8 ) | ( ( uint16_t )pxNoteFragments[i].ucTechnique );
					printf( "Fragment " BYTE2_TO_BINARY_PATTERN "\r\n", BYTE2_TO_BINARY( usFragmentInformation ) );

					//fwrite( &usFragmentInformation, sizeof( usFragmentInformation ), 1, this->pxOut );
					xOut.write( ( const char* )&usFragmentInformation, sizeof( usFragmentInformation ) );
                    this->ulCompositionSize += sizeof( usFragmentInformation );
				}
				usFragmentInformation = 0x0000;
			}
		}
	}


	void vWriteEndCommand()
	{
		std::cout << "END COMMAND" << std::endl;
		static const uint8_t ucEndCommand = 0x00;
		//fwrite( &ucEndCommand, sizeof( ucEndCommand ), 1, this->pxOut );
		xOut.write( ( const char* )&ucEndCommand, sizeof( ucEndCommand ) );
        this->ulCompositionSize += sizeof( ucEndCommand );
	}
};






int main()
{

	Piece xPiece( "test2.bin" );
	xPiece.vStartComposition();
	xPiece.vWriteHeader();
	xPiece.vWriteCompositionSize( COMPOSITION_SIZE );
	xPiece.vWriteResetConfig();

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, Ab3, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, Db4, 0 ) );
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Db4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, F4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Eb4, 0 ) );
	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( G, Eb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( G, Db4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Ab3, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Bb3, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, C4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Db4, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, Eb4, 0 ) );


	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, F4, 0 ) );
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, F4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Gb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, F4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Eb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, Ab4, 0 ) );
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Ab4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Ab4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Ab4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Bb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Gb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, F4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Eb4, 0 ) );
	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( G, Eb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( G, Bb3, 0 ) );
	//
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Eb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Db4, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, Bb3, 0 ) );
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Bb3, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, C4, 0 ) );
	//
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Db4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Eb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, F4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Ab4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, C5, 0 ) );
	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( G, C5, 0 ) );

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( G, Bb4, 0 ) );
	//
	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, G4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, G4, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, Ab4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, A4, 0 ) );
	//
	xPiece.vWriteFragment( NOPELET, MINIM, NoteFragment( G, Bb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, Bb4, 0 ) );
	//
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Bb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, C5, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( G, F4, 0 ) );


	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab4, 0 ) );
	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( D, Ab4, 0 ) );

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( D, A4, 0 ) );
	//

	xPiece.vWriteFragment( NOPELET,	CROTCHET, NoteFragment( D, Bb4, 0 ) );

	xPiece.vWriteFragment( NOPELET,	QUAVER, NoteFragment( D, Bb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( D, Bb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Bb4, 0 ) );
	//

	xPiece.vWriteFragment( TRIPLET, QUAVER, NoteFragment( D, C5, 0 ) );
	xPiece.vWriteFragment( TRIPLET, QUAVER, NoteFragment( D, Eb5, 0 ) );
	xPiece.vWriteFragment( TRIPLET, QUAVER, NoteFragment( D, Db5, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Bb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, C5, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Db5, 0 ) );
	//

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( D, Eb5, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( D, F5, 0 ) );
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, F5, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Eb5, 0 ) );

	//
	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( D, Ab5, 0 ) );
	
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab5, 0 ) );
	
	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( D, Bb5, 0 ) );
	
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab5, 0 ) );
	//
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Bb4, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, C5, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, D5, 0 ) );

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( D, Eb5, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, F5, 0 ) );
	//
	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Gb5, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab5, 0 ) );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( E, A5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( E, Bb5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, Gb5, 0 ), NoteFragment( E, Eb6, 0 ));
	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( A, Gb5, 0 ), NoteFragment( E, Eb6, 0 ));

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( A, F5, 0 ), NoteFragment( E, Db6, 0 ));
	//


	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, F5, 0 ), NoteFragment( E, Db6, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, Eb5, 0 ), NoteFragment( E, C6, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, B4, 0 ), NoteFragment( E, G5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, Db5, 0 ), NoteFragment( E, Bb5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, C5, 0 ), NoteFragment( E, Ab5, 0 ));

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER );

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( D, Gb4, 0 ), NoteFragment( A, Eb5, 0 ));

	//

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Bb4, 0 ), NoteFragment( A, Gb5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab4, 0 ), NoteFragment( A, F5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, E4, 0 ), NoteFragment( A, C5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Gb4, 0 ), NoteFragment( A, Eb5, 0 ));

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( D, F4, 0 ), NoteFragment( A, Db5, 0 ));

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab4, 0 ), NoteFragment( A, F5, 0 ));

	//

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab4, 0 ), NoteFragment( A, F5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, G4, 0 ), NoteFragment( A, Eb5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, C4, 0 ), NoteFragment( D, A4, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Eb4, 0 ), NoteFragment( D, C5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( G, Db4, 0 ), NoteFragment( D, Bb4, 0 ));
	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( G, Db4, 0 ), NoteFragment( D, Bb4, 0 ));

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( D, F4, 0 ), NoteFragment( A, Db5, 0 ));

	//

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab4, 0 ), NoteFragment( A, F5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, G4, 0 ), NoteFragment( A, Eb5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Bb4, 0 ), NoteFragment( A, G5, 0 ));

	xPiece.vWriteFragment( NOPELET, CROTCHET, NoteFragment( A, Eb5, 0 ), NoteFragment( E, C6, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, Db5, 0 ), NoteFragment( E, Bb5, 0 ));

	//

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, Db5, 0 ), NoteFragment( E, Bb5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, C5, 0 ), NoteFragment( E, Ab5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER );

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, F4, 0 ), NoteFragment( A, D5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Ab4, 0 ), NoteFragment( A, F5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( D, Gb4, 0 ), NoteFragment( A, Eb5, 0 ));

	//

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, Bb4, 0 ), NoteFragment( E, Gb5, 0 ));
	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( A, Bb4, 0 ), NoteFragment( E, Gb5, 0 ));

	xPiece.vWriteFragment( NOPELET, SEMIQUAVER, NoteFragment( A, Db5, 0 ), NoteFragment( E, Bb5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, C5, 0 ), NoteFragment( E, Ab5, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, Eb5, 0 ), NoteFragment( E, C6, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, Ab5, 0 ), NoteFragment( E, F6, 0 ));

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( A, Gb5, 0 ), NoteFragment( E, Eb6, 0 ));
	//

	xPiece.vWriteFragment( NOPELET, QUAVER, NoteFragment( E, Ab5, 0 ));

	//

	xPiece.vWriteEndCommand();

    // xPiece.reWriteCompositionSize(seekp past the constant header initial)
	xPiece.vEndComposition();

    std::cout << xPiece.getCompositionSize() << std::endl;

	return 0;
}




