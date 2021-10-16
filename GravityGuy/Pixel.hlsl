/**********************************************************************************
// Pixel (Arquivo de Sombreamento)
//
// Cria��o:     11 Jul 2007
// Atualiza��o: 13 Ago 2021
// Compilador:  D3DCompiler
//
// Descri��o:   Define um pixel shader que apenas multiplica a cor do objeto 
//              pela cor da textura, depois de fazer uma amostragem linear
//              ou anisotr�pica
//
**********************************************************************************/


Texture2D resource;

SamplerState linearfilter
{
    Filter = MIN_MAG_MIP_LINEAR;
};

SamplerState anisotropic
{
    Filter = ANISOTROPIC;
    MaxAnisotropy = 4;
};

struct pixelIn
{
    float4 Pos   : SV_POSITION;
    float4 Color : COLOR;
    float2 Tex   : TEXCOORD;    
};

float4 main(pixelIn pIn) : SV_TARGET
{
    return resource.Sample(linearfilter, pIn.Tex) * pIn.Color;    
}