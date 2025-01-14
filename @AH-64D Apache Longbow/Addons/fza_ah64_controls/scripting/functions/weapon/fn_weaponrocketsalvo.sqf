/* ----------------------------------------------------------------------------
Function: fza_fnc_weaponRocketsalvo

Description:
    changes the rocket salvo value to the next

Parameters:
    _heli - The helicopter that fired it

Returns:

Examples:
	statement="[this] spawn weaponRocketsalvo";

Author:
	
---------------------------------------------------------------------------- */

// Disables to reduce script running of disabled function
/*params["_heli"];

_salvo = _heli getVariable "fza_ah64_rocketsalvo";
_salvo = switch (_salvo) do {
    case 1: {2};
    case 2: {4};
    case 4: {8};
    case 8: {12};
    case 12: {24};
    case 24: {38};
    case 38: {1};
};
_heli setVariable ["fza_ah64_rocketsalvo", _salvo]