#pragma once

#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define OFFSET(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}

//struct RaidEsp {
//	const wchar_t* name;
//	Vector3 Pos;
//	RaidEsp(const wchar_t* n, Vector3 p) {
//		name = n;
//		Pos = p;
//	}
//}	inline RaidInfo;

struct
{
	const wchar_t* Name;
	Vector3 Pos;
	Color Col;
} inline RaidInfo;

inline float GetGravity(const int ammoid)
{
	switch (ammoid)
	{
	case 14241751: //fire arrow
		return 1.f;
	case -1234735557: //arrow normal
		return 0.75f;
	case 215754713: //arrow bone
		return 0.75f;
	case -1023065463: //hv arrow
		return 0.5f;
	case -2097376851: //nails
		return 0.75f;
	case -1321651331: //5.56 exp
		return 1.25f;
	default:
		return 1.f;
	}
}
Vector3 ManipulationAngle = Vector3::Zero();

Vector3 MeleeEyePos = Vector3::Zero();
class Attack {
public:

	union {
		OFFSET(Vector3, pointStart, 0x10);
		OFFSET(Vector3, pointEnd, 0x1C);
		OFFSET(unsigned int, hitID, 0x28);
		OFFSET(unsigned int, hitBone, 0x30);
		OFFSET(Vector3, hitNormalLocal, 0x34);
		OFFSET(Vector3, hitPositionLocal, 0x40);
		OFFSET(Vector3, hitNormalWorld, 0x4c);
		OFFSET(Vector3, hitPositionWorld, 0x58);
		OFFSET(unsigned int, hitPartID, 0x64);
		OFFSET(unsigned int, hitMaterialID, 0x64);
		OFFSET(unsigned int, hitItem, 0x68); //public bool ShouldPool; // 0x6C
		OFFSET(bool, ShouldPool, 0x6C);
	};
};

class PlayerAttack {
public:
	union {
		OFFSET(Attack*, attack, 0x10);
	};
};

class PlayerProjectileAttack {
public:
	union {
		OFFSET(PlayerAttack*, playerAttack, 0x10);
		OFFSET(Vector3, hitVelocity, 0x18);
		OFFSET(float, hitDistance, 0x24);
		OFFSET(float, travelTime, 0x28);

	};
};

class PlayerProjectileUpdate {
public:
	union {
		OFFSET(int, projectileID, 0x10);
		OFFSET(Vector3, curPosition, 0x14);
		OFFSET(Vector3, curVelocity, 0x20);
		OFFSET(float, travelTime, 0x2C);
	};
};



Str get_keystr(int key) {
	switch (key)
	{
	case 0:
		return _(L"");
	case 8:
		return _(L"Backspace");
	case 127:
		return _(L"Delete");
	case 9:
		return _(L"Tab");
	case 12:
		return _(L"Clear");
	case 13:
		return _(L"Return");
	case 19:
		return _(L"Pause");
	case 27:
		return _(L"");
	case 32:
		return _(L"Space");
	case 256:
		return _(L"0");
	case 257:
		return _(L"1");
	case 258:
		return _(L"2");
	case 259:
		return _(L"3");
	case 260:
		return _(L"4");
	case 261:
		return _(L"5");
	case 262:
		return _(L"6");
	case 263:
		return _(L"7");
	case 264:
		return _(L"8");
	case 265:
		return _(L"9");
	case 266:
		return _(L".");
	case 267:
		return _(L"/");
	case 268:
		return _(L"*");
	case 269:
		return _(L"+");
	case 270:
		return _(L"-");
	case 271:
		return _(L"Enter");
	case 272:
		return _(L"Equals");
	case 273:
		return _(L"Up");
	case 274:
		return _(L"Down");
	case 275:
		return _(L"Right");
	case 276:
		return _(L"Left");
	case 277:
		return _(L"Ins");
	case 278:
		return _(L"Home");
	case 279:
		return _(L"End");
	case 280:
		return _(L"PUp");
	case 281:
		return _(L"PDown");
	case 282:
		return _(L"F1");
	case 283:
		return _(L"F2");
	case 284:
		return _(L"F3");
	case 285:
		return _(L"F4");
	case 286:
		return _(L"F5");
	case 287:
		return _(L"F6");
	case 288:
		return _(L"F7");
	case 289:
		return _(L"F8");
	case 290:
		return _(L"F9");
	case 291:
		return _(L"F10");
	case 292:
		return _(L"F11");
	case 293:
		return _(L"F12");
	case 294:
		return _(L"F13");
	case 295:
		return _(L"F14");
	case 296:
		return _(L"F15");
	case 48:
		return _(L"0");
	case 49:
		return _(L"1");
	case 50:
		return _(L"2");
	case 51:
		return _(L"3");
	case 52:
		return _(L"4");
	case 53:
		return _(L"5");
	case 54:
		return _(L"6");
	case 55:
		return _(L"7");
	case 56:
		return _(L"8");
	case 57:
		return _(L"9");
	case 33:
		return _(L"!");
	case 34:
		return _(L"\"");
	case 35:
		return _(L"#");
	case 36:
		return _(L"$");
	case 37:
		return _(L"%");
	case 38:
		return _(L"&");
	case 39:
		return _(L"'");
	case 40:
		return _(L"(");
	case 41:
		return _(L")");
	case 42:
		return _(L"*");
	case 43:
		return _(L"+");
	case 44:
		return _(L",");
	case 45:
		return _(L"-");
	case 46:
		return _(L".");
	case 47:
		return _(L"/");
	case 58:
		return _(L":");
	case 59:
		return _(L";");
	case 60:
		return _(L"<");
	case 61:
		return _(L"=");
	case 62:
		return _(L">");
	case 63:
		return _(L"?");
	case 64:
		return _(L"@");
	case 91:
		return _(L"[");
	case 92:
		return _(L"\\");
	case 93:
		return _(L"]");
	case 94:
		return _(L"^");
	case 95:
		return _(L"_");
	case 96:
		return _(L"`");
	case 97:
		return _(L"A");
	case 98:
		return _(L"B");
	case 99:
		return _(L"C");
	case 100:
		return _(L"D");
	case 101:
		return _(L"E");
	case 102:
		return _(L"F");
	case 103:
		return _(L"G");
	case 104:
		return _(L"H");
	case 105:
		return _(L"I");
	case 106:
		return _(L"J");
	case 107:
		return _(L"K");
	case 108:
		return _(L"L");
	case 109:
		return _(L"M");
	case 110:
		return _(L"N");
	case 111:
		return _(L"O");
	case 112:
		return _(L"P");
	case 113:
		return _(L"Q");
	case 114:
		return _(L"R");
	case 115:
		return _(L"S");
	case 116:
		return _(L"T");
	case 117:
		return _(L"U");
	case 118:
		return _(L"V");
	case 119:
		return _(L"W");
	case 120:
		return _(L"X");
	case 121:
		return _(L"Y");
	case 122:
		return _(L"Z");
	case 123:
		return _(L"{");
	case 124:
		return _(L"|");
	case 125:
		return _(L"}");
	case 126:
		return _(L"~");
	case 300:
		return _(L"Numlk");
	case 301:
		return _(L"Caps");
	case 302:
		return _(L"Scrl");
	case 303:
		return _(L"RShift");
	case 304:
		return _(L"LShift");
	case 305:
		return _(L"RCtrl");
	case 306:
		return _(L"CLtrl");
	case 307:
		return _(L"RAlt");
	case 308:
		return _(L"LAlt");
	case 310:
		return _(L"LCmd");
	case 311:
		return _(L"LWin");
	case 309:
		return _(L"RCmd");
	case 312:
		return _(L"Rwin");
	case 313:
		return _(L"Altgr");
	case 315:
		return _(L"Help");
	case 316:
		return _(L"Pr");
	case 317:
		return _(L"Sysreq");
	case 318:
		return _(L"Break");
	case 319:
		return _(L"Menu");
	case 323:
		return _(L"Mouse 0");
	case 324:
		return _(L"Mouse 1");
	case 325:
		return _(L"Mouse 2");
	case 326:
		return _(L"Mouse 3");
	case 327:
		return _(L"Mouse 4");
	case 328:
		return _(L"Mouse 5");
	case 329:
		return _(L"Mouse 6");
	}
	return _(L"Undefined");
}

//AimTarget FindTarget(Vector3 from, DWORD64 ply, float Distance)
//{
//	DWORD64 ClientEntities = 0;
//
//	if (ClientEntities == 0) {
//		ClientEntities = Il2cpp::GetValue(_("BaseNetworkable"), _("clientEntities"), false);
//		if (ClientEntities) return {};
//	}
//
//
//
//	AimTarget Target;
//	BasePlayer* TargetPlayer = reinterpret_cast<BasePlayer*>(ply);
//	if (!TargetPlayer == NULL && TargetPlayer->IsValid())
//	{
//		//AimTarget Target;
//		Target.Player = TargetPlayer;
//		
//
//		Target.Pos = Target.Player->GetPosition(Vars::Aim::AimBone);
//		
//
//		Target.Visible = Unity::CheckLOS(from, Target.Pos);
//
//		//SearchTarget = Target;
//
//		
//	}
//
//	return Target;
//}

