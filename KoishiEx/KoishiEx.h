#ifndef KOISHI_EX_LIB
#define KOISHI_EX_LIB

#pragma once

#include <vector>
#include <string>
#include <math.h>
#pragma warning(disable:4018)			//�޷������������ֱ�ӽ��в���
#pragma warning(disable:4244)			//��ͬ��������֮���ǿ��ת��
#pragma warning(disable:4390)			//���ڿյ��ܿ����
#pragma warning(disable:4996)			//����ȫ�ĺ��������


#define KOISHI_EX_VER		(double)1.1

#define MAX_UNCOMPRESSED_DATA_LENGTH	0x1000000

#define unclared
#define declare_basefun(_member,_type) protected:_type _member;public:inline _type get_##_member() const{return _member;}inline _type*getPtr_##_member(){return &_member;}inline void set_##_member(_type val){_member=val;}


namespace Koishi{
	//���ֶ���
	typedef std::string				str;
	typedef float					fl1;
	typedef double					fl2;
	typedef unsigned char			b8,			*pb8;
	typedef unsigned short			b16,		*pb16;
	typedef unsigned long			b32,		*pb32;
	typedef unsigned long long		b64,		*pb64;
	typedef signed char				i8,			*pi8;
	typedef short					i16,		*pi16;
	typedef long					i32,		*pi32;
	typedef long long				i64,		*pi64;
	typedef std::vector<b8>			lb8;
	typedef std::vector<b16>		lb16;
	typedef std::vector<b32>		lb32;
	typedef std::vector<b64>		lb64;
	typedef std::vector<i8>			li8;
	typedef std::vector<i16>		li16;
	typedef std::vector<i32>		li32;
	typedef std::vector<i64>		li64;
	extern str NPKheaderStr;
	extern str IMGheaderStr;
	extern str IMGheaderStr2;
	extern str NPKext;
	extern str IMGext;
	extern str IMGnameMask;
	enum IMGversion{V1 = 1, V2 = 2, V4 = 4, V5 = 5, V6 = 6, OGG = -1, VUDEF = 0};
	enum command{
		//�ṹ���
		CREATE, LOAD, MAKE, RELEASE, CONVERT,
		//ͼƬ���
		GETINFO, GETINFOGETDATA, PUSH, INSERT, REMOVE, REPLACE, EXTRACT, PREPROCESS, EMPTY,
		//DDS���
		DDSGETINFO, DDSGETDATA, DDSPUSH, DDSINSERT, DDSREMOVE, DDSREPLACE, DDSEXTRACT, DDSPREPROCESS, 
		//��ɫ���
		CLRPUSH, CLRINSERT, 
		//�������
		RENAME, SETPARA
	};
	enum compressType{COMP_NONE = 5, COMP_ZLIB = 6, COMP_ZLIB2 = 7, COMP_UDEF = 0};
	enum DDSPixelFormatID{DXT1 = 0x12, DXT3=0x13, DXT5=0x14, DPF_UDF = 0};
	enum colorFormat{ARGB8888 = 0x10, ARGB4444 = 0x0F, ARGB1555 = 0x0E, LINK = 0x11, DDS_DXT1 = 0x12, DDS_DXT3 = 0x13, DDS_DXT5 = 0x14, COLOR_UDEF = 0, V4_FMT, RGB565};
	enum colorMethod{LAY, DARKEN, MULTIPLY, COLORBURN, LINEARBURN, LIGHTEN, SCREEN, COLORDODGE, LINEARDODGE, OVERLAY, HARDLIGHT, SOFTLIGHT, VIVIDLIGHT, LINEARLIGHT, PINLIGHT, HARDMIX, DIFFER, EXCLUSION};
	enum picChangablePara{LINKTO, BASEX, BASEY, FRAMEW, FRAMEH};
	enum channelFlag{FA = 0x01, FR = 0x02, FG = 0x04, FB = 0x08};
	enum layerMethod{UPPER, LOWER};
	class stream;
	class color;
	class point;
	class size;
	class matrix;
	class palette;
	typedef stream *pstream;
	typedef color *pcolor;
	typedef point *ppoint;
	typedef size *psize;
	typedef std::vector<color> lcolor;
	typedef std::vector<lcolor> llcolor;
	///////////////////////////////////////
	//������
	///////////////////////////////////////
	class stream{
	public:
		stream();
		stream(b64 _len);
		stream(const stream &_s);
		~stream();
		stream& operator = (const stream &_s);
	public:
		void allocate(b64 _len);
		void reallocate(b64 _len);
		void release();
	public:
		b8& operator[] (b64 _i) const;
		operator str();
		b64 getLen() const;
		b64 getMaxLen() const;
		b64 ptPos() const;
		b64 ptMoveTo(i64 pos);
		b64 ptMove(i64 dist);
	public:
		//����������ݣ������ͷſռ�
		void clear();
		b8 push(b8 _d);
		b8 push(b16 _d);
		b8 push(b32 _d);
		b8 push(b64 _d);
		b8 push(i32 _i);
		b8 read(b8 &_d);
		b8 read(b16 &_d);
		b8 read(b32 &_d);
		b8 read(b64 &_d);
		b8 read(i32 &_i);
		b8 pushString(str _s);
		str readString(b32 _len);
		b8 pushStream(const stream &_s, b64 _len);
		void readStream(stream &dest, b64 _len);
		void insertStream(const stream &_s, b64 _len, b64 _pos);
		void deleteStream(b64 _pos, b64 _len);
		bool modify(b64 _pos, b8 _d);
		bool modify(b64 _pos, i32 _i);
		b64 replace(const b8 &whos, const b8 &to);	//�����滻�˶��ٸ�
	public:
		//���������洢���ļ�
		bool makeFile(str fileName);
		bool loadFile(str fileName);
	public:
		//NPK�����ļ�����
		void nameMask();
		//������������type��ʾѹ�������洢��dest��
		i8 compressData(stream &dest, compressType type);
		//������������type��ʾ��ѹ�����洢��dest�У��ɹ�����0�����ݴ��󷵻�-3��tryLength��������-5
		i8 uncompressData(stream &dest, compressType type, b64 tryLength = MAX_UNCOMPRESSED_DATA_LENGTH);
		//������������MD5���ܣ�����16�ֽ����ݴ洢��dest��
		unclared void getMD5(stream &dest);
		//������������SHA256���ܣ�����32�ֽ����洢��dest��
		void getSHA256(stream &dest);
		void getSHA256(stream &dest, const stream &added);
	protected:
		pb8 data;
		b64 len,maxLen,pt;
	};
	/////////////////////////////////////
	typedef struct{
		i32 H;
		fl2 S;
		fl2 V;
	}colorHSV;
	class color{
		declare_basefun(A,b8);
		declare_basefun(R,b8);
		declare_basefun(G,b8);
		declare_basefun(B,b8);
	public:
		color();
		color(b32 colorDt, colorFormat clrFmt = ARGB8888);
		color(b8 r, b8 g, b8 b);
		color(b8 a, b8 r, b8 g, b8 b);
		void set(b32 colorDt, colorFormat clrFmt = ARGB8888);
	public:
		color getChannel(b8 _chn) const;
		operator b32() const;
		fl2 mixMethod(fl2 a,fl2 b, colorMethod _method);
		b8 mixMethod(b8 a,b8 b, colorMethod _method);
		void mixWith(const color &_clr2, colorMethod _method = LAY);
		color mix(const color &_clr1, const color &_clr2, colorMethod _method = LAY);
	public:
		//HSV����
		void getHSV(colorHSV &hsv) const;
		void useHSV(const colorHSV &hsv);
		void moveHto(i32 newH);
		void moveSto(fl2 newS);
		void moveVto(fl2 newV);
		void moveH(i32 delta);
		void moveS(fl2 delta);
		void moveV(fl2 delta);
		void moveRto(b8 newR);
		void moveGto(b8 newG);
		void moveBto(b8 newB);
		void moveR(i8 delta);
		void moveG(i8 delta);
		void moveB(i8 delta);
	};
	////////////////////////////////////
	class point{
		declare_basefun(X,i32);
		declare_basefun(Y,i32);
	public:
		point();
		point(i32 x, i32 y);
		void set(i32 x, i32 y);
		void moveHonz(i32 dist);
		void moveVert(i32 dist);
		void move(i32 honzDist, i32 vertDist);
		void move(size sz);
	};
	class size{
		declare_basefun(W,i32);
		declare_basefun(H,i32);
	public:
		size();
		size(i32 w, i32 h);
		void set(i32 w, i32 h);
		i32 area() const;
	};
	//////////////////////////////////
	//static size operator - (const point& pt1, const point& pt2);
	//static point operator + (const point& pt1, const size& sz);
	//static point operator - (const point& pt1, const size& sz);
	/////////////////////////////////////
	class matrix{
	public:
		matrix();
		matrix(b32 _row, b32 _column);
		matrix(const size &_sz);
		matrix(const matrix &_mat);
		~matrix();
		matrix& operator = (const matrix &_mat);
	public:
		//�ڴ����
		void allocate(b32 _row, b32 _column);
		void allocate(const size &_sz);
		void release();
		void fill(color _clr);
		void push(color _clr);							//�α괦��ɫ��ֵ����1
		b64 push(const stream &_s, colorFormat cf = ARGB8888);		//�������
		b64 make(stream &_s) const;							//������ARGB8888��
	public:
		//ȡֵ/����
		pcolor operator[] (b32 _i) const;		//��д˫�±꺯��
		b32 getRowCount() const;
		b32 getColumnCount() const;
		b32 getElemCount() const;
		//ȡ����
		void getSubMatrix(matrix &dest, b32 rowStart, b32 rowEnd, b32 columnStart, b32 columnEnd) const;
		void getChannelMatrix(matrix &dest, b8 _chn = FA) const;
		//�������
		void expandMatrix(matrix &dest, b32 toTop, b32 toBottom, b32 toLeft, b32 toRight) const;
		//Ԫ��ͳ��
		void setElem(b32 _row, b32 _column, const color &_clr);
		void setElem(b32 _id, const color &_clr);
		color getElem(b32 _row, b32 _column) const;			//ȡ���ص�
		color getElem(b32 _id) const;						//ȡ���ص�
		b32 getElemCountNzero() const;						//ͳ��ʵ�����ظ���
		b32 getElemCountWhos(const color &whos) const;		//ͳ����ɫֵ����whos�����ظ���
		void getElemCountList(lcolor &colorList) const;			//ͳ�����г��ֵ���ɫ
		void getElemHonzBound(b32 &lower, b32 &upper) const;	//ͳ�ƴ���ʵ�����ص�ˮƽ�߽�
		void getElemVertBound(b32 &lower, b32 &upper) const;	//ͳ�ƴ���ʵ�����صĴ�ֱ�߽�
	public:
		//��������
		i32 elemMoveHonz(i32 dist);							//��0Ԫ��ˮƽ�ƶ�
		i32 elemMoveVert(i32 dist);							//��0Ԫ�ش�ֱ�ƶ�
		i32 elemReplace(const color &whos, const color &to);//��ָ����ɫ���������ر��ΪĿ����ɫ
		void putFore(const matrix &layer, colorMethod _met = LAY);	//��ǰ��
		void putBack(const matrix &layer, colorMethod _met = LAY);	//�̱���
	public:
		bool loadPNG(str fileName);
		bool makePNG(str fileName);
	protected:
		pcolor data;
		b32 column, row, pt;
	};
	//��ɫ��
	class palette{
	public:
		palette();
		~palette();
	public:
		lcolor& operator[] (i32 i);
		void clear();
		void push(lcolor colorList);
		i32 getCount() const;
		i32 getTotalColorCount() const;
	public:
		//�Ե�����ɫ�����
		i32 getColorCount(i32 paletteID = 0) const;
		i32 findColor(color goalColor, i32 paletteID = 0) const;
		bool joinWith(const lcolor &colorList, i32 paletteID = 0);
	public:
		bool tinyMake(stream &s, i32 paletteID = 0);
		bool bigMake(stream &s);
	protected:
		llcolor table;
	};
	//////������////////////////////////
	class NPKobject;		//����NPK��
	class IMGobject;		//IMG��
	//////�ṹ��//////////////////////
	class IMGindex;			//IMG��������
	class PICinfo;			//PIC����
	class DDSinfo;			//DDS����
	typedef std::vector<IMGindex> IMGcontent;
	typedef std::vector<IMGobject> IMGlist;
	typedef std::vector<PICinfo> PIClist;
	typedef std::vector<DDSinfo> DDSlist;
	///////////////////////////////////
	class IMGindex{
		//IMG��������
		declare_basefun(imgoffset,b32);
		declare_basefun(imgsize,b32);
		declare_basefun(imgname,str);
	public:
		IMGindex();
	};
	class PICinfo{
		//ͼ����Ϣ
		declare_basefun(format, colorFormat);
		declare_basefun(comp, compressType);
		declare_basefun(dataSize, b32);
		declare_basefun(basePt, point);
		declare_basefun(picSize, size);
		declare_basefun(frmSize, size);
		declare_basefun(linkTo, i32);
		//V5����
		declare_basefun(DDSIDused, b32);
		declare_basefun(DDSpointLT, point);
		declare_basefun(DDSpointRB, point);
	public:
		PICinfo();
	};
	class DDSinfo{
		declare_basefun(fourCCID, DDSPixelFormatID);
		declare_basefun(DDSID, b32);
		declare_basefun(lengthOfCompressed, b32);
		declare_basefun(lengthOfDDS, b32);
		declare_basefun(width, b32);
		declare_basefun(height, b32);
		declare_basefun(reserved, b32);
	public:
		DDSinfo();
	};
	class NPKobject{
	public:
		NPKobject();
		NPKobject(const stream &_s);
		NPKobject(const str &fileName);
		bool load(const stream &_s);
		bool make(stream &_s);
		bool loadFile(const str &fileName);
		bool saveFile(const str &fileName);
		bool create();
		bool release();
	public:
		bool IMGpush(const IMGobject &obj, const str &imgName);
		bool IMGinsert(i32 pos, const IMGobject &obj, const str &imgName);
		bool IMGremove(i32 pos);
		bool IMGreplace(i32 pos, const IMGobject &obj);
		bool IMGrename(i32 pos, const str& newName);
	public:
		pstream getData(b8 part);
		b64 getSize() const;
		bool IMGextract(b32 pos, IMGobject &obj);
		bool extractIMGFile(i32 pos, str fileName);
	public:
		b32 count;
		IMGcontent content;
	protected:
		//Data���ĸ������ļ�ͷ��IMG������У��λ��IMG�ļ�
		stream data1, data2, data3, data4;
		bool invoke(b16 command, void *para1 = NULL, void *para2 = NULL, void *para3 = NULL);
	
	};
	/////////////////////////////////////
	class IMGobject{
	public:
		IMGobject();
		IMGobject(stream &s);
		IMGobject(const str &fileName);
		~IMGobject();
		bool LoadFile(str fileName);			//���ļ��ж�ȡ
		bool SaveFile(str fileName);			//�����ļ�
		bool Load(stream &s);
		bool Make(stream &s);
		bool Create(IMGversion ver);
		bool Release();
		bool GetPICInfo(i32 pos, PICinfo &info);		//
		bool GetPICInfoOffset(i32 pos, b64 &off);
		bool GetPICData(i32 pos, stream &s);
		bool GetPICDataOffset(i32 pos, b64 &off);
		bool GetDDSInfo(i32 pos, DDSinfo &info);
		bool GetDDSInfoOffset(i32 pos, b64 &off);
		bool GetDDSData(i32 pos, stream &s);
		bool GetDDSDataOffset(i32 pos, b64 &off);
		bool SetPICInfoPara(i32 pos, i32 term, void *pval);
		bool PICpush(const PICinfo &info, const stream &s);
		bool PICinsert(i32 pos, const PICinfo &info, const stream &s);
		bool PICremove(i32 pos);
		bool PICreplace(i32 pos, const PICinfo &info, const stream &s);
		bool PICextract(i32 pos, matrix &mat, i32 paletteID = 0);
		bool PICpreprocess(const matrix &mat, stream &s, PICinfo &info);
		bool PICempty(stream &s, PICinfo &info);
		bool DDSpush(const DDSinfo &info, const stream &s);
		bool DDSinsert(i32 pos, const DDSinfo &info, const stream &s);
		bool DDSremove(i32 pos);
		bool DDSreplace(i32 pos, const DDSinfo &info, const stream &s);
		bool DDSextract(i32 pos, matrix &mat);
		bool DDSpreprocess(const matrix &mat, stream &s, DDSinfo &info);
		bool CLRpush(const color &clr, i32 paletteID = 0);
		bool CLRinsert(i32 pos, const color &clr, i32 paletteID = 0);
		bool CLRremove(i32 pos, i32 paletteID = 0);
		bool CLRreplace(i32 pos, const color &clr, i32 paletteID = 0);
		bool CLRnewPalette();
		bool ConvertTo(IMGobject &newIO, IMGversion newVersion, i32 palettedID = 0);
	public:
		i32 linkFind(b32 pos, b32 depth = 5);		//��������֡����ָ��depthΪ��ȣ�
		b64 getSize() const;
	protected:
		stream *getData(b8 _part);
		stream data1;		//�ļ�ͷ��V2,V4,V6Ϊһ��,V5Ϊһ�飩
		stream data2;		//��ɫ������
		stream data3;		//DDS��Ϣ��V5֮����Ч
		stream data4;		//ͼ����Ϣ
		stream data5;		//DDSͼ�����ݣ�V5֮����Ч
		stream data6;		//ͼ������
	public:
		IMGindex *derived;

		IMGversion version;
		b32 indexCount, indexSize;
		b32 V5_DDSCount;
		b32 V5_totalLength;

		palette paletteData;
		DDSlist DDScontent;
		PIClist PICcontent;
	};
}


#endif
