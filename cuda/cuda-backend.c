#include <stdio.h>
#include <cuda.h>
#include "sgbuf.h"
#include "cuda-backend.h"

#define cudaSilent(a) if(a!=cudaSuccess) exit(0);

void create_dev_buffers_cuda(sgDataBuf* source, sgDataBuf* target, 
                            sgIndexBuf* si, sgIndexBuf *ti, 
                            size_t block_len){
    cudaError_t ret;
    ret = cudaMalloc((void **)&(source->dev_ptr), source->size); cudaSilent(ret);
    ret = cudaMalloc((void **)&(target->dev_ptr), target->size); cudaSilent(ret);
    ret = cudaMalloc((void **)&(si->dev_ptr), si->size);         cudaSilent(ret);
    ret = cudaMalloc((void **)&(ti->dev_ptr), ti->size);         cudaSilent(ret);
}