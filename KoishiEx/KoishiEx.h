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

#define MAX_UNCOMPRESSED_DATA_LENGTH	0x100000

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
	typedef char					i8,			*pi8;
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
	enum compressType{COMP_NONE = 5, COMP_ZLIB = 6, COMP_UDEF = 0};
	enum colorFormat{ARGB8888 = 0x10, ARGB4444 = 0x0F, ARGB1555 = 0x0E, LINK = 0x11, COLOR_UDEF = 0, V4_FMT};
	enum colorMethod{LAY, DARKEN, MULTIPLY, COLORBURN, LINEARBURN, LIGHTEN, SCREEN, COLORDODGE, LINEARDODGE, OVERLAY, HARDLIGHT, SOFTLIGHT, VIVIDLIGHT, LINEARLIGHT, PINLIGHT, HARDMIX, DIFFER, EXCLUSION};
	enum command{CREATE, LOAD, MAKE, RELEASE, PUSH, INSERT, REMOVE, REPLACE, RENAME, SETPARA, EXTRACT, PREPROCESS, CONVERT};
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
	static size operator - (const point& pt1, const point& pt2);
	static point operator + (const point& pt1, const size& sz);
	static point operator - (const point& pt1, const size& sz);
	/////////////////////////////////////
	class matrix{
	public:
		matrix();
		matrix(b32 _row, b32 _column);
		matrix(const matrix &_mat);
		~matrix();
		matrix& operator = (const matrix &_mat);
	public:
		//�ڴ����
		void allocate(b32 _row, b32 _column);
		void reallocate(b32 _row, b32 _column);
		void release();
		void fill(color _clr);
		void push(color _clr);					//�α괦��ɫ��ֵ����1
		b64 push(const stream &_s);				//�������
		b64 make(stream &_s);					//��������
	public:
		//ȡֵ/����
		pcolor operator[] (b32 _i) const;		//��д˫�±꺯��
		b32 getRowCount() const;
		b32 getColumnCount() const;
		b32 getElemCount() const;
		//ȡ����
		void getSubMatrix(matrix &dest, b32 &_rst, b32 &_red, b32 &_cst, b32 &_ced) const;
		void getChannelMatrix(matrix &dest, b8 _chn = FA) const;
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
	typedef std::vector<IMGindex> IMGcontent;
	typedef std::vector<IMGobject> IMGlist;
	typedef std::vector<PICinfo> PIClist;
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
	public:
		//ͼ����Ϣ
		declare_basefun(format, colorFormat);
		declare_basefun(comp, compressType);
		declare_basefun(dataSize, b32);
		declare_basefun(basePt, point);
		declare_basefun(picSize, size);
		declare_basefun(frmSize, size);
		declare_basefun(linkTo, i32);
	public:
		PICinfo();
	};
	///////////////////////////////////
	class NPKobject{
	public:
		NPKobject();
		bool load(const stream &_s);
		bool make(const stream &_s);
		bool loadFile(str fileName);
		bool saveFile(str fileName);
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
		~IMGobject();
		bool loadFile(str fileName);			//���ļ��ж�ȡ
		bool saveFile(str fileName);			//������
	public:
		bool create(IMGversion ver = V2);
		bool load(const stream &_s);
		bool make(stream& _s);
		bool release();
		bool PICparaModify(i32 pos, i32 term, i32 val);
		bool PICpush(const PICinfo &obj, const stream &_s);
		bool PICinsert(i32 pos, const PICinfo &obj, const stream &_s);
		bool PICremove(i32 pos);
		bool PICreplace(i32 pos, const PICinfo &obj, const stream &_s);
		bool PICextract(i32 pos, matrix &mat, i32 paletteID = 0);
		bool PICpreprocess(const matrix &mat, stream &s, PICinfo &obj);
		bool colorExtract(lcolor &list);
		bool convertTo(IMGversion newVer, IMGobject &imgObj, i32 paletteID = 0);
	public:
		pstream getData(b8 _part);
		b64 getSize() const;
		bool PICInfo(b32 pos, PICinfo &obj);
		bool PICData(b32 pos, stream &data);
		bool PICInfoOffset(b32 pos, b64 &off);		//����Ŀ���ֽ��������ݿ�3�ڵĴ洢λ��
		bool PICDataOffset(b32 pos, b64 &off);		//����Ŀ���ֽ��������ݿ�4�ڵĴ洢λ��
		i32 linkFind(b32 pos, b32 depth = 5);		//��������֡����ָ��depthΪ��ȣ�
	public:
		//ͨ������
		IMGversion version;
		b32 count, indexSize;
		IMGindex *derived;
		PIClist content;
	public:
		//V4,V6ʹ�õĵ�ɫ��
		palette paletteData;
	protected:
		//Data��Ϊ�ĸ������ļ�ͷ��IMG��������ͼ����Ϣ����ͼ��������
		stream data1, data2, data3, data4;
		bool invoke(b16 command, void *para1 = NULL, void *para2 = NULL, void *para3 = NULL);
	};
}


#endif
