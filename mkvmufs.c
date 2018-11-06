//
//  mkvmufs.c
//  project2
//
//  Created by Gurparmvir Singh on 11/2/18.
//  Copyright © 2018 Gurparmvir Singh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  //  int f = 4;
    int X = (254 * 512);
    unsigned short y = 0xfffc;
    unsigned short z = 0xfffa;
    unsigned short x = 0x55;
    int a = 242;
    unsigned short b = 1;
     unsigned short c = 0;
  //  int z = (241 * 512)-1;
  //  int c = (242 * 512)-1;
   // int d = (253 *  512)-1;
  
        FILE *fp = fopen("file.img", "wb");
        fseek(fp, X , SEEK_SET);
    for(int i=0;i<240;i++)
    {
        fwrite(&y, sizeof(y), 1, fp);
    
    }
    fwrite(&z, sizeof(z), 1, fp);
    for(int i=241;i<253;i++)
    {
        putc(a-1, fp);
        a++;
        //fwrite(&a, sizeof(int), 1, fp);
    }
    fwrite(&z, sizeof(z), 1, fp);
    fwrite(&z, sizeof(z), 1, fp);
    for(int i=254;i<270;i++)
    {
          fwrite(&x, sizeof(x), 1, fp);
    }
    // color values and code components sets to 1
    fwrite(&b, sizeof(b), 1, fp);
    fwrite(&b, sizeof(b), 1, fp);
    fwrite(&b, sizeof(b), 1, fp);
    fwrite(&b, sizeof(b), 1, fp);
    fwrite(&b, sizeof(b), 1, fp);
    //putc(1, fp);
   // putc(1, fp);
    
    for(int i=276;i<303;i++)
    {
        fwrite(&c, sizeof(c), 1, fp);
    }
    
        fclose(fp);
    return 0;


}
 

