/*
	@file		Protocol.Display.h
	@brief		디스플레이 제어
 */


#ifndef PROTOCOL_DISPLAY_H_
#define PROTOCOL_DISPLAY_H_


#include "Light.Definition.h"


	namespace Protocol
	{
		namespace Display
		{	
			/*
				DataType.DisplayClear
			 */
			#pragma pack(1)
			class ClearAll
			{
			public:
				u8 			pixel;
			};
			#pragma pack()
			
			
			/*
				DataType.DisplayClear
			 */
			#pragma pack(1)
			class Clear
			{
			public:
				s16 		x;
				s16 		y;
				s16			width;
				s16			height;
				u8			pixel;
			};
			#pragma pack()
			
			
			/*
				DataType.DisplayInvert
			 */
			#pragma pack(1)
			class Invert
			{
			public:
				s16 		x;
				s16 		y;
				s16			width;
				s16			height;
			};
			#pragma pack()
			
			
			/*
				DataType.DisplayDrawPoint
			 */
			#pragma pack(1)
			class DrawPoint
			{
			public:
				s16 		x;
				s16 		y;
				u8			pixel;
			};
			#pragma pack()
			
			
			/*
				DataType.DisplayDrawLine
			 */
			#pragma pack(1)
			class DrawLine
			{
			public:
				s16 		x1;
				s16 		y1;
				s16 		x2;
				s16 		y2;
				u8			pixel;
				u8			line;
			};
			#pragma pack()
			
			
			/*
				DataType.DisplayDrawRect
			 */
			#pragma pack(1)
			class DrawRect
			{
			public:
				s16 		x;
				s16 		y;
				s16			width;
				s16			height;
				u8			pixel;
				u8			flagFill;
				u8			line;
			};
			#pragma pack()
			
			
			/*
				DataType.DisplayDrawCircle
			 */
			#pragma pack(1)
			class DrawCircle
			{
			public:
				s16 		x;
				s16 		y;
				s16			radius;
				u8			pixel;
				u8			flagFill;
			};
			#pragma pack()
			
			
			/*
				DataType.DisplayDrawString
			 */
			#pragma pack(1)
			class DrawString
			{
			public:
				s16 		x;
				s16 		y;
				u8			font;
				u8			pixel;
			};
			#pragma pack()
			
			
			/*
				DataType.DisplayDrawStringAlign
			 */
			#pragma pack(1)
			class DrawStringAlign
			{
			public:
				s16 		xStart;
				s16 		xEnd;
				s16 		y;
				u8			align;
				u8			font;
				u8			pixel;
			};
			#pragma pack()
			
			
			/*
				DataType.DrawImage
			 */
			#pragma pack(1)
			class DrawImage
			{
			public:
				s16 		x;
				s16 		y;
				s16 		width;
				s16 		height;
			};
			#pragma pack()
		}
	}		


#endif