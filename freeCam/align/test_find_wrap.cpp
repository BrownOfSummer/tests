/*************************************************************************
    > File Name: test_wrap.cpp
    > Author: li_pengju
    > Mail: li_pengju@vobile.cn
    > Copyright (c) Vobile Inc. All Rights Reserved
    > Created Time: 2018-05-11 12:30:30
 ************************************************************************/

#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
#include "registration.h"
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    Mat reference = imread( argv[1] );
    cout<<"Read "<<argv[1]<<" as reference !\n";
    Mat im = imread( argv[2] );
    cout<<"Read "<<argv[2]<<" to align. \n";

    cout<<"Get match points ...\n";
    vector<Point2f> imgP, referenceP;
    getMatchPoints(im, reference, imgP, referenceP);
    
    Mat imRegistered1, imRegistered2;
    Mat warpMatrix1, warpMatrix2;
    const int warp_mode = MOTION_HOMOGRAPHY;

    cout<<"Get warpMatrix ORB...\n";
    getWarpMatrixORB(imgP, referenceP, warpMatrix1, warp_mode);
    cout<<warpMatrix1<<endl;
    
    cout<<"Get warpMatrix ECC...\n";
    getWarpMatrixECC(im, reference, warpMatrix2, warp_mode);
    cout<<warpMatrix2<<endl;
    
    if(warpMatrix1.empty()) {
        cout<<"Can not get warp matrix ORB !\n";
    }
    else {
        warpImage(im, imRegistered1, reference.size(), warpMatrix1, warp_mode);
    }
    if(warpMatrix2.empty()) {
        cout<<"Can not get warp matrix ECC !\n";
    }
    else {
        warpImage(im, imRegistered2, reference.size(), warpMatrix2, warp_mode);
    }
    if( !imRegistered1.empty() ) imwrite("00aligned_ORB.jpg", imRegistered1);
    if( !imRegistered2.empty() ) imwrite("01aligned_ECC.jpg", imRegistered2);
    return 0;
}