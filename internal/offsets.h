#include "canvas_gui.h"
#include "unrealengine.h"
#pragma once

namespace menusize {
	float xsize = 595.0f, ysize = 400.0f;
}

FVector2D menu_size = FVector2D{ 620, 450 };

namespace Globals {
	bool handChamsRGB = false;
	bool handchams = false;
	bool crosshairrainbow = false;
	bool riotid = false;
	bool selfchams = false;
	bool gunmaterial = false;
	bool CoolFov = false;
	bool ShowCheatOptions = false;
	bool InvisibleEnemy = false;
	bool glowenemy = false;
	bool SpinBot = false;
	bool outline = false;
	bool NoSmoke = false;
	bool FireSilent = false;
	bool Mesh3PModifed = false;
	bool dynamicrecoil = false;
	bool GadgetESP = false;
	bool player_view_angle = false;
	bool autoknife = false;
	bool CrossBool = true;
	int spinbotkey;
	bool Itsgamerdoc = false;
	bool menucheck = true;
	bool WeaponChams = false;
	bool InvisibleWeapon = false;
	bool WireframePlayer = false;
	float glowenemyfloat = 10.0f;
	bool AgentName = false;
	bool AgentIcon = false;
	bool Aimlock = false;
	bool bigweapon = false;
	bool ClientSideSpinbot = false;
	bool InivisiblePlayer = false;
	bool ChamsPlayer = false;
	bool tpbool = false;
	bool spinbot = false;
	float spinbot_speed = 100;
	float third_person_float = 100;
	float view = 1;
	bool bigplayer = false;
	bool UnlockAll = false;
	bool Thirdperson = false;
	float TPDistance = 300;
	bool HandGlow = false;
	bool TeamCheck = false;
	bool BuddyChanger = false;
	bool Buddytext = true;
	bool DistangeEsp = false;
	bool invisiblehands = false;
	bool EnableESP = true;
	bool RecoilCrosshair = false;
	bool BunnyHop = false;
	bool Box = false;
	bool Box2D = false;
	bool Silent = false;
	bool AntiAFK = false;
	bool HeadESP = false;
	bool BottomSnapline = false;
	bool WeaponEsp = false;
	bool HealthText = false;
	bool EnableSkin = false;
	bool EnableSkin2 = false;
	bool EnableSkinBool = false;
	bool SpikeEsp = false;
	bool Snapline = false;
	bool skill_esp = false;
	bool dropped_gun = false;
	bool Menu_Open = true;
	bool kekIsOff = 0;
	bool Shieldbar = false;
	bool CorneredBox = false;
	bool Healthbar = false;
	bool Box3D = false;
	bool ChamsESP = false;
	bool custom_fresnel = false;
	bool rainbow_fresnel = false;
	bool rainbow_chams = false;
	bool visibleCheckChams = false;
	bool ChamsESP_not = true;
	bool ChamsESP2 = true;
	bool NoSpreadAimbot = false;
	bool NoSpreadAimbot_not = false;
	bool EnableAim = true;
	bool VisibleCheck = true;
	bool AutoShoot = false;
	bool FastCrouch = false;
	bool FovChangerBool = false;
	bool Always = false;
	bool Behind = true;
	bool DrawFov = false;
	bool HealthEsp = false;
	bool SkipTutorial = false;
	bool ViewModelChanger = false;
	bool championssheriff = false;
	bool Minimap = false;
	bool weaponesp = false;
	bool Watermark = true;
	bool streammode = false;
	bool Visible_Check_ESP = false;
	bool SkeletonEsp = false;
	bool WireFrameWeapon = false;
	bool null = false;
	bool big_gun = false;
	bool WireFrameHand = false;
	bool RecoilControl = false;
	int LegitBotKey;
	int MenuKey = VK_INSERT;
	int LegitBotKey2;
	int SecondKey;
	int SkinChangerKey;
	int ApplySkinKey;
	int Width = GetSystemMetrics(SM_CXSCREEN);
	int Height = GetSystemMetrics(SM_CYSCREEN);
	int AimBone = 0;
	int WatermarkType = 0;
	int tpkey;
	int SelectSnapline = 1;
	static float FovChangerValue = 105.0f;
	static float LegitFOvValue = 30.0f;
	float Glow = 2.0f;
	float skeleton_size = 1.7f;
	float biggunvalue = 1.0f;
	float bigplayervalue = 1.0f;
	float ColorGlow = 4.0f;
	float ESPThickness = 1.1f;
	float FovCircle = 200.0f;
	float PlayerDistange = 400.0f;
	float ScreenCenterX = static_cast<float>(Width) / 2.0f;
	float ScreenCenterY = static_cast<float>(Height) / 2.0f;
	float smooth = 1.0f;

	//Skin Value
	int SkinKnife = 0;
	int SkinVandal = 0;
	int SkinSheriff = 0;
	int SkinSheriff2 = 0;
	int SkinOperator = 0;
	int SkinSpectre = 0;
	int SkinPhantom = 0;
	int SkinBulldog = 0;
	int SkinFrenzy = 0;
	int SkinGuardian = 0;
	int SkinGhost = 0;
	int SkinClassic = 0;


	static bool t = true;

	float spinMULTIX = 3;
	static float spinY = 10;
	static float spinX = 10;
	static float spinMULTIY = 10.f;
	static float spinMULTIZ = 10.f;
	float Pitch = 0;
	float Roll = 0;
}
namespace f {

	FVector	LocalCameraRotation;
	FVector	LocalCameraRotation2;
	FVector	CurrentTargetAimAngle;
	FVector	LocalCameraLocation;

	static bool bLockedCameraRotation = false;
	static bool bLockedCameraRotation_2 = false;
	static bool bFlickSilent = true;
	float LocalCameraFOV;
	float PreviousRotationX = 0.0f;
	float PreviousRotationY = 0.0f;
	int bone = 0;

	float OldLocalCameraFOV;
	FVector OldCameraPos;
	FVector OldCameraRot;
}
namespace Silent_f {

	FVector	LocalCameraRotation;
	FVector	LocalCameraRotation2;
	FVector	CurrentTargetAimAngle;
	FVector	LocalCameraLocation;

	static bool bLockedCameraRotation = false;
	static bool bLockedCameraRotation_2 = false;

	static bool bFlickSilent = true;
	float LocalCameraFOV;
	FVector OldCameraPos = f::LocalCameraLocation;
	FVector OldCameraRot = f::LocalCameraRotation;
	float PreviousRotationX = 0.0f;
	float PreviousRotationY = 0.0f;
	int bone = 0;
}
namespace Colors {
	FLinearColor ChamsColor{ 2.093f, 0.019f, 20.0f, 2.6f };
	FLinearColor WeaponColor{ 2.093f, 0.019f, 20.0f, 1.0f };
	FLinearColor FovColor = { 255.0f, 255.0f, 255.0f, 0.1f };
	FLinearColor CrosshairColor = { 1.0f, 1.0f, 1.0f, 1.0f };

	FLinearColor BoxVisible = { 1,1,1,1 };
	FLinearColor Boxinvisible = { 1,0,0,1 };
	FLinearColor ChamsVisible = { 1,0,0,1 };
	FLinearColor ChamsInvisible = { 1,0,0,1 };
	FLinearColor LineVisible = { 1,0,0,1 };
	FLinearColor LineINvisible = { 1,1,1,1 };

	FLinearColor SkeletonVisible = { 1,1,1,1 };
	FLinearColor SkeletonInvisible = { 1,0,0,1 };

	FLinearColor WeaponNameColor = { 25,25,25,2.5f };
	FLinearColor AgentNameColor = { 25,25,25,2.5f };
	FLinearColor PlayerColor{ 2.093f, 0.019f, 20.0f, 1.0f };
	FLinearColor ChamsColor1;
	FLinearColor BoxColor;
	FLinearColor Skeleton;
	FLinearColor LineColor;
}
constexpr uint64_t camerapos = 0x11e0;
constexpr uint64_t camerafov = 0x11d0;
constexpr uint64_t camerarot = 0x11ec;

namespace Offsets {
	constexpr uint64_t State = 0x9FA80D0; // o_gworld
	constexpr uint64_t PlayerState = 0x480;
	constexpr uint64_t PlatformPlayer = 0x688;
	constexpr uint64_t RiotName = 0x3d8;
	constexpr uint64_t RelativeScale3D = 0x17c;
	constexpr uint64_t WireFrame = 0x71E;
	constexpr uint64_t WireFrame2 = 0xC0;
	constexpr uint64_t WireFrame3 = 0xff;
	constexpr uint64_t Inventory = 0xC08;
	constexpr uint64_t fmemory_malloc = 0x48151F0; // o_fmemory_malloc
	constexpr uint64_t Equippable = 0x248;

	std::uintptr_t process_event = 0x4B898D0; // o_process_event
	std::uintptr_t static_find_object = 0x4B9E050; // o_find_object
	std::uintptr_t static_load_object = 0x4B9EE90; // o_load_object
	std::uint64_t MagicOffsets = 0x46C4660; // inchanger
	std::uintptr_t play_finisher_effect = 0x33E60B0; // o_play_finisher_effect
	std::uintptr_t set_ares_outline = 0x6608820; // o_set_ares_outline_mode
	std::uintptr_t bone_matrix = 0x6660D60; // o_bone_matrix
	constexpr uint64_t Mesh3pGun = 0xDE8;

	std::uintptr_t get_spread_values = 0x3498C30; // o_get_spread_values
	std::uintptr_t get_spread_angles = 0x3F73A50; // o_get_spread_angles
	std::uintptr_t get_firing_location_direction = 0x3BF2000; // o_get_firing_location
	std::uintptr_t tovector_and_normalize = 0x48962B0; // o_to_vector_and_normalize
	std::uintptr_t toangle_and_normalize = 0x4892860; // o_to_angle_and_normalize

	std::uintptr_t firing_state_component = 0x1070;
	std::uintptr_t seed_data = 0x4B0;
	std::uintptr_t stability_component = 0x4A0;

	std::uintptr_t error_power = 0x49c;
	std::uintptr_t error_retries = 0x480;

	std::uintptr_t OwningGameInstance = 0x1D8;

	std::uintptr_t bone_cout = 0x5d0; // o_bone_count // verify manually - not in SDK
	std::uintptr_t real_time_dormant = 0x101;

	std::uintptr_t mesh3p_mids = 0xF80;

	std::uintptr_t mesh1p = 0xF30;
	std::uintptr_t mesh1p_overlay = 0xF38;
	std::uintptr_t Mesh3P = 0xDE8;
	std::uintptr_t mesh_cosmetic_3p = 0xF40;
	std::uintptr_t thirdpersoncosmetic = 0xc88;

	std::uintptr_t InventoryIcon = 0xF30;
	std::uintptr_t wireframe_num = 0x71E;
	std::uintptr_t wireframe_num_1 = 0xC0;

	std::uintptr_t skin_data_assets = 0xFB0;
	std::uintptr_t skin_pointer = 0x360; // o_skin_changer_1
	std::uintptr_t skin_pointer_2 = 0xB0; // o_skin_changer_2
	std::uintptr_t skin_pointer_3 = 0x80; // o_skin_changer_3

	std::uintptr_t defuse_percentage = 0x4e8;
	std::uintptr_t bomb_time_remaining = 0x4cc;
	std::uintptr_t viewport_world = 0x78;

	std::uintptr_t uworld_pointer = 0x80;
	std::uintptr_t draw_transition = 0x68;
}