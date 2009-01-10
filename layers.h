#ifndef __LAYERS_H__
#define __LAYERS_H__

#include <png.h>

/* What is the largest layer purpose name we have? */
#define MAX_CROSS_SECTION_NAME 100
/* What is the maximum number of layers on a single point? */
#define MAX_CROSS_SECTIONS_PER_POINT 100

typedef struct{
	unsigned int ybottom;
	unsigned int ytop;
	unsigned int colour;
	char **rules;
	unsigned int num_rules;
} layerdef;

int contains_layer(char **cross_sectioncol, char *name);
int check_rule(layerdef *layer, char **cross_sectioncol);
void free_cross_section(char ***cross_section, png_uint_32 width);
int load_cross_section(char *infile, char ****cross_section, png_uint_32 *width, png_uint_32 *height);
int load_layers(char *layersfile, layerdef **layers, unsigned int *num_layers);
void free_layers(layerdef *layers, unsigned int num_layers);
int parse_rules(char *line, char ***rules, unsigned int *num_rules);

#endif
