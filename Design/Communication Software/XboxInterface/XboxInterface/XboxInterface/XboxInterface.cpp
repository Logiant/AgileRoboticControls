// XboxInterface.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"//Required to build DLL, must also be at top of this file
#include "Windows.h"//Required to use DWORD, must be before #ifndef
#ifndef XboxInterface_CPP
#define XboxInterface_CPP
#include "XboxInterface.h"

/*
//readControllerStates is only used by the internally by the DLL
//state: pointer to memory sizeof(XINPUT_STATE)
//controllerNumber: The number of the Xbox controller to read the state from
//returns: DWORD - zero when successful, 1167 when no controller 
DWORD readControllerState(XINPUT_STATE* state, int controllerNumber){
	//Check that the programmer only specified controller 0,1,2,or 3
	//If they failed default to zero
	if (controllerNumber > 3 || controllerNumber < 0){
		controllerNumber = 0;
	}
	return XInputGetState(controllerNumber, state);
}

__declspec(dllexport) int getLeftJoyStick(int controllerNumber){
	DWORD dwResult;
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	readControllerState(&state, controllerNumber);

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
	readControllerState(&state, controllerNumber);

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
	readControllerState(&state, controllerNumber);

	//Declare retrun value
	int retVal = 0;

	if (dwResult == ERROR_SUCCESS){
		//Controller Connected
		retVal = state.Gamepad.wButtons;
	}
	return retVal;
}

__declspec(dllexport) short getTriggerStates(int controllerNumber){
	DWORD dwResult;
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	readControllerState(&state, controllerNumber);

	//Declare retrun value
	short retVal = 0;

	if (dwResult == ERROR_SUCCESS){
		//Controller Connected
		retVal = ((state.Gamepad.bLeftTrigger) << BYTE_SHIFT) | state.Gamepad.bRightTrigger;
	}
	return retVal;
}
*/

#endif