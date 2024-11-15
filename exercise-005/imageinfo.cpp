#include "imageinfo.h"
#include "image.h"
#include "stdlib.h"


ImageInfo* newImageInfo(){
    ImageInfo* tmp = (ImageInfo*) malloc(sizeof(ImageInfo));
    tmp -> height = image_uc_height;
    tmp -> width = image_uc_width;
    tmp -> data = image_uc_data;
    return tmp;
};

unsigned int getWidth(ImageInfo* self){
    return self->width;
};

unsigned int getHeight(ImageInfo* self){
    return self->height;
};