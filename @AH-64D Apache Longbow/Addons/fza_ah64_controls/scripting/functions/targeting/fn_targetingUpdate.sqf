/* ----------------------------------------------------------------------------
Function: fza_fnc_targetingUpdate
Description:
	Handles repetitive ASE targeting information management. Should be run regularly.
Parameters:
	_heli - The helicopter to act on
Returns:
	Nothing
Examples:
	--- Code
    [_heli] call fza_fnc_targetingUpdate
	---
Author:
	Rosd6(Dryden)
---------------------------------------------------------------------------- */
params ["_heli"];

fza_ah64_aseAudio = fza_ah64_asethreats;
{
	if ((vehicle player) animationphase "plt_apu" > 0.5 || (isEngineOn _heli)) then {
		if ((_heli == assignedTarget _x || _x AimedAtTarget[_heli] > 0.5) && (alive _x) && !(_x in fza_ah64_threattracking) && (true == isVehicleRadarOn vehicle _x)) then {
			fza_ah64_threattracking = fza_ah64_threattracking + [_x];
			fza_ah64_targetlist = fza_ah64_targetlist + [_x];
			_x confirmSensorTarget [playerSide, true];
			if (_x iskindof "rhs_zsutank_base") then {
				["fza_ah64_zsu23_track", 2.3] spawn fza_fnc_playAudio;
			};
			if (_x iskindof "O_APC_Tracked_02_AA_F") then {
				["fza_ah64_bt_sa19", 1.6, "fza_ah64_bt_tracking", 0.65] spawn fza_fnc_playAudio;
			};
			if !((_x iskindof "rhs_zsutank_base") || (_x iskindof "O_APC_Tracked_02_AA_F")) then {
				["fza_ah64_rdr_track", 0.1] spawn fza_fnc_playAudio;
			};
			if (_heli getVariable "fza_ah64_aseautopage" == 1) then {
				[_heli, 1, "ase"] call fza_fnc_mpdSetDisplay;
			};
		};
		if !((_heli == assignedTarget _x || _x AimedAtTarget[_heli] > 0.1) || (alive _x) || (true == isVehicleRadarOn vehicle _x) && !(_x in fza_ah64_threattracking)) then {
			fza_ah64_threattracking = fza_ah64_threattracking - [_x];
		};
	};
} forEach fza_ah64_aseAudio