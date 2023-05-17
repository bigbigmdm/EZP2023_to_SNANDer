# EZP2023_to_SNANDer
This is the parser of chips data from the EZP2019 - EZP2023 programmer to the SNANDer programmer.
The EZP2019, EZP2020, EZP2022, EZP2023 programmers has the big chips database stored in binary file EZP20xx.Dat 
(e.q. EZP2023+.Dat, EZP2019.Dat etc.)
This programm extracting the SERIAL NOR FLASH chip informations from this file and print it in the SNANDer format:
{"Chip Name", Manufacture id, Chip ID, Block Sisz, Number of blocks, 4bit operations enable}
You can print in terminal ./ezp_parser <Dat file name> and copying many strings with chip data to file spi_nor_flash.c
in the SNANDer project.
