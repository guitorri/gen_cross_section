#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include "gen_cross_section.h"
#include "usage.h"
#include "gen_png.h"
#include "layers.h"

int main(int argc, char *argv[])
{
	char *outfile=NULL, *infile=NULL, *layersfile=NULL, *palettefile=NULL;
	png_uint_32 width = 640;
	png_uint_32 height = 640;
	char ***cross_section = NULL;
	int pixelwidth = 4;
	png_uint_32 imagewidth;
	png_uint_32 maxwidth = 0;

	if(!process_args(argc, argv, &infile, &outfile, &layersfile, &palettefile, &maxwidth)){
		return 1;
	}
	if(!load_cross_section(infile, &cross_section, &imagewidth, &width, &height, &pixelwidth)){
		if(cross_section){
			free_cross_section(cross_section, width);
		}
		return 1;
	}
	make_png(outfile, palettefile, imagewidth, height, pixelwidth, cross_section);
	free_cross_section(cross_section, width);

	return 0;
}

