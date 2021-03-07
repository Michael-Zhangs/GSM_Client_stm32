#ifndef __UI_H
#define __UI_H

#include "bsp_12864.h"
#include "bsp_GSM.h"
#include "bsp_keyboard.h"
#include "bsp_printer.h"

void UI_hander(void);
void UI_PrintMenu(void);
void UI_SendMsg_hander(void);
void UI_ReceiveMsg_hander(void);
void UI_Net_hander(void);
void UI_SelfCheck_hander(void);

#endif
