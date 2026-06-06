#pragma once

enum
{
	PLAYER_INVALID = -1,
	PLAYER_MENU = 0,
	PLAYER_CUTSCENE = 1,
	PLAYER_INGAME = 2
};

enum CAMERA_MODE
{
	CAMERA_MODE_INVALID		 = -1,
	CAMERA_MODE_FLYMODE		 = 0,
	CAMERA_MODE_FIRST_PERSON = 1,
	CAMERA_MODE_THIRD_PERSON = 2
};

enum CT_WEAPON : int {
    CT_TRIPWIRE = 1,
    CT_GASOLINE = 2,
    CT_WATER = 3,
    CT_LIGHTER = 4,
    CT_CASH = 5,
    CT_TORCH = 6,
    CT_NVISION = 7,
    CT_PAINKILLERS = 8,
    CT_GFIRSTAID = 9,
    CT_YFIRSTAID = 10,
    CT_SPEEDBOOST = 11,
    CT_STRENGTHBOOS = 12,
    CT_SHOOTINGBOOS = 13,
    CT_REFLEXESBOOS = 14,
    CT_HEALTHBOOST = 15,
    CT_FISTS = 16,
    CT_KDUST = 17,
    CT_KNIFE = 18,
    CT_SHARD = 19,
    CT_BROKENBOTTLE = 20,
    CT_JURYBLADES = 21,
    CT_BOTTLE = 22,
    CT_PIPE = 23,
    CT_CLEAVER = 24,
    CT_WOODENBAR = 25,
    CT_CROWBAR = 26,
    CT_SICKLE = 27,
    CT_NIGHTSTICK = 28,
    CT_CANE = 29,
    CT_AXE = 30,
    CT_ICEPICK = 31,
    CT_MACHETE = 32,
    CT_SMALLBAT = 33,
    CT_BASEBALLBAT = 34,
    CT_WBASEBALLBAT = 35,
    CT_FIREAXE = 36,
    CT_HOCKEYSTICK = 37,
    CT_BASEBALLBATB = 38,
    CT_6SHOOTER = 39,
    CT_GLOCK = 40,
    CT_GLOCKSILENCE = 41,
    CT_GLOCKTORCH = 42,
    CT_UZI = 43,
    CT_SHOTGUN = 44,
    CT_SHOTGUNTORCH = 45,
    CT_DESERTEAGLE = 46,
    CT_COLTCOMMANDO = 47,
    CT_SNIPERRIFLE = 48,
    CT_SNIPERRIFLES = 48, // Ambos compartilham o ID 48
    CT_TRANQRIFLE = 49,
    CT_SAWNOFF = 50,
    CT_GRENADE = 51,
    CT_MOLOTOV = 52,
    CT_EXPMOLOTOV = 53,
    CT_TEARGAS = 54,
    CT_FLASH = 55,
    CT_BRICKHALF = 56,
    CT_FIREWORK = 57,
    CT_BAG = 58,
    CT_RAG = 59,
    CT_CHLORINE = 60,
    CT_METHS = 61,
    CT_HCC = 62,
    CT_DBEERGUY = 63,
    CT_DMERCLEADER = 64,
    CT_DSMILEY = 65,
    CT_DHUNTLORD = 66,
    CT_ELSIGHT = 67,
    CT_SSILENCER = 68,
    CT_RADIO = 69,
    CT_BARKEY = 70,
    CT_SYARDCOMB = 71,
    CT_CAMERA = 72,
    CT_BODYP1 = 73,
    CT_BODYP2 = 74,
    CT_PRECKEY = 75,
    CT_PRECCARD = 76,
    CT_PRECDOCS = 77,
    CT_PHARMHAND = 78,
    CT_ESTGKEY = 79,
    CT_ESTAKEY = 80,
    CT_DOLL = 81,
    CT_ANTIDOTE = 82,
    CT_KEY = 83,
    CT_CHAINSAW = 88,
    CT_NAILGUN = 89,
    CT_WIRE = 90,
    CT_CAN = 91,
    CT_WOODENSPIKE = 92,
    CT_PIGSYSHARD = 94,
    CT_PIGSYWIRE = 95,
    CT_PIGSYSPIKE = 96,
    CT_HAMMER = 97, // ID solicitado
    CT_DOLL1 = 98,
    CT_DOLL2 = 99,
    CT_DOLL3 = 100,
    CT_HEAD = 101,
    CT_AMMONAILS = 102,
    CT_AMMOSHOTGUN = 103,
    CT_AMMOPISTOL = 104,
    CT_AMMOMGUN = 105,
    CT_AMMOTRANQ = 106,
    CT_AMMOSNIPER = 107,
    CT_CHAINSAWPLAY = 108,
    CT_DVTAPE = 109,
    CT_HANDYCAM = 110,
    CT_UNRECOGNISEDCO = 111
};


namespace Manhunt {
	namespace Debug {
        typedef void(__stdcall* ShowCredits_t)();
        static ShowCredits_t ShowCredits =
            (ShowCredits_t)0x5EE5F0;

        typedef void(__stdcall* ToggleGodMode_t)();
        static ToggleGodMode_t ToggleGodMode =
            (ToggleGodMode_t)0x5EE4F0;

        typedef void(__stdcall* KillHunters_t)();
        static KillHunters_t KillHunters =
            (KillHunters_t)0x5EE7C0;

        typedef void(__stdcall* ToggleHunterEn_t)();
        static ToggleHunterEn_t ToggleHunterEn =
            (ToggleHunterEn_t)0x5EE580;

        typedef void(__stdcall* ResetGameState_t)();
        static ResetGameState_t ResetGameState =
            (ResetGameState_t)0x5D2010;

        typedef void(__stdcall* CompleteLevel_t)();
        static CompleteLevel_t CompleteLevel =
            (CompleteLevel_t)0x5D1F00;

        typedef void(__stdcall* GiveAllStars_t)();
        static GiveAllStars_t GiveAllStars =
            (GiveAllStars_t)0x5D6CC0;

        typedef void(__stdcall* OpenNormalLevels_t)();
        static OpenNormalLevels_t OpenNormalLevels =
            (OpenNormalLevels_t)0x5D6CB0;

        //

        void ToggleScreenCalibLines(bool state);
        int GetScreenCalibLines();

        void ToggleScreenCalibLines(bool state);
        int GetScreenCalibLines();

        void ToggleTexCacheFix(bool state);
        int GetTexCacheFix();

        void ToggleZClearOnly(bool state);
        int GetZClearOnly();

        void ToggleFxMode(bool state);
        int GetFxMode();

        void ToggleFxModeAA(bool state);
        int GetFxModeAA();

        void ToggleFxArtFilter(bool state);
        int GetFxArtFilter();

        void ToggleFxDrug(bool state);
        int GetFxDrug();

        void ToggleSlowMotion(bool state);
        int GetSlowMotion();

        void ToggleDisableHunters(bool state);
        int GetDisableHunters();

        void ToggleInventoryInfo(bool state);
        int GetInventoryInfo();
	}

	namespace Visual {
		void GameText(const char* text);

        typedef void(__stdcall* tGameTextLeft)(int line, const char* text);
        static tGameTextLeft GameTextLeft =
            (tGameTextLeft)0x5E5480;
	}

    namespace Weapons {
		int GetCurrentWeapon();

        // sub_4C67F0 - getitemname?
    }


	int PlayerState();
	void KillPlayer();
	void TogglePlayerGodMode();

    void ToggleHUD(bool state);
    void ToggleSlowMotion(bool state);
    void DisableHunters(bool state);

	void ToggleMemInfo(bool state);
	void ToggleFPS(bool state);
	
	void SetPlayerCameraMode(CAMERA_MODE mode);
	CAMERA_MODE GetPlayerCameraMode();
}