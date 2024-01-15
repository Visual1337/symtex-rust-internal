#pragma once
bool looped = false;

// extern "C" { int _fltused = 0; }
// extern "C" void __chkstk() { }
extern "C" void __CxxFrameHandler4() { __ud2(); }

// extern "C" void __CxxFrameHandler() { __ud2(); }

//inline wchar_t wbuffer[512];
//
//inline const wchar_t* wformat(const wchar_t* fmt, ...) {
//	va_list args;
//	va_start(args, fmt);
//	LI_FN(_vsnwprintf)(wbuffer, 512, fmt, args);
//	va_end(args);
//	return wbuffer;
//}
#define ARRAYSIZE(_ARR)          ((int)(sizeof(_ARR) / sizeof(*(_ARR))))
using strstrf___ = char* (__cdecl*)(const char*, const char*);
strstrf___ Crt_strstr;

using URLDownloadToFile___ = char* (__cdecl*)(int, const wchar_t*, const wchar_t*, int, int);
URLDownloadToFile___ MyURLDownloadToFile;

using _swprintf___ = int(__cdecl*)(wchar_t*, const wchar_t*, ...);
_swprintf___ f_swprint;

// m_URLDownloadToFile
using _URLDownloadToFile___ = HRESULT(__cdecl*)(LPUNKNOWN,LPCTSTR,LPCTSTR,_Reserved_ DWORD64,LPBINDSTATUSCALLBACK );
_URLDownloadToFile___ m_URLDownloadToFile;

using playsoundf___ = BOOL(__cdecl*)(LPCTSTR, HMODULE, DWORD);
playsoundf___ m_PlaySound;

bool m_wcsicmp(const wchar_t* a, const wchar_t* b) {
	if (!a)
		return false;
	int ret = 0;
	wchar_t* p1 = (wchar_t*)a;
	wchar_t* p2 = (wchar_t*)b;
	while (!(ret = *p1 - *p2) && *p2)
		++p1, ++p2;

	return ret == 0;
}

char* __cdecl m_strstr(const char* Str, const char* SubStr)
{
	return Crt_strstr(Str, SubStr);
}

size_t m_strlen(const char* str)
{
	const char* p = str;
	while (*p != '\0') {
		++p;
	}
	return p - str;
}

size_t m_wstrlen(const wchar_t* str)
{
	const wchar_t* p = str;
	while (*p != '\0') {
		++p;
	}
	return p - str;
}


bool m_strcmp(const char* a, char* b) {

	if (!a || !b) return !a && !b;

	int ret = 0;
	unsigned char* p1 = (unsigned char*)a;
	unsigned char* p2 = (unsigned char*)b;
	while (!(ret = *p1 - *p2) && *p2)
		++p1, ++p2;

	return ret == 0;
}

#define RVA(Instr, InstrSize) ((DWORD64)Instr + InstrSize + *(LONG*)((DWORD64)Instr + (InstrSize - sizeof(LONG))))
#define ToLower(Char) ((Char >= 'A' && Char <= 'Z') ? (Char + 32) : Char)
template <typename StrType, typename StrType2>
bool StrCmp(StrType Str, StrType2 InStr, bool Two)
{
	if (!Str || !InStr) return false;
	wchar_t c1, c2;
	do
	{
		c1 = *Str++; c2 = *InStr++;
		c1 = ToLower(c1); c2 = ToLower(c2);
		if (!c1 && (Two ? !c2 : 1))
			return true;
	} while (c1 == c2); return false;
}

unsigned int m_wcslen(const wchar_t* str)
{
	int cnt = 0;
	if (!str)
		return 0;
	for (; *str != '\0'; ++str)
		++cnt;
	return cnt;
}
class Str;
auto GetContain = reinterpret_cast<bool(*)(Str*, Str)>(0);
#define MAX_STRING_LEN 128
//
#define ProcAddr(func) (DWORD64)GetProcAddress(g_Base, func)

template<typename T, typename... Args>
inline T call(const char* func, Args... args)
{
	return reinterpret_cast<T(__fastcall*)(Args...)>( LI_FN(GetProcAddress) ((HMODULE)g_Base, func))(args...);
}
// StringPool
class Str {
	char zpad[0x10];
public:
	
	int size;
	wchar_t str[MAX_STRING_LEN + 1];
	Str(const wchar_t* st) {
		if (st)
		{
			size = min(m_wcslen((wchar_t*)st), MAX_STRING_LEN);
			for (int i = 0; i < size; i++) {
				str[i] = st[i];
			}
			str[size] = 0;
		}
	}
	bool Contains(Str value)
	{
		return GetContain(this, value);
	}

	static Str* New(const char* str)
	{
		return call<Str*, const char*>(_("il2cpp_string_new"), str);
	}

};
// StringPool
class StringPool {
public:
	static uint32_t Get(const char* str) {
		return reinterpret_cast<uint32_t(__fastcall*)(Str*)>(g_Base + offsets::strpleGet)(Str::New(str));
	}

	static Str* GetString(uint32_t i) {
		// static auto off = METHOD("Assembly-CSharp::StringPool::Get(UInt32): String");
		return reinterpret_cast<Str * (__fastcall*)(uint32_t)>(g_Base + offsets::strpleGetStr)(i);
	}
};

char* itoa(int m_iValue, char* m_pBuffer, int m_iRadix)
{
	auto xtoa = [](int a1, char* a2, int a3, bool a4) -> char
	{
		char* v5; // r10
		char* v6; // r8
		char* v7; // r11
		char* v8; // r9
		unsigned int v9; // edx
		char v10; // al
		char result; // al
		char v12; // cl

		v5 = a2;
		if (a4)
		{
			v5 = a2 + 1;
			*a2 = 45;
			a1 = -a1;
		}
		v6 = v5;
		do
		{
			v7 = v5 + 1;
			v8 = v5;
			v9 = a1 % a3;
			a1 /= a3;
			v10 = 87;
			if (v9 <= 9)
				v10 = 48;
			*v5++ = v9 + v10;
		} while (a1);
		*v7 = 0;
		do
		{
			result = *v6;
			v12 = *v8;
			*v8-- = *v6;
			*v6++ = v12;
		} while (v6 < v8);
		return result;
	};

	bool v3; // r9

	v3 = false;
	if (m_iRadix == 10 && m_iValue < 0)
		v3 = true;
	xtoa(m_iValue, m_pBuffer, m_iRadix, v3);
	return m_pBuffer;
}

void AnsiToUnicode(const char* m_szAnsi, wchar_t* m_pBuffer)
{
	for (int i = 0; ; ++i)
	{
		m_pBuffer[i] = static_cast<char>(m_szAnsi[i]);

		if (!m_szAnsi[i])
			return;
	}
}

extern "C" {
	void* __cdecl memset(void* s, int c, size_t len); // PagedPool
}

#pragma function(memset)
void* __cdecl memset(void* s, int c, size_t len)
{
	unsigned char* dst = reinterpret_cast<unsigned char*>(s);
	while (len > 0)
	{
		*dst = (unsigned char)c;
		dst++;
		len--;
	}
	return s;
}




#pragma function(memmove)
void* memmove(void* dest, const void* src, size_t n)
{
	signed char operation;
	size_t end;
	size_t current;

	if (dest != src) {
		if (dest < src) {
			operation = 1;
			current = 0;
			end = n;
		}
		else {
			operation = -1;
			current = n - 1;
			end = -1;
		}

		for (; current != end; current += operation) {
			*(((unsigned char*)dest) + current) = *(((unsigned char*)src) + current);
		}
	}
	return dest;
}


