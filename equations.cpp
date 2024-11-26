// rate change of prey 
float d_prey_dt(float x, float y, float a, float b, float k) { 
return a*x*(1-x/k) - b * x * y; 
} 
// rate of change of predator 
float d_pred_dt(float x, float y, float c, float d, float k) { 
return c*y*(1-y/k) + d * x * y; 
} 