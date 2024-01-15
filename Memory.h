#pragma once

template<typename T = uintptr_t, typename A>
T& Read(A address) {
	auto addresss = (DWORD64)address;
	if (addresss > 0x40000 && (addresss + sizeof(T)) < 0x7FFFFFFF0000)
		return *(T*)addresss;

	auto n = nullptr;
	return reinterpret_cast<T&>(n);
}
template <typename T>
void Write(uintptr_t address, T data) {
	if (address > 0x40000 && (address + sizeof(T)) < 0x7FFFFFFF0000)
		*(T*)(address) = data;
}

bool IsValidCheck(void* m_pPointer)
{
	if (reinterpret_cast<DWORD64>(m_pPointer) <= 0x400000 || reinterpret_cast<DWORD64>(m_pPointer) >= 0x7fffffffffff)
		return false;

	return true;
}

bool IsValidPointer(DWORD64 m_pPointer)
{
	return IsValidCheck(reinterpret_cast<void*>(m_pPointer));
}


#define safe_memcpy(Dst, Src, Size) safe_memcpy_wrapper(((ULONG64)Dst), ((ULONG64)Src), Size)
void safe_memcpy_wrapper(ULONG64 Dst, ULONG64 Src, ULONG Sz)
{
	if ((((ULONG64)Dst) > 0x400000) && (((ULONG64)Dst + Sz) < 0x00007FFFFFFF0000))
	{
		while (true)
		{
			if (Sz >= 8) { *(ULONG64*)Dst = *(ULONG64*)Src; Dst += 8; Src += 8; Sz -= 8; }
			else if (Sz >= 4) { *(ULONG*)Dst = *(ULONG*)Src; Dst += 4; Src += 4; Sz -= 4; }
			else if (Sz >= 2) { *(WORD*)Dst = *(WORD*)Src; Dst += 2; Src += 2; Sz -= 2; }
			else if (Sz) { *(BYTE*)Dst = *(BYTE*)Src; break; }
			else break;
		}
	}
}

#define safe_read(Addr, Type) (((((ULONG64)Addr) > 0x400000) && (((ULONG64)Addr + sizeof(Type)) < 0x00007FFFFFFF0000)) ? *(Type*)((ULONG64)Addr) : Type{})
#define safe_write(Addr, Data, Type) if ((((ULONG64)Addr) > 0x400000) && (((ULONG64)Addr + sizeof(Type)) < 0x00007FFFFFFF0000)) { *(Type*)((ULONG64)Addr) = (Data); }