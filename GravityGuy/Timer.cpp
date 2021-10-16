/**********************************************************************************
// Timer (C�digo Fonte)
// 
// Cria��o:     02 Abr 2011
// Atualiza��o: 10 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Usa um contador de alta precis�o para medir o tempo.
//
**********************************************************************************/

#include "Timer.h"
#include "Types.h"

// ------------------------------------------------------------------------------

Timer::Timer()
{
    // pega freq��ncia do contador de alta resolu��o
    QueryPerformanceFrequency(&freq);

    // zera os valores de in�cio e fim da contagem
    ZeroMemory(&start, sizeof(start));
    ZeroMemory(&end, sizeof(end));

    // timer em funcionamento
    stoped = false;
}

// ------------------------------------------------------------------------------

void Timer::Start()
{
    if (stoped)
    {
        // guarda tempo antes da parada
        //
        //      <--- elapsed ---> <--- stoped --->
        // ----|-----------------|----------------|----> time
        //    start              end              now 
        //
        
        // tempo transcorrida antes da parada
        llong elapsed = end.QuadPart - start.QuadPart;
        
        // retoma contagem do tempo
        //
        //      <--- elapsed --->
        // ----|-----------------|-----------> time
        //    start              now
        //                         

        // leva em conta tempo j� transcorrido antes da parada
        QueryPerformanceCounter(&start); 
        start.QuadPart -= elapsed;

        // retoma contagem normal
        stoped = false;
    }
    else
    {
        // inicia contagem do tempo
        QueryPerformanceCounter(&start);
    }
}

// ------------------------------------------------------------------------------

void Timer::Stop()
{
    if (!stoped)
    {
        // marca o ponto de parada do tempo
        QueryPerformanceCounter(&end);
        stoped = true;
    }
}

// ------------------------------------------------------------------------------

float Timer::Reset()
{
    llong elapsed;

    if (stoped)
    {
        // reseta a contagem do tempo
        //
        //      <--- elapsed ---> <--- stoped --->
        // ----|-----------------|----------------|------> time
        //    start              end              start
        //                       

        // pega tempo transcorrido antes da parada
        elapsed = end.QuadPart - start.QuadPart;
        
        // reinicia contagem do tempo
        QueryPerformanceCounter(&start); 
        
        // contagem reativada
        stoped = false;
    }
    else
    {
        // reseta a contagem do tempo
        //
        //      <--- elapsed --->
        // ----|-----------------|------------> time
        //    start              end     
        //                       start

        // finaliza contagem do tempo
        QueryPerformanceCounter(&end);

        // calcula tempo transcorrido (em ciclos)
        elapsed = end.QuadPart - start.QuadPart;

        // reinicia contador
        start = end;
    }

    // converte tempo para segundos
    return float(elapsed / double(freq.QuadPart));    
}

// ------------------------------------------------------------------------------

float Timer::Elapsed()
{
    llong elapsed;

    if (stoped)
    {
        // tempo transcorrido at� a parada
        //
        //      <--- elapsed ---> <--- stoped --->
        // ----|-----------------|----------------|----> time
        //    start              end              now
        //
        elapsed = end.QuadPart - start.QuadPart;
    }
    else
    {
        // tempo transcorrido
        //
        //      <--- elapsed ---> 
        // ----|-----------------|-----------> time
        //    start              end               
        //

        // finaliza contagem do tempo
        QueryPerformanceCounter(&end);

        // calcula tempo transcorrido (em ciclos)
        elapsed = end.QuadPart - start.QuadPart;
    }

    // converte tempo para segundos
    return float(elapsed / double(freq.QuadPart));
}

// -------------------------------------------------------------------------------