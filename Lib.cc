#include "hwpEqToTex.h"
#include <cstring>
#include <iostream>

extern "C" __declspec(dllexport) size_t HwpEqToTex(const wchar_t* in, wchar_t* out, size_t num_size)
{
    static bool __initialized = false;
    if (!__initialized)
    {
        __initialized = true;
        initializeEqValue(0, nullptr);
    }

    wstring out_str = L"$";
    out_str += in;
    out_str += L"$";
    hwpEqToTex(out_str);

    if (out_str.length() - 2 < num_size)
    {
        std::copy(out_str.begin() + 1, out_str.end() - 1, out);
        out[out_str.length() - 2] = L'\0';
    }

    return out_str.length() + 1;
}