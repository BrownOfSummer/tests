/*************************************************************************
    > File Name: registration.h
    > Author: li_pengju
    > Mail: li_pengju@vobile.cn
    > Copyright (c) Vobile Inc. All Rights Reserved
    > Created Time: 2018-05-11 12:28:41
 ************************************************************************/

#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
/*
 * MOTION_AFFINE
 * MOTION_EUCLIDEAN
 * MOTION_TRANSLATION
 * MOTION_HOMOGRAPHY 
 */

Mat getGradient(Mat src);
Mat DrawInlier(Mat &src1, Mat &src2, std::vector<KeyPoint> &kpt1, std::vector<KeyPoint> &kpt2, std::vector<DMatch> &inlier, int type);
Mat drawPointPairs(const Mat &img1, const Mat&img2, const std::vector<Point2f> &p1, const std::vector<Point2f> &p2, const int type);
// Match points based
void getMatchPoints(Mat img, Mat reference, std::vector<Point2f> &imgP, std::vector<Point2f> &referenceP);
void getWarpMatrixORB(std::vector<Point2f> imgP, std::vector<Point2f> referenceP, Mat &warpMatrix, const int method);
void warpImage(Mat img, Mat &imgWrap, Size outSize, Mat warpMatrix, const int method);
Point2d phaseMove(const Mat &img, const Mat &reference);
Mat localWarpEstimate(const std::vector<Point2f>& shape1, const std::vector<Point2f>& shape2, int type);
#if CV_MAJOR_VERSION > 2
// ECC based
void getWarpMatrixECC(Mat img, Mat reference, Mat &warpMatrix, const int warp_mode);
void warpImageECC(Mat img, Mat &imgWarp, Size outSize, Mat warpMatrix, const int method);
#endif
