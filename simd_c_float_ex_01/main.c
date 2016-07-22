//
//  main.c
//  simd_c_float_ex_01
//
//  Created by PARK JAICHANG on 7/21/16.
//  Copyright © 2016 JAICHANGPARK. All rights reserved.
//

#include <stdio.h>
#include <emmintrin.h>
#include <immintrin.h>

int main(int argc, const char * argv[]) {
   
    /*
    // 1. 입력과 저장
    
    float A[4] = {1.0,2.0,3.0,4.0};
    float R[4] = {0};
    
    __m128 xmmA = _mm_load_ps(A); // align 된 32bit 실수값 4개를 읽어서 대입...
    __m128 xmmR = xmmA;
    _mm_store_ps(R, xmmR); // 32bit 값 4 개를 저장... 메모리는 정렬....
    printf("align Store : %.3f,%.3f,%.3f,%.3f \n",R[3],R[2],R[1],R[0]);
    */
    
    float A[4] = {1.0,2.0,3.0,4.0};
    float B[4] = {4.0,3.0,2.0,1.0};
    float R[4] = {0};
    
    __m128 xmmA = _mm_load_ps(A);
    __m128 xmmB = _mm_load_ps(B);
    
    __m128 xmmR = _mm_add_ps(xmmA, xmmB); // 덧셈
    _mm_store_ps(R, xmmR); //결과 출력
    printf("add Store : %.3f,%.3f,%.3f,%.3f \n",R[3],R[2],R[1],R[0]);
    
    xmmR = _mm_sub_ps(xmmA, xmmB);  // 뺄셈 xmmR에 뺀 결과를 집어넣고
    _mm_store_ps(R, xmmR);          // xmmR에 저장된 결과를 R로 밀어넣음..
    printf("sub Store : %.3f,%.3f,%.3f,%.3f \n",R[3],R[2],R[1],R[0]);
    
    return 0;
}
