# EZP2023_to_SNANDer
This is the parser of chips data from the EZP2019 - EZP2023 programmer to the SNANDer programmer.

The EZP2019, EZP2020, EZP2022, EZP2023 programmers have a big database of chips 
stored in the binary file `EZP20xx.Dat` (for example, `EZP2023+.Dat`, `EZP2019.Dat`, etc.) 
This program takes the information about the SERIAL NOR FLASH chips from this file 
and prints it in the SNANDer format:

`{"Chip Name", Manufacture id, Chip ID, Block Sise, Number of blocks, 4bit operations enable}`

You can print in the terminal `./ezp_parser <Dat file name>` and copy some needed lines with chip data into the file `spi_nor_flash.c` 
in the [SNANDer](https://github.com/McMCCRU/SNANDer) project.  

 ![The screenshot](https://github.com/bigbigmdm/EZP2023_to_SNANDer/raw/main/ezp_parser.png)  

EZP2019.Dat parsing:

Chip string lenght: 0x44 (68) bytes;

```
offset	 Size   Value
00 -     2F     ASCII Chip type, Name and Manufacture, 0x00 filling
30        1     NOR FLASH Chip Size code   / 0x00 - other chips
31        1     NOR FLASH Chip ID Code     / 0x00 - other chips
32        1     NOR FLASH Manufacture code / 0x00 - other chips
33              0x00
34        4     Chip Size
35 	
36 	  
37 
38        2     Block size
39 
3A        1     0x00 - NOR FLASH FLAG / 0x01 - 24xxx FLAG / 0x02 - 93xxx FLAG / 0x04 - 95xxx
3B        1     ???
3C        2     Timing parameter:
3D              3000/1000/500/300/200/100 - NOR FLASH, 4000/2000 - 24xxx, 100 - 93xxx
3E        1     0x00
3F        1     0x00
40        1     ???
41        1     ???
42        1     ???
43        1     VCC 00=>3.3V 01=>1.8V 02=>5.0V
The end record is 0x44 (68) zero bytes.
```
