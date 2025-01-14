/* ----------------------------------------------------------------------------
Function: fza_fnc_sfmplusSetFuel

Description:


Parameters:
	_heli - The apache helicopter to get information from [Unit].

Returns:
	The mass of the forward and aft fuel cells.

Examples:
	...
	_fuelMass = [_heli] call fza_fnc_setFuel;
	_fwdFuelMass = _fuelMass select 0;
	_aftFuelMass = _fuelMass select 1;

Author:
	BradMick
---------------------------------------------------------------------------- */
params ["_heli"];

private _percentFuel    = fuel _heli;
private _maxFwdFuelMass = _heli getVariable "fza_ah64_maxFwdFuelMass";
private _maxAftFuelMass = _heli getVariable "fza_ah64_maxAftFuelMass";
private _maxTotFuelMass = _maxFwdFuelMass + _maxAftFuelMass;
_heli setVariable ["fza_ah64_maxTotFuelMass", _maxTotFuelMass];

private _totFuelMass = _maxTotFuelMass * _percentFuel;
private _fwdFuelMass = [_totFuelMass / 2, 0, _maxFwdFuelMass] call BIS_fnc_clamp;
private _aftFuelMass = _totFuelMass - _fwdFuelMass;

[_fwdFuelMass, _aftFuelMass];