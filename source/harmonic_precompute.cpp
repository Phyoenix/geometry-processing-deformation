#include "harmonic_precompute.h"
#include <igl/min_quad_with_fixed.h>
#include <igl/cotmatrix.h>

void harmonic_precompute(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::VectorXi & b,
  igl::min_quad_with_fixed_data<double> & data)
{
  // 计算拉普拉斯矩阵（使用余切权重）
  Eigen::SparseMatrix<double> L;
  igl::cotmatrix(V, F, L);
  
  // 对于谐波变形，我们直接使用拉普拉斯矩阵作为能量矩阵
  // 这对应于最小化梯度能量：∫_Ω ||∇d||²_F dA
  
  // 预处理线性系统求解器
  // 注意：这里我们使用拉普拉斯矩阵L作为能量矩阵Q
  igl::min_quad_with_fixed_precompute(L, b, Eigen::SparseMatrix<double>(), false, data);
}