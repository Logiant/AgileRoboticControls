// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "XInput.h"
#include "Windows.h"
#include "math.h"
#include "XboxInterface.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	return TRUE;
}

//Function Declarations
extern "C" __declspec(dllexport) int getLeftJoyStick(int);
extern "C" __declspec(dllexport) int getRightJoyStick(int);
extern "C" __declspec(dllexport) int getButtonStates(int);
extern "C" __declspec(dllexport) short getTriggerStates(int);

//The code implementation
#include "XboxInterface.cpp"
/*
DWORD readControllerState(XINPUT_STATE* state, int controllerNumber){
	//Check that the programmer only specified controller 0,1,2,or 3
	//If they failed default to zero
	if (controllerNumber > 3 || controllerNumber < 0){
		controllerNumber = 0;
	}
	return XInputGetState(controllerNumber, state);
}
*/

__declspec(dllexport) int getLeftJoyStick(int controllerNumber){
	DWORD dwResult;
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	dwResult = XInputGetState(controllerNumber, &state);

	//Declare retrun value
	int retVal = 0;

	if (dwResult == ERROR_SUCCESS){
		//Controller 
		retVal = (state.Gamepad.sThumbLX << SHORT_SHIFT) | state.Gamepad.sThumbLY;
	}
	return retVal;
}

__declspec(dllexport) int getRightJoyStick(int controllerNumber){
	DWORD dwResult;
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	dwResult = XInputGetState(controllerNumber, &state);

	//Declare retrun value
	int retVal = 0;

	if (dwResult == ERROR_SUCCESS){
		//Controller 
		retVal = (state.Gamepad.sThumbRX << SHORT_SHIFT) | state.Gamepad.sThumbRY;
	}
	return retVal;
}

__declspec(dllexport) int getButtonStates(int controllerNumber){
	DWORD dwResult;
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	dwResult = XInputGetState(controllerNumber, &state);

	//Declare retrun value
	int retVal = 0;

	if (dwResult == ERROR_SUCCESS){
		//Controller Connected
		retVal = state.Gamepad.wButtons;
	}
	return retVal;
}

//short = byte(leftTrigger) + byte(rightTrigger)
__declspec(dllexport) short getTriggerStates(int controllerNumber){
	DWORD dwResult;
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	dwResult = XInputGetState(controllerNumber, &state);

	//Declare retrun value
	short retVal = 0;

	if (dwResult == ERROR_SUCCESS){
		//Controller Connected
		retVal = ((state.Gamepad.bLeftTrigger) << BYTE_SHIFT) | state.Gamepad.bRightTrigger;
	}
	return retVal;
}