	#pragma once
	#include "memory.h"
	#include "unrealengine.h"
	#include "Decryptor.h"
	#include "options.hpp"
	#include "Hookign/ret_spoofing.h"
	#include "Hookign/spoofer.h"
#include <algorithm>
#include <ctime> // needed for std::time, std::localtime
int index = 453;
int elements_count = 0;
FLinearColor HSVtoRGB2(float h, float s, float v)
{
	float R, G, B;

	int i = int(h * 6.0f);
	float f = h * 6.0f - i;
	float p = v * (1.0f - s);
	float q = v * (1.0f - f * s);
	float t = v * (1.0f - (1.0f - f) * s);

	switch (i % 6) {
	case 0: R = v; G = t; B = p; break;
	case 1: R = q; G = v; B = p; break;
	case 2: R = p; G = v; B = t; break;
	case 3: R = p; G = q; B = v; break;
	case 4: R = t; G = p; B = v; break;
	case 5: R = v; G = p; B = q; break;
	}

	return FLinearColor(R, G, B, 1.0f);
}
FLinearColor BOSSRAINBOMAW(float time)
{

	const float PI = 3.14159265359f;
	float R = 0.5f + 0.5f * sin(time);
	float G = 0.5f + 0.5f * sin(time + 2.0f * PI / 3.0f);
	float B = 0.5f + 0.5f * sin(time + 4.0f * PI / 3.0f);
	return FLinearColor(R, G, B, 1.0f);
}
float rainbowTimeZ = 0;
float rainbowTimeZRGB = 0;
enum class e_blend_mode : uint8_t
{
	opaque = 0,
	masked = 1,
	translucent = 2,
	additive = 3,
	modulate = 4,
	alpha_composite = 5,
	max = 6,
};
		struct FHitResult {
		int32_t FaceIndex; // 0x00(0x04)
		float Time; // 0x04(0x04)
		float Distance; // 0x08(0x04)
		float PenetrationDepth; // 0x54(0x04)
		int32_t Item; // 0x58(0x04)
		char ElementIndex; // 0x5c(0x01)
		char bBlockingHit : 1; // 0x5d(0x01)
		char bStartPenetrating : 1; // 0x5d(0x01)
		char pad_5D_2 : 6; // 0x5d(0x01)
		char pad_5E[0x2]; // 0x5e(0x02)
		struct FName BoneName; // 0x78(0x0c)
		struct FName MyBoneName; // 0x84(0x0c)
	};
	template<class type> class enum_as_byte {
	public:
		enum_as_byte() {}
		enum_as_byte(type value) : value(static_cast<std::uint8_t>(value)) {}

		explicit enum_as_byte(std::int32_t value) : value(static_cast<std::uint8_t>(value)) {}
		explicit enum_as_byte(std::uint8_t value) : value(value) {}

		operator type() const { return type(value); }
		type get() const { return type(value); }
		type* cast() {
			return reinterpret_cast<type*>(this);
		}
	private:
		std::uint8_t value;
	};

	static enum search_case : std::uint8_t {
		case_sensitive, ignore_case
	};
	struct SkinData {
		const wchar_t* SkinName;
		const wchar_t* skin;
		const wchar_t* chroma;
		int level;
	};

	namespace keys
	{
		fkey_ left_mouse;
		fkey_ right_mouse;
		fkey_ insert;

		fkey_ w;
		fkey_ A;
		fkey_ s;
		fkey_ d;

		fkey_ space;
		fkey_ capslock;
	}

	class UObject
	{
	public:


		char padding_01[0x18];
		int32_t ComparisonIndex;

		static UObject* StaticFindObject(const wchar_t* Name)
		{
			SPOOF_FUNC;
			static uintptr_t StaticFindObjectAddress = VALORANT::Module + Offsets::static_find_object;
			return reinterpret_cast<UObject * (__fastcall*)(UObject*, UObject*, const wchar_t*, bool, uintptr_t, void*)>(spoofcall_stub)(nullptr, reinterpret_cast<UObject*>(-1), Name, false, Offsets::MagicOffsets, (void*)StaticFindObjectAddress);
		}
		static UObject* StaticFindObject(UObject* Class, UObject* InOuter, const wchar_t* Name, bool ExactClass)
		{
			SPOOF_FUNC;
			static uintptr_t StaticFindObjectAddress = VALORANT::Module + Offsets::static_find_object;
			return reinterpret_cast<UObject * (__fastcall*)(UObject*, UObject*, const wchar_t*, bool, uintptr_t, void*)>(spoofcall_stub)(Class, InOuter, Name, ExactClass, Offsets::MagicOffsets, (void*)StaticFindObjectAddress);
		}

		template<typename type = UObject> static inline type find_object2(const wchar_t* name, UObject* outer = nullptr, bool exact = false) {
			SPOOF_FUNC;
			return reinterpret_cast<type>(UObject::StaticFindObject(nullptr, outer, name, exact));
		}

		template<typename type = UObject> static inline type* find_object(const wchar_t* name, UObject* outer = nullptr, bool exact = false) {
			SPOOF_FUNC;
			return reinterpret_cast<type*>(UObject::StaticFindObject(nullptr, outer, name, exact));
		}

		static void ProcessEvent(void* class_, UObject* function, void* params)
		{
			SPOOF_FUNC;
			static uintptr_t negritas = VALORANT::Module + Offsets::process_event;
			reinterpret_cast<void (*)(void*, UObject*, void*, uintptr_t, void*)>(spoofcall_stub)(class_, function, params, Offsets::MagicOffsets, (void*)negritas);
		}
		void ProcessEvent(void* class_, void* params)
		{
			SPOOF_FUNC;
			static uintptr_t negritas = VALORANT::Module + Offsets::process_event;
			reinterpret_cast<void (*)(void*, UObject*, void*, uintptr_t, void*)>(spoofcall_stub)(class_, this, params, Offsets::MagicOffsets, (void*)negritas);
		}

		void ProcessEvent_(UObject* function, void* params) {
			SPOOF_FUNC;
			static uintptr_t negritas = VALORANT::Module + Offsets::process_event;
			reinterpret_cast<void (*)(UObject*, UObject*, void*, uintptr_t, void*)>(spoofcall_stub)(this, function, params, Offsets::MagicOffsets, (void*)negritas);

		}

		static UObject* StaticLoadObject(const wchar_t* ObjectPath) {
			SPOOF_FUNC;
			if (!ObjectPath)
				return nullptr;


			static uintptr_t StaticLoadObjectAddress = VALORANT::Module + Offsets::static_load_object;
			return reinterpret_cast<UObject * (__fastcall*)(UObject*, UObject*, const wchar_t*, const wchar_t*, uint32_t, uint32_t, void*, uintptr_t, void*)>(spoofcall_stub)(nullptr, nullptr, ObjectPath, nullptr, 0, 0, nullptr, Offsets::MagicOffsets, (void*)StaticLoadObjectAddress);

		
		}
		template <typename type = UObject>
			type* cast() {
		return reinterpret_cast<type*>(this);
	}


	};

	struct UWorld
	{

	};
	UWorld* UWorldSave;
	struct UFont : UObject
	{

	};

	class fmemory {
	public:
		static uint64_t malloc(int32_t size, uint32_t aligment);
	};

	uint64_t fmemory::malloc(int32_t size, uint32_t aligment) {
		return reinterpret_cast<uint64_t(__cdecl*)(uint64_t, int)>(VALORANT::Module + Offsets::fmemory_malloc)(size, aligment);
	}

	UObject* DefaultMediumFont;
	struct UEngine
	{
		UObject* GetMediumFont()
		{
			SPOOF_FUNC;
			return Memory::R<UObject*>((uintptr_t)this + 0x88);
		}
	};

	bool bOutline = 0;
	bool InGame = 0;
	struct USkeletalMeshComponent
	{
		void GetMesh3P()
		{

			UObject* function = UObject::find_object2<UObject*>(ez(L"ShooterGame.AresEquippable.GetMesh3P").d());

			struct
			{
				USkeletalMeshComponent* Out;
			}Parameters;
			function->ProcessEvent(this, function, &Parameters);
			
		}
		void set_world_rotation(FVector NewRotation, bool bsweep, bool bteleport)
		{
			SPOOF_FUNC;
			static UObject* function = 0; if (!function) function = UObject::find_object2<UObject*>(ez(L"Engine.SceneComponent.K2_SetWorldRotation").d());

			if (function == nullptr)
				return;

			struct {
				FVector NewRotation;
				bool bsweep;
				uintptr_t FHitResult;
				bool bTeleport;
			} params = { NewRotation, bsweep, 0, bteleport };

			function->ProcessEvent_(function, &params);
		}
		void SetAresOutlineMode(EAresOutlineMode Mode, bool bPropagateToChildren)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.MeshComponent.SetAresOutlineMode").d();
			static UObject* Function;
			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
			{
				return;
			}
			struct
			{
				EAresOutlineMode Mode;
				bool bPropagateToChildren;
			} Parameters;
			Parameters.Mode = Mode;
			Parameters.bPropagateToChildren = bPropagateToChildren;
			Function->ProcessEvent(this, Function, &Parameters);
		}
		void SetMaterial(int32_t ElementIndex, UObject* Material) {

			UObject* function = UObject::find_object2<UObject*>(ez(L"Engine.PrimitiveComponent.SetMaterial").d());
			if (!function) {
				return;
			}

			struct {
				int32_t ElementIndex;
				UObject* Material;
			} Parameters;

			Parameters.ElementIndex = ElementIndex;
			Parameters.Material = Material;
			function->ProcessEvent_(function, &Parameters);
		}
		USkeletalMeshComponent* mesh3p() {
			static UObject* function;
			if (!function)
				function = UObject::find_object<UObject>(ez(L"ShooterGame.ShooterCharacter.GetCoreMesh3P").d());

			struct
			{
				USkeletalMeshComponent* output;
			} params;

			function->ProcessEvent_(function, &params);

			return params.output;
		}

		void SetOutlineMode(EAresOutlineMode Mode)
		{
			SPOOF_FUNC;
			auto function_name = (ez(L"ShooterGame.AresOutlineComponent.SetOutlineMode").d());
			static UObject* Function;
			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
			{
				return;
			}
			struct
			{
				EAresOutlineMode Mode;
			} Parameters;
			Parameters.Mode = Mode;
			Function->ProcessEvent(this, Function, &Parameters);
		}


	};

	struct UCanvas
	{
	
		void K2_DrawLine(struct FVector2D ScreenPositionA, struct FVector2D ScreenPositionB, float Thickness, struct FLinearColor RenderColor)
		{
			SPOOF_FUNC;
			auto function_name = (L"Engine.Canvas.K2_DrawLine");
			static UObject* function;
			if (!function)
				function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct
			{
				FVector2D ScreenPositionA;
				FVector2D ScreenPositionB;
				float Thickness;
				FLinearColor RenderColor;
			} Args;

			Args.ScreenPositionA = ScreenPositionA;
			Args.ScreenPositionB = ScreenPositionB;
			Args.Thickness = Thickness;
			Args.RenderColor = RenderColor;
			function->ProcessEvent(this, function, &Args);
		}

		void K2_DrawLinex(FVector2D ScreenPositionA, FVector2D ScreenPositionB, float Thickness, FLinearColor RenderColor)
		{
			SPOOF_FUNC;
			Thickness = 1.2f;
			if (bOutline)
			{
				K2_DrawLine({ ScreenPositionA.X + 1, ScreenPositionA.Y }, { ScreenPositionB.X, ScreenPositionB.Y }, Thickness, { 0.0f,0.0f,0.0f,1.0f });
				K2_DrawLine({ ScreenPositionA.X - 1, ScreenPositionA.Y }, { ScreenPositionB.X, ScreenPositionB.Y }, Thickness, { 0.0f,0.0f,0.0f,1.0f });
				K2_DrawLine({ ScreenPositionA.X, ScreenPositionA.Y + 1 }, { ScreenPositionB.X, ScreenPositionB.Y }, Thickness, { 0.0f,0.0f,0.0f,1.0f });
				K2_DrawLine({ ScreenPositionA.X, ScreenPositionA.Y - 1 }, { ScreenPositionB.X, ScreenPositionB.Y }, Thickness, { 0.0f,0.0f,0.0f,1.0f });
			}
			K2_DrawLine({ ScreenPositionA.X, ScreenPositionA.Y }, { ScreenPositionB.X, ScreenPositionB.Y }, Thickness, RenderColor);
		}

		void K2_DrawText_2(struct FString RenderText, struct FVector2D ScreenPosition, struct FVector2D Scale, struct FLinearColor RenderColor, float Kerning, struct FVector2D ShadowOffset, bool bCentreX, bool bCentreY)
		{
			SPOOF_FUNC;
			auto function_name = (L"Engine.Canvas.K2_DrawText");
			static UObject* function;
			if (!function)
				function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!DefaultMediumFont)
				DefaultMediumFont = UObject::StaticFindObject(nullptr, nullptr, (L"Font'/Engine/EngineFonts/Roboto.Roboto'"), false);

			struct
			{	
				UObject* RenderFont;
				FString RenderText;
				FVector2D ScreenPosition;
				FVector2D Scale;
				FLinearColor RenderColor;
				float Kerning;
				FLinearColor ShadowColor;
				FVector2D ShadowOffset;
				bool bCentreX;
				bool bCentreY;
				FLinearColor OutlineColor;
			} Args;

			Args.RenderFont = DefaultMediumFont;
			Args.RenderText = RenderText;
			Args.ScreenPosition = ScreenPosition;
			Args.Scale = Scale;
			Args.RenderColor = RenderColor;
			Args.Kerning = Kerning;
			Args.ShadowOffset = ShadowOffset;
			Args.bCentreX = bCentreX;
			Args.bCentreY = bCentreY;
			function->ProcessEvent(this, function, &Args);
		}
		
		



		void K2_DrawText(struct FString RenderText, struct FVector2D ScreenPosition, struct FVector2D Scale, struct FLinearColor RenderColor, float Kerning, struct FLinearColor ShadowColor, struct FVector2D ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, struct FLinearColor OutlineColor)
		{
			SPOOF_FUNC;
			auto function_name = (L"Engine.Canvas.K2_DrawText");
			static UObject* function;
			if (!function)
				function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);
			if (!DefaultMediumFont)
				DefaultMediumFont = UObject::StaticFindObject(nullptr, nullptr, (L"Font'/Engine/EngineFonts/Roboto.Roboto'"), false);
			struct
			{
				UObject* RenderFont;
				FString RenderText;
				FVector2D ScreenPosition;
				FVector2D Scale;
				FLinearColor RenderColor;
				float Kerning;
				FLinearColor ShadowColor;
				FVector2D ShadowOffset;
				bool bCentreX;
				bool bCentreY;
				bool bOutlined;
				FLinearColor OutlineColor;
			} Args;

			Args.RenderFont = DefaultMediumFont;
			Args.RenderText = RenderText;
			Args.ScreenPosition = ScreenPosition;
			Args.Scale = Scale;
			Args.RenderColor = RenderColor;
			Args.Kerning = Kerning;
			Args.ShadowColor = ShadowColor;
			Args.ShadowOffset = ShadowOffset;
			Args.bCentreX = bCentreX;
			Args.bCentreY = bCentreY;
			Args.bOutlined = bOutlined;
			Args.OutlineColor = OutlineColor;
			function->ProcessEvent(this, function, &Args);
		}

		FVector2D GetScreenSize() {
			return FVector2D(Memory::R<int32_t>(std::uintptr_t(this) + 0x48), Memory::R<int32_t>(std::uintptr_t(this) + 0x4c));
		}
	};


	struct UGameInstance
	{
		struct ULocalPlayer* LocalPlayer()
		{
			SPOOF_FUNC;
			const auto localplayers = Memory::R<ULocalPlayer*>((uintptr_t)this + 0x40);
			return Memory::R<ULocalPlayer*>((uintptr_t)localplayers);
		}
		UEngine* GetUEngine()
		{
			SPOOF_FUNC;
			return Memory::R<UEngine*>((uintptr_t)this + 0x28);
		}
	};

	struct ULocalPlayer
	{
		struct UGameViewportClient* ViewportClient()
		{
			SPOOF_FUNC;
			return Memory::R<UGameViewportClient*>((uintptr_t)this + 0x78);
		}
		struct APlayerController* GetController()
		{
			SPOOF_FUNC;
			return Memory::R<APlayerController*>((uintptr_t)this + 0x38);
		};
	};
	struct UGameViewportClient
	{
		UWorld* GetUWorld()
		{
			SPOOF_FUNC;
			return Memory::R<UWorld*>((uintptr_t)this + 0x80);
		}
		UGameInstance* GetGameInstance()
		{
			SPOOF_FUNC;
			return Memory::R<UGameInstance*>((uintptr_t)this + 0x88);
		}
	};

	struct FBoxSphereBounds {
		FVector Origin;
		FVector BoxExtent;
		float SphereRadius;
	};

	namespace AresOutlineComponent
	{
		UObject* Static_Class()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"ShooterGame.Default__AresOutlineComponent").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}

		void SetOutlineMode(EAresOutlineMode OutlineMode)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresOutlineComponent.SetOutlineMode").d();
			static UObject* Function;
			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
			{
				return;
			}

			struct
			{
				EAresOutlineMode OutlineMode;
			} Parameters;

			Parameters.OutlineMode = OutlineMode;
			Function->ProcessEvent(Static_Class(), Function, &Parameters);
		}
	}

	struct UAresOutlineComponent
	{
		UObject* Static_Class()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"ShooterGame.Default__AresOutlineComponent").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}

		void SetOutlineMode(EAresOutlineMode OutlineMode)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresOutlineComponent.SetOutlineMode").d();
			static UObject* Function;
			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
			{
				return;
			}

			struct
			{
				EAresOutlineMode OutlineMode;
			} Parameters;

			Parameters.OutlineMode = OutlineMode;
			Function->ProcessEvent(Static_Class(), Function, &Parameters);
		}
	};

	DWORD64 ProjectWorldToScreen;

	struct APlayerState
	{
		FString GetPlayerName()
		{SPOOF_FUNC;
			auto function_name = ez(L"Engine.PlayerState.GetPlayerName").d();
			static UObject* function;
			if (!function)
				function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!function)
				return ez(L"AAresPlayerCharacter_PC_C").d();

			struct
			{
				FString Return;
			} Args;

			function->ProcessEvent(this, function, &Args);
			return Args.Return;
		}
	};



	struct FQuat
	{
	public:

		float X, Y, Z, W;

		FQuat() : X(0.f), Y(0.f), Z(0.f), W(0.f) {};

		FQuat(float InX, float InY, float InZ, float InW) : X(InX), Y(InY), Z(InZ), W(InW) {}

		FQuat(struct FRotator& R);

		FVector RotateVector(const struct FVector& V) const;
	};
	struct FRotator
	{
		float Pitch, Yaw, Roll;

		FRotator()
			: Pitch(0), Yaw(0), Roll(0)
		{
		}

		FRotator(float pitch, float yaw, float roll) : Pitch(pitch), Yaw(yaw), Roll(roll) {}

		FRotator operator+ (const FRotator& other) const { return FRotator(Pitch + other.Pitch, Yaw + other.Yaw, Roll + other.Roll); }

		FRotator operator- (const FRotator& other) const { return FRotator(Pitch - other.Pitch, Yaw - other.Yaw, Roll - other.Roll); }

		FRotator operator* (float scalar) const { return FRotator(Pitch * scalar, Yaw * scalar, Roll * scalar); }

		FRotator& operator=  (const FRotator& other) { Pitch = other.Pitch; Yaw = other.Yaw; Roll = other.Roll; return *this; }

		FRotator& operator+= (const FRotator& other) { Pitch += other.Pitch; Yaw += other.Yaw; Roll += other.Roll; return *this; }

		FRotator& operator-= (const FRotator& other) { Pitch -= other.Pitch; Yaw -= other.Yaw; Roll -= other.Roll; return *this; }

		FRotator& operator*= (const float other) { Yaw *= other; Pitch *= other; Roll *= other; return *this; }

		struct FQuat Quaternion() const;
	};

	constexpr auto PI = 3.1415926535897932f;
	constexpr auto FLOAT_NON_FRACTIONAL = 8388608.f /* All single-precision floating point numbers greater than or equal to this have no fractional value. */;
	constexpr auto INV_PI = 0.31830988618f;
	constexpr auto HALF_PI = 1.57079632679f;
	constexpr auto DEG_TO_RAD = PI / 180.f;
	constexpr auto RADS_DIVIDED_BY_2 = DEG_TO_RAD / 2.f;

	namespace classes {
		namespace defines {
			static UObject* system = nullptr;
			static UObject* game_statics = nullptr;
			static UObject* blueprint = nullptr;
			static UObject* content_library = nullptr;
			static UObject* text_library = nullptr;
			static UObject* material_library = nullptr;
		}

		static inline void init()
		{
			SPOOF_FUNC;
			auto game_statics_name = (L"Engine.Default__GameplayStatics");
			auto blueprint_name = (L"ShooterGame.Default__ShooterBlueprintLibrary");
			auto content_library_name = (L"ShooterGame.Default__ContentLibrary");
			auto system_name = (L"Engine.Default__KismetSystemLibrary");
			auto text_library_name = (L"Engine.Default__KismetStringLibrary");

			defines::game_statics = UObject::StaticFindObject(nullptr, nullptr, game_statics_name, false);
			defines::blueprint = UObject::StaticFindObject(nullptr, nullptr, blueprint_name, false);
			defines::content_library = UObject::StaticFindObject(nullptr, nullptr, content_library_name, false);
			defines::system = UObject::StaticFindObject(nullptr, nullptr, system_name, false);
			defines::text_library = UObject::StaticFindObject(nullptr, nullptr, text_library_name, false);
		}

	}

	namespace kismentsystemlibrary
	{
		UObject* static_class()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"Engine.Default__KismetSystemLibrary").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}
	
		FString get_object_name(UObject* obj)
		{
			SPOOF_FUNC;
			auto function_name = (L"Engine.KismetSystemLibrary.GetObjectName");
			static UObject* functions;
			if (!functions)
				functions = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct
			{
				UObject* obj;
				FString out;
			} Args;

			Args.obj = obj;
			functions->ProcessEvent(static_class(), functions, &Args);
			return Args.out;
		}





		static inline UObject* get_outer_object(UObject* object)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.KismetSystemLibrary.GetOuterObject").d();
			static UObject* functions;
			if (!functions)
				functions = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct
			{
				UObject* object;
				UObject* return_value;
			} params = { object };

			functions->ProcessEvent(static_class(), &params);
			return params.return_value;
		}

		UObject* static_class_string()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"Engine.Default__KismetStringLibrary").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}

		FName_ Conv_StringToName(FString InString)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.KismetStringLibrary.Conv_StringToName").d();
			static UObject* Function = nullptr;
			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct
			{
				FString InString;
				FName_ ReturnValue;
			} Params = { InString };

			classes::defines::text_library->ProcessEvent(static_class_string(), Function, &Params);

			return Params.ReturnValue;
		}

		FString TextToString(FText str)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.KismetTextLibrary.Conv_TextToString").d();
			static UObject* Function;
			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct
			{
				FText string;
				FString out;
			} Args;

			Args.string = str;
			Function->ProcessEvent(static_class(), Function, &Args);
			return Args.out;
		}

		static inline bool contains(const wchar_t* search_in, const wchar_t* sub_string, bool use_case = false, bool search_from_end = false)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.KismetStringLibrary.Contains").d();
			struct
			{
				FString search_in;
				FString sub_string;
				bool use_case;
				bool search_from_end;
				bool return_value;
			} params = { search_in, sub_string, use_case, search_from_end };

			classes::defines::text_library->ProcessEvent_(UObject::find_object(function_name), &params), function_name;

			return params.return_value;
		}
	}


	struct FMath {
		static __forceinline void SinCos(float* ScalarSin, float* ScalarCos, float  Value);
		static __forceinline float Fmod(float X, float Y);
		template<class T>
		static __forceinline T Clamp(const T X, const T Min, const T Max) { return X < Min ? Min : X < Max ? X : Max; }
		template<class T>
		static __forceinline T Min(const T A, const T B) { return A < B ? A : B; }
		template<class T>
		static __forceinline T Max(const T A, const T B) { return A > B ? A : B; }
		template<class T>
		static __forceinline T Lerp(const T A, const T B, const float Alpha) { return A + Alpha * (B - A); }
	};
	struct FTransform
	{
		FQuat Rotation;
		FVector Translation;
		char UnknownData00[0x4];
		FVector Scale3D;
		char UnknownData01[0x4];

		/** Default constructor. */
		FTransform() : Rotation(0.f, 0.f, 0.f, 1.f), Translation(0.f), Scale3D(FVector::OneVector) {};

		FVector TransformPosition(FVector& V) const;

		FTransform(const FRotator& InRotation) : Rotation(InRotation.Quaternion()), Translation(FVector::ZeroVector), Scale3D(FVector::OneVector) {};
	};

	enum EBlendMode : uint8
	{
		BLEND_Opaque = 0,
		BLEND_Masked = 1,
		BLEND_Translucent = 2,
		BLEND_Additive = 3,
		BLEND_Modulate = 4,
		BLEND_AlphaComposite = 5,
		BLEND_MAX = 6,
	};

	struct UMaterialInstance : UObject
	{
	public:
		e_blend_mode GetBlendMode();

	};

	struct UMaterialInstanceDynamic : UMaterialInstance {
		e_blend_mode GetBlendMode() {

			UObject* function = UObject::find_object2<UObject*>(ez(L"MaterialInterface.GetBlendMode").d());

			struct {
				e_blend_mode ReturnValue;
			} Params = {  };

			this->ProcessEvent_(function, &Params);

			return Params.ReturnValue;
		}
	
		void SetVectorParameterValue(FName_ ParameterName, FLinearColor Value)
		{
			SPOOF_FUNC;
			static UObject* Function;

			if (!Function) Function = UObject::StaticFindObject(ez(L"MaterialInstanceDynamic.SetVectorParameterValue").d());

			struct {
				FName_ ParameterName;
				int shift;
				FLinearColor Value;
			} Params = { ParameterName, 0, Value };

			this->ProcessEvent(this, Function, &Params);
		}

		void SetScalarParameterValue(FName_ ParameterName, float Value) {
			SPOOF_FUNC;
			static UObject* Function = nullptr;
			if (!Function) {
				Function = UObject::StaticFindObject(ez(L"MaterialInstanceDynamic.SetScalarParameterValue").d());
			}

			struct {
				FName_ ParameterName;
				int shift;
				float Value;
			} Params = { ParameterName,0, Value };

			this->ProcessEvent(this, Function, &Params);
		}

		void SetTextureParameterValue(struct FName_ ParameterName, UObject* Texture) {

			static UObject* Function = 0;
			if (!Function) Function = UObject::StaticFindObject(ez(L"MaterialInstanceDynamic.SetTextureParameterValue").d());

			struct {
				FName_ ParameterName;
				int shift;
				UObject* Value;
			}Params = { ParameterName, 0, Texture };

			this->ProcessEvent(this, Function, &Params);
		}
	};

	struct UPrimitiveComponent : UObject {

		UObject* create_and_set_material_instance_dynamic_from_material(int32_t element_index, UObject* parent) {
			if (!this || !parent) return nullptr;

			static UObject* fn = nullptr;
			if (!fn)
				fn = UObject::find_object2<UObject*>(L"Engine.PrimitiveComponent.CreateAndSetMaterialInstanceDynamicFromMaterial");

			struct {
				int32_t element_index;
				UObject* parent;
				UObject* return_value;
			} params = { element_index, parent };

			this->ProcessEvent(fn, &params);
			return params.return_value;
		}
		void SetMaterial(int32_t ElementIndex, UObject* Material)
		{
			SPOOF_FUNC;
			static UObject* Function = 0;
			if (!Function) Function = this->StaticFindObject(ez(L"Engine.PrimitiveComponent.SetMaterial").d());

			struct {
				int32_t ElementIndex;
				UObject* Material;
			} Params = { ElementIndex, Material };

			this->ProcessEvent(this, Function, &Params);
		}

		UMaterialInstanceDynamic* GetMaterial(int32_t ElementIndex)
		{
			static UObject* Function = 0;
			if (!Function) Function = this->StaticFindObject(ez(L"Engine.PrimitiveComponent.GetMaterial").d());

			struct {
				int32_t ElementIndex;
				UMaterialInstanceDynamic* ReturnValue;
			} Params = { ElementIndex };

			this->ProcessEvent(this, Function, &Params);

			return Params.ReturnValue;
		}

		int32_t GetNumMaterials()
		{
			SPOOF_FUNC;
			static UObject* Function = 0;
			if (!Function) Function = this->StaticFindObject(ez(L"Engine.PrimitiveComponent.GetNumMaterials").d());

			struct {
				int32_t ReturnValue;
			} Params = { };

			this->ProcessEvent(this, Function, &Params);

			return Params.ReturnValue;
		}

	};


	bool starts_with(const wchar_t* source, const wchar_t* prefix, const enum_as_byte<search_case>& search_case = ignore_case) {
		SPOOF_FUNC;
		UObject* niggersmeow = UObject::find_object2<UObject*>(ez(L"Engine.Default__KismetStringLibrary").d());
		static UObject* function;
		if (!function)
			function = UObject::find_object2<UObject*>(ez(L"Engine.KismetStringLibrary.StartsWith").d());

		struct {
			FString source;
			FString prefix;
			std::uint8_t search_case;
			bool return_value;
		} params = { source, prefix, search_case.get() };

		niggersmeow->ProcessEvent_(function, &params);

		return params.return_value;
	}

	struct AAresEquippable : UObject
	{
		struct type {
		
			const wchar_t* search = nullptr;
			const char* config = nullptr;
			std::int32_t index = 0;

			const bool is_valid() const noexcept {
				return this->search != nullptr || this->config != nullptr;
			}
		};

		struct USkeletalMeshComponent* GetEquippableMesh()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresEquippable.GetEquippableMesh").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				struct USkeletalMeshComponent* Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}
		USkeletalMeshComponent* GetMesh3P()
		{

			UObject* function = UObject::find_object2<UObject*>(ez(L"ShooterGame.AresEquippable.GetMesh3P").d());

			struct
			{
				USkeletalMeshComponent* Out;
			}Parameters;
			function->ProcessEvent(this, function, &Parameters);
			return Parameters.Out;
		}
		USkeletalMeshComponent* GetMesh1P()
		{

			UObject* function = UObject::find_object2<UObject*>(ez(L"ShooterGame.AresEquippable.GetMesh1P").d());

			struct
			{
				USkeletalMeshComponent* Out;
			}Parameters;
			function->ProcessEvent(this, function, &Parameters);
			return Parameters.Out;
		}
		struct skin_data_asset* GetSkinDataAsset()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresEquippable.GetEquippableSkinDataAsset").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				struct skin_data_asset* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		static inline AAresEquippable::type types[] = {
				{ L"basepistol", "classic" },
				{ L"sawedoffshotgun", "shorty" },
				{ L"automaticpistol", "frenzy" },
				{ L"lugerpistol", "ghost" },
				{ L"revolverpistol", "sheriff" },

				{ L"vector", "stinger" },
				{ L"submachinegun_mp5", "spectre" },

				{ L"pumpshotgun", "bucky" },
				{ L"automaticshotgun", "judge" },

				{ L"assaultrifle_burst", "bulldog" },
				{ L"dmr", "guardian" },
				{ L"assaultrifle_acr", "phantom" },
				{ L"assaultrifle_ak", "vandal" },

				{ L"leversniperrifle", "marshal" },
				{ L"boltsniper", "operator" },

				{ L"lightmachinegun", "ares" },
				{ L"heavymachinegun", "odin" },

				{ L"ability_melee_base", "knife" },

				{ L"gun_sprinter_x_heavylightninggun_production", "neon_x" },
				{ L"ability_wushu_x_dagger_production", "jett_dagger" }
		};

		AAresEquippable::type get_type() {
			SPOOF_FUNC;
			const FString& name = kismentsystemlibrary::get_object_name(this);

			for (std::int32_t index = 0; index < sizeof(AAresEquippable::types) / sizeof(AAresEquippable::type); index++) {
				AAresEquippable::type type = AAresEquippable::types[index];

				if (type.index == 0)
					type.index = index;

				if (starts_with(name.c_str(), type.search))
					return { type.search, type.config, type.index };

			}

			return {};

		}
	};

	struct UAresInventory : UObject
	{
		AAresEquippable* GetCurrentWeapon()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresInventory.GetCurrentEquippable").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				AAresEquippable* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
	};

	struct AShooterCharacter : UObject
	{
		bool dormant;
		UObject* get_character_icon()
		{

			static UObject* function;
			if (!function)
				function = UObject::find_object2<UObject*>(ez(L"ShooterGame.ShooterCharacter.GetCharacterIcon").d());

			struct
			{
				UObject* Out;
			} params;

			this->ProcessEvent_(function, &params);
			return params.Out;
		}
		void k2_drawtexture(UObject* texture, FVector2D screen_position, FVector2D screen_size, FVector2D coordinate_position, FVector2D coordinate_size, FLinearColor render_color, e_blend_mode blend_mode, float rotation, FVector2D pivot_point)
		{
			SPOOF_FUNC;
			static UObject* function;
			if (!function)
				function = UObject::find_object2<UObject*>(ez(L"Engine.Canvas.K2_DrawTexture").d());

			struct {
				UObject* texture;
				FVector2D screen_position;
				FVector2D screen_size;
				FVector2D coordinate_position;
				FVector2D coordinate_size;
				FLinearColor render_color;
				e_blend_mode blend_mode;
				float rotation;
				FVector2D pivot_point;
			} params;
			params.texture = texture;
			params.screen_position = screen_position;
			params.screen_size = screen_size;
			params.coordinate_position = coordinate_position;
			params.coordinate_size = coordinate_size;
			params.render_color = render_color;
			params.blend_mode = blend_mode;
			params.rotation = rotation;
			params.pivot_point = pivot_point;

			this->ProcessEvent_(function, &params);
		}
		FRotator K2_SetActorRotation(FRotator NewRotation, bool bTeleportPhysics)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Actor.K2_SetActorRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return { 0, 0, 0 };

			struct {
				FRotator NewRotation;
				bool bTeleportPhysics;
				FRotator Out;
			} Parameters;

			Parameters.NewRotation = NewRotation;
			Parameters.bTeleportPhysics = bTeleportPhysics;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
		void K2_SetActorRelativeRotationnigger(struct FRotator NewRelativeRotation, bool bSweep, bool bTeleport)
		{

			static UObject* Function;
			if (!Function)
				Function = UObject::find_object2<UObject*>(ez(L"Engine.Actor.K2_SetActorRelativeRotation").d());

			struct
			{
				struct FRotator NewRelativeRotation;
				bool bSweep;
				bool bTeleport;
			}Parameters;
			Parameters.NewRelativeRotation = NewRelativeRotation;
			Parameters.bSweep = bSweep;
			Parameters.bTeleport = bTeleport;
			this->ProcessEvent_(Function, &Parameters);
		}
		bool IsDormant()
		{
			SPOOF_FUNC;
			return this->dormant;
		}

		bool IsDeadAndSettled()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.IsDeadAndSettled").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return false;

			struct {
				bool Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}

		bool WasRecentlyRendered(float Tolerance)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Actor.WasRecentlyRendered").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return false;

			struct {
				float Tolerance;
				bool Out;
			} Args;

			Args.Tolerance = Tolerance;
			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}

		UAresInventory* GetInventory()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetInventory").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				UAresInventory* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		UObject* FindClass()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"ShooterGame.Default__ContentLibrary").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}

		bool CanJump()
		{
			SPOOF_FUNC;
			static UObject* function;
			if (!function)
				function = this->StaticFindObject(0, 0, L"Character.CanJump", false);

			struct { bool ret; } params;

			this->ProcessEvent_(function, &params);
			return params.ret;
		}
		void SetCrouchTimeOverride(float Override)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.SetCrouchTimeOverride").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				float Override;
			} Parameters;

			Parameters.Override = Override;
			Function->ProcessEvent(this, Function, &Parameters);
		}

		void Set3pMeshVisible(bool value)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.Set3PMeshVisible").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = this->StaticFindObject(nullptr, nullptr, function_name, false);

			struct { bool a1; } params;
			params.a1 = value;

			this->ProcessEvent_(Function, &params);
		}

		bool ClearWeaponComponents(UObject* equippable)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ContentLibrary.ClearWeaponComponents").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return false;

			struct {
				UObject* equippable;
				UObject* skindata;
				UObject* chromadata;
				int skinlevel;
				UObject* charmdata;
				int charm_level;
			} Parameters = { equippable };

			UObject::ProcessEvent(FindClass(), Function, &Parameters);
		}

		bool ApplySkin(UObject* equippable, UObject* skindata, UObject* chromadata, int skinlevel, UObject* charmdata, int charm_level)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ContentLibrary.ApplySkin").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return false;

			struct {
				UObject* equippable;
				UObject* skindata;
				UObject* chromadata;
				int skinlevel;
				UObject* charmdata;
				int charm_level;
			} Parameters = { equippable, skindata, chromadata, skinlevel, charmdata, charm_level };

			UObject::ProcessEvent(FindClass(), Function, &Parameters);
		}

		void SetControlRotation(FVector NewRot)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Controller.SetControlRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				FVector Rot;
			} Parameters;

			Parameters.Rot = NewRot;
			Function->ProcessEvent(this, Function, &Parameters);
		}

		APlayerState* GetPlayerState()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetPlayerState").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				APlayerState* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		int32_t GetMaxHealth()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetMaxHealth").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return 0;

			struct {
				int32_t Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		float GetMaxShield()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetMaxShield").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return 0;

			struct {
				float Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		float GetHealth()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetHealth").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return 0;

			struct {
				float Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		float GetShield()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetShield").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return 0;

			struct {
				float Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		FVector K2_GetActorLocation()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Actor.K2_GetActorLocation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return { 0, 0, 0 };

			struct {
				FVector Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		USkeletalMeshComponent* GetPawnMesh()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetPawnMesh").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				USkeletalMeshComponent* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
	/*	void get_mesh() {

			static UObject* function;
			if (!function)
				function = UObject::find_object2<UObject*>((L"ShooterGame.ShooterCharacter.GetPawnMesh"));
			static UObject* function = nullptr;
			struct
			{
				USkeletalMeshComponent* output;
			} params;

			this->ProcessEvent_(function, &params);

			return params.output;
		}*/

		USkeletalMeshComponent* GetPawnMesh2()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetPawnMesh").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				USkeletalMeshComponent* Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}

		USkeletalMeshComponent* GetOverlayMesh1P()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetOverlayMesh1P").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				USkeletalMeshComponent* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		APlayerState* GetState()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetPlayerState").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				APlayerState* KekState;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.KekState;
		}

		bool IsAlive()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.IsAlive").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return false;

			struct {
				bool Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
	};

	struct APlayerCameraManager
	{
	
		FVector GetCameraLocation()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.PlayerCameraManager.GetCameraLocation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return { 0, 0, 0 };

			struct {
				FVector Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		FVector GetCameraRotation()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.PlayerCameraManager.GetCameraRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return { 0, 0, 0 };

			struct {
				FVector Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}
	};

	struct APawn : UObject
	{
		FVector GetControlRotation()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Pawn.GetControlRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return { 0, 0, 0 };

			struct {
				FVector Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}

		void k2_set_actor_relative_rotation(struct FRotator NewRotation, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"SceneComponent.K2_SetRelativeRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				FRotator a1;
				bool a2;
				int a3;
				bool a4;
			} params;

			params.a1 = NewRotation;
			params.a2 = bSweep;
			params.a4 = bTeleport;

			Function->ProcessEvent_(Function, &params);
		}
	
		void K2_SetRelativeRotation(FRotator NewRotation, bool bSweep, FHitResult& SweepHitResult, bool bTeleport)
		{
			UObject* function = UObject::StaticFindObject(nullptr, nullptr, ez(L"Engine.SceneComponent.K2_SetRelativeRotation").d(), false);

			struct {
				FRotator NewRotation;
				bool bSweep;
				FHitResult SweepHitResult;
				bool bTeleport;
			}Args;
			Args.NewRotation = NewRotation;
			Args.bSweep = bSweep;
			Args.SweepHitResult = SweepHitResult;
			Args.bTeleport = bTeleport;
			function->ProcessEvent(this, function, &Args);
		}
		bool set_actor_rotation	(FRotator new_rotation, bool teleport_physics) {
			SPOOF_FUNC;
			static UObject* function;
			if (!function) function = UObject::StaticFindObject(nullptr, nullptr, ez(L"Engine.Actor.K2_SetActorRelativeRotation").d(), false);
			struct {
				FRotator new_rotation;
				bool teleport_physics;
				bool return_value;
			} params = { new_rotation, teleport_physics };


			function->ProcessEvent(this, function, &params);
			return params.return_value;
		}
		USkeletalMeshComponent* GetOverlayMesh1P()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterCharacter.GetOverlayMesh1P").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				USkeletalMeshComponent* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
	};

	struct APlayerController : UObject
	{
		void ClientForceSetControlRotation(FRotator NewRotation)
		{
			auto function_name = ez(L"ShooterGame.AresPlayerController.ClientForceSetControlRotation").d();
			UObject* function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				FRotator NewRotation;
			} Args;
			Args.NewRotation = NewRotation;
			function->ProcessEvent(this, function, &Args);
		}
		FVector2D ProjectWorldToScreen(FVector WorldLocation)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.PlayerController.ProjectWorldLocationToScreen").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return FVector2D();

			struct {
				FVector WorldLocation;
				FVector2D OutLocation;
				bool bRelativeForViewPort;
			} Args;

			Args.WorldLocation = WorldLocation;
			Args.bRelativeForViewPort = true;
			Function->ProcessEvent(this, Function, &Args);
			return Args.OutLocation;
		}

		APlayerCameraManager* GetPlayerCameraManager()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresPlayerController.GetPlayerCameraManager").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				APlayerCameraManager* Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}

		AShooterCharacter* K2_GetPawn_in()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Controller.K2_GetPawn").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				AShooterCharacter* Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}

		APawn* K2_GetPawn()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Controller.K2_GetPawn").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				APawn* Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}
		APawn* get_acknowledged_pawn() {

			static UObject* function;
			if (!function)
				function = UObject::find_object2<UObject*>(ez(L"Engine.Controller.K2_GetPawn").d());

			struct
			{
				APawn* output;
			} params;

			this->ProcessEvent_(function, &params);
			return params.output;
		}
		APawn* K2_GetWeapon()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresEquippable.GetMesh1P").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				APawn* Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}

		bool LineOfSightTo(AShooterCharacter* Actor, FVector ViewPoint, bool bAlternateChecks)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Controller.LineOfSightTo").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return false;

			struct {
				AShooterCharacter* Actor;
				FVector ViewPoint;
				bool bAlternateChecks;
				bool Out;
			} Parameters;

			Parameters.Actor = Actor;
			Parameters.ViewPoint = ViewPoint;
			Parameters.bAlternateChecks = bAlternateChecks;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		bool LineOfSightTo(AShooterCharacter* Enemy)
		{
			SPOOF_FUNC;
			auto function_name = (L"Engine.Controller.LineOfSightTo");
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				AShooterCharacter* Enemy;
				FVector ViewPoint;
				bool bAlternateCheck;
				bool ReturnValue;
			} Args;

			Args.Enemy = Enemy;
			Args.ViewPoint = FVector(0, 0, 0);
			Args.bAlternateCheck = false;
			Function->ProcessEvent(this, Function, &Args);
			return Args.ReturnValue;
		}

		void simulate_input_key(fkey_ key, bool bpressed) {
			SPOOF_FUNC;
			static UObject* function;
			if (!function)
				function = this->StaticFindObject(0, 0, L"AresPlayerController.SimulateInputKey", false);

			struct { fkey_ a1; bool a2; } params;
			params.a1 = key;
			params.a2 = bpressed;

			this->ProcessEvent_(function, &params);
			return;
		}
		float GetMouseSensitivity()
		{

			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, ez(L"ShooterGame.ShooterPlayerController.GetMouseSensitivity").d(), false);

			if (!Function)
			{
				return 0;
			}
			struct
			{
				float Out;
			}Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
		void GetInputMouseDelta(float& DeltaX, float& DeltaY)
		{

			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, ez(L"Engine.PlayerController.GetInputMouseDelta").d(), false);

			if (!Function)
			{
				return;
			}
			struct
			{
				float DeltaX;
				float DeltaY;
			}Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			DeltaX = Parameters.DeltaX;
			DeltaY = Parameters.DeltaY;
		}
		FVector GetControlRotation()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Controller.GetControlRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return { 0, 0, 0 };

			struct {
				FVector Rot;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Rot;
		}

		void SetControlRotationRage(FRotator NewRot)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Controller.SetControlRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				FRotator Rot;
			} Parameters;

			Parameters.Rot = NewRot;
			Function->ProcessEvent(this, Function, &Parameters);
		}

		void ClientForceSetControlRotation2(FRotator NewRotation)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresPlayerController.ClientForceSetControlRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				FRotator NewRotation;
			} Args;

			Args.NewRotation = NewRotation;
			Function->ProcessEvent(this, Function, &Args);
		}

		void SetControlRotation(FVector NewRot)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.Controller.SetControlRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				FVector Rot;
			} Parameters;

			Parameters.Rot = NewRot;
			Function->ProcessEvent(this, Function, &Parameters);
		}

		bool ProjectWorldLocationToScreen(struct FVector WorldLocation, struct FVector2D& ScreenLocation, bool bPlayerViewportRelative)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.PlayerController.ProjectWorldLocationToScreen").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				FVector WorldLocationn;
				FVector2D ScreenLocationn;
				bool bPlayerViewportRelativee;
				bool return_value;
			} Args;

			Args.WorldLocationn = WorldLocation;
			Args.bPlayerViewportRelativee = bPlayerViewportRelative;

			Function->ProcessEvent(this, Function, &Args);

			ScreenLocation = Args.ScreenLocationn;

			return Args.return_value;
		}

		bool IsInputKeyDown(fkey_ key)
		{
			SPOOF_FUNC;
			static UObject* Function;
			if (!Function) Function = this->StaticFindObject(0, 0, ez(L"PlayerController.IsInputKeyDown").d(), false);

			struct
			{
				fkey_ key;
				bool ReturnValue;
			} params = { key };

			this->ProcessEvent_(Function, &params);

			return params.ReturnValue;
		}

		void set_fov(float fov)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresPlayerController.SetFOV").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				float fov;
			} Args;

			Args.fov = fov;
			Function->ProcessEvent(this, Function, &Args);
		}

		AShooterCharacter* GetShooterCharacter()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresPlayerController.GetShooterCharacter").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return nullptr;

			struct {
				AShooterCharacter* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		void DisconnectFromServer()
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.AresPlayerController.DisconnectFromServer").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return;

			Function->ProcessEvent(this, Function, nullptr);
		}
	};


	namespace ShooterGameBlueprints
	{
		UObject* Static_Class()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"ShooterGame.Default__ShooterBlueprintLibrary").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}

		APlayerController* GetFirstLocalPlayerController(UWorld* WorldContextObject)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterBlueprintLibrary.GetFirstLocalPlayerController").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
			{
				return nullptr;
			}

			struct
			{
				UWorld* WorldContextObject;
				APlayerController* Out;
			} Parameters;

			Parameters.WorldContextObject = WorldContextObject;
			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}

		TArray<AShooterCharacter*> FindAllShooterCharactersWithAlliance(UWorld* WorldContextObject, AShooterCharacter* LocalViewer, EAresAlliance Alliance, bool OnlyPlayerControlled, bool OnlyAlivePlayers)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.ShooterBlueprintLibrary.FindAllShooterCharactersWithAlliance").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct
			{
				UWorld* WorldContextObject;
				AShooterCharacter* LocalViewer;
				EAresAlliance Alliance;
				bool OnlyPlayerControlled;
				bool OnlyAlivePlayers;
				TArray<AShooterCharacter*> Out;
			} Parameters;

			Parameters.WorldContextObject = WorldContextObject;
			Parameters.LocalViewer = LocalViewer;
			Parameters.Alliance = Alliance;
			Parameters.OnlyPlayerControlled = OnlyPlayerControlled;
			Parameters.OnlyAlivePlayers = OnlyAlivePlayers;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}
	}

	namespace AresOutlineRendering
	{
		UObject* Static_Class()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"Renderer.Default__AresOutlineRendering").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}

		void SetOutlineColorsForRender(UWorld* WorldContextObject, FLinearColor AllyColor, FLinearColor EnemyColor)
		{
			SPOOF_FUNC;
			auto function_name =ez (L"Renderer.AresOutlineRendering.SetOutlineColorsForRender").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
			{
				return;
			}

			struct
			{
				UWorld* WorldContextObject;
				FLinearColor AllyColor;
				FLinearColor EnemyColor;
			} Parameters;

			Parameters.WorldContextObject = WorldContextObject;
			Parameters.AllyColor = AllyColor;
			Parameters.EnemyColor = EnemyColor;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
		}
	}

	namespace BaseTeamComponent
	{
		UObject* Static_Class()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"ShooterGame.Default__BaseTeamComponent").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}

		bool IsAlly(AShooterCharacter* Enemy, AShooterCharacter* Self)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"ShooterGame.BaseTeamComponent.IsAlly").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct
			{
				AShooterCharacter* Enemy;
				AShooterCharacter* Self;
				bool ReturnValue;
			} Parameters;

			Parameters.Enemy = Enemy;
			Parameters.Self = Self;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.ReturnValue;
		}
	}


	namespace menu
	{
		namespace input
		{
			bool mouseDown[5];
			bool mouseDownAlready[256];

			bool keysDown[256];
			bool keysDownAlready[256];

			bool is_any_mouse_down()
			{
				if (mouseDown[0]) return true;
				if (mouseDown[1]) return true;
				if (mouseDown[2]) return true;
				if (mouseDown[3]) return true;
				if (mouseDown[4]) return true;

				return false;
			}

			bool is_mouse_clicked(int button, int element_id, bool repeat)
			{
				if (mouseDown[button])
				{
					if (!mouseDownAlready[element_id])
					{
						mouseDownAlready[element_id] = true;
						return true;
					}
					if (repeat)
						return true;
				}
				else
				{
					mouseDownAlready[element_id] = false;
				}
				return false;
			}
			bool is_key_pressed(int key, bool repeat)
			{
				if (keysDown[key])
				{
					if (!keysDownAlready[key])
					{
						keysDownAlready[key] = true;
						return true;
					}
					if (repeat)
						return true;
				}
				else
				{
					keysDownAlready[key] = false;
				}
				return false;
			}

			void handle()
			{
				if (GetAsyncKeyState(0x01))
					mouseDown[0] = true;
				else
					mouseDown[0] = false;
			}
		}
	}
	wchar_t* s2wc(const char* c)
	{
		const size_t cSize = strlen(c) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, c, cSize);

		return wc;
	}

		FLinearColor RGBtoFLC(float R, float G, float B)
		{
			return { R / 255, G / 255, B / 255, 1 };
		}

		namespace menu
		{
			UObject* font;

			FLinearColor RGBtoFLC(float R, float G, float B)
			{
				return { R / 255, G / 255, B / 255, 1 };
			}

			FLinearColor HSVtoRGB(float h, float s, float v) {
				float R, G, B;

				int i = static_cast<int>(h * 6);
				float f = h * 6 - i;
				float p = v * (1 - s);
				float q = v * (1 - f * s);
				float t = v * (1 - (1 - f) * s);

				switch (i % 6) {
				case 0: R = v; G = t; B = p; break;
				case 1: R = q; G = v; B = p; break;
				case 2: R = p; G = v; B = t; break;
				case 3: R = p; G = q; B = v; break;
				case 4: R = t; G = p; B = v; break;
				case 5: R = v; G = p; B = q; break;
				default: R = G = B = 0.0f;
				}

				return FLinearColor{ R, G, B, 1.0f };

			}

			// x9 ware
			/*namespace Colors
			{
				FLinearColor Text{ 192.0f / 255.0f, 192.0f / 255.0f, 192.0f / 255.0f, 255.0f / 255.0f }; //
				FLinearColor Text_Shadow{ 0.0f, 0.0f, 0.0f, 1.0f };
				FLinearColor Text_Outline{ 0.0f, 0.0f, 0.0f, 1.0f };
				FLinearColor Text_Active = RGBtoFLC(184, 51, 255);  // Updated purple

				FLinearColor Button_Idle{ 10.0 / 255.0f, 10.0 / 255.0f, 10.0 / 255.0f, 0.8f }; //
				FLinearColor Button_Hovered = RGBtoFLC(7, 7, 7);
				FLinearColor Button_Active = RGBtoFLC(184, 51, 255);  // Updated purple

				FLinearColor Checkbox_Idle = RGBtoFLC(15, 15, 15);
				FLinearColor Checkbox_Hovered = RGBtoFLC(20, 20, 20);
				FLinearColor Checkbox_Enabled = RGBtoFLC(184, 51, 255); // Updated purple

				FLinearColor Combobox_Idle{ 200.0f / 255.0f, 150.0f / 255.0f, 40.0f / 255.0f };
				FLinearColor Combobox_Hovered{ 200.0f / 255.0f, 150.0f / 255.0f, 40.0f / 255.0f };
				FLinearColor Combobox_Elements{ 0.239f, 0.42f, 0.0f, 0.5f };

				FLinearColor Slider_Idle = RGBtoFLC(8, 8, 8);
				FLinearColor Slider_Hovered = RGBtoFLC(14, 14, 14);
				FLinearColor Slider_Progress = RGBtoFLC(184, 51, 255);  // Updated purple
				FLinearColor Slider_Button = RGBtoFLC(184, 51, 255);  // Updated purple

				FLinearColor ColorPicker_Background{ 0.006f, 0.006f, 0.006f, 0.4f };
			}*/


			namespace colors
			{
				FLinearColor Text{ 192.0f / 255.0f, 192.0f / 255.0f, 192.0f / 255.0f, 255.0f / 255.0f }; //
				FLinearColor Text_Shadow{ 0.0f, 0.0f, 0.0f, 1.0f };
				FLinearColor Text_Outline{ 0.0f, 0.0f, 0.0f, 1.0f };
				FLinearColor Text_Active{ 128.0f / 255.0f, 128.0f / 255.0f, 128.0f / 255.0f, 0.8f };

				FLinearColor Button_Idle{ 10.0 / 255.0f, 10.0 / 255.0f, 10.0 / 255.0f, 0.8f / 255.0f }; //
				FLinearColor Button_Hovered{ 15.0f / 255.0f, 15.0f / 255.0f, 15.0f / 255.0f, 1.f };
				FLinearColor Button_Active{ 128.0f / 255.0f, 128.0f / 255.0f, 128.0f / 255.0f, 0.8f };

				FLinearColor Checkbox_Idle = RGBtoFLC(15, 15, 15);
				FLinearColor Checkbox_Hovered = RGBtoFLC(20, 20, 20);
				FLinearColor Checkbox_Enabled = RGBtoFLC(128, 128, 128); //

				FLinearColor Combobox_Idle{ 200.0f / 255.0f, 150.0f / 255.0f, 40.0f / 255.0f };
				FLinearColor Combobox_Hovered{ 200.0f / 255.0f, 150.0f / 255.0f, 40.0f / 255.0f };
				FLinearColor Combobox_Elements{ 0.239f, 0.42f, 0.0f, 0.5f };

				FLinearColor Slider_Idle = RGBtoFLC(8, 8, 8);
				FLinearColor Slider_Hovered = RGBtoFLC(14, 14, 14);
				FLinearColor Slider_Progress = RGBtoFLC(128, 128, 128);
				FLinearColor Slider_Button = RGBtoFLC(128, 128, 128);

				FLinearColor ColorPicker_Background{ 0.006f, 0.006f, 0.006f, 0.4f };
			}

			namespace PostRenderer
			{
				struct DrawList
				{
					int type = -1; //1 = FilledRect, 2 = TextLeft, 3 = TextCenter, 4 = Draw_Line
					FVector2D pos;
					FVector2D size;
					FLinearColor color;
					const wchar_t* name;
					bool outline;

					FVector2D from;
					FVector2D to;
					int thickness;
				};
				DrawList drawlist[128];

				void drawFilledRect(FVector2D pos, float w, float h, FLinearColor color)
				{
					for (int i = 0; i < 128; i++)
					{
						if (drawlist[i].type == -1)
						{
							drawlist[i].type = 1;
							drawlist[i].pos = pos;
							drawlist[i].size = FVector2D{ w, h };
							drawlist[i].color = color;
							return;
						}
					}
				}
				void TextLeft(const wchar_t* name, FVector2D pos, FLinearColor color, bool outline)
				{
					for (int i = 0; i < 128; i++)
					{
						if (drawlist[i].type == -1)
						{
							drawlist[i].type = 2;
							drawlist[i].name = name;
							drawlist[i].pos = pos;
							drawlist[i].outline = outline;
							drawlist[i].color = color;
							return;
						}
					}
				}
				void TextCenter(const wchar_t* name, FVector2D pos, FLinearColor color, bool outline)
				{
					for (int i = 0; i < 128; i++)
					{
						if (drawlist[i].type == -1)
						{
							drawlist[i].type = 3;
							drawlist[i].name = name;
							drawlist[i].pos = pos;
							drawlist[i].outline = outline;
							drawlist[i].color = color;
							return;
						}
					}
				}
				void Draw_Line(FVector2D from, FVector2D to, int thickness, FLinearColor color)
				{
					for (int i = 0; i < 128; i++)
					{
						if (drawlist[i].type == -1)
						{
							drawlist[i].type = 4;
							drawlist[i].from = from;
							drawlist[i].to = to;
							drawlist[i].thickness = thickness;
							drawlist[i].color = color;
							return;
						}
					}
				}
			}

			UCanvas* canvas;


			bool hover_element = false;
			FVector2D menu_pos = FVector2D{ 0, 0 };
			float offset_x = 0.0f;
			float offset_y = 0.0f;

			FVector2D first_element_pos = FVector2D{ 0, 0 };

			FVector2D last_element_pos = FVector2D{ 0, 0 };
			FVector2D last_element_size = FVector2D{ 0, 0 };

			int current_element = -1;
			FVector2D current_element_pos = FVector2D{ 0, 0 };
			FVector2D current_element_size = FVector2D{ 0, 0 };
			

			bool sameLine = false;

			bool pushY = false;
			float pushYvalue = 0.0f;

			void SetupCanvas(UCanvas* _canvas)
			{
				canvas = _canvas;
			}

			void Draw_Line(FVector2D from, FVector2D to, int thickness, FLinearColor color)
			{
				canvas->K2_DrawLine(FVector2D{ from.X, from.Y }, FVector2D{ to.X, to.Y }, thickness, color);
			}
			void drawFilledRect(FVector2D initial_pos, float w, float h, FLinearColor color)
			{
				for (float i = 0.0f; i < h; i += 1.0f)
					canvas->K2_DrawLine(FVector2D{ initial_pos.X, initial_pos.Y + i }, FVector2D{ initial_pos.X + w, initial_pos.Y + i }, 1.0f, color);
			}
			void DrawGradientLine(FVector2D screenpos_a, FVector2D screenpos_b, FLinearColor color_a, FLinearColor color_c, FLinearColor color_b, float thickness, int num_segments)
			{
				for (int i = 0; i < num_segments; i++)
				{
					float t1 = static_cast<float>(i) / num_segments;
					float t2 = static_cast<float>(i + 1) / num_segments;

					FVector2D start = screenpos_a + (screenpos_b - screenpos_a) * t1;
					FVector2D end = screenpos_a + (screenpos_b - screenpos_a) * t2;

					float t_mid = (t1 + t2) / 2.0f;

					FLinearColor color;

					if (t_mid <= 0.5f)
					{
						float u = 2.0f * t_mid;  // Maps t_mid [0, 0.5] to u [0, 1]
						color.R = color_a.R * (1.0f - u) + color_c.R * u;
						color.G = color_a.G * (1.0f - u) + color_c.G * u;
						color.B = color_a.B * (1.0f - u) + color_c.B * u;
						color.A = color_a.A * (1.0f - u) + color_c.A * u;
					}
					else
					{
						float v = 2.0f * (t_mid - 0.5f);  // Maps t_mid [0.5, 1] to v [0, 1]
						color.R = color_c.R * (1.0f - v) + color_b.R * v;
						color.G = color_c.G * (1.0f - v) + color_b.G * v;
						color.B = color_c.B * (1.0f - v) + color_b.B * v;
						color.A = color_c.A * (1.0f - v) + color_b.A * v;
					}

					canvas->K2_DrawLine(start, end, thickness, color);
				}
			}

			// DrawGradientLine(startPos, endPos, red, green, blue, 2.0f, 20);
			void drawGradientFilledRect(FVector2D initial_pos, float w, float h, FLinearColor color_a, FLinearColor color_c, FLinearColor color_b, int num_segments)
			{
				for (float i = 0.0f; i < h; i += 1.0f)
					DrawGradientLine(FVector2D{ initial_pos.X, initial_pos.Y + i }, FVector2D{ initial_pos.X + w, initial_pos.Y + i }, color_a, color_c, color_b, 1.0f, num_segments);
			}

			void drawGradientFilledRectVertical(FVector2D initial_pos, float w, float h, FLinearColor color_a, FLinearColor color_c, FLinearColor color_b, int num_segments)
			{
				for (float i = 0.0f; i < w; i += 1.0f)
					DrawGradientLine(FVector2D{ initial_pos.X + i, initial_pos.Y }, FVector2D{ initial_pos.X + i, initial_pos.Y + h }, color_a, color_c, color_b, 1.0f, num_segments);
			}


			void draw_filled_rect(UCanvas* canvas, float X, float Y, float width, float height, FLinearColor color) {
				for (float i = 0; i < height; i++) {
					canvas->K2_DrawLine(
						{ X, Y + i },
						{ X + width, Y + i },
						1.0f,
						color
					);
				}
			}

			void draw_rect(UCanvas* canvas, float X, float Y, float width, float height, FLinearColor color) {
				canvas->K2_DrawLine({ X, Y }, { X + width, Y }, 1.0f, color);
				canvas->K2_DrawLine({ X + width, Y }, { X + width, Y + height }, 1.0f, color);
				canvas->K2_DrawLine({ X + width, Y + height }, { X, Y + height }, 1.0f, color);
				canvas->K2_DrawLine({ X, Y + height }, { X, Y }, 1.0f, color);
			}

			FVector2D CursorPos()
			{
				POINT cursorPos;
				GetCursorPos(&cursorPos);
				return FVector2D{ (float)cursorPos.x, (float)cursorPos.y };
			}
			bool MouseInZone(FVector2D pos, FVector2D size)
			{
				FVector2D cursor_pos = CursorPos();

				if (cursor_pos.X > pos.X && cursor_pos.Y > pos.Y)
					if (cursor_pos.X < pos.X + size.X && cursor_pos.Y < pos.Y + size.Y)
						return true;

				return false;
			}

			void Draw_Cursor(bool toogle)
			{
				if (toogle)
				{
					FVector2D cursorPos = CursorPos();
					drawFilledRect(FVector2D(cursorPos.X - 5, cursorPos.Y - 5), 10, 10, FLinearColor(255, 255, 255, 255));
				}
			}

			void SameLine()
			{
				sameLine = true;
			}
			void PushNextElementY(float Y, bool from_last_element = true)
			{
				pushY = true;
				if (from_last_element)
					pushYvalue = last_element_pos.Y + last_element_size.Y + Y;
				else
					pushYvalue = Y;
			}
			void NextColumn(float X)
			{
				offset_x = X;
				PushNextElementY(first_element_pos.Y, false);
			}
			void ClearFirstPos()
			{
				first_element_pos = FVector2D{ 0, 0 };
			}

			void xDrawTextRGB(const wchar_t* text, float X, float Y, FLinearColor color)
			{
				canvas->K2_DrawText(text, { X, Y }, { 1.1, 1.1 }, { 1.f,1.f,1.f,1.0f }, 0.f, { 0, 0, 0, 1 }, { 0, 0 }, 0, 0, 0, { 0, 0, 0, 1 });
			}
			void yDrawTextRGB(const wchar_t* text, float X, float Y, FLinearColor color)
			{
				canvas->K2_DrawText( text, { X, Y }, { 1.1, 1.1 }, { 1.f,1.f,1.f,1.0f }, 0.f, { 0, 0, 0, 1 }, { 0, 0 }, 1, 0, 0, { 0, 0, 0, 1 });
			}
			void TextLeft(const wchar_t* name, FVector2D pos, FLinearColor color, bool outline)
			{
				xDrawTextRGB(name, pos.X, pos.Y, { 1,1,1,1 });
			}
			void TextCenter(const wchar_t* name, FVector2D pos, FLinearColor color, bool outline, bool kekw = 0)
			{
				if (kekw)
					yDrawTextRGB(name, pos.X, pos.Y - 10, color);
				else
					yDrawTextRGB(name, pos.X, pos.Y - 10, { 1.f,1.f,1.f,1.0f });
			}

			void GetColor(FLinearColor* color, float* R, float* G, float* B, float* A)
			{
				*R = color->R;
				*G = color->G;
				*B = color->B;
				*A = color->A;
			}
			UINT32 GetColorUINT(int R, int G, int B, int A)
			{
				UINT32 result = (BYTE(A) << 24) + (BYTE(R) << 16) + (BYTE(G) << 8) + BYTE(B);
				return result;
			}
			void DrawFilledCircle(FVector2D pos, float R, FLinearColor color)
			{
				float smooth = 0.07f;

				double PI = 3.14159265359;
				int size = (int)(2.0f * PI / smooth) + 1;

				float angle = 0.0f;
				int i = 0;

				for (; angle < 2 * PI; angle += smooth, i++)
				{
					Draw_Line(FVector2D{ pos.X, pos.Y }, FVector2D{ pos.X + cosf(angle) * R, pos.Y + sinf(angle) * R }, 1.0f, color);
				}
			}
			void DrawCircle(FVector2D pos, int radius, int numSides, FLinearColor Color)
			{
				float PI = 3.1415927f;

				float Step = PI * 2.0 / numSides;
				int Count = 0;
				FVector2D V[128];
				for (float A = 0; A < PI * 2.0; A += Step) {
					float X1 = radius * cos(A) + pos.X;
					float Y1 = radius * sin(A) + pos.Y;
					float X2 = radius * cos(A + Step) + pos.X;
					float Y2 = radius * sin(A + Step) + pos.Y;
					V[Count].X = X1;
					V[Count].Y = Y1;
					V[Count + 1].X = X2;
					V[Count + 1].Y = Y2;
					//Draw_Line(FVector2D{ pos.X, pos.Y }, FVector2D{ X2, Y2 }, 1.0f, Color); // Points from Centre to ends of circle
					Draw_Line(FVector2D{ V[Count].X, V[Count].Y }, FVector2D{ X2, Y2 }, 1.0f, Color);// Circle Around
				}
			}

			FVector2D dragPos;
			bool Window(FString title, FVector2D* pos, FVector2D size, bool isOpen)
			{
				// Couleur gold à la place de l'arc-en-ciel
				FLinearColor RainbowColor = RGBtoFLC(0, 0, 255); // Violet
				elements_count = 0;

				if (!isOpen)
					return false;

				bool isHovered = MouseInZone(FVector2D{ pos->X, pos->Y }, size);

				// Drop last element
				if (current_element != -1 && !GetAsyncKeyState(0x1))
				{
					current_element = -1;
				}

				// Drag
				if (hover_element && GetAsyncKeyState(0x1))
				{
				}
				else if ((isHovered || dragPos.X != 0) && !hover_element)
				{
					if (input::is_mouse_clicked(0, elements_count, true))
					{
						FVector2D cursorPos = CursorPos();

						cursorPos.X -= size.X;
						cursorPos.Y -= size.Y;

						if (dragPos.X == 0)
						{
							dragPos.X = (cursorPos.X - pos->X);
							dragPos.Y = (cursorPos.Y - pos->Y);
						}
						pos->X = cursorPos.X - dragPos.X;
						pos->Y = cursorPos.Y - dragPos.Y;
					}
					else
					{
						dragPos = FVector2D{ 0, 0 };
					}
				}
				else
				{
					hover_element = false;
				}

				offset_x = 15.0f; offset_y = 63.0f;
				menu_pos = FVector2D{ pos->X, pos->Y };
				first_element_pos = FVector2D{ 0, 0 };
				current_element_pos = FVector2D{ 0, 0 };
				current_element_size = FVector2D{ 0, 0 };

				drawFilledRect(FVector2D(pos->X, pos->Y), size.X, size.Y, RGBtoFLC(1.2, 1.2, 1.2));
				drawFilledRect(FVector2D(pos->X, pos->Y + 45), size.X, 2, RainbowColor); // maintenant doré

				canvas->K2_DrawText(
					title,
					FVector2D(pos->X + (size.X / 2), pos->Y + (47 / 2)),
					FVector2D(1.15, 1.15),
					RGBtoFLC(225, 225, 225),
					0.0f,
					RGBtoFLC(0, 0, 0),
					FVector2D(0, 0),
					true,
					true,
					false,
					RGBtoFLC(0, 0, 0)
				);

				return true;
			}
#include <wchar.h> // for swprintf
			bool Watermark(FVector2D pos, FVector2D size, bool isOpen)
			{
				if (!isOpen)
					return false;

				// Texte simple
				FString finalText(L"Pasted");

				// Couleur gold (dorée) : RGB(255, 215, 0)
				FLinearColor goldColor = RGBtoFLC(0, 0, 255);

				// Fond de la bannière (clair, comme avant)
				drawFilledRect(pos, size.X, size.Y, RGBtoFLC(1.2f, 1.2f, 1.2f));

				// Ligne gold en bas de la bannière
				drawFilledRect(FVector2D(pos.X, pos.Y + size.Y - 2), size.X, 2, goldColor);

				// Affichage du texte centré
				canvas->K2_DrawText(
					finalText,
					FVector2D(pos.X + size.X / 2, pos.Y + size.Y / 2),
					FVector2D(0.9f, 0.9f),
					RGBtoFLC(255, 255, 255), // texte blanc
					0.0f,
					RGBtoFLC(0, 0, 0),       // ombre noire
					FVector2D(1, 1),
					true,
					true,
					false,
					RGBtoFLC(0, 0, 0)
				);

				return true;
			}




			bool ButtonTab(const wchar_t* name, FVector2D size, bool active)
			{
				elements_count++;

				FVector2D padding = FVector2D{ 0, 0 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + offset_x;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 0.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y }, size);

				if (!sameLine)
					offset_y += size.Y + padding.Y;

				FVector2D textPos = FVector2D{ pos.X + size.X / 2, pos.Y + size.Y / 2 };

				//Bg
				if (active)
				{
					drawFilledRect(FVector2D(pos.X, pos.Y), size.X, size.Y, RGBtoFLC(3, 3, 3));
					canvas->K2_DrawText( name, textPos, FVector2D(1.05, 1.05), RGBtoFLC(255, 255, 255), 0.0f, RGBtoFLC(0, 0, 0), FVector2D(0, 0), true, true, false, RGBtoFLC(0, 0, 0));
				}
				else if (isHovered)
				{
					canvas->K2_DrawText( name, textPos, FVector2D(1.05, 1.05), RGBtoFLC(120, 120, 120), 0.0f, RGBtoFLC(0, 0, 0), FVector2D(0, 0), true, true, false, RGBtoFLC(0, 0, 0));
					hover_element = true;
				}
				else
				{
					canvas->K2_DrawText( name, textPos, FVector2D(1.05, 1.05), RGBtoFLC(60, 60, 60), 0.0f, RGBtoFLC(0, 0, 0), FVector2D(0, 0), true, true, false, RGBtoFLC(0, 0, 0));
				}

				sameLine = false;
				last_element_pos = pos;
				last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;

				if (isHovered && input::is_mouse_clicked(0, elements_count, false))
					return true;

				return false;
			}

			void DrawCheckMark(FVector2D pos, float sz, FLinearColor color)
			{
				float thickness = fmaxf(sz / 5.0f, 1.0f);
				sz -= thickness * 0.5f;
				pos.X += thickness * 0.25f;
				pos.Y += thickness * 0.25f;

				float third = sz / 3.0f;
				float bx = pos.X + third;
				float by = pos.Y + sz - third * 0.5f;

				FVector2D p1 = FVector2D{ bx - third, by - third };
				FVector2D p2 = FVector2D{ bx, by };
				FVector2D p3 = FVector2D{ bx + third * 2.0f, by - third * 2.0f };

				// Assuming A simple function to draw lines with thickness
				canvas->K2_DrawLine(p1, p2, thickness, color);
				canvas->K2_DrawLine(p2, p3, thickness, color);
			}

			void SectionWrapper(FString name, FVector2D size)
			{
				FVector2D padding = FVector2D{ 0, 0 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = menu_pos.X + padding.X + offset_x;
					pos.Y = menu_pos.Y + padding.Y + offset_y;
				}

				drawFilledRect(FVector2D{ pos.X, pos.Y }, size.X, size.Y, RGBtoFLC(4, 4, 4));
				drawFilledRect(FVector2D{ pos.X + 1, pos.Y + 1 }, size.X - 2, size.Y - 2, RGBtoFLC(2, 2, 2));

				canvas->K2_DrawText( name, FVector2D(pos.X + (size.X / 2), pos.Y + (24 / 2)), FVector2D(1.05, 1.05), RGBtoFLC(255, 255, 255), 0.0f, RGBtoFLC(0, 0, 0), FVector2D(0, 0), true, true, false, RGBtoFLC(0, 0, 0));

				drawFilledRect(FVector2D{ pos.X + 1 + 13, pos.Y + 26 }, size.X - 28, 2, RGBtoFLC(3, 3, 3));

				menu::offset_y += 26 + 4;

				sameLine = false;
			}
	
			void Checkbox(const wchar_t* name, bool* value)
			{
				elements_count++;

				float sizex = 16.5;
				float xsize = 2;
				FVector2D padding = FVector2D{ 15,10 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 0.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X + 215, pos.Y }, FVector2D{ sizex, sizex });

				FVector2D textPos = FVector2D{ pos.X, pos.Y - xsize };

				drawFilledRect(FVector2D{ pos.X + 215, pos.Y }, sizex, sizex, RGBtoFLC(7, 7, 7));
				drawFilledRect(FVector2D{ pos.X + 215 + 1, pos.Y + 1 }, sizex - 2, sizex - 2, RGBtoFLC(2.5, 2.5, 2.5));

				if (!sameLine)
					offset_y += sizex + padding.Y;

				if (*value)
				{
					drawFilledRect(FVector2D{ pos.X + 215 + 2, pos.Y + 2 }, sizex - 4, sizex - 4, RGBtoFLC(0, 0, 255));
					DrawCheckMark(FVector2D(pos.X + 215 + 4, pos.Y + 4), sizex - 8, RGBtoFLC(3, 3, 3));
					canvas->K2_DrawText( name, textPos, FVector2D(1, 1), RGBtoFLC(255, 255, 255), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, false, false, colors::Text_Outline);
				}
				else {
					canvas->K2_DrawText( name, textPos, FVector2D(1, 1), RGBtoFLC(90, 90, 90), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, false, false, colors::Text_Outline);
				}

				sameLine = false;
				last_element_pos = pos;
				//last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;

				if (isHovered && input::is_mouse_clicked(0, elements_count, false))
					*value = !*value;
			}

			bool checkbox_enabled[256];
			void Combobox(const wchar_t* name, FVector2D size, int* value, const wchar_t* arg, ...)
			{
				elements_count++;

				FVector2D padding = FVector2D{ 15, 30 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 20.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y }, size);

				//Bg
				if (isHovered || checkbox_enabled[elements_count])
				{
					drawFilledRect(FVector2D{ pos.X, pos.Y }, size.X, size.Y, RGBtoFLC(5, 5, 5));
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + 1 }, size.X - 2, size.Y - 2, RGBtoFLC(4, 4, 4));

					hover_element = true;
				}
				else
				{
					drawFilledRect(FVector2D{ pos.X, pos.Y }, size.X, size.Y, RGBtoFLC(5, 5, 5));
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + 1 }, size.X - 2, size.Y - 2, RGBtoFLC(3, 3, 3));
				}

				if (!sameLine)
					offset_y += size.Y + padding.Y;

				//Text
				FVector2D textPos = FVector2D{ pos.X - 2.0f, pos.Y - size.Y + 2.0f };
				canvas->K2_DrawText( name, textPos, FVector2D(0.99, 0.99), RGBtoFLC(255, 255, 255), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, false, true, colors::Text_Outline);

				canvas->K2_DrawText( s2wc("v"), FVector2D{ pos.X + size.X - 18, pos.Y - 2 + size.Y / 2 }, FVector2D(1.2, 0.96), RGBtoFLC(255, 255, 255), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, true, false, colors::Text_Outline);

				//Elements
				bool isHovered2 = false;
				FVector2D element_pos = pos;
				int num = 0;

				if (checkbox_enabled[elements_count])
				{
					current_element_size.X = element_pos.X - 5.0f;
					current_element_size.Y = element_pos.Y - 5.0f;
				}
				va_list arguments;
				for (va_start(arguments, arg); arg != NULL; arg = va_arg(arguments, const wchar_t*))
				{
					//Selected Element
					if (num == *value)
					{
						FVector2D _textPos = FVector2D{ pos.X + 5, pos.Y + size.Y / 2 };
						canvas->K2_DrawText( arg, _textPos, FVector2D(0.98, 0.98), RGBtoFLC(130, 130, 130), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, true, true, colors::Text_Outline);
					}

					if (checkbox_enabled[elements_count])
					{
						element_pos.Y += 25.0f;

						isHovered2 = MouseInZone(FVector2D{ element_pos.X, element_pos.Y }, FVector2D{ size.X, 25.0f });
						if (isHovered2)
						{
							hover_element = true;
							PostRenderer::drawFilledRect(FVector2D{ element_pos.X, element_pos.Y }, size.X, 25.0f, RGBtoFLC(4, 4, 4));

							//Click
							if (input::is_mouse_clicked(0, elements_count, false))
							{
								*value = num;
								checkbox_enabled[elements_count] = false;
							}
						}
						else
						{
							PostRenderer::drawFilledRect(FVector2D{ element_pos.X, element_pos.Y }, size.X, 25.0f, RGBtoFLC(3, 3, 3));
						}

						PostRenderer::TextLeft(arg, FVector2D{ element_pos.X + 10.0f, element_pos.Y + 5.0f }, RGBtoFLC(110, 110, 110), true);
					}
					num++;
				}
				va_end(arguments);
				if (checkbox_enabled[elements_count])
				{
					current_element_size.X = element_pos.X + 5.0f;
					current_element_size.Y = element_pos.Y + 5.0f;
				}


				sameLine = false;
				last_element_pos = pos;
				last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;

				if (isHovered && input::is_mouse_clicked(0, elements_count, false))
				{
					checkbox_enabled[elements_count] = !checkbox_enabled[elements_count];
				}
				if (!isHovered && !isHovered2 && input::is_mouse_clicked(0, elements_count, false))
				{
					checkbox_enabled[elements_count] = false;
				}
			}
			void Combobox2(const wchar_t* name, FVector2D size, int* value, const std::vector<const wchar_t*>& items)
			{
				elements_count++;

				FVector2D padding = FVector2D{ 15, 30 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 20.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y }, size);

				if (isHovered || checkbox_enabled[elements_count])
				{
					drawFilledRect(FVector2D{ pos.X, pos.Y }, size.X, size.Y, RGBtoFLC(5, 5, 5));
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + 1 }, size.X - 2, size.Y - 2, RGBtoFLC(4, 4, 4));
					hover_element = true;
				}
				else
				{
					drawFilledRect(FVector2D{ pos.X, pos.Y }, size.X, size.Y, RGBtoFLC(5, 5, 5));
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + 1 }, size.X - 2, size.Y - 2, RGBtoFLC(3, 3, 3));
				}

				if (!sameLine)
					offset_y += size.Y + padding.Y;

				FVector2D textPos = FVector2D{ pos.X - 2.0f, pos.Y - size.Y + 2.0f };
				canvas->K2_DrawText(name, textPos, FVector2D(0.99, 0.99), RGBtoFLC(255, 255, 255), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, false, true, colors::Text_Outline);
				canvas->K2_DrawText(s2wc("v"), FVector2D{ pos.X + size.X - 18, pos.Y - 2 + size.Y / 2 }, FVector2D(1.2, 0.96), RGBtoFLC(255, 255, 255), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, true, false, colors::Text_Outline);

				bool isHovered2 = false;
				FVector2D element_pos = pos;

				if (checkbox_enabled[elements_count])
				{
					current_element_size.X = element_pos.X - 5.0f;
					current_element_size.Y = element_pos.Y - 5.0f;
				}

				for (int num = 0; num < items.size(); num++)
				{
					const wchar_t* arg = items[num];
					if (num == *value)
					{
						FVector2D _textPos = FVector2D{ pos.X + 5, pos.Y + size.Y / 2 };
						canvas->K2_DrawText(arg, _textPos, FVector2D(0.98, 0.98), RGBtoFLC(130, 130, 130), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, true, true, colors::Text_Outline);
					}

					if (checkbox_enabled[elements_count])
					{
						element_pos.Y += 25.0f;
						isHovered2 = MouseInZone(FVector2D{ element_pos.X, element_pos.Y }, FVector2D{ size.X, 25.0f });

						if (isHovered2)
						{
							hover_element = true;
							PostRenderer::drawFilledRect(FVector2D{ element_pos.X, element_pos.Y }, size.X, 25.0f, RGBtoFLC(4, 4, 4));

							if (input::is_mouse_clicked(0, elements_count, false))
							{
								*value = num;
								checkbox_enabled[elements_count] = false;
							}
						}
						else
						{
							PostRenderer::drawFilledRect(FVector2D{ element_pos.X, element_pos.Y }, size.X, 25.0f, RGBtoFLC(3, 3, 3));
						}

						PostRenderer::TextLeft(arg, FVector2D{ element_pos.X + 10.0f, element_pos.Y + 5.0f }, RGBtoFLC(110, 110, 110), true);
					}
				}

				if (checkbox_enabled[elements_count])
				{
					current_element_size.X = element_pos.X + 5.0f;
					current_element_size.Y = element_pos.Y + 5.0f;
				}

				sameLine = false;
				last_element_pos = pos;
				last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;

				if (isHovered && input::is_mouse_clicked(0, elements_count, false))
				{
					checkbox_enabled[elements_count] = !checkbox_enabled[elements_count];
				}
				if (!isHovered && !isHovered2 && input::is_mouse_clicked(0, elements_count, false))
				{
					checkbox_enabled[elements_count] = false;
				}
			}

			void ShowSkinCombobox(const wchar_t* name, FVector2D size, int* selectedSkin, const std::vector<SkinData>& skinData)
			{
				// Collect the skin display names in a vector of const wchar_t*
				std::vector<const wchar_t*> skinNames;
				for (const auto& skin : skinData)
				{
					skinNames.push_back(skin.SkinName);
				}

				// Pass the skin names to your Combobox function
				Combobox2(name, size, selectedSkin, skinNames);
			}
			void SliderFloat(const wchar_t* name, float* value, float min, float max, const char* format = "%.0f")
			{
				elements_count++;
				FVector2D size = FVector2D{ 231, 10 };
				FVector2D slider_size = FVector2D{ 231, 10 };
				FVector2D adjust_zone = FVector2D{ 0, 20 };
				FVector2D padding = FVector2D{ 15, 10 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 0.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y + slider_size.Y + padding.Y - adjust_zone.Y }, FVector2D{ slider_size.X, slider_size.Y + adjust_zone.Y * 1.5f });

				if (!sameLine)
					offset_y += size.Y + padding.Y;

				//Bg
				if (isHovered || current_element == elements_count)
				{
					//Drag
					if (input::is_mouse_clicked(0, elements_count, true))
					{
						current_element = elements_count;

						FVector2D cursorPos = CursorPos();
						*value = ((cursorPos.X - pos.X) * ((max - min) / slider_size.X)) + min;
						if (*value < min) *value = min;
						if (*value > max) *value = max;
					}

					drawFilledRect(FVector2D{ pos.X, pos.Y + slider_size.Y + padding.Y }, slider_size.X, slider_size.Y, RGBtoFLC(10, 10, 9));
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + slider_size.Y + padding.Y + 1 }, slider_size.X - 2, slider_size.Y - 2, RGBtoFLC(6, 6, 6));

					hover_element = true;
				}
				else
				{
					drawFilledRect(FVector2D{ pos.X, pos.Y + slider_size.Y + padding.Y }, slider_size.X, slider_size.Y, RGBtoFLC(10, 10, 9));
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + slider_size.Y + padding.Y + 1 }, slider_size.X - 2, slider_size.Y - 2, RGBtoFLC(4, 4, 4));
				}


				//Text
				FVector2D textPos = FVector2D{ pos.X, pos.Y - 2.0f };
				canvas->K2_DrawText( name, textPos, FVector2D(0.98, 0.98), RGBtoFLC(211, 211, 211), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, false, false, colors::Text_Outline);

				//Value
				float oneP = slider_size.X / (max - min);
				drawFilledRect(FVector2D{ pos.X + 1, pos.Y + slider_size.Y + padding.Y + 1 }, oneP * (*value - min) - 2, slider_size.Y - 2, RGBtoFLC(110, 182, 229));
				drawFilledRect(FVector2D{ pos.X + oneP * (*value - min), pos.Y + slider_size.Y + padding.Y + 1 - 5 }, 12, 17, RGBtoFLC(7, 7, 7));

				char buffer[32];
				sprintf_s(buffer, format, *value);
				canvas->K2_DrawText( s2wc(buffer), FVector2D(pos.X + slider_size.X - 14.0f, pos.Y - 2.0f), FVector2D(0.98, 0.98), RGBtoFLC(78, 78, 78), 0.0f, colors::Text_Shadow, FVector2D(0, 0), true, false, false, colors::Text_Outline);

				sameLine = false;
				last_element_pos = pos;
				last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;
			}

			int active_hotkey = -1;
			bool already_pressed = false;
			std::string VirtualKeyCodeToString(UCHAR virtualKey)
			{
				UINT scanCode = MapVirtualKey(virtualKey, MAPVK_VK_TO_VSC);
				if (virtualKey == VK_LBUTTON)
				{
					return ("MOUSE0");
				}
				if (virtualKey == VK_RBUTTON)
				{
					return ("MOUSE1");
				}
				if (virtualKey == VK_MBUTTON)
				{
					return ("MBUTTON");
				}
				if (virtualKey == VK_XBUTTON1)
				{
					return ("XBUTTON1");
				}
				if (virtualKey == VK_XBUTTON2)
				{
					return ("XBUTTON2");
				}


				CHAR szName[128];
				int result = 0;
				switch (virtualKey)
				{
				case VK_LEFT: case VK_UP: case VK_RIGHT: case VK_DOWN:
				case VK_RCONTROL: case VK_RMENU:
				case VK_LWIN: case VK_RWIN: case VK_APPS:
				case VK_PRIOR: case VK_NEXT:
				case VK_END: case VK_HOME:
				case VK_INSERT: case VK_DELETE:
				case VK_DIVIDE:
				case VK_NUMLOCK:
					scanCode |= KF_EXTENDED;
				default:
					result = GetKeyNameTextA(scanCode << 16, szName, 128);
				}

				return szName;
			}
			void Hotkey(const char* name, FVector2D size, int* key)
			{
				elements_count++;
				FVector2D padding = FVector2D{ 80, 4 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y - padding.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 0.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y }, size);

				drawFilledRect(FVector2D{ pos.X, pos.Y }, size.X, size.Y, RGBtoFLC(10, 10, 10));
				drawFilledRect(FVector2D{ pos.X + 1, pos.Y + 1 }, size.X - 2, size.Y - 2, RGBtoFLC(2, 2, 2));

				if (!sameLine)
					offset_y += size.Y + padding.Y;

				if (active_hotkey == elements_count)
				{
					//Text
					FVector2D textPos = FVector2D{ pos.X + size.X / 2, pos.Y + size.Y / 2 };
					canvas->K2_DrawText( L"...", textPos, FVector2D(0.99, 0.99), RGBtoFLC(60, 60, 60), 0.0f, colors::Text_Shadow, FVector2D(0, 0), true, true, true, colors::Text_Outline);

					if (!menu::input::is_any_mouse_down())
					{
						already_pressed = false;
					}

					if (!already_pressed)
					{
						for (int code = 0; code < 255; code++)
						{
							if (GetAsyncKeyState(code))
							{
								*key = code;
								active_hotkey = -1;
							}
						}
					}
				}
				else
				{
					//Text
					FVector2D textPos = FVector2D{ pos.X + size.X / 2, pos.Y + size.Y / 2 };
					canvas->K2_DrawText( s2wc(VirtualKeyCodeToString(*key).c_str()), textPos, FVector2D(0.99, 0.99), RGBtoFLC(60, 60, 60), 0.0f, colors::Text_Shadow, FVector2D(0, 0), true, true, true, colors::Text_Outline);


					if (isHovered)
					{
						if (input::is_mouse_clicked(0, elements_count, false))
						{
							already_pressed = true;
							active_hotkey = elements_count;

							//Queue Fix
							for (int code = 0; code < 255; code++)
								if (GetAsyncKeyState(code)) {}
						}
					}
					else
					{
						if (input::is_mouse_clicked(0, elements_count, false))
						{
							active_hotkey = -1;
						}
					}
				}


				sameLine = false;
				last_element_pos = pos;
				last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;
			}

			bool draw_color_picker(UCanvas* canvas, UObject* font, const wchar_t* label, FLinearColor& color, FVector2D pos, FVector2D mouse_pos, bool mouse_clicked) {
				const float hue_slider_width = 100.0f;
				const float hue_slider_height = 7.0f;
				const float sb_picker_size = 75.0f;
				const float alpha_slider_width = hue_slider_width;
				const float alpha_slider_height = 7.0f;
				const float preview_box_size = 15.0f;
				const float spacing = 5.0f;

				static bool hue_dragging = false;
				static bool sb_dragging = false;
				static bool alpha_dragging = false;

				static float hue = 0.0f;
				static float saturation = 1.0f;
				static float brightness = 1.0f;

				float thickness = 2.0f; // grosor del texto
				float width_scale = 1.0f; // escala de anchura
				float height_scale = 0.8f; // escala de altura
				float text_scale = 1.1f; // escala del tamaÃ±o de la fuente

				bool value_changed = false;

				for (int i = 0; i < hue_slider_width; i++) {
					float h = (float)i / hue_slider_width;
					FLinearColor color_at_hue = HSVtoRGB(h, 1.0f, 1.0f);
					draw_filled_rect(canvas, pos.X + i, pos.Y, 1.0f, hue_slider_height, color_at_hue); // raya arriba
				}
				draw_rect(canvas, pos.X, pos.Y, hue_slider_width, hue_slider_height, RGBtoFLC(5, 5, 5));

				if (mouse_clicked && mouse_pos.X >= pos.X && mouse_pos.X <= pos.X + hue_slider_width &&
					mouse_pos.Y >= pos.Y && mouse_pos.Y <= pos.Y + hue_slider_height) {
					hue_dragging = true;
				}
				if (hue_dragging) {
					if (mouse_clicked) {
						hue = (mouse_pos.X - pos.X) / hue_slider_width;
						hue = std::clamp(hue, 0.0f, 1.0f);
						value_changed = true;
					}
					else {
						hue_dragging = false;
					}
				}

				FVector2D sb_pos = { pos.X, pos.Y + hue_slider_height + spacing };

				for (int Y = 0; Y < sb_picker_size; Y++) {
					for (int X = 0; X < sb_picker_size; X++) {
						float s = (float)X / sb_picker_size;
						float B = 1.0f - (float)Y / sb_picker_size;
						FLinearColor sb_color = HSVtoRGB(hue, s, B);
						draw_filled_rect(canvas, sb_pos.X + X, sb_pos.Y + Y, 1.0f, 1.0f, sb_color);
					}
				}
				draw_rect(canvas, sb_pos.X, sb_pos.Y, sb_picker_size, sb_picker_size, RGBtoFLC(5, 5, 5));

				if (mouse_clicked && mouse_pos.X >= sb_pos.X && mouse_pos.X <= sb_pos.X + sb_picker_size &&
					mouse_pos.Y >= sb_pos.Y && mouse_pos.Y <= sb_pos.Y + sb_picker_size) {
					sb_dragging = true;
				}
				if (sb_dragging) {
					if (mouse_clicked) {
						saturation = (mouse_pos.X - sb_pos.X) / sb_picker_size;
						brightness = 1.0f - (mouse_pos.Y - sb_pos.Y) / sb_picker_size;
						saturation = std::clamp(saturation, 0.0f, 1.0f);
						brightness = std::clamp(brightness, 0.0f, 1.0f);
						value_changed = true;
					}
					else {
						sb_dragging = false;
					}
				}

				FVector2D alpha_pos = { pos.X, sb_pos.Y + sb_picker_size + spacing };

				for (int i = 0; i < alpha_slider_width; i++) {
					float alpha = (float)i / alpha_slider_width;
					FLinearColor alpha_color = HSVtoRGB(hue, saturation, brightness);
					alpha_color.A = alpha;
					draw_filled_rect(canvas, alpha_pos.X + i, alpha_pos.Y, 1.0f, alpha_slider_height, alpha_color);
				}
				draw_rect(canvas, alpha_pos.X, alpha_pos.Y, alpha_slider_width, alpha_slider_height, RGBtoFLC(5, 5, 5));

				if (mouse_clicked && mouse_pos.X >= alpha_pos.X && mouse_pos.X <= alpha_pos.X + alpha_slider_width &&
					mouse_pos.Y >= alpha_pos.Y && mouse_pos.Y <= alpha_pos.Y + alpha_slider_height) {
					alpha_dragging = true;
				}
				if (alpha_dragging) {
					if (mouse_clicked) {
						color.A = (mouse_pos.X - alpha_pos.X) / alpha_slider_width;
						color.A = std::clamp(color.A, 0.0f, 1.0f);
						value_changed = true;
					}
					else {
						alpha_dragging = false;
					}
				}

				FLinearColor final_color = HSVtoRGB(hue, saturation, brightness);
				color.R = final_color.R;
				color.G = final_color.G;
				color.B = final_color.B;

				FVector2D preview_pos = { pos.X + hue_slider_width + spacing, pos.Y };
				draw_filled_rect(canvas, preview_pos.X, preview_pos.Y, preview_box_size, preview_box_size, { color.R, color.G, color.B, color.A });
				draw_rect(canvas, preview_pos.X, preview_pos.Y, preview_box_size, preview_box_size, RGBtoFLC(5, 5, 5));

				return value_changed;
			}

			// END
			void Text(const wchar_t* text, bool center = false, bool outline = false)
			{
				elements_count++;

				float size = 24;
				FVector2D padding = FVector2D{ 1,3 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 0.0f;
					offset_y = pos.Y - menu_pos.Y;
				}

				if (!sameLine)
					offset_y += size + padding.Y;

				//Text
				FVector2D textPos = FVector2D{ pos.X + 5.0f, pos.Y };
				if (center)
					TextCenter(text, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, outline);
				else
					TextLeft(text, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, outline);

				sameLine = false;
				last_element_pos = pos;
				//last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;
			}
			bool Button(const wchar_t* name, FVector2D size)
			{
				elements_count++;

				FVector2D padding = FVector2D{ 15, 15 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 0.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y }, size);

				drawFilledRect(FVector2D{ pos.X, pos.Y }, size.X, size.Y, RGBtoFLC(7, 7, 7));

				//Bg
				if (isHovered)
				{
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + 1 }, size.X - 2, size.Y - 2, RGBtoFLC(3, 3, 3));
					hover_element = true;
				}
				else
				{
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + 1 }, size.X - 2, size.Y - 2, RGBtoFLC(2, 2, 2));
				}

				if (!sameLine)
					offset_y += size.Y + padding.Y;

				//Text
				FVector2D textPos = FVector2D{ pos.X + size.X / 2, pos.Y + size.Y / 2 };
				canvas->K2_DrawText( name, textPos, FVector2D(1.05, 0.99), RGBtoFLC(160, 160, 160), 0.0f, colors::Text_Shadow, FVector2D(0, 0), true, true, false, colors::Text_Outline);


				sameLine = false;
				last_element_pos = pos;
				last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;

				if (isHovered && input::is_mouse_clicked(0, elements_count, false))
					return true;

				return false;
			}
			void SliderInt(const wchar_t* name, int* value, int min, int max, const char* format = "%d")
			{
				elements_count++;
				FVector2D size = FVector2D{ 231, 10 };
				FVector2D slider_size = FVector2D{ 231, 10 };
				FVector2D adjust_zone = FVector2D{ 0, 20 };
				FVector2D padding = FVector2D{ 15, 10 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };

				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 0.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y + slider_size.Y + padding.Y - adjust_zone.Y }, FVector2D{ slider_size.X, slider_size.Y + adjust_zone.Y * 1.5f });

				if (!sameLine)
					offset_y += size.Y + padding.Y;

				if (isHovered || current_element == elements_count)
				{
					if (input::is_mouse_clicked(0, elements_count, true))
					{
						current_element = elements_count;

						FVector2D cursorPos = CursorPos();
						float ratio = (cursorPos.X - pos.X) / slider_size.X;
						int newValue = static_cast<int>(min + (max - min) * ratio + 0.5f);
						if (newValue < min) newValue = min;
						if (newValue > max) newValue = max;
						*value = newValue;
					}

					drawFilledRect(FVector2D{ pos.X, pos.Y + slider_size.Y + padding.Y }, slider_size.X, slider_size.Y, RGBtoFLC(10, 10, 9));
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + slider_size.Y + padding.Y + 1 }, slider_size.X - 2, slider_size.Y - 2, RGBtoFLC(6, 6, 6));
					hover_element = true;
				}
				else
				{
					drawFilledRect(FVector2D{ pos.X, pos.Y + slider_size.Y + padding.Y }, slider_size.X, slider_size.Y, RGBtoFLC(10, 10, 9));
					drawFilledRect(FVector2D{ pos.X + 1, pos.Y + slider_size.Y + padding.Y + 1 }, slider_size.X - 2, slider_size.Y - 2, RGBtoFLC(4, 4, 4));
				}

				FVector2D textPos = FVector2D{ pos.X, pos.Y - 2.0f };
				canvas->K2_DrawText(name, textPos, FVector2D(0.98, 0.98), RGBtoFLC(211, 211, 211), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, false, false, colors::Text_Outline);

				float oneP = slider_size.X / float(max - min);
				drawFilledRect(FVector2D{ pos.X + 1, pos.Y + slider_size.Y + padding.Y + 1 }, oneP * (*value - min) - 2, slider_size.Y - 2, RGBtoFLC(110, 182, 229));
				drawFilledRect(FVector2D{ pos.X + oneP * (*value - min), pos.Y + slider_size.Y + padding.Y + 1 - 5 }, 12, 17, RGBtoFLC(7, 7, 7));

				char buffer[32];
				sprintf_s(buffer, format, *value);
				canvas->K2_DrawText(s2wc(buffer), FVector2D(pos.X + slider_size.X - 14.0f, pos.Y - 2.0f), FVector2D(0.98, 0.98), RGBtoFLC(78, 78, 78), 0.0f, colors::Text_Shadow, FVector2D(0, 0), true, false, false, colors::Text_Outline);

				sameLine = false;
				last_element_pos = pos;
				last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;
			}


			int active_picker = -1;
			FLinearColor saved_color;
			bool ColorPixel(FVector2D pos, FVector2D size, FLinearColor* original, FLinearColor color)
			{
				PostRenderer::drawFilledRect(FVector2D{ pos.X, pos.Y }, size.X, size.Y, color);

				//Выбранный цвет
				if (original->R == color.R && original->G == color.G && original->B == color.B)
				{
					PostRenderer::Draw_Line(FVector2D{ pos.X, pos.Y }, FVector2D{ pos.X + size.X - 1, pos.Y }, 1.0f, FLinearColor{ 0.0f, 0.0f, 0.0f, 1.0f });
					PostRenderer::Draw_Line(FVector2D{ pos.X, pos.Y + size.Y - 1 }, FVector2D{ pos.X + size.X - 1, pos.Y + size.Y - 1 }, 1.0f, FLinearColor{ 0.0f, 0.0f, 0.0f, 1.0f });
					PostRenderer::Draw_Line(FVector2D{ pos.X, pos.Y }, FVector2D{ pos.X, pos.Y + size.Y - 1 }, 1.0f, FLinearColor{ 0.0f, 0.0f, 0.0f, 1.0f });
					PostRenderer::Draw_Line(FVector2D{ pos.X + size.X - 1, pos.Y }, FVector2D{ pos.X + size.X - 1, pos.Y + size.Y - 1 }, 1.0f, FLinearColor{ 0.0f, 0.0f, 0.0f, 1.0f });
				}

				//Смена цвета
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y }, size);
				if (isHovered)
				{
					if (input::is_mouse_clicked(0, elements_count, false))
						*original = color;
				}

				return true;
			}
			void ColorPicker_Fresnel(const wchar_t* name, FLinearColor* color)
			{
				elements_count++;

				float size = 15;
				float xsize = 5;
				FVector2D padding = FVector2D{ 15, 10 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 0.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y }, FVector2D{ size, size });

				if (!sameLine)
					offset_y += size + padding.Y;

				if (active_picker == elements_count)
				{
					hover_element = true;

					float sizePickerX = 260;
					float sizePickerY = 260;
					bool isHoveredPicker = MouseInZone(FVector2D{ pos.X, pos.Y }, FVector2D{ sizePickerX, sizePickerY - 60 });

					//Background
					PostRenderer::drawFilledRect(FVector2D{ pos.X, pos.Y }, sizePickerX - 120.0f, sizePickerY - 210, menu::colors::ColorPicker_Background);

					FVector2D pixelSize = FVector2D{ sizePickerX / 12, sizePickerY / 12 };

					//0
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 0.f, 24.0f, 0.0f, 1.0f });

					}
					//1
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 24.0f, 0.0f, 24.0f , 1.0f });

					}
					//2
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 24.0f, 0.0f, 0.0f, 1.0f });
					}
					//2
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 24.0f,24.0f, 0.0f, 1.0f });
					}
					//1
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 0.0f, 25.0f, 25.0f , 1.0f });

					}

					if (isHoveredPicker)
					{
						if (input::is_mouse_clicked(0, elements_count, false))
						{

						}
					}
					else
					{
						if (input::is_mouse_clicked(0, elements_count, false))
						{
							active_picker = -1;
							//hover_element = false;
						}
					}
				}
				else
				{
					//Bg
					if (isHovered)
					{
						drawFilledRect(FVector2D{ pos.X, pos.Y }, size, size, menu::colors::Checkbox_Hovered);
						hover_element = true;
					}
					else
					{
						drawFilledRect(FVector2D{ pos.X, pos.Y }, size, size, menu::colors::Checkbox_Idle);
					}

					//Color
					drawFilledRect(FVector2D{ pos.X + 4, pos.Y + 4 }, size - 8, size - 8, *color);

					//Text
					FVector2D textPos = FVector2D{ pos.X + size + 5.0f, pos.Y - xsize + 4.0f };
					canvas->K2_DrawText(name, textPos, FVector2D(0.98f, 0.98f), RGBtoFLC(192, 192, 192), 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, false, true, colors::Text_Outline);

					if (isHovered && input::is_mouse_clicked(0, elements_count, false))
					{
						saved_color = *color;
						active_picker = elements_count;
					}
				}


				sameLine = false;
				last_element_pos = pos;
				//last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;
			}
			void ColorPicker(const wchar_t* name, FLinearColor* color)
			{
				elements_count++;

				float size = 20;
				float xsize = 5;
				FVector2D padding = FVector2D{ 15, 10 };
				FVector2D pos = FVector2D{ menu_pos.X + padding.X + offset_x, menu_pos.Y + padding.Y + offset_y };
				if (sameLine)
				{
					pos.X = last_element_pos.X + last_element_size.X + padding.X;
					pos.Y = last_element_pos.Y;
				}
				if (pushY)
				{
					pos.Y = pushYvalue;
					pushY = false;
					pushYvalue = 0.0f;
					offset_y = pos.Y - menu_pos.Y;
				}
				bool isHovered = MouseInZone(FVector2D{ pos.X, pos.Y }, FVector2D{ size, size });

				if (!sameLine)
					offset_y += size + padding.Y;

				if (active_picker == elements_count)
				{
					hover_element = true;

					float sizePickerX = 250;
					float sizePickerY = 250;
					bool isHoveredPicker = MouseInZone(FVector2D{ pos.X, pos.Y }, FVector2D{ sizePickerX, sizePickerY - 60 });

					//Background
					PostRenderer::drawFilledRect(FVector2D{ pos.X, pos.Y }, sizePickerX, sizePickerY - 65, colors::ColorPicker_Background);

					FVector2D pixelSize = FVector2D{ sizePickerX / 12, sizePickerY / 12 };

					//0
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 174 / 255.f, 235 / 255.f, 253 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 136 / 255.f, 225 / 255.f, 251 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 108 / 255.f, 213 / 255.f, 250 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 89 / 255.f, 175 / 255.f, 213 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 76 / 255.f, 151 / 255.f, 177 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 60 / 255.f, 118 / 255.f, 140 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 43 / 255.f, 85 / 255.f, 100 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 32 / 255.f, 62 / 255.f, 74 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 0, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 255 / 255.f, 255 / 255.f, 255 / 255.f, 1.0f });
					}
					//1
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 175 / 255.f, 205 / 255.f, 252 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 132 / 255.f, 179 / 255.f, 252 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 90 / 255.f, 152 / 255.f, 250 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 55 / 255.f, 120 / 255.f, 250 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 49 / 255.f, 105 / 255.f, 209 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 38 / 255.f, 83 / 255.f, 165 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 28 / 255.f, 61 / 255.f, 120 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 20 / 255.f, 43 / 255.f, 86 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 1, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 247 / 255.f, 247 / 255.f, 247 / 255.f, 1.0f });
					}
					//2
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 153 / 255.f, 139 / 255.f, 250 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 101 / 255.f, 79 / 255.f, 249 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 64 / 255.f, 50 / 255.f, 230 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 54 / 255.f, 38 / 255.f, 175 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 39 / 255.f, 31 / 255.f, 144 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 32 / 255.f, 25 / 255.f, 116 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 21 / 255.f, 18 / 255.f, 82 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 16 / 255.f, 13 / 255.f, 61 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 2, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 228 / 255.f, 228 / 255.f, 228 / 255.f, 1.0f });
					}
					//3
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 194 / 255.f, 144 / 255.f, 251 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 165 / 255.f, 87 / 255.f, 249 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 142 / 255.f, 57 / 255.f, 239 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 116 / 255.f, 45 / 255.f, 184 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 92 / 255.f, 37 / 255.f, 154 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 73 / 255.f, 29 / 255.f, 121 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 53 / 255.f, 21 / 255.f, 88 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 37 / 255.f, 15 / 255.f, 63 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 3, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 203 / 255.f, 203 / 255.f, 203 / 255.f, 1.0f });
					}
					//4
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 224 / 255.f, 162 / 255.f, 197 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 210 / 255.f, 112 / 255.f, 166 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 199 / 255.f, 62 / 255.f, 135 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 159 / 255.f, 49 / 255.f, 105 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 132 / 255.f, 41 / 255.f, 89 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 104 / 255.f, 32 / 255.f, 71 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 75 / 255.f, 24 / 255.f, 51 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 54 / 255.f, 14 / 255.f, 36 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 4, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 175 / 255.f, 175 / 255.f, 175 / 255.f, 1.0f });
					}
					//5
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 5, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 235 / 255.f, 175 / 255.f, 176 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 5, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 227 / 255.f, 133 / 255.f, 135 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 5, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 219 / 255.f, 87 / 255.f, 88 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 5, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 215 / 255.f, 50 / 255.f, 36 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 5, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 187 / 255.f, 25 / 255.f, 7 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 5, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 149 / 255.f, 20 / 255.f, 6 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 5, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 107 / 255.f, 14 / 255.f, 4 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 5, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 77 / 255.f, 9 / 255.f, 3 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 5, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 144 / 255.f, 144 / 255.f, 144 / 255.f, 1.0f });
					}
					//6
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 6, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 241 / 255.f, 187 / 255.f, 171 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 6, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 234 / 255.f, 151 / 255.f, 126 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 6, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 229 / 255.f, 115 / 255.f, 76 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 6, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 227 / 255.f, 82 / 255.f, 24 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 6, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 190 / 255.f, 61 / 255.f, 15 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 6, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 150 / 255.f, 48 / 255.f, 12 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 6, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 107 / 255.f, 34 / 255.f, 8 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 6, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 79 / 255.f, 25 / 255.f, 6 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 6, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 113 / 255.f, 113 / 255.f, 113 / 255.f, 1.0f });
					}
					//7
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 7, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 245 / 255.f, 207 / 255.f, 169 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 7, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 240 / 255.f, 183 / 255.f, 122 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 7, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 236 / 255.f, 159 / 255.f, 74 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 7, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 234 / 255.f, 146 / 255.f, 37 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 7, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 193 / 255.f, 111 / 255.f, 28 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 7, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 152 / 255.f, 89 / 255.f, 22 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 7, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 110 / 255.f, 64 / 255.f, 16 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 7, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 80 / 255.f, 47 / 255.f, 12 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 7, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 82 / 255.f, 82 / 255.f, 82 / 255.f, 1.0f });
					}
					//8
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 8, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 247 / 255.f, 218 / 255.f, 170 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 8, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 244 / 255.f, 200 / 255.f, 124 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 8, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 241 / 255.f, 182 / 255.f, 77 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 8, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 239 / 255.f, 174 / 255.f, 44 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 8, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 196 / 255.f, 137 / 255.f, 34 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 8, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 154 / 255.f, 108 / 255.f, 27 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 8, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 111 / 255.f, 77 / 255.f, 19 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 8, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 80 / 255.f, 56 / 255.f, 14 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 8, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 54 / 255.f, 54 / 255.f, 54 / 255.f, 1.0f });
					}
					//9
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 9, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 254 / 255.f, 243 / 255.f, 187 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 9, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 253 / 255.f, 237 / 255.f, 153 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 9, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 253 / 255.f, 231 / 255.f, 117 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 9, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 254 / 255.f, 232 / 255.f, 85 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 9, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 242 / 255.f, 212 / 255.f, 53 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 9, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 192 / 255.f, 169 / 255.f, 42 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 9, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 138 / 255.f, 120 / 255.f, 30 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 9, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 101 / 255.f, 87 / 255.f, 22 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 9, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 29 / 255.f, 29 / 255.f, 29 / 255.f, 1.0f });
					}
					//10
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 10, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 247 / 255.f, 243 / 255.f, 185 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 10, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 243 / 255.f, 239 / 255.f, 148 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 10, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 239 / 255.f, 232 / 255.f, 111 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 10, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 235 / 255.f, 229 / 255.f, 76 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 10, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 208 / 255.f, 200 / 255.f, 55 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 10, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 164 / 255.f, 157 / 255.f, 43 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 10, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 118 / 255.f, 114 / 255.f, 31 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 10, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 86 / 255.f, 82 / 255.f, 21 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 10, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 9 / 255.f, 9 / 255.f, 9 / 255.f, 1.0f });
					}
					//11
					{
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 11, pos.Y + pixelSize.Y * 0 }, pixelSize, color, FLinearColor{ 218 / 255.f, 232 / 255.f, 182 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 11, pos.Y + pixelSize.Y * 1 }, pixelSize, color, FLinearColor{ 198 / 255.f, 221 / 255.f, 143 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 11, pos.Y + pixelSize.Y * 2 }, pixelSize, color, FLinearColor{ 181 / 255.f, 210 / 255.f, 103 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 11, pos.Y + pixelSize.Y * 3 }, pixelSize, color, FLinearColor{ 154 / 255.f, 186 / 255.f, 76 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 11, pos.Y + pixelSize.Y * 4 }, pixelSize, color, FLinearColor{ 130 / 255.f, 155 / 255.f, 64 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 11, pos.Y + pixelSize.Y * 5 }, pixelSize, color, FLinearColor{ 102 / 255.f, 121 / 255.f, 50 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 11, pos.Y + pixelSize.Y * 6 }, pixelSize, color, FLinearColor{ 74 / 255.f, 88 / 255.f, 36 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 11, pos.Y + pixelSize.Y * 7 }, pixelSize, color, FLinearColor{ 54 / 255.f, 64 / 255.f, 26 / 255.f, 1.0f });
						ColorPixel(FVector2D{ pos.X + pixelSize.X * 11, pos.Y + pixelSize.Y * 8 }, pixelSize, color, FLinearColor{ 0 / 255.f, 0 / 255.f, 0 / 255.f, 1.0f });
					}



					if (isHoveredPicker)
					{
						if (input::is_mouse_clicked(0, elements_count, false))
						{

						}
					}
					else
					{
						if (input::is_mouse_clicked(0, elements_count, false))
						{
							active_picker = -1;
							//hover_element = false;
						}
					}
				}
				else
				{
					//Bg
					if (isHovered)
					{
						drawFilledRect(FVector2D{ pos.X, pos.Y }, size, size, colors::Checkbox_Hovered);
						hover_element = true;
					}
					else
					{
						drawFilledRect(FVector2D{ pos.X, pos.Y }, size, size, colors::Checkbox_Idle);
					}

					//Color
					drawFilledRect(FVector2D{ pos.X + 4, pos.Y + 4 }, size - 8, size - 8, *color);

					//Text
					FVector2D textPos = FVector2D{ pos.X + size + 5.0f, pos.Y - xsize + 6.0f };
					TextLeft(name, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);

					if (isHovered && input::is_mouse_clicked(0, elements_count, false))
					{
						saved_color = *color;
						active_picker = elements_count;
					}
				}


				sameLine = false;
				last_element_pos = pos;
				//last_element_size = size;
				if (first_element_pos.X == 0.0f)
					first_element_pos = pos;
			}
			void Render()
			{
				for (int i = 0; i < 128; i++)
				{
					if (PostRenderer::drawlist[i].type != -1)
					{
						//Filled Rect
						if (PostRenderer::drawlist[i].type == 1)
						{
							menu::drawFilledRect(PostRenderer::drawlist[i].pos, PostRenderer::drawlist[i].size.X, PostRenderer::drawlist[i].size.Y, PostRenderer::drawlist[i].color);
						}
						//TextLeft
						else if (PostRenderer::drawlist[i].type == 2)
						{
							canvas->K2_DrawText( (const wchar_t*)PostRenderer::drawlist[i].name, PostRenderer::drawlist[i].pos, FVector2D(0.98, 0.98), PostRenderer::drawlist[i].color, 0.0f, colors::Text_Shadow, FVector2D(0, 0), false, false, PostRenderer::drawlist[i].outline, colors::Text_Outline);
						}
						//TextCenter
						else if (PostRenderer::drawlist[i].type == 3)
						{
							menu::TextCenter((const wchar_t*)PostRenderer::drawlist[i].name, PostRenderer::drawlist[i].pos, PostRenderer::drawlist[i].color, PostRenderer::drawlist[i].outline);
						}
						//Draw_Line
						else if (PostRenderer::drawlist[i].type == 4)
						{
							Draw_Line(PostRenderer::drawlist[i].from, PostRenderer::drawlist[i].to, PostRenderer::drawlist[i].thickness, PostRenderer::drawlist[i].color);
						}

						PostRenderer::drawlist[i].type = -1;
					}
				}
			}

		}


	

	struct AGameObject
	{
		char pad_0[0x4a0];
		FText DisplayName;

		FVector GetObjectLocation()
		{
			SPOOF_FUNC;
			auto function_name = (L"Engine.Actor.K2_GetActorLocation");
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return FVector();

			struct {
				FVector Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}

		FText GetDisplayName()
		{
			SPOOF_FUNC;
			return this->DisplayName;
		}

		float GetObjectHealth()
		{
			SPOOF_FUNC;
			auto function_name = (L"ShooterGame.GameObject.GetHealth");
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!Function)
				return 0;

			struct {
				float Out;
			} Args;

			Function->ProcessEvent(this, Function, &Args);
			return Args.Out;
		}
	};
	namespace Filters
	{
		namespace Names
		{
			FString CharacterName(FString in)
			{
				if (in.ToString().find("Training") != std::string::npos)
					return FString(L"Bot Lobby");
				if (in.ToString().find("BountyHunter_PC_C") != std::string::npos)
					return FString(L"Fade");
				if (in.ToString().find("Stealth_PC_C") != std::string::npos)
					return FString(L"Yoru");
				if (in.ToString().find("Pandemic_PC_C") != std::string::npos)
					return FString(L"Viper");
				if (in.ToString().find("Hunter_PC_C") != std::string::npos)
					return FString(L"Sova");
				if (in.ToString().find("Guide_PC_C") != std::string::npos)
					return FString(L"Skye");
				if (in.ToString().find("Thorne_PC_C") != std::string::npos)
					return FString(L"Sage");
				if (in.ToString().find("Vampire_PC_C") != std::string::npos)
					return FString(L"Reyna");
				if (in.ToString().find("Clay_PC_C") != std::string::npos)
					return FString(L"Raze");
				if (in.ToString().find("Phoenix_PC_C") != std::string::npos)
					return FString(L"Phoenix");
				if (in.ToString().find("Wraith_PC_C") != std::string::npos)
					return FString(L"Omen");
				if (in.ToString().find("Sprinter_PC_C") != std::string::npos)
					return FString(L"Neon");
				if (in.ToString().find("Killjoy_PC_C") != std::string::npos)
					return FString(L"Killjoy");
				if (in.ToString().find("Grenadier_PC_C") != std::string::npos)
					return FString(L"Kayo");
				if (in.ToString().find("Terra_PC_C") != std::string::npos)
					return FString(L"Waylay");
				if (in.ToString().find("Cashew_PC_C") != std::string::npos)
					return FString(L"Tejo");
				if (in.ToString().find("Wushu_PC_C") != std::string::npos)
					return FString(L"Jett");
				if (in.ToString().find("Gumshoe_PC_C") != std::string::npos)
					return FString(L"Cypher");
				if (in.ToString().find("Deadeye_PC_C") != std::string::npos)
					return FString(L"Chamber");
				if (in.ToString().find("Sarge_PC_C") != std::string::npos)
					return FString(L"Brimstone");
				if (in.ToString().find("Breach_PC_C") != std::string::npos)
					return FString(L"Breach");
				if (in.ToString().find("Rift_TargetingForm_PC_C") != std::string::npos)
					return FString(L"Astra");
				if (in.ToString().find("Rift_PC_C") != std::string::npos)
					return FString(L"Astra");
				if (in.ToString().find("Mage_PC_C") != std::string::npos)
					return FString(L"Harbor");
				if (in.ToString().find("AggroBot_PC_C") != std::string::npos)
					return FString(L"Gekko");
				if (in.ToString().find("Cable_PC_C") != std::string::npos)
					return FString(L"DeadLock");
				if (in.ToString().find("Pawn_TrainingBot_DanceHall_Easy_C") != std::string::npos)
					return FString(L"Bot Lobby");
				if (in.ToString().find("Pawn_TrainingBot_Defuse_Ultimate_C") != std::string::npos)
					return FString(L"Bot Lobby");
				if (in.ToString().find("Sequoia_PC_C") != std::string::npos)
					return FString(L"Iso");
				if (in.ToString().find("Smonk_PC_C") != std::string::npos)
					return FString(L"Clove");
				if (in.ToString().find("Nox_PC_C") != std::string::npos)
					return FString(L"Vyse");
				else
					return FString(L"");
			}
			FString WeaponName(FString in)
			{
				if (in.ToString().find("Ability_Melee_Base_C") != std::string::npos)
					return FString(L"Knife");
				if (in.ToString().find("BasePistol_C") != std::string::npos)
					return FString(L"Classic");
				if (in.ToString().find("TrainingBotBasePistol_C") != std::string::npos)
					return FString(L"Classic");
				if (in.ToString().find("SawedOffShotgun_C") != std::string::npos)
					return FString(L"Shorty");
				if (in.ToString().find("AutomaticPistol_C") != std::string::npos)
					return FString(L"Frenzy");
				if (in.ToString().find("LugerPistol_C") != std::string::npos)
					return FString(L"Ghost");
				if (in.ToString().find("RevolverPistol_C") != std::string::npos)
					return FString(L"Sheriff");
				if (in.ToString().find("Vector_C") != std::string::npos)
					return FString(L"Stinger");
				if (in.ToString().find("SubMachineGun_MP5_C") != std::string::npos)
					return FString(L"Spectre");
				if (in.ToString().find("PumpShotgun_C") != std::string::npos)
					return FString(L"Bucky");
				if (in.ToString().find("AutomaticShotgun_C") != std::string::npos)
					return FString(L"Judge");
				if (in.ToString().find("AssaultRifle_Burst_C") != std::string::npos)
					return FString(L"Bulldog");
				if (in.ToString().find("DMR_C") != std::string::npos)
					return FString(L"Guardian");
				if (in.ToString().find("AssaultRifle_ACR_C") != std::string::npos)
					return FString(L"Phantom");
				if (in.ToString().find("AssaultRifle_AK_C") != std::string::npos)
					return FString(L"Vandal");
				if (in.ToString().find("LeverSniperRifle_C") != std::string::npos)
					return FString(L"Marshall");
				if (in.ToString().find("BoltSniper_C") != std::string::npos)
					return FString(L"Operator");
				if (in.ToString().find("LightMachineGun_C") != std::string::npos)
					return FString(L"Ares");
				if (in.ToString().find("HeavyMachineGun_C") != std::string::npos)
					return FString(L"Odin");
				if (in.ToString().find("DS_Gun_C") != std::string::npos)
					return FString(L"Outlaw");
				else
					return FString(L"");
			}

			FString ItsGamerDoc(FString in)
			{
				if (in.ToString().find("Ability_Melee_Base_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("BasePistol_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("TrainingBotBasePistol_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("SawedOffShotgun_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("AutomaticPistol_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("LugerPistol_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("RevolverPistol_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("Vector_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("SubMachineGun_MP5_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("PumpShotgun_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("AutomaticShotgun_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("AssaultRifle_Burst_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("DMR_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("AssaultRifle_ACR_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("AssaultRifle_AK_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("LeverSniperRifle_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("BoltSniper_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("LightMachineGun_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				if (in.ToString().find("HeavyMachineGun_C") != std::string::npos)
					return FString(L"ItsGamerDoc");
				else
					return FString(L"ItsGamerDoc");
			}
		}

	}
	namespace Class
	{
		UObject* ShooterGameObject()
		{
			SPOOF_FUNC;
			return UObject::StaticFindObject(nullptr, nullptr, (L"ShooterGame.GameObject"), false);
		}
	}

	namespace GameplayStatics
	{
		UObject* GameplayStatics()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"Engine.Default__GameplayStatics").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}

		TArray<AGameObject*> GetAllActorsOfClass(UWorld* WorldContext, UObject* Class)
		{
			auto function_name = (L"Engine.GameplayStatics.GetAllActorsOfClass");
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				UWorld* World;
				UObject* Class;
				TArray<AGameObject*> Out;
			} Args;

			Args.World = WorldContext;
			Args.Class = Class;
			Function->ProcessEvent(GameplayStatics(), Function, &Args);
			return Args.Out;
		}

		static inline UObject* get_game_instance(UWorld* world_context)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.GameplayStatics.GetGameInstance").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				UWorld* world_context;
				UObject* return_value;
			} params = { world_context };

			Function->ProcessEvent(GameplayStatics(), &params);
			return params.return_value;
		}
	}

	namespace KismetMathLibrary
	{
		UObject* KismetMathLibrary()
		{
			SPOOF_FUNC;
			auto class_name = ez(L"Engine.Default__KismetMathLibrary").d();
			return UObject::StaticFindObject(nullptr, nullptr, class_name, false);
		}

		FVector FindLookAtRotation(FVector start, FVector target)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.KismetMathLibrary.FindLookAtRotation").d();
			static UObject* Function = nullptr;

			if (!Function)
				Function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			struct {
				FVector start;
				FVector target;
				FVector out;
			} Args;

			Args.start = start;
			Args.target = target;
			Function->ProcessEvent(KismetMathLibrary(), Function, &Args);
			return Args.out;
		}

		float distance_2d(FVector2D v1, FVector2D v2)
		{
			SPOOF_FUNC;
			auto function_name = ez(L"Engine.KismetMathLibrary.Distance2D").d();
			UObject* function = UObject::StaticFindObject(nullptr, nullptr, function_name, false);

			if (!function)
				return 0;

			struct
			{
				FVector2D v1;
				FVector2D v2;
				float output;
			} params;

			params.v1 = v1;
			params.v2 = v2;

			function->ProcessEvent(KismetMathLibrary(), function, &params);

			return params.output;
		}
	}
	struct inventory_manager
	{

	};
	/*class currentequippable : public UObject
	{
	public:
		struct type {
			const wchar_t* search = nullptr;
			const char* config = nullptr;
			std::int32_t index = 0;

			const bool is_valid() const noexcept {
				return this->search != nullptr || this->config != nullptr;
			}
		};





		static inline currentequippable::type types[] = {
				{ L"basepistol", "classic" },
				{ L"sawedoffshotgun", "shorty" },
				{ L"automaticpistol", "frenzy" },
				{ L"lugerpistol", "ghost" },
				{ L"revolverpistol", "sheriff" },

				{ L"vector", "stinger" },
				{ L"submachinegun_mp5", "spectre" },

				{ L"pumpshotgun", "bucky" },
				{ L"automaticshotgun", "judge" },

				{ L"assaultrifle_burst", "bulldog" },
				{ L"dmr", "guardian" },
				{ L"assaultrifle_acr", "phantom" },
				{ L"assaultrifle_ak", "vandal" },

				{ L"leversniperrifle", "marshal" },
				{ L"boltsniper", "operator" },

				{ L"lightmachinegun", "ares" },
				{ L"heavymachinegun", "odin" },

				{ L"ability_melee_base", "knife" },

				{ L"gun_sprinter_x_heavylightninggun_production", "neon_x" },
				{ L"ability_wushu_x_dagger_production", "jett_dagger" }
		};

		currentequippable::type get_type() {
			const FString& name = system::get_object_name(this);

			for (std::int32_t index = 0; index < sizeof(currentequippable::types) / sizeof(currentequippable::type); index++) {
				currentequippable::type type = currentequippable::types[index];

				if (type.index == 0)
					type.index = index;

				if (system::starts_with(name.c_str(), type.search))
					return { type.search, type.config, type.index };
			}

			return {};
		}




		equippable_skin_data_asset* get_skin_data_asset();
	};*/
	struct skin_data_asset
	{
		int get_type()
		{
			SPOOF_FUNC;
			return Memory::R<int>(std::uintptr_t(this) + 0x38);
		}

		TArray<UObject*> get_levels()
		{
			SPOOF_FUNC;
			return Memory::R<TArray<UObject*>>(std::uintptr_t(this) + 0x88);
		}
	};

	struct invetory_chroma_asset
	{
		UObject* get_skin_chroma_asset()
		{
			SPOOF_FUNC;
			return Memory::R<UObject*>(std::uintptr_t(this) + 0x108);
		}
	};

	struct skin_inventory_model
	{
		skin_data_asset* get_skin_data_asset()
		{
			SPOOF_FUNC;
			return Memory::R<skin_data_asset*>(std::uintptr_t(this) + 0x108);
		}
		invetory_chroma_asset* get_skin_invetory_chroma_asset()
		{
			SPOOF_FUNC;
			return Memory::R<invetory_chroma_asset*>(std::uintptr_t(this) + 0x158);
		}
	};

	struct invetory_model
	{
		skin_inventory_model* get_equipped_skin()
		{
			SPOOF_FUNC;
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.EquippableInventoryModel.GetEquippedSkin", false);
			struct {
				skin_inventory_model* out;
			}Args;
			Function->ProcessEvent(this, Function, &Args);
			return Args.out;
		}
	};

	struct arsenal_view_model
	{
		TArray<invetory_model*> get_gun_models()
		{
			SPOOF_FUNC;
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ArsenalViewModel.GetGunModels", false);
			struct {
				TArray<invetory_model*> out;
			}Args;
			Function->ProcessEvent(this, Function, &Args);
			return Args.out;
		}
	};

	struct arsenal_view_controller
	{
		arsenal_view_model* get_arsenal_view_model()
		{
			SPOOF_FUNC;
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ArsenalViewController.GetViewModel", false);
			struct {
				arsenal_view_model* out;
			}Args;
			Function->ProcessEvent(this, Function, &Args);
			return Args.out;
		}
	};

	struct client_gameinstance
	{
		inventory_manager* get_inventory_manager()
		{
			SPOOF_FUNC;
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.AresClientGameInstance.GetInventoryManager", false);
			struct {
				inventory_manager* out;
			}Args;
			Function->ProcessEvent(this, Function, &Args);
			return Args.out;
		}
		arsenal_view_controller* get_arsenal_view_controller()
		{
			SPOOF_FUNC;
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.AresClientGameInstance.GetArsenalViewController", false);
			struct {
				arsenal_view_controller* out;
			}Args;
			Function->ProcessEvent(this, Function, &Args);
			return Args.out;
		}
		TArray<UObject*> get_all_spray_models()
		{
			SPOOF_FUNC;
			static UObject* function = nullptr;
			if (!function)
				function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.InventoryManager.GetAllSprayModels", false);

			struct {
				TArray<UObject*> return_value;
			} params = { };

			function->ProcessEvent(this, function, &params);

			return params.return_value;
		}
	};


	namespace ares_instance
	{
		UObject* AresIntanceStatic()
		{
			SPOOF_FUNC;
			return UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.Default__AresClientGameInstance", false);
		}

		client_gameinstance* get_ares_client_game_instance(UWorld* WORLD)
		{
			SPOOF_FUNC;
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.AresClientGameInstance.GetAresClientGameInstance", false);
			struct {
				UWorld* World;
				client_gameinstance* Class;
			}Args;
			Args.World = WORLD;
			Function->ProcessEvent(AresIntanceStatic(), Function, &Args);
			return Args.Class;
		}
	}
	namespace ContentLibrary
	{
		UObject* ContentLibrary()
		{
			SPOOF_FUNC;
			return UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.Default__ContentLibrary", false);
		}

		void ApplySkin(AAresEquippable* Equippable, UObject* SkinAsset, UObject* ChromaAsset, std::int32_t Level, UObject* CharmData, std::int32_t BuddieLevel)
		{
			SPOOF_FUNC;
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ContentLibrary.ApplySkin", false);
			struct {
				AAresEquippable* eqp;
				UObject* skinasset;
				UObject* chromaasset;
				std::int32_t level;
				UObject* charmdata;
				std::int32_t buddielevel;
			}Args;
			Args.eqp = Equippable;
			Args.skinasset = SkinAsset;
			Args.chromaasset = ChromaAsset;
			Args.level = Level;
			Args.charmdata = CharmData;
			Args.buddielevel = BuddieLevel;
			Function->ProcessEvent(ContentLibrary(), Function, &Args);
		}
		void ClearWeaponComponents(AAresEquippable* Equippable)
		{
			SPOOF_FUNC;
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ContentLibrary.ClearWeaponComponents", false);
			struct {
				AAresEquippable* Equippable;
			}Args;
			Args.Equippable = Equippable;
			Function->ProcessEvent(ContentLibrary(), Function, &Args);
		}
	}
	class system : public UObject
	{
	public:
		static FString get_object_name(UObject* object);
		static bool contains_string(const wchar_t* search_in, const wchar_t* sub_string, bool use_case = false, bool search_from_end = false);
		static bool starts_with(const wchar_t* source, const wchar_t* prefix, const enum_as_byte<search_case>& search_case = ignore_case);
		UObject* get_outer_object(UObject* object);

		/*static inline __int64 decrypt_parent(UObject* parent) {

			static __int64(__fastcall * decrypt_function)(__int64);
			if (!decrypt_function) {
				decrypt_function = reinterpret_cast<decltype(decrypt_function)>(Offsets::skin_decrypt + VALORANT::Module);
			}

			if (!decrypt_function) return 0x0;

			return decrypt_function((__int64)parent);
		}*/
	};

	class equippable_skin_data_asset : public UObject
	{
	public:
		/*int32_t get_type() {
			FString name = kismentsystemlibrary::get_object_name(this);

			if (string::contains(name, L"Default__BasePistol", true, false)) {
				return 1;
			}
			else if (string::contains(name, L"Default__SawedOffShotgun", true, false) || string::contains(name, L"Default__Slim", true, false)) {
				return 2;
			}
			else if (string::contains(name, L"Default__AutoPistol", true, false) || string::contains(name, L"Default__AutomaticPistol", true, false)) {
				return 3;
			}
			else if (string::contains(name, L"Default__Luger", true, false)) {
				return 4;
			}
			else if (string::contains(name, L"Default__Revolver", true, false)) {
				return 5;
			}
			else if (string::contains(name, L"Default__Vector", true, false)) {
				return 6;
			}
			else if (string::contains(name, L"Default__MP5", true, false) || string::contains(name, L"Default__SubMachineGun_MP5", true, false)) {
				return 7;
			}
			else if (string::contains(name, L"Default__PumpShotgun", true, false)) {
				return 8;
			}
			else if (string::contains(name, L"Default__AutomaticShotgun", true, false) || string::contains(name, L"Default__AutoShotgun", true, false)) {
				return 9;
			}
			else if (string::contains(name, L"Default__Burst", true, false) || string::contains(name, L"Default__AssaultRifle_Burst", true, false)) {
				return 10;
			}
			else if (string::contains(name, L"Default__DMR", true, false)) {
				return 11;
			}
			else if (string::contains(name, L"Default__AssaultRifle_ACR", true, false) || string::contains(name, L"Default__Carbine", true, false)) {
				return 12;
			}
			else if (string::contains(name, L"Default__AK", true, false) || string::contains(name, L"Default__AssaultRifle_AK", true, false)) {
				return 13;
			}
			else if (string::contains(name, L"Default__LeverSniperRifle", true, false) || string::contains(name, L"Default__LeverSniper", true, false)) {
				return 14;
			}
			else if (string::contains(name, L"Default__BoltSniper", true, false)) {
				return 15;
			}
			else if (string::contains(name, L"Default__LMG", true, false) || string::contains(name, L"Default__LightMachineGun", true, false)) {
				return 16;
			}
			else if (string::contains(name, L"Default__HMG", true, false) || string::contains(name, L"Default__HeavyMachineGun", true, false)) {
				return 17;
			}
			else if (string::contains(name, L"Default__Melee", true, false)) {
				return 18;
			}
			else if (string::contains(name, L"Default__DS_Gun", true, false)) {
				return 19;
			}
			return 0;
		}*/

		TArray<int> get_skin_levels();
	};

	namespace arsenal_view
	{
		invetory_model* get_aresnal_gun_models(int type_index)
		{
			SPOOF_FUNC;
			if (APlayerController* controller = ShooterGameBlueprints::GetFirstLocalPlayerController(UWorldSave))
				if (client_gameinstance* ares = ares_instance::get_ares_client_game_instance(UWorldSave))
					if (arsenal_view_controller* arsenal_view_controller = ares->get_arsenal_view_controller())
						if (arsenal_view_model* arsenal_view_model = arsenal_view_controller->get_arsenal_view_model())
						{
							auto models = arsenal_view_model->get_gun_models();
							for (int i = 0; i < models.Num(); i++)
							{
								auto model = models[i];
								if (!model)
									continue;
								if (skin_data_asset* skin_data = model->get_equipped_skin()->get_skin_data_asset())
								{
									if (int type = skin_data->get_type())
									{
										if (type == type_index)
										{
											return model;
										}
									}
								}
							}
						}
			return nullptr;
		}
	}

	void unlock_all_skins(UWorld* world) {
		SPOOF_FUNC;
		if (inventory_manager* manager = ares_instance::get_ares_client_game_instance(world)->get_inventory_manager()) {
			TArray<UObject*> equippable_models = Memory::R<TArray<UObject*>>(std::uintptr_t(manager) + 0xe0);

			for (int i = 0; i < equippable_models.Num(); i++) {
				if (auto model = equippable_models[i]) {
					TArray<UObject*> skins = Memory::R<TArray<UObject*>>(std::uintptr_t(model) + 0x150);

					if (skins.Num() > 0) {
						for (int A = 0; A < skins.Num(); A++) {
							if (auto skin = skins[A]) {

								TArray<UObject*> possible_levels = Memory::R<TArray<UObject*>>(std::uintptr_t(skin) + 0x138);
								for (int A = 0; A < possible_levels.Num(); A++)
									if (UObject* level = possible_levels[A])
										Memory::W<bool>(std::uintptr_t(level) + 0xfe, true),  // bIsUnlockedByConfig
										Memory::W<bool>(std::uintptr_t(level) + 0xf2, true);  // bIsOwned


								TArray<UObject*> possible_chromas = Memory::R<TArray<UObject*>>(std::uintptr_t(skin) + 0x128);
								for (int A = 0; A < possible_chromas.Num(); A++)
									if (UObject* chroma = possible_chromas[A])
										Memory::W<bool>(std::uintptr_t(chroma) + 0xfe, true),  // bIsUnlockedByConfig
										Memory::W<bool>(std::uintptr_t(chroma) + 0xf2, true);  // bIsOwned


								Memory::W<bool>(std::uintptr_t(skin) + 0xfe, true); // bIsUnlockedByConfig
								Memory::W<bool>(std::uintptr_t(skin) + 0xf3, true); // bIsFavorited
								Memory::W<bool>(std::uintptr_t(skin) + 0xf2, true); // bIsOwned

							}
						}
					}
				}
			}
		}
	}
	void unlock_all_apply(AAresEquippable* Equippable, UObject* skin_data_asset, UObject* skin_chroma_asset, int max_level, UObject* skin_charm_data_asset, int skin_charm_level_data_asset) {

		/*if (auto decrypted = system::decrypt_parent(Equippable)) {
			auto a1 = Memory::R<uintptr_t>(decrypted + Offsets::skin_pointer);
			if (a1) {
				a1 = Memory::R<uintptr_t>(a1 + Offsets::skin_pointer_2);
				if (a1) {
					auto old_value = Memory::R<int>(a1 + Offsets::skin_pointer_3);
					Memory::W<int>(a1 + Offsets::skin_pointer_3, 2);

					(ContentLibrary::ClearWeaponComponents)(Equippable);
					(ContentLibrary::ApplySkin)(Equippable, skin_data_asset, skin_chroma_asset, max_level, skin_charm_data_asset, skin_charm_level_data_asset);
					Memory::W<int>(a1 + Offsets::skin_pointer_3, old_value);
				}
			}
		}*/
	}
	template<class k, class e>
	class tmap
	{
	public:
		k Key;
		e Element;
		char __pad0x[0x8];
	};	
	FString BuddyName;
	UObject* buddy;
	namespace Skin
	{
		void ChangeSkin(AAresEquippable* Equippable, UObject* SkinAsset, UObject* ChromaAsset, std::int32_t Level, UWorld* world)
		{
			SPOOF_FUNC;

				

			inventory_manager* manager = ares_instance::get_ares_client_game_instance(world)->get_inventory_manager();

			auto charm_instances = Memory::R<TArray<tmap<UObject*, UObject*>>>(std::uintptr_t(manager) + 0x430);
			buddy = charm_instances[index].Key;
			auto ares_client_game_instance = ares_instance::get_ares_client_game_instance(world);
			auto v1 = *(uintptr_t*)(ares_client_game_instance + 0x360);
			auto v2 = *(uintptr_t*)(v1 + 0xB0);
			*(BYTE*)(v2 + 0x80) = 2;
			
			if (Globals::BuddyChanger)
			{ 
				ContentLibrary::ClearWeaponComponents(Equippable);
				ContentLibrary::ApplySkin(Equippable, SkinAsset, ChromaAsset, Level, buddy, 1);
				*(BYTE*)(v2 + 0x80) = 6;
			}
			else
			{
				ContentLibrary::ClearWeaponComponents(Equippable);
				ContentLibrary::ApplySkin(Equippable, SkinAsset, ChromaAsset, Level, nullptr, -1);
				*(BYTE*)(v2 + 0x80) = 6;
			}
			
			


		}
	}
	float DegreeToRadian(float degrees) {
		return degrees * (PI / 180);
	}
	void DrawTextRGB(UCanvas* canvas, const wchar_t* text, float X, float Y, FLinearColor color, bool CenterX = 0)
	{
		canvas->K2_DrawText(text, { X, Y }, { 1.1, 1.1 }, color, 0.f, { 0, 0, 0, 1 }, { 0, 0 }, CenterX, 0, bOutline, { 0, 0, 0, 1 });
	}
	void DrawTextSimple(UCanvas* canvas, const std::wstring& text, float X, float Y, FLinearColor color, bool CenterX = 0)
	{
		canvas->K2_DrawText(text.c_str(), { X, Y }, { 1.1, 1.1 }, color, 0.f, { 0, 0, 0, 1 }, { 0, 0 }, CenterX, 0, bOutline, { 0, 0, 0, 1 });
	}
	void DrawTextRGBWithFString(UCanvas* canvas, FString text, float X, float Y, FLinearColor color, bool CenterX = 0)
	{
		canvas->K2_DrawText(text, { X, Y }, { 1.1, 1.1 }, color, 0.f, { 0, 0, 0, 1 }, { 0, 0 }, CenterX, 0, bOutline, { 0, 0, 0, 1 });
	}
	void xxDrawTextRGB(UCanvas* canvas, FString text, float X, float Y, FLinearColor color)
	{
		canvas->K2_DrawText(text, { X, Y }, { 1.1, 1.1 }, color, 0.f, { 0, 0, 0, 1 }, { 0, 0 }, 0, 0, false, { 0, 0, 0, 1 });
	}

	__forceinline void Clamp2(FVector& Ang) {
		if (Ang.X < 0.f)
			Ang.X += 360.f;

		if (Ang.X > 360.f)
			Ang.X -= 360.f;

		if (Ang.Y < 0.f) Ang.Y += 360.f;
		if (Ang.Y > 360.f) Ang.Y -= 360.f;
		Ang.Z = 0.f;
	}
	void normalize2(FVector& in) {
		if (in.X > 89.f) in.X -= 360.f;
		else if (in.X < -89.f) in.X += 360.f;

		while (in.Y > 180)in.Y -= 360;
		while (in.Y < -180)in.Y += 360;
		in.Z = 0;
	}

	FVector smooth_aim2(FVector target, FVector delta_rotation, float smooth) {
		FVector diff = target - delta_rotation;
		normalize2(diff);
		return delta_rotation + diff / smooth;
	}
	struct FMinimalViewInfo {
		FVector Location;
		FVector Rotation;

		float FOV;
	};
	struct Bone {
		BYTE thing[0xCC];
		float X;
		BYTE thing2[0xC];
		float Y;
		BYTE thing3[0xC];
		float z;
	};
	boolean in_rect(double centerX, double centerY, double radius, double X, double Y) {
		return X >= centerX - radius && X <= centerX + radius &&
			Y >= centerY - radius && Y <= centerY + radius;
	}
	uintptr_t OffsetGetActorBounds;
	FVector GetBoneMatrix(void* Mesh, int Idx) {
		SPOOF_FUNC;
		FMatrix Matrix;
		reinterpret_cast<FMatrix* (__fastcall*)(void*, FMatrix*, int)>((uintptr_t)VALORANT::Module + Offsets::bone_matrix)(Mesh, &Matrix, Idx);
		return  { Matrix.WPlane.X, Matrix.WPlane.Y, Matrix.WPlane.Z };
	}
	FVector FindSkeleton(APlayerController* controller, void* mesh, int i)
	{
		SPOOF_FUNC;
		FVector2D drawtextat;
		return controller->ProjectWorldLocationToScreen(GetBoneMatrix(mesh, i), drawtextat, 0);
	}

	static FVector2D scr[8];
	void FMath::SinCos(float* ScalarSin, float* ScalarCos, float Value)
	{
		float quotient = (INV_PI * 0.5f) * Value;
		if (Value >= 0.0f)
		{
			quotient = (float)((int)(quotient + 0.5f));
		}
		else
		{
			quotient = (float)((int)(quotient - 0.5f));
		}
		float Y = Value - (2.0f * PI) * quotient;
		float sign;
		if (Y > HALF_PI)
		{
			Y = PI - Y;
			sign = -1.0f;
		}
		else if (Y < -HALF_PI)
		{
			Y = -PI - Y;
			sign = -1.0f;
		}
		else
		{
			sign = +1.0f;
		}

		float y2 = Y * Y;

		*ScalarSin = (((((-2.3889859e-08f * y2 + 2.7525562e-06f) * y2 - 0.00019840874f) * y2 + 0.0083333310f) * y2 - 0.16666667f) * y2 + 1.0f) * Y;

		float p = ((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f;
		*ScalarCos = sign * p;
	}
	float FMath::Fmod(float X, float Y)
	{
		const float AbsY = fabsf(Y);
		if (AbsY <= 1.e-8f) { return 0.f; }
		const float Div = (X / Y);

		const float Quotient = fabsf(Div) < FLOAT_NON_FRACTIONAL ? truncf(Div) : Div;
		float IntPortion = Y * Quotient;


		if (fabsf(IntPortion) > fabsf(X)) { IntPortion = X; }

		const float Result = X - IntPortion;

		return FMath::Clamp(Result, -AbsY, AbsY);
	}

	FQuat FRotator::Quaternion() const
	{
		float SP, SY, SR;
		float CP, CY, CR;
		const float PitchNoWinding = FMath::Fmod(Pitch, 360.0f);
		const float YawNoWinding = FMath::Fmod(Yaw, 360.0f);
		const float RollNoWinding = FMath::Fmod(Roll, 360.0f);
		FMath::SinCos(&SP, &CP, PitchNoWinding * RADS_DIVIDED_BY_2);
		FMath::SinCos(&SY, &CY, YawNoWinding * RADS_DIVIDED_BY_2);
		FMath::SinCos(&SR, &CR, RollNoWinding * RADS_DIVIDED_BY_2);
		FQuat RotationQuat;
		RotationQuat.X = CR * SP * SY - SR * CP * CY;
		RotationQuat.Y = -CR * SP * CY - SR * CP * SY;
		RotationQuat.Z = CR * CP * SY - SR * SP * CY;
		RotationQuat.W = CR * CP * CY + SR * SP * SY;
		return RotationQuat;
	}
	const FVector FVector::ZeroVector(0.0f, 0.0f, 0.0f);
	const FVector FVector::OneVector(1.0f, 1.0f, 1.0f);
	FVector FTransform::TransformPosition(FVector& V) const
	{
		return Rotation.RotateVector(Scale3D * V) + Translation;
	}
	FVector FQuat::RotateVector(const FVector& V) const
	{
		const FVector Q(X, Y, Z);
		const FVector T = (Q ^ V) * 2.f;
		const FVector Result = V + (T * W) + (Q ^ T);
		return Result;
	}

	namespace NoSpread
	{

		FVector get_error_angle(uint64_t actor, uint64_t firing_state_component) {
			auto get_spread_values_fn =
				(float* (__fastcall*)(uint64_t, float*))(VALORANT::Module + Offsets::get_spread_values);
			auto get_spread_angles_fn =
				(void(__fastcall*)(uint64_t, FVector*, float, float, int, int, uint64_t))(VALORANT::Module + Offsets::get_spread_values);
			auto get_firing_location_and_direction_fn =
				(void(__fastcall*)(uint64_t, FVector*, FVector*))(VALORANT::Module + Offsets::get_firing_location_direction);
			auto to_vector_and_normalize_fn =
				(FVector * (__fastcall*)(FVector*, FVector*))(VALORANT::Module + Offsets::tovector_and_normalize);
			auto to_angle_and_normalize_fn =
				(FVector * (__fastcall*)(FVector*, FVector*))(VALORANT::Module + Offsets::tovector_and_normalize);

			static uint8_t error_values[4096];
			static uint8_t seed_data_snapshot[4096];
			static uint8_t spread_angles[4096];
			static uint8_t out_spread_angles[4096];

			if (!actor || !firing_state_component)
				return FVector(0, 0, 0);

			memset(error_values, 0, sizeof(error_values));
			memset(seed_data_snapshot, 0, sizeof(seed_data_snapshot));
			memset(spread_angles, 0, sizeof(spread_angles));
			memset(out_spread_angles, 0, sizeof(out_spread_angles));

			*(uint64_t*)(&out_spread_angles[0]) = (uint64_t)&spread_angles[0];
			*(int*)(&out_spread_angles[0] + 8) = 1;
			*(int*)(&out_spread_angles[0] + 12) = 1;

			uint64_t seed_data = *(uint64_t*)(firing_state_component + Offsets::seed_data);
			memcpy((void*)seed_data_snapshot, (void*)seed_data, sizeof(seed_data_snapshot)); //Make our own copy since we don't want to desync our own seed component

			uint64_t stability_component = *(uint64_t*)(firing_state_component + Offsets::stability_component);
			if (stability_component)
				get_spread_values_fn(stability_component, (float*)&error_values[0]);

			FVector temp1, temp2 = FVector(0, 0, 0);
			FVector previous_firing_direction, firing_direction = FVector(0, 0, 0);
			get_firing_location_and_direction_fn(actor, &temp1, &previous_firing_direction);
			to_vector_and_normalize_fn(&previous_firing_direction, &temp2);
			to_angle_and_normalize_fn(&temp2, &temp1);
			previous_firing_direction = temp1;
			temp1.X += *(float*)(&error_values[0] + 12); //Your recoil angle
			temp1.Y += *(float*)(&error_values[0] + 16);
			to_vector_and_normalize_fn(&temp1, &firing_direction);

			float error_degrees = *(float*)(&error_values[0] + 8) + *(float*)(&error_values[0] + 4);
			float error_power = *(float*)(firing_state_component + Offsets::error_power); // OK
			int error_retries = *(int*)(firing_state_component + Offsets::error_retries); // OK
			get_spread_angles_fn(((uint64_t)&seed_data_snapshot[0]) + 0xE8, &firing_direction, error_degrees, error_power, error_retries, 1, (uint64_t)&out_spread_angles[0]);

			FVector spread_vector = *(FVector*)(&spread_angles[0]);
			to_angle_and_normalize_fn(&spread_vector, &firing_direction);

			return firing_direction - previous_firing_direction;
		}


		inline FVector GetErrorAngle(uint64_t actor, uint64_t firing_state_component) {
			static auto get_spread_values_fn = (float* (__fastcall*)(uint64_t, float*))(VALORANT::Module + Offsets::get_spread_values);
			static auto get_spread_angles_fn = (void(__fastcall*)(uint64_t, FVector*, float, float, int, int, uint64_t))(VALORANT::Module + Offsets::get_spread_angles);
			static auto get_firing_location_and_direction_fn = (void(__fastcall*)(uint64_t, FVector*, FVector*))(VALORANT::Module + Offsets::get_firing_location_direction);
			static auto to_vector_and_normalize_fn = (FVector * (__fastcall*)(FVector*, FVector*))(VALORANT::Module + Offsets::tovector_and_normalize);
			static auto to_angle_and_normalize_fn = (FVector * (__fastcall*)(FVector*, FVector*))(VALORANT::Module + Offsets::toangle_and_normalize);
			if (get_spread_values_fn && get_spread_angles_fn && get_firing_location_and_direction_fn && to_vector_and_normalize_fn && to_angle_and_normalize_fn)
			{

				static uint8_t error_values[4096] = { 0 };
				static uint8_t seed_data_snapshot[4096] = { 0 };
				static uint8_t spread_angles[4096] = { 0 };
				static uint8_t out_spread_angles[4096] = { 0 };

				if (!actor || !firing_state_component)
					return NULL;

				memset(error_values, 0, sizeof(error_values));
				memset(seed_data_snapshot, 0, sizeof(seed_data_snapshot));
				memset(spread_angles, 0, sizeof(spread_angles));
				memset(out_spread_angles, 0, sizeof(out_spread_angles));

				*(uint64_t*)(&out_spread_angles[0]) = (uint64_t)&spread_angles[0];
				*(int*)(&out_spread_angles[0] + 8) = 1;
				*(int*)(&out_spread_angles[0] + 12) = 1;

				uint64_t seed_data = Memory::R<uint64_t>(firing_state_component + Offsets::seed_data);
				if (!seed_data || seed_data > 9999999999999 || seed_data < 1000000000000) {
					return NULL;
				}

				memcpy((void*)seed_data_snapshot, (void*)seed_data, sizeof(seed_data_snapshot));

				uint64_t stability_component = Memory::R<uint64_t>(firing_state_component + Offsets::stability_component);
				if (stability_component)
					get_spread_values_fn(stability_component, (float*)&error_values[0]);

				FVector temp1, temp2 = FVector(0, 0, 0);
				FVector previous_firing_direction, firing_direction = FVector(0, 0, 0);
				get_firing_location_and_direction_fn(actor, &temp1, &previous_firing_direction);
				to_vector_and_normalize_fn(&previous_firing_direction, &temp2);
				to_angle_and_normalize_fn(&temp2, &temp1);
				previous_firing_direction = temp1;
				temp1.X += *(float*)(&error_values[0] + 12);
				temp1.Y += *(float*)(&error_values[0] + 16);
				to_vector_and_normalize_fn(&temp1, &firing_direction);

				float error_degrees = *(float*)(&error_values[0] + 8) + *(float*)(&error_values[0] + 4);
				if (firing_state_component != -1008 && firing_state_component != -1012)
				{
					float error_power = *(float*)(firing_state_component + Offsets::error_power);
					int error_retries = *(int*)(firing_state_component + Offsets::error_retries);
					if (error_degrees == 0) {
						return NULL;
					}
					get_spread_angles_fn(((uint64_t)&seed_data_snapshot[0]) + 0xE8, &firing_direction, error_degrees, error_power, error_retries, 1, (uint64_t)&out_spread_angles[0]);

					FVector spread_vector = *(FVector*)(&spread_angles[0]);
					to_angle_and_normalize_fn(&spread_vector, &firing_direction);

					FVector spread_out = firing_direction - previous_firing_direction;
					if (spread_out.X > 10000 || spread_out.Y > 10000 || spread_out.Z > 10000)
						return NULL;
					return spread_out;
				}
				else
				{
					return NULL;
				}

			}
			return NULL;
		}

		

	}

	void angle_rotation(const FVector& angles, FVector* forward)
	{
		float	sp, sy, cp, cy;

		sy = sin(DegreeToRadian(angles.Y));
		cy = cos(DegreeToRadian(angles.Y));

		sp = sin(DegreeToRadian(angles.X));
		cp = cos(DegreeToRadian(angles.X));

		forward->X = cp * cy;
		forward->Y = cp * sy;
		forward->Z = -sp;
	}

	void AntiAfk() {
		SPOOF_FUNC;
		if (!GetAsyncKeyState(0x57) || !GetAsyncKeyState(0x41) || GetAsyncKeyState(0x44) || GetAsyncKeyState(0x53)) {
			INPUT space = { 0 };
			space.ki.wVk = VK_SPACE;
			space.type = INPUT_KEYBOARD;
			SendInput(1, &space, sizeof(INPUT));
			Sleep(rand() % 5 + 1);
			space.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &space, sizeof(INPUT));
		}

	}

	void mouse_shoot(BYTE key, bool set) {
		SPOOF_FUNC;
		keybd_event(key,
			0x45,
			set ? (KEYEVENTF_EXTENDEDKEY | 0) : (KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP),
			0);
	}
	void FovChanger(APlayerController* MyController) {
		SPOOF_FUNC;
		MyController->set_fov(Globals::FovChangerValue);
	}
	enum Bones : int {
		head = 8,
		base = 0,
		CestBone = 6,
		Leg = 4
	};

	void DrawLineSimple(UCanvas* can, FVector2D first_bone_position, FVector2D second_bone_position, FLinearColor Color)
	{

		can->K2_DrawLine({ first_bone_position.X, first_bone_position.Y }, { second_bone_position.X, second_bone_position.Y }, Globals::ESPThickness, Color);
	}
	void DrawBox(UCanvas* can, FVector2D& topleft, FVector2D& downright, FLinearColor clr)
	{
		auto h = downright.Y - topleft.Y;
		auto w = downright.X - topleft.X;

		auto downleft = FVector2D{ topleft.X , downright.Y };
		auto topright = FVector2D{ downright.X, topleft.Y };

		auto thicc = Globals::ESPThickness;

		FLinearColor xclr = RGBtoFLC(0, 0, 0);

		can->K2_DrawLinex(topleft, { downright.X, topleft.Y }, thicc, clr);
		can->K2_DrawLinex(topleft, { topleft.X , downright.Y }, thicc, clr);
		can->K2_DrawLinex(downright, { topleft.X , downright.Y }, thicc, clr);
		can->K2_DrawLinex(downright, { downright.X, topleft.Y }, thicc, clr);
	}
	namespace helper {
		FString convert_weapon_name(FString weapon_name)
		{
			std::wstring weapon_name_str = weapon_name.wide();

			if (weapon_name_str.find(L"Ability_Melee_Base_C") != std::wstring::npos)
				return L"Melee";
			else if (weapon_name_str.find(L"BasePistol_C") != std::wstring::npos)
				return L"Classic";
			else if (weapon_name_str.find(L"SawedOffShotgun_C") != std::wstring::npos)
				return L"Shorty";
			else if (weapon_name_str.find(L"AutomaticPistol_C") != std::wstring::npos)
				return L"Frenzy";
			else if (weapon_name_str.find(L"LugerPistol_C") != std::wstring::npos)
				return L"Ghost";
			else if (weapon_name_str.find(L"RevolverPistol_C") != std::wstring::npos)
				return L"Sheriff";
			else if (weapon_name_str.find(L"Vector_C") != std::wstring::npos)
				return L"Stinger";
			else if (weapon_name_str.find(L"SubMachineGun_MP5") != std::wstring::npos)
				return L"Spectre";
			else if (weapon_name_str.find(L"PumpShotgun_C") != std::wstring::npos)
				return L"Bucky";
			else if (weapon_name_str.find(L"AutomaticShotgun_C") != std::wstring::npos)
				return L"Judge";
			else if (weapon_name_str.find(L"AssaultRifle_Burst_C") != std::wstring::npos)
				return L"Bulldog";
			else if (weapon_name_str.find(L"DMR_C") != std::wstring::npos)
				return L"Guardian";
			else if (weapon_name_str.find(L"AssaultRifle_ACR_C") != std::wstring::npos)
				return L"Phantom";
			else if (weapon_name_str.find(L"AssaultRifle_AK_C") != std::wstring::npos)
				return L"Vandal";
			else if (weapon_name_str.find(L"LeverSniperRifle_C") != std::wstring::npos)
				return L"Marshal";
			else if (weapon_name_str.find(L"BoltSniper_C") != std::wstring::npos)
				return L"Operator";
			else if (weapon_name_str.find(L"LightMachineGun_C") != std::wstring::npos)
				return L"Ares";
			else if (weapon_name_str.find(L"HeavyMachineGun_C") != std::wstring::npos)
				return L"Odin";
			else if (weapon_name_str.find(L"Gun_Deadeye_Q_Pistol_C") != std::wstring::npos)
				return L"Headhunter";
			else if (weapon_name_str.find(L"Ability_Wushu_X_Dagger_Production_C") != std::wstring::npos)
				return L"Blade storm";
			else if (weapon_name_str.find(L"Gun_Sprinter_X_HeavyLightningGun_Production_C") != std::wstring::npos)
				return L"Overdrive";
			else if (weapon_name_str.find(L"DS_Gun_C") != std::wstring::npos)
				return L"Outlaw";
			else if (weapon_name_str.find(L"Gun_Deadeye_X_Giantslayer_Prototype_C") != std::wstring::npos)
				return L"Tour de force";
			return L"Invalid";
		}
	}

	namespace pos_decrpt {
		FVector2D pos = {
		((float)GetSystemMetrics(SM_CXSCREEN) / 2) - 500,
		((float)GetSystemMetrics(SM_CYSCREEN) / 2) - 475
		};
	}
	void DrawLineSimple_3D(UCanvas* can, FVector2D first_bone_position, FVector2D second_bone_position, FLinearColor Color) {
		can->K2_DrawLine({ first_bone_position.X, first_bone_position.Y }, { second_bone_position.X, second_bone_position.Y }, 1.15f, Color);
	}
	void DrawLineSimple_Spike(UCanvas* can, FVector2D first_bone_position, FVector2D second_bone_position, FLinearColor Color) {
		can->K2_DrawLine({ first_bone_position.X, first_bone_position.Y }, { second_bone_position.X, second_bone_position.Y }, 0.9f, Color);
	}
	void Draw3DDiamond(UCanvas* Canvas, APlayerController* MYController, FVector ObjectLocation3D, float BaseLength, float Height, FLinearColor Color)
	{

		FVector Pos0, Pos1, Pos2, Pos3, Pos4, Pos5;
		Pos0 = ObjectLocation3D;
		Pos0.Z += 20;
		Pos1 = Pos0 + FVector(-BaseLength / 2, 0, 0);
		Pos2 = Pos0 + FVector(BaseLength / 2, 0, 0);
		Pos3 = Pos0 + FVector(0, -BaseLength / 2, 0);
		Pos4 = Pos0 + FVector(0, BaseLength / 2, 0);
		Pos5 = Pos0 + FVector(0, 0, Height);

		FVector2D ScreenPos0, ScreenPos1, ScreenPos2, ScreenPos3, ScreenPos4, ScreenPos5;
		if (MYController->ProjectWorldLocationToScreen(Pos0, ScreenPos0, 0) && ScreenPos0.IsValid() &&
			MYController->ProjectWorldLocationToScreen(Pos1, ScreenPos1, 0) && ScreenPos1.IsValid() &&
			MYController->ProjectWorldLocationToScreen(Pos2, ScreenPos2, 0) && ScreenPos2.IsValid() &&
			MYController->ProjectWorldLocationToScreen(Pos3, ScreenPos3, 0) && ScreenPos3.IsValid() &&
			MYController->ProjectWorldLocationToScreen(Pos4, ScreenPos4, 0) && ScreenPos4.IsValid() &&
			MYController->ProjectWorldLocationToScreen(Pos5, ScreenPos5, 0) && ScreenPos5.IsValid())
		{
			// Draw lines between points to create the 3D triangle
			DrawLineSimple_Spike(Canvas, ScreenPos1, ScreenPos2, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos2, ScreenPos3, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos3, ScreenPos1, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos1, ScreenPos4, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos2, ScreenPos4, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos3, ScreenPos4, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos0, ScreenPos5, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos1, ScreenPos5, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos2, ScreenPos5, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos3, ScreenPos5, Color);
			DrawLineSimple_Spike(Canvas, ScreenPos4, ScreenPos5, Color);
		}

	}

	void Draw3D(UCanvas* Canvas, APlayerController* MYController, USkeletalMeshComponent* Mesh, FLinearColor Color)
	{
		FVector2D bottom1;
		FVector2D bottom2;
		FVector2D bottom3;
		FVector2D bottom4;
		FVector2D top1;
		FVector2D top2;
		FVector2D top3;
		FVector2D top4;
		FVector vBaseBone = GetBoneMatrix(Mesh, 0);
		FVector vHeadBone = GetBoneMatrix(Mesh, 8);
		if (MYController->ProjectWorldLocationToScreen(FVector(vBaseBone.X + 53, vBaseBone.Y - 55, vBaseBone.Z), bottom1, 0) && bottom1.IsValid())
		{
			if (MYController->ProjectWorldLocationToScreen(FVector(vBaseBone.X - 53, vBaseBone.Y - 55, vBaseBone.Z), bottom2, 0) && bottom2.IsValid())
			{
				if (MYController->ProjectWorldLocationToScreen(FVector(vBaseBone.X - 53, vBaseBone.Y + 55, vBaseBone.Z), bottom3, 0) && bottom3.IsValid())
				{
					if (MYController->ProjectWorldLocationToScreen(FVector(vBaseBone.X + 53, vBaseBone.Y + 55, vBaseBone.Z), bottom4, 0) && bottom4.IsValid())
					{
						if (MYController->ProjectWorldLocationToScreen(FVector(vHeadBone.X + 53, vHeadBone.Y - 55, vHeadBone.Z + 26), top1, 0) && top1.IsValid())
						{
							if (MYController->ProjectWorldLocationToScreen(FVector(vHeadBone.X - 53, vHeadBone.Y - 55, vHeadBone.Z + 26), top2, 0) && top2.IsValid())
							{
								if (MYController->ProjectWorldLocationToScreen(FVector(vHeadBone.X - 53, vHeadBone.Y + 55, vHeadBone.Z + 26), top3, 0) && top3.IsValid())
								{
									if (MYController->ProjectWorldLocationToScreen(FVector(vHeadBone.X + 53, vHeadBone.Y + 55, vHeadBone.Z + 26), top4, 0) && top4.IsValid())
									{

										DrawLineSimple_3D(Canvas, bottom1, top1, Color);
										DrawLineSimple_3D(Canvas, bottom1, top1, Color);
										DrawLineSimple_3D(Canvas, bottom2, top2, Color);
										DrawLineSimple_3D(Canvas, bottom3, top3, Color);
										DrawLineSimple_3D(Canvas, bottom4, top4, Color);


										DrawLineSimple_3D(Canvas, bottom1, bottom2, Color);
										DrawLineSimple_3D(Canvas, bottom2, bottom3, Color);
										DrawLineSimple_3D(Canvas, bottom3, bottom4, Color);
										DrawLineSimple_3D(Canvas, bottom4, bottom1, Color);

										DrawLineSimple_3D(Canvas, top1, top2, Color);
										DrawLineSimple_3D(Canvas, top2, top3, Color);
										DrawLineSimple_3D(Canvas, top3, top4, Color);
										DrawLineSimple_3D(Canvas, top4, top1, Color);
									}
								}
							}
						}
					}
				}
			}

		}

	}
	namespace health {
		FLinearColor HealthColor;
		static FLinearColor HighHealth = { 0.0f,255.0f,0.0f,1.0f };
		static FLinearColor NormalHealth = { 255, 151, 0 ,1.0f };
		static FLinearColor LowHealth = { 255.0f,0.0f,0.f,1.0f };
	}
	void DrawLineBottomLocation(UCanvas* canvas, APlayerController* MyController, USkeletalMeshComponent* Mesh) {
		FVector2D drawtextat;
		if (MyController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 0), drawtextat, 0) && drawtextat.IsValid()) {
			canvas->K2_DrawLine({ (float)canvas->GetScreenSize().X / 2, (float)canvas->GetScreenSize().Y / 1 }, drawtextat, Globals::ESPThickness, Colors::LineColor);
		}
	}

	void DrawLineTopLocation(UCanvas* canvas, APlayerController* MyController, USkeletalMeshComponent* Mesh) {
		FVector2D drawtextat;
		if (MyController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 8), drawtextat, 0) && drawtextat.IsValid()) {
			canvas->K2_DrawLine({ (float)canvas->GetScreenSize().X / 2, (float)canvas->GetScreenSize().Y / 800.0f }, drawtextat, Globals::ESPThickness, Colors::LineColor);
		}
	}
	void DrawEspText(UCanvas* canvas, const FString& text, const FVector2D& position, const FVector2D& scale, const FLinearColor& color, float shadowOpacity = 0.75f)
	{
		canvas->K2_DrawText(text, position, scale, color, false, menu::colors::Text_Shadow, FVector2D{ pos_decrpt::pos.X + 1, pos_decrpt::pos.Y + 1 }, true, true, true, { 0,0,0,shadowOpacity });
	}

	void DrawAgentNameEsp_noneHealth(UCanvas* canvas, UObject* actor, const FVector2D& baseOut, USkeletalMeshComponent* Mesh, APlayerController* myController, float boxWidth, float distance) {
		if (Globals::AgentName && distance >= 1.2f) {
			FString objectName = kismentsystemlibrary::get_object_name((UObject*)actor);
			float X = baseOut.X - (boxWidth / 2), Y = baseOut.Y + (boxWidth / 10.0f);
			FVector2D vHeadBoneOut;
			if (myController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 8), vHeadBoneOut, 0) && vHeadBoneOut.IsValid()) {
				DrawEspText(canvas, Filters::Names::CharacterName(objectName), FVector2D(baseOut.X, baseOut.Y + 15.0f), FVector2D{ 0.8f ,0.8f }, Colors::AgentNameColor);
			}
		}
	}
	void DrawAgentNameEsp(UCanvas* canvas, UObject* actor, const FVector2D& baseOut, USkeletalMeshComponent* Mesh, APlayerController* myController, float boxWidth, float distance) {
		if (Globals::AgentName && distance >= 1.2f) {
			FString objectName = kismentsystemlibrary::get_object_name((UObject*)actor);
			float X = baseOut.X - (boxWidth / 2), Y = baseOut.Y + (boxWidth / 10.0f);
			FVector2D vHeadBoneOut;
			if (myController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 8), vHeadBoneOut, 0) && vHeadBoneOut.IsValid()) {
				DrawEspText(canvas, Filters::Names::CharacterName(objectName), FVector2D(baseOut.X, baseOut.Y + 25.0f), FVector2D{ 0.8f, 0.8f }, Colors::AgentNameColor);
			}
		}
	}
	static void agent_icon(AShooterCharacter* actor, FVector2D base_out, float distance, UCanvas* canvas) {

		UObject* icon = actor->get_character_icon();

		if (!icon || !canvas || distance <= 0.0f)
			return;

		FVector2D baseSize = FVector2D(8.5f, 8.5f);
		float scaleFactor = 100.0f / distance;
		FVector2D size = baseSize * scaleFactor;

		actor->k2_drawtexture(icon, base_out, size,
			FVector2D(0.0f, 0.0f),
			FVector2D(1.0f, 1.0f),
			FLinearColor(1, 1, 1, 1), e_blend_mode::translucent, 0.0f, FVector2D(0.5f, 0.5f));
	}
	void DrawAgentNameEsp_dist8(UCanvas* canvas, UObject* actor, const FVector2D& baseOut, USkeletalMeshComponent* Mesh, APlayerController* myController, float boxWidth, float distance) {
		if (Globals::AgentName && distance >= 1.2f) {
			FString objectName = kismentsystemlibrary::get_object_name((UObject*)actor);
			float X = baseOut.X - (boxWidth / 2), Y = baseOut.Y + (boxWidth / 10.0f);
			FVector2D vHeadBoneOut;

			FVector2D newSize;
			if (distance >= 16) {
				FVector2D baseSize = FVector2D(0.20f, 0.20f);
				float scaleFactor = 100.0f / distance;
				newSize = baseSize * scaleFactor;
			}
			else {
				newSize = FVector2D(1.2f, 1.2f);
			}

			if (myController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 8), vHeadBoneOut, 0) && vHeadBoneOut.IsValid()) {
				DrawEspText(canvas, Filters::Names::CharacterName(objectName), FVector2D(baseOut.X, baseOut.Y + 40.0f), FVector2D{ 0.8f, 0.8f }, Colors::AgentNameColor);
			}
		}
	}
	void Draw2DBox(UCanvas* canvas, APlayerController* MyController, USkeletalMeshComponent* Mesh, const FLinearColor& color) {
		FVector2D HeadPos;
		if (!MyController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 8), HeadPos, 0) || !HeadPos.IsValid()) {
			return;
		}

		FVector2D FootPos;
		if (!MyController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 0), FootPos, 0) || !FootPos.IsValid()) {
			return;
		}

		const float height = abs(FootPos.Y - HeadPos.Y);
		const float width = height * 0.45f;
		FVector2D top = { HeadPos.X - width * 0.5f, FootPos.Y };
		FVector2D bottom = { HeadPos.X + width * 0.5f, HeadPos.Y };
		DrawBox(canvas, top, bottom, color);
	}
	void DrawCorner(UCanvas* Canvas, APlayerController* MYController, USkeletalMeshComponent* Mesh, FLinearColor Color, float thick) {

		FVector Head = GetBoneMatrix(Mesh, 8);
		FVector2D HeadLongOut = MYController->ProjectWorldToScreen(FVector(Head.X, Head.Y, Head.Z + 15));
		FVector Base = GetBoneMatrix(Mesh, 0);
		FVector2D BaseOut = MYController->ProjectWorldToScreen(Base);

		float BoxHeight = abs(HeadLongOut.Y - BaseOut.Y);
		float BoxWidth = BoxHeight * 0.55;

		float X = HeadLongOut.X - (BoxWidth / 2), Y = HeadLongOut.Y;
		float lineW = (BoxWidth / 3);
		float lineH = (BoxHeight / 3);
		Canvas->K2_DrawLine(FVector2D(X, Y), FVector2D(X, Y + lineH), thick, Colors::BoxColor);
		Canvas->K2_DrawLine(FVector2D(X, Y), FVector2D(X + lineW, Y), thick, Colors::BoxColor);
		Canvas->K2_DrawLine(FVector2D(X + BoxWidth - lineW, Y), FVector2D(X + BoxWidth, Y), thick, Colors::BoxColor);
		Canvas->K2_DrawLine(FVector2D(X + BoxWidth, Y), FVector2D(X + BoxWidth, Y + lineH), thick, Colors::BoxColor);
		Canvas->K2_DrawLine(FVector2D(X, Y + BoxHeight - lineH), FVector2D(X, Y + BoxHeight), thick, Colors::BoxColor);
		Canvas->K2_DrawLine(FVector2D(X, Y + BoxHeight), FVector2D(X + lineW, Y + BoxHeight), thick, Colors::BoxColor);
		Canvas->K2_DrawLine(FVector2D(X + BoxWidth - lineW, Y + BoxHeight), FVector2D(X + BoxWidth, Y + BoxHeight), thick, Colors::BoxColor);
		Canvas->K2_DrawLine(FVector2D(X + BoxWidth, Y + BoxHeight - lineH), FVector2D(X + BoxWidth, Y + BoxHeight), thick, Colors::BoxColor);
	}
	void DrawSnapline(UCanvas* canvas, AShooterCharacter* shooter, FVector2D headOut, FLinearColor color, float tick) {
		if (shooter->IsAlive()) {
			float radius = 54;
			float A = headOut.Y - (float)canvas->GetScreenSize().Y / 2;
			float B = headOut.X - (float)canvas->GetScreenSize().X / 2;
			float x3, y3;
			float angle = atan(A / B);

			if (B >= 0) {
				x3 = radius * cos(angle) + (float)canvas->GetScreenSize().X / 2;
				y3 = radius * sin(angle) + (float)canvas->GetScreenSize().Y / 2;
			}
			else {
				x3 = radius * (-cos(angle)) + (float)canvas->GetScreenSize().X / 2;
				y3 = radius * (-sin(angle)) + (float)canvas->GetScreenSize().Y / 2;
			}

			if (sqrt(A * A + B * B) >= radius) {
				canvas->K2_DrawLine(FVector2D(headOut.X, headOut.Y), FVector2D(x3, y3), tick, color);
			}
		}
	}
	void DrawHealthAndShieldBars(UCanvas* canvas, float health, float shield, FVector2D headPos, FVector2D footPos, float distance)
	{
		const int boxHeight = abs(footPos.Y - headPos.Y);
		const int boxWidth = boxHeight * 0.45f;

		const int barHeight = boxHeight;
		const int barThickness = 2;  // Thinner bars
		const int barOffset = 5;

		const int barX_Health = headPos.X - (boxWidth * 0.5f) - barOffset - barThickness;
		const int barX_Shield = barX_Health - barThickness - 2;
		const int barY = headPos.Y;

		const int healthHeight = FMath::Clamp(int((health / 100.0f) * barHeight), 0, barHeight);
		const int shieldHeight = FMath::Clamp(int((shield / 50.0f) * barHeight), 0, barHeight);

		const FLinearColor outlineColor = FLinearColor(0, 0, 0, 0.5f); // Lower opacity outline

		FLinearColor healthColor = FLinearColor(0.0f, 1.0f, 0.0f, 1.0f); // green
		if (health <= 25)
			healthColor = FLinearColor(1.0f, 0.0f, 0.0f, 1.0f); // red
		else if (health <= 50)
			healthColor = FLinearColor(1.0f, 1.0f, 0.0f, 1.0f); // yellow

		FLinearColor shieldColor = FLinearColor(0.25f, 0.6f, 1.0f, 1.0f); // light blue

		// Draw health bar (filled with lines)
		if (health > 0)
		{
			for (int i = 0; i < healthHeight; i++) {
				canvas->K2_DrawLine(FVector2D(barX_Health, barY + barHeight - i - 1), FVector2D(barX_Health + barThickness, barY + barHeight - i - 1), 1.0f, healthColor);
			}
		}

		// Draw shield bar (filled with lines)
		if (shield > 0)
		{
			for (int i = 0; i < shieldHeight; i++) {
				canvas->K2_DrawLine(FVector2D(barX_Shield, barY + barHeight - i - 1), FVector2D(barX_Shield + barThickness, barY + barHeight - i - 1), 1.0f, shieldColor);
			}
		}

		// Draw the bar outlines only once for health and shield bars
		canvas->K2_DrawLine(FVector2D(barX_Health, barY), FVector2D(barX_Health + barThickness, barY), 1.0f, outlineColor); // Top for health
		canvas->K2_DrawLine(FVector2D(barX_Health, barY + barHeight), FVector2D(barX_Health + barThickness, barY + barHeight), 1.0f, outlineColor); // Bottom for health
		canvas->K2_DrawLine(FVector2D(barX_Health, barY), FVector2D(barX_Health, barY + barHeight), 1.0f, outlineColor); // Left for health
		canvas->K2_DrawLine(FVector2D(barX_Health + barThickness, barY), FVector2D(barX_Health + barThickness, barY + barHeight), 1.0f, outlineColor); // Right for health

		canvas->K2_DrawLine(FVector2D(barX_Shield, barY), FVector2D(barX_Shield + barThickness, barY), 1.0f, outlineColor); // Top for shield
		canvas->K2_DrawLine(FVector2D(barX_Shield, barY + barHeight), FVector2D(barX_Shield + barThickness, barY + barHeight), 1.0f, outlineColor); // Bottom for shield
		canvas->K2_DrawLine(FVector2D(barX_Shield, barY), FVector2D(barX_Shield, barY + barHeight), 1.0f, outlineColor); // Left for shield
		canvas->K2_DrawLine(FVector2D(barX_Shield + barThickness, barY), FVector2D(barX_Shield + barThickness, barY + barHeight), 1.0f, outlineColor); // Right for shield

		// Calculate total health + shield
		float totalHealth = health + shield;

		// Draw the combined health + shield text
		wchar_t healthTextBuffer[8];
		swprintf_s(healthTextBuffer, (L"%d"), static_cast<int>(totalHealth)); // Use combined total health/shield value
		FString healthText(healthTextBuffer);

		// Adjust text size based on distance (distance affects text size)
		const float textScale = FMath::Clamp(0.85f / (distance / 15.0f), 0.5f, 0.85f);  // Scale text size based on distance

		// Adjust text size and position to match the bars
		int healthTextX = barX_Health + (barThickness / 2) - (healthText.Num() * 4); // Adjust for text length (approximate width)
		int shieldTextX = barX_Shield + (barThickness / 2) - (healthText.Num() * 4); // Similarly for shield

		// Calculate the middle of the bar height (for Y positioning)
		int textCenterY = barY + (barHeight / 2) - 10; // Slightly adjust Y for centering
	
	
	}






		





	void DrawWeaponEsp(UCanvas* canvas, UObject* equippable, const FVector2D& headLongOut, float distance)
	{
		if (Globals::WeaponEsp && distance >= 1.2f) {
			FString weaponName = kismentsystemlibrary::get_object_name((UObject*)equippable);
			DrawEspText(canvas, Filters::Names::WeaponName(weaponName), FVector2D(headLongOut.X, headLongOut.Y - 10), FVector2D{ 1.f, 1.f }, Colors::WeaponNameColor);
		}
	}
	void DrawBoxLines(UCanvas* canvas, FVector2D position, float width, float height, FLinearColor color)
	{
		float X = position.X - (width / 2);
		float Y = position.Y;
		float lineW = (width / 3);
		float lineH = (height / 3);

		canvas->K2_DrawLine(FVector2D(X, Y), FVector2D(X, Y + lineH), 1.8f, color);
		canvas->K2_DrawLine(FVector2D(X, Y), FVector2D(X + lineW, Y), 1.8f, color);
		canvas->K2_DrawLine(FVector2D(X + width - lineW, Y), FVector2D(X + width, Y), 1.8f, color);
		canvas->K2_DrawLine(FVector2D(X + width, Y), FVector2D(X + width, Y + lineH), 1.8f, color);
		canvas->K2_DrawLine(FVector2D(X, Y + height - lineH), FVector2D(X, Y + height), 1.8f, color);
		canvas->K2_DrawLine(FVector2D(X, Y + height), FVector2D(X + lineW, Y + height), 1.8f, color);
		canvas->K2_DrawLine(FVector2D(X + width - lineW, Y + height), FVector2D(X + width, Y + height), 1.8f, color);
		canvas->K2_DrawLine(FVector2D(X + width, Y + height - lineH), FVector2D(X + width, Y + height), 1.8f, color);
	}
	void DrawCircle(UCanvas* canvas, FVector2D pos, int radius, int numSides, FLinearColor Color)
	{
		float PI = 3.1415927f;

		float Step = PI * 2.0 / numSides;
		int Count = 0;
		FVector2D V[128];
		for (float A = 0; A < PI * 2.0; A += Step) {
			float X1 = radius * cos(A) + pos.X;
			float Y1 = radius * sin(A) + pos.Y;
			float X2 = radius * cos(A + Step) + pos.X;
			float Y2 = radius * sin(A + Step) + pos.Y;
			V[Count].X = X1;
			V[Count].Y = Y1;
			V[Count + 1].X = X2;
			V[Count + 1].Y = Y2;
			//Draw_Line(FVector2D{ pos.X, pos.Y }, FVector2D{ X2, Y2 }, 1.0f, Color); // Points from Centre to ends of circle
			canvas->K2_DrawLine(FVector2D{ V[Count].X, V[Count].Y }, FVector2D{ X2, Y2 }, 0.5f, Color);// Circle Around
		}
	}
	void DrawProgressBarFill(UCanvas* canvas, const FVector2D& TopLeft, const FVector2D& BottomRight, float Percentage) {
		float X = TopLeft.X, Y = TopLeft.Y;
		const FLinearColor ForegroundColor = { 0, 0, 1, 1 };

		for (int i = 0; i < 5; i++) {
			if (i > 0 && i < 5 - 1) {
				// Draw foreground bar with percentage
				float ForegroundWidth = 70 * Percentage / 100;
				canvas->K2_DrawLine(FVector2D(X, Y + i), FVector2D(X + ForegroundWidth, Y + i), 2.9, ForegroundColor);
			}
		}
	}
	void DrawBoxOutline(UCanvas* canvas, const FVector2D& TopLeft, const FVector2D& BottomRight) {
		canvas->K2_DrawLine(TopLeft, FVector2D(BottomRight.X, TopLeft.Y), 2, { 170, 170, 170, 0.0002f });
		canvas->K2_DrawLine(FVector2D(TopLeft.X, BottomRight.Y), BottomRight, 2, { 170, 170, 170, 0.0002f });
		canvas->K2_DrawLine(TopLeft, FVector2D(TopLeft.X, BottomRight.Y), 2, { 170, 170, 170, 0.0002f });
		canvas->K2_DrawLine(FVector2D(BottomRight.X, TopLeft.Y), BottomRight, 2, { 170, 170, 170, 0.0002f });
	}
	void Draw3DWeapon(UCanvas* Canvas, APlayerController* MYController, FVector ObjectLocation3D, FLinearColor Color)
	{
		int xz = 70;
		int uzunluk = 20;
		FVector Pos0, Pos1, Pos2, Pos3, Pos4, Pos5, Pos6, Pos7, Pos8;
		Pos0 = ObjectLocation3D;
		Pos0.Z += 10;
		Pos1 = Pos0 + FVector(-xz, -xz, uzunluk);
		Pos2 = Pos0 + FVector(-xz, -xz, -uzunluk);
		Pos3 = Pos0 + FVector(xz, -xz, -uzunluk);
		Pos4 = Pos0 + FVector(xz, -xz, uzunluk);
		Pos5 = Pos0 + FVector(-xz, xz, uzunluk);
		Pos6 = Pos0 + FVector(-xz, xz, -uzunluk);
		Pos7 = Pos0 + FVector(xz, xz, -uzunluk);
		Pos8 = Pos0 + FVector(xz, xz, uzunluk);

		FVector2D ScreenPos0, ScreenPos1, ScreenPos2, ScreenPos3, ScreenPos4, ScreenPos5, ScreenPos6, ScreenPos7, ScreenPos8;
		if (MYController->ProjectWorldLocationToScreen(Pos0, ScreenPos0, 0) && ScreenPos0.IsValid())
		{
			if (MYController->ProjectWorldLocationToScreen(Pos1, ScreenPos1, 0) && ScreenPos1.IsValid())
			{
				if (MYController->ProjectWorldLocationToScreen(Pos2, ScreenPos2, 0) && ScreenPos2.IsValid())
				{
					if (MYController->ProjectWorldLocationToScreen(Pos3, ScreenPos3, 0) && ScreenPos3.IsValid())
					{
						if (MYController->ProjectWorldLocationToScreen(Pos4, ScreenPos4, 0) && ScreenPos4.IsValid())
						{
							if (MYController->ProjectWorldLocationToScreen(Pos5, ScreenPos5, 0) && ScreenPos5.IsValid())
							{
								if (MYController->ProjectWorldLocationToScreen(Pos6, ScreenPos6, 0) && ScreenPos6.IsValid())
								{
									if (MYController->ProjectWorldLocationToScreen(Pos7, ScreenPos7, 0) && ScreenPos7.IsValid())
									{
										if (MYController->ProjectWorldLocationToScreen(Pos8, ScreenPos8, 0) && ScreenPos8.IsValid())
										{
											// Draw lines between points to create the 3D box
											DrawLineSimple(Canvas, ScreenPos1, ScreenPos2, Color);
											DrawLineSimple(Canvas, ScreenPos2, ScreenPos3, Color);
											DrawLineSimple(Canvas, ScreenPos3, ScreenPos4, Color);
											DrawLineSimple(Canvas, ScreenPos4, ScreenPos1, Color);

											DrawLineSimple(Canvas, ScreenPos5, ScreenPos6, Color);
											DrawLineSimple(Canvas, ScreenPos6, ScreenPos7, Color);
											DrawLineSimple(Canvas, ScreenPos7, ScreenPos8, Color);
											DrawLineSimple(Canvas, ScreenPos8, ScreenPos5, Color);

											DrawLineSimple(Canvas, ScreenPos1, ScreenPos5, Color);
											DrawLineSimple(Canvas, ScreenPos2, ScreenPos6, Color);
											DrawLineSimple(Canvas, ScreenPos3, ScreenPos7, Color);
											DrawLineSimple(Canvas, ScreenPos4, ScreenPos8, Color);
										}
									}
								}
							}
						}
					}
				}
			}
		}


	}
	void DrawProgressBar(UCanvas* canvas, const FVector2D& Location, float Percentage) {
		FVector2D BoxTopLeft = FVector2D(Location.X - 35, Location.Y + 15);
		FVector2D BoxBottomRight = FVector2D(BoxTopLeft.X + 70, BoxTopLeft.Y + 5);

		DrawBoxOutline(canvas, BoxTopLeft, BoxBottomRight);
		DrawProgressBarFill(canvas, BoxTopLeft, BoxBottomRight, Percentage);
	}
	void DrawBombInfo(UCanvas* canvas, const FVector2D& ObjectLocation, float DefusePercentage, float bomb_time_remaining) {
		std::string timeRemainingStr = std::to_string((int)bomb_time_remaining);
		std::wstring timeRemainingWStr(timeRemainingStr.begin(), timeRemainingStr.end());

		canvas->K2_DrawText(timeRemainingWStr.c_str(), ObjectLocation, FVector2D{ 1.15f, 1.15f }, { 1,1, 1 ,2.5f }, false, menu::colors::Text_Shadow, FVector2D{ pos_decrpt::pos.X + 1, pos_decrpt::pos.Y + 1 }, true, true, true, { 0,0,0,0.60f });

		if (DefusePercentage > 0) {
			DrawProgressBar(canvas, ObjectLocation, DefusePercentage);
		}

	}

	void DrawDroppedSpikeInfo(UCanvas* canvas, const FVector2D& ObjectLocation) {
		canvas->K2_DrawText(FString{ L"Dropped Spike" }, ObjectLocation, FVector2D{ 1.06f, 1.06f }, { 1, 1, 1 ,2.5f }, false, menu::colors::Text_Shadow, FVector2D{ pos_decrpt::pos.X + 1, pos_decrpt::pos.Y + 1 }, true, true, true, { 0,0,0.65f });
	}


	void config_value(int value) {
		switch (value)
		{
		case 1:
			Globals::LegitFOvValue = 60.0f;

			Globals::EnableAim = true;
			Globals::DrawFov = true;
			Globals::LegitBotKey = VK_XBUTTON1;
			Globals::smooth = 4.0f;

			Globals::RecoilControl = true;
			Globals::RecoilCrosshair = true;
			Globals::NoSpreadAimbot = false;
			Globals::VisibleCheck = true;
			Globals::Silent = false;


			Globals::EnableESP = true;
			Globals::CorneredBox = true;
			Globals::HeadESP = true;
			Globals::Snapline = true;
			Globals::SelectSnapline = 1;
			Globals::Healthbar = true;
			Globals::SkeletonEsp = true;

			Globals::Box2D = false;
			Globals::Box3D = false;
			Globals::AgentName = false;
			Globals::ChamsESP = false;
			Globals::DistangeEsp = false;
			Globals::HealthText = false;
			Globals::Shieldbar = false;

			Globals::SpikeEsp = false;
			Globals::weaponesp = false;
			Globals::WeaponEsp = false;
			Globals::EnableSkin = false;
			Globals::BunnyHop = true;
			Globals::AntiAFK = false;
			break;
		case 2:
			Globals::LegitFOvValue = 1000.0f;
			Globals::EnableAim = true;
			Globals::DrawFov = false;
			Globals::LegitBotKey = VK_LBUTTON;
			Globals::smooth = 1.0f;
			Globals::RecoilControl = true;
			Globals::RecoilCrosshair = true;
			Globals::VisibleCheck = true;
			Globals::Silent = false;

			Globals::EnableESP = true;
			Globals::CorneredBox = true;
			Globals::HeadESP = true;
			Globals::Snapline = true;
			Globals::SelectSnapline = 1;
			Globals::Healthbar = true;
			Globals::SkeletonEsp = true;

			Globals::Box2D = false;
			Globals::Box3D = false;
			Globals::AgentName = false;
			Globals::ChamsESP = false;
			Globals::DistangeEsp = false;
			Globals::HealthText = false;
			Globals::Shieldbar = false;

			Globals::SpikeEsp = false;
			Globals::weaponesp = false;
			Globals::WeaponEsp = false;
			Globals::EnableSkin = false;
			Globals::BunnyHop = true;
			Globals::AntiAFK = false;
			break;
		case 3:
			Globals::LegitFOvValue = 1000.0f;
			Globals::EnableAim = true;
			Globals::DrawFov = false;
			Globals::LegitBotKey = VK_LBUTTON;
			Globals::smooth = 1.0f;
			Globals::RecoilControl = true;
			Globals::RecoilCrosshair = true;
			Globals::VisibleCheck = true;
			Globals::Silent = false;

			Globals::EnableESP = true;
			Globals::CorneredBox = true;
			Globals::HeadESP = true;
			Globals::Snapline = true;
			Globals::SelectSnapline = 1;
			Globals::Healthbar = true;
			Globals::SkeletonEsp = true;

			Globals::Box2D = false;
			Globals::Box3D = false;
			Globals::AgentName = false;
			Globals::ChamsESP = false;
			Globals::DistangeEsp = false;
			Globals::HealthText = false;
			Globals::Shieldbar = false;

			Globals::SpikeEsp = false;
			Globals::weaponesp = false;
			Globals::WeaponEsp = false;
			Globals::EnableSkin = false;
			Globals::BunnyHop = true;
			Globals::AntiAFK = false;
			break;
		case 4:
			Globals::LegitFOvValue = 17.0f;
			Globals::EnableAim = true;
			Globals::DrawFov = true;
			Globals::LegitBotKey;
			Globals::smooth = 15.0f;
			Globals::RecoilControl = false;
			Globals::RecoilCrosshair = false;
			Globals::AutoShoot = false;
			Globals::VisibleCheck = true;
			Globals::Silent = false;
			Globals::EnableSkin = false;

			Globals::EnableESP = true;
			Globals::CorneredBox = false;
			Globals::HeadESP = true;
			Globals::Snapline = false;
			Globals::SelectSnapline = 1;
			Globals::Healthbar = true;
			Globals::SkeletonEsp = true;

			Globals::Box2D = false;
			Globals::Box3D = false;
			Globals::AgentName = false;
			Globals::ChamsESP = false;
			Globals::DistangeEsp = true;
			Globals::HealthText = false;
			Globals::Shieldbar = true;

			Globals::SpikeEsp = false;
			Globals::weaponesp = false;
			Globals::WeaponEsp = false;
			Globals::EnableSkin = false;
			Globals::BunnyHop = true;
			Globals::AntiAFK = false;
			break;
		case 5:
			Globals::LegitFOvValue = 21.0f;
			Globals::EnableAim = true;
			Globals::DrawFov = false;
			Globals::LegitBotKey = VK_LBUTTON;
			Globals::smooth = 21.0f;
			Globals::RecoilControl = true;
			Globals::RecoilCrosshair = false;
			Globals::VisibleCheck = true;
			Globals::Silent = false;

			Globals::EnableESP = true;
			Globals::CorneredBox = false;
			Globals::HeadESP = true;
			Globals::Snapline = false;
			Globals::SelectSnapline = 1;
			Globals::Healthbar = true;
			Globals::SkeletonEsp = true;

			Globals::Box2D = false;
			Globals::Box3D = false;
			Globals::AgentName = false;
			Globals::ChamsESP = false;
			Globals::DistangeEsp = false;
			Globals::HealthText = false;
			Globals::Shieldbar = false;

			Globals::SpikeEsp = false;
			Globals::weaponesp = false;
			Globals::WeaponEsp = false;
			Globals::EnableSkin = false;
			Globals::BunnyHop = false;
			Globals::AntiAFK = false;
			break;
		case 6:
			Globals::LegitFOvValue = 6.0f;
			Globals::EnableAim = true;
			Globals::DrawFov = false;
			Globals::LegitBotKey = VK_LBUTTON;
			Globals::smooth = 25.0f;
			Globals::RecoilControl = true;
			Globals::RecoilCrosshair = false;
			Globals::VisibleCheck = true;
			Globals::Silent = false;

			Globals::EnableESP = true;
			Globals::CorneredBox = false;
			Globals::HeadESP = false;
			Globals::Snapline = false;
			Globals::SelectSnapline = 1;
			Globals::Healthbar = true;
			Globals::SkeletonEsp = true;

			Globals::Box2D = false;
			Globals::Box3D = false;
			Globals::AgentName = false;
			Globals::ChamsESP = false;
			Globals::DistangeEsp = false;
			Globals::HealthText = false;
			Globals::Shieldbar = false;

			Globals::SpikeEsp = false;
			Globals::weaponesp = false;
			Globals::WeaponEsp = false;
			Globals::EnableSkin = false;
			Globals::BunnyHop = false;
			Globals::AntiAFK = false;
			break;

		case 7:
			Globals::LegitFOvValue = 14.0f;
			Globals::EnableAim = true;
			Globals::DrawFov = false;
			Globals::LegitBotKey = VK_LBUTTON;
			Globals::smooth = 6.0f;
			Globals::RecoilControl = true;
			Globals::RecoilCrosshair = false;
			Globals::VisibleCheck = true;
			Globals::Silent = false;

			Globals::EnableESP = true;
			Globals::CorneredBox = false;
			Globals::HeadESP = true;
			Globals::Snapline = false;
			Globals::SelectSnapline = 1;
			Globals::Healthbar = true;
			Globals::SkeletonEsp = true;

			Globals::Box2D = false;
			Globals::Box3D = false;
			Globals::AgentName = false;
			Globals::ChamsESP = false;
			Globals::DistangeEsp = false;
			Globals::HealthText = false;
			Globals::Shieldbar = false;

			Globals::SpikeEsp = false;
			Globals::weaponesp = false;
			Globals::WeaponEsp = false;
			Globals::EnableSkin = false;
			Globals::BunnyHop = false;
			Globals::AntiAFK = false;
			break;
		case 8:
			Globals::LegitFOvValue = 16.0f;
			Globals::EnableAim = true;
			Globals::DrawFov = true;
			Globals::LegitBotKey = VK_LBUTTON;
			Globals::smooth = 4.7f;
			Globals::RecoilControl = false;
			Globals::RecoilCrosshair = false;
			Globals::VisibleCheck = true;
			Globals::Silent = false;

			Globals::EnableESP = true;
			Globals::CorneredBox = true;
			Globals::HeadESP = true;
			Globals::Snapline = true;
			Globals::SelectSnapline = 1;
			Globals::Healthbar = true;
			Globals::SkeletonEsp = true;

			Globals::Box2D = false;
			Globals::Box3D = false;
			Globals::AgentName = false;
			Globals::ChamsESP = false;
			Globals::DistangeEsp = false;
			Globals::HealthText = false;
			Globals::Shieldbar = false;

			Globals::SpikeEsp = false;
			Globals::weaponesp = false;
			Globals::WeaponEsp = false;
			Globals::EnableSkin = false;
			Globals::BunnyHop = false;
			Globals::AntiAFK = false;
			break;
		}

	

	}
	void aimbot_recoil(const FVector& CameraRot, const FVector& ControlRotation, const FVector& Target, const FVector& CameraPos, const FVector& recoil, APlayerController* MyController) {
		SPOOF_FUNC;


		FVector vector_pos = Target - CameraPos;
		float distance = sqrtf(vector_pos.X * vector_pos.X + vector_pos.Y * vector_pos.Y + vector_pos.Z * vector_pos.Z);
		float X, Y, z;
		X = -((acosf(vector_pos.Z / distance) * (float)(180.0f / PI)) - 90.f);
		Y = atan2f(vector_pos.Y, vector_pos.X) * (float)(180.0f / PI);
		z = 0;

		FVector target_rotation = FVector(X, Y, z);
		FVector new_aim_rotation;
		new_aim_rotation.X = target_rotation.X - recoil.X - recoil.X;
		new_aim_rotation.Y = target_rotation.Y - recoil.Y - recoil.Y;
		new_aim_rotation.Z = 0;

		FVector new_rotation = Math::SmoothAim(new_aim_rotation, ControlRotation, Globals::smooth);

		if (new_rotation.X < 0) {
			new_rotation.X += 360.f;
		}

		if (new_rotation.Y < 0) {
			new_rotation.Y += 360.f;
		}

		new_rotation.Z = 0;

		MyController->SetControlRotation(new_rotation);
	}
	void aimbot(const FVector& CameraRot, const FVector& ControlRotation, const FVector& Target, const FVector& CameraPos, APlayerController* MyController) {
		SPOOF_FUNC;


		FVector vector_pos = Target - CameraPos;
		float distance = sqrtf(vector_pos.X * vector_pos.X + vector_pos.Y * vector_pos.Y + vector_pos.Z * vector_pos.Z);
		float X, Y, z;
		X = -((acosf(vector_pos.Z / distance) * (float)(180.0f / PI)) - 90.f);
		Y = atan2f(vector_pos.Y, vector_pos.X) * (float)(180.0f / PI);
		z = 0;

		FVector target_rotation = FVector(X, Y, z);
		FVector new_aim_rotation;
		new_aim_rotation.X = target_rotation.X;
		new_aim_rotation.Y = target_rotation.Y;
		new_aim_rotation.Z = 0;

		FVector new_rotation = Math::SmoothAim(new_aim_rotation, ControlRotation, Globals::smooth);

		if (new_rotation.X < 0) {
			new_rotation.X += 360.f;
		}

		if (new_rotation.Y < 0) {
			new_rotation.Y += 360.f;
		}

		new_rotation.Z = 0;

		MyController->SetControlRotation(new_rotation);
	}
	void Draw3DSkeleton(UCanvas* Canvas, FVector start, FVector last, APlayerController* MYController, USkeletalMeshComponent* Mesh, FLinearColor Color)
	{
		FVector2D bottom1;
		FVector2D bottom2;
		FVector2D bottom3;
		FVector2D bottom4;
		FVector2D top1;
		FVector2D top2;
		FVector2D top3;
		FVector2D top4;
		FVector vBaseBone = start;
		FVector vHeadBone = last;
		if (MYController->ProjectWorldLocationToScreen(FVector(vBaseBone.X + 4, vBaseBone.Y - 4, vBaseBone.Z), bottom1, 0) && bottom1.IsValid())
		{
			if (MYController->ProjectWorldLocationToScreen(FVector(vBaseBone.X - 4, vBaseBone.Y - 4, vBaseBone.Z), bottom2, 0) && bottom2.IsValid())
			{
				if (MYController->ProjectWorldLocationToScreen(FVector(vBaseBone.X - 4, vBaseBone.Y + 4, vBaseBone.Z), bottom3, 0) && bottom3.IsValid())
				{
					if (MYController->ProjectWorldLocationToScreen(FVector(vBaseBone.X + 4, vBaseBone.Y + 4, vBaseBone.Z), bottom4, 0) && bottom4.IsValid())
					{
						if (MYController->ProjectWorldLocationToScreen(FVector(vHeadBone.X + 4, vHeadBone.Y - 4, vHeadBone.Z + 8), top1, 0) && top1.IsValid())
						{
							if (MYController->ProjectWorldLocationToScreen(FVector(vHeadBone.X - 4, vHeadBone.Y - 4, vHeadBone.Z + 8), top2, 0) && top2.IsValid())
							{
								if (MYController->ProjectWorldLocationToScreen(FVector(vHeadBone.X - 4, vHeadBone.Y + 4, vHeadBone.Z + 8), top3, 0) && top3.IsValid())
								{
									if (MYController->ProjectWorldLocationToScreen(FVector(vHeadBone.X + 4, vHeadBone.Y + 4, vHeadBone.Z + 8), top4, 0) && top4.IsValid())
									{

										DrawLineSimple_3D(Canvas, bottom1, top1, Color);
										DrawLineSimple_3D(Canvas, bottom1, top1, Color);
										DrawLineSimple_3D(Canvas, bottom2, top2, Color);
										DrawLineSimple_3D(Canvas, bottom3, top3, Color);
										DrawLineSimple_3D(Canvas, bottom4, top4, Color);


										DrawLineSimple_3D(Canvas, bottom1, bottom2, Color);
										DrawLineSimple_3D(Canvas, bottom2, bottom3, Color);
										DrawLineSimple_3D(Canvas, bottom3, bottom4, Color);
										DrawLineSimple_3D(Canvas, bottom4, bottom1, Color);

										DrawLineSimple_3D(Canvas, top1, top2, Color);
										DrawLineSimple_3D(Canvas, top2, top3, Color);
										DrawLineSimple_3D(Canvas, top3, top4, Color);
										DrawLineSimple_3D(Canvas, top4, top1, Color);
									}
								}
							}
						}
					}
				}
			}

		}

	}
	void DrawSkeleton(APlayerController* MyController, USkeletalMeshComponent* Mesh, int bone_count, UCanvas* canvas) {
		struct BoneIDs {
			int hip, neck, upperArmLeft, leftHand, leftHand1, upperArmRight, rightHand, rightHand1;
			int leftThigh, leftCalf, leftFoot, rightThigh, rightCalf, rightFoot;
		};

		BoneIDs boneIDs;

		switch (bone_count) {
		case 101:
			boneIDs = { 3, 21, 23, 24, 25, 49, 50, 51, 75, 76, 78, 82, 83, 85 };
			break;
		case 103:
			boneIDs = { 3, 9, 33, 30, 32, 58, 55, 57, 63, 65, 69, 77, 79, 83 };
			break;
		case 104:
			boneIDs = { 3, 21, 23, 24, 25, 49, 50, 51, 77, 78, 80, 84, 85, 87 };
			break;
		default:
			return;
		}

		auto ProjectAndCheck = [&](int boneIndex, FVector2D& out) {
			return MyController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, boneIndex), out, 0) && out.IsValid();
			};

		FVector2D vHipOut, vNeckOut, vUpperArmLeftOut, vLeftHandOut, vLeftHandOut1, vUpperArmRightOut, vRightHandOut, vRightHandOut1, vLeftThighOut, vLeftCalfOut, vLeftFootOut, vRightThighOut, vRightCalfOut, vRightFootOut;

		if (ProjectAndCheck(boneIDs.hip, vHipOut) && ProjectAndCheck(boneIDs.neck, vNeckOut) &&
			ProjectAndCheck(boneIDs.upperArmLeft, vUpperArmLeftOut) && ProjectAndCheck(boneIDs.leftHand, vLeftHandOut) && ProjectAndCheck(boneIDs.leftHand1, vLeftHandOut1) &&
			ProjectAndCheck(boneIDs.upperArmRight, vUpperArmRightOut) && ProjectAndCheck(boneIDs.rightHand, vRightHandOut) && ProjectAndCheck(boneIDs.rightHand1, vRightHandOut1) &&
			ProjectAndCheck(boneIDs.leftThigh, vLeftThighOut) && ProjectAndCheck(boneIDs.leftCalf, vLeftCalfOut) && ProjectAndCheck(boneIDs.leftFoot, vLeftFootOut) &&
			ProjectAndCheck(boneIDs.rightThigh, vRightThighOut) && ProjectAndCheck(boneIDs.rightCalf, vRightCalfOut) && ProjectAndCheck(boneIDs.rightFoot, vRightFootOut)) {

			canvas->K2_DrawLine(vHipOut, vNeckOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vUpperArmLeftOut, vNeckOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vUpperArmRightOut, vNeckOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vLeftHandOut, vUpperArmLeftOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vRightHandOut, vUpperArmRightOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vLeftHandOut, vLeftHandOut1, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vRightHandOut, vRightHandOut1, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vLeftThighOut, vHipOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vRightThighOut, vHipOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vLeftCalfOut, vLeftThighOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vRightCalfOut, vRightThighOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vLeftFootOut, vLeftCalfOut, 1, Colors::Skeleton);
			canvas->K2_DrawLine(vRightFootOut, vRightCalfOut, 1, Colors::Skeleton);
		}
	}

	namespace G {
		UWorld* UWorldClass;
		UWorld* UWorldClass_2;
		AShooterCharacter* actor;
		APlayerCameraManager* MyCamera;
		APlayerController* controller;
		AAresEquippable* LastWeapon;
		AAresEquippable* MyWeapon;
		UObject* GameInstance;
		ULocalPlayer* LocalPlayers;
		ULocalPlayer* LocalPlayer;
		FVector2D pos = { ((float)GetSystemMetrics(SM_CXSCREEN) / 2) - 500, ((float)GetSystemMetrics(SM_CYSCREEN) / 2) - 475 };
		static bool recoil_hide_bool = true;
		static bool IsKnife = false;
		static bool alive = true;

		bool Mesh3PModifed = true;
		static bool pixel_time_bool;
		float spin_speed = 10.f;

	}
	void skills_names(std::string ObjectName, AShooterCharacter* MyShooter, UCanvas* canvas, FVector2D ObjectLocation) {
		SPOOF_FUNC;
		static float font_size = 0.80f;

		if (ObjectName.find(("SmokeZone")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Smoke" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("Zone_Wraith_4_Smoke_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Smoke" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("Zone_Mage_Q_SphereShield_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Smoke" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Sarge_4_SmokeManager_Production_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Smoke" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Pandemic_E_SmokeScreenManager_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Viper Wall Smoke" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Phoenix_Q_FlameWallManager_Production_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Flame Wall Smoke" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Sprinter_4_Tunnel_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Neon Wall Smoke" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Sequoia_4_MovingCover_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Iso Wall" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Rift_GlobalWall_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Astra Smoke" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Breach_4_FusionBlast_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Fusion Line" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Breach_4_SweetSpotFissure_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Fault Line" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Breach_X_Shockwave_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Breach Ulti" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Sarge_E_SpeedStim_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Brim SpeedKit" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Deadeye_E_Trap_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Chamber Trap" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Deadeye_E_Teleporter_Tether_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Chamber Teleport" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Gumshoe_E_TripWire_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Cyper Trap" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Gumshoe_4_Cage_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Cyper Cage" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_CableJamRoot_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Deadlock JamRoot" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_StealthingTrap_SoundSensor_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Deadlock Trap" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_FishingHook_BouncingTrajectoryWarning_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Deadlock Ulti" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_BountyHunter_E_LoSReveal_Source_Reactivate_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Fade Hount" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Q_BountyHunter_Tether_SphereExpansion_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Fade Seize" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_BountyHunter_X_WaveForm_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Fade Ulti" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_BountyHunter_X_WaveForm_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Fade Ulti" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Mage_4_Wave_Chunk_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Harbor Wall" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Mage_E_WallManager_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Harbor Wall" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Sequoia_Q_FragileMissile_TrajectoryWarning_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Iso UnderCut" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Grenadier_E_SuppressionPulse_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Kayo Point" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Killjoy_X_Bomb_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Killjoy Ulti" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Sprinter_Q_ElectricSphere_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Neon RelayBlot" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Wraith_Q_NearsightMissile_TrajectoryWarning_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Omen Paranora" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Wraith_X_GlobalTeleport_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Omen Teleport" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Phoenix_X_ResTarget_Production_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Phoenix Ulti" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Phoenix_X_ResTarget_Production_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Phoenix Ulti" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Vampire_4_NearsightAOE_Source_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Reyna Blind" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Hunter_Q_SonarBolt_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Sova Arrow" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Hunter_4_ExplosiveBolt_Explosion_PrototypeBalance_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Sova Shock" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Gumshoe_E_TripWire_SecondWire_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Cyper Trap" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Gumshoe_E_TripWire_SecondWire_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Cyper Trap" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Sarge_4_Smoke_ProductionNEW_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Smoke" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Sarge_4_OrbitalStrike_Production_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Brim Ulti" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Killjoy_4_BeeSwarm_Damage_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Killjoy Molly" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Aggrobot_Reclaim_Orb_SkederNade_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Iso Orb" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}

		// Clove
		if (ObjectName.find(("GameObject_Smonk_NewSmoke_C")) != std::string::npos) {
			if (!MyShooter->IsAlive())
				return;
			DrawEspText(canvas,FString{ L"Clove Ruse" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}

		if (ObjectName.find(("GameObject_Smonk_Q_DecayExplosion_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Clove Meddle" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}


		if (ObjectName.find(("GameObject_Gumshoe_Q_PossessableCamera_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Cyper Camera" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Killjoy_E_Turret_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Killjoy Turret" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Killjoy_Q_StealthAlarmbot_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Killjoy Alarmbot" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Clay_E_Boomba_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"RazeBot" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Aggrobot_SeekerNade_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Wingman" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("Ability_Guide_Q_PossessableScout_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Sky Kurd" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Stealth_4_Decoy_V2_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Yoru Klon" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Stealth_E_TeleporterMoving_FakeTP_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Yoru Teleport" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("Ability_Stealth_X_Cloak_Equip_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Yoru Ulti" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_BountyHunter_4_WolfHound_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Fade Prowler" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Hunter_E_Drone_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Sova Drone" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
		if (ObjectName.find(("GameObject_Rift_Q_FlashBurst_C")) != std::string::npos)
		{
			if (!MyShooter->IsAlive())
				return;

			DrawEspText(canvas,FString{ L"Astra FlashBurst" }, ObjectLocation, FVector2D{ font_size, font_size }, { 1,1,1,3.0f }, 0.75f);
		}
	}

	void meshp1_material(APawn* MyPawn, AShooterCharacter* characterz)
	{
		UPrimitiveComponent* mesh = Memory::R<UPrimitiveComponent*>(uintptr_t(MyPawn) + Offsets::mesh1p);
		UPrimitiveComponent* meshOverlay = Memory::R<UPrimitiveComponent*>(uintptr_t(MyPawn) + Offsets::mesh1p_overlay);

		//  this two offset is for hands

		UObject* Material = nullptr;

		SPOOF_FUNC; // Spoof only once before loading
		// yea so what u need exactly, HAND FRESNEL
		switch (g_Options.material) {
		case 0:
			Material = UObject::StaticLoadObject(L"/Game/Equippables/_Core/Materials/3P_Weapon_Translucent_Mat");
			break;
		case 1:
			Material = UObject::StaticLoadObject(L"/Game/Characters/Vampire/S0/VFX/Ability_X/1P_Vampire_Tattoo_X_S0_MI_VFX.1P_Vampire_Tattoo_X_S0_MI_VFX");
			break;
		case 2:
			Material = UObject::StaticLoadObject(L"/Game/Equippables/_Core/Materials/SpecialMaterials/Gems/1P_Gem_MAT");
			break;
		case 3:
			Material = UObject::StaticLoadObject(L"/Game/Equippables/_Core/Materials/1P_Weapon_Glass_Mat.1P_Weapon_Glass_Mat");
			break;
		case 4:
			Material = UObject::StaticLoadObject(L"/Game/Equippables/_Core/Materials/SpecialMaterials/Sakura/Tritium_Sakura_3P_MI");
			break;
		case 5:
			Material = UObject::StaticLoadObject(L"/Game/Equippables/_Core/Materials/SpecialMaterials/Arcade/Arcade_Emissive_Yellow_MI.Arcade_Emissive_Yellow_MI");
			break;
		case 6:
			Material = UObject::StaticLoadObject(L"/Game/Equippables/_Core/Materials/SpecialMaterials/Arcade/Arcade_Emissive_Red_MI.Arcade_Emissive_Red_MI");
			break;
		case 7:
			Material = UObject::StaticLoadObject(L"/Game/Equippables/_Core/Materials/SpecialMaterials/Arcade/Arcade_Emissive_Blue_MI.Arcade_Emissive_Blue_MI");
			break;
		case 8:
			Material = UObject::StaticLoadObject(L"/Game/Equippables/_Core/Materials/SpecialMaterials/Afterglow3/BakedLight/Afterglow3_BakedLight_MI.Afterglow3_BakedLight_MI");
			break;
		}

		// Only apply if we loaded a valid material
		if (Material)
		{
			if (mesh && mesh->GetMaterial(0) != Material)
				mesh->SetMaterial(0, Material);

			if (meshOverlay && meshOverlay->GetMaterial(0) != Material)
				meshOverlay->SetMaterial(0, Material);
		}
	}
