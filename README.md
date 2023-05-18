# EZP2023_to_SNANDer
This is the parser of chips data from the EZP2019 - EZP2023 programmer to the SNANDer programmer.

The EZP2019, EZP2020, EZP2022, EZP2023 programmers have a big database of chips 
stored in the binary file `EZP20xx.Dat` (for example, `EZP2023+.Dat`, `EZP2019.Dat`, etc.) 
This program takes the information about the SERIAL NOR FLASH chips from this file 
and prints it in the SNANDer format:

`{"Chip Name", Manufacture id, Chip ID, Block Sise, Number of blocks, 4bit operations enable}`

You can print in the terminal `./ezp_parser <Dat file name>` and copy some needed lines with chip data into the file `spi_nor_flash.c` in SNANDer project.
in the SNANDer project.

 ![The screenshot](https://github.com/bigbigmdm/EZP2023_to_SNANDer/raw/main/ezp_parser.png)  
