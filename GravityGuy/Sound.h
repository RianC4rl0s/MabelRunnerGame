/**********************************************************************************
// Sound (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Out 2011
// Atualiza��o: 19 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Representa um som no formato WAVE
//
**********************************************************************************/

#ifndef _PROGJOGOS_SOUND_H_
#define _PROGJOGOS_SOUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"
#include <xaudio2.h> 
#include <string>
using std::string;

// ---------------------------------------------------------------------------------

class Sound
{
private:
    WAVEFORMATEXTENSIBLE format;                        // formato do arquivo .wav
    XAUDIO2_BUFFER       buffer;                        // buffer com os dados do som
    float                volume;                        // volume do som
    float                frequency;                     // freq��ncia do som

    IXAudio2SourceVoice  ** voices;                     // vetor de ponteiros para vozes
    uint                 tracks;                        // n�mero de vozes para este som
    uint                 index;                         // �ndice da voz selecionada

    HRESULT FindChunk(HANDLE hFile, 
                      DWORD fourcc, 
                      DWORD & dwChunkSize, 
                      DWORD & dwChunkDataPosition);     // localiza blocos no arquivo RIFF

    HRESULT ReadChunkData(HANDLE hFile, 
                          void * buffer, 
                          DWORD buffersize, 
                          DWORD bufferoffset);          // l� blocos do arquivo para um buffer

    friend class Audio;

public:
    Sound(string fileName, uint nTracks);               // construtor
    ~Sound();                                           // destrutor
};

// ---------------------------------------------------------------------------------


#endif