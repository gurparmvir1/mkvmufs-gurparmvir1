//
//  mkvmufs.c
//  project2
//
//  Created by Gurparmvir Singh on 11/2/18.
//  Copyright © 2018 Gurparmvir Singh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include<math.h>

int main(void)
{
    //local time for timestamps
    time_t timer;
    struct tm* info;
    char day[2];
    char month[2];
    char year[4];
    char hour[2];
    char min[2];
    char sec [2];
    char wday[2];
    time(&timer);
    info = localtime(&timer);
    strftime(day, 2, "%d", info);
    strftime(month, 2, "%m", info);
    strftime(year, 4, "%Y", info);
    strftime(hour, 2, "%H", info);
    strftime(min, 2, "%M", info);
    strftime(sec, 2, "%S", info);
    strftime(wday, 1, "%w", info);
    
    
    // intializing number of bytes
    int a = 242;
    int X = (254 * 512);
    unsigned short y = 0xfffc;
    unsigned short z = 0xfffa;
    int x = 85;
    unsigned short b = 0;
    unsigned short c = 0;
    unsigned short d = 0x00FE;
    unsigned short e = 0x0001;
    unsigned short f = 0x00FD;
    unsigned short g = 0x000D;
    unsigned short h = 1;
    unsigned short i = 0x00C8;
    
    
    FILE *fp = fopen("file.img", "wb");
    fseek(fp, X , SEEK_SET);
    for(int i=0;i<241;i++)
    {
        fwrite(&y, sizeof(y), 1, fp);
    
    }
    // printing 0xFFFA
    fwrite(&z, sizeof(z), 1, fp);
    
    for(int i=242;i<254;i++)
    {
        unsigned short abc = a-1;
        fwrite(&abc,sizeof(abc),1,fp);
        a++;
    }
    //writing 0xFFFA
    fwrite(&z, sizeof(z), 1, fp);
    fwrite(&z, sizeof(z), 1, fp);
    
    //writing 0x55
    for(int i=256;i<272;i++)
    {
        fputc(x, fp);
    }
    // color values and code components sets to 0
    fwrite(&b, 1, 1, fp);
    fwrite(&b, 1, 1, fp);
    fwrite(&b, 1, 1, fp);
    fwrite(&b, 1, 1, fp);
    fwrite(&b, 1, 1, fp);
    
    //set 27 bytes to 0
    for(int i=277;i<304;i++)
    {
        fwrite(&c, 1, 1, fp);
    }
    
    // timestamps
    
    fwrite(&year, sizeof(year), 1, fp);
    fwrite(&month, sizeof(month), 1, fp);
    fwrite(&day, sizeof(day), 1, fp);
    fwrite(&hour, sizeof(hour), 1, fp);
    fwrite(&min, sizeof(min), 1, fp);
    fwrite(&sec, sizeof(sec), 1, fp);
    fwrite(&wday, sizeof(wday), 1, fp);
    
    //set 14 bytes to 0
    
    for( int i=311;i<325;i++)
    {
        fwrite(&c, 1, 1, fp);
    }
    //writing 0x00FE
    fwrite(&d, 2, 1, fp);
    
    
    //writing 0x0001
    fwrite(&e, 2, 1, fp);
    
    
    //writing 0x00FD
    fwrite(&f, 2, 1, fp);
    
    
    //wrinting 0x000D
    fwrite(&g, 2, 1, fp);
    
    
    ////wrting 0-230 random
    fwrite(&h, 2, 1, fp);
    
   
    //writing 0x00C8
    fwrite(&i, 2, 1, fp);
    
    
    //set all bytes 430  to 0
    for( int i=337;i<767;i++)
    {
        fwrite(&c, 1, 1, fp);
    }
    
        fclose(fp);
    return 0;


}

