#include <fstream>
#include <iostream>

#include "spoofer.hpp"

int main( ) {
    system( "mountvol X: /S > nul" );
    system( "attrib -s -h X:\\EFI\\Microsoft\\Boot\\bootmgfw.efi > nul" );
    system( "move X:\\EFI\\Microsoft\\Boot\\bootmgfw.efi X:\\EFI\\Microsoft\\Boot\\bootmgfw.old > nul" );

    std::ofstream temp_file("X:\\EFI\\Microsoft\\Boot\\bootmgfw.efi", std::ios::binary );
    temp_file.write( reinterpret_cast< char* >( rawData ), sizeof(rawData) );
    temp_file.close( );

    system( "shutdown /r /t 0" );
}

// Discord - leshashved