#include <iostream>
#include "Windows.h"
//traducir a humano
//cadena inmutable
const char* getProcType(int proc)
{
    switch (proc)
    {
    case 0: return "x86";
    case 5: return "ARM";
    case 6: return "Intel Titanium - based";
    case 9: return "x64 (AMD or Intel)";
    case 12: "ARM64";
    default: return "Unkwon";
    }
}

const char* getTitleFromKarma(byte karma) {
    if (karma >= 0 && karma < 25) return "Hitler";
    else if (karma >= 25 && karma < 50) return "Despota";
    else if (karma >= 50 && karma < 100) return "Tirano";
    else if (karma >= 100 && karma < 150) return "Neutro";
    else if (karma >= 150 && karma < 200) return "Bondadoso";
    else if (karma >= 200 && karma < 230) return "Santo";
    else if (karma >= 230 && karma <= 255) return "Divino";
    else return "Unknown";
}

int main()
{
    //pruebas con datos atomicos
    int i = 2147483647;
    std::cout << "overflow de int" << i << "\n";

    std::cout<< "i = " << i << "\n";
    i++;
    std::cout << "i = " << i << "\n";

    unsigned short int usi = 65635;

    std::cout << "overflow de unsigned short int" << usi << "\n";

    std::cout << "usi = " << usi << "\n";
    usi++;
    std::cout << "usi = " << usi << "\n";

    short int si = 20000;

    std::cout << "overflow de signed short int" << si << "\n";

    std::cout << "usi = " << si << "\n";
    si = si+20000;
    std::cout << "usi = " << si << "\n";

    //ejemplo del bud de ghandi
    //definimos el "karma como el nivel de maldad o bondad, va de 0 a 255
    //karma 0 es malvado
    //karma 128 es neutral
    //karma 255 muy bondadoso
    byte karma = 128;
    std::cout << "karma: " << (int)karma << "\n";

    for (int x = 0; x < 20; x++) 
    {
        karma += 10;

        std::cout << "incrementando karma en 10: " << static_cast<int>(karma) << " - " << getTitleFromKarma(karma) << "\n";
    }

    SYSTEM_INFO sisinfo;
    GetSystemInfo(&sisinfo);
    std::cout << "Procesador: " << getProcType(sisinfo.wProcessorArchitecture) << "\n";

    return 0;
}

