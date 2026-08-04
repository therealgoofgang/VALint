#include "windows.h"
#include <stdint.h>
#include <iostream>
#include <Winternl.h>
#include "canvas_gui.h"
#include "decryption.h"
#include "hook.h"
#include "Decryptor.h"
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "skinchanging.h"
#include <stdio.h>
#include "Hookign/spoofer.h"
#include "options.hpp"
#include "config.hpp"
float TPDistance = 500; // Third Person Distance
#include "offsets.h"
#pragma comment(lib, "user32.lib")
#include "json.hpp"
#include <cmath>
using json = nlohmann::json;
float time_ = 0.0f;

static float X = 610, Y = 390.0f;
APawn* MyPawn;
USkeletalMeshComponent* mesh3p;
AShooterCharacter* MyShooter;
APlayerController* MyController;
AShooterCharacter* Char;
AShooterCharacter* Actor;
USkeletalMeshComponent* Mesh;
APawn* ThirdPersonMesh;
using PostRenderHook = void(*)(uintptr_t _this, UCanvas* canvas, std::uintptr_t a3);
PostRenderHook pRender = 0;
FVector2D head_screen;

auto enc = (L"Fresnel Enemy Tint");
auto enc2 = (L"Fresnel Ally Tint");

int Width = GetSystemMetrics(SM_CXSCREEN);
int Height = GetSystemMetrics(SM_CYSCREEN);

float ScreenCenterX = static_cast<float>(Width) / 2.0f;
float ScreenCenterY = static_cast<float>(Height) / 2.0f;
class ConfigSystem {
public:
    static void Save(const std::string& file);
    static void Load(const std::string& file);
};
#include "Config.hpp"



bool Dormant(AShooterCharacter* Actor) {
    SPOOF_FUNC;
	return Memory::R<bool>(reinterpret_cast<uintptr_t>(Actor) + Offsets::real_time_dormant);
}

bool DormantServer(AShooterCharacter* Actor) {
    SPOOF_FUNC;
	return Memory::R<bool>(reinterpret_cast<uintptr_t>(Actor) + 0x100);
}
namespace spin_tool {
    static float Pitch = 50;
    static float Roll = 50;
    static auto OldAimAngles = FVector();
    static float spinX = 20;

    static float spinMULTIX = -2;
    static float spinMULTIY = 10.f;
    static float spinMULTIZ = 10.f;

    static bool one = true;
}
namespace bones {
	FVector2D vHipOut; FVector2D vNeckOut;
	FVector2D vUpperArmLeftOut; FVector2D vLeftHandOut;
	FVector2D vLeftHandOut1; FVector2D vUpperArmRightOut;
	FVector2D vRightHandOut; FVector2D vRightHandOut1;
	FVector2D vLeftThighOut; FVector2D vLeftCalfOut;
	FVector2D vLeftFootOut; FVector2D vRightThighOut;
	FVector2D vRightCalfOut; FVector2D vRightFootOut;
}

static bool one;
static bool firstTime2 = true;
static bool firstTime3 = true;
static FVector OldAimAngles2 = FVector();

static bool lock_screen = false;
static FVector OldAimAngles3 = FVector();
static FVector nigga = FVector();
static bool bLockedCameraRotation = false;

float LocalCameraFOV;
FVector    LocalCameraLocation;
FVector    LocalCameraRotation;
void(*SetCameraCachePOVOriginal)(uintptr_t, FMinimalViewInfo*) = nullptr;

void disable_input_keys(APlayerController* MyController)
{
    SPOOF_FUNC;
	/* KeyEvent(0x41, false);
	 KeyEvent(0x44, false);
	 KeyEvent(0x57, false);
	 KeyEvent(0x53, false);
	 KeyEvent(0x20, false);*/

	MyController->simulate_input_key(keys::w, false);
	MyController->simulate_input_key(keys::A, false);
	MyController->simulate_input_key(keys::s, false);
	MyController->simulate_input_key(keys::d, false);
	MyController->simulate_input_key(keys::space, false);
}

FLinearColor fresnel = FLinearColor(0.5f, 0.0f, 0.5f, 1.0f);       // Violet
FLinearColor fresnel_team = FLinearColor(0.5f, 0.0f, 0.5f, 1.0f);  // Violet



void A1M() {
    SPOOF_FUNC;
    elements_count = 0;
    menu::offset_x = 15 + 130 + 13;
    menu::offset_y = 47 + 16;

    menu::SectionWrapper(ez(L"Main").d(), FVector2D(260, 475));
    menu::Checkbox(ez(L"Enable aimbot").d(), &Globals::EnableAim);
    menu::Checkbox(ez(L"Enable Silent Aimbot").d(), &Globals::Silent);
    menu::Checkbox(ez(L"Recoil control").d(), &Globals::RecoilControl);
    menu::Checkbox(ez(L"Vishcheck").d(), &Globals::VisibleCheck);
    menu::SliderFloat(ez(L"FOV Size").d(), &Globals::LegitFOvValue, 1, 1500);
    menu::Text(ez(L"").d());
    menu::SliderFloat(ez(L"Smooth").d(), &Globals::smooth, 1, 40);
    menu::offset_y += 20;
    menu::Combobox(ez(L"Bone").d(), { 95, 27 }, &Globals::AimBone, L"Head", L"Chest", L"Leg", NULL);
    menu::offset_x = 15 + 130 + 13 + 260 + 10;
    menu::offset_y = 47 + 16;
    menu::SectionWrapper(L"Other", FVector2D(260, 475));
    menu::Checkbox(ez(L"Recoil crosshair").d(), &Globals::RecoilCrosshair);
    menu::Checkbox(ez(L"Draw fov").d(), &Globals::DrawFov);
    menu::Checkbox(ez(L"Draw RGB fov").d(), &Globals::CoolFov);
   // menu::Checkbox(ez(L"No Spread ( updating )").d(), &Globals::NoSpreadAimbot);
    menu::Hotkey("Aimkey1", FVector2D(83, 28.0f), &Globals::LegitBotKey);
   // menu::Hotkey("Aimkey2", FVector2D(83, 28.0f), &Globals::SecondKey);
   
}

void E3P() {
 
    SPOOF_FUNC;
    menu::offset_x = 15 + 130 + 13;
    menu::offset_y = 47 + 16;

        menu::SectionWrapper(L"Main", FVector2D(260, 475));
        menu::Checkbox(ez(L"D1stange").d(), &Globals::DistangeEsp);
        menu::Checkbox(ez(L"Snapl1ne").d(), &Globals::Snapline);
        menu::Checkbox(ez(L"2D b0x").d(), &Globals::Box2D);
        menu::Checkbox(ez(L"3D b0x").d(), &Globals::Box3D);
        menu::Checkbox(ez(L"C0rner box").d(), &Globals::CorneredBox);
        menu::Checkbox(ez(L"Dr0pped gun").d(), &Globals::dropped_gun);
        menu::Checkbox(ez(L"Ske1eton").d(), &Globals::SkeletonEsp);
        menu::Checkbox(ez(L"Hea1thbar").d(), &Globals::Healthbar);
        menu::Checkbox(ez(L"Hea1thbar T4xt").d(), &Globals::HealthText);
        menu::Checkbox(ez(L"Tr4ps & sk1ll n4me").d(), &Globals::skill_esp);
        menu::Checkbox(ez(L"Head Circle").d(), &Globals::HeadESP);
        menu::Checkbox(ez(L"Sp1ke inf0").d(), &Globals::SpikeEsp);
        menu::Checkbox(ez(L"Weap0n n4me").d(), &Globals::WeaponEsp);
        menu::Checkbox(ez(L"Ag3nt n4me").d(), &Globals::AgentName);
        menu::Checkbox(ez(L"R10t n4me").d(), &Globals::riotid);
        
        menu::offset_x = 15 + 130 + 13 + 260 + 10;
        menu::offset_y = 47 + 16;
        menu::SectionWrapper(L"Others", FVector2D(260, 475));   
        menu::ColorPicker(ez(L"Fov color").d(), &Colors::FovColor);
        menu::ColorPicker(ez(L"Box visible color").d(), &Colors::BoxVisible);
        menu::ColorPicker(ez(L"Line visible color").d(), &Colors::LineVisible);
        menu::ColorPicker(ez(L"Skeleton visible color").d(), &Colors::SkeletonVisible);
        menu::ColorPicker(ez(L"Weapon color").d(), &Colors::WeaponNameColor);
        menu::ColorPicker(ez(L"Agent color").d(), &Colors::AgentNameColor);
        menu::ColorPicker(ez(L"Box invisible color").d(), &Colors::Boxinvisible);
        menu::ColorPicker(ez(L"Line invisible color").d(), &Colors::LineINvisible);
        menu::ColorPicker(ez(L"Skeleton invisible color").d(), &Colors::SkeletonInvisible);
        menu::Combobox((L""), { 95, 27 }, &Globals::SelectSnapline, L"bottom", L"middle", L"top", NULL);
    
}

void W4ALL() {
    menu::offset_x = 15 + 130 + 13;
    menu::offset_y = 47 + 16;
    SPOOF_FUNC;
    menu::SectionWrapper(L"Main", FVector2D(260, 475));
   // menu::Checkbox((L"Self Chams"), &Globals::ChamsPlayer);
    menu::Checkbox(ez(L"Chams").d(), &Globals::ChamsESP);
    if (Globals::ChamsESP) {
        menu::Checkbox(ez(L"add color").d(), &Globals::outline);
        if (Globals::outline) {
            menu::Checkbox(ez(L"Rainbow Chams").d(), &Globals::rainbow_chams);
            menu::ColorPicker(ez(L"rgb color").d(), &Colors::ChamsColor);
            menu::SliderFloat(ez(L"Brightness").d(), &Globals::glowenemyfloat, 1, 40);
           // menu::Checkbox((L"Visible Check Chams"), &Globals::visibleCheckChams);
        }
         
    }
    menu::offset_x = 15 + 130 + 13 + 260 + 10;
    menu::offset_y = 47 + 16;
    menu::SectionWrapper(L"Other", FVector2D(260, 475));
   // menu::Checkbox(ez(L"wireframe hand").d(), &Globals::WireFrameHand);
   // menu::Checkbox(ez(L"wireframe weapon").d(), &Globals::WireFrameWeapon);
   // menu::Checkbox(ez(L"Hand Material").d(), &Globals::HandGlow);
    if (Globals::HandGlow)
    {
        //   menu::Combobox(ez(L"Color").d(), { 95, 27 }, &g_Options.material, L"Black", L"Reyna Ult", L"Green", L"Glass",L"Pink", L"Yellow", L"Red", L"Blue", L"Random", NULL);
    }

   // menu::Checkbox((L"Self Material"), &Globals::ChamsPlayer);
  //  menu::Checkbox(ez(L"Custom fresnel").d(), &Globals::custom_fresnel);
    //menu::Checkbox((L"Rainbow fresnel"), &Globals::rainbow_fresnel);
  //  menu::ColorPicker_Fresnel(ez(L"fresnel enemy color").d(), &fresnel);
}

void Misc() {
    menu::offset_x = 15 + 130 + 13;
    menu::offset_y = 47 + 16;

    SPOOF_FUNC;

     std::filesystem::path path = std::getenv("USERPROFILE");
     path /= ("Documents\\Inernal.json");
        menu::SectionWrapper(L"Main", FVector2D(260, 475));
        menu::Checkbox(ez(L"bunny hop").d(), &Globals::BunnyHop);
        menu::Checkbox(ez(L"anti afk").d(), &Globals::AntiAFK);
        menu::Checkbox(ez(L"Draw RGB Crosshair").d(), &Globals::crosshairrainbow);
        menu::Checkbox(ez(L"Watermark").d(), &Globals::Watermark);
        //menu::Checkbox((L"team check"), &Globals::TeamCheck);   
        menu::Hotkey("Men4 Keybind", FVector2D(83, 28.0f), &Globals::MenuKey);
        menu::offset_x = 15 + 130 + 13 + 260 + 10;
        menu::offset_y = 47 + 16;
        menu::SectionWrapper(L"Other", FVector2D(260, 475));
        
        
        if (menu::Button(ez(L"Save Config").d(), FVector2D{ 83, 30 }))
        {
         

            ConfigSystem::Save(path.string().c_str());
        }

        menu::SameLine();

        if (menu::Button(ez(L"Load Config").d(), FVector2D{ 83, 30 }))
        {
            ConfigSystem::Load(path.string().c_str());
        }
       
  
   
}
void Exploits()
{
    menu::offset_x = 15 + 130 + 13;
    menu::offset_y = 47 + 16;
    menu::SectionWrapper(L"Main", FVector2D(260, 475));
    menu::Checkbox(ez(L"skip tutorial( in-game )").d(), &Globals::SkipTutorial);
    menu::Checkbox(ez(L"View Model Changer").d(), &Globals::ViewModelChanger);
    menu::Checkbox(ez(L"Thirdperson").d(), &Globals::Thirdperson);
    menu::Checkbox(ez(L"Serversided Spinbot").d(), &Globals::SpinBot);
    menu::Checkbox(ez(L"champions sheriff").d(), &Globals::championssheriff);
    menu::Checkbox(ez(L"Big Weapon 1P").d(), &Globals::big_gun);
    menu::Checkbox(ez(L"Big Weapon 3P").d(), &Globals::bigweapon);
    menu::Checkbox(ez(L"Fast Crouch").d(), &Globals::FastCrouch);
    menu::offset_x = 15 + 130 + 13 + 260 + 10;
    menu::offset_y = 47 + 16;
    menu::SectionWrapper(L"Adjust", FVector2D(260, 475));
    if (Globals::big_gun || Globals::bigweapon) {
        menu::SliderFloat(ez(L"Size").d(), &Globals::biggunvalue, 0, 170);
    }
    menu::Text((L""));
    menu::SliderFloat(ez(L"Fov Slider").d(), &Globals::FovChangerValue, 0, 170);
    menu::Text((L""));
    if (menu::Button(ez(L"apply").d(), FVector2D{ 95, 28 })) {
        Globals::FovChangerBool = true;
    }
    menu::SameLine();
    if (menu::Button(ez(L"reset").d(), FVector2D{ 95, 28 })) {
        Globals::FovChangerValue = 105.0f; Globals::FovChangerBool = true;
    }
    menu::SliderFloat(ez(L"Spinbot Speed").d(), &Globals::spinbot_speed, 0, 300);
    menu::Text((L""));
    menu::SliderFloat(ez(L"Thirdperson Dis").d(), &Globals::third_person_float, 0, 500);
    menu::Text((L""));
    if (Globals::ViewModelChanger)
    {
        menu::SliderFloat(ez(L"ViewModel Slider").d(), &Globals::view, 0, 7);
    }
 }
void SK1NCH4NG3R() {
    menu::offset_x = 15 + 130 + 13;
    menu::offset_y = 47 + 16;
    SPOOF_FUNC;
    menu::SectionWrapper(L"One", FVector2D(260, 475));
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Vandal", FVector2D(234, 25), &vandalSkinOption, vandalSkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Phantom", FVector2D(234, 25), &phantomSkinOption, phantomSkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Operator", FVector2D(234, 25), &operatorSkinOption, operatorSkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Bulldog", FVector2D(234, 25), &bulldogSkinOption, bulldogSkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Frenzy", FVector2D(234, 25), &frenzySkinOption, frenzySkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Guardian", FVector2D(234, 25), &guardianSkinOption, guardianSkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Sheriff", FVector2D(234, 25), &sheriffSkinOption, sheriffSkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Ghost", FVector2D(234, 25), &ghostSkinOption, ghostSkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Spectre", FVector2D(234, 25), &spectreSkinOption, spectreSkins);

    menu::offset_x = 15 + 130 + 13 + 260 + 10;
    menu::offset_y = 47 + 16;
    menu::SectionWrapper(L"Second", FVector2D(260, 475));
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Classic", FVector2D(234, 25), &classicSkinOption, classicSkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Marshal", FVector2D(234, 25), &marshalSkinOption, marshalSkins);
    menu::offset_y -= 6;
    menu::ShowSkinCombobox(L"Knife", FVector2D(234, 25), &knifeSkinOption, knifeskins);
    menu::offset_y -= 6;
    menu::Checkbox(ez(L"Buddy Changer").d(), &Globals::BuddyChanger);
    if (Globals::BuddyChanger)
    {
        menu::SliderInt(ez(L"Buddy Slider").d(), &index, 1, 650);
        menu::Text((L""));
        if (menu::Button((L"<"), FVector2D{ 30, 30 }))
        {
            index--;
        }

        menu::SameLine();

        if (menu::Button((L">"), FVector2D{ 30, 30 }))
        {
            index++;
        }

        
        menu::Checkbox(ez(L"Buddy Text").d(), &Globals::Buddytext);
        menu::Text((L""));
    }
  

    menu::Text(ez(L"Press Delete Key To Apply Skins").d());
    menu::Text(ez(L"And Buddies").d());
}

void ConfigSystem::Save(const std::string& file) {
    json j;

    // Aimbot settings
    j["aimbot"]["EnableAim"] = Globals::EnableAim;
    j["aimbot"]["Silent"] = Globals::Silent;
    j["aimbot"]["RecoilControl"] = Globals::RecoilControl;
    j["aimbot"]["VisibleCheck"] = Globals::VisibleCheck;
    j["aimbot"]["FOV"] = Globals::LegitFOvValue;
    j["aimbot"]["Smooth"] = Globals::smooth;
    j["aimbot"]["AimBone"] = Globals::AimBone;
    j["aimbot"]["RecoilCrosshair"] = Globals::RecoilCrosshair;
    j["aimbot"]["DrawFov"] = Globals::DrawFov;
    j["aimbot"]["CoolFov"] = Globals::CoolFov;
    j["aimbot"]["NoSpread"] = Globals::NoSpreadAimbot;
    j["aimbot"]["Aimlock"] = Globals::Aimlock;
    j["aimbot"]["LegitBotKey"] = Globals::LegitBotKey;
    j["aimbot"]["SecondKey"] = Globals::SecondKey;

    // ESP settings
    j["esp"]["DistangeEsp"] = Globals::DistangeEsp;
    j["esp"]["Snapline"] = Globals::Snapline;
    j["esp"]["Box2D"] = Globals::Box2D;
    j["esp"]["Box3D"] = Globals::Box3D;
    j["esp"]["CorneredBox"] = Globals::CorneredBox;
    j["esp"]["dropped_gun"] = Globals::dropped_gun;
    j["esp"]["SkeletonEsp"] = Globals::SkeletonEsp;
    j["esp"]["Healthbar"] = Globals::Healthbar;
    j["esp"]["HealthText"] = Globals::HealthText;
    j["esp"]["skill_esp"] = Globals::skill_esp;
    j["esp"]["HeadESP"] = Globals::HeadESP;
    j["esp"]["SpikeEsp"] = Globals::SpikeEsp;
    j["esp"]["WeaponEsp"] = Globals::WeaponEsp;
    j["esp"]["AgentName"] = Globals::AgentName;
    j["esp"]["SelectSnapline"] = Globals::SelectSnapline;

    // Chams settings
    j["chams"]["ChamsESP"] = Globals::ChamsESP;
    j["chams"]["outline"] = Globals::outline;
    j["chams"]["rainbow_chams"] = Globals::rainbow_chams;
    j["chams"]["glowenemyfloat"] = Globals::glowenemyfloat;

    // Misc settings
    j["misc"]["WireFrameHand"] = Globals::WireFrameHand;
    j["misc"]["WireFrameWeapon"] = Globals::WireFrameWeapon;
    j["misc"]["HandGlow"] = Globals::HandGlow;
    j["misc"]["custom_fresnel"] = Globals::custom_fresnel;
    j["misc"]["BunnyHop"] = Globals::BunnyHop;
    j["misc"]["AntiAFK"] = Globals::AntiAFK;
    j["misc"]["Watermark"] = Globals::Watermark;
    j["misc"]["TeamCheck"] = Globals::TeamCheck;
    j["misc"]["MenuKey"] = Globals::MenuKey;

    // Skins settings
    j["skin"]["Vandal"] = vandalSkinOption;
    j["skin"]["Phantom"] = phantomSkinOption;
    j["skin"]["Operator"] = operatorSkinOption;
    j["skin"]["Bulldog"] = bulldogSkinOption;
    j["skin"]["Frenzy"] = frenzySkinOption;
    j["skin"]["Guardian"] = guardianSkinOption;
    j["skin"]["Sheriff"] = sheriffSkinOption;
    j["skin"]["Ghost"] = ghostSkinOption;
    j["skin"]["Spectre"] = spectreSkinOption;
    j["skin"]["Classic"] = classicSkinOption;
    j["skin"]["Marshal"] = marshalSkinOption;
    j["skin"]["Knife"] = knifeSkinOption;
    j["skin"]["BuddyChanger"] = Globals::BuddyChanger;
    j["skin"]["BuddyText"] = Globals::Buddytext;
    j["skin"]["Buddy"] = index;
    // Exploits settings
    j["exploits"]["SkipTutorial"] = Globals::SkipTutorial;
    j["exploits"]["Thirdperson"] = Globals::Thirdperson;
    j["exploits"]["SpinBot"] = Globals::SpinBot;
    j["exploits"]["championssheriff"] = Globals::championssheriff;
    j["exploits"]["big_gun"] = Globals::big_gun;
    j["exploits"]["bigweapon"] = Globals::bigweapon;
    j["exploits"]["biggunvalue"] = Globals::biggunvalue;
    j["exploits"]["FovChangerValue"] = Globals::FovChangerValue;
    j["exploits"]["spinbot_speed"] = Globals::spinbot_speed;
    j["exploits"]["third_person_float"] = Globals::third_person_float;

    // Save to file
    std::ofstream out(file);
    out << j.dump(4);
}

void ConfigSystem::Load(const std::string& file) {
    std::ifstream in(file);
    if (!in.is_open()) return;

    json j;
    in >> j;

    auto safe = [&](const json& j, const std::string& key, auto def) -> decltype(def) {
        if (j.contains(key) && !j[key].is_null()) {
            return j[key].get<decltype(def)>();
        }
        return def;
        };

    Globals::EnableAim = safe(j["aimbot"], "EnableAim", false);
    Globals::Silent = safe(j["aimbot"], "Silent", false);
    Globals::RecoilControl = safe(j["aimbot"], "RecoilControl", false);
    Globals::VisibleCheck = safe(j["aimbot"], "VisibleCheck", false);
    Globals::LegitFOvValue = safe(j["aimbot"], "FOV", 90.0f);
    Globals::smooth = safe(j["aimbot"], "Smooth", 1.0f);
    Globals::AimBone = safe(j["aimbot"], "AimBone", 0);
    Globals::RecoilCrosshair = safe(j["aimbot"], "RecoilCrosshair", false);
    Globals::DrawFov = safe(j["aimbot"], "DrawFov", false);
    Globals::CoolFov = safe(j["aimbot"], "CoolFov", false);
    Globals::NoSpreadAimbot = safe(j["aimbot"], "NoSpread", false);
    Globals::Aimlock = safe(j["aimbot"], "Aimlock", false);
    Globals::LegitBotKey = safe(j["aimbot"], "LegitBotKey", 0);
    Globals::SecondKey = safe(j["aimbot"], "SecondKey", 0);
    Globals::DistangeEsp = safe(j["esp"], "DistangeEsp", false);
    Globals::Snapline = safe(j["esp"], "Snapline", false);
    Globals::Box2D = safe(j["esp"], "Box2D", false);
    Globals::Box3D = safe(j["esp"], "Box3D", false);
    Globals::CorneredBox = safe(j["esp"], "CorneredBox", false);
    Globals::dropped_gun = safe(j["esp"], "dropped_gun", false);
    Globals::SkeletonEsp = safe(j["esp"], "SkeletonEsp", false);
    Globals::Healthbar = safe(j["esp"], "Healthbar", false);
    Globals::HealthText = safe(j["esp"], "HealthText", false);
    Globals::skill_esp = safe(j["esp"], "skill_esp", false);
    Globals::HeadESP = safe(j["esp"], "HeadESP", false);
    Globals::SpikeEsp = safe(j["esp"], "SpikeEsp", false);
    Globals::WeaponEsp = safe(j["esp"], "WeaponEsp", false);
    Globals::AgentName = safe(j["esp"], "AgentName", false);
    Globals::SelectSnapline = safe(j["esp"], "SelectSnapline", 0);

    Globals::ChamsESP = safe(j["chams"], "ChamsESP", false);
    Globals::outline = safe(j["chams"], "outline", false);
    Globals::rainbow_chams = safe(j["chams"], "rainbow_chams", false);
    Globals::glowenemyfloat = safe(j["chams"], "glowenemyfloat", 1.0f);

    Globals::WireFrameHand = safe(j["misc"], "WireFrameHand", false);
    Globals::WireFrameWeapon = safe(j["misc"], "WireFrameWeapon", false);
    Globals::HandGlow = safe(j["misc"], "HandGlow", false);
    Globals::custom_fresnel = safe(j["misc"], "custom_fresnel", false);
    Globals::BunnyHop = safe(j["misc"], "BunnyHop", false);
    Globals::AntiAFK = safe(j["misc"], "AntiAFK", false);
    Globals::Watermark = safe(j["misc"], "Watermark", false);
    Globals::TeamCheck = safe(j["misc"], "TeamCheck", false);
    Globals::MenuKey = safe(j["misc"], "MenuKey", 0);

    vandalSkinOption = safe(j["skin"], "Vandal", 0);
    phantomSkinOption = safe(j["skin"], "Phantom", 0);
    operatorSkinOption = safe(j["skin"], "Operator", 0);
    bulldogSkinOption = safe(j["skin"], "Bulldog", 0);
    frenzySkinOption = safe(j["skin"], "Frenzy", 0);
    guardianSkinOption = safe(j["skin"], "Guardian", 0);
    sheriffSkinOption = safe(j["skin"], "Sheriff", 0);
    ghostSkinOption = safe(j["skin"], "Ghost", 0);
    spectreSkinOption = safe(j["skin"], "Spectre", 0);
    classicSkinOption = safe(j["skin"], "Classic", 0);
    marshalSkinOption = safe(j["skin"], "Marshal", 0);
    knifeSkinOption = safe(j["skin"], "Knife", 0);
    Globals::BuddyChanger = safe(j["skin"], "BuddyChanger", false);
    Globals::Buddytext = safe(j["miskinsc"], "BuddyText", false);
    index = safe(j["skin"], "Buddy", 0);
    Globals::SkipTutorial = safe(j["exploits"], "SkipTutorial", false);
    Globals::Thirdperson = safe(j["exploits"], "Thirdperson", false);
    Globals::SpinBot = safe(j["exploits"], "SpinBot", false);
    Globals::championssheriff = safe(j["exploits"], "championssheriff", false);
    Globals::big_gun = safe(j["exploits"], "big_gun", false);
    Globals::bigweapon = safe(j["exploits"], "bigweapon", false);
    Globals::biggunvalue = safe(j["exploits"], "biggunvalue", 0.f);
    Globals::FovChangerValue = safe(j["exploits"], "FovChangerValue", 105.f);
    Globals::spinbot_speed = safe(j["exploits"], "spinbot_speed", 0.f);
    Globals::third_person_float = safe(j["exploits"], "third_person_float", 0.f);
}

auto isActorValid = [](AShooterCharacter* Actor, AShooterCharacter* MyShooter) -> bool {
    SPOOF_FUNC;
	return Actor && MyShooter;
	};


void Rehook(UWorld* Uworld, APlayerController* PlayerController) {
    SPOOF_FUNC;
	if (Uworld == nullptr || PlayerController == nullptr)
		return;

	APlayerCameraManager* CameraManager = PlayerController->GetPlayerCameraManager();

	if (CameraManager == nullptr)
		return;

	try {
		if (G::UWorldClass != Uworld && CameraManager) {
            SPOOF_FUNC;
		  //  Hook::vhook((void*)CameraManager, SetCameraCachePOVHook, 0xd7, (void**)&SetCameraCachePOVOriginal);
			G::UWorldClass = Uworld;
		}   

	}
	catch (const std::exception& e) {
		return;
	}

}
