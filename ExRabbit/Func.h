#pragma once
#include "stdafx.h"
#include "../KoishiEx/koishiex.h"
#include "../KoishiEx/DDS.h"
#include "../KoishiEx/avatar.h"
//////////////////////////////////////////////////////
//֧��
//////////////////////////////////////////////////////
using namespace Koishi;
void CStrToStr(CString cstr,str &str1);
CString StrToCStr(str str1);
CString NumToCStr(int n);
CString shorten(CString str1);
CString to_(CString str1);
CString toSl(CString str1);
CString PtToCStr(point pt);
CString SzToCStr(size pt);
CString ClrToCStr(color clr);
CString FmtToCStr(colorFormat cf, IMGversion iv);
CString getCurDir();
CString getOutPutDir();
CString getOutPutDir(CString npkName);
CString getOutPutDir(CString npkName, CString imgName);
CString getOutPutDir(CString npkName, CString imgName, int clPro);