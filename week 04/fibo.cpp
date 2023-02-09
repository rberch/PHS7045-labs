#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int fibRcp(int n) {
  if (n <= 1)
    return n;
  return fibRcp(n - 1) + fibRcp(n - 2);
}
