class CfgAmmo
{
	class Default{};
	class B_30mm_HE;
	class Bulletbase;
	class MissileCore;
	class MissileBase;
	class Missile_AGM_02_F : MissileBase {
		class Components;
		class EventHandlers;
	};
	class RocketCore;
	class RocketBase;
	class GrenadeBase;
	class FlareCore;
	class B_9x21_Ball;
	
	class fza_ah64_flare_shot: FlareCore 
	{
		hit 						= 1;
		indirectHit 				= 0;
		indirectHitRange 			= 0;
		timeToLive 					= 14;
		thrustTime 					= 4;
		airFriction 				= -0.01;
		simulation 					= "shotCM";
		effectsSmoke 				= "fza_cmflare";
		weaponLockSystem 			= 2+8;
		model 						= "\A3\weapons_f\empty";
		maxControlRange 			= -1;
		initTime 					= 0;
		aiAmmoUsageFlags			= 8;	
	};
	class fza_master: Default
	{
		airLock						=0;
		irLock						=0;
		laserLock					=0;
		nvLock						=0;
		artilleryLock				=0;
		weaponLockSystem			=0;
		lockType					=2;
	};
	
	///////////////////////////////////////////////////////////////////////
	//////////////////////////////M230/////////////////////////////////////
	///////////////////////////////////////////////////////////////////////	
	
	class fza_30x113: B_30mm_HE
	{
		ace_frag_enabled			= 0;
		ace_frag_skip 				= 1;
		soundsetbulletfly[] 		= {"fza_sc_bullet_flyby_soundset"};
		soundsetsoniccrack[] 		= {"fza_sc_30x113_soundset"};
		soundsetexplosion[] 		= {"fza_20mm_explosion_soundset", "fza_explosion_echo_small_soundset"};

		//duel purpose warhead
		submunitionAmmo				="ammo_Penetrator_30mm";
		submunitionDirectionType	="SubmunitionModelDirection";
		submunitionInitSpeed		=1000;
		submunitionParentSpeedCoef	=0;
		submunitionInitialOffset[]	={0,0,-0.2};
		triggerOnImpact				=1;
		deleteParentWhenTriggered	=0;

		hit 						= 60;
		indirectHit 				= 20;
		indirectHitRange 			= 3.5;		
		maxspeed 					= 805;
		explosive					= 0.8;

		airFriction 				= -0.00036;
		airlock 					= 0;
		irlock						= 0;
		weaponType 					= "cannon";

		//AI uasge
		aiAmmoUsageFlags 			= "64+128+256"
		allowAgainstInfantry 		= 1;
		cost 						= 15;
		visibleFire=32;
		audibleFire=200;
		visibleFireTime=3;
		dangerRadiusBulletClose=20;
		dangerRadiusHit=60;
		suppressionRadiusBulletClose=12;
		suppressionRadiusHit=24;
	};
	
	///////////////////////////////////////////////////////////////////////
	//////////////////////////////HELLFIRE/////////////////////////////////
	///////////////////////////////////////////////////////////////////////	
	class fza_agm114base : Missile_AGM_02_F {

		ace_frag_enabled 			= 0;
		ace_frag_skip 				= 1;

		fza_salType 				= "sal2";
		irLock						= 1;
		laserLock					= 0;
		airLock						= 0;

		maxSpeed					= 425;
		simulationStep				= 0.005;
		airFriction					= 0.03;
		sideAirFriction				= 0.15;
		initTime					= 0;
		thrustTime					= 3;
		thrust						= 199;
		fuseDistance				= 100;
		manualControl 				= 0;
		maxControlRange				= 8000;
		trackOversteer				= 4;
		trackLead					= 1.2;
		maneuvrability				= 21;
		timeToLive					= 70;
		cmImmunity					= 0.97;

		//AI uasge
		aiAmmoUsageFlags 			= "64+128+512";
		allowAgainstInfantry 		= 1;
		cost 						= 1000;

		//Penetrator
		submunitionAmmo				="ammo_Penetrator_AGM_01";
		submunitionDirectionType	="SubmunitionModelDirection";
		submunitionInitSpeed		=1000;
		submunitionParentSpeedCoef	=0;
		submunitionInitialOffset[]	={0,0,-0.2};
		triggerOnImpact				=1;
		deleteParentWhenTriggered	=0;

		effectsmissile 				= "fza_ah64_hellfiresmoke";
		muzzleEffect 				= "BIS_fnc_effectFiredHeliRocket";
		effectsMissileInit 			= "MissileDAR1";
		explosionEffects 			= "BombExplosion"; 
		soundsetsoniccrack[] 		= {"fza_sc_wire_flyby_soundset"};
		soundfly[]  				= {"fza_ah64_us\audio\Flyby\soundfly1.ogg", 1, 1.500000, 400};
		soundsetexplosion[] 		= {"fza_rocket_explosion_soundset", "fza_missile_explosion_stereo_soundset", "fza_shell_explosion_reverb_soundset"};
		whistledist 				= 300;

		//Missile sensors definition
		missileLockMaxDistance		= 8000;
		missileLockMinDistance		= 700;
		missileLockMaxSpeed			= 56;
		missileLockCone				= 90;
		missileKeepLockedCone		= 90;
		lockSeekRadius				= 2000;
		autoSeekTarget 				= 0;
		weaponLockSystem			= "4 + 8";
		maneuvDependsOnSpeedCoef	= 0.018;

		flightProfiles[]	= {TopDown,LoalDistance,Cruise};
		class Direct{};
		class TopDown
		{
			ascendAngle				= 39;
			ascendHeight			= 360;
			minDistance				= 600;
			descendDistance			= 700;
		};
		class LoalDistance
		{
			lockSeekDistanceFromParent = 500;
		};
		class Cruise
		{
			preferredFlightAltitude = 500;
			lockDistanceToTarget = 1000;
		};

		class Components : Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class RadarSensorComponent : SensorTemplateActiveRadar
					{
						class AirTarget {
							minRange = 8000;
							maxRange = 8000;
						};
						class GroundTarget {
							minRange = 8000;
							maxRange = 8000;
						};
						typeRecognitionDistance = -1; // distance how far the target type gets recognized
						angleRangeHorizontal = 90;     // sensor azimuth coverage in degrees
						angleRangeVertical = 90;
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;        // target speed in km/h above which the target will start to become visible
						maxSpeedThreshold = -1;       // target speed above which the target becomes visible even if below groundNoiseDistanceCoef, linearly decreases to minSpeedThreshold
						maxFogSeeThrough = 0.8;
						minTrackableSpeed = 0;
						maxTrackableSpeed = 56;
						minTrackableATL = -1;
						maxTrackableATL = 1000;
					};
				};
			};
		};
		class Eventhandlers: Eventhandlers
		{
			class FZA_EH
			{
				fired = "_this call fza_fnc_weaponMissileSlowDown";
			};
		};
	};
	class fza_agm114l : fza_agm114base
	{
		fza_salType 				= "rf";
		model 						= "\fza_ah64_US\fza_agm114l";
		proxyShape					= "\fza_ah64_US\fza_agm114l";
		simulation 					= "shotMissile";

		//AI usage
		aiAmmoUsageFlags 			= "128+512";
		allowAgainstInfantry 		= 0;
		cost 						= 1000;
		
		hit 						= 600;
		indirectHit 				= 200;
		indirectHitRange 			= 4;

		airLock 					= 1;
		irlock 						= 1;	
		nvLock						= 0;

		activeSensorAlwaysOn = 0;
		missileLockCone				= 90;
		missileKeepLockedCone		= 90;
		flightProfiles[]	= {TopDown,LoalDistance,Cruise};
		class TopDown
		{
			ascendAngle				= 26.5;
			ascendHeight			= 850;
			minDistance				= 1000;
			descendDistance			= 1200;
		};
	};
	class fza_agm114k : fza_agm114base
	{
		model 						= "\fza_ah64_us\fza_agm114k"; 
		proxyShape					= "\fza_ah64_us\fza_agm114k";

		//AI usage
		aiAmmoUsageFlags 			= "128+512";
		allowAgainstInfantry 		= 0;
		cost 						= 1000;

		hit 						= 600;
		indirectHit 				= 200;
		indirectHitRange 			= 4;

		laserLock 					= 1;
		airLock 					= 0;
		irlock 						= 0;	
		nvLock						= 0;
		
		//MSL sensors definition
		missileLockMaxDistance 		= 8000;
		missileLockMinDistance 		= 500;
		missileLockMaxSpeed 		= 56;
		missileLockCone 			= 90;
		missileKeepLockedCone 		= 90;
		missileManualControlCone 	= 90;
		weaponLockSystem 			= "4";
		weaponType					= "missileAT";
		class Components : Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class LaserSensorComponent : SensorTemplateLaser
					{
						class AirTarget {
							minRange = 7000;
							maxRange = 7000;
						};
						class GroundTarget {
							minRange = 7000;
							maxRange = 7000;
						};
						angleRangeHorizontal = 30;
						angleRangeVertical = 50;
						typeRecognitionDistance = -1;
						maxGroundNoiseDistance = 0;   // distance from the ground in meters, hard cap, above which the target will be visible even if still below groundNoiseDistanceCoef
						maxFogSeeThrough = 0.3;
						allowsMarking= 1;
					};
				};
			};
		};
	};
	class fza_agm114a : fza_agm114k
	{		
		fza_salType 				= "sal1";
		model 						= "\fza_ah64_US\fza_agm114c";
		proxyShape					= "\fza_ah64_US\fza_agm114c";
		effectsmissile 				= "missile3";

		submunitionAmmo				= "ammo_Penetrator_Titan_AT";

		hit							= 200;
		indirectHit 				= 80;
		indirectHitRange 			= 4;

		//AI usage
		aiAmmoUsageFlags 			= "128+512";
		allowAgainstInfantry 		= 0;
		cost 						= 500;
	};
	class fza_agm114c : fza_agm114k
	{
		fza_salType 				= "sal1";
		model 						= "\fza_ah64_US\fza_agm114c";
		proxyShape					= "\fza_ah64_US\fza_agm114c";

		submunitionAmmo				= "ammo_Penetrator_Titan_AT_long";

		hit							= 260;
		indirectHit 				= 100;
		indirectHitRange 			= 4;

		//AI usage
		aiAmmoUsageFlags 			= "128+512";
		allowAgainstInfantry 		= 0;
		cost 						= 600;
	};
	class fza_agm114m : fza_agm114k
	{
		ace_frag_enabled 			= 1;
		ace_frag_skip 				= 0;
		ace_frag_force 				= 1;
		model 						= "\fza_ah64_US\fza_agm114k";
		proxyShape 					= "\fza_ah64_US\fza_agm114k";		
		hit 						= 100;
		indirectHit 				= 100;
		indirectHitRange 			= 40;

		submunitionAmmo				= "";

		//AI usage
		aiAmmoUsageFlags 			= "64+128+512";
		allowAgainstInfantry 		= 1;
		cost 						= 700;
	};
	class fza_agm114n : fza_agm114k
	{
		model 						= "\fza_ah64_US\fza_agm114k";
		proxyShape 					= "\fza_ah64_US\fza_agm114k";	
		hit 						= 200;
		indirecthit 				= 200;
		indirecthitrange 			= 12;
		explosionEffects 			= "BombExplosion";

		submunitionAmmo				= "";

		//AI usage
		aiAmmoUsageFlags 			= "64+128+512";
		allowAgainstInfantry 		= 1;
		cost 						= 700;
	};
	
	///////////////////////////////////////////////////////////////////////
	//////////////////////////////ROCKETS//////////////////////////////////
	///////////////////////////////////////////////////////////////////////	
	
	class fza_275_base: MissileBase 
	{

		ace_frag_enabled 			= 0;
		ace_frag_skip 				= 1;

		fza_wpnPageIconB 			= "";
		fza_wpnPageIconG 			= "";
		fza_shortCode 				= "";
		soundfly[]  				= {"fza_ah64_us\audio\Flyby\SoundFly1.ogg", 1, 1, 400};	
		soundsetexplosion[]  		= {"fza_rocket_explosion_soundset", "fza_rocket_explosion_stereo_soundset", "fza_shell_explosion_reverb_soundset"};
		soundsetsoniccrack[] 		= {"fza_sc_rocket_flyby_soundset"};
		model 						= "\fza_ah64_us\weps\fza_hydra_m151_wep";
		effectsmissile 				= "fza_ah64_rocketsmoke";
		effectsMissileInit 			= "MissileDAR1";
		muzzleEffect 				= "BIS_fnc_effectFiredHeliRocket";
		hit							= 60;
		indirectHit					= 20;
		indirectHitRange			= 10;
		manualControl				= 0;
		maxControlRange 			= 0;
		maneuvrability 				= 0;
		airLock 					= 0;
		irLock						= 0;
		laserLock 					= 0;
		nvLock 						= 0;
		weaponLockSystem			= 0;
		cmimmunity 					= 1;

		//AI uasge
		aiAmmoUsageFlags 			= "64+128";
		allowAgainstInfantry 		= 1;
		cost 						= 75;

		weaponType 					= "rocket";
		suppressionRadiusHit 		= 15;
		dangerRadiusHit 			= 40;
		initTime 					= 0.02;
		maxSpeed					= 840;
		thrustTime					= 2;
		thrust 						= 840;
		fuseDistance 				= 75;
		airFriction 				= 0.1;
		sideAirFriction 			= 0.004;
		timeToLive					= 15;
		whistleDist					= 24;
	};
	class fza_275_m151: fza_275_base
	{
		fza_wpnPageIconB 			= "\fza_ah64_us\tex\icons\6PD-B_ca.paa";
		fza_wpnPageIconG 			= "\fza_ah64_us\tex\icons\6PD-G_ca.paa";
		fza_shortCode 				= "6PD";
		model 						= "\fza_ah64_us\weps\fza_hydra_m151_wep";
		proxyShape 					= "\fza_ah64_us\fza_hydra_m151";	
		explosionEffects 			= "GrenadeExplosion";
		hit							= 60;
		indirectHit					= 40;
		indirectHitRange			= 13;
	};
	class fza_275_m229: fza_275_base
	{
		fza_wpnPageIconB 			= "\fza_ah64_us\tex\icons\6RC-B_ca.paa";
		fza_wpnPageIconG 			= "\fza_ah64_us\tex\icons\6RC-G_ca.paa";
		fza_shortCode 				= "6RC";
		model 						= "\fza_ah64_us\weps\fza_hydra_m229_wep";	
		proxyShape 					= "\fza_ah64_us\fza_hydra_m229";	
		explosionEffects 			= "GrenadeExplosion";
		hit							= 100;
		indirectHit					= 66;
		indirectHitRange			= 20;
		suppressionRadiusHit 		= 20;

	};
	class fza_275_m261: fza_275_base 
	{
		fza_wpnPageIconB 			= "\fza_ah64_us\tex\icons\6MP-B_ca.paa";
		fza_wpnPageIconG 			= "\fza_ah64_us\tex\icons\6MP-G_ca.paa";
		fza_shortCode 				= "6MP";
		model 						= "\fza_ah64_us\weps\fza_hydra_m261_wep";	
		proxyShape 					= "\fza_ah64_us\fza_hydra_m261";	
		explosionEffects 			= "GrenadeExplosion";		
		maxSpeed 					= 600;
		hit 						= 30;
		indirectHit 				= 5;
		indirectHitRange 			= 5;
		submunitionDirectionType	= "SubmunitionModelDirection";
		submunitionAmmo 			= "fza_m73mpsm";
		submunitionConeType[] 		= {"randomcenter",9};
		submunitionConeAngle		= 2;

		//AI uasge
		aiAmmoUsageFlags 			= "64";
		cost 						= 100;
	};
	class fza_275_m257: fza_275_base 
	{	
		fza_wpnPageIconB 			= "\fza_ah64_us\tex\icons\6IL-B_ca.paa";
		fza_wpnPageIconG 			= "\fza_ah64_us\tex\icons\6IL-G_ca.paa";
		fza_shortCode 				= "6IL";
		model 						= "\fza_ah64_us\weps\fza_hydra_m261_wep";
		proxyShape 					= "\fza_ah64_us\fza_hydra_m261";
		CraterEffects 				= "ATMissileCrater";
		explosionEffects 			= "";	
		hit 						= 30;
		indirectHit 				= 0;
		indirectHitRange 			= 0;
		submunitionAmmo 			= "fza_m257_flare";
		submunitionCount 			= 1;
		submunitionConeAngle		= 0;
		triggerTime 				= 1.5;
		maxSpeed 					= 450;
		soundHit1[] 				= {"A3\sounds_f\dummysound",2.5118864,1,5};
		multiSoundHit[] 			= {"soundHit1",1};

		//AI uasge
		aiAmmoUsageFlags 			= "1";
		allowAgainstInfantry 		= 0;
	};
	class fza_275_m255: fza_275_base 
	{
		fza_wpnPageIconB 			= "\fza_ah64_us\tex\icons\6FL-B_ca.paa";
		fza_wpnPageIconG 			= "\fza_ah64_us\tex\icons\6FL-G_ca.paa";
		fza_shortCode 				= "6FL";
		model 						= "\fza_ah64_us\weps\fza_hydra_m261_wep";	
		proxyShape 					= "\fza_ah64_us\fza_hydra_m261";
		CraterEffects 				= "ATMissileCrater";
		explosionEffects 			= "";	
		maxSpeed 					= 600;
		hit 						= 30;
		indirectHit					= 0;
		indirectHitRange 			= 0;
		submunitionDirectionType	="SubmunitionModelDirection";
		submunitionAmmo 			= "fza_flec_cluster";
		submunitionConeType[] 		= {"randomcenter",100};
		submunitionConeAngle 		= 12;
		soundHit1[] 				= {"A3\sounds_f\dummysound",2.5118864,1,5};
		multiSoundHit[] 			= {"soundHit1",1};

		//AI uasge
		aiAmmoUsageFlags 			= "64";
		cost 						= 100;
	};
	
	///////////////////////////////////////////////////////////////////////
	//////////////////////////////SUBMUNITIONS/////////////////////////////
	///////////////////////////////////////////////////////////////////////	
	
	class fza_m73mpsm: GrenadeBase
	{
		soundsetexplosion[] 		= {"fza_small_explosion_soundset", "fza_he_explosion_stereo_soundset", "fza_small_explosion_reverb_soundset"};
		simulation 					= "shotShell";
		model 						= "\A3\weapons_f\ammo\UGL_slug"; //M73 model needed.
		explosionEffects 			= "ExploAmmoExplosion";
		CraterEffects 				= "ExploAmmoCrater";
		muzzleEffect 				= "BIS_fnc_effectFiredHeliRocket";
		hit 						= 30;
		indirectHit 				= 15;
		indirectHitRange 			= 20;
		visibleFire 				= 1;
		audibleFire 				= 30;
		visibleFireTime 			= 3;
		dangerRadiusHit 			= 60;
		suppressionRadiusHit		= 30;
		explosive 					= 1;
		deflecting 					= 0;
		airFriction 				= -0.001;
		fuseDistance 				= 30;
		whistleDist 				= 16;
		typicalSpeed 				= 300;
		caliber 					= 3.7;
		soundHit1[] = {"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_01",1.7782794,1,1600};
		soundHit2[] = {"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_02",1.7782794,1,1600};
		soundHit3[] = {"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_03",1.7782794,1,1600};
		soundHit4[] = {"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_04",1.7782794,1,1600};
		multiSoundHit[] = {"soundHit1",0.25,"soundHit2",0.25,"soundHit3",0.25,"soundHit4",0.25};
	};	
	class fza_m257_flare: FlareCore
	{		
		timeToLive 					= 100;
		model 						= "\A3\Weapons_F\Ammo\UGL_Flare";
		lightColor[] 				= {1,0.8,0.7,0.5};
		smokeColor[] 				= {1,1,1,0.4};
		effectFlare 				= "CounterMeasureFlare";
		brightness 					= 0.1;
		size 						= 3;
		triggerTime					= 0.25;
		triggerSpeedCoef 			= 1;
		audibleFire 				= 20;
		intensity 					= 1000000;
	};
	class fza_flec_cluster: B_9x21_Ball
	{
		hit 						= 6;
		indirectHit 				= 6;
		indirectHitRange 			= 4;
		deflecting 					= 0;
		fuseDistance 				= 50;
	};
};
	///////////////////////////////////////////////////////////////////////
	//////////////////////////////FLARES CM STYLE//////////////////////////
	///////////////////////////////////////////////////////////////////////	

class fza_cmflare
{
		class Cmeasures1
		{
			simulation = "particles";
			type = "Cmeasures1";
			position[] = {0,0,0};
			intensity = 1;
			interval = 1;
			lifeTime = 4.5;
			qualityLevel = 2;
		};
		class Cmeasures1M
		{
			simulation = "particles";
			type = "Cmeasures1M";
			position[] = {0,0,0};
			intensity = 1;
			interval = 1;
			lifeTime = 4.5;
			qualityLevel = 1;
		};
		class Cmeasures1L
		{
			simulation = "particles";
			type = "Cmeasures1L";
			position[] = {0,0,0};
			intensity = 1;
			interval = 1;
			lifeTime = 4.5;
			qualityLevel = 0;
		};
		class Cmeasures2
		{
			simulation = "particles";
			type = "Cmeasures2";
			position[] = {0,0,0};
			intensity = 1;
			interval = 1;
			lifeTime = 3.2;
		};
		class Light1
		{
			simulation = "light";
			type = "CmeasuresLight";
			position[] = {0,0,0};
			intensity = 1;
			interval = 1;
			lifeTime = 3;
		};
};
