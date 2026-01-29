/*
	@file		Base.h
	@brief		공통 include 파일
 */


#ifndef BASE_CLASS_H_
#define BASE_CLASS_H_


	/*
		펌웨어 버젼
	 */
	// Struct에서 윗부분에 위치한 값이 실제 배열에서 뒷 부분에 위치함
	union Version
	{
		u32			v;			// 
		
		struct
		{
			u16		build;  	// Build Number(0~65535)
			u8		minor;  	// Minor Number		: the minor number is incremented when only minor features or significant fixes have been added
			u8		major;		// Major Number		: the major number is increased when there are significant jumps in functionality such as changing the framework which could cause incompatibility with interfacing systems
		};
	};


	class Color
	{
	public:
		u8		r;
		u8		g;
		u8		b;
		
	public:
		static Color	fromRgb(u8 r, u8 g, u8 b) {	Color c; c.r = r; c.g = g; c.b = b; return c;	}
		void			clear() { r = 0; g = 0; b = 0; }
	};
	
	
	union ColorHSV
	{
	public:
		struct
		{
			float	hue;
			float	saturation;
			float	value;
		};
		
		struct
		{
			float	h;
			float	s;
			float	v;
		};
	};
	
	
	union ColorHSVL
	{
	public:
		struct
		{
			float	hue;
			float	saturation;
			float	value;
			float	lightness;
		};
		
		struct
		{
			float	h;
			float	s;
			float	v;
			float	l;
		};
	};
	
	
	union ColorHSL
	{
	public:
		struct
		{
			float	hue;
			float	saturation;
			float	lightness;
		};
		
		struct
		{
			float	h;
			float	s;
			float	l;
		};
	};


	// Point
	class Point8
	{
	public:
		s8		x;		// 수평
		s8		y;		// 수직
		
	public:
		void 	init() { x = 0; y = 0; }
	};


	class Point16
	{
	public:
		s16		x;		// 수평
		s16		y;		// 수직
		
	public:
		void 	init() { x = 0; y = 0; }
	};


	class Point32
	{
	public:
		s32		x;		// 수평
		s32		y;		// 수직
		
	public:
		void 	init() { x = 0; y = 0; }
	};


	class PointF
	{
	public:
		float	x;		// 수평
		float	y;		// 수직
		
	public:
		void 	init() { x = 0; y = 0; }
	};


	class PointD
	{
	public:
		double	x;		// 수평
		double	y;		// 수직
		
	public:
		void 	init() { x = 0; y = 0; }
	};
    
	

	// Vector
	class VectorB
	{
	public:
		union
		{
			struct
			{
				bool	x;			// X
				bool	y;			// Y
				bool	z;			// Z
			};
			
			struct
			{
				bool	roll;		// Roll
				bool	pitch;		// Pitch
				bool	yaw;		// Yaw
			};
			
			struct
			{
				bool	aileron;	// Aileron	- Roll
				bool	elevator;	// Elevator	- Pitch
				bool	rudder;		// Rudder	- Yaw
			};
			
			u8 array[6];
		};
			
		void		init() { roll = pitch = yaw = 0; };
	};    

	
	class Vector8
	{
	public:
		union
		{
			struct
			{
				s8		x;			// X
				s8		y;			// Y
				s8		z;			// Z
			};
			
			struct
			{
				s8		roll;		// Roll
				s8		pitch;		// Pitch
				s8		yaw;		// Yaw
			};
			
			struct
			{
				s8		aileron;	// Aileron	- Roll
				s8		elevator;	// Elevator	- Pitch
				s8		rudder;		// Rudder	- Yaw
			};
			
			u8 array[3];
		};
			
		void		init() { roll = pitch = yaw = 0; };
	};

	
	class Vector16
	{
	public:
		union
		{
			struct
			{
				s16		x;			// X
				s16		y;			// Y
				s16		z;			// Z
			};
			
			struct
			{
				s16		roll;		// Roll
				s16		pitch;		// Pitch
				s16		yaw;		// Yaw
			};
			
			struct
			{
				s16		aileron;	// Aileron	- Roll
				s16		elevator;	// Elevator	- Pitch
				s16		rudder;		// Rudder	- Yaw
			};
			
			u8 array[6];
		};
			
		void		init() { roll = pitch = yaw = 0; };
	};

	
	class Vector32
	{
	public:
		union
		{
			struct
			{
				s32		x;			// X
				s32		y;			// Y
				s32		z;			// Z
			};
			
			struct
			{
				s32		roll;		// Roll
				s32		pitch;		// Pitch
				s32		yaw;		// Yaw
			};
			
			struct
			{
				s32		aileron;	// Aileron	- Roll
				s32		elevator;	// Elevator	- Pitch
				s32		rudder;		// Rudder	- Yaw
			};
			
			u8 array[12];
		};
			
		void		init() { roll = pitch = yaw = 0; };
	};


	class VectorF
	{
	public:
		union
		{
			struct
			{
				float	x;		// X
				float	y;		// Y
				float	z;		// Z
			};
			
			struct
			{
				float	roll;		// Roll
				float	pitch;		// Pitch
				float	yaw;		// Yaw
			
			};
			
			struct
			{
				float	beta;		// Beta
				float	gamma;		// Gamma
				float	alpha;		// Alpha
			};
			
			struct
			{
				float	theta;		// Theta
				float	phi;		// Phi
				float	psi;		// Psi
			};
			
			struct
			{
				float	aileron;	// Aileron	- Roll
				float	elevator;	// Elevator	- Pitch
				float	rudder;		// Rudder	- Yaw
			};
		};
		
		void		init() { roll = pitch = yaw = 0; };
	};


	class VectorD
	{
	public:
		union
		{
			struct
			{
				double	x;		// X
				double	y;		// Y
				double	z;		// Z
			};
			
			struct
			{
				double	roll;		// Roll
				double	pitch;		// Pitch
				double	yaw;		// Yaw
			
			};
			
			struct
			{
				double	beta;		// Beta
				double	gamma;		// Gamma
				double	alpha;		// Alpha
			};
			
			struct
			{
				double	theta;		// Theta
				double	phi;		// Phi
				double	psi;		// Psi
			};
			
			struct
			{
				double	aileron;	// Aileron	- Roll
				double	elevator;	// Elevator	- Pitch
				double	rudder;		// Rudder	- Yaw
			};
		};
		
		void		init() { roll = pitch = yaw = 0; };
	};


	
	// Double
    class Double8
    {
    public:
        union
        {
            struct
            {
                s8		x;			// X
                s8		y;			// Y
            };
            
            struct
            {
                s8		yaw;		// yaw
                s8		throttle;	// throttle
            };
            
            struct
            {
                s8		wheel;		// wheel
                s8		accel;		// accel
            };
            
            u8 array[2];
        };
            
        void		init() { wheel = accel = 0; };
    };


    class Double16
    {
    public:
        union
        {
            struct
            {
                s16		x;			// X
                s16		y;			// Y
            };
            
            struct
            {
                s16		yaw;		// yaw
                s16		throttle;	// throttle
            };
            
            struct
            {
                s16		wheel;		// wheel
                s16		accel;		// accel
            };
            
            u8 array[4];
        };
            
        void		init() { wheel = accel = 0; };
    };


    class Double32
    {
    public:
        union
        {
            struct
            {
                s32		x;			// X
                s32		y;			// Y
            };
            
            struct
            {
                s32		yaw;		// yaw
                s32		throttle;	// throttle
            };
            
            struct
            {
                s32		wheel;		// wheel
                s32		accel;		// accel
            };
            
            u8 array[8];
        };
            
        void		init() { wheel = accel = 0; };
    };



    class DoubleF
    {
    public:
        union
        {
            struct
            {
                float		x;			// X
                float		y;			// Y
            };
            
            struct
            {
                float		yaw;		// yaw
                float		throttle;	// throttle
            };
            
            struct
            {
                float		wheel;		// wheel
                float		accel;		// accel
            };
        };
            
        void		init() { x = y = 0; };
    };

    
    class DoubleD
    {
    public:
        union
        {
            struct
            {
                double		x;			// X
                double		y;			// Y
            };
            
            struct
            {
                double		yaw;		// yaw
                double		throttle;	// throttle
            };
            
            struct
            {
                double		wheel;		// wheel
                double		accel;		// accel
            };
        };
            
        void		init() { x = y = 0; };
    };

	

	// Quad
    class Quad8 : public Vector8
    {
    public:
        union
        {
            s8			altimeter;		// Altimeter(고도계)
            s8			altitude;		// Altitude(고도)
            s8			throttle;		// Throttle
        };
        
        void		init() { roll = pitch = yaw = throttle = 0; };
    };


    class Quad16 : public Vector16
    {
    public:
        union
        {
            s16			altimeter;		// Altimeter(고도계)
            s16			altitude;		// Altitude(고도)
            s16			throttle;		// Throttle
        };
        
        void		init() { roll = pitch = yaw = throttle = 0; };
    };

	
    class Quad32 : public Vector32
    {
    public:
        union
        {
            s32			altimeter;		// Altimeter(고도계)
            s32			altitude;		// Altitude(고도)
            s32			throttle;		// Throttle
        };
        
        void		init() { roll = pitch = yaw = throttle = 0; };
    };
	
	
    class QuadF : public VectorF
    {
    public:
        union
        {
            float		altimeter;		// Altimeter(고도계)
            float		altitude;		// Altitude(고도)
            float		throttle;		// Throttle
        };
        
        void		init() { roll = pitch = yaw = throttle = 0; };
    };
    
    
    class QuadD : public VectorD
    {
    public:
        union
        {
            double		altimeter;		// Altimeter(고도계)
            double		altitude;		// Altitude(고도)
            double		throttle;		// Throttle
        };
        
        void		init() { roll = pitch = yaw = throttle = 0; };
    };
	
	
	/*
		DataType.Pairing
	 */
	class Pairing
	{
	public:
		u8		address[5];
		u8		channelArray[8];
	};

	
#endif