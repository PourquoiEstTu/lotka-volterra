#include <cmath> 
#include <iostream> 
#include "cpgplot.h" 
#include "equations.h" 
int main(void) 
{ 
  const int nintervals = 100000; 
  float prey_rate[nintervals+1]; //middle_rate[nintervals+1],  
  float pred_rate[nintervals+1], tp[nintervals+1]; 
  // prey_rate[0] = 500; 
  // pred[0] = 50; 
  float t_start = 0., t_end = 20.; //range of interval 
  float dt = (t_end - t_start)/float(nintervals); 
  //std::cout << "dt = " << dt << std::endl; 
  //constants variables for the three equations  
  float a, b, c, d; //c, d, e, f, g; 
  a = 7./3., b = 5./3., c = 7./3., d = 5./3.; //c = 0.8, d = 0.8, e = 0.3, f = 0.25, g = 0.1; 
  //carrying capacity constants for each equation 
  float cc_prey, cc_pred; //c_middle, cc_pred; 
  cc_prey = 1.7, cc_pred = 0.7;// c_middle = 30.,  
  // variables which will be iterated over 
  float t; 
  float prey, pred; //middle,  // values which will be put in the array 
  float k_prey[4], k_pred[4]; //k_middle[4],  // k values for both bottom and top 
  // Open a plot window 
  if (!cpgopen("/XWINDOW")) return 1; 
  // Set-up plot axes 
  cpgenv(0.,t_end,0.,3.0,0,1); 
   
  // Label axes 
  cpglab("time", "population", "populations of bottom, middle, and top of food chain"); 
 
  // Change plot colour to colour 4 (BLUE) 
  // cpgsci(4); 
 
  // Compute the function at the points 
  prey = 2.; 
  //middle = 50; 
  pred = 0.1; 
  t = t_start; 
  for (int i=0; i <= nintervals; i++) { 
    //std::cout << "hi" << "\n"; 
      tp[i] = t; 
      prey_rate[i] = prey; 
      //middle_rate[i] = middle; 
      pred_rate[i] = pred; 
       
      k_prey[0] = dt * d_prey_dt(prey, pred, a, b, cc_prey); 
      //std::cout << "k_prey[0] = " << k_prey[0]  << "\n"; 
      //std::cout << "d_prey_dt(bottom, top, a, b) = " << d_prey_dt(bottom, top, a, b)  << "\n"; 
      //std::cout << std::endl; 
      //k_middle[0] = dt * d_middle_dt(bottom, middle, top, c, d, e, c_middle); 
      k_pred[0] = dt * d_pred_dt(prey, pred, c, d, cc_pred); 
      //std::cout << "k_pred[0] = " << k_pred[0]  << "\n"; 
      //std::cout << "d_pred_dt(bottom, top, r, c) = " << d_pred_dt(bottom, top, r, c)  << "\n"; 
      //std::cout << std::endl; 
      k_prey[1] = dt * d_prey_dt(prey + k_prey[0]/2, pred + k_pred[0]/2, a, b, cc_prey); 
      //std::cout << "k_prey[1] = " << k_prey[1]  << "\n"; 
      // k_middle[1] = dt * d_middle_dt(bottom + k_prey[0]/2, middle + k_middle[0]/2, top + k_pred[0]/2, 
c, d, e, c_middle); 
      k_pred[1] = dt * d_pred_dt(prey + k_prey[0]/2, pred + k_pred[0]/2, c, d, cc_pred); 
      //std::cout << "k_pred[1] = " << k_pred[1]  << "\n"; 
      k_prey[2] = dt * d_prey_dt(prey + k_prey[1]/2, pred + k_pred[1]/2, a, b, cc_prey); 
      //std::cout << "k_prey[2] = " << k_prey[2]  << "\n"; 
      // k_middle[2] = dt * d_middle_dt(bottom + k_prey[1]/2, middle + k_middle[1]/2, top + k_pred[1]/2, 
c, d, e, c_middle); 
      k_pred[2] = dt * d_pred_dt(prey + k_prey[1]/2, pred + k_pred[1]/2, c, d, cc_pred); 
      //std::cout << "k_pred[2] = " << k_pred[2]  << "\n"; 
      k_prey[3] = dt * d_prey_dt(prey + k_prey[2], pred + k_pred[2], a, b, cc_prey); 
      //std::cout << "k_prey[3] = " << k_prey[3]  << "\n"; 
      // k_middle[3] = dt * d_middle_dt(bottom + k_prey[2]/2, middle + k_middle[2]/2, top + k_pred[2]/2, 
c, d, e, c_middle); 
      k_pred[3] = dt * d_pred_dt(prey + k_prey[2], pred + k_pred[2], c, d, cc_pred); 
      // std::cout << "k_pred[3] = " << k_pred[3]  << "\n"; 
 
      t += dt; 
       
      prey += (1./6.) * (k_prey[0] + 2*k_prey[1] + 2*k_prey[2] + k_prey[3]); 
      // middle += (1./6.) * (k_middle[0] + 2*k_middle[1] + 2*k_middle[2] + k_middle[3]); 
      //std::cout << middle << "\n"; 
      //std::cout << bottom  << "\n"; 
      pred += (1./6.) * (k_pred[0] + 2*k_pred[1] + 2*k_pred[2] + k_pred[3]); 
      //std::cout << top  << "\n"; 
    /*x[i] = dx*i; 
y[i] = cos(x[i]);*/ 
} 
// Plot the curve   
cpgsci(5); // bottom line is cyan 
cpgline(nintervals+1,tp,prey_rate); 
// cpgsci(6); // middle line is pink 
// cpgline(nintervals+1,tp,middle_rate); 
cpgsci(3); // top line is green 
cpgline(nintervals+1,tp,pred_rate); 
// Pause and then close plot window 
cpgclos();  
} 