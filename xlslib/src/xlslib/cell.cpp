/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * This file is part of xlslib -- A multiplatform, C/C++ library
 * for dynamic generation of Excel(TM) files.
 *
 * xlslib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * xlslib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with xlslib.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright 2004 Yeico S. A. de C. V.
 * Copyright 2008 David Hoerl
 *  
 * $Source: /cvsroot/xlslib/xlslib/src/xlslib/cell.cpp,v $
 * $Revision: 1.9 $
 * $Author: dhoerl $
 * $Date: 2009/03/02 04:08:43 $
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * File description:
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <xlsys.h>

#include <cell.h>

#include <format.h>
#include <globalrec.h>

using namespace std;
using namespace xlslib_core;

cell_t::cell_t(CGlobalRecords& gRecord, unsigned32_t rowNum, unsigned32_t colNum) :
   m_GlobalRecords(gRecord),
   row(rowNum), col(colNum),
   pxf(gRecord.GetDefaultXF())
{
	assert(pxf);
	pxf->MarkUsed();

	//cerr << "INITIAL XFT" << endl << pxf->Description() << endl;
}
cell_t::~cell_t()
{
	pxf->UnMarkUsed();
}

unsigned16_t cell_t::GetXFIndex() const
{
	assert(pxf);
   //return pxf ? pxf->GetIndex() : XF_PROP_XF_DEFAULT_CELL;
   return pxf->GetIndex();
}

unsigned32_t cell_t::GetRow(void) const {return row;}
unsigned32_t cell_t::GetCol(void) const {return col;}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// Implementation of the XF record interface (xf_i pure virtual interface)
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

// This is why the default formats get marked used twice! (see test for > 1)

#if 0
#define SET_XF_COMMON_OLD											\
	xf_t* currentxf = pxf;											\
																	\
	if(pxf == NULL) {												\
		pxf = new xf_t(m_GlobalRecords, true);						\
		pxf->MarkUsed();											\
	} else															\
	if(pxf->Usage() > 1) {				/* not sole user	*/		\
		pxf->UnMarkUsed();											\
		pxf = xf_t::xfDup(currentxf);								\
		pxf->MarkUsed();											\
	}
#endif

#define SET_XF_COMMON												\
	if(pxf->Usage() > 1) {				/* not sole user	*/		\
		pxf->UnMarkUsed();											\
		pxf = xf_t::xfDup(pxf);										\
		pxf->MarkUsed();											\
	}

#define SET_XF_CELL_FUNCTION(function, value)						\
{																	\
	SET_XF_COMMON													\
																	\
	pxf->function(value);											\
}
#define SET_XF_CELL_FUNCTION2(function,val1,val2)					\
{																	\
	SET_XF_COMMON													\
																	\
	pxf->function(val1,val2);									\
}
#define SET_XF_CELL_FUNCTION3(function,val1,val2,val3)				\
{																	\
	SET_XF_COMMON													\
																	\
	pxf->function(val1,val2,val3);									\
}

void cell_t::borderstyle(border_side_t side, border_style_t style)
{
   SET_XF_CELL_FUNCTION2(SetBorderStyle, side, style);
}
void cell_t::bordercolor(border_side_t side, color_name_t color)
{
   SET_XF_CELL_FUNCTION2(SetBorderColor, side, color);
}
void cell_t::bordercolor(border_side_t side, unsigned8_t color)
{
   SET_XF_CELL_FUNCTION2(SetBorderColor, side, color);
}

void cell_t::font(font_t* fnt)
{
   SET_XF_CELL_FUNCTION(SetFont, fnt);
}
void cell_t::format(format_number_t formatidx)
{
   SET_XF_CELL_FUNCTION(SetFormat, formatidx);
}
void cell_t::format(format_t* fmt)
{
   SET_XF_CELL_FUNCTION(SetFormat, fmt);
}
void cell_t::halign(halign_option_t ha_option)
{
   SET_XF_CELL_FUNCTION(SetHAlign,ha_option);
}

void cell_t::valign(valign_option_t va_option)
{
   SET_XF_CELL_FUNCTION(SetVAlign,va_option);
}

void cell_t::indent(indent_option_t indent_option)
{
   SET_XF_CELL_FUNCTION(SetIndent,indent_option);
}

void cell_t::orientation(txtori_option_t ori_option)
{
   SET_XF_CELL_FUNCTION(SetTxtOrientation,ori_option);
}

void cell_t::fillfgcolor(color_name_t color)
{
   SET_XF_CELL_FUNCTION(SetFillFGColor,color);
}

void cell_t::fillfgcolor(unsigned8_t color)
{
   SET_XF_CELL_FUNCTION(SetFillFGColor,color);
}

void cell_t::fillbgcolor(color_name_t color)
{
   SET_XF_CELL_FUNCTION(SetFillBGColor,color);
}

void cell_t::fillbgcolor(unsigned8_t color)
{
   SET_XF_CELL_FUNCTION(SetFillBGColor,color);
}

void cell_t::fillstyle(fill_option_t fill)
{
   SET_XF_CELL_FUNCTION(SetFillStyle,fill);
}

void cell_t::locked(bool locked_opt)
{
   SET_XF_CELL_FUNCTION(SetLocked,locked_opt);
}

void cell_t::hidden(bool hidden_opt)
{
   SET_XF_CELL_FUNCTION(SetHidden,hidden_opt);
}

void cell_t::wrap(bool wrap_opt)
{
   SET_XF_CELL_FUNCTION(SetWrap,wrap_opt);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// Implementation of the FONT record interface (font_i pure virtual interface)
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#define SET_CELL_FONT_FUNCTION(function, value)						\
{																	\
	SET_XF_COMMON													\
																	\
	font_t* currentfont = pxf->GetFont();							\
																	\
	if(currentfont == NULL)	{										\
		currentfont = m_GlobalRecords.GetDefaultFont();				\
		font_t* fntnew = font_t::fontDup(currentfont);				\
		pxf->SetFont(fntnew);										\
	} else															\
	if(currentfont->Usage() > 1)									\
	{																\
		font_t* fntnew = font_t::fontDup(currentfont);				\
		pxf->SetFont(fntnew);										\
	}																\
	pxf->GetFont()->function(value);								\
}

void cell_t::fontname(string fntname)
{
   SET_CELL_FONT_FUNCTION(SetName, fntname);
}

void cell_t::fontheight(unsigned16_t fntheight)
{
   SET_CELL_FONT_FUNCTION(SetHeight,fntheight);
}

void cell_t::fontbold(boldness_option_t fntboldness)
{
   SET_CELL_FONT_FUNCTION(SetBoldStyle,fntboldness);
}

void cell_t::fontunderline(underline_option_t fntunderline)
{
   SET_CELL_FONT_FUNCTION(SetUnderlineStyle,fntunderline);
}

void cell_t::fontscript(script_option_t fntscript)
{
   SET_CELL_FONT_FUNCTION(SetScriptStyle,fntscript);
}

void cell_t::fontcolor(color_name_t fntcolor)
{
   SET_CELL_FONT_FUNCTION(SetColor,fntcolor);
}
void cell_t::fontcolor(unsigned8_t fntcolor)
{
   SET_CELL_FONT_FUNCTION(SetColor,fntcolor);
}

#if 0
void cell_t::fontattr(unsigned16_t attr)
{
   SET_CELL_FONT_FUNCTION(SetAttributes,attr);
}
#endif
void cell_t::fontitalic(bool italic)
{
   SET_CELL_FONT_FUNCTION(SetItalic,italic);
}

void cell_t::fontstrikeout(bool so)
{
   SET_CELL_FONT_FUNCTION(SetStrikeout,so);
}

void cell_t::fontoutline(bool ol)
{
   SET_CELL_FONT_FUNCTION(SetOutline,ol);
}

void cell_t::fontshadow(bool sh)
{
   SET_CELL_FONT_FUNCTION(SetShadow,sh);
}

void cell_t::SetXF(xf_t* pxfval)
{
	if(!pxfval) return;
	
	assert(pxf);
	pxfval->MarkUsed();
	pxf->UnMarkUsed();
	pxf = pxfval;
}
xf_t* cell_t::GetXF(void) const {return pxf;}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * $Log: cell.cpp,v $
 * Revision 1.9  2009/03/02 04:08:43  dhoerl
 * Code is now compliant to gcc  -Weffc++
 *
 * Revision 1.8  2009/01/23 16:09:55  dhoerl
 * General cleanup: headers and includes. Fixed issues building mainC and mainCPP
 *
 * Revision 1.7  2009/01/10 21:10:50  dhoerl
 * More tweaks
 *
 * Revision 1.6  2009/01/09 15:04:26  dhoerl
 * GlobalRec now used only as a reference.
 *
 * Revision 1.5  2009/01/09 03:23:12  dhoerl
 * GlobalRec references tuning
 *
 * Revision 1.4  2009/01/08 02:53:15  dhoerl
 * December Rework
 *
 * Revision 1.3  2008/12/11 21:12:49  dhoerl
 * Cleanup
 *
 * Revision 1.2  2008/10/25 18:39:53  dhoerl
 * 2008
 *
 * Revision 1.1.1.1  2004/08/27 16:31:54  darioglz
 * Initial Import.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

