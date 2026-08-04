	#include "config.hpp"
#include "options.hpp"
#include <ShlObj.h>
#include <filesystem>
#include <Windows.h>
#include <iostream>
#include "base64.hpp"
#include <fstream>


using namespace std;

void CConfig::AddItem(void* pointer, const char* name, const std::string& type) {
	items.push_back(new C_ConfigItem(std::string(name), pointer, type));
}

void CConfig::setup_item(int* pointer, int value, const std::string& name)
{
	AddItem(pointer, name.c_str(), ("int"));
	*pointer = value;
}

void CConfig::setup_item(bool* pointer, bool value, const std::string& name)
{
	AddItem(pointer, name.c_str(), ("bool"));
	*pointer = value;
}

void CConfig::setup_item(float* pointer, float value, const std::string& name)
{
	AddItem(pointer, name.c_str(), ("float"));
	*pointer = value;
}

void CConfig::setup_item(std::vector< int >* pointer, int size, const std::string& name)
{
	AddItem(pointer, name.c_str(), ("vector<int>"));
	pointer->clear();

	for (int i = 0; i < size; i++)
		pointer->push_back(FALSE);
}

void CConfig::setup_item(std::vector< std::string >* pointer, const std::string& name)
{
	AddItem(pointer, name.c_str(), ("vector<string>"));
}

void CConfig::setup_item(std::string* pointer, const std::string& value, const std::string& name)
{
	AddItem(pointer, name.c_str(), ("string"));
	*pointer = value;
}



void CConfig::SetupAimbot() {
	setup_item(&g_Options.Aimbot, false, ("Aimbot"));
	setup_item(&g_Options.AimKey, 0, ("AimKey"));
	setup_item(&g_Options.VisibleCheck, true, ("VisibleCheck"));
	setup_item(&g_Options.AimRadius, 20.0f, ("AimRadius"));
	setup_item(&g_Options.Smooth, 7.0f, ("Aimbot_Smooth"));
	setup_item(&g_Options.drawfov, false, ("drawfov"));
	setup_item(&g_Options.NoSpreadmode, 0, ("NoSpreadmode"));
	setup_item(&g_Options.aimlock, 0, ("aimlock"));
	setup_item(&g_Options.recoilcontrol, 0, ("recoilcontrol"));
}

void CConfig::SetupVisuals() {
	setup_item(&g_Options.EnableESP, false, ("EnableESP"));
	setup_item(&g_Options.box3d, false, ("box3d"));
	setup_item(&g_Options.ChamsESP, false, ("ChamsESP"));
	setup_item(&g_Options.box2d, false, ("box2d"));
	setup_item(&g_Options.corneredbox, false, ("corneredbox"));
	setup_item(&g_Options.Behind, false, ("Behind"));
	setup_item(&g_Options.Always, false, ("Always"));
	setup_item(&g_Options.snapline, false, ("snapline"));
	setup_item(&g_Options.HeadESP, false, ("HeadESP"));
	setup_item(&g_Options.healthbar, false, ("healthbar"));
	setup_item(&g_Options.SpikeEsp, false, ("SpikeEsp"));
	setup_item(&g_Options.WeaponEsp, false, ("WeaponEsp"));
	setup_item(&g_Options.AgentNameESP, false, ("AgentNameESP"));
	setup_item(&g_Options.gadgetm_mode, false, ("gadgetm_mode"));

}

void CConfig::SetupMisc() {
	setup_item(&g_Options.WireFrameHand, false, ("WireFrameHand"));
	setup_item(&g_Options.WireFrameWeapon, false, ("WireFrameWeapon"));
	setup_item(&g_Options.recoilcontrol, false, ("recoilcontrol"));
	setup_item(&g_Options.autoknife, false, ("autoknife"));
	setup_item(&g_Options.Bhop, false, ("Bhop"));
	setup_item(&g_Options.fovchangurvalue, 105.0f, ("fovchangurvalue"));
	setup_item(&g_Options.EnableSkin, false, ("EnableSkin"));
}

void CConfig::SetupColors() {

}

void CConfig::Initialize() {
	CHAR my_documents[MAX_PATH];
	SHGetFolderPathA(nullptr, CSIDL_PERSONAL, nullptr, SHGFP_TYPE_CURRENT, my_documents);
	folder = my_documents + std::string(("\\Internal\\"));
	CreateDirectoryA(folder.c_str(), nullptr);

	SetupAimbot();
	SetupVisuals();
	SetupMisc();
	SetupColors();
}



CConfig* Config = new CConfig();