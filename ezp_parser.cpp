#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(int argc, char* argv[])
{
 if (argc > 1)
 {
 ifstream file(argv[1]);
 char buf, man_code, id_code, cap_code, block_size;
 unsigned int blocks;
 char icType[0x10] = "";
 char icManuf[0x10] = "";
 char icName[0x10] = "";
 int i, j;
 if (!file)
 {
   cout << "File not opened!" << endl;
   return 0;
 }	
 //{ "W25Q64BV",		0xef, 0x40170000, 64 * 1024, 128,  0, 2.70, 3.60 },
 cout << "ic_type  ManuFacture ic_name	man_code  id_code  block_size  blocks 4bit" << endl;
 cout << "===========================================================================" << endl;
 i = 0;
 while (!file.eof())
 {
	 for (j=0; j<0x10; j++)
	 {
		 icType[j] = 0;
	 }
	 while ((i < 0x10) && (buf != ',')) // ASCII data reading
	 {
	     file.get(buf);	   
	     icType[i] = buf;
	     i++;	   
	 }
	 icType[i-1] = 0x00; 
	 //printf ("%s", icType);
	 for (j=0; j<0x10; j++)
	 {
		 icManuf[j] = 0;
	 }
	 j = 0;
	 buf= 0x20;	
	 while ((i < 0x20) && (buf != ',')) // ASCII data reading
	 {
	     file.get(buf);	   
	     icManuf[j] = buf;
	     i++;
	     j++;	   
	 }
	 icManuf[j-1] = 0x00; 
	 //printf (" %s", icManuf);
	 
	 for (j=0; j<0x10; j++)
	 {
		 icName[j] = 0;
	 }
	 j = 0;
	 buf= 0x20;	
	 while ((i < 0x30) && (buf != 0x00)) // ASCII data reading
	 {
	     file.get(buf);	   
	     icName[j] = buf;
	     i++;
	     j++;	   
	 }
	 icName[j-1] = 0x00; 
	 //printf (" { \"%s\", ", icName);
	 
	  
	 while (i < 0x44)
	 {
		file.get(buf);
		if (i == 0x30) cap_code = buf;
		if (i == 0x31) id_code = buf;
		if (i == 0x32) man_code = buf;
		if (i == 0x36) blocks = abs(buf);
		if (i == 0x37) blocks = blocks + abs(buf * 256);
		if (i == 0x39) block_size = buf;
		i++; 
     }
	  i = 0;
	  if (strcmp (icType, "SPI_FLASH") == 0)
	  {
	     printf ("%s %s { \"%s\", ", icType, icManuf, icName);
	     printf("		0x%hhx, 0x%hhx%hhx0000, 64 * %d, %d", man_code, id_code, cap_code, (block_size * 1024), blocks );
         if (blocks < 512) printf(", 0 },\n");
         else printf(", 1 },\n");
      }
 }	   	  

 file.close();
}
else cout << "Noting to open! \nExample: ezp_parser <Filename>\n";
 return 0;
}

