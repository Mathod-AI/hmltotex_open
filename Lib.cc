#include <string>
#include <cstring>

extern void hwpEqToTex(std::wstring& str);

extern "C" __declspec(dllexport) void HwpEqToTex(const wchar_t* in, wchar_t* out, size_t num_size)
{
    std::wstring out_str = in;
    hwpEqToTex(out_str);
    std::copy_n(out_str.begin(), std::min(out_str.length(), num_size), out);
}