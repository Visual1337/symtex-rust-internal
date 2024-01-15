#pragma once

typedef struct _UncStr
{
	char stub[0x10];
	int len;
	wchar_t str[1];
} *pUncStr;

//#define in_range(x,a,b) (x>=a&&x<=b) 
//#define get_bits(x) (in_range((x&(~0x20)),'A','F')?((x&(~0x20))-'A'+0xa):(in_range(x,'0','9')?x-'0':0))
//#define get_byte(x) (get_bits(x[0])<<4|get_bits(x[1]))

namespace Il2cpp_Utils
{

	__declspec(noinline) PBYTE GetModuleBase_Wrapper(const char* ModuleName)
	{
		PPEB_LDR_DATA Ldr = ((PTEB)__readgsqword(FIELD_OFFSET(NT_TIB, Self)))->ProcessEnvironmentBlock->Ldr; void* ModBase = nullptr;
		for (PLIST_ENTRY CurEnt = Ldr->InMemoryOrderModuleList.Flink; CurEnt != &Ldr->InMemoryOrderModuleList; CurEnt = CurEnt->Flink) {
			LDR_DATA_TABLE_ENTRY* pEntry = CONTAINING_RECORD(CurEnt, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
			PUNICODE_STRING BaseDllName = (PUNICODE_STRING)&pEntry->Reserved4[0];
			if (!ModuleName || StrCmp(ModuleName, BaseDllName->Buffer, false))
				return (PBYTE)pEntry->DllBase;
		}

		return nullptr;
	}

	ULONG64 GetExport(ULONG64 hDll, const char* Name)
	{
		PIMAGE_NT_HEADERS NT_Head = (PIMAGE_NT_HEADERS)(hDll + ((PIMAGE_DOS_HEADER)hDll)->e_lfanew);
		PIMAGE_EXPORT_DIRECTORY ExportDir = (PIMAGE_EXPORT_DIRECTORY)(hDll + NT_Head->OptionalHeader.DataDirectory[0].VirtualAddress);

		for (DWORD i = 0; i < ExportDir->NumberOfNames; i++)
		{
			USHORT Ordinal = ((USHORT*)(hDll + ExportDir->AddressOfNameOrdinals))[i];
			const char* ExpName = (const char*)hDll + ((DWORD*)(hDll + ExportDir->AddressOfNames))[i];

			for (int i = 0; ExpName[i] == Name[i]; i++) if (!ExpName[i])
				return hDll + ((DWORD*)(hDll + ExportDir->AddressOfFunctions))[Ordinal];
		} return 0;
	}

	//DWORD64 findsex(DWORD64 range_start, DWORD64 range_end, const char* pattern) {
	//	const char* pattern_bytes = pattern;

	//	DWORD64 first_match = 0;

	//	for (DWORD64 cur_byte = range_start; cur_byte < range_end; cur_byte++) {
	//		if (!*pattern_bytes)
	//			return first_match;

	//		if (*(uint8_t*)pattern_bytes == '\?' || *(uint8_t*)cur_byte == static_cast<uint8_t>(get_byte(pattern_bytes))) {
	//			if (!first_match)
	//				first_match = cur_byte;

	//			if (!pattern_bytes[2])
	//				return first_match;

	//			if (*(uint16_t*)pattern_bytes == '\?\?' || *(uint8_t*)pattern_bytes != '\?')
	//				pattern_bytes += 3;
	//			else
	//				pattern_bytes += 2;
	//		}
	//		else {
	//			pattern_bytes = pattern;
	//			first_match = 0;
	//		}
	//	}

	//	return 0;
	//}
	//DWORD64 FindPtr(const char* mod, const char* pattern) {
	//	/*const char* pattern_bytes = pattern;

	//	DWORD64 range_start = (DWORD64)LI_MODULE_SAFE_(mod);

	//	DWORD64 range_end = range_start + (DWORD64)LI_MODULE_SAFE_(mod);

	//	return findsex(range_start, range_end, pattern);*/
	//}

}
// const char* (*)(DWORD64, uint32_t);
	// const char* (*)(DWORD64);
//auto method_get_name = LI_FIND_DEF(il2cpp_method_get_name);
typedef const char* (*il2cpp_method_get_param_name)(DWORD64, uint32_t);
typedef const char* (*il2cpp_method_get_name)(DWORD64);
typedef int(*GPC)(DWORD64);
typedef DWORD64(*AGI)(DWORD64);
typedef DWORD64(*resolve)(const char*);
typedef DWORD64(*Dm)();
typedef DWORD64(*CFN)(DWORD64, const char*, const char*);
typedef DWORD64(*Call)(DWORD64, DWORD64);
typedef DWORD64(*Ptr)(DWORD64, DWORD64*);
typedef DWORD64* (*DGA)(void*, DWORD64*);

struct Il2CppClass
{
				// 0x0128
};

namespace Il2cpp
{
	//il2cpp_method_get_param_name method_get_param_name = (il2cpp_method_get_param_name)(Il2cpp_Utils::GetExport(mem::game_assembly_base, _("il2cpp_method_get_param_name")));
	//il2cpp_method_get_name method_get_name = (il2cpp_method_get_name)(GetExport(mem::game_assembly_base, _("il2cpp_method_get_name")));

	il2cpp_method_get_param_name method_get_param_name = 0;
	il2cpp_method_get_name method_get_name = 0;
	Ptr class_get_methods = 0;
	Ptr class_get_fields = 0;
	Dm domain_get = 0;
	Dm thread_attach = 0;
	DGA domain_get_assemblies = 0;
	AGI assembly_get_image = 0;
	CFN class_from_name = 0;
	AGI field_get_offset = 0;
	Ptr field_static_get_value = 0;
	GPC method_get_param_count = 0;
	Call array_new = 0;
	resolve new_string = 0;
	AGI type_get_object = 0;
	AGI class_get_type = 0;
	resolve resolve_icall = 0;
	AGI object_new = 0;
	AGI runtime_class_init = 0;
	void Il2cppInit()
	{
		runtime_class_init = (AGI)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_runtime_class_init")));
		method_get_param_name = (il2cpp_method_get_param_name)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_method_get_param_name")));
		method_get_name = (il2cpp_method_get_name)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_method_get_name")));
		class_get_methods = (Ptr)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_class_get_methods")));
		class_get_fields = (Ptr)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_class_get_fields")));
		domain_get = (Dm)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_domain_get")));
		thread_attach = (Dm)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_thread_attach")));
		domain_get_assemblies = (DGA)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_domain_get_assemblies")));
		assembly_get_image = (AGI)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_assembly_get_image")));
		class_from_name = (CFN)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_class_from_name")));
		field_get_offset = (AGI)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_field_get_offset")));
		field_static_get_value = (Ptr)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_field_static_get_value")));
		method_get_param_count = (GPC)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_method_get_param_count")));
		array_new = (Call)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_array_new")));
		new_string = (resolve)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_string_new")));
		type_get_object = (AGI)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_type_get_object")));
		class_get_type = (AGI)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_class_get_type")));
		resolve_icall = (resolve)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_resolve_icall")));
		object_new = (AGI)(Il2cpp_Utils::GetExport(g_Base, _("il2cpp_object_new")));

	}

	DWORD64 Il2cppArray(DWORD64 klass, DWORD64 size) {
		DWORD64 arr = array_new(klass, size);
		return arr;
	}

	inline DWORD64 InitClass(const char* name, const char* name_space = _("")) {

		DWORD64 domain = domain_get();

		DWORD64 nrofassemblies = 0;
		DWORD64* assemblies;
		assemblies = domain_get_assemblies((void*)domain, &nrofassemblies);

		for (int i = 0; i < nrofassemblies; i++) {
			DWORD64 img = assembly_get_image(assemblies[i]);

			DWORD64 kl = class_from_name(img, name_space, name);
			if (!kl) continue;

			return kl;
		}
		return 0;
	}


	DWORD64 TypeGetObject(const char* name_space, const char* name)
	{
		auto klass = InitClass(name, name_space);
		return type_get_object(class_get_type(klass));
	}

	DWORD64 GetObjectTypeNew(const char* name_space, const char* name)
	{
		auto klass = InitClass(name, name_space);
		return object_new(klass);
	}

	

	/*inline static UINT_PTR GetType(const char* qualified_name)
	{
		static auto off = Globals::g_GameAssemblyBase + Dumper::GetMethodOffset("mscorlib", "System", "Type", "GetType", 1);
		return reinterpret_cast<UINT_PTR(__cdecl*)(String*)>(off)(String::New(qualified_name));
	}

	inline UINT_PTR GetComponent(UINT_PTR type, UINT_PTR pointer) {
		typedef UINT_PTR getComp(UINT_PTR, UINT_PTR);
		return ((getComp*)(Globals::g_GameAssemblyBase + Dumper::GetMethodOffset("UnityEngine.CoreModule", "UnityEngine", "Component", "GetComponent", 1)))(pointer, type);
	}

	inline UINT_PTR GetGameObjectComponent(UINT_PTR type, UINT_PTR pointer) {
		typedef UINT_PTR getComp(UINT_PTR, UINT_PTR);
		return ((getComp*)(Globals::g_GameAssemblyBase + Dumper::GetMethodOffset("UnityEngine.CoreModule", "UnityEngine", "GameObject", "GetComponent", 1)))(pointer, type);
	}*/





	inline DWORD64 Method(const char* kl, const char* name, int argument_number = -1, char* arg_name = _(""), const char* name_space = _(""), int selected_argument = -1) {
		DWORD64 iter = 0;
		auto klass = InitClass(kl, name_space);
		if (IsValidPointer(klass))
		{
			while (DWORD64 f = class_get_methods(klass, &iter)) {
				if (IsValidPointer(f))
				{
					const auto st = method_get_name(f);
					if (IsValidPointer((DWORD64)st))
					{
						if (m_strcmp(st, (char*)name)) {
							if (selected_argument >= 0 && arg_name) {

								int method_count = method_get_param_count(f);
								if (selected_argument > method_count || (argument_number >= 0 && method_count != argument_number)) continue;

								const char* argname;
								if (method_count > 0) {
									argname = method_get_param_name(f, selected_argument - 1);
								}
								else
									argname = (char*)_("-");

								if (!argname || !m_strcmp(argname, arg_name)) continue;
							}

							return f;
						}
					}
				}
			}
		}
		return 0;
	}

	//inline UINT_PTR GetGameObjectComponent(UINT_PTR type, UINT_PTR pointer) {
	//	typedef UINT_PTR getComp(UINT_PTR, UINT_PTR);
	//	auto ObjectComponent = reinterpret_cast<UINT_PTR(*)(UINT_PTR, UINT_PTR)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GameObject"), _("GetComponent"), 1, _("type"), _("UnityEngine"), 1)));
	//	return ObjectComponent(type, pointer);//((getComp*)(Globals::g_GameAssemblyBase + Dumper::GetMethodOffset("UnityEngine.CoreModule", "UnityEngine", "GameObject", "GetComponent", 1)))(pointer, type);
	//}

	DWORD64 Field(DWORD64 klass, char* field_name, bool get_offset = true) {
		DWORD64 out = 0;
		DWORD64 il2cpp_field;

		while (il2cpp_field = class_get_fields(klass, &out)) {

			char* name = (char*)Read<DWORD64>(il2cpp_field);
			if (!name)
				break;

			if (!m_strcmp(name, field_name)) {
				continue;
			}
			if (!get_offset)
				return il2cpp_field;

			DWORD64 offset = field_get_offset(il2cpp_field);
			return offset;
		}
		return 0;
	}

	DWORD64 GetValue(const char* kl, char* name, bool get_offset = true) {

		auto klass = InitClass(kl);

		if (get_offset) {
			auto field_offset = Field(klass, name);
			return field_offset;
		}
		else
		{
			auto _field = Field(klass, name, false);

			DWORD64 ret;
			field_static_get_value(_field, &ret);
			return ret;
		}
		return 0;
	}

	DWORD64 GetOffset(const char* kl, char* name, bool get_offset = true) {

		auto klass = InitClass(kl);
		auto field_offset = Field(klass, name);

		return field_offset;
	}

	PBYTE FindPattern(const char* Pattern, const char* Module = nullptr)
	{
		//find pattern utils
#define InRange(x, a, b) (x >= a && x <= b) 
#define GetBits(x) (InRange(x, '0', '9') ? (x - '0') : ((x - 'A') + 0xA))
#define GetByte(x) ((BYTE)(GetBits(x[0]) << 4 | GetBits(x[1])))

//get module range
		PBYTE ModuleStart = (PBYTE)Il2cpp_Utils::GetModuleBase_Wrapper(Module); if (!ModuleStart) return nullptr;
		PIMAGE_NT_HEADERS NtHeader = ((PIMAGE_NT_HEADERS)(ModuleStart + ((PIMAGE_DOS_HEADER)ModuleStart)->e_lfanew));
		PBYTE ModuleEnd = (PBYTE)(ModuleStart + NtHeader->OptionalHeader.SizeOfImage - 0x1000); ModuleStart += 0x1000;

		//scan pattern main
		PBYTE FirstMatch = nullptr;
		const char* CurPatt = Pattern;
		for (; ModuleStart < ModuleEnd; ++ModuleStart)
		{
			bool SkipByte = (*CurPatt == '\?');
			if (SkipByte || *ModuleStart == GetByte(CurPatt)) {
				if (!FirstMatch) FirstMatch = ModuleStart;
				SkipByte ? CurPatt += 2 : CurPatt += 3;
				if (CurPatt[-1] == 0) return FirstMatch;
			}
			else if (FirstMatch) {
				ModuleStart = FirstMatch;
				FirstMatch = nullptr;
				CurPatt = Pattern;
			}
		}

		return nullptr;
	}
	__int64 recreated_object_new(uintptr_t klass) {
		__int64 v8 = *(unsigned int*)(klass + 248);
		__int64 v9, object;

		if (*(unsigned __int64*)(klass + 8))
			v9 = (__int64)reinterpret_cast<__int64(*)(unsigned __int64, unsigned __int64)>(FindPattern(_("GameAssembly.dll"), _("E8 ?? ?? ?? ?? EB 08 E8 ?? ?? ?? ?? 48 89 30")))(v8, klass);
		else
			v9 = klass;


		runtime_class_init(klass);
		object = v9;
		return object;
	}


}



DWORD64 Il2cpp_Hook(void* our_func, const char* function_to_hook, const char* class_to_hook, const char* name_space = _(""), int argument_number = -1, char* argument_name = _("")) {
	auto il2cpp_method = Il2cpp::Method(class_to_hook, function_to_hook, argument_number, argument_name, name_space);

	//if (!IsValidPointer(il2cpp_method)) return {};

	*reinterpret_cast<void**>(il2cpp_method) = our_func;
	return il2cpp_method;

}

//void virtual_hook(void* addr, void* pDes, int index, void** ret) {
//
//	// We get the vtable of viewport client
//	auto vtable = *(uintptr_t**)addr;
//
//	// Now we loop through the vtable. 
//	int methods = 0;
//	do {
//		++methods;
//	} while (*(uintptr_t*)((uintptr_t)vtable + (methods * 0x8)));
//
//	// We make our own copy of the vtable
//	auto vtable_buf = new uint64_t[methods * 0x8];
//	for (auto count = 0; count < methods; ++count) {
//		vtable_buf[count] = *(uintptr_t*)((uintptr_t)vtable + (count * 0x8));
//
//		*ret = (void*)vtable[index];
//
//		// Now we switch the function in our own copy and then finally swapping the vtable with ours 
//		vtable_buf[index] = (uintptr_t)(pDes);
//		*(uint64_t**)addr = vtable_buf;
//	}
//}
	//virtual_hook((void*)utils::get_viewportclient(), hkPostrender, 97, (void**)&Postrender);

DWORD64 Virtual_Hook(const char* classname, const char* function_to_hook, void* our_func, const char* name_space = _(""), int argnum = -1, char* argname = _("")) {
	DWORD64 search = *reinterpret_cast<DWORD64*>(Il2cpp::Method(classname, function_to_hook, argnum, argname, name_space));
	DWORD64 table = Il2cpp::InitClass(classname, name_space);
	//if (!IsValidPointer(search)) return {};

	if (search == (DWORD64)our_func)
		return (DWORD64)our_func;
	for (DWORD64 i = table; i <= table + 0x1500; i += 0x1) {
		DWORD64 addr = *reinterpret_cast<DWORD64*>(i);
		if (addr == search) {
			*reinterpret_cast<DWORD64*>(i) = (DWORD64)our_func;
			return addr;
		}
	}
}

void QwordSwap(void* ourFunc, uintptr_t funcToHook, uintptr_t& orig) {
	orig = *(uintptr_t*)funcToHook;
	*(uintptr_t*)(funcToHook) = (uintptr_t)ourFunc;
}


