#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "tiffio.h"
int main()
{
  TIFF* tif = TIFFOpen("sample.svs", "r");
  if (tif) {
  	uint32 imageWidth, imageLength;
  	uint32 tileWidth, tileLength;
  	uint32 x, y;
  	//tdata_t buf;

  	TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &imageWidth);
  	TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imageLength);
  	TIFFGetField(tif, TIFFTAG_TILEWIDTH, &tileWidth);
  	TIFFGetField(tif, TIFFTAG_TILELENGTH, &tileLength);
  	//buf = _TIFFmalloc(TIFFTileSize(tif));
    uint32* buf = (uint32 *)malloc(imageWidth*imageLength * sizeof(uint32));
  	for (y = 0; y < imageLength; y += tileLength)
  	    for (x = 0; x < imageWidth; x += tileWidth)
  		    TIFFReadTile(tif, buf, x, y, 0, 0);
          printf("%d x %d\n", imageWidth, imageLength);
          printf("%d\n", buf[0]);
  	_TIFFfree(buf);
  	TIFFClose(tif);
  }
  return 0;
}
