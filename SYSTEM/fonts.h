#ifndef __FONTS_H
#define __FONTS_H

//unsigned int uni2gb(unsigned int uni);

#define MAX_UNI_INDEX	6768

typedef unsigned short	uint16;
typedef unsigned char	uchar;

uint16 BinarySearch(const uint16 x);
void UniToStr(const uint16 *uni,uchar *str);

#endif
