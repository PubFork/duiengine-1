#include "duistd.h"
#include "Accelerator.h"

namespace DuiEngine
{

	CAccelerator::CAccelerator(UINT vKey,bool bCtrl,bool bAlt,bool bShift):m_wVK(vKey),m_wModifier(0)
	{
		if(bCtrl) m_wModifier|=HOTKEYF_CONTROL;
		if(bAlt) m_wModifier |=HOTKEYF_ALT;
		if(bShift) m_wModifier |= HOTKEYF_SHIFT;
	}

	CAccelerator::~CAccelerator(void)
	{
	}

	CDuiStringT CAccelerator::FormatHotkey()
	{
		if(m_wModifier==0 && m_wVK==0) return _T("无");
		CDuiStringT str;
		if(m_wModifier == HOTKEYF_ALT) str=_T("Alt+");
		if(m_wModifier == HOTKEYF_CONTROL) str=_T("Ctrl+");
		if(m_wModifier == HOTKEYF_SHIFT) str=_T("Shift+");
		if(m_wModifier == (HOTKEYF_ALT|HOTKEYF_SHIFT)) str=_T("Shift+Alt+");
		if(m_wModifier == (HOTKEYF_ALT|HOTKEYF_CONTROL)) str=_T("Ctrl+Alt+");
		if(m_wModifier == (HOTKEYF_CONTROL|HOTKEYF_SHIFT)) str=_T("Ctrl+Shift+");
		if(m_wModifier == (HOTKEYF_ALT|HOTKEYF_CONTROL|HOTKEYF_SHIFT)) str=_T("Ctrl+Shift+Alt+");
		str+=GetKeyName(m_wVK);
		return str;
	}

	CDuiStringT CAccelerator::GetKeyName( WORD vk )
	{
		CDuiStringT str;
		switch(vk)
		{
		case VK_ESCAPE:
			str=_T("ESC");
			break;
		case VK_RETURN:
			str=_T("Enter");
			break;
		case VK_UP:
			str=_T("Up");
			break;
		case VK_DOWN:
			str=_T("Down");
			break;
		case VK_LEFT:
			str=_T("Left");
			break;
		case VK_RIGHT:
			str=_T("Right");
			break;
		case VK_HOME:
			str=_T("Home");
			break;
		case VK_END:
			str=_T("End");
			break;
		case VK_PRIOR:
			str=_T("PageUp");
			break;
		case VK_NEXT:
			str=_T("PageDown");
			break;
		case VK_INSERT:
			str=_T("Insert");
			break;
		default:
			if((vk>='0' && m_wVK<='9')||(vk>='A' && vk<='Z'))
				str=(TCHAR)vk;
			else if(vk>=VK_F1 && vk<=VK_F9)
				str=CDuiStringT(_T('F'))+TCHAR(m_wVK-VK_F1+'1');
			else if(vk==VK_F10)
				str+=_T("F10");
			else if(vk==VK_F11)
				str+=_T("F11");
			else if(vk==VK_F12)
				str+=_T("F12");
			else
			{
				char c=MapVirtualKeyA(vk,2);
				switch(c)
				{
				case '-':
				case '=':
				case '[':
				case ']':
				case '\\':
				case ';':
				case '\'':
				case ',':
				case '.':
				case '/':
				case '`':
					str+=TCHAR(c);
					break;
				}
			}
			break;
		}
		return str;
	}
}//end of namespace DuiEngine
