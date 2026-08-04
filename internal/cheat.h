#include "./includes.h"
#include "Hookign/ret_spoofing.h"
#include "canvas_gui.h" 
#include <unordered_set>


void HSVtoRGB(float h, float s, float v, uint8_t& R, uint8_t& G, uint8_t& B) {
    float c = v * s;
    float X = c * (1 - fabsf(fmodf(h / 60.0f, 2) - 1));
    float m = v - c;

    float r_, g_, b_;
    if (h < 60) { r_ = c; g_ = X; b_ = 0; }
    else if (h < 120) { r_ = X; g_ = c; b_ = 0; }
    else if (h < 180) { r_ = 0; g_ = c; b_ = X; }
    else if (h < 240) { r_ = 0; g_ = X; b_ = c; }
    else if (h < 300) { r_ = X; g_ = 0; b_ = c; }
    else { r_ = c; g_ = 0; b_ = X; }

    R = static_cast<uint8_t>((r_ + m) * 255);
    G = static_cast<uint8_t>((g_ + m) * 255);
    B = static_cast<uint8_t>((b_ + m) * 255);
}


float GetRainbowHue() {
    static auto start = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();
    float seconds = std::chrono::duration<float>(now - start).count();
    return fmodf(seconds * 60.0f, 360.0f); // 60 degrees per second
}
void PostRender(uintptr_t _this, UCanvas* canvas, std::uintptr_t a3) {
    SPOOF_FUNC;
    if (canvas)
        canvas = UObject::find_object2<UCanvas*>(ez(L"/Engine/Transient.DebugCanvasObject").d(), (UObject*)-1);

    menu::SetupCanvas(canvas);
    UWorld* World = Memory::R<UWorld*>(_this + 0x80); //0x68 
    static UWorld* LastWorld = nullptr;

    MyController = ShooterGameBlueprints::GetFirstLocalPlayerController(World);

    MyShooter = MyController->GetShooterCharacter();
    TArray<AShooterCharacter*> Actors = ShooterGameBlueprints::FindAllShooterCharactersWithAlliance(World, MyShooter, EAresAlliance::Alliance_Any, false, true);
    APlayerCameraManager* MyCamera = MyController->GetPlayerCameraManager();
    MyPawn = MyController->K2_GetPawn();
    
    UWorldSave = World;
    menu::input::handle(); //-> crash

    bool hasTarget = false;
    bool hasTarget3 = false;
    bool hasTarget2 = false;

    static int tab = 0;

    static bool firstTime3 = true;
    static bool firstTime5 = true;
    static bool one3 = false;
    static bool one2 = false;
    int target_id = -1;
    float closest_distance = FLT_MAX;

    if (GetAsyncKeyState(Globals::MenuKey) & 1) {
        Globals::Menu_Open = !Globals::Menu_Open;
    }

    time_ += 0.01f;
    float R = (sin(time_ * 2.0f) + 1.0f) / 2.0f;
    float G = (sin(time_ * 2.0f + 2.0f) + 1.0f) / 2.0f;
    float B = (sin(time_ * 2.0f + 4.0f) + 1.0f) / 2.0f;
    float a = 1.0f;
    menu::Watermark(FVector2D(20, 20), FVector2D(200, 30), Globals::Watermark);

  
    
   
        
  
        
    
    if (menu::Window(ez(L"Pasted").d(), &G::pos, FVector2D{700, 550}, Globals::Menu_Open)) {
        SPOOF_FUNC;
        static int tab = 0;

        if (menu::ButtonTab(ez(L"Aimbot").d(), FVector2D(130, 36), tab == 0)) tab = 0;
        menu::offset_y += 10;
        if (menu::ButtonTab(ez(L"Visuals").d(), FVector2D(130, 36), tab == 1)) tab = 1;
        menu::offset_y += 10;
        if (menu::ButtonTab(ez(L"Wallhack").d(), FVector2D(130, 36), tab == 2)) tab = 2;
        menu::offset_y += 10;
        if (menu::ButtonTab(ez(L"Skins").d(), FVector2D(130, 36), tab == 3)) tab = 3;
        menu::offset_y += 10;
        if (menu::ButtonTab(ez(L"Exploits").d(), FVector2D(130, 36), tab == 4)) tab = 4;
        menu::offset_y += 10;
        if (menu::ButtonTab(ez(L"Settings").d(), FVector2D(130, 36), tab == 5)) tab = 5;





        //menu::PushNextElementY(10.0f);

        if (tab == 0) { SPOOF_CALL(A1M)(); }
        if (tab == 1) { SPOOF_CALL(E3P)(); }
        if (tab == 2) { SPOOF_CALL(W4ALL)(); }
        if (tab == 5) { SPOOF_CALL(Misc)(); }
        if (tab == 4) { SPOOF_CALL(Exploits)(); }
        if (tab == 3) { SPOOF_CALL(SK1NCH4NG3R)(); }

    }



    if (UObject* world = Memory::R<UObject*>(std::uintptr_t(_this) + 0x80)) {
        auto enc = ez(L"MainMenuv2").d();
        if (kismentsystemlibrary::contains(kismentsystemlibrary::get_object_name(world).c_str(), enc)) {
            if (G::UWorldClass != nullptr)
                G::UWorldClass = nullptr;
        }
        enc;
    }

    menu::Render();
    //menu::Draw_Cursor(Globals::Menu_Open);

    static float font_size = 1.08f;


   

    if (Globals::SpikeEsp) {
        SPOOF_FUNC;
        TArray<AShooterCharacter*> Actors = ShooterGameBlueprints::FindAllShooterCharactersWithAlliance(World, MyShooter, EAresAlliance::Alliance_Any, false, true);
        TArray<AGameObject*> Objects = GameplayStatics::GetAllActorsOfClass(World, Class::ShooterGameObject());

        for (int index = 0; index < Objects.Num(); index++) {
            if (MyShooter->IsAlive()) {
                if (!Objects.IsValidIndex(index)) { continue; }

                AGameObject* Object = Objects[index];
                if (Object == nullptr) { continue; }

                FVector ObjectLocation3D = Object->GetObjectLocation();
                FVector2D ObjectLocation = MyController->ProjectWorldToScreen(ObjectLocation3D);

                if (!ObjectLocation.IsValid() || !ObjectLocation3D.IsValid()) { continue; }

                std::string ObjectName = kismentsystemlibrary::get_object_name((UObject*)Object).ToString();

                if (ObjectName.find(("TimedBomb_C")) != std::string::npos) {
                    float DefusePercentage = *(float*)((uintptr_t)Object + 0x4E8) * 100 / 6.984602;
                    float bomb_time_remaining = *(float*)((uintptr_t)Object + 0x4CC);

                    SPOOF_CALL(DrawBombInfo)(canvas, ObjectLocation, DefusePercentage, bomb_time_remaining);
                    float Width = 50.0f;
                    float Height = 100.0f;

                    int xz = 60;
                    int uzunluk = 70;
                    Draw3DDiamond(canvas, MyController, ObjectLocation3D, xz, uzunluk, { 255, 255, 255, 255 });
                }
                else if (ObjectName.find(("X_Bomb")) != std::string::npos) {
                    SPOOF_CALL(DrawDroppedSpikeInfo)(canvas, ObjectLocation);
                }
            }
        }
    }

    if (Globals::dropped_gun) {
        SPOOF_FUNC;
        TArray<AGameObject*> Objects = GameplayStatics::GetAllActorsOfClass(World, Class::ShooterGameObject());
        for (int index = 0; index < Objects.Num(); index++) {
            if (!Objects.IsValidIndex(index)) { continue; }
            AGameObject* Object = Objects[index];

            if (Object == nullptr) { continue; }

            FVector ObjectLocation3D = Object->GetObjectLocation();
            FVector2D ObjectLocation = MyController->ProjectWorldToScreen(Object->GetObjectLocation());
            if (!ObjectLocation.IsValid() || !ObjectLocation3D.IsValid()) { continue; }
            std::string ObjectName = kismentsystemlibrary::get_object_name((UObject*)Object).ToString();

            if (ObjectName.find(("EquippableGroundPickup_C")) != std::string::npos) {
                if (MyShooter->IsAlive()) {
                    Draw3DWeapon(canvas, MyController, ObjectLocation3D, { 255, 255, 255, 255 });
                    canvas->K2_DrawText(
                        FString{ L"Weapon" },
                        ObjectLocation,
                        FVector2D{ font_size, font_size },
                        { 1, 1, 1, 2.5f },
                        false,
                        menu::colors::Text_Shadow,
                        FVector2D{ G::pos.X + 1, G::pos.Y + 1 },
                        true,
                        true,
                        true,
                        { 0, 0, 0, 0.65f }
                    );
                }
            }
        }
    }

    if (Globals::skill_esp) {
        SPOOF_FUNC;
        TArray<AGameObject*> Objects = GameplayStatics::GetAllActorsOfClass(World, Class::ShooterGameObject());

        for (int index = 0; index < Objects.Num(); index++) {
            if (!Objects.IsValidIndex(index)) { continue; }
            AGameObject* Object = Objects[index];

            if (Object == nullptr) { continue; }

            FVector2D ObjectLocation = MyController->ProjectWorldToScreen(Object->GetObjectLocation());
            if (!ObjectLocation.IsValid()) { continue; }
            std::string ObjectName = kismentsystemlibrary::get_object_name((UObject*)Object).ToString();

            if (ObjectName.find(("GameObject_Thorne_E_Wall")) != std::string::npos) {
                float ObjectHealth = Object->GetObjectHealth();
                if (ObjectHealth == 0) { continue; }
                std::string Health = std::to_string((int)ObjectHealth) + "HP";
                std::wstring WHealth(Health.begin(), Health.end());
                FString HealthFString = FString{ WHealth.c_str() };
                DrawEspText(
                    canvas,
                    HealthFString,
                    ObjectLocation,
                    FVector2D{ 1.15f, 1.15f },
                    { 1, 1, 1, 1.5f },
                    0.74f
                );
            }

            skills_names(ObjectName, MyShooter, canvas, ObjectLocation);
        }
    }

    if (Globals::EnableAim && Globals::DrawFov) {
        SPOOF_FUNC;
        if (Globals::CoolFov)
        {
                rainbowTimeZ += 0.005f;
                FLinearColor RainbowColor = BOSSRAINBOMAW(rainbowTimeZ);
            menu::DrawCircle({ (float)canvas->GetScreenSize().X / 2, (float)canvas->GetScreenSize().Y / 2 }, Globals::LegitFOvValue, 100.0f, RainbowColor);

        }
        else
        {
            menu::DrawCircle({ (float)canvas->GetScreenSize().X / 2, (float)canvas->GetScreenSize().Y / 2 }, Globals::LegitFOvValue, 100.0f, Colors::FovColor);
        }
       
    }
    if (Globals::crosshairrainbow)
    {
        SPOOF_FUNC; 
        rainbowTimeZ += 0.005f;
        FLinearColor RainbowColor = BOSSRAINBOMAW(rainbowTimeZ);
        FVector2D ScreenSize;
        ScreenSize = canvas->GetScreenSize();

        float CenterX = ScreenSize.X / 2.0f;
        float CenterY = ScreenSize.Y / 2.0f;

        float Offset = 5.0f; // tiny like TenZ's
        float Thickness = 2.0f; // Line thickness
        //FLinearColor CrosshairColor = FLinearColor(0.0f, 1.0f, 1.0f, 1.0f); // Cyan

        // Draw horizontal line
        canvas->K2_DrawLine(
            FVector2D(CenterX - Offset, CenterY),
            FVector2D(CenterX + Offset, CenterY),
            Thickness,
            RainbowColor
        );

        // Draw vertical line
        canvas->K2_DrawLine(
            FVector2D(CenterX, CenterY - Offset),
            FVector2D(CenterX, CenterY + Offset),
            Thickness,
            RainbowColor
        );
    }
    if (Globals::SkipTutorial) {
        SPOOF_FUNC;
        MyController->DisconnectFromServer();
        SPOOF_CALL(Beep)(300, 300);
        Globals::SkipTutorial = false;
    }

    for (int Index = 0; Index < Actors.Num(); Index++) {
        SPOOF_FUNC;

        if (!Actors.IsValidIndex(Index)) { continue; }
        Char = MyController->K2_GetPawn_in();

        Actor = Actors[Index];
        Rehook(World, MyController);

        if (Actor == nullptr || !MyShooter || !Char) { continue; }

        if (auto eq = MyShooter->GetInventory()->GetCurrentWeapon()) {
            FString obj_name = helper::convert_weapon_name(kismentsystemlibrary::get_object_name(eq));
            G::IsKnife = (obj_name.wide() == L"Melee");
        }

        if (Globals::FovChangerBool) {
            SPOOF_FUNC;
            FovChanger(MyController);
            Globals::FovChangerBool = false;
        }

        if (Globals::RecoilCrosshair && !G::IsKnife) {
            SPOOF_FUNC;
            float screen_width = canvas->GetScreenSize().X;
            float screen_height = canvas->GetScreenSize().Y;
            if (!hasTarget2) {
                FVector punchAngle = (MyCamera->GetCameraRotation() - MyController->GetControlRotation()).ClampFVector();
                float centerX = screen_width / 2 + (screen_width / 90 * punchAngle.Y * 0.75f);
                float centerY = screen_height / 2 - (screen_height / 90 * punchAngle.X * 0.75f);

                FLinearColor circleColor = { 255, 255, 255, 255 };
                menu::DrawCircle({ centerX, centerY }, 5.25f, 20, circleColor);

                hasTarget2 = true;
            }
        }
        static float spin_yaw = 0.f;

        APawn* pawn = MyController->get_acknowledged_pawn();
        Mesh = Actor->GetPawnMesh2();   
        ThirdPersonMesh = MyPawn + Offsets::Mesh3P;
        AAresEquippable* Equippable = Actor->GetInventory()->GetCurrentWeapon();

        if (!Mesh || !Equippable) { continue; }

        if (!Globals::TeamCheck) {
            SPOOF_FUNC;
            if (BaseTeamComponent::IsAlly(Actor, MyShooter)) { continue; }
        }

        if (!Actor->IsAlive()) { continue; }
        if (Actor->IsDeadAndSettled()) { continue; }
        if (!Actor->IsDormant()) { continue; }

        auto Head = GetBoneMatrix(Mesh, Bones::head);
        auto Base = GetBoneMatrix(Mesh, Bones::base);
        auto CestBone = GetBoneMatrix(Mesh, 6);

        auto HeadOut = MyController->ProjectWorldToScreen(Head);
        auto HeadLongOut = MyController->ProjectWorldToScreen(FVector(Head.X, Head.Y, Head.Z + 15));
        auto HeadLongOut2 = MyController->ProjectWorldToScreen(FVector(Head.X, Head.Y, Head.Z + 17.5f));
        auto BaseOut = MyController->ProjectWorldToScreen(Base);
        auto Cest = MyController->ProjectWorldToScreen(CestBone);

        if (!HeadOut.IsValid() || !BaseOut.IsValid())
            continue;

        float BoxHeight = abs(HeadLongOut.Y - BaseOut.Y);
        float BoxWidth = BoxHeight * 0.55;

        float Health = Actor->GetHealth();
        float Shield = Actor->GetShield();

        auto RelativeLocation = Actor->K2_GetActorLocation();
        auto MyShooterRelativeLocation = MyShooter->K2_GetActorLocation();
        auto distance2 = MyShooterRelativeLocation.Distance(RelativeLocation);
        auto distance = distance2 / 5;

        if (Health <= 0) { continue; }

        FString ObjectName = kismentsystemlibrary::get_object_name(reinterpret_cast<UObject*>(Actor));
        FString WeaponName = kismentsystemlibrary::get_object_name(reinterpret_cast<UObject*>(Equippable));

        bool IsAlive = Actor->IsAlive();

        bool IsDormant = Dormant(Actor);
        if (!IsDormant) continue;

        bool IsDormantServer = DormantServer(Actor);
        if (!IsDormantServer) continue;

        if (Health <= 100 && Health > 0) {
            SPOOF_FUNC;
            if (Mesh && IsAlive) {
                SPOOF_FUNC;
                if (Health >= 75) { health::HealthColor = health::HighHealth; }
                else if (Health <= 74 && Health >= 44) { health::HealthColor = health::NormalHealth; }
                else if (Health <= 45) { health::HealthColor = health::LowHealth; }

                if (MyController->LineOfSightTo(Actor, { 0, 0, 0 }, false)) {
                    Colors::LineColor = Colors::LineVisible;
                    Colors::BoxColor = Colors::BoxVisible;
                    Colors::Skeleton = Colors::SkeletonVisible;
                    Colors::ChamsColor1 = Colors::ChamsVisible;
                }
                else {
                    Colors::BoxColor = Colors::Boxinvisible;
                    Colors::LineColor = Colors::LineINvisible;
                    Colors::Skeleton = Colors::SkeletonInvisible;
                    Colors::ChamsColor1 = Colors::ChamsInvisible;
                }
                FVector2D HeadPos;
                if (!MyController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 8), HeadPos, 0) || !HeadPos.IsValid()) {
                    return;
                }

                FVector2D FootPos;
                if (!MyController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 0), FootPos, 0) || !FootPos.IsValid()) {
                    return;
                }
                if (Globals::EnableESP && Health <= 100) {
                    if (Globals::DistangeEsp) {
                        FVector2D HeadPos;

                        if (MyController->ProjectWorldLocationToScreen(GetBoneMatrix(Mesh, 8), HeadPos, 0) && HeadPos.IsValid()) {
                            char buffer[32];
                            sprintf_s(buffer, ez("[%.fM]", ).d(), distance);
                            if (distance < 38) {    
                                if (Globals::WeaponEsp) {
                                    canvas->K2_DrawText(s2wc(buffer), FVector2D(BaseOut.X, BaseOut.Y + 35),
                                        FVector2D{ 0.8f, 0.8f }, { 1, 1, 1, 2.5f }, false, menu::colors::Text_Shadow,
                                        FVector2D{ G::pos.X + 1, G::pos.Y + 1 }, true, true, true, { 0, 0, 0, 0.49 });
                                }
                                else {
                                    canvas->K2_DrawText(s2wc(buffer), FVector2D(BaseOut.X, BaseOut.Y + 25),
                                        FVector2D{ 0.8f, 0.8f }, { 1, 1, 1, 2.5f }, false, menu::colors::Text_Shadow,
                                        FVector2D{ G::pos.X + 1, G::pos.Y + 1 }, true, true, true, { 0, 0, 0, 0.49 });
                                }
                            }
                        }
                    }

                    if (Globals::HeadESP) {
                        SPOOF_FUNC;
                        float lineW = (BoxWidth / 7);
                        float lineH = (BoxHeight / 7);
                        FVector2D position = { HeadLongOut2.X, HeadLongOut2.Y + 7.0f }; // Adjust the Y position to move it down
                        SPOOF_CALL(DrawCircle)(canvas, position, lineW, lineH, Colors::Skeleton);
                    }


                    if (Globals::SkeletonEsp && Actor->IsAlive()) {
                        SPOOF_FUNC;
                        int32_t bone_count = Memory::R<int32_t>((uintptr_t)Mesh + Offsets::bone_cout);
                        SPOOF_CALL(DrawSkeleton)(MyController, Mesh, bone_count, canvas);
                    }
                    if (Globals::AgentIcon && Actor->IsAlive())
                    {
                        FVector2D position1 = { Head.X - 10, Head.Y + 28 };
                        SPOOF_CALL(agent_icon)(Actor, position1, distance, canvas);
                    }
                    if (Globals::CorneredBox && Actor->IsAlive()) {
                        SPOOF_FUNC;
                        SPOOF_CALL(DrawCorner)(canvas, MyController, Mesh, Colors::BoxColor, Globals::ESPThickness);
                    }
                    if (Globals::Box3D && Actor->IsAlive()) {
                        SPOOF_FUNC;
                        SPOOF_CALL(Draw3D)(canvas, MyController, Mesh, Colors::BoxColor);
                    }
                    if (Globals::Box2D) {
                        SPOOF_FUNC;
                        SPOOF_CALL(Draw2DBox)(canvas, MyController, Mesh, Colors::BoxColor);
                    }

                    if (Globals::Snapline && !ObjectName.IsEmpty() && Actor->IsAlive()) {
                        SPOOF_FUNC;
                        if (Globals::SelectSnapline == 0) {
                            SPOOF_CALL(DrawLineBottomLocation)(canvas, MyController, Mesh);
                        }
                        else if (Globals::SelectSnapline == 1) {
                            SPOOF_CALL(DrawSnapline)(canvas, MyShooter, HeadOut, Colors::LineColor, Globals::ESPThickness);
                        }
                            else if (Globals::SelectSnapline == 2) {
                            SPOOF_CALL(DrawLineTopLocation)(canvas, MyController, Mesh);
                        }
                    }
                
                    if (Globals::Healthbar && Health <= 100 && distance >= 1.3f && !ObjectName.IsEmpty()) {
                        SPOOF_FUNC;
                        SPOOF_CALL(DrawHealthAndShieldBars)(canvas, Health, Shield, HeadPos, FootPos, distance);
                    }
                    if (Globals::HealthText && Health <= 100 && distance >= 1.3f && !ObjectName.IsEmpty())
                    {
                        SPOOF_FUNC;

                        const int boxHeight = abs(FootPos.Y - HeadPos.Y);
                        const int boxWidth = boxHeight * 0.45f;

                        const int barHeight = boxHeight;
                        const int barThickness = 2;  // Thinner bars
                        const int barOffset = 5;

                        const int barX_Health = HeadPos.X - (boxWidth * 0.5f) - barOffset - barThickness;
                        const int barX_Shield = barX_Health - barThickness - 2;
                        const int barY = HeadPos.Y;

                        const int healthHeight = FMath::Clamp(int((Health / 100.0f) * barHeight), 0, barHeight);
                        const int shieldHeight = FMath::Clamp(int((Shield / 50.0f) * barHeight), 0, barHeight);

                        const FLinearColor outlineColor = FLinearColor(0, 0, 0, 0.5f); // Lower opacity outline

                        FLinearColor healthColor = FLinearColor(0.0f, 1.0f, 0.0f, 1.0f); // green
                        if (Health <= 25)
                            healthColor = FLinearColor(1.0f, 0.0f, 0.0f, 1.0f); // red
                        else if (Health <= 50)
                            healthColor = FLinearColor(1.0f, 1.0f, 0.0f, 1.0f); // yellow

                        FLinearColor shieldColor = FLinearColor(0.25f, 0.6f, 1.0f, 1.0f); // light blue
                        // Calculate total health + shield
                        float totalHealth = Health + Shield;
                        const float textScale = FMath::Clamp(0.85f / (distance / 15.0f), 0.5f, 0.85f);  // Scale text size based on distance

                        // Draw the combined health + shield text
                        wchar_t healthTextBuffer[8];
                        swprintf_s(healthTextBuffer, (L"%d"), static_cast<int>(totalHealth)); // Use combined total health/shield value
                        FString healthText(healthTextBuffer);
                        int healthTextX = barX_Health + (barThickness / 2) - (healthText.Num() * 4); // Adjust for text length (approximate width)
                        int shieldTextX = barX_Shield + (barThickness / 2) - (healthText.Num() * 4); // Similarly for shield
                        int textCenterY = barY + (barHeight / 2) - 10; // Slightly adjust Y for centering
                        DrawEspText(
                            canvas,
                            healthText,
                            FVector2D(healthTextX, textCenterY),  // Position the text at the center of the health bar
                            FVector2D(textScale, textScale),       // Adjust text scale based on distance
                            FLinearColor(1.0f, 1.0f, 1.0f, 1.0f)   // Text color (white)
                        );
                    }
                    if (Globals::WeaponEsp && Actor->IsAlive()) {
                        SPOOF_FUNC;
                            DrawEspText(canvas,Filters::Names::WeaponName(WeaponName),
                            FVector2D(BaseOut.X, BaseOut.Y + 20), FVector2D{ 0.8f, 0.8f },
                            Colors::WeaponNameColor,0.75f);
                    }

                    if (Globals::AgentName && !ObjectName.IsEmpty() && Actor->IsAlive()) {
                        SPOOF_FUNC;



                        DrawAgentNameEsp(canvas, Actor, FVector2D(HeadLongOut.X, HeadLongOut.Y - 30), Mesh, MyController, BoxWidth, distance);


                    }

                    if (Globals::riotid && Actor->IsAlive() ) {

                        FVector2D textPos = { HeadLongOut.X, HeadLongOut.Y - 40 };

                        FString negrito;    
                        if (uintptr_t mawmasarap =Memory::R<uintptr_t>((uintptr_t)Actor + Offsets::PlayerState)) {
                            if (FString* Name =Memory::R<FString*>((uintptr_t)mawmasarap + Offsets::PlatformPlayer)) {
                                FString RiotUsr =Memory::R<FString>((uintptr_t)Name + Offsets::RiotName);
                                std::string RiotUsrStr = RiotUsr.ToString();

                                if (!RiotUsrStr.empty())
                                {
                                    std::wstring wideStr(RiotUsrStr.begin(), RiotUsrStr.end());
                                    FString negrito = FString(wideStr.c_str());
                                    DrawEspText(canvas, negrito, textPos, FVector2D(1.f, 1.f), FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), 0.75f);
                                    
                                }
                            }
                        }

                    }
                    if (Globals::invisiblehands)
                    {
                        UPrimitiveComponent* mesh1 = nullptr;
                        UPrimitiveComponent* mesh_2 = nullptr;
                        if (auto handmesh = MyShooter->GetOverlayMesh1P()) {
                            UPrimitiveComponent* mesh_first_person = Memory::R<UPrimitiveComponent*>(uintptr_t(MyPawn) + Offsets::mesh1p);
                            if (!mesh_first_person) return;
                            mesh1 = mesh_first_person;

                            UPrimitiveComponent* mesh_overlay_first_person = Memory::R<UPrimitiveComponent*>(uintptr_t(MyPawn) + Offsets::mesh1p_overlay);
                            if (!mesh_overlay_first_person) return;
                            mesh_2 = mesh_overlay_first_person;


                            meshp1_material(MyPawn, Actor);


                        }
                    }
                    
            

                    /*static float spin_yaw = 0.f;
                    if (Globals::SpinBot) {
                        spin_yaw = (spin_yaw >= 360.f) ? 0.f : spin_yaw + Globals::spinbot_speed;
                        MyShooter->GetPawnMesh2()->set_world_rotation({ 0.f, spin_yaw, 0.f }, false, true);
                    }*/
             
                    

                    if (Globals::ChamsESP) {
                            SPOOF_FUNC;
                            if (!Globals::outline) {
                                using SetAresOutlineModeFunc = bool(__fastcall*)(USkeletalMeshComponent*, int, bool);
                            USkeletalMeshComponent* myselfchams = Memory::R<USkeletalMeshComponent*>(uintptr_t(pawn) + Offsets::thirdpersoncosmetic);
                                SetAresOutlineModeFunc outlineFunc = reinterpret_cast<SetAresOutlineModeFunc>(VALORANT::Module + Offsets::set_ares_outline);
                                bool isCharacterAlive = outlineFunc(Mesh, 4, true);
                        }
                        else if (Globals::outline) {
                            SPOOF_FUNC;

                            reinterpret_cast<USkeletalMeshComponent* (__fastcall*)(USkeletalMeshComponent*, int, bool)>(VALORANT::Module + Offsets::set_ares_outline)(Mesh, 4, true);

                            if (Globals::rainbow_chams)
                            {   
                                rainbowTimeZRGB += 0.004f;
                                FLinearColor RainbowColor = BOSSRAINBOMAW(rainbowTimeZRGB);

                                AresOutlineRendering::SetOutlineColorsForRender(World, { RainbowColor.R * Globals::glowenemyfloat, RainbowColor.G * Globals::glowenemyfloat, RainbowColor.B * Globals::glowenemyfloat ,RainbowColor.A * Globals::glowenemyfloat }, { RainbowColor.R * Globals::glowenemyfloat, RainbowColor.G * Globals::glowenemyfloat, RainbowColor.B * Globals::glowenemyfloat, RainbowColor.A * Globals::glowenemyfloat });
                            }
                            else if (Globals::visibleCheckChams)
                            {
                                SPOOF_FUNC;
                                AresOutlineRendering::SetOutlineColorsForRender(World,
                                    { Colors::ChamsColor1.R * Globals::glowenemyfloat, Colors::ChamsColor1.G * Globals::glowenemyfloat, Colors::ChamsColor1.B * Globals::glowenemyfloat, Colors::ChamsColor1.A * Globals::glowenemyfloat },
                                    { Colors::ChamsColor1.R * Globals::glowenemyfloat, Colors::ChamsColor1.G * Globals::glowenemyfloat, Colors::ChamsColor1.B * Globals::glowenemyfloat, Colors::ChamsColor1.A * Globals::glowenemyfloat });
                            }
                            else
                            {
                                SPOOF_FUNC;
                                AresOutlineRendering::SetOutlineColorsForRender(World,
                                    { Colors::ChamsColor.R * Globals::glowenemyfloat, Colors::ChamsColor.G * Globals::glowenemyfloat, Colors::ChamsColor.B * Globals::glowenemyfloat, Colors::ChamsColor.A * Globals::glowenemyfloat },
                                    { Colors::ChamsColor.R * Globals::glowenemyfloat, Colors::ChamsColor.G * Globals::glowenemyfloat, Colors::ChamsColor.B * Globals::glowenemyfloat, Colors::ChamsColor.A * Globals::glowenemyfloat });
                            }

                        }
                        else {
                            SPOOF_FUNC;
                            Mesh->SetOutlineMode(EAresOutlineMode::None);
                        }
                    }
                    if (Globals::ChamsESP) {

                        if (Globals::rainbow_chams) {

                            rainbowTimeZRGB += 0.004f;
                            FLinearColor RainbowColor = BOSSRAINBOMAW(rainbowTimeZRGB);
                            auto niga = VALORANT::Module + Offsets::set_ares_outline;
                            USkeletalMeshComponent* myselfchams = Memory::R<USkeletalMeshComponent*>(uintptr_t(pawn) + Offsets::thirdpersoncosmetic);
                            reinterpret_cast<void (*)(USkeletalMeshComponent*, int, bool, uintptr_t, void*)>(spoofcall_stub)(myselfchams, 4, true, Offsets::MagicOffsets, (void*)niga);
                            reinterpret_cast<void (*)(USkeletalMeshComponent*, int, bool, uintptr_t, void*)>(spoofcall_stub)(Mesh, 4, true, Offsets::MagicOffsets, (void*)niga);

                            AresOutlineRendering::SetOutlineColorsForRender(World, { RainbowColor.R * Globals::glowenemyfloat, RainbowColor.G * Globals::glowenemyfloat, RainbowColor.B * Globals::glowenemyfloat ,RainbowColor.A * Globals::glowenemyfloat }, { RainbowColor.R * Globals::glowenemyfloat, RainbowColor.G * Globals::glowenemyfloat, RainbowColor.B * Globals::glowenemyfloat, RainbowColor.A * Globals::glowenemyfloat });
                        }
                        else {
                            USkeletalMeshComponent* myselfchams = Memory::R<USkeletalMeshComponent*>(uintptr_t(pawn) + Offsets::thirdpersoncosmetic);
                            auto niga = VALORANT::Module + Offsets::set_ares_outline;
                            reinterpret_cast<void (*)(USkeletalMeshComponent*, int, bool, uintptr_t, void*)>(spoofcall_stub)(myselfchams, 4, true, Offsets::MagicOffsets, (void*)niga);
                            reinterpret_cast<void (*)(USkeletalMeshComponent*, int, bool, uintptr_t, void*)>(spoofcall_stub)(Mesh, 4, true, Offsets::MagicOffsets, (void*)niga);
                            AresOutlineRendering::SetOutlineColorsForRender(World,
                                { Colors::ChamsColor.R * Globals::glowenemyfloat, Colors::ChamsColor.G * Globals::glowenemyfloat, Colors::ChamsColor.B * Globals::glowenemyfloat, Colors::ChamsColor.A * Globals::glowenemyfloat },
                                { Colors::ChamsColor.R * Globals::glowenemyfloat, Colors::ChamsColor.G * Globals::glowenemyfloat, Colors::ChamsColor.B * Globals::glowenemyfloat, Colors::ChamsColor.A * Globals::glowenemyfloat });
                        }

                    }
                    else {
                        Mesh->SetOutlineMode(EAresOutlineMode::None);
                    }


                }


                if (Globals::EnableAim) {
                    SPOOF_FUNC;
                    float screen_center_x = canvas->GetScreenSize().X / 2.f;
                    float screen_center_y = canvas->GetScreenSize().Y / 2.f;

                    float delta_x = HeadOut.X - screen_center_x;
                    float delta_y = HeadOut.Y - screen_center_y;

                    float distance = sqrtf(delta_x * delta_x + delta_y * delta_y);
                    float screen_distance = KismetMathLibrary::distance_2d(HeadOut, { screen_center_x, screen_center_y });
                    float max_distance = Globals::NoSpreadAimbot ? 1300.0f : Globals::LegitFOvValue;

                    if (distance < closest_distance && screen_distance < max_distance) {
                        target_id = Index;

                        closest_distance = screen_distance;
                    }

                }
            }
        }
    }
    static bool linganguuulinganguu = false;
    float spin_value = Globals::spinbot_speed;
    if (Globals::BuddyChanger)
    {

        FVector2D screenCenter(canvas->GetScreenSize().X * 0.5f, 50.0f);
     
        inventory_manager* manager = ares_instance::get_ares_client_game_instance(World)->get_inventory_manager();

        auto charm_instances = Memory::R<TArray<tmap<UObject*, UObject*>>>(std::uintptr_t(manager) + 0x430);
        buddy = charm_instances[index].Key;
        BuddyName = kismentsystemlibrary::get_object_name(buddy);
        if (Globals::Buddytext)
        {
            DrawEspText(canvas, BuddyName, screenCenter, FVector2D(1.f, 1.f), FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), 0.75f);
        }
        

    }
    else if (MyShooter) {
        SPOOF_FUNC;
        if (Globals::Mesh3PModifed) {
            SPOOF_FUNC;
            MyShooter->SetCrouchTimeOverride(1.0);
            Globals::Mesh3PModifed = false;
        }
    }
    if (target_id != -1) {
        SPOOF_FUNC;

        if (Globals::EnableAim && !G::IsKnife && !Globals::Menu_Open) {
            SPOOF_FUNC;

            if (!Actors.IsValidIndex(target_id)) return;

            AShooterCharacter* Actor = Actors[target_id];
            if (!Actor || !MyShooter || !isActorValid(Actor, MyShooter)) return;

            USkeletalMeshComponent* Mesh = Actor->GetPawnMesh2();
            USkeletalMeshComponent* HandMesh = MyShooter->GetOverlayMesh1P();
            if (!Mesh || Actor->GetHealth() <= 0) return;

            FVector Target;


            Target = GetBoneMatrix(Mesh, Globals::AimBone == 0 ? 8 : (Globals::AimBone == 1 ? 6 : 3));

            FVector CameraPos = MyCamera->GetCameraLocation();
            FVector ControlRotation = MyController->GetControlRotation();
            FVector CameraRot = MyCamera->GetCameraRotation();

            //auto IsInFovAndVisible = [&]() {
                //SPOOF_FUNC;
                //return in_rect(
                    //Globals::ScreenCenterX,
                    //Globals::ScreenCenterY,
                    //Globals::LegitFOvValue,
                    //head_screen.X,
                    //head_screen.Y
                //) && (Globals::VisibleCheck && MyController->LineOfSightTo(Actor)) || !Globals::VisibleCheck;
                //};

            auto ApplyAimbot = [&]() {
                SPOOF_FUNC;
                FVector recoil;
                recoil.X = CameraRot.X - ControlRotation.X;
                recoil.Y = CameraRot.Y - ControlRotation.Y;
                recoil.Z = 0.f;

                Globals::RecoilControl ? aimbot_recoil(CameraRot, ControlRotation, Target, CameraPos, recoil, MyController)
                    : aimbot(CameraRot, ControlRotation, Target, CameraPos, MyController);
                };

            if (MyController->ProjectWorldLocationToScreen(Target, head_screen, 0) && head_screen.IsValid()) {
                if (Globals::EnableAim &&
                    (GetAsyncKeyState(Globals::LegitBotKey) & 0x8000) ||
                    (GetAsyncKeyState(Globals::SecondKey) & 0x8000) &&
                    !G::pixel_time_bool &&
                    //IsInFovAndVisible() &&
                    !Globals::NoSpreadAimbot &&
                    !hasTarget)
                {
                    ApplyAimbot();
                    hasTarget = true;
                }

                //else if (Globals::Aimlock && !Globals::RecoilControl && !G::pixel_time_bool && IsInFovAndVisible() && !Globals::NoSpreadAimbot && !hasTarget) {
                else if (Globals::Aimlock && !Globals::RecoilControl && !G::pixel_time_bool && !Globals::NoSpreadAimbot && !hasTarget) {
                    ApplyAimbot();
                    hasTarget = true;
                }
                //else if (Globals::EnableAim && Globals::Aimlock && Globals::RecoilControl && IsInFovAndVisible() && !Globals::NoSpreadAimbot && !hasTarget) {
                else if (Globals::EnableAim && Globals::Aimlock && Globals::RecoilControl && !Globals::NoSpreadAimbot && !hasTarget) {
                    ApplyAimbot();
                    hasTarget = true;
                }
            }
        }
    }

    return pRender(_this, canvas, a3);
}
