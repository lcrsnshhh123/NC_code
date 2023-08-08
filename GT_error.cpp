#include "GT_Move.h"

#include "stdafx.h"
#include "InterpolationDemo.h"
#include "InterpolationDemoDlg.h"
#include "afxdialogex.h"

using namespace std;

void GT_error(short rtn)
{
 switch(rtn)
 {
 case -1:
	 AfxMessageBox(_T("error:communciation error!"),MB_OKCANCEL); break;
 case 0:
	 //no error,continue
	 break;
 case 1:
	 AfxMessageBox(_T("error:command error!"),MB_OKCANCEL); break;
 case 2:
	 AfxMessageBox(_T("error:Radius or chord is 0!"),MB_OKCANCEL); break;
 case 3:
	 AfxMessageBox(_T("error:Length is 0 or overflow!"),MB_OKCANCEL); break;
 case 4:
	 AfxMessageBox(_T("error:Velocity or acceleration is less then 0!"),MB_OKCANCEL); break;
 case 5:
	 AfxMessageBox(_T("error:Chord is greater than diameter!"),MB_OKCANCEL); break;
 case 7:
	 AfxMessageBox(_T("error:parameter error!"),MB_OKCANCEL); break;
 case 6:
	 AfxMessageBox(_T("error:map is error!"),MB_OKCANCEL); break;
 default:
	 break;
 }
}