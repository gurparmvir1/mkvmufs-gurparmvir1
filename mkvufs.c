#include <stdio.h>

#include <stdlib.h>


int main(void)

{

    int X = (256 * 512)-1;

    int y = (240 * 512)-1;

    int z = (241 * 512)-1;

    int c = (242 * 512)-1;

    int d = (253 *  512)-1;

    int f = (256 * 512)-1;

    int b[6] ;

        FILE *fp = fopen("file.img", "wb");

        fseek(fp, X , SEEK_SET);

    for(int i=0;i<f;i++)

    {

        fputs("0xFFFC", fp);

     }

    fclose(fp);

    return 0;
