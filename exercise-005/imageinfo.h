#ifndef MY_FANCY_IMAGE_INFO_H
#define MY_FANCY_IAMGE_INFO_H

struct ImageInfo {
    unsigned int width;
    unsigned int height;
    const unsigned char* data; //pointer auf image.h
};

ImageInfo* newImageInfo();
unsigned int getWidth(ImageInfo* self);
unsigned int getHeight(ImageInfo* self);

#endif