#include "Image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jpeglib.h"

int Image::loadFromJpg(const char* Name) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    
    JSAMPARRAY pJpegBuffer; // Output row buffer */
    
    FILE * infile = fopen(Name, "rb"); // source file
    if (infile == NULL) {
        fprintf(stderr, "can't open %s\n", Name);
        return 0;
    }
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    cinfo.out_color_space = JCS_RGB;
    jpeg_start_decompress(&cinfo);
    width = cinfo.output_width;
    height = cinfo.output_height;
    
    unsigned char * pDummy = new unsigned char [width*height*4];
    unsigned char * pFirst = pDummy;
    
    int row_stride = cinfo.output_width * cinfo.output_components; // physical row width in output buffer
    pJpegBuffer = (*cinfo.mem->alloc_sarray) ((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);
    
    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, pJpegBuffer, 1);
        // if doesnot need alpha, use memcpy, donot use loop
        // memcpy(pDummy, pJpegBuffer[0], row_stride);
        // pDummy += row_stride;
        for(int x = 0; x < row_stride; x += 3) {
            *(pDummy++) = pJpegBuffer[0][x];
            *(pDummy++) = pJpegBuffer[0][x + 1];
            *(pDummy++) = pJpegBuffer[0][x + 2];
            *(pDummy++) = 1;
        }
    }
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
    
    if(buffer) {
        delete[] buffer;
    }
    buffer = (uint8_t*)pFirst;
    return 0;
}

uint8_t* Image::getPixel(int x, int y) {
    return buffer + (y * width + x) * 4;
}

void Image::drawBinary(FrameBuffer* frame, Pixel black, Pixel white) {
    drawCustom(frame, [=](uint8_t* p) -> Pixel {
        if((p[0] + p[1] + p[2]) * p[3] < 255 * 3 / 2) {
            return white;
        } else {
            return black;
        }
    });
}

void Image::drawColor(FrameBuffer* frame) {
    // todo
}

void Image::drawCustom(FrameBuffer* frame, std::function<Pixel(uint8_t*)> f) {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            Pixel p = f(getPixel(x, y));
            frame->set(x, height-y-1, p);
        }
    }
}
