#pragma once
#include "canvas_gui.h"
#include "options.hpp"
#include <fstream>
static int vandalSkinOption = 0;
static int sheriffSkinOption = 0;
static int guardianSkinOption = 0;
static int frenzySkinOption = 0;
static int bulldogSkinOption = 0;
static int operatorSkinOption = 0;
static int phantomSkinOption = 0;
static int ghostSkinOption = 0;
static int spectreSkinOption = 0;
static int classicSkinOption = 0;
static int marshalSkinOption = 0;	
static int knifeSkinOption = 0;
static int outlawSkinOption = 0;
// Define skin arrays for each weapon type
static const std::vector<SkinData> vandalSkins = {
{L"Divergence V4ndal", L"Default__AK_Anomaly_PrimaryAsset_C", L"Default__Anomaly_v1_PrimaryAsset_C", 4},
{L"CYRAX Vandal", L"Default__AK_Syndra_PrimaryAsset_C", L"Default__Syndra_v1_PrimaryAsset_C", 4},
{L"Primordium Vandal", L"Default__AK_Hellfire_PrimaryAsset_C", L"Default__Hellfire_v2_PrimaryAsset_C", 4},
{L"Singularity Vandal", L"Default__AK_Edge2_PrimaryAsset_C", L"Default__AK_Edge2_v1_PrimaryAsset_C", 4},
{L"Aemondir Vandal", L"Default__AK_Legion_PrimaryAsset_C", L"Default__AK_Legion_Lv3_PrimaryAsset_C", 4},
{L"Evori Dreamwings Vandal", L"Default__AK_StarPower_PrimaryAsset_C", L"Default__StarPower_v3_PrimaryAsset_C", 4},
{L"Prelude to Chaos Vandal", L"Default__AK_DemonStone_PrimaryAsset_C", L"Default__AK_DemonStone_Lv4_PrimaryAsset_C", 4},
{L"Reaver Vandal", L"Default__AK_Soulstealer_PrimaryAsset_C", L"Default__AK_Soulstealer_White_PrimaryAsset_C", 4},
{L"XERØFANG Vandal ", L"Default__AK_Hypedragon_PrimaryAsset_C", L"Default__AK_Hypedragon_v1_PrimaryAsset_C", 4},
{L"Kuronami Vandal", L"Default__AK_Ninja_PrimaryAsset_C", L"Default__AK_Ninja_v1_PrimaryAsset_C", 4},
{L"Imperium Vandal", L"Default__AK_Dynasty_PrimaryAsset_C", L"Default__AK_Dynasty_Standard_PrimaryAsset_C", 4},
{L"Champions 2023 Vandal", L"Default__AK_Champions2023_PrimaryAsset_C", L"Default__AK_Champions2023_Standard_PrimaryAsset_C", 4},
{L"Magepunk Vandal", L"Default__AK_Magepunk3_PrimaryAsset_C", L"Default__AK_Magepunk3_Standard_PrimaryAsset_C", 4},
{L"Gaia's Vengeance Vandal", L"Default__AK_Ashen_PrimaryAsset_C", L"Default__AK_Ashen_v2_PrimaryAsset_C", 4},
{L"RGX 11z Pro Vandal", L"Default__AK_Afterglow_PrimaryAsset_C", L"Default__AK_Afterglow_Blue_PrimaryAsset_C", 4},
{L"Champions 2021 Vandal", L"Default__AK_Champions_PrimaryAsset_C", L"Default__AK_Champions_Lv4_PrimaryAsset_C", 4},
{L"Elderflame Vandal", L"Default__AK_Dragon_PrimaryAsset_C", L"Default__AK_Dragon_Blue_PrimaryAsset_C", 4},
{L"Ion Vandal", L"Default__AK_Oblivion2_PrimaryAsset_C", L"Default__AK_Oblivion2_v1_PrimaryAsset_C", 4},
{L"ChronoVoid Vandal", L"Default__AK_Daedalus_PrimaryAsset_C", L"Default__AK_Daedalus_v2_PrimaryAsset_C", 4},
{L"Araxys Vandal", L"Default__AK_Antares_PrimaryAsset_C", L"Default__AK_Antares_Lv4_PrimaryAsset_C", 4},
{L"Origin Vandal", L"Default__AK_Circle_PrimaryAsset_C", L"Default__AK_Circle_Lv4_PrimaryAsset_C",4},
{L"Sentinels of Light Vandal", L"Default__AK_SOL_PrimaryAsset_C", L"Default__AK_SOL_Lv4_PrimaryAsset_C", 4},
{L"Glitchpop Vandal", L"Default__AK_Cyberpunk2_PrimaryAsset_C", L"Default__AK_Cyberpunk2_Red_PrimaryAsset_C", 4},
{L"Prime Vandal", L"Default__AssaultRifle_AK_HypeBeast_PrimaryAsset_C", L"Default__AssaultRifle_AK_HypeBeast_Blue_PrimaryAsset_C", 4},
{L"Oni Vandal", L"Default__AK_Oni2_PrimaryAsset_C", L"Default__AK_Oni2_Lv4_PrimaryAsset_C", 4},
{L"Overdrive Vandal", L"Default__AK_Motorbike_PrimaryAsset_C", L"Default__Motorbike_v2_PrimaryAsset_C", 4},
{L"EX.O Vandal", L"Default__AK_Hologram_PrimaryAsset_C", L"Default__Hologram_v3_PrimaryAsset_C", 4},
{L"Valiant Hero Vandal", L"Default__AK_MonkeyKing_PrimaryAsset_C", L"Default__MonkeyKing_v1_PrimaryAsset_C", 4},
{L"Cryostasis Vandal", L"Default__AK_Permafrost_PrimaryAsset_C", L"Default__Permafrost_v1_PrimaryAsset_C", 4},
{L"Forsaken Vandal", L"Default__AK_Fallen_PrimaryAsset_C", L"Default__Fallen_v2_PrimaryAsset_C", 4},

};
static const std::vector<SkinData> phantomSkins = {

{L"Bolt Phantom", L"Default__Carbine_Bolt_PrimaryAsset_C", L"Default__Carbine_Bolt_v1_PrimaryAsset_C", 4},
{L"Nocturnum Phantom", L"Default__Carbine_Coven_PrimaryAsset_C", L"Default__Carbine_Coven_V1_PrimaryAsset_C", 4},
{L"Champions 2024 Phantom", L"Default__Carbine_Champions2024_PrimaryAsset_C", L"Default__Carbine_Champions2024_Lv4_PrimaryAsset_C", 4},
{L"Mystbloom Phantom", L"Default__Carbine_Spirit_PrimaryAsset_C", L"Default__Carbine_Spirit_v2_PrimaryAsset_C", 4},
{L"Sovereign Phantom", L"Default__Carbine_Sovereign2_PrimaryAsset_C", L"Default__Carbine_Sovereign2_v1_PrimaryAsset_C", 4},
{L"Singularity Phantom", L"Default__AssaultRifle_ACR_Edge_PrimaryAsset_C", L"Default__AssaultRifle_ACR_Edge_Lv4_PrimaryAsset_C", 4},
{L"Spectrum Phantom", L"Default__Carbine_Atlas_PrimaryAsset_C", L"Default__Carbine_Atlas_v1_PrimaryAsset_C", 4},
{L"Reaver Phantom", L"Default__Carbine_Soulstealer2_PrimaryAsset_C", L"Default__Carbine_Soulstealer2_v1_PrimaryAsset_C", 4},
{L"RGX 11z Pro Phantom", L"Default__Carbine_Afterglow2_PrimaryAsset_C", L"Default__Carbine_Afterglow2_v2_PrimaryAsset_C", 4},
{L"Glitchpop Phantom", L"Default__Carbine_Cyberpunk2_PrimaryAsset_C", L"Default__Carbine_Cyberpunk2_Lv4_PrimaryAsset_C", 4},
{L"Ruination Phantom", L"Default__Carbine_King_PrimaryAsset_C", L"Default__Carbine_King_Lv4_PrimaryAsset_C", 4},
{L"ChronoVoid Phantom", L"Default__Carbine_Daedalus_PrimaryAsset_C", L"Default__Carbine_Daedalus_Lv4_PrimaryAsset_C", 4},
{L"Recon Phantom", L"Default__Carbine_SpecOps_PrimaryAsset_C", L"Default__Carbine_SpecOps_Lv4_PrimaryAsset_C", 4},
{L"BlastX Phantom", L"Default__Carbine_URF_PrimaryAsset_C", L"Default__Carbine_URF_Lv4_PrimaryAsset_C", 4},
{L"Protocol 781-A Phantom", L"Default__Carbine_Protocol_PrimaryAsset_C", L"Default__Carbine_Protocol_Lv4_PrimaryAsset_C", 4},
{L"Oni Phantom", L"Default__AssaultRifle_ACR_Oni_PrimaryAsset_C", L"Default__AssaultRifle_ACR_Oni_Black_PrimaryAsset_C", 4},
{L"Nebula Phantom", L"Default__Carbine_Cosmos_PrimaryAsset_C", L"Default__Carbine_Cosmos_Lv1_PrimaryAsset_C", 4},
{L"Celestial Phantom", L"Default__Carbine_Lunar_PrimaryAsset_C", L"Default__Carbine_Lunar_Lv1_PrimaryAsset_C", 4},

};
//
//
static const std::vector<SkinData> operatorSkins = {
{L"Divergence Operator", L"Default__BoltSniper_Anomaly_PrimaryAsset_C", L"Default__BoltSniper_Anomaly_v1_PrimaryAsset_C", 4},
{L"Mystbloom Operator", L"Default__BoltSniper_Spirit_PrimaryAsset_C", L"Default__BoltSniper_Spirit_v2_PrimaryAsset_C", 4},
{L"Ion Operator", L"Default__BoltSniper_Oblivion_PrimaryAsset_C", L"Default__BoltSniper_OblivionLv4_PrimaryAsset_C", 4},
{L"RGX 11z Pro Operator", L"Default__BoltSniper_Afterglow2_PrimaryAsset_C", L"Default__BoltSniper_Afterglow2_Lv5_PrimaryAsset_C", 4},
{L"Origin Operator", L"Default__BoltSniper_Circle_PrimaryAsset_C", L"Default__BoltSniper_Circle_Lv4_PrimaryAsset_C", 4},
{L"Prelude to Chaos Operator", L"Default__BoltSniper_DemonStone_PrimaryAsset_C", L"Default__BoltSniper_DemonStone_Lv4_PrimaryAsset_C", 4},
{L"Forsaken Operator", L"Default__BoltSniper_Fallen_PrimaryAsset_C", L"Default__BoltSniper_Fallen_Lv4_PrimaryAsset_C", 4},
{L"Glitchpop Operator", L"Default__BoltSniper_Cyberpunk2_PrimaryAsset_C", L"Default__BoltSniper_Cyberpunk2_Lv4_PrimaryAsset_C", 4},
{L"Radiant Entertainment System Operator", L"Default__BoltSniper_Arcade_PrimaryAsset_C", L"Default__BoltSniper_Arcade_Lv4_PrimaryAsset_C", 4},
{L"Elderflame Operator", L"Default__BoltSniper_Dragon_PrimaryAsset_C", L"Default__BoltSniper_Dragon_Dark_PrimaryAsset_C", 4},
{L"Sentinels of Light Operator", L"Default__BoltSniper_SOL_PrimaryAsset_C", L"Default__BoltSniper_SOL_Lv4_PrimaryAsset_C", 4},
{L"Reaver Operator", L"Default__BoltSniper_Soulstealer_PrimaryAsset_C", L"Default__BoltSniper_Soulstealer_Black_PrimaryAsset_C", 4},
{L"Tethered Realms Operator", L"Default__BoltSniper_SovWorld_PrimaryAsset_C", L"Default__BoltSniper_SovWorld_Lv1_PrimaryAsset_C", 4},
{L"Araxys Operator", L"Default__BoltSniper_Antares_PrimaryAsset_C", L"Default__BoltSniper_Antares_Lv4_PrimaryAsset_C", 4},
{L"Gravitational Uranium Neuroblaster Operator", L"Default__BoltSniper_Raygun_PrimaryAsset_C", L"Default__BoltSniper_Raygun_Lv2_PrimaryAsset_C", 4},
{L"Magepunk Operator", L"Default__BoltSniper_Magepunk2_v1_PrimaryAsset_C", L"Default__BoltSniper_Magepunk2_Lv4_PrimaryAsset_C", 4},

};
//
static const std::vector<SkinData> bulldogSkins = {

{L"Nocturnum Bulldog", L"Default__Burst_Coven_PrimaryAsset_C", L"Default__Burst_Coven_v1_PrimaryAsset_C", 4},
{L"Glitchpop Bulldog", L"Default__AssaultRifle_Burst_Cyberpunk_PrimaryAsset_C", L"Default__AssaultRifle_Burst_Cyberpunk_Lv4_PrimaryAsset_C", 4},
{L"Spectrum Bulldog", L"Default__Burst_Atlas_PrimaryAsset_C", L"Default__Burst_Atlas_v2_PrimaryAsset_C", 4},
{L"Radiant Entertainment System Bulldog", L"Default__Burst_Arcade_v2_PrimaryAsset_C", L"Default__Burst_Arcade_Lv4_PrimaryAsset_C", 4},
};
//
static const std::vector<SkinData> frenzySkins = {

{L"Sovereign Frenzy", L"Default__AutoPistol_Sovereign2_PrimaryAsset_C", L"Default__AutoPistol_Sovereign2_v1_PrimaryAsset_C", 4},
{L"Elderflame Frenzy", L"Default__AutomaticPistol_Dragon_PrimaryAsset_C", L"Default__AutomaticPistol_Dragon_Blue_PrimaryAsset_C", 4},
{L"Glitchpop Frenzy", L"Default__AutomaticPistol_Cyberpunk_PrimaryAsset_C", L"Default__AutomaticPistol_Cyberpunk_Blue_PrimaryAsset_C", 4},
{L"BlastX Frenzy", L"Default__AutoPistol_URF_PrimaryAsset_C", L"Default__AutoPistol_URF_Standard_PrimaryAsset_C", 4},
{L"Prime//2.0 Frenzy", L"Default__AutomaticPistol_HypeBeast2_PrimaryAsset_C", L"Default__AutomaticPistol_HypeBeast2_PrimaryAsset_C", 4},
{L"Ion Frenzy", L"Default__AutoPistol_Oblivion2_PrimaryAsset_C", L"Default__AutoPistol_Oblivion2_Lv4_PrimaryAsset_C", 4},
{L"Oni Frenzy", L"Default__AutoPistol_Oni2_PrimaryAsset_C", L"Default__AutoPistol_Oni2_PrimaryAsset_C", 4},
{L"Origin Frenzy", L"Default__AutoPistol_Circle_PrimaryAsset_C", L"Default__AutoPistol_Circle_Lv4_PrimaryAsset_C", 4},
{L"RGX 11z Pro Frenzy", L"Default__AutoPistol_Afterglow_PrimaryAsset_C", L"Default__AutoPistol_Afterglow_Lv4_PrimaryAsset_C", 4},

};
//
static const std::vector<SkinData> guardianSkins = {	

{L"Prime Guardian", L"Default__DMR_HypeBeast_PrimaryAsset_C", L"Default__DMR_HypeBeast_Lv4_PrimaryAsset_C", 4},
{L"Reaver Guardian", L"Default__DMR_SoulStealer_PrimaryAsset_C", L"Default__DMR_SoulStealer_Lv4_PrimaryAsset_C", 4},
{L"Ruination Guardian", L"Default__DMR_King_PrimaryAsset_C", L"Default__DMR_King_Lv4_PrimaryAsset_C", 4},
{L"Sovereign Guardian", L"Default__DMR_Sovereign_PrimaryAsset_C", L"Default__DMR_Sovereign_Lv4_PrimaryAsset_C", 4},
{L"RGX 11z Pro Guardian", L"Default__DMR_Afterglow_PrimaryAsset_C", L"Default__DMR_Afterglow_Lv4_PrimaryAsset_C", 4},
{L"Oni Guardian", L"Default__DMR_Oni_PrimaryAsset_C", L"Default__DMR_Oni_Lv4_PrimaryAsset_C", 4},

};
//
static const std::vector<SkinData> sheriffSkins = {

{L"Doombringer Sheriff", L"Default__Revolver_Cyberknight_PrimaryAsset_C", L"Default__Revolver_Cyberknight_v1_PrimaryAsset_C", 4},
{L"Neo Frontier Sheriff", L"Default__Revolver_Gunslinger_PrimaryAsset_C", L"Default__Revolver_Gunslinger_v1_PrimaryAsset_C", 4},
{L"RGX 11z Pro Sheriff", L"Default__Revolver_Afterglow3_PrimaryAsset_C", L"Default__Revolver_Afterglow3_v2_PrimaryAsset_C", 4},
{L"Mystbloom Sheriff", L"Default__Revolver_Spirit_PrimaryAsset_C", L"Default__Revolver_Spirit_v2_PrimaryAsset_C", 4},
{L"Kuronami Sheriff", L"Default__Revolver_Ninja_PrimaryAsset_C", L"Default__Revolver_Ninja_v1_PrimaryAsset_C", 4},
{L"Reaver Sheriff", L"Default__RevolverPistol_Soulstealer_PrimaryAsset_C", L"Default__RevolverPistol_Soulstealer_White_PrimaryAsset_C", 4},
{L"Singularity Sheriff", L"Default__RevolverPistol_Edge_PrimaryAsset_C", L"Default__RevolverPistol_Edge_Lv4_PrimaryAsset_C", 4},
{L"Protocol 781-A Sheriff", L"Default__Revolver_Protocol_PrimaryAsset_C", L"Default__Revolver_Protocol_Lv4_PrimaryAsset_C", 4},
{L"Sentinels of Light Sheriff", L"Default__Revolver_SOL_PrimaryAsset_C", L"Default__Revolver_SOL_Lv4_PrimaryAsset_C", 4},
{L"ChronoVoid Sheriff", L"Default__Revolver_Daedalus_PrimaryAsset_C", L"Default__Revolver_Daedalus_Lv4_PrimaryAsset_C", 4},
{L"Magepunk Sheriff", L"Default__Revolver_Magepunk2_PrimaryAsset_C", L"Default__Revolver_Magepunk2_Lv4_PrimaryAsset_C", 4},
{L"Nebula Sheriff", L"Default__Revolver_Cosmos_PrimaryAsset_C", L"Default__Revolver_Cosmos_Lv1_PrimaryAsset_C", 4},
{L"Arcane Sheriff", L"Default__Revolver_XP1_PrimaryAsset_C", L"Default__Revolver_XP1_Lv2_PrimaryAsset_C", 4},
{L"Schema Sheriff", L"Default__Revolver_Schema_PrimaryAsset_C", L"Default__Revolver_Schema_Lv1_PrimaryAsset_C", 4},
{L"Crimsonbeast Sheriff", L"Default__Revolver_Mythic_PrimaryAsset_C", L"Default__Revolver_Mythic_Lv2_PrimaryAsset_C", 4},
{L"Signature Sheriff", L"Default__Revolver_MidnightAerosol_PrimaryAsset_C", L"Default__Revolver_MidnightAerosol_PrimaryAsset_C", 4},
{L"Abyssal Sheriff", L"Default__Revolver_DeepSea_PrimaryAsset_C", L"Default__Revolver_DeepSea_Lv1_PrimaryAsset_C", 4},
{L"Ion Sheriff", L"Default__RevolverPistol_Oblivion_PrimaryAsset_C", L"Default__RevolverPistol_OblivionLv4_PrimaryAsset_C", 4},

};
static const std::vector<SkinData> ghostSkins = {

{L"Reaver Ghost", L"Default__Luger_Soulstealer2_PrimaryAsset_C", L"Default__Luger_Soulstealer2_v1_PrimaryAsset_C", 4},
{L"XERØFANG Ghost", L"Default__Luger_Hypedragon_PrimaryAsset_C", L"Default__Luger_Hypedragon_v1_PrimaryAsset_C", 4},
{L"Sovereign Ghost", L"Default__LugerPistol_Sovereign_PrimaryAsset_C", L"Default__LugerPistol_Sovereign_Purple_PrimaryAsset_C", 4},
{L"Ruination Ghost", L"Default__Luger_King_PrimaryAsset_C", L"Default__Luger_King_Lv4_PrimaryAsset_C", 4},
{L"Magepunk Ghost", L"Default__Luger_Magepunk_PrimaryAsset_C", L"Default__Luger_Magepunk_Lv4_PrimaryAsset_C", 4},
{L"Gaia's Vengeance Ghost", L"Default__LugerPistol_Ashen_PrimaryAsset_C", L"Default__LugerPistol_Ashen_Lv4_PrimaryAsset_C", 4},

};
//
static const std::vector<SkinData> spectreSkins = {
{L"Kuronami Spectre", L"Default__MP5_Ninja_PrimaryAsset_C", L"Default__MP5_Ninja_v1_PrimaryAsset_C", 4},
{L"Ruination Spectre", L"Default__MP5_King_PrimaryAsset_C", L"Default__MP5_King_Lv4_PrimaryAsset_C", 4},
{L"Protocol 781-A Spectre", L"Default__MP5_Protocol_PrimaryAsset_C", L"Default__MP5_Protocol_Lv4_PrimaryAsset_C", 4},
{L"Reaver Spectre", L"Default__MP5_Soulstealer2_PrimaryAsset_C", L"Default__MP5_Soulstealer2_Lv4_PrimaryAsset_C", 4},
{L"Radiant Crisis 001 Spectre", L"Default__MP5_Comicbook_PrimaryAsset_C", L"Default__MP5_Comicbook_Lv3_PrimaryAsset_C", 4},
};
//
static const std::vector<SkinData> classicSkins = {
{L"VCT x SEN Classic", L"Default__BasePistol_VCTCaps24_SEN_PrimaryAsset_C", L"Default__BasePistol_VCTCaps24_SEN_V1_PrimaryAsset_C", 4},
{L"VCT x G2 Classic", L"Default__BasePistol_VCTCaps24_G2_PrimaryAsset_C", L"Default__BasePistol_VCTCaps24_G2_Lv3_PrimaryAsset_C", 4},
{L"VCT x BBL Classic", L"Default__BasePistol_VCTCaps24_BBL_PrimaryAsset_C", L"Default__BasePistol_VCTCaps24_BBL_Lv3_PrimaryAsset_C", 4},
{L"Spectrum Classic", L"Default__BasePistol_Atlas_PrimaryAsset_C", L"Default__BasePistol_Atlas_v1_PrimaryAsset_C", 4},
{L"Prime Classic", L"Default__BasePistol_HypeBeast_PrimaryAsset_C", L"Default__BasePistol_HypeBeast_Blue_PrimaryAsset_C", 4},
{L"RGX 11z Pro Classic", L"Default__BasePistol_Afterglow2_PrimaryAsset_C", L"Default__BasePistol_Afterglow2_Lv4_PrimaryAsset_C", 4},
{L"Forsaken Classic", L"Default__BasePistol_Fallen_PrimaryAsset_C", L"Default__BasePistol_Fallen_Lv3_PrimaryAsset_C", 4},
{L"Glitchpop Classic", L"Default__BasePistol_Cyberpunk2_PrimaryAsset_C", L"Default__BasePistol_Cyberpunk2_Lv4_PrimaryAsset_C", 4},
};
//
static const std::vector<SkinData> marshalSkins = {
{L"Nocturnum Marshal", L"Default__LeverSniper_Coven_PrimaryAsset_C", L"Default__LeverSniper_Coven_V1_PrimaryAsset_C", 4},
{L"Kuronami Marshal", L"Default__LeverSniper_Ninja_PrimaryAsset_C", L"Default__LeverSniper_Ninja_v1_PrimaryAsset_C", 4},
{L"Sovereign Marshal", L"Default__LeverSniperRifle_Sovereign_PrimaryAsset_C", L"Default__LeverSniperRifle_Sovereign_Purple_PrimaryAsset_C", 4},
};
//
//static const std::vector<SkinData> judgeSkins = {
//	{L"Default__AutomaticShotgun_Soulstealer_PrimaryAsset_C", L"Default__AutomaticShotgun_Soulstealer_Lv2_PrimaryAsset_C", 4},
//	{L"Default__AutomaticShotgun_Dragon_PrimaryAsset_C", L"Default__AutomaticShotgun_Dragon_Lv4_PrimaryAsset_C", 4},
//	{L"Default__AutomaticShotgun_Ninja_PrimaryAsset_C", L"Default__AutomaticShotgun_Ninja_v2_PrimaryAsset_C", 4},
//	{L"Default__AutomaticShotgun_Sovereign_PrimaryAsset_C", L"Default__AutomaticShotgun_Sovereign_Lv4_PrimaryAsset_C", 4},
//	{L"Default__AutomaticShotgun_Oni_PrimaryAsset_C", L"Default__AutomaticShotgun_Oni_Lv4_PrimaryAsset_C", 4},
//};
//
//static const std::vector<SkinData> ariesSkins = {
//	{L"Default__LMG_SOL_PrimaryAsset_C", L"Default__LMG_SOL_Lv4_PrimaryAsset_C", 4},
//	{L"Default__LMG_Dragon_PrimaryAsset_C", L"Default__LMG_Dragon_Lv4_PrimaryAsset_C", 4},
//	{L"Default__LMG_Ninja_PrimaryAsset_C", L"Default__LMG_Ninja_v2_PrimaryAsset_C", 4},
//	{L"Default__LMG_Soulstealer_PrimaryAsset_C", L"Default__LMG_Soulstealer_Lv4_PrimaryAsset_C", 4},
//	{L"Default__LMG_Oni_PrimaryAsset_C", L"Default__LMG_Oni_Lv4_PrimaryAsset_C", 4},
//};
//
//static const std::vector<SkinData> odinSkins = {
//	{L"Default__HMG_Soulstealer_PrimaryAsset_C", L"Default__HMG_Soulstealer_Lv2_PrimaryAsset_C", 4},
//	{L"Default__HMG_Dragon_PrimaryAsset_C", L"Default__HMG_Dragon_Lv4_PrimaryAsset_C", 4},
//	{L"Default__HMG_Ninja_PrimaryAsset_C", L"Default__HMG_Ninja_v2_PrimaryAsset_C", 4},
//	{L"Default__HMG_Sovereign_PrimaryAsset_C", L"Default__HMG_Sovereign_Lv4_PrimaryAsset_C", 4},
//	{L"Default__HMG_Oni_PrimaryAsset_C", L"Default__HMG_Oni_Lv4_PrimaryAsset_C", 4},
//};
//
//static const std::vector<SkinData> buckySkins = {
//	{L"Default__PumpShotgun_Soulstealer_PrimaryAsset_C", L"Default__PumpShotgun_Soulstealer_Lv2_PrimaryAsset_C", 4},
//	{L"Default__PumpShotgun_Dragon_PrimaryAsset_C", L"Default__PumpShotgun_Dragon_Lv4_PrimaryAsset_C", 4},
//	{L"Default__PumpShotgun_Ninja_PrimaryAsset_C", L"Default__PumpShotgun_Ninja_v2_PrimaryAsset_C", 4},
//	{L"Default__PumpShotgun_Sovereign_PrimaryAsset_C", L"Default__PumpShotgun_Sovereign_Lv4_PrimaryAsset_C", 4},
//	{L"Default__PumpShotgun_Oni_PrimaryAsset_C", L"Default__PumpShotgun_Oni_Lv4_PrimaryAsset_C", 4},
//};
//
//static const std::vector<SkinData> shortySkins = {
//	{L"Default__SawedOffShotgun_Soulstealer_PrimaryAsset_C", L"Default__SawedOffShotgun_Soulstealer_Lv2_PrimaryAsset_C", 4},
//	{L"Default__SawedOffShotgun_Dragon_PrimaryAsset_C", L"Default__SawedOffShotgun_Dragon_Lv4_PrimaryAsset_C", 4},
//	{L"Default__SawedOffShotgun_Ninja_PrimaryAsset_C", L"Default__SawedOffShotgun_Ninja_v2_PrimaryAsset_C", 4},
//	{L"Default__SawedOffShotgun_Sovereign_PrimaryAsset_C", L"Default__SawedOffShotgun_Sovereign_Lv4_PrimaryAsset_C", 4},
//	{L"Default__SawedOffShotgun_Oni_PrimaryAsset_C", L"Default__SawedOffShotgun_Oni_Lv4_PrimaryAsset_C", 4},
//};
//
//static const std::vector<SkinData> stingerSkins = {
//	{L"Default__Vector_Soulstealer_PrimaryAsset_C", L"Default__Vector_Soulstealer_Lv2_PrimaryAsset_C", 4},
//	{L"Default__Vector_Dragon_PrimaryAsset_C", L"Default__Vector_Dragon_Lv4_PrimaryAsset_C", 4},
//	{L"Default__Vector_Ninja_PrimaryAsset_C", L"Default__Vector_Ninja_v2_PrimaryAsset_C", 4},
//	{L"Default__Vector_Sovereign_PrimaryAsset_C", L"Default__Vector_Sovereign_Lv4_PrimaryAsset_C", 4},
//	{L"Default__Vector_Oni_PrimaryAsset_C", L"Default__Vector_Oni_Lv4_PrimaryAsset_C", 4},
//};
//
static const std::vector<SkinData> knifeskins = {
{L"Divergence St4ff", L"Default__Melee_Anomaly_PrimaryAsset_C", L"Default__Melee_Anomaly_v1_PrimaryAsset_C", 2},
{L"Helix Daggers", L"Default__Melee_Snake_PrimaryAsset_C", L"Default__Melee_Snake_v2_PrimaryAsset_C", 2},
{L"Blades of Primordia", L"Default__Melee_Hellfire_PrimaryAsset_C", L"Default__Melee_Hellfire_v2_PrimaryAsset_C", 2},
{L"Bolt Knife", L"Default__Melee_Bolt_PrimaryAsset_C", L"Default__Melee_Bolt_v1_PrimaryAsset_C", 2},
{L"CYRAX Fanblade", L"Default__Melee_Syndra_PrimaryAsset_C", L"Default__Melee_Syndra_v1_PrimaryAsset_C", 2},
{L"VCT 2025 Karambit", L"Default__Melee_VCT25Season_PrimaryAsset_C", L"Default__Melee_VCT25Season_v1_PrimaryAsset_C", 2},
{L"EX.O Edge", L"Default__Melee_Hologram_PrimaryAsset_C", L"Default__Melee_Hologram_v3_PrimaryAsset_C", 2},
{L"Doombringer Battleaxe", L"Default__Melee_Cyberknight_PrimaryAsset_C", L"Default__Melee_Cyberknight_v1_PrimaryAsset_C", 2},
{L"Neo Frontier Axe", L"Default__Melee_Gunslinger_PrimaryAsset_C", L"Default__Gunslinger_Syndra_v1_PrimaryAsset_C", 2},
{L"Evori's Spellcaster", L"Default__Melee_StarPower_PrimaryAsset_C", L"Default__Melee_StarPower_v1_PrimaryAsset_C", 2},
{L"Singularity Butterfly Knife", L"Default__Melee_Edge2_PrimaryAsset_C", L"Default__Melee_Edge2_v1_PrimaryAsset_C", 2},
{L"Nocturnum Scythe", L"Default__Melee_Coven_PrimaryAsset_C", L"Default__Melee_Coven_v1_PrimaryAsset_C", 2},
{L"Champions 2024 Blade", L"Default__Melee_Champions2024_PrimaryAsset_C", L"Default__Melee_Champions2024_Lv3_PrimaryAsset_C", 2},
{L"RGX 11z Pro Karambit", L"Default__Melee_Afterglow3_PrimaryAsset_C", L"Default__Melee_Afterglow3_v2_PrimaryAsset_C", 2},
{L"Mystbloom Kunai", L"Default__Melee_Spirit_PrimaryAsset_C", L"Default__Melee_Spirit_v2_PrimaryAsset_C", 2},
{L"Eternal Sovereign", L"Default__Melee_Sovereign2_PrimaryAsset_C", L"Default__Melee_Sovereign2_v1_PrimaryAsset_C", 2},
{L"Waveform", L"Default__Melee_Atlas_PrimaryAsset_C", L"Default__Melee_Atlas_v1_PrimaryAsset_C", 2},
{L"XERØFANG Knife", L"Default__Melee_Hypedragon_PrimaryAsset_C", L"Default__Melee_Hypedragon_v2_PrimaryAsset_C", 2},
{L"Kuronami no Yaiba", L"Default__Melee_Ninja_PrimaryAsset_C", L"Default__Melee_Ninja_V1_PrimaryAsset_C", 2},
{L"Champions 2023 Kunai", L"Default__Melee_Champions2023_PrimaryAsset_C", L"Default__Melee_Champions2023_PrimaryAsset_C", 2},
{L"Magepunk Sparkswitch", L"Default__Melee_Magepunk3_PrimaryAsset_C", L"Default__Melee_Magepunk3_PrimaryAsset_C", 2},
{L"VCT LOCK//IN Misericórdia", L"Default__Melee_Esportsinvitational_PrimaryAsset_C", L"Default__Melee_Esportsinvitational_Standard_PrimaryAsset_C", 2},
{L"Champions 2021 Karambit", L"Default__Melee_Champions_PrimaryAsset_C", L"Default__Melee_Champions_Lv2_PrimaryAsset_C", 2},
{L"Reaver Karambit", L"Default__Melee_Soulstealer2_PrimaryAsset_C", L"Default__Melee_Soulstealer2_v1_PrimaryAsset_C", 2},
{L"Black.Market Butterfly Knife", L"Default__Melee_Infantry2_Lv2_PrimaryAsset_C", L"Default__Melee_Infantry2_PrimaryAsset_C", 2},
{L"RGX 11z Pro Firefly", L"Default__Melee_Afterglow2_PrimaryAsset_C", L"Default__Melee_Afterglow2_v2_PrimaryAsset_C", 2},
{L"Xenohunter Knife", L"Default__Melee_Alien_PrimaryAsset_C", L"Default__Melee_Alien_Lv2_PrimaryAsset_C", 2},
{L"Prime//2.0 Karambit", L"Default__Melee_HypeBeast2_PrimaryAsset_C", L"Default__Melee_HypeBeast2_Lv2_PrimaryAsset_C", 2},
{L"Reaver Knife", L"Default__Melee_Soulstealer_PrimaryAsset_C", L"Default__Melee_Soulstealer_Lv2_PrimaryAsset_C", 2},
{L"Radiant Crisis 001 Baseball Bat", L"Default__Melee_Comicbook_PrimaryAsset_C", L"Default__Melee_Comicbook_Lv2_PrimaryAsset_C", 2},
//{L"NOT FOUND", L"Default__Melee_Dragon_PrimaryAsset_C", L"Default__Melee_Dragon_Lv2_PrimaryAsset_C", 2},
{L"Araxys Bio Harvester", L"Default__Melee_Antares_v2_PrimaryAsset_C", L"Default__Melee_Antares_Lv2_PrimaryAsset_C", 2},
{L"Soulstrife Scythe", L"Default__Melee_Haunted_PrimaryAsset_C", L"Default__Melee_Haunted_Lv2_PrimaryAsset_C", 2},
{L"Crimsonbeast Hammer", L"Default__Melee_Mythic_PrimaryAsset_C", L"Default__Melee_Mythic_Lv2_PrimaryAsset_C", 2},
{L"Magepunk Shock Gauntlet", L"Default__Melee_Magepunk2_PrimaryAsset_C", L"Default__Melee_Magepunk2_Lv2_PrimaryAsset_C", 2},
//{L"NOT FOUND", L"Default__Melee_Oni_PrimaryAsset_C", L"Default__Melee_Oni_Lv2_PrimaryAsset_C", 2},
{L"Onimaru Kunitsuna", L"Default__Melee_Oni2_PrimaryAsset_C", L"Default__Melee_Oni2_Lv2_PrimaryAsset_C", 2},
{L"Forsaken Ritual Blade", L"Default__Melee_Fallen_Lv2_PrimaryAsset_C", L"Default__Melee_Fallen_PrimaryAsset_C", 2},
{L"Blade of Chaos", L"Default__Melee_DemonStone_PrimaryAsset_C", L"Default__Melee_DemonStone_v2_PrimaryAsset_C", 2},
};

static const std::vector<SkinData> outlawskins = {
	{L"NIGGA",L"Default__DS_Gun_Afterglow3_PrimaryAsset_C", L"Default__DS_Gun_Afterglow3_v2_PrimaryAsset_C", 2},
};

static const std::vector<SkinData> chamspions_sheriff = {
	{L"NIGGA",L"Default__AK_Champions_PrimaryAsset_C", L"Default__AK_Champions_Lv4_PrimaryAsset_C", 2},
};

void ApplyWeaponSkin(AAresEquippable* myweapon, const std::vector<SkinData>& skins, int& skinOption) {
	UObject* skin_data_asset;
	UObject* chroma_data_asset;

	skin_data_asset = (UObject*)UObject::StaticFindObject(skins[skinOption].skin);
	chroma_data_asset = (UObject*)UObject::StaticFindObject(skins[skinOption].chroma);

	Skin::ChangeSkin(myweapon, skin_data_asset, chroma_data_asset, skins[skinOption].level, UWorldSave);
}
	void ChangeWeaponSkin(AAresEquippable* myweapon, const std::vector<SkinData>& skins, int& skinOption) {
		UObject* skin_data_asset;
		UObject* chroma_data_asset;

		if (Globals::EnableSkin && GetAsyncKeyState(Globals::SkinChangerKey)) {
			skinOption = (skinOption + 1) % skins.size();
			Sleep(140);
		}

		skin_data_asset = (UObject*)UObject::StaticFindObject(skins[skinOption].skin);
		chroma_data_asset = (UObject*)UObject::StaticFindObject(skins[skinOption].chroma);

		Skin::ChangeSkin(myweapon, skin_data_asset, chroma_data_asset, skins[skinOption].level, UWorldSave);
	}
void ApplySkinChanges(AAresEquippable* myweapon) {
	std::string weapon_name = kismentsystemlibrary::get_object_name((UObject*)myweapon).ToString();

	if (weapon_name.find("AssaultRifle_AK_C") != std::string::npos) {

		ChangeWeaponSkin(myweapon, vandalSkins, vandalSkinOption);
	}
	else if (weapon_name.find("AssaultRifle_ACR_C") != std::string::npos) {
		
		ChangeWeaponSkin(myweapon, phantomSkins, phantomSkinOption);
	}
	else if (weapon_name.find("BoltSniper_C") != std::string::npos) {
		
		ChangeWeaponSkin(myweapon, operatorSkins, operatorSkinOption);
	}
	else if (weapon_name.find("AssaultRifle_Burst_C") != std::string::npos) {
		
		ChangeWeaponSkin(myweapon, bulldogSkins, bulldogSkinOption);
	}
	else if (weapon_name.find("AutomaticPistol_C") != std::string::npos) {
		
		ChangeWeaponSkin(myweapon, frenzySkins, frenzySkinOption);
	}
	else if (weapon_name.find("DMR_C") != std::string::npos) {
	
		ChangeWeaponSkin(myweapon, guardianSkins, guardianSkinOption);
	}
	else if (weapon_name.find("RevolverPistol_C") != std::string::npos) {
		
		static int sheriff_champions = 0;
		if (!Globals::championssheriff) {
			ChangeWeaponSkin(myweapon, sheriffSkins, sheriffSkinOption);
		}
		else {
			ApplyWeaponSkin(myweapon, chamspions_sheriff, sheriff_champions);
		}
		
	}
	else if (weapon_name.find("LugerPistol_C") != std::string::npos) {
		
		ChangeWeaponSkin(myweapon, ghostSkins, ghostSkinOption);
	}
	else if (weapon_name.find("SubMachineGun_MP5_C") != std::string::npos) {
	
		ChangeWeaponSkin(myweapon, spectreSkins, spectreSkinOption);
	}
	else if (weapon_name.find("BasePistol_C") != std::string::npos) {
	
		ChangeWeaponSkin(myweapon, classicSkins, classicSkinOption);
	}
	else if (weapon_name.find("LeverSniperRifle_C") != std::string::npos) {
			
		ChangeWeaponSkin(myweapon, marshalSkins, marshalSkinOption);
	}
	else if (weapon_name.find("Ability_Melee_Base_C") != std::string::npos) {
		
		ChangeWeaponSkin(myweapon, knifeskins, knifeSkinOption);
	}
	else if (weapon_name.find("DS_Gun_C") != std::string::npos) {
			
		ApplyWeaponSkin(myweapon, outlawskins, outlawSkinOption);
	}
}
void ChangeKnown(AAresEquippable* myweapon) {
	UObject* skin_data_asset;
	UObject* chroma_data_asset;
	if (kismentsystemlibrary::get_object_name((UObject*)myweapon).ToString().find("AutomaticShotgun_C") != std::string::npos)
	{
		/*skin_data_asset = (UObject*)UObject::StaticFindObject(L"Default__AutomaticShotgun_Dragon_PrimaryAsset_C");
		chroma_data_asset = (UObject*)UObject::StaticFindObject(L"Default__AutomaticShotgun_Dragon_Blue_PrimaryAsset_C");*/
		/*skin_data_asset = (UObject*)UObject::StaticFindObject(L"Default__AutoShotgun_Sovereign2_PrimaryAsset_C");
		chroma_data_asset = (UObject*)UObject::StaticFindObject(L"Default__AutoShotgun_Sovereign1_v1_PrimaryAsset_C");*/

		skin_data_asset = (UObject*)UObject::StaticFindObject(L"Default__AutoShotgun_Cyberknight_PrimaryAsset_C");
		chroma_data_asset = (UObject*)UObject::StaticFindObject(L"Default__AutoShotgun_Cyberknight_v1_PrimaryAsset_C");
		Skin::ChangeSkin(myweapon, skin_data_asset, chroma_data_asset, 4 , UWorldSave);
	}

	if (kismentsystemlibrary::get_object_name((UObject*)myweapon).ToString().find("LightMachineGun_C") != std::string::npos)
	{
		skin_data_asset = (UObject*)UObject::StaticFindObject(L"Default__LMG_SOL_PrimaryAsset_C");
		chroma_data_asset = (UObject*)UObject::StaticFindObject(L"Default__LMG_SOL_Lv4_PrimaryAsset_C");
		Skin::ChangeSkin(myweapon, skin_data_asset, chroma_data_asset, 4, UWorldSave);
	}

	if (kismentsystemlibrary::get_object_name((UObject*)myweapon).ToString().find(("HeavyMachineGun_C")) != std::string::npos)
	{
		skin_data_asset = (UObject*)UObject::StaticFindObject(L"Default__HMG_Cyberknight_PrimaryAsset_C");
		chroma_data_asset = (UObject*)UObject::StaticFindObject(L"Default__HMG_Cyberknight_v1_PrimaryAsset_C");
		Skin::ChangeSkin(myweapon, skin_data_asset, chroma_data_asset, 4, UWorldSave);
	}

	if (kismentsystemlibrary::get_object_name((UObject*)myweapon).ToString().find("PumpShotgun_C") != std::string::npos)
	{
		skin_data_asset = (UObject*)UObject::StaticFindObject(L"Default__PumpShotgun_Oblivion_PrimaryAsset_C");
		chroma_data_asset = (UObject*)UObject::StaticFindObject(L"Default__PumpShotgun_OblivionLv4_PrimaryAsset_C");
		Skin::ChangeSkin(myweapon, skin_data_asset, chroma_data_asset, 4, UWorldSave);
	}

	if (kismentsystemlibrary::get_object_name((UObject*)myweapon).ToString().find("SawedOffShotgun_C") != std::string::npos)
	{
		skin_data_asset = (UObject*)UObject::StaticFindObject(L"Default__SawedOffShotgun_Oni_PrimaryAsset_C");
		chroma_data_asset = (UObject*)UObject::StaticFindObject(L"Default__SawedOffShotgun_Oni_Lv4_PrimaryAsset_C");
		Skin::ChangeSkin(myweapon, skin_data_asset, chroma_data_asset, 4, UWorldSave);
	}

	if (kismentsystemlibrary::get_object_name((UObject*)myweapon).ToString().find("Vector_C") != std::string::npos)
	{
		skin_data_asset = (UObject*)UObject::StaticFindObject(L"Default__Vector_Sovereign_PrimaryAsset_C");
		chroma_data_asset = (UObject*)UObject::StaticFindObject(L"Default__Vector_Sovereign_Lv4_PrimaryAsset_C");
		Skin::ChangeSkin(myweapon, skin_data_asset, chroma_data_asset, 4, UWorldSave);
	}
}

