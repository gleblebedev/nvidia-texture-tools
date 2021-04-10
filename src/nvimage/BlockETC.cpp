#include "BlockETC.h"
#include "../nvmath/Color.inl"
#include "../nvtt/CompressorETC.h"


void nv::BlockETC::decodeBlock(ColorBlock* output_colors) const
{
    Vector4 colors[16];
    decompress_etc(this, colors);
    for (int i = 0; i < 16; ++i)
        output_colors->color(i) = toColor32(colors[i]);
}

void nv::BlockEAC_ETC::decodeBlock(ColorBlock* output_colors) const
{
    Vector4 colors[16];
    decompress_etc_eac(this, colors);
    for (int i = 0; i < 16; ++i)
        output_colors->color(i) = toColor32(colors[i]);
}
