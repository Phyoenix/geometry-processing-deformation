#include "biharmonic_precompute.h"
#include <igl/min_quad_with_fixed.h>
#include <igl/cotmatrix.h>
#include <igl/massmatrix.h>
#include <igl/invert_diag.h>

void biharmonic_precompute(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::VectorXi & b,
  igl::min_quad_with_fixed_data<double> & data)
{
  // 1. 计算拉普拉斯矩阵 L
  Eigen::SparseMatrix<double> L;
  igl::cotmatrix(V, F, L);
  
  // 2. 计算质量矩阵 M
  Eigen::SparseMatrix<double> M;
  igl::massmatrix(V, F, igl::MASSMATRIX_TYPE_BARYCENTRIC, M);
  
  // 3. 计算质量矩阵的逆 Minv
  Eigen::SparseMatrix<double> Minv;
  igl::invert_diag(M, Minv);
  
  // 4. 计算双拉普拉斯矩阵 Q = L' * Minv * L
  Eigen::SparseMatrix<double> Q = L.transpose() * Minv * L;
  
  // 5. 预处理线性系统求解器
  igl::min_quad_with_fixed_precompute(Q, b, Eigen::SparseMatrix<double>(), false, data);
}
