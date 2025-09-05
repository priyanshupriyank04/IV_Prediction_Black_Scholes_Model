#ifndef ROOT_FINDERS_HPP
#define ROOT_FINDERS_HPP

struct IVResult{
    double IV;  //final implied volatility
    int iteration; //number of iterations performed
    bool converge;   //convergence succeeded or not
};

IVResult newtonRaphsonIV(bool isCall,
                         double S, double K, double r, double T,
                         double market_price,
                         double initial_sigma = 0.20,
                         double tol = 1e-8,
                         int max_iter = 100);

#endif