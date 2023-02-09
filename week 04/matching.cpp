
#include <Rcpp.h>

using namespace Rcpp;

// // [[Rcpp::export]]
// [output must be list] ps_match1(const NumericVector & x) {
//   
//   ...prepare the output (save space)...
//   ...it should be an integer vector indicating the id of the match...
//   ...and a numeric vector with the value of `x` for the match...
//   
//   for (...loop over i...) {
//     
//     for (...loop over j and check if it is the optimum...) {
//       if (...the closests so far...) {
//           ...update the optimum...
//       }
//     }
//     
//   }
//   
//   return [a list like the R function]
//   
// }

// [[Rcpp::export]]
List ps_match1(const NumericVector & x) {
  int n = x.size();
  IntegerVector match_id(n);
  NumericVector match_x(n);
  
  for (int i = 0; i < n; i++) {
    int id = -1;
    double x_min = INFINITY;
    
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (fabs(x[i] - x[j]) < x_min) {
        id = j;
        x_min = fabs(x[i] - x[j]);
      }
    }
    
    match_id[i] = id + 1;
    match_x[i] = x[id];
  }
  
  return List::create(
    _["match_id"] = match_id,
    _["match_x"] = match_x
  );
}

/***R


ps_match1(runif(5))
*/
