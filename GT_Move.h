#include "Gt400.h"

void GT_error(short rtn);
void GTInitial();
void InputCfg();
void AxisInitialSG();
void AxisInitialSV();
void SMotion();
void TMotion();
void VMotion();
void GMotion();
void delay(unsigned int xms);
void MapAxis();
void DrawTrack(char filename[100],double TrPt_x,double TrPt_y);
void Home (long pos);