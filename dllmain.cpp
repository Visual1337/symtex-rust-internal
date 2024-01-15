
#include <dxgi.h>

#include <winnt.h>
#include <winternl.h>
#include "vmp_sdk.h"
#include "imports.h"
 
#define Release release

#define nocrt_max(a,b)            (((a) > (b)) ? (a) : (b))
#define nocrt_min(a,b)            (((a) < (b)) ? (a) : (b))

bool wake = true;
DWORD64 __go;


using _CreateDirectoryA___ = bool(__cdecl*)(LPCSTR, LPSECURITY_ATTRIBUTES);
_CreateDirectoryA___ m_CreateDirectoryA;

void UI_Update(void* instance) {
    if (wake) {
        __go = Il2cpp::recreated_object_new(Il2cpp::InitClass(_("GameObject"), _("UnityEngine")));

        GUI::GuiMethods::create(__go, _(L""));
        GUI::GuiMethods::add_component(__go, Il2cpp::TypeGetObject(_(""), _("DevControls")));
        GUI::dont_destroy_on_load(__go);
        wake = false;
    }
    GUI::GuiMethods::Update(instance);
}

namespace module
{
    DWORD64 kernel32 = 0;
}

namespace util
{
    auto __CreateThread = reinterpret_cast<void(*)(int, int, LPTHREAD_START_ROUTINE, int, int, int)>(0);
}


DWORD64 GetFunction(const char* modename, const char* func)
{
    return Il2cpp_Utils::GetExport((DWORD64)Il2cpp_Utils::GetModuleBase_Wrapper(modename), func);
}

bool initAllMethods()
{


    static bool isInited = false;

    if (!isInited) {
        g_Base = (DWORD64)Il2cpp_Utils::GetModuleBase_Wrapper(_("GameAssembly.dll"));
        Crt_strstr = (strstrf___)Il2cpp_Utils::GetExport((DWORD64)Il2cpp_Utils::GetModuleBase_Wrapper(_("ucrtbase.dll")), _("strstr"));
        m_PlaySound = (playsoundf___)Il2cpp_Utils::GetExport((DWORD64)Il2cpp_Utils::GetModuleBase_Wrapper(_("Winmm.dll")), _("PlaySound"));
        f_swprint = (_swprintf___)Il2cpp_Utils::GetExport((DWORD64)Il2cpp_Utils::GetModuleBase_Wrapper(_("msvcrt.dll")), _("swprintf"));

        auto initMethod = reinterpret_cast<__int64(*)(__int64, __int64)>(Il2cpp::FindPattern(_("48 89 5C 24 18 41 56 48 83 EC 40 33 DB 44 0F B6 D2 44 8B CB 4C 8B F1"), _("GameAssembly.dll")));
        initMethod(g_Base + offsets::Method$BaseEntity_ServerRPCPlayerProjectileShoot__, 1);
        initMethod(g_Base + offsets::Method$BaseEntity_ServerRPC_PlayerProjectileAttack___, 1);

        

        m_CreateFileA = (CFW)GetFunction(_("kernel32.dll"), _("CreateFileA"));
        m_WriteFile = (WFEX)GetFunction(_("kernel32.dll"), _("WriteFile"));
        m_ReadFile = (RFEX)GetFunction(_("kernel32.dll"), _("ReadFile"));
        m_CloseHandle = (CH)GetFunction(_("kernel32.dll"), _("CloseHandle"));
        m_DeleteFileW = (DFW)GetFunction(_("kernel32.dll"), _("DeleteFileW"));
        m_GetFileSizeEx = (GFSEX)GetFunction(_("kernel32.dll"), _("GetFileSizeEx"));
        m_PathFileExistsW = (PFEW)GetFunction(_("shlwapi.dll"), _("PathFileExistsW"));
        m_SHGetFolderPathW = (SHGFPW)GetFunction(_("shell32.dll"), _("SHGetFolderPathW"));
       
        Il2cpp::Il2cppInit();
        GUI::GuiMethods::InitMethods();
        GUI::GuiMethods::InitMethods2();
        Unity::InitUnity();
        Classes::InitClasses();
        Classes::InitClasses2();
        Hooks::InitHooks();
        Dump::InitDumper1();
        Dump::InitDumper2();
        Dump::InitDumper3();
        InitExploits();

        isInited = true;
    }

    return isInited;
}

void CleanOverlay()
{

}



void OnViewmodelEvent()
{

}

bool CanHit(DWORD64 asdasd, HitTest info)
{
    return true;
}

DWORD64 LastUpdatedProjectile;
DWORD64 orig_blm;
int LoadTime = 0;






bool DllMain(uintptr_t hmodule)
{

    if (initAllMethods()) {
        Il2cpp_Hook(&UI_Update, _("Update"), _("PerformanceUI"), _("Facepunch"), 0);
        Il2cpp_Hook(&OnGUI, _("OnGUI"), _("DevControls"), _(""), 0);
        Il2cpp_Hook(&UpdateProjectile_Hook, _("Update"), _("Projectile"), _(""), 0);

        Il2cpp_Hook(&CleanOverlay, _("Update"), _("WaterOverlay"), _(""), 0);
        Il2cpp_Hook(&CleanOverlay, _("Update"), _("ColdOverlay"), _(""), 0);

        Virtual_Hook(_("BasePlayer"), _("ClientInput"), &hk_ClientInput); 
        Virtual_Hook(_("BaseMelee"), _("ProcessAttack"), &ProcessAttack_hk); 
        Virtual_Hook(_("BaseProjectile"), _("CanAttack"), &CanAttack_hk); 
        Virtual_Hook(_("BaseProjectile"), _("CanAim"), &CanAim_hk); 

        return true;
    }

    return false;
}