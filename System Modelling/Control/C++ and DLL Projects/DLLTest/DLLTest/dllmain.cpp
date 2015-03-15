// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "math.h"    //library that defines the pow function
#define M_PI 3.14159 //declare our M_PI constant

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return -1;
}

//Function declarations
extern "C" __declspec(dllexport) int GetSphereSAandVol(double radius, double sa, double vol);

__declspec(dllexport) int GetSphereSAandVol(double radius, double sa, double vol)
//Calculate the surface area and volume of a sphere with given radius
{	
	sa = 7;
	vol = 14;
	return radius * 2;
}

