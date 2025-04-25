#ifndef HARMONIC_PRECOMPUTE_H
#define HARMONIC_PRECOMPUTE_H

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <igl/min_quad_with_fixed.h>

// 预计算用于基于梯度能量（谐波）变形的必要数据
//
// 输入:
//   V  #V by 3 列表示的顶点位置
//   F  #F by 3 列表示的三角形面片
//   b  #b 列表示的控制点索引
// 输出:
//   data  预计算的数据，用于后续求解
void harmonic_precompute(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::VectorXi & b,
  igl::min_quad_with_fixed_data<double> & data);

#endif