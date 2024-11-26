#ifndef EQUATIONS_H 
#define EQUATIONS_H 
// rate change of bottom of food chain 
float d_prey_dt(float x, float y, float a, float b, float k); 
// rate of change of middle of food change 
//float d_middle_dt(float x, float y, float z, float c, float d, float e, float k); 
// rate change of top of food chain  
float d_pred_dt(float x, float y, float c, float d, float k); 
#endif 
