params["_heli"];
#include "\fza_ah64_controls\headers\selections.h"

//Lbs
//#define FORWARD_FUEL_CELL_WEIGHT 1041
//#define AFT_FUEL_CELL_WEIGHT 1534
//#define TOTAL_FUEL_CELL_WEIGHT 2575
#define KGTOLBS 2.20462


private _forwardCellWeight = [_heli] call fza_fnc_sfmplusSetFuel select 0;
private _aftCellWeight     = [_heli] call fza_fnc_sfmplusSetFuel select 1;
private _totFuelCellWeight = _forwardCellWeight + _aftCellWeight;
_forwardCellWeight = _forwardCellWeight * KGTOLBS;
_aftCellWeight     = _aftCellWeight * KGTOLBS;
_totFuelCellWeight = _totFuelCellWeight * KGTOLBS;

private _fuelWeight = _totFuelCellWeight;

private _FFVal = [_heli] call fza_fnc_sfmplusGetData select 2;
_FFVal = _FFVal * 7936.64;

private _eng1FuelCons = 0;
private _eng1State    = ((_heli getVariable "fza_ah64_engineStates") select 0) select 0;
if (isEngineOn _heli && (_eng1State != "OFF")) then {
	_eng1FuelCons = _FFVal / 2;
} else {
	_eng1FuelCons = 0;
};

private _eng2FuelCons = 0;
private _eng2State    = ((_heli getVariable "fza_ah64_engineStates") select 1) select 0;
if (isEngineOn _heli && (_eng2State != "OFF")) then {
	_eng2FuelCons = _FFVal / 2;
} else {
	_eng2FuelCons = 0;
};

private _totalFuelConsumption = _eng1FuelCons + _eng2FuelCons;

private _enduranceNumber = if(_totalFuelConsumption > 0) then {
	private _enduranceTotal = _fuelWeight / _totalFuelConsumption * 60; //Minutes
	private _enduranceMinutes = _enduranceTotal % 60;
	private _enduranceHours = floor(_enduranceTotal / 60);
	100 * _enduranceHours + _enduranceMinutes;
} else {999;};

[_heli, _forwardCellWeight, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_FWD_FUEL] call fza_fnc_drawNumberSelections;
[_heli, _aftCellWeight, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_AFT_FUEL] call fza_fnc_drawNumberSelections;
[_heli, 0, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_IAFS_FUEL] call fza_fnc_drawNumberSelections;

//[_heli, _engineFuelConsumption # 0, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_FLOW1_FUEL] call fza_fnc_drawNumberSelections;
//[_heli, _engineFuelConsumption # 1, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_FLOW2_FUEL] call fza_fnc_drawNumberSelections;
[_heli, _eng1FuelCons, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_FLOW1_FUEL] call fza_fnc_drawNumberSelections;
[_heli, _eng2FuelCons, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_FLOW2_FUEL] call fza_fnc_drawNumberSelections;
[_heli, _totalFuelConsumption, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_TFLOW_FUEL] call fza_fnc_drawNumberSelections;

[_heli, _fuelWeight, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_INT_FUEL] call fza_fnc_drawNumberSelections;
[_heli, _fuelWeight, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_TOT_FUEL] call fza_fnc_drawNumberSelections;

[_heli, _enduranceNumber, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_IEND_FUEL] call fza_fnc_drawNumberSelections;
[_heli, _enduranceNumber, "\fza_ah64_us\tex\CHAR\G", SEL_DIGITS_PL_TEND_FUEL] call fza_fnc_drawNumberSelections;
