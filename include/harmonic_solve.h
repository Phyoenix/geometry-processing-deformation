#ifndef HARMONIC_SOLVE_H
#define HARMONIC_SOLVE_H

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <igl/min_quad_with_fixed.h>

// 使用预计算的数据求解基于梯度能量（谐波）的变形
//
// 输入:
//   data  预计算的数据
//   bc    #b by 3 列表示的控制点位置
// 输出:
//   U     #V by 3 列表示的变形后顶点位置
void harmonic_solve(
  const igl::min_quad_with_fixed_data<double> & data,
  const Eigen::MatrixXd & bc,
  Eigen::MatrixXd & U);

#endif