// MIT license see full LICENSE text at end of file
#pragma once

#include "nvimage.h"

#define NV_MAKEFOURCC(ch0, ch1, ch2, ch3) \
    (uint(uint8(ch0)) | (uint(uint8(ch1)) << 8) | \
    (uint(uint8(ch2)) << 16) | (uint(uint8(ch3)) << 24 ))

namespace nv
{
    class Image;
    class FloatImage;
    class Stream;

    enum DDPF
    {
        DDPF_ALPHAPIXELS = 0x00000001U,
        DDPF_ALPHA = 0x00000002U,
        DDPF_FOURCC = 0x00000004U,
        DDPF_RGB = 0x00000040U,
        DDPF_PALETTEINDEXED1 = 0x00000800U,
        DDPF_PALETTEINDEXED2 = 0x00001000U,
        DDPF_PALETTEINDEXED4 = 0x00000008U,
        DDPF_PALETTEINDEXED8 = 0x00000020U,
        DDPF_LUMINANCE = 0x00020000U,
        DDPF_ALPHAPREMULT = 0x00008000U,

        // Custom NVTT flags.
        DDPF_NORMAL = 0x80000000U,
        DDPF_SRGB = 0x40000000U,
    };


    enum D3DFORMAT
    {
        // 32 bit RGB formats.
        D3DFMT_R8G8B8 = 20,
        D3DFMT_A8R8G8B8 = 21,
        D3DFMT_X8R8G8B8 = 22,
        D3DFMT_R5G6B5 = 23,
        D3DFMT_X1R5G5B5 = 24,
        D3DFMT_A1R5G5B5 = 25,
        D3DFMT_A4R4G4B4 = 26,
        D3DFMT_R3G3B2 = 27,
        D3DFMT_A8 = 28,
        D3DFMT_A8R3G3B2 = 29,
        D3DFMT_X4R4G4B4 = 30,
        D3DFMT_A2B10G10R10 = 31,
        D3DFMT_A8B8G8R8 = 32,
        D3DFMT_X8B8G8R8 = 33,
        D3DFMT_G16R16 = 34,
        D3DFMT_A2R10G10B10 = 35,

        D3DFMT_A16B16G16R16 = 36,

        // Palette formats.
        D3DFMT_A8P8 = 40,
        D3DFMT_P8 = 41,

        // Luminance formats.
        D3DFMT_L8 = 50,
        D3DFMT_A8L8 = 51,
        D3DFMT_A4L4 = 52,
        D3DFMT_L16 = 81,

        // Floating point formats
        D3DFMT_R16F = 111,
        D3DFMT_G16R16F = 112,
        D3DFMT_A16B16G16R16F = 113,
        D3DFMT_R32F = 114,
        D3DFMT_G32R32F = 115,
        D3DFMT_A32B32G32R32F = 116,
    };

    enum FOURCC
    {
        FOURCC_NVTT = NV_MAKEFOURCC('N', 'V', 'T', 'T'),
        FOURCC_DDS = NV_MAKEFOURCC('D', 'D', 'S', ' '),
        FOURCC_DXT1 = NV_MAKEFOURCC('D', 'X', 'T', '1'),
        FOURCC_DXT2 = NV_MAKEFOURCC('D', 'X', 'T', '2'),
        FOURCC_DXT3 = NV_MAKEFOURCC('D', 'X', 'T', '3'),
        FOURCC_DXT4 = NV_MAKEFOURCC('D', 'X', 'T', '4'),
        FOURCC_DXT5 = NV_MAKEFOURCC('D', 'X', 'T', '5'),
        FOURCC_RXGB = NV_MAKEFOURCC('R', 'X', 'G', 'B'),
        FOURCC_ATI1 = NV_MAKEFOURCC('A', 'T', 'I', '1'),
        FOURCC_ATI2 = NV_MAKEFOURCC('A', 'T', 'I', '2'),
        FOURCC_A2XY = NV_MAKEFOURCC('A', '2', 'X', 'Y'),
        FOURCC_DX10 = NV_MAKEFOURCC('D', 'X', '1', '0'),
        FOURCC_UVER = NV_MAKEFOURCC('U', 'V', 'E', 'R'),
        FOURCC_BC6H = NV_MAKEFOURCC('B', 'C', '6', 'H'),
        FOURCC_BC7L = NV_MAKEFOURCC('B', 'C', '7', 'L'),

        FOURCC_ETC1 = NV_MAKEFOURCC('E', 'T', 'C', '1'),
        FOURCC_ETC2 = NV_MAKEFOURCC('E', 'T', 'C', '2'),
        FOURCC_ET2A = NV_MAKEFOURCC('E', 'T', '2', 'A'),

        FOURCC_PTC2 = NV_MAKEFOURCC('P', 'T', 'C', '2'),
        FOURCC_PTC4 = NV_MAKEFOURCC('P', 'T', 'C', '4'),
    };


    // D3D1x resource dimensions.
    enum DDS_DIMENSION // D3D10_RESOURCE_DIMENSION
    {
        DDS_DIMENSION_UNKNOWN = 0,
        DDS_DIMENSION_BUFFER = 1,
        DDS_DIMENSION_TEXTURE1D = 2,
        DDS_DIMENSION_TEXTURE2D = 3,
        DDS_DIMENSION_TEXTURE3D = 4,
    };

    enum DDS_MISC_FLAG
    {
        DDS_MISC_TEXTURECUBE = 0x4,
    };

    // DXGI formats.
    enum DXGI_FORMAT
    {
        DXGI_FORMAT_UNKNOWN = 0,

        DXGI_FORMAT_R32G32B32A32_TYPELESS = 1,
        DXGI_FORMAT_R32G32B32A32_FLOAT = 2,
        DXGI_FORMAT_R32G32B32A32_UINT = 3,
        DXGI_FORMAT_R32G32B32A32_SINT = 4,

        DXGI_FORMAT_R32G32B32_TYPELESS = 5,
        DXGI_FORMAT_R32G32B32_FLOAT = 6,
        DXGI_FORMAT_R32G32B32_UINT = 7,
        DXGI_FORMAT_R32G32B32_SINT = 8,

        DXGI_FORMAT_R16G16B16A16_TYPELESS = 9,
        DXGI_FORMAT_R16G16B16A16_FLOAT = 10,
        DXGI_FORMAT_R16G16B16A16_UNORM = 11,
        DXGI_FORMAT_R16G16B16A16_UINT = 12,
        DXGI_FORMAT_R16G16B16A16_SNORM = 13,
        DXGI_FORMAT_R16G16B16A16_SINT = 14,

        DXGI_FORMAT_R32G32_TYPELESS = 15,
        DXGI_FORMAT_R32G32_FLOAT = 16,
        DXGI_FORMAT_R32G32_UINT = 17,
        DXGI_FORMAT_R32G32_SINT = 18,

        DXGI_FORMAT_R32G8X24_TYPELESS = 19,
        DXGI_FORMAT_D32_FLOAT_S8X24_UINT = 20,
        DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS = 21,
        DXGI_FORMAT_X32_TYPELESS_G8X24_UINT = 22,

        DXGI_FORMAT_R10G10B10A2_TYPELESS = 23,
        DXGI_FORMAT_R10G10B10A2_UNORM = 24,
        DXGI_FORMAT_R10G10B10A2_UINT = 25,

        DXGI_FORMAT_R11G11B10_FLOAT = 26,

        DXGI_FORMAT_R8G8B8A8_TYPELESS = 27,
        DXGI_FORMAT_R8G8B8A8_UNORM = 28,
        DXGI_FORMAT_R8G8B8A8_UNORM_SRGB = 29,
        DXGI_FORMAT_R8G8B8A8_UINT = 30,
        DXGI_FORMAT_R8G8B8A8_SNORM = 31,
        DXGI_FORMAT_R8G8B8A8_SINT = 32,

        DXGI_FORMAT_R16G16_TYPELESS = 33,
        DXGI_FORMAT_R16G16_FLOAT = 34,
        DXGI_FORMAT_R16G16_UNORM = 35,
        DXGI_FORMAT_R16G16_UINT = 36,
        DXGI_FORMAT_R16G16_SNORM = 37,
        DXGI_FORMAT_R16G16_SINT = 38,

        DXGI_FORMAT_R32_TYPELESS = 39,
        DXGI_FORMAT_D32_FLOAT = 40,
        DXGI_FORMAT_R32_FLOAT = 41,
        DXGI_FORMAT_R32_UINT = 42,
        DXGI_FORMAT_R32_SINT = 43,

        DXGI_FORMAT_R24G8_TYPELESS = 44,
        DXGI_FORMAT_D24_UNORM_S8_UINT = 45,
        DXGI_FORMAT_R24_UNORM_X8_TYPELESS = 46,
        DXGI_FORMAT_X24_TYPELESS_G8_UINT = 47,

        DXGI_FORMAT_R8G8_TYPELESS = 48,
        DXGI_FORMAT_R8G8_UNORM = 49,
        DXGI_FORMAT_R8G8_UINT = 50,
        DXGI_FORMAT_R8G8_SNORM = 51,
        DXGI_FORMAT_R8G8_SINT = 52,

        DXGI_FORMAT_R16_TYPELESS = 53,
        DXGI_FORMAT_R16_FLOAT = 54,
        DXGI_FORMAT_D16_UNORM = 55,
        DXGI_FORMAT_R16_UNORM = 56,
        DXGI_FORMAT_R16_UINT = 57,
        DXGI_FORMAT_R16_SNORM = 58,
        DXGI_FORMAT_R16_SINT = 59,

        DXGI_FORMAT_R8_TYPELESS = 60,
        DXGI_FORMAT_R8_UNORM = 61,
        DXGI_FORMAT_R8_UINT = 62,
        DXGI_FORMAT_R8_SNORM = 63,
        DXGI_FORMAT_R8_SINT = 64,
        DXGI_FORMAT_A8_UNORM = 65,

        DXGI_FORMAT_R1_UNORM = 66,

        DXGI_FORMAT_R9G9B9E5_SHAREDEXP = 67,

        DXGI_FORMAT_R8G8_B8G8_UNORM = 68,
        DXGI_FORMAT_G8R8_G8B8_UNORM = 69,

        DXGI_FORMAT_BC1_TYPELESS = 70,
        DXGI_FORMAT_BC1_UNORM = 71,
        DXGI_FORMAT_BC1_UNORM_SRGB = 72,

        DXGI_FORMAT_BC2_TYPELESS = 73,
        DXGI_FORMAT_BC2_UNORM = 74,
        DXGI_FORMAT_BC2_UNORM_SRGB = 75,

        DXGI_FORMAT_BC3_TYPELESS = 76,
        DXGI_FORMAT_BC3_UNORM = 77,
        DXGI_FORMAT_BC3_UNORM_SRGB = 78,

        DXGI_FORMAT_BC4_TYPELESS = 79,
        DXGI_FORMAT_BC4_UNORM = 80,
        DXGI_FORMAT_BC4_SNORM = 81,

        DXGI_FORMAT_BC5_TYPELESS = 82,
        DXGI_FORMAT_BC5_UNORM = 83,
        DXGI_FORMAT_BC5_SNORM = 84,

        DXGI_FORMAT_B5G6R5_UNORM = 85,
        DXGI_FORMAT_B5G5R5A1_UNORM = 86,
        DXGI_FORMAT_B8G8R8A8_UNORM = 87,
        DXGI_FORMAT_B8G8R8X8_UNORM = 88,

        DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,
        DXGI_FORMAT_B8G8R8A8_TYPELESS = 90,
        DXGI_FORMAT_B8G8R8A8_UNORM_SRGB = 91,
        DXGI_FORMAT_B8G8R8X8_TYPELESS = 92,
        DXGI_FORMAT_B8G8R8X8_UNORM_SRGB = 93,

        DXGI_FORMAT_BC6H_TYPELESS = 94,
        DXGI_FORMAT_BC6H_UF16 = 95,
        DXGI_FORMAT_BC6H_SF16 = 96,

        DXGI_FORMAT_BC7_TYPELESS = 97,
        DXGI_FORMAT_BC7_UNORM = 98,
        DXGI_FORMAT_BC7_UNORM_SRGB = 99,

        DXGI_FORMAT_AYUV = 100,
        DXGI_FORMAT_Y410 = 101,
        DXGI_FORMAT_Y416 = 102,
        DXGI_FORMAT_NV12 = 103,
        DXGI_FORMAT_P010 = 104,
        DXGI_FORMAT_P016 = 105,
        DXGI_FORMAT_420_OPAQUE = 106,
        DXGI_FORMAT_YUY2 = 107,
        DXGI_FORMAT_Y210 = 108,
        DXGI_FORMAT_Y216 = 109,
        DXGI_FORMAT_NV11 = 110,
        DXGI_FORMAT_AI44 = 111,
        DXGI_FORMAT_IA44 = 112,
        DXGI_FORMAT_P8 = 113,
        DXGI_FORMAT_A8P8 = 114,
        DXGI_FORMAT_B4G4R4A4_UNORM = 115,
        DXGI_FORMAT_P208 = 116,
        DXGI_FORMAT_V208 = 117,
        DXGI_FORMAT_V408 = 118,
        DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE = 119,
        DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE = 120,
        DXGI_FORMAT_FORCE_UINT = 121,

        //Fake format values to accomodate mobile compression algorithms
        EXDXGI_FORMAT_ETC1 = 200,
        EXDXGI_FORMAT_ETC2,
        EXDXGI_FORMAT_ETC2_RGBA,
        EXDXGI_FORMAT_PVRTC_2BPP_RGB,
        EXDXGI_FORMAT_PVRTC_2BPP_RGBA,
        EXDXGI_FORMAT_PVRTC_4BPP_RGB,
        EXDXGI_FORMAT_PVRTC_4BPP_RGBA,
    };

    extern uint findD3D9Format(uint bitcount, uint rmask, uint gmask, uint bmask, uint amask);
    extern uint findDXGIFormat(uint bitcount, uint rmask, uint gmask, uint bmask, uint amask);

    struct RGBAPixelFormat
    {
        uint bitcount;
        uint rmask;
        uint gmask;
        uint bmask;
        uint amask;
    };

    extern const RGBAPixelFormat *findD3D9PixelFormat(uint dxgiFormat);
    extern const RGBAPixelFormat *findDXGIPixelFormat(uint dxgiFormat);

    struct DDSPixelFormat
    {
        uint size;
        uint flags;
        uint fourcc;
        uint bitcount;
        uint rmask;
        uint gmask;
        uint bmask;
        uint amask;
    };

    struct DDSCaps
    {
        uint caps1;
        uint caps2;
        uint caps3;
        uint caps4;
    };

    /// DDS file header for DX10.
    struct DDSHeader10
    {
        uint dxgiFormat;
        uint resourceDimension;
        uint miscFlag;
        uint arraySize;
        uint reserved;
    };

    /// DDS file header.
    struct DDSHeader
    {
        uint fourcc;
        uint size;
        uint flags;
        uint height;
        uint width;
        uint pitch;
        uint depth;
        uint mipmapcount;
        uint reserved[11];
        DDSPixelFormat pf;
        DDSCaps caps;
        uint notused;
        DDSHeader10 header10;


        // Helper methods.
        DDSHeader();

        void setWidth(uint w);
        void setHeight(uint h);
        void setDepth(uint d);
        void setMipmapCount(uint count);
        void setTexture2D();
        void setTexture3D();
        void setTextureCube();
        void setTextureArray(int imageCount);
        void setLinearSize(uint size);
        void setPitch(uint pitch);
        void setFourCC(uint8 c0, uint8 c1, uint8 c2, uint8 c3);
        void setFormatCode(uint code);
        void setSwizzleCode(uint8 c0, uint8 c1, uint8 c2, uint8 c3);
        void setPixelFormat(uint bitcount, uint rmask, uint gmask, uint bmask, uint amask);
        void setDX10Format(uint format);
        void setNormalFlag(bool b);
        void setSrgbFlag(bool b);
        void setHasAlphaFlag(bool b);
        void setUserVersion(int version);

        void swapBytes();

        bool hasDX10Header() const;
        uint signature() const;
        uint toolVersion() const;
        uint userVersion() const;
        bool isNormalMap() const;
        bool isSrgb() const;
        bool hasAlpha() const;
        uint d3d9Format() const;
        uint pixelSize() const; // In bits!
        uint blockSize() const; // In bytes!
        bool isBlockFormat() const;
    };

    Stream & operator<< (Stream & s, DDSHeader & header);


    /// DirectDraw Surface. (DDS)
    class DirectDrawSurface
    {
    public:
        DirectDrawSurface();
        ~DirectDrawSurface();

        bool load(const char * filename);
        bool load(Stream * stream);

        bool isValid() const;
        bool isSupported() const;

        bool hasAlpha() const;
        bool isColorsRGB() const;

        uint mipmapCount() const;
        uint width() const;
        uint height() const;
        uint depth() const;
        uint arraySize() const;
        bool isTexture1D() const;
        bool isTexture2D() const;
        bool isTexture3D() const;
        bool isTextureCube() const;
        bool isTextureArray() const;
        bool isBlockFormat() const;

        void setNormalFlag(bool b);
        void setHasAlphaFlag(bool b);
        void setUserVersion(int version);

        uint surfaceWidth(uint mipmap) const;
        uint surfaceHeight(uint mipmap) const;
        uint surfaceDepth(uint mipmap) const;
        uint surfaceSize(uint mipmap) const;
        bool readSurface(uint face, uint mipmap, void * data, uint size);

        void printInfo() const;

        // Only initialized after loading.
        DDSHeader header;

    private:

        uint faceSize() const;
        uint offset(uint face, uint mipmap);

        Stream * stream;
        //void * data;
    };

    bool imageFromDDS(Image * img, DirectDrawSurface & dds, uint face, uint mipmap);
    bool imageFromDDS(FloatImage * img, DirectDrawSurface & dds, uint face, uint mipmap);

} // nv namespace

// Copyright NVIDIA Corporation 2007 -- Ignacio Castano <icastano@nvidia.com>
// Copyright (c) 2008-2020 -- Ignacio Castano <castano@gmail.com>
// 
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
