//! \file examples/Arrangement_2/ex_rational_functions.cpp
// Constructing an arrangement of arcs of rational functions.
#include <CGAL/basic.h>

#include <CGAL/Gmpz.h>
#include <CGAL/Gmpq.h>
#include <CGAL/Algebraic_kernel_d_1.h>
#include <CGAL/Arr_rational_function_traits_2.h>
#include <CGAL/Arrangement_2.h>

typedef CGAL::Gmpz                                    Integer;
typedef CGAL::Algebraic_kernel_d_1<Integer>           AK1; 
typedef CGAL::Arr_rational_function_traits_2<AK1>     Traits_2; 

typedef AK1::Polynomial_1                             Polynomial_1;
typedef AK1::Algebraic_real_1                         Alg_real_1;

typedef CGAL::Arrangement_2<Traits_2>                 Arrangement_2;

int main ()
{
  // create a polynomial representing x .-)
  Polynomial_1 x = CGAL::shift(Polynomial_1(1),1);

  // Traits class object 
  Traits_2 traits; 
  Traits_2::Construct_x_monotone_curve_2 construct_arc
    = traits.construct_x_monotone_curve_2_object(); 

  // container storing all arcs 
  std::vector<Traits_2::X_monotone_curve_2>  arcs;
  
  // Create an arc supported by the polynomial y = x^4 - 6x^2 + 8,
  // defined over the interval [-2, 2]:
  Polynomial_1 P1 = x*x*x*x - 6*x*x + 8;
  arcs.push_back(construct_arc(P1, Alg_real_1(-2), Alg_real_1(2)));

  // Create an arc supported by the function y = x / (1 + x^2),
  // defined over the interval [-3, 3]:
  Polynomial_1 P2 = x;
  Polynomial_1 Q2 = 1+x*x;
  
  arcs.push_back(construct_arc(P2, Q2, Alg_real_1(-3), Alg_real_1(3)));
      
  // Create an arc supported by the parbola y = 8 - x^2,
  // defined over the interval [-2, 3]:
  Polynomial_1 P3 = 8 - x*x; 
  arcs.push_back(construct_arc(P3, Alg_real_1(-2), Alg_real_1(3)));
  
  // Create an arc supported by the line y = -2x,
  // defined over the interval [-3, 0]:
  Polynomial_1 P4 = -2*x;
  arcs.push_back(construct_arc(P4, Alg_real_1(-3), Alg_real_1(0)));
  
  // Construct the arrangement of the four arcs.
  Arrangement_2              arr;
  insert (arr, arcs.begin(), arcs.end());

  // Print the arrangement size.
  std::cout << "The arrangement size:" << std::endl
            << "   V = " << arr.number_of_vertices()
            << ",  E = " << arr.number_of_edges()
            << ",  F = " << arr.number_of_faces() << std::endl;

  return 0;
}
