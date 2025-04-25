#include "biharmonic_solve.h"
#include <igl/min_quad_with_fixed.h>

void biharmonic_solve(
  const igl::min_quad_with_fixed_data<double> & data,
  const Eigen::MatrixXd & bc,
  Eigen::MatrixXd & D)
{
  // 使用预计算的数据求解线性系统
  // 对于双调和变形，我们最小化拉普拉斯能量：∫_Ω ||Δd||² dA
  // 这等价于求解双调和方程：Δ²d = 0，满足边界条件
  
  // 使用预计算的数据求解线性系统
  // B为空，因为我们没有线性项
  // Y为空，因为我们没有二次项
  igl::min_quad_with_fixed_solve(data, Eigen::VectorXd::Zero(data.n), bc, Eigen::MatrixXd(), D);
}
